// Підключення хедр файлу  Functions, де написані функції, які треба визначити, надати тіло.
#include "Functions.h"

// Визначення конструктора без параметрів
functions::functions(): function_values_at_point_x(0), function_values_at_point_y(0), center_coordinate_point_x(0), center_coordinate_point_y(0), show_or_not_show(false), number_of_points(0), initial_boundary(0), final_boundary(0){}

// Визначення деструктора
functions::~functions(){
    function_values_at_point_x = 0;
    function_values_at_point_y = 0;
    center_coordinate_point_x = 0;
    center_coordinate_point_y = 0;
    show_or_not_show = false;
    number_of_points = 0;
    initial_boundary = 0;
    final_boundary = 0;
}