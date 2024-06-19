#ifndef F_x
#define F_x

// Підключення хедр файлу Functions для використання в цьому модулі класу нащадка function
#include "Functions.h"

// Створення класу нащадка f_F від functions
class f_F: public functions{

    // Відкриття публічного доступу
    public:

    // Оголошення конструктора бкз параметрів
    f_F();

    // Оголошення конструктора з двома параметрами
    f_F(int x, int y);

    // Оголошення диструктора
    ~f_F();

    // Перевірка на пустоту
    bool empty();

    // Головна функція, яка створює точки (xi,yi)
    void f_x(float a, float b, int n, int move, int size);

    // Функція для повернення xi
    float get_point_coordinates_x(int i);
    
    // Функція для повернення yi
    float get_point_coordinates_y(int i);
    
    // Функція для встановлення xi
    void set_point_coordinates_x(int i, float x);
    
    // Функція для встановлення yi
    void set_point_coordinates_y(int i, float y);
 
    // Функція для встановлення відповідної кількості точок
    void great_points(int n);

    // Функція для перевірки відображення
    bool show_function();
    
    // Функція для встановлення типу відображення або не відображення
    void show_function(bool show);

    // Функція для ссува графіка по осі абцис
    void move_x(float x, int n, int move);

    // Функція для ссува графіка по осі оординат
    void move_y(float y, int n, int move);

    // Функція для стиснення графіка по осі абцис
    void compress_x(float x, int n);

    // Функція для стиснення графіка по осі оординат
    void compress_y(float y, int n);

    // Функція для повернення кількості точок для функції
    int get_n();

    // Функція для задання кількості точок для функції
    void set_n(int n);
};

#endif