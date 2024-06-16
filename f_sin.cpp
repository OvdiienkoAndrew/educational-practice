#include "F_sin.h"

f_sin::f_sin(){};

f_sin::~f_sin(){};

f_sin::f_sin(int x, int y){
    center_coordinate_point_x = x;
    center_coordinate_point_y = y;
}

bool f_sin::empty(){return point_coordinates_x == nullptr;}


void f_sin::f_x(float a, float b, int n, int move, int size){

    f_sin::initial_boundary=a;
    f_sin::final_boundary=b;
    f_sin::number_of_points=n;
    
    if(n<=0){}
    else{

        point_coordinates_x=new float[n];
        point_coordinates_y=new float[n];

        if(n==1){

            function_values_at_point_x = (a+b)*0.5;
            function_values_at_point_y = -sin(function_values_at_point_x);

            point_coordinates_x[0]=center_coordinate_point_x+function_values_at_point_x*move-size;
            point_coordinates_y[0]=center_coordinate_point_y+function_values_at_point_y*move-size;

        }else{

            double step=(b-a)/(n-1);
            
            for(int i=0; i<n; i++){

                function_values_at_point_x=a+step*i;
                function_values_at_point_y = -sin(function_values_at_point_x);

                point_coordinates_x[i]=center_coordinate_point_x+function_values_at_point_x*move-size;
                point_coordinates_y[i]=center_coordinate_point_y+function_values_at_point_y*move-size;
            }
        }
    }
}

float f_sin::get_point_coordinates_x(int i){ return point_coordinates_x[i];}
    
float f_sin::get_point_coordinates_y(int i){ return point_coordinates_y[i];}
    
void f_sin::set_point_coordinates_x(int i, float x){ point_coordinates_x[i] = x;}
    
void f_sin::set_point_coordinates_y(int i, float y){ point_coordinates_y[i] = y;}

void f_sin::great_points(int n){
    point_coordinates_x=new float[n];
    point_coordinates_y=new float[n];
}

bool f_sin::show_function() {return show_or_not_show;}
    
void f_sin::show_function(bool show) {show_or_not_show=show;}

void f_sin::move_x(float x, int n, int move){
    for(int i=0; i<n; i++)
        point_coordinates_x[i] +=  x*move;
}

void f_sin::move_y(float y, int n, int move){
    for(int i=0; i<n; i++)
        point_coordinates_y[i] -=  y*move;
}

void f_sin::compress_x(float x, int n){
    for(int i=0; i<n; i++)
        point_coordinates_x[i] *= x;
}

void f_sin::compress_y(float y, int n){
    for(int i=0; i<n; i++)
        point_coordinates_y[i] *= y;
}

int f_sin::get_n(){return number_of_points;}

void f_sin::set_n(int n){number_of_points = n;}