// Підключення хедр файлу  F_cos, де написані функції, які треба визначити, надати тіло.
#include "F_cos.h"

// Визначення конструктора без параметрів
f_cos::f_cos(){};

// Визначення деструктора
f_cos::~f_cos(){};

// Визначення конструктора з параметрами
f_cos::f_cos(int x, int y){
    center_coordinate_point_x = x;
    center_coordinate_point_y = y;
}

// Повернення істини, якщо точок немає
bool f_cos::empty(){return point_coordinates_x == nullptr;}

// Визначення головної функції, яка створює точки (xi,yi)
void f_cos::f_x(float a, float b, int n, int move, int size){

    // Надання проміжків відрисовки функції та кількості точок
    f_cos::initial_boundary=a;
    f_cos::final_boundary=b;
    f_cos::number_of_points=n;
    
    if(n<=0){}
    else{

        // Створення масивві для точок (xi, yi)
        point_coordinates_x=new float[n];
        point_coordinates_y=new float[n];

        // Якщо одна точка.
        if(n==1){

            // За х беремо середнє арифметичне проміжку
            function_values_at_point_x = (a+b)*0.5;

            // За y беремо потрібну функцію але із знаком мінус попереду
            function_values_at_point_y = -cos(function_values_at_point_x);

            // (x,y) це буде сума початкових координат та значень функції множножених на масштаб відображення та мінус масштаб точки
            point_coordinates_x[0]=center_coordinate_point_x+function_values_at_point_x*move-size;
            point_coordinates_y[0]=center_coordinate_point_y+function_values_at_point_y*move-size;

        }else{
            // Шукаємо крок між вузловими точками
            double step=(b-a)/(n-1);
            
            for(int i=0; i<n; i++){

                // За х беремо суму початкового значення відрізка відображення функції та кроку, у перший раз крок нульовий
                function_values_at_point_x=a+step*i;

                // За y беремо потрібну функцію але із знаком мінус попереду
                function_values_at_point_y = -cos(function_values_at_point_x);

                // (xi,yi) це буде сума початкових координат та значень функції множножених на масштаб відображення та мінус масштаб точки
                point_coordinates_x[i]=center_coordinate_point_x+function_values_at_point_x*move-size;
                point_coordinates_y[i]=center_coordinate_point_y+function_values_at_point_y*move-size;
            }
        }
    }
}

// Визначаємо функцію для повернення хі
float  f_cos::get_point_coordinates_x(int i){ return point_coordinates_x[i];}
    
// Визначаємо функцію для повернення уі
float  f_cos::get_point_coordinates_y(int i){ return point_coordinates_y[i];}
    
// Визначаємо функцію для встановлення хі
void f_cos::set_point_coordinates_x(int i, float  x){ point_coordinates_x[i] = x;}
    
// Визначаємо функцію для встановлення уі
void f_cos::set_point_coordinates_y(int i, float  y){ point_coordinates_y[i] = y;}

// Визначення функції створення відповідної кількості точок для відображення
void f_cos::great_points(int n){
    point_coordinates_x=new float [n];
    point_coordinates_y=new float [n];
}

// Повернення істнини, якщо графік слід відображати
bool f_cos::show_function() {return show_or_not_show;}
    
// Надання умову відображення чи не відображення графіка
void f_cos::show_function(bool show) {show_or_not_show=show;}

// Зсув графіка по осі абцис
void f_cos::move_x(float x, int n, int move){
    
    // Додавання до кожної координати х певного коефіцієнта
    for(int i=0; i<n; i++)
        point_coordinates_x[i] +=  x*move;
}

// Зсув графіка по осі ординат
void f_cos::move_y(float y, int n, int move){
    
    // Додавання до кожної координати y певного коефіцієнта
    for(int i=0; i<n; i++)
        point_coordinates_y[i] -=  y*move;
}

// Стиснення/розтягування графіка відносно осі абцис
void f_cos::compress_x(float x, int n){
    for(int i=0; i<n; i++)
    {
        point_coordinates_x[i] -= center_coordinate_point_x;
        point_coordinates_x[i] += 2;
        point_coordinates_x[i] *= x;
        point_coordinates_x[i] += center_coordinate_point_x;
        point_coordinates_x[i] -= 2;
    }
}

// Стиснення/розтягування графіка відносно осі ординат
void f_cos::compress_y(float y, int n){
    for(int i=0; i<n; i++)
    {
        point_coordinates_y[i] -= center_coordinate_point_y;
        point_coordinates_y[i] += 2;
        point_coordinates_y[i] *= y;
        point_coordinates_y[i] += center_coordinate_point_y;
        point_coordinates_y[i] -= 2;
    }
}

// Повернення кількості точок у функції
int f_cos::get_n(){return number_of_points;}

// Встановлення кількості точок у функції
void f_cos::set_n(int n){number_of_points = n;}