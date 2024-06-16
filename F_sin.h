#ifndef F_sin
#define F_sin

#include "Functions.h"

class f_sin: public functions{

    public:

    f_sin();
    f_sin(int x, int y);
    ~f_sin();

    bool empty();

    void f_x(float a, float b, int n, int move, int size);

    float get_point_coordinates_x(int i);
    
    float get_point_coordinates_y(int i);
    
    void set_point_coordinates_x(int i, float x);
    
    void set_point_coordinates_y(int i, float y);

    void great_points(int n);

    bool show_function();
    
    void show_function(bool show);

    void move_x(float x, int n, int move);

    void move_y(float y, int n, int move);

    void compress_x(float x, int n);

    void compress_y(float y, int n);

    int get_n();

    void set_n(int n);
};

#endif