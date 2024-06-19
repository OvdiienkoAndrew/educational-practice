#ifndef Files
#define Files

// Підключення стандартноі бібліотеки для вводу/виводу та простору імен std
#include <iostream>
using namespace std;

// Підключення бібліотеки sfml для вграфіки та простору імен sf
#include <SFML/Graphics.hpp>
using namespace sf;

// Підключення бібліотеки для роботи з фалами
#include <sstream>

// Фунуція для записання дданних у файл
void input_file(Font& font, string& str);

// Функція для надання данних із файлу
void output_file(Font& font, string& text);

#endif