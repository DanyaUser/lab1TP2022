#include "helper.h"
bool checkStringToInt(std::string s)
{
for (auto letter : s)
if (letter < '0' || letter > '9')
return false;
return true;
}
bool checkStringToDouble(std::string s)
{
bool flagPoint = false;
for (int i = 0; i < s.size(); i++)
{
if ((s[i] < '0' || s[i] > '9') && (s[i] == '.' && i == 0 || flagPoint))
return false;
if (s[i] == '.')
flagPoint = true;
}
return true;
}
