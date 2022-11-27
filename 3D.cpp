#include "3D.h"
#include <stdio.h>
#include <math.h>
#include <windows.h>
VolumetricFigure::VolumetricFigure() : Base("3D"), name("Not set"), type("Not set"), color("Not set"),
width(0), length(0), high(0), volume(0)
{
cout << "The constructor of VolumetricFigure is called" << endl;
}
VolumetricFigure::VolumetricFigure(string name, string type, string color, int width, int length, int high,
int volume) :
Base("3D"), name(name), type(type), color(color), width(width), length(length), high(high),
volume(volume)
{
cout << "The constructor of VolumetricFigure is called" << endl;
}
VolumetricFigure::VolumetricFigure(const VolumetricFigure& volumetricFigure) :
Base(volumetricFigure), name(volumetricFigure.name), type(volumetricFigure.type),
color(volumetricFigure.color), width(volumetricFigure.width), length(volumetricFigure.length),
high(volumetricFigure.high), volume(volumetricFigure.volume)
{
cout << "The constructor of PlaneFigure is called" << endl;
}
void VolumetricFigure::inputFromConsole()
{
cout << "Enter the name of figure: ";
getline(cin, name);
cout << "Select the type of figure: " << endl;
cout << "1 - Cube" << endl;
cout << "2 - Pyramid" << endl;
cout << "3 - Parallelepiped" << endl;
cout << "Enter number of type: " << endl;
int select = safeInput(1, 3);
switch (select)
{
case 1:
type = "cube";
break;
case 2:
type = "pyramid";
break;
case 3:
type = "parallelepiped";
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
cout << "Enter the high of figure: ";
high = safeInput(1, INT32_MAX);
cout << "Enter the volume of figure: ";
volume = safeInput(1, INT32_MAX);
}
void VolumetricFigure::inputFromFile(std::ifstream& file, std::string& tmpS)
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
high = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
if (!getline(file, tmpS))
throw err;
volume = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
}
void VolumetricFigure::printToConsole()
{
Base::printToConsole();
cout << "The name of figure: " << name << endl;
cout << "The type of figure: " << type << endl;
cout << "The color of figure: " << color << endl;
cout << "The width of figure: " << width << endl;
cout << "The length of figure: " << length << endl;
cout << "The high of figure: " << high << endl;
cout << "The square of figure: " << volume << endl;
}
void VolumetricFigure::printToFile(ostream& out)
{
Base::printToFile(out);
out << name << endl;
out << type << endl;
out << color << endl;
out << width << endl;
out << length << endl;
out << high << endl;
out << volume << endl;
}
void VolumetricFigure::change()
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
cout << "Enter the new high of figure: ";
high = safeInput(1, INT32_MAX);
cout << "Enter the new square of figure: ";
volume = safeInput(1, INT32_MAX);
}
void VolumetricFigure::image()
{
HWND sHwnd = GetForegroundWindow();
HDC hdc = GetDC(sHwnd);
HPEN hPen;
hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
if (type == "cube") {
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
if (type == "pyramid") {
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
if (type == "parallelepiped") {
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
void VolumetricFigure::check()
{
int err = 0;
if (type == "cube") {
if (size(name) != 8) {
err++;
cout << "There are not 8 letters in the name, although the cube has 8 vertices" <<
endl;
}
if (volume != width*length*high) {
err++;
cout << "The volume is " << width * length * high << ", but is written as " <<
volume << endl;
}
if (err == 0)
{
cout << "No errors detected" << endl;
}
}
if (type == "pyramid") {
if (size(name) != 5) {
err++;
cout << "There are not 5 letters in the name, although the pyramid has 5 vertices"
<< endl;
}
if (volume != (0.3 * width * length * high)) {
err++;
cout << "The volume is " << (0.3 * width * length * high) << ", but is written as" << volume << endl;
}
if (err == 0)
{
cout << "No errors detected" << endl;
}
}
if (type == "parallelepiped") {
if (size(name) != 8) {
err++;
cout << "There are not 8 letters in the name, although the parallelepiped has 8 vertices" << endl;
}
if (volume != width * length * high) {
err++;
cout << "The volume is " << width * length * high << ", but is written as " <<
volume << endl;
}
if (err == 0)
{
cout << "No errors detected" << endl;
}
}
}
