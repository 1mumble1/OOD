#include "stdafx.h"
#include "Application.h"

const std::string INPUT_FILE_NAME = "input.txt";
const std::string OUTPUT_FILE_NAME = "output.txt";

int main()
{
    auto app = Application::GetInstance(INPUT_FILE_NAME, OUTPUT_FILE_NAME);
    app->Run();

    return 0;
}