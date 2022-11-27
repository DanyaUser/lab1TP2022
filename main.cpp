#include "keeper.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
void printMenu();
void addObject(Keeper& keeper);
void changeObject(Keeper& keeper);
void deleteObject(Keeper& keeper);
void imageObject(Keeper& keeper);
void checkObject(Keeper& keeper);
int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
Keeper keeper;
cout << "Do data outputing from a file?" << endl;
cout << "-----------------" << endl;
cout << "1 - Yes" << endl;
cout << "2 - No" << endl;
cout << "Enter number of operation: ";
int method = safeInput(1, 2);
try
{
if (method == 1) {
system("cls");
cout << "The operation was completed successfully" << endl;
cout << "-----------------" << endl;
keeper.inputFromFile();
}
}
catch (string err)
{
system("cls");
cout << err << endl;
cout << "-----------------" << endl;
}
bool isExit = false;
while (!isExit) {
printMenu();
method = safeInput(1, 8);
switch (method)
{
case 1:
addObject(keeper);
break;
case 2:
changeObject(keeper);
break;
case 3:
deleteObject(keeper);
break;
case 4:
system("cls");
keeper.printToConsole();
cout << "-----------------" << endl;
break;
case 5:
system("cls");
cout << "The operation was completed successfully" << endl;
cout << "-----------------" << endl;
keeper.printToFile();
break;
case 6:
imageObject(keeper);
break;
case 7:
checkObject(keeper);
break;
case 8:
isExit = true;
break;
}
}
}
void printMenu() {
cout << "Instruction" << endl;
cout << "-----------------" << endl;
cout << "1 - Add a new object" << endl;
cout << "2 - Edit an existing object" << endl;
cout << "3 - Delete an existing object" << endl;
cout << "4 - Display data on the screen" << endl;
cout << "5 - Save data to a file" << endl;
cout << "6 - Print image of figure" << endl;
cout << "7 - Check figure" << endl;
cout << "8 - Exit" << endl;
cout << "-----------------" << endl;
cout << "Select a menu item: ";
}
void addObject(Keeper& keeper)
{
cout << "-----------------" << endl;
cout << "1 - 2D figure" << endl;
cout << "2 - 3D figure" << endl;
cout << "Select the object to add: " << endl;
int typeInt = safeInput(1, 2);
string typeS;
if (typeInt == 1)
typeS = "2D";
if (typeInt == 2)
typeS = "3D";
Base* object = createObj(typeS);
object->inputFromConsole();
keeper.add(object);
system("cls");
cout << "The operation was completed successfully" << endl;
cout << "-----------------" << endl;
}
void changeObject(Keeper& keeper)
{
if (keeper.getSize() == 0) {
system("cls");
cout << "No figures to change" << endl;
cout << "-----------------" << endl;
}
else
{
system("cls");
keeper.printToConsole();
cout << "Select the object number to change: ";
int number = safeInput(1, keeper.getSize());
keeper[number - 1]->change();
system("cls");
cout << "The operation was completed successfully" << endl;
cout << "-----------------" << endl;
}
}
void deleteObject(Keeper& keeper)
{
if (keeper.getSize() == 0) {
system("cls");
cout << "No figures to delete" << endl;
cout << "-----------------" << endl;
}
else
{
system("cls");
keeper.printToConsole();
cout << "Select the object number to delete: ";
int number = safeInput(1, keeper.getSize());
keeper.del(number - 1);
system("cls");
cout << "The operation was completed successfully" << endl;
cout << "-----------------" << endl;
}
}
void imageObject(Keeper& keeper)
{
if (keeper.getSize() == 0) {
system("cls");
cout << "No figures to image" << endl;
cout << "-----------------" << endl;
}
else
{
system("cls");
keeper.printToConsole();
cout << "Select the object number to image: ";
int number = safeInput(1, keeper.getSize());
system("cls");
keeper[number - 1]->image();
cout << endl << endl << endl << endl << endl << endl << endl << endl;
cout << "-----------------" << endl;
}
}
void checkObject(Keeper& keeper)
{
if (keeper.getSize() == 0) {
system("cls");
cout << "No figures to check" << endl;
cout << "-----------------" << endl;
}
else
{
system("cls");
keeper.printToConsole();
cout << "Select the object number to image: ";
int number = safeInput(1, keeper.getSize());
system("cls");
keeper[number - 1]->check();
cout << "-----------------" << endl;
}
}
