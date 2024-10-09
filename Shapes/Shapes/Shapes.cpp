#include "stdafx.h"
#include "ShapeController.h"

int main()
{
    ShapeController sController;
    sController.ReadShapes("input.txt");
    sController.DrawShapes();
    sController.PrintShapesInfo("output.txt");
    return 0;
}