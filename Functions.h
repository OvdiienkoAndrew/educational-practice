#ifndef Functions
#define Functions

#include <cmath>

class functions{

    protected:

    float *point_coordinates_x;
    float *point_coordinates_y;

    float function_values_at_point_x;
    float function_values_at_point_y;

    float center_coordinate_point_x;
    float center_coordinate_point_y;

    bool show_or_not_show;

    int number_of_points;
    float initial_boundary;
    float final_boundary;

    public:

    functions();
    ~functions();

};

#endif