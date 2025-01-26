#include "stdafx.h"
#include "Application.h"

int main()
{
    Application& app = Application::GetInstance();
    app.ReadShapes(INPUT_FILE_NAME);
    app.DrawShapes();
    return 0;
}