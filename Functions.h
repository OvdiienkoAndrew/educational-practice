#ifndef Functions
#define Functions

// Підключення стандартноі бібліотеки для математичних функцій
#include <cmath>

// Створення батьківського класу функцій
class functions{

    // Відкриваємо доступ до наслідування
    protected:

    // Масиви для зберігання точок функції
    float *point_coordinates_x;
    float *point_coordinates_y;

    // Змінні для вираховування точок функції
    float function_values_at_point_x;
    float function_values_at_point_y;

    // Змінні для зберігання центру осей 
    float center_coordinate_point_x;
    float center_coordinate_point_y;

    // Змінна для зберігання умови відображення графіка
    bool show_or_not_show;

    // Зммінні для кількості точок, початку та кінця інтервалу побудови графіка
    int number_of_points;
    float initial_boundary;
    float final_boundary;

    // Відкриття публічного доступу
    public:

    // Оголошення конструктора бкз параметрів
    functions();

    // Оголошення диструктора
    ~functions();

};

#endif