#include "Keeper.h"
Keeper::Keeper() : data(nullptr), size(0)
{
cout << "The constructor of Keeper is called" << endl;
}
Keeper::Keeper(Base** data, int size)
{
this->data = new Base * [size];
this->size = size;
for (int i = 0; i < size; i++)
this->data[i] = data[i];
cout << "The constructor of Keeper is called" << endl;
}
Keeper::Keeper(const Keeper& keeper)
{
data = new Base * [keeper.size];
size = keeper.size;
for (int i = 0; i < size; i++)
this->data[i] = keeper.data[i];
cout << "The copy constructor of Keeper is called" << endl;
}
Keeper::~Keeper()
{
size = 0;
delete[] data;
data = nullptr;
cout << "The destructor of Keeper is called" << endl;
}
void Keeper::add(Base* base)
{
Base** tmp = data;
size++;
data = new Base * [size];
for (int i = 0; i < size - 1; i++)
data[i] = tmp[i];
data[size - 1] = base;
}
void Keeper::del(int index)
{
if (index < 0 || index >= size)
throw index;
Base** tmp = new Base * [size - 1];
int k = 0;
for (int i = 0; i < size; i++)
if (i != index)
tmp[k++] = data[i];
size--;
data = tmp;
}
Base* Keeper::operator[](int index)
{
if (index < 0 || index >= size)
throw index;
return data[index];
}
void Keeper::inputFromFile()
{
ifstream input("save.txt");
if (input.is_open())
{
string tmpS;
int countRecord;
if (!getline(input, tmpS))
{
input.close();
string err = "The file cannot be read";
throw err;
}
countRecord = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
try
{
for (int i = 0; i < countRecord; i++)
{
string err = "The file cannot be read correctly";
if (!getline(input, tmpS))
throw err;
Base* obj = createObj(tmpS);
obj->inputFromFile(input, tmpS);
this->add(obj);
}
}
catch (string err)
{
input.close();
throw err;
}
input.close();
}
else
{
string err = "File keeper.txt not found";
throw err;
}
}
void Keeper::printToFile()
{
ofstream output("save.txt");
output << size << endl;
for (int i = 0; i < size; i++)
data[i]->printToFile(output);
output.close();
}
void Keeper::printToConsole()
{
if (size == 0)
cout << "Figures are missing" << endl;
else
{
cout << "The figures are saved in the file:" << endl;
for (int i = 0; i < size; i++)
{
cout << i + 1 << ". ";
data[i]->printToConsole();
}
}
}
