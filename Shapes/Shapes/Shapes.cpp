#include "stdafx.h"
#include "ShapeController.h"

int main()
{
    ShapeController& sController = ShapeController::GetInstance();
    sController.ReadShapes(INPUT_FILE_NAME);
    sController.DrawShapes();
    sController.PrintShapesInfo(OUTPUT_FILE_NAME);

    return 0;
}