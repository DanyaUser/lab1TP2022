#pragma once
#include "helper.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
class Base
{
private:
string typeObj;
public:
Base(string typeObj);
Base(const Base& base);
~Base() { cout << "The destructor of Base is called" << endl; }
virtual void inputFromConsole() = 0;
virtual void inputFromFile(std::ifstream& file, std::string& tmpS) = 0;
virtual void printToConsole();
virtual void printToFile(ostream& out);
virtual void change() = 0;
virtual void image() = 0;
virtual void check() = 0;
string getTypeObj() { return typeObj; }
};
