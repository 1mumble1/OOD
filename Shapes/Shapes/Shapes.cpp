#include "stdafx.h"
#include "ShapeController.h"

int main()
{
    ShapeController sController;
    sController.ReadShapes("input.txt");
    sController.PrintShapesInfo("output.txt");
    sController.DrawShapes();
    return 0;
}