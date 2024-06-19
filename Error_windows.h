#ifndef Error_windows
#define Error_windows

// Підключення бібліотеки sfml для вграфіки та простору імен sf
#include <SFML/Graphics.hpp>
using namespace sf;

// Вікно про нульовий коефіцієнт, який немає сенсу
void zero_coefficient(Font& font);

// Вікно про помилку, коли людина намагається перемістити чи масштабувати неіснуюче
void there_is_a_coefficient_but_there_is_no_graph(Font& font);

// Вікно про помилку, коли початкове значення проміжка А і В більше ніж кінцеве
void the_beginning_is_greater_than_the_end(Font& font);

// Вікно про помилку, коли А, В чи N не введені
void A_B_N_were_not_entered(Font& font);

#endif