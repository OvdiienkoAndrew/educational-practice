#ifndef Text_input
#define Text_input

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

void text_input_for_A_B_k(Event& event, string& text_assistant, Text& text_display_written, float& number);
void text_input_for_N(Event& event, string& text_assistant, Text& text_display_written, int& number);
void text_input_for_K(Event& event, string& text_assistant, Text& text_display_written, float& number);

#endif