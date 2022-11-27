#include "2D.h"
#include <stdio.h>
#include <math.h>
#include <windows.h>
PlaneFigure::PlaneFigure() : Base("2D"), name("Not set"), type("Not set"), color("Not set"), width(0),
length(0), square(0)
{
cout << "The constructor of PlaneFigure is called" << endl;
}
PlaneFigure::PlaneFigure(string name, string type, string color, int width, int length, int square) :
Base("2D"), name(name), type(type), color(color), width(width), length(length),
square(square)
{
cout << "The constructor of PlaneFigure is called" << endl;
}
PlaneFigure::PlaneFigure(const PlaneFigure& planeFigure) :
Base(planeFigure), name(planeFigure.name), type(planeFigure.type), color(planeFigure.color),
width(planeFigure.width), length(planeFigure.length), square(planeFigure.square)
{
cout << "The constructor of PlaneFigure is called" << endl;
}
void PlaneFigure::inputFromConsole()
{
cout << "Enter the name of figure: ";
getline(cin, name);
cout << "Select the type of figure: " << endl;
cout << "1 - Square" << endl;
cout << "2 - Triangle" << endl;
cout << "3 - Parallelogram" << endl;
cout << "Enter number of type: ";
int select = safeInput(1, 3);
switch (select)
{
case 1:
type = "square";
break;
case 2:
type = "triangle";
break;
case 3:
type = "parallelogram";
break;
}
cout << "Select the color of figure: " << endl;
cout << "1 - Red" << endl;
cout << "2 - Blue" << endl;
cout << "3 - Green" << endl;
cout << "Enter number of color: ";
select = safeInput(1, 3);
switch (select)
{
case 1:
color = "red";
break;
case 2:
color = "blue";
break;
case 3:
color = "green";
break;
}
cout << "Enter the width of figure: ";
width = safeInput(1, INT32_MAX);
cout << "Enter the length of figure: ";
length = safeInput(1, INT32_MAX);
cout << "Enter the square of figure: ";
square = safeInput(1, INT32_MAX);
}
void PlaneFigure::inputFromFile(std::ifstream& file, std::string& tmpS)
{
string err = "The file cannot be read correctly";
if (!getline(file, tmpS))
throw err;
name = tmpS;
if (!getline(file, tmpS))
throw err;
type = tmpS;
if (!getline(file, tmpS))
throw err;
color = tmpS;
if (!getline(file, tmpS))
throw err;
width = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
if (!getline(file, tmpS))
throw err;
length = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
if (!getline(file, tmpS))
throw err;
square = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
}
void PlaneFigure::printToConsole()
{
Base::printToConsole();
cout << "The name of figure: " << name << endl;
cout << "The type of figure: " << type << endl;
cout << "The color of figure: " << color << endl;
cout << "The width of figure: " << width << endl;
cout << "The length of figure: " << length << endl;
cout << "The square of figure: " << square << endl;
}
void PlaneFigure::printToFile(ostream& out)
{
Base::printToFile(out);
out << name << endl;
out << type << endl;
out << color << endl;
out << width << endl;
out << length << endl;
out << square << endl;
}
void PlaneFigure::change()
{
cout << "Enter the new name of figure: ";
getline(cin, name);
cout << "Enter the new type of figure: ";
getline(cin, type);
cout << "Enter the new color of figure: ";
getline(cin, color);
cout << "Enter the new width of figure: ";
width = safeInput(1, INT32_MAX);
cout << "Enter the new length of figure: ";
length = safeInput(1, INT32_MAX);
cout << "Enter the new square of figure: ";
square = safeInput(1, INT32_MAX);
}
void PlaneFigure::image()
{
HWND sHwnd = GetForegroundWindow();
HDC hdc = GetDC(sHwnd);
HPEN hPen;
hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
if (type == "square") {
if (color == "red") {
hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
}
if (color == "blue") {
hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}
if (color == "green") {
hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
}
SelectObject(hdc, hPen);
MoveToEx(hdc, 100, 50, NULL);
LineTo(hdc, 100, 100);
MoveToEx(hdc, 100, 100, NULL);
LineTo(hdc, 50, 100);
MoveToEx(hdc, 50, 100, NULL);
LineTo(hdc, 100, 50);
}
if (type == "triangle") {
if (color == "red") {
hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
}
if (color == "blue") {
hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}
if (color == "green") {
hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
}
SelectObject(hdc, hPen);
MoveToEx(hdc, 100, 50, NULL);
LineTo(hdc, 150, 100);
MoveToEx(hdc, 150, 100, NULL);
LineTo(hdc, 50, 100);
MoveToEx(hdc, 50, 100, NULL);
LineTo(hdc, 100, 50);
}
if (type == "parallelogram") {
if (color == "red") {
hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
}
if (color == "blue") {
hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}
if (color == "green") {
hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
}
SelectObject(hdc, hPen);
MoveToEx(hdc, 100, 50, NULL);
LineTo(hdc, 100, 100);
MoveToEx(hdc, 100, 100, NULL);
LineTo(hdc, 50, 100);
MoveToEx(hdc, 50, 100, NULL);
LineTo(hdc, 100, 50);
}
}
void PlaneFigure::check()
{
int err = 0;
if (type == "square") {
if (size(name) != 4) {
err++;
cout << "There are not 4 letters in the name, although the square has 4 vertices" << endl;
}
if (square != width * length) {
err++;
cout << "The square is " << width * length << ", but is written as " << square
<< endl;
}
if (err == 0)
{
cout << "No errors detected" << endl;
}
}
if (type == "triangle") {
if (size(name) != 3) {
err++;
cout << "There are not 3 letters in the name, although the triagle has 3 vertices" << endl;
}
if (square != (0.5 * width * length)) {
err++;
cout << "The square is " << 0.5 * width * length << ", but is written as " <<
square << endl;
}
if (err == 0)
{
cout << "No errors detected" << endl;
}
}
if (type == "parallelogram") {
if (size(name) != 4) {
err++;
cout << "There are not 4 letters in the name, although the parallelogram has 4 vertices" << endl;
}
if (square != width * length) {
err++;
cout << "The square is " << width * length << ", but is written as " << square
<< endl;
}
if (err == 0)
{
cout << "No errors detected" << endl;
}
}
}
