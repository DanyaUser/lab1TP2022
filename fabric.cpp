#include "fabric.h"
Base* createObj(string name)
{
if (name == "2D")
return new PlaneFigure();
if (name == "3D")
return new VolumetricFigure();
string err = "Object type not recognized";
throw err;
}
