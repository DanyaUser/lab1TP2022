#pragma once
#include "Base.h"
class VolumetricFigure :
public Base
{
private:
string name, type, color;
int width, length, high, volume;
public:
VolumetricFigure();
VolumetricFigure(string name, string type, string color, int width, int length, int high, int
volume);
VolumetricFigure(const VolumetricFigure& volumetricFigure);
~VolumetricFigure() { cout << "The destructor of VolumetricFigure is called" << endl; }
virtual void inputFromConsole();
virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
virtual void printToConsole();
virtual void printToFile(ostream& out);
virtual void change();
virtual void image();
virtual void check();
string getName() { return name; }
void setName(string name) { this->name = name; }
string getType() { return type; }
void setType(string type) { this->type = type; }
string getСolor() { return color; }
void setСolor(string color) { this->color = color; }
int getWidth() { return width; }
void setWidth(int width) { this->width = width; }
int getLength() { return length; }
void setLength(double length) { this->length = length; }
int getHigh() { return high; }
void setHigh(double high) { this->high = high; }
int getSquare() { return volume; }
void setSquare(double volume) { this->volume = volume; }
};
