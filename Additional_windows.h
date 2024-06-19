#ifndef Additional_windows
#define Additional_windows

// Підключення стандартноі бібліотеки для вводу/виводу та простору імен std
#include <iostream>
using namespace std;

// Підключення бібліотеки sfml для вграфіки та простору імен sf
#include <SFML/Graphics.hpp>
using namespace sf;

// Додавання проміжків для рандомної функції
void Random_function_settings_A_B(Font& font, string& A, string& B);

// Вікно з інформацією про програму та користувача
void job_information(Font& font);

// Вікно з інформацією про упішне збереження
void program_save(Font& font, string& text);

// Вікно з інформацією про упішне відкриття
void program_open(Font& font, string& text);

// Вікно з інформацією про невдачу зберегти файл
void program_does_not_save(Font& font, string& text);

// Вікно з інформацією про невдачу відкрити файл
void program_does_not_open(Font& font, string& text);

#endif