#pragma once
const std::string INPUT_FILE_NAME = "input.txt";
const std::string OUTPUT_FILE_NAME = "output.txt";

const int MIN_RGB_COLOR_VALUE = 0;
const int MAX_RGB_COLOR_VALUE = 255;

const int COUNT_OF_VERTEX_FOR_TRIANGLE = 3;
const int ID_OF_FIRST_VERTEX_FOR_TRIANGLE = 0;
const int ID_OF_SECOND_VERTEX_FOR_TRIANGLE = 1;
const int ID_OF_THIRD_VERTEX_FOR_TRIANGLE = 2;

const int MIN_THICKNESS = 1;

const int WIDTH_WINDOW = 1500;
const int HEIGHT_WINDOW = 900;
const std::string TITLE_WINDOW = "Window";
const bool INITIAL_DRAGGING_VALUE = false;

const sf::Vector2f POSITION_OF_CREATE_CIRCLE_BUTTON = sf::Vector2f(20, 20);
const sf::Vector2f POSITION_OF_CREATE_RECTANGLE_BUTTON = sf::Vector2f(200, 20);
const sf::Vector2f POSITION_OF_CREATE_TRIANGLE_BUTTON = sf::Vector2f(380, 20);
const sf::Vector2f POSITION_OF_DRAG_AND_DROP_BUTTON = sf::Vector2f(560, 20);
const sf::Vector2f POSITION_OF_FILL_COLOR_BUTTON = sf::Vector2f(740, 20);
const sf::Vector2f POSITION_OF_FILL_OUTLINE_BUTTON = sf::Vector2f(920, 20);
const sf::Vector2f POSITION_OF_SET_RED_COLOR_BUTTON = sf::Vector2f(20, 100);
const sf::Vector2f POSITION_OF_SET_GREEN_COLOR_BUTTON = sf::Vector2f(120, 100);
const sf::Vector2f POSITION_OF_SET_BLUE_COLOR_BUTTON = sf::Vector2f(220, 100);
const sf::Vector2f POSITION_OF_ADD_THICKNESS_BUTTON = sf::Vector2f(740, 100);
const sf::Vector2f POSITION_OF_REDUCE_THICKNESS_BUTTON = sf::Vector2f(900, 100);

const sf::Vector2f SIZE_OF_BIG_BUTTON = sf::Vector2f(150, 50);
const sf::Vector2f SIZE_OF_SMALL_BUTTON = sf::Vector2f(100, 25);

const std::string TEXT_OF_CREATE_CIRCLE_BUTTON = "Create Circle";
const std::string TEXT_OF_CREATE_RECTANGLE_BUTTON = "Create Rectangle";
const std::string TEXT_OF_CREATE_TRIANGLE_BUTTON = "Create Triangle";
const std::string TEXT_OF_DRAG_AND_DROP_BUTTON = "Drag&Drop";
const std::string TEXT_OF_FILL_COLOR_BUTTON = "Fill Color";
const std::string TEXT_OF_FILL_OUTLINE_BUTTON = "Fill Outline";
const std::string TEXT_OF_ADD_THICKNESS_BUTTON = "+";
const std::string TEXT_OF_REDUCE_THICKNESS_BUTTON = "-";

const int FONT_SIZE = 20;

const std::string FONT_FILE_NAME = "arialmt.ttf";

const std::string CIRCLE_SHAPE_NAME = "CIRCLE";
const std::string COMPOSITE_SHAPE_NAME = "COMPOSITE";
const std::string RECTANGLE_SHAPE_NAME = "RECTANGLE";
const std::string TRIANGLE_SHAPE_NAME = "TRIANGLE";
const std::string TABULATION = "\t";

const std::string ERROR_OPEN_FILE = "Ошибка при открытии файла";
const std::string ERROR_CREATE_CIRCLE = "Invalid circle coordinates or sizes";
const std::string ERROR_CREATE_RECTANGLE = "Invalid rectangle coordinates";
const std::string ERROR_CREATE_TRIANGLE = "Invalid triangle coordinates";

const std::string SHAPE_PATTERN = R"(^(\w+):\s*(.*)$)";
const std::string CIRCLE_PATTERN = R"(^C=(\d+),(\d+);\s*R=(\d+)$)";
const std::string RECTANGLE_PATTERN = R"(^P1=(\d+),(\d+);\s*P2=(\d+),(\d+)$)";
const std::string TRIANGLE_PATTERN = R"(^P1=(\d+),(\d+);\s*P2=(\d+),(\d+);\s*P3=(\d+),(\d+)$)";

const std::string CIRCLE_TEMPLATE = "CIRCLE: C=100,100; R=50";
const std::string RECTANGLE_TEMPLATE = "RECTANGLE: P1=200,200; P2=300,400";
const std::string TRIANGLE_TEMPLATE = "TRIANGLE: P1=100,100; P2=50,200; P3=150,200";