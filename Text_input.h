#ifndef Text_input
#define Text_input

// Підключення стандартноі бібліотеки для вводу/виводу та простору імен std
#include <iostream>
using namespace std;

// Підключення бібліотеки sfml для вграфіки та простору імен sf
#include <SFML/Graphics.hpp>
using namespace sf;

// Функція для заповнення проміжків відображення функцій та коефіцієнта зсуву
void text_input_for_A_B_k(Event& event, string& text_assistant, Text& text_display_written, float& number);

// Функція для заповнення кількості точок для відображення графіка
void text_input_for_N(Event& event, string& text_assistant, Text& text_display_written, int& number);

// Функція для заповнення коефіцієнта стискання
void text_input_for_K(Event& event, string& text_assistant, Text& text_display_written, float& number);

#endif