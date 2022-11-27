#pragma once
#include "Base.h"
class PlaneFigure :
public Base
{
private:
string name, type, color;
int width, length, square;
public:
PlaneFigure();
PlaneFigure(string name, string type, string color, int width, int length, int square);
PlaneFigure(const PlaneFigure& planeFigure);
~PlaneFigure() { cout << "The destructor of PlaneFigure is called" << endl; }
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
int getSquare() { return square; }
void setSquare(double square) { this->square = square; }
};
