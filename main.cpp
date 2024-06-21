// Підключення додаткових файлів
#include "Files.h"
#include "Error_windows.h"
#include "Text_input.h"
#include "Functions.h"
#include "F_x.h"
#include "F_cos.h"
#include "F_sin.h"
#include "F_rand.h"
#include "Additional_windows.h"
#include "Additional_functions.h"
#include "Graph_display_switch.h"
#include "Graph_displacement_and_compression.h"

// Підключення стандартної бібліотеки для роботи з потоками
#include <fstream>

// Підключення стандартноі бібліотеки для вводу/виводу та простору імен std
#include <iostream>
using namespace std;

// Підключення бібліотеки sfml для вграфіки та простору імен sf
#include <SFML/Graphics.hpp>
using namespace sf;

int main(){

    // Встановлення розмірів основного вікна, назви та розрахування ширини для відображення графіків та меню користувача
    int WIDTH = 1700, HEIGHT = 900;
    char NAME[] = "Graph of a function";
    float USER_INPUT_WIDTH = WIDTH * (1./ 4) - 15;
    float FUNCTION_GRAPH_WIDTH = WIDTH * (3./4) - 15;

    // Створення вікна
    RenderWindow window(VideoMode(WIDTH, HEIGHT), NAME);

    // Створення області для шапки програми - область штуччної панелі інструментів
    RectangleShape head_background(Vector2f(WIDTH, 45));
    head_background.setPosition(0, 0);
    head_background.setFillColor(Color(139, 139, 139));

    // Створення області для відображення графіка
    RectangleShape graph_background(Vector2f(FUNCTION_GRAPH_WIDTH, HEIGHT - 65));
    graph_background.setPosition(10, 55);
    graph_background.setFillColor(Color::White);

    // Створення області для шменю користувача
    RectangleShape user_background(Vector2f(USER_INPUT_WIDTH, HEIGHT - 65));
    user_background.setPosition(FUNCTION_GRAPH_WIDTH + 20, 55);
    user_background.setFillColor(Color(169, 169, 169));

    // Створення шрифта
    Font font;

    // Встановлення шрифта з файла та перевірка відкриття
    font.loadFromFile("/Users/admin/Documents/My documends/Університет/ДНУ/2 Курс/2 Семестр/Навчальна практика/Times_New_Roman-font.ttf");
    if (!font.loadFromFile("/Users/admin/Documents/My documends/Університет/ДНУ/2 Курс/2 Семестр/Навчальна практика/Times_New_Roman-font.ttf"))
    {
        cerr << "\nError opening file Times_New_Roman-font.ttf.\n";
        return 1;
    }

    // Створення підказок, що має ввести користувач
    Text user_hint("User Input", font, 24);
    user_hint.setFillColor(Color::Black);
    user_hint.setStyle(Text::Bold);
    user_hint.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  (USER_INPUT_WIDTH - user_hint.getLocalBounds().width)/2, 65);

    Text user_hint_A("A", font, 24);
    user_hint_A.setFillColor(Color::Black);
    user_hint_A.setStyle(Text::Bold);
    user_hint_A.setPosition(FUNCTION_GRAPH_WIDTH + 20 + user_hint_A.getLocalBounds().width, 85 + user_hint.getLocalBounds().height);

    Text user_hint_B("B", font, 24);
    user_hint_B.setFillColor(Color::Black);
    user_hint_B.setStyle(Text::Bold);
    user_hint_B.setPosition(FUNCTION_GRAPH_WIDTH + 20 + user_hint_A.getLocalBounds().width, 105 + user_hint.getLocalBounds().height + user_hint_A.getLocalBounds().height);

    Text user_hint_N("N", font, 24);
    user_hint_N.setFillColor(Color::Black);
    user_hint_N.setStyle(Text::Bold);
    user_hint_N.setPosition(FUNCTION_GRAPH_WIDTH + 20 + user_hint_A.getLocalBounds().width, 125 + user_hint.getLocalBounds().height + user_hint_A.getLocalBounds().height + user_hint_B.getLocalBounds().height);

    // Створення білих прямокутників із чорною оболочкою, для візуального розуміння де буде текст та куди клікати, щоб його написати
    RectangleShape user_A_wright(Vector2f(15 * user_hint_A.getLocalBounds().width, user_hint_A.getLocalBounds().height)); 
    user_A_wright.setFillColor(Color::Transparent);
    user_A_wright.setFillColor(Color::White);
    user_A_wright.setOutlineColor(Color::Black);
    user_A_wright.setOutlineThickness(2);
    user_A_wright.setPosition(FUNCTION_GRAPH_WIDTH + 20 + 3 * user_hint_A.getLocalBounds().width, 92 + user_hint.getLocalBounds().height);

    RectangleShape user_B_wright(Vector2f(15 * user_hint_A.getLocalBounds().width, user_hint_A.getLocalBounds().height)); 
    user_B_wright.setFillColor(Color::Transparent);
    user_B_wright.setFillColor(Color::White);
    user_B_wright.setOutlineColor(Color::Black);
    user_B_wright.setOutlineThickness(2);
    user_B_wright.setPosition(FUNCTION_GRAPH_WIDTH + 20 + 3 * user_hint_A.getLocalBounds().width, 112 + user_hint.getLocalBounds().height + user_hint_A.getLocalBounds().height);

    RectangleShape user_N_wright(Vector2f(15 * user_hint_A.getLocalBounds().width, user_hint_A.getLocalBounds().height)); 
    user_N_wright.setFillColor(Color::Transparent);
    user_N_wright.setFillColor(Color::White);
    user_N_wright.setOutlineColor(Color::Black);
    user_N_wright.setOutlineThickness(2);
    user_N_wright.setPosition(FUNCTION_GRAPH_WIDTH + 20 + 3 * user_hint_A.getLocalBounds().width, 132 + user_hint.getLocalBounds().height + user_hint_A.getLocalBounds().height + user_hint_B.getLocalBounds().height);

    // Створення обʼєктів для відображення введеного текста
    Text text_display_written_A("", font, 24);
    text_display_written_A.setFillColor(Color::Black);
    text_display_written_A.setPosition(FUNCTION_GRAPH_WIDTH + 20 + 3 * user_hint_A.getLocalBounds().width, 84.5 + user_hint.getLocalBounds().height);

    Text text_display_written_B("", font, 24);
    text_display_written_B.setFillColor(Color::Black);
    text_display_written_B.setPosition(FUNCTION_GRAPH_WIDTH + 20 + 3 * user_hint_A.getLocalBounds().width, 104.5 + user_hint.getLocalBounds().height + user_hint_A.getLocalBounds().height);

    Text text_display_written_N("", font, 24);
    text_display_written_N.setFillColor(Color::Black);
    text_display_written_N.setPosition(FUNCTION_GRAPH_WIDTH + 20 + 3 * user_hint_A.getLocalBounds().width, 124.5 + user_hint.getLocalBounds().height + user_hint_A.getLocalBounds().height + user_hint_B.getLocalBounds().height);

    // Змінні для розрахункових дій
    float number_A = 0.0;
    float number_B = 0.0;
    float number_A2 = 0.0;
    float number_B2 = 0.0;
    int number_N = 0.0;
    float number_k = 0.0;
    float number_K = 0.0;

    // Змінні для перевірки натискання
    bool click_A = false;
    bool click_B = false;
    bool click_A2 = false;
    bool click_B2 = false;
    bool click_N = false;
    bool click_k = false;
    bool click_K = false;
    bool click_save_button = false;
    bool click_open_button = false;
    bool click_generate_button = false;
    bool click_about_button = false;

    // змінні для перевірки вводу
    string text_assistant_A;
    string text_assistant_B;
    string text_assistant_N;
    string text_assistant_k;
    string text_assistant_K;
    string text_assistant_A2;
    string text_assistant_B2;

    // встановлення точки цунтру координатних осей - (0;0)
    int x0 = 10 + graph_background.getLocalBounds().width/2;
    int y0 = 55 + graph_background.getLocalBounds().height/2;

    // Задання кількості цифр для відображення на осях від нуля до певного числа
    int number_of_segments_x = 13;
    int number_of_segments_y = 9;
    int move = 50;
    int index;

    // Створення квадратних кнопок для надання можливості відображення графіків
    square_buttons_with_selection_of_displayed_functions f_x(font, 0), f_cos_x(font, 1), f_sin_x(font, 2), f_rand_x(font, 3);
    
    // Створення функцій з відповідними початковими координатами
    f_F F_x_(x0, y0);
    f_cos F_cos_(x0, y0);
    f_sin F_sin_(x0, y0);
    f_rand F_rand_(x0, y0);

    // Створення круглихх кнопок для надання можливості зсуву та маштабування графіків
    round_buttons_for_moving_and_compressing_graphs  move_x(font, 6), move_y(font, 7), compress_x(font, 9), compress_y(font, 10);

    // Створення віссі абцис
    VertexArray Ox(Lines, 2);
    Ox[0].position = Vector2f(10, y0);
    Ox[0].color = Color::Black;
    Ox[1].position = Vector2f(10 + FUNCTION_GRAPH_WIDTH, y0);
    Ox[1].color = Color::Black;

    // Створення віссі ординат
    VertexArray Oy(Lines, 2);
    Oy[0].position = Vector2f(x0, 55);
    Oy[0].color = Color::Black;
    Oy[1].position = Vector2f(x0, 55 + HEIGHT - 65);
    Oy[1].color = Color::Black;

    // Створення правої частини стрілки напряму віссі абцис
    VertexArray right_side_of_the_arrow_x(Lines, 2);
    right_side_of_the_arrow_x[0].position = Vector2f(x0+x0-10, y0);
    right_side_of_the_arrow_x[0].color = Color::Black;
    right_side_of_the_arrow_x[1].position = Vector2f(x0+x0-20, y0+10);
    right_side_of_the_arrow_x[1].color = Color::Black;

    // Створення лівої частини стрілки напряму віссі абцис
    VertexArray left_side_of_the_arrow_x(Lines, 2);
    left_side_of_the_arrow_x[0].position = Vector2f(x0+x0-10, y0);
    left_side_of_the_arrow_x[0].color = Color::Black;
    left_side_of_the_arrow_x[1].position = Vector2f(x0+x0-20, y0-10);
    left_side_of_the_arrow_x[1].color = Color::Black;

    // Створення правої частини стрілки напряму віссі ординат
    VertexArray right_side_of_the_arrow_y(Lines, 2);
    right_side_of_the_arrow_y[0].position = Vector2f(x0, 55);
    right_side_of_the_arrow_y[0].color = Color::Black;
    right_side_of_the_arrow_y[1].position = Vector2f(x0+10, 65);
    right_side_of_the_arrow_y[1].color = Color::Black;

    // Створення лівої частини стрілки напряму віссі ординат
    VertexArray left_side_of_the_arrow_y(Lines, 2);
    left_side_of_the_arrow_y[0].position = Vector2f(x0, 55);
    left_side_of_the_arrow_y[0].color = Color::Black;
    left_side_of_the_arrow_y[1].position = Vector2f(x0-10, 65);
    left_side_of_the_arrow_y[1].color = Color::Black;

    // Створення одиничних відрізків на позитивній області віссі абцис
    VertexArray positive_segments_x(Lines, number_of_segments_x * 2);
    for (index = 0; index < number_of_segments_x; index++) {
        positive_segments_x[index * 2].color = Color::Black;
        positive_segments_x[index * 2].position = Vector2f(x0 + move * index, y0 - 10);
        positive_segments_x[index * 2 + 1].color = Color::Black;
        positive_segments_x[index * 2 + 1].position = Vector2f(x0 + move * index, y0 + 10);
    }

    // Створення одиничних відрізків на негативній області віссі абцис
    VertexArray negative_segments_x(Lines, number_of_segments_x * 2);
    for (index = 0; index < number_of_segments_x; index++) {
        negative_segments_x[index * 2].color = Color::Black;
        negative_segments_x[index * 2].position = Vector2f(x0 - move * index, y0 - 10);
        negative_segments_x[index * 2 + 1].color = Color::Black;
        negative_segments_x[index * 2 + 1].position = Vector2f(x0 - move * index, y0 + 10);
    }
    
    // Створення одиничних відрізків на позитивній області віссі ординат
    VertexArray positive_segments_y(Lines, number_of_segments_y * 2);
    for (index = 0; index < number_of_segments_y; index++) {
        positive_segments_y[index * 2].color = Color::Black;
        positive_segments_y[index * 2].position = Vector2f(x0 - 10, y0 + move * index);
        positive_segments_y[index * 2 + 1].color = Color::Black;
        positive_segments_y[index * 2 + 1].position = Vector2f(x0 + 10, y0 + move * index);
    }

    // Створення одиничних відрізків на негативній області віссі ординат
    VertexArray negative_segments_y(Lines, number_of_segments_y * 2);
    for (index = 0; index < number_of_segments_y; index++) {
        negative_segments_y[index * 2].color = Color::Black;
        negative_segments_y[index * 2].position = Vector2f(x0 - 10, y0 - move * index);
        negative_segments_y[index * 2 + 1].color = Color::Black;
        negative_segments_y[index * 2 + 1].position = Vector2f(x0 + 10, y0 - move * index);
    }

    // Створення тексту для підпису вісей
    Text x_image("X", font, 24);
    x_image.setFillColor(Color::Black);
    x_image.setStyle(Text::Bold);
    x_image.setPosition(x0 + move*12, y0 + move/2);

    Text y_image("Y", font, 24);
    y_image.setFillColor(Color::Black);
    y_image.setStyle(Text::Bold);
    y_image.setPosition(x0 + move/2, y0 - move*8);

    // Створення масиву із числами для відображення відстані одиничних відрізків на віссі абцис
    Text number_x[2*number_of_segments_x-1];
    for (index = 0; index < 2*number_of_segments_x-1; index++) {
        number_x[index].setFont(font);
        number_x[index].setCharacterSize(12);
        number_x[index].setFillColor(Color::Black);
        number_x[index].setStyle(Text::Bold);
        number_x[index].setPosition(x0 - move * 12 + move * index, y0 + 10);
        number_x[index].setString(to_string(-12 + index));
    }

    // Створення масиву із числами для відображення відстані одиничних відрізків на віссі ординат
    Text number_y[2*number_of_segments_y-1];
    for (index = 0; index < 2*number_of_segments_y-1; index++) {
        number_y[index].setFont(font);
        number_y[index].setCharacterSize(12);
        number_y[index].setFillColor(Color::Black);
        number_y[index].setStyle(Text::Bold);
        number_y[index].setPosition(x0 + 10, y0 + move * 8 - move * index);
        number_y[index].setString(to_string(-8 + index));
    }

    // Створення кнопок: відкриття файла, закриття файла, про програму та користуваяа, генерація 
    RectangleShape open_button(Vector2f(75, 25));
    open_button.setPosition(WIDTH  - 20 - open_button.getLocalBounds().width,(head_background.getLocalBounds().height - open_button.getLocalBounds().height)/2);
    open_button.setFillColor(Color::Transparent);
    open_button.setFillColor(Color::White);
    open_button.setOutlineColor(Color::Black);
    open_button.setOutlineThickness(2);
    open_button.setFillColor(Color::White);

    RectangleShape save_button(Vector2f(75, 25));
    save_button.setPosition(WIDTH  - 30 - open_button.getLocalBounds().width -  save_button.getLocalBounds().width,(head_background.getLocalBounds().height - save_button.getLocalBounds().height)/2);
    save_button.setFillColor(Color::Transparent);
    save_button.setFillColor(Color::White);
    save_button.setOutlineColor(Color::Black);
    save_button.setOutlineThickness(2);
    save_button.setFillColor(Color::White);

    RectangleShape about_button(Vector2f(75, 25));
    about_button.setPosition(20,(head_background.getLocalBounds().height - about_button.getLocalBounds().height)/2);
    about_button.setFillColor(Color::Transparent);
    about_button.setFillColor(Color::White);
    about_button.setOutlineColor(Color::Black);
    about_button.setOutlineThickness(2);
    about_button.setFillColor(Color::White);

    RectangleShape generate_button(Vector2f(150, 50));
    generate_button.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  (USER_INPUT_WIDTH - generate_button.getLocalBounds().width)/2, 154.5 + user_hint.getLocalBounds().height + user_hint_A.getLocalBounds().height + user_hint_B.getLocalBounds().height + user_hint_N.getLocalBounds().height);
    generate_button.setFillColor(Color::Transparent);
    generate_button.setFillColor(Color::White);
    generate_button.setOutlineColor(Color::Black);
    generate_button.setOutlineThickness(2);
    generate_button.setFillColor(Color::White);

    // Створення назви кнопок: відкриття файла, закриття файла, про програму та користуваяа, генерація 
    Text open_button_text("Open", font, 24);
    open_button_text.setFillColor(Color::Black);
    open_button_text.setOrigin(open_button_text.getLocalBounds().left + open_button_text.getLocalBounds().width / 2, open_button_text.getLocalBounds().top + open_button_text.getLocalBounds().height / 2);
    open_button_text.setPosition(open_button.getPosition().x + open_button.getSize().x / 2, open_button.getPosition().y + open_button.getSize().y / 2);

    Text save_button_text("Save", font, 24);
    save_button_text.setFillColor(Color::Black);
    save_button_text.setOrigin(save_button_text.getLocalBounds().left + save_button_text.getLocalBounds().width / 2, save_button_text.getLocalBounds().top + save_button_text.getLocalBounds().height / 2);
    save_button_text.setPosition(save_button.getPosition().x + save_button.getSize().x / 2, save_button.getPosition().y + save_button.getSize().y / 2);

    Text about_button_text("About", font, 24);
    about_button_text.setFillColor(Color::Black);
    about_button_text.setOrigin(about_button_text.getLocalBounds().left + about_button_text.getLocalBounds().width / 2, about_button_text.getLocalBounds().top + about_button_text.getLocalBounds().height / 2);
    about_button_text.setPosition(about_button.getPosition().x + about_button.getSize().x / 2, about_button.getPosition().y + about_button.getSize().y / 2);

    Text generate_button_text("Generate", font, 24);
    generate_button_text.setFillColor(Color::Black);
    generate_button_text.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  (USER_INPUT_WIDTH - generate_button.getLocalBounds().width)/2 + (generate_button.getLocalBounds().width - generate_button_text.getLocalBounds().width)/2, 144.5 + user_hint.getLocalBounds().height + user_hint_A.getLocalBounds().height + user_hint_B.getLocalBounds().height + user_hint_N.getLocalBounds().height + (generate_button.getLocalBounds().height - generate_button_text.getLocalBounds().height)/2);

    // Створення текста підказки: вибора функцій, колір кожної функції
    Text user_hint_F_x("Functions", font, 24);
    user_hint_F_x.setFillColor(Color::Black);
    user_hint_F_x.setStyle(Text::Bold);
    user_hint_F_x.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  (USER_INPUT_WIDTH - user_hint_F_x.getLocalBounds().width)/2, 345 - 1*50);

    Text user_hint_F("y = F(x) - Red", font, 24);
    user_hint_F.setFillColor(Color::Black);
    user_hint_F.setStyle(Text::Bold);
    user_hint_F.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  (USER_INPUT_WIDTH - generate_button.getLocalBounds().width)/2 + (generate_button.getLocalBounds().width - generate_button_text.getLocalBounds().width)/2 - 100, 345 + 0*50);

    Text user_hint_cos("y = cos(x) - Darck Green", font, 24);
    user_hint_cos.setFillColor(Color::Black);
    user_hint_cos.setStyle(Text::Bold);
    user_hint_cos.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  (USER_INPUT_WIDTH - generate_button.getLocalBounds().width)/2 + (generate_button.getLocalBounds().width - generate_button_text.getLocalBounds().width)/2 - 100, 345 + 1*50);

    Text user_hint_sin("y = sin(x) - Blue", font, 24);
    user_hint_sin.setFillColor(Color::Black);
    user_hint_sin.setStyle(Text::Bold);
    user_hint_sin.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  (USER_INPUT_WIDTH - generate_button.getLocalBounds().width)/2 + (generate_button.getLocalBounds().width - generate_button_text.getLocalBounds().width)/2 - 100, 345 + 2*50);

    Text user_hint_rand("y = rand - Darck Yellow", font, 24);
    user_hint_rand.setFillColor(Color::Black);
    user_hint_rand.setStyle(Text::Bold);
    user_hint_rand.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  (USER_INPUT_WIDTH - generate_button.getLocalBounds().width)/2 + (generate_button.getLocalBounds().width - generate_button_text.getLocalBounds().width)/2 - 100, 345 + 3*50);

    // Створення обʼєкта для відображення проміжків рандомної функції
    Text text_display_written("", font, 20);
    text_display_written.setFillColor(Color::Black);
    text_display_written.setPosition(FUNCTION_GRAPH_WIDTH + 20 +70+ 100 + (USER_INPUT_WIDTH - generate_button.getLocalBounds().width)/2 + (generate_button.getLocalBounds().width - generate_button_text.getLocalBounds().width)/2,345 + 3*50);

    // Створення підказок, що має ввести користувач
    Text user_hint_F_x_move("Move and compress", font, 24);
    user_hint_F_x_move.setFillColor(Color::Black);
    user_hint_F_x_move.setStyle(Text::Bold);
    user_hint_F_x_move.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  (USER_INPUT_WIDTH - user_hint_F_x_move.getLocalBounds().width)/2, 345 + 4*50);

    Text user_hint_k("k", font, 24);
    user_hint_k.setFillColor(Color::Black);
    user_hint_k.setStyle(Text::Bold);
    user_hint_k.setPosition( FUNCTION_GRAPH_WIDTH + 20 +  5*user_hint_k.getLocalBounds().width, 345 + 5*50 + user_hint.getLocalBounds().height -24);

    Text user_hint_K("K", font, 24);
    user_hint_K.setFillColor(Color::Black);
    user_hint_K.setStyle(Text::Bold);
    user_hint_K.setPosition( FUNCTION_GRAPH_WIDTH + 20 +  5*user_hint_k.getLocalBounds().width, 345 + 8*50 + user_hint.getLocalBounds().height -7-10);

    // Створення білих прямокутників із чорною оболочкою, для візуального розуміння де буде текст та куди клікати, щоб його написати
    RectangleShape user_k_wright(Vector2f(15 * user_hint_k.getLocalBounds().width, user_hint_k.getLocalBounds().height)); 
    user_k_wright.setFillColor(Color::Transparent);
    user_k_wright.setFillColor(Color::White);
    user_k_wright.setOutlineColor(Color::Black);
    user_k_wright.setOutlineThickness(2);
    user_k_wright.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  7*user_hint_k.getLocalBounds().width, 345 + 5*50 + user_hint.getLocalBounds().height-17);

    RectangleShape user_K_wright(Vector2f(15 * user_hint_k.getLocalBounds().width, user_hint_K.getLocalBounds().height)); 
    user_K_wright.setFillColor(Color::Transparent);
    user_K_wright.setFillColor(Color::White);
    user_K_wright.setOutlineColor(Color::Black);
    user_K_wright.setOutlineThickness(2);
    user_K_wright.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  7*user_hint_k.getLocalBounds().width, 345 + 8*50 + user_hint.getLocalBounds().height-10);

    // Створення обʼєктів для відображення введеного текста
    Text text_display_written_k("", font, 24);
    text_display_written_k.setFillColor(Color::Black);
    text_display_written_k.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  7*user_hint_k.getLocalBounds().width, 345 + 5*50 + user_hint.getLocalBounds().height-24);

    Text text_display_written_K("", font, 24);
    text_display_written_K.setFillColor(Color::Black);
    text_display_written_K.setPosition(FUNCTION_GRAPH_WIDTH + 20 +  7*user_hint_k.getLocalBounds().width, 345 + 8*50 + user_hint.getLocalBounds().height-7-10);

    // Створення підказок для розуміння дій кнопок
    Text user_hint_move_x("Move by k units along the x-axis", font, 20);
    user_hint_move_x.setFillColor(Color::Black);
    user_hint_move_x.setStyle(Text::Bold);
    user_hint_move_x.setPosition(FUNCTION_GRAPH_WIDTH + 80, 345+ 5 + 6*50);

    Text user_hint_move_y("Move by k units along the y-axis", font, 20);
    user_hint_move_y.setFillColor(Color::Black);
    user_hint_move_y.setStyle(Text::Bold);
    user_hint_move_y.setPosition(FUNCTION_GRAPH_WIDTH + 80, 345+5 + 7*50);

    Text user_hint_shrink_x("Shrink by K units along the x-axis", font, 20);
    user_hint_shrink_x.setFillColor(Color::Black);
    user_hint_shrink_x.setStyle(Text::Bold);
    user_hint_shrink_x.setPosition(FUNCTION_GRAPH_WIDTH + 80, 345+ 6 + 9*50);

    Text user_hint_shrink_y("Shrink by K units along the y-axis", font, 20);
    user_hint_shrink_y.setFillColor(Color::Black);
    user_hint_shrink_y.setStyle(Text::Bold);
    user_hint_shrink_y.setPosition(FUNCTION_GRAPH_WIDTH + 80, 345+6+ 10*50);

    // Відкриття головного вікна
    while (window.isOpen()) {

        // Створення поії
        Event event;

        // Обробка події
        while (window.pollEvent(event)){

            // Опрацювання кнопки закриття
            if (event.type == Event::Closed)
                window.close();

            // Перевіряємо, чи відбулось натискання лівої кнопки миші
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                Vector2i mousePosition = Mouse::getPosition(window);
                Vector2f mousePositionF(mousePosition.x, mousePosition.y);

                // Якщо мишка клікнула в області вводу для значення A
                if (user_A_wright.getGlobalBounds().contains(mousePositionF)) {
                    click_A = true;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області вводу для значення В
                if (user_B_wright.getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = true;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області вводу для значення N
                if (user_N_wright.getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = true;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області вводу для значення k
                if (user_k_wright.getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = true;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області вводу для значення K
                if (user_K_wright.getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = true;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області кнопки генерації
                if (generate_button.getGlobalBounds().contains(mousePositionF) || generate_button_text.getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = true;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області кнопки збереження
                if (save_button.getGlobalBounds().contains(mousePositionF) || save_button_text.getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = true;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області кнопки відкриття
                if (open_button.getGlobalBounds().contains(mousePositionF) || open_button_text.getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = true;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області кнопки про програму та розробника
                if (about_button.getGlobalBounds().contains(mousePositionF) || about_button_text.getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = true;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області кнопки для відображення індивідуальної функції
                if (f_x.get_button().getGlobalBounds().contains(mousePositionF) || f_x.get_button_text().getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(true);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області кнопки для відображення функції косинусів
                if (f_cos_x.get_button().getGlobalBounds().contains(mousePositionF) || f_cos_x.get_button_text().getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(true);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області кнопки для відображення функції сінусів
                if (f_sin_x.get_button().getGlobalBounds().contains(mousePositionF)  || f_sin_x.get_button_text().getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(true);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області кнопки для відображення випадкової функції
                if (f_rand_x.get_button().getGlobalBounds().contains(mousePositionF) || f_rand_x.get_button_text().getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(true);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області кнопки для зсуву функції по віссі абцис
                if (move_x.get_button().getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(true);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області кнопки для зсуву функції по віссі ординат
                if (move_y.get_button().getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(true);
                    compress_x.setClicked(false);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області кнопки для стиснення функції по віссі абцис
                if (compress_x.get_button().getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(true);
                    compress_y.setClicked(false);
                }

                // Якщо мишка клікнула в області кнопки для стиснення функції по віссі ординат
                if (compress_y.get_button().getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_N = false;
                    click_k = false;
                    click_K = false;
                    click_generate_button = false;
                    click_save_button = false;
                    click_open_button = false;
                    click_about_button = false;
                    f_x.setClicked(false);
                    f_cos_x.setClicked(false);
                    f_sin_x.setClicked(false);
                    f_rand_x.setClicked(false);
                    move_x.setClicked(false);
                    move_y.setClicked(false);
                    compress_x.setClicked(false);
                    compress_y.setClicked(true);
                }
            }

            // Перевірка, чи подія є введенням тексту
            if (event.type == Event::TextEntered) {

                // Якщо натиснуто в області А то можна змінювати значення А, графіки закриваються для візуального перегляду
                if(click_A){ text_input_for_A_B_k(event, text_assistant_A, text_display_written_A, number_A); F_x_.show_function(false); F_cos_.show_function(false); F_sin_.show_function(false); F_rand_.show_function(false); click_k = false; click_K = false; }
                
                // Якщо натиснуто в області В то можна змінювати значення В, графіки закриваються для візуального перегляду
                if(click_B){ text_input_for_A_B_k(event, text_assistant_B, text_display_written_B, number_B);  F_x_.show_function(false); F_cos_.show_function(false); F_sin_.show_function(false); F_rand_.show_function(false); click_k = false; click_K = false;}
                
                // Якщо натиснуто в області N то можна змінювати значення N, графіки закриваються для візуального перегляду
                if(click_N){ text_input_for_N(event, text_assistant_N, text_display_written_N, number_N);  F_x_.show_function(false); F_cos_.show_function(false); F_sin_.show_function(false); F_rand_.show_function(false); click_k = false; click_K = false;}
                
                // Якщо натиснуто в області k то можна змінювати значення k
                if(click_k) text_input_for_A_B_k(event, text_assistant_k, text_display_written_k, number_k);
                
                // Якщо натиснуто в області K то можна змінювати значення K
                if(click_K) text_input_for_K(event, text_assistant_K, text_display_written_K, number_K);
            }

            // Якщо була натиснула кнопка збереження
            if(click_save_button){
                string name_file;

                // Отримаємо введений файл та прибираємо всі символи, які відповідають за перехід на ноий рядкок
                input_file(font, name_file);
                name_file.erase(remove(name_file.begin(), name_file.end(), '\n'), name_file.end());
                
                // Якщо назва файла не порожня то працюємо з нею
                if(name_file.empty()){}
                else{
                    name_file += ".txt";
                    ofstream fout;
                    fout.open(name_file);
                    if(F_x_.get_n()==0){fout << "0 ";}
                    else{
                        // Якщо файл не відкрився, то виводимо вікно про помилку
                        if(!fout.is_open()){program_does_not_save(font, name_file);}
                        else{
                            int size = F_x_.get_n();
                            fout << size << " " << text_assistant_A << " " << text_assistant_B << " ";
                            for(int i=0; i<size; i++) fout << F_x_.get_point_coordinates_x(i) << " " << F_x_.get_point_coordinates_y(i) << " ";
                            for(int i=0; i<size; i++) fout << F_cos_.get_point_coordinates_x(i) << " " << F_cos_.get_point_coordinates_y(i) << " ";
                            for(int i=0; i<size; i++) fout << F_sin_.get_point_coordinates_x(i) << " " << F_sin_.get_point_coordinates_y(i) << " ";
                        }
                    }
                    if(F_rand_.get_n()==0){fout << "0 ";}
                    else{
                        if(!fout.is_open()){}
                        else{
                            int size = F_rand_.get_n();
                            fout << size << " " << text_assistant_A2 << " " << text_assistant_B2 << " ";
                            for(int i=0; i<size; i++) fout << F_rand_.get_point_coordinates_x(i) << " " << F_rand_.get_point_coordinates_y(i) << " ";
                        }
                    }

                    // Вивід вікна про збереження даних у файлі
                    program_save(font, name_file);

                    fout.close();
                }
                click_save_button = false;
            }

            // Якщо була натиснула кнопка відкриття
            if (click_open_button) {
                string name_file;

                // Отримаємо введений файл та прибираємо всі символи, які відповідають за перехід на ноий рядкок
                output_file(font, name_file);
                name_file.erase(remove(name_file.begin(), name_file.end(), '\n'), name_file.end());
                
                // Якщо назва файла не порожня то працюємо з нею
                if (name_file.empty()) {}
                else {
                    name_file += ".txt";
                    ifstream fin;
                    fin.open(name_file);

                    // Якщо файл не відкрився, то виводимо вікно про помилку
                    if (!fin.is_open()) {program_does_not_open(font, name_file);}
                    else {
                        int size;
                        double number;
                        fin >> size;
                        number_N = size;
                        if(size<=0){

                        }
                        else 
                        {
                            F_x_.great_points(size);
                            F_cos_.great_points(size);
                            F_sin_.great_points(size);
                            fin >> text_assistant_A >> text_assistant_B;
                            text_display_written_A.setString(text_assistant_A);
                            text_display_written_B.setString(text_assistant_B);
                            text_assistant_N = to_string(size);
                            text_display_written_N.setString(text_assistant_N);
                            number_A = stod(text_assistant_A);
                            number_B = stod(text_assistant_B);
                            for(int i=0; i<size; i++)
                            {
                                fin >> number;
                                F_x_.set_point_coordinates_x(i, number);
                                fin >> number;
                                if(number<pow(10,-15)) number = pow(10,-5);
                                F_x_.set_point_coordinates_y(i, number);
                            }
                            for(int i=0; i<size; i++)
                            {
                                fin >> number;
                                F_cos_.set_point_coordinates_x(i, number);
                                fin >> number;
                                F_cos_.set_point_coordinates_y(i, number);
                            }
                            for(int i=0; i<size; i++)
                            {
                                fin >> number;
                                F_sin_.set_point_coordinates_x(i, number);
                                fin >> number;
                                F_sin_.set_point_coordinates_y(i, number);
                            }
                            F_x_.show_function(true);
                            F_cos_.show_function(true);
                            F_sin_.show_function(true);
                            F_x_.set_n(size);
                            F_sin_.set_n(size);
                            F_cos_.set_n(size);
                        }
                        fin >> size;
                        if(size<=0){}
                        else 
                        {
                            F_rand_.great_points(size);
                            fin >> text_assistant_A2 >> text_assistant_B2;
                            number_A2 = stod(text_assistant_A2);
                            number_B2 = stod(text_assistant_B2);
                            for(int i=0; i<size; i++)
                            {
                                fin >> number;
                                F_rand_.set_point_coordinates_x(i, number);
                                fin >> number;
                                F_rand_.set_point_coordinates_y(i, number);
                            }
                            F_rand_.show_function(true);
                            F_rand_.set_n(size);
                            ostringstream oss;
                            oss << "[" << text_assistant_A2 << "; " << text_assistant_B2 << "]";
                            string result = oss.str();
                            text_display_written.setString(result);
                        }

                        // Вивід вікна про відкриття файлу з даними
                        program_open(font, name_file);
                    }
                }
                click_open_button = false;
            }                

            // Якщо була натиснула кнопка про прогграму та користувача то виводимо відповідне вікно з інформацією
            if (click_about_button){
                job_information(font);
                click_about_button = false;
            }

            // Якщо була натиснута кнопка генерації то створюємо відповідні графікі
            if(click_generate_button)
            {
                // Якщо щось не введено - виводимо помилку
                if(text_assistant_A.empty() || text_assistant_B.empty() || text_assistant_N.empty() || number_N <= 0 || number_N > 100000 ) A_B_N_were_not_entered(font);
        
                // Якщо початкове значення більше за кінцеве - змінюємо місцями та виводимо повідомлення
                if(number_A > number_B){
                    the_beginning_is_greater_than_the_end(font);

                    swap(number_A,number_B);

                    String temp = text_display_written_A.getString();
                    String temp2 = text_display_written_B.getString();

                    text_assistant_A = text_display_written_B.getString();
                    text_assistant_B = text_display_written_A.getString();

                    text_display_written_A.setString(temp2);
                    text_display_written_B.setString(temp);
                }

                F_x_.f_x(number_A, number_B, number_N, move, 2);
                F_cos_.f_x(number_A, number_B, number_N, move, 2);
                F_sin_.f_x(number_A, number_B, number_N, move, 2);
                if(!text_assistant_A2.empty() && !text_assistant_B2.empty()) F_rand_.f_x(number_A2, number_B2, number_N, move, 2);
                click_generate_button = false;
            }

            // Якщо натиснута кнопка відображення графіка то можна його відображати, якщо вона була вимкнута, а можна не відображати в проти лежному випадку - якщо вона відображала графік
            if(f_x.isClicked())
            {
                // Якщо щось не введено або змінено кількість точок і не сгенеровано функції- виводимо помилку
                if(F_x_.get_n()!=number_N || text_assistant_A.empty() || text_assistant_B.empty() || text_assistant_N.empty() || number_N <= 0 || number_N > 100000) A_B_N_were_not_entered(font);
                else{
                if(F_x_.show_function()) F_x_.show_function(false);
                else F_x_.show_function(true);
                }
                f_x.setClicked(false);
            }

            // Якщо натиснута кнопка відображення графіка то можна його відображати, якщо вона була вимкнута, а можна не відображати в проти лежному випадку - якщо вона відображала графік
            if(f_cos_x.isClicked())
            {
                // Якщо щось не введено або змінено кількість точок і не сгенеровано функції- виводимо помилку
                if(F_cos_.get_n()!=number_N || text_assistant_A.empty() || text_assistant_B.empty() || text_assistant_N.empty() || number_N <= 0 || number_N > 100000) A_B_N_were_not_entered(font);
                else{
                if(F_cos_.show_function()) F_cos_.show_function(false);
                else F_cos_.show_function(true);
                }
                f_cos_x.setClicked(false);
            }

            // Якщо натиснута кнопка відображення графіка то можна його відображати, якщо вона була вимкнута, а можна не відображати в проти лежному випадку - якщо вона відображала графік
            if(f_sin_x.isClicked())
            {
                // Якщо щось не введено або змінено кількість точок і не сгенеровано функції- виводимо помилку
                if(F_sin_.get_n()!=number_N || text_assistant_A.empty() || text_assistant_B.empty() || text_assistant_N.empty() || number_N <= 0 || number_N > 100000) A_B_N_were_not_entered(font);
                else{
                if(F_sin_.show_function()) F_sin_.show_function(false);
                else F_sin_.show_function(true);
                }
                f_sin_x.setClicked(false);
            }

            // Якщо натиснута кнопка відображення графіка то можна його відображати, якщо вона була вимкнута, а можна не відображати в проти лежному випадку - якщо вона відображала графік. А також змінити область х, яка виводиться для випадкової функції
            if(f_rand_x.isClicked())
            {
                // Якщо щось не введено або змінено кількість точок і не сгенеровано функції- виводимо помилку
                if(F_x_.get_n()!=number_N || text_assistant_N.empty() || number_N <= 0 || number_N > 100000) A_B_N_were_not_entered(font);
                else{
                if(F_rand_.show_function()) F_rand_.show_function(false);
                else F_rand_.show_function(true);
                f_rand_x.setClicked(false);

                if(F_rand_.show_function()){
                    Random_function_settings_A_B(font, text_assistant_A2, text_assistant_B2);
                    if(text_assistant_A2.empty() || text_assistant_B2.empty())
                    {
                        while (!text_assistant_A2.empty()) text_assistant_A2.pop_back();
                        while (!text_assistant_B2.empty()) text_assistant_B2.pop_back();
                    }
                    if(!text_assistant_A2.empty() && !text_assistant_B2.empty())
                    {
                        number_A2 = stod(text_assistant_A2);
                        number_B2 = stod(text_assistant_B2);
                        F_rand_.f_x(number_A2, number_B2, number_N, move, 2);
                    }
                }
                ostringstream oss;
                oss << "[" << text_assistant_A2 << "; " << text_assistant_B2 << "]";
                string result = oss.str();
                text_display_written.setString(result);
                }
                f_rand_x.setClicked(false);
            }

            // Якщо клікнута кнопка зсуву по х і вибрані графіки - перемістити храфіки по осі абцис на певну кількість одиниць
            if(move_x.isClicked()){
                if(text_assistant_k.empty()) zero_coefficient(font);
                else
                {
                    if(F_x_.show_function()) F_x_.move_x(number_k, number_N, move);
                    if(F_cos_.show_function()) F_cos_.move_x(number_k, number_N, move);
                    if(F_sin_.show_function()) F_sin_.move_x(number_k, number_N, move);
                    if(F_rand_.show_function()){
                        F_rand_.move_x(number_k, number_N, move);
                        
                        number_A2 += number_k;
                        number_B2 += number_k;

                        text_assistant_A2 = to_string(number_A2); 
                        text_assistant_B2 = to_string(number_B2);

                        text_assistant_A2 = trimFloatString(text_assistant_A2);
                        text_assistant_B2 = trimFloatString(text_assistant_B2);
                        
                        ostringstream oss;
                        oss << "[" << text_assistant_A2 << "; " << text_assistant_B2 << "]";
                        string result = oss.str();
                        text_display_written.setString(result);
                    }
                    if(!F_x_.show_function()&&!F_cos_.show_function()&&!F_sin_.show_function()&&!F_rand_.show_function() || number_N==0) there_is_a_coefficient_but_there_is_no_graph(font);
                }
                move_x.setClicked(false);
            }

            // Якщо клікнута кнопка зсуву по у і вибрані графіки - перемістити храфіки по осі ординат на певну кількість одиниць
            if(move_y.isClicked()){
                if(text_assistant_k.empty()) zero_coefficient(font);
                else
                {
                    if(F_x_.show_function()) F_x_.move_y(number_k, number_N, move);
                    if(F_cos_.show_function()) F_cos_.move_y(number_k, number_N, move);
                    if(F_sin_.show_function()) F_sin_.move_y(number_k, number_N, move);
                    if(F_rand_.show_function()) F_rand_.move_y(number_k, number_N, move);
                    if(!F_x_.show_function()&&!F_cos_.show_function()&&!F_sin_.show_function()&&!F_rand_.show_function() || number_N==0) there_is_a_coefficient_but_there_is_no_graph(font);
               }
                move_y.setClicked(false);
            }

            // Якщо клікнута кнопка стиснення по х і вибрані графіки - стиснути храфіки по осі абцис на певний коефіцієнт. А також змінити область х, яка виводиться для випадкової функції
            if(compress_x.isClicked()){
                if(text_assistant_K.empty()) zero_coefficient(font);
                else
                {
                    if(F_x_.show_function()) F_x_.compress_x(number_K, number_N);
                    if(F_cos_.show_function()) F_cos_.compress_x(number_K, number_N);
                    if(F_sin_.show_function()) F_sin_.compress_x(number_K, number_N);
                    if(F_rand_.show_function()){ 
                        F_rand_.compress_x(number_K, number_N);
                        number_A2 *= number_K;
                        number_B2 *= number_K;

                        text_assistant_A2 = to_string(number_A2); 
                        text_assistant_B2 = to_string(number_B2);

                        text_assistant_A2 = trimFloatString(text_assistant_A2);
                        text_assistant_B2 = trimFloatString(text_assistant_B2);
                        
                        ostringstream oss;
                        oss << "[" << text_assistant_A2 << "; " << text_assistant_B2 << "]";
                        string result = oss.str();
                        text_display_written.setString(result);
                    }
                    if(!F_x_.show_function()&&!F_cos_.show_function()&&!F_sin_.show_function()&&!F_rand_.show_function() || number_N==0) there_is_a_coefficient_but_there_is_no_graph(font);
                }
                compress_x.setClicked(false);
            }

            // Якщо клікнута кнопка стиснення по у і вибрані графіки - стиснути храфіки по осі ординат на певний коефіцієнт
            if(compress_y.isClicked()){
                if(text_assistant_K.empty()) zero_coefficient(font);
                else
                {
                    if(F_x_.show_function()) F_x_.compress_y(number_K, number_N);
                    if(F_cos_.show_function()) F_cos_.compress_y(number_K, number_N);
                    if(F_sin_.show_function()) F_sin_.compress_y(number_K, number_N);
                    if(F_rand_.show_function()) F_rand_.compress_y(number_K, number_N);
                    if(!F_x_.show_function()&&!F_cos_.show_function()&&!F_sin_.show_function()&&!F_rand_.show_function() || number_N==0) there_is_a_coefficient_but_there_is_no_graph(font);
                }   
                compress_y.setClicked(false);
            }
        }

        // Створення точок для малювання графіків
        CircleShape point1;
        point1.setRadius(2);
        point1.setFillColor(Color::Red);

        CircleShape point2;
        point2.setRadius(2);
        point2.setFillColor(Color(0,100,0));  

        CircleShape point3;
        point3.setRadius(2);
        point3.setFillColor(Color::Blue); 

        CircleShape point4;
        point4.setRadius(2);
        point4.setFillColor(Color(139,139,0));   

        // Відмальовка кольору фону
        window.clear(Color(109,109,109));

        // Відмальовка фону де буде наш графік
        window.draw(graph_background);
        
        // Відмаловка осі х із стрілками
        window.draw(Ox);
        window.draw(right_side_of_the_arrow_x);
        window.draw(left_side_of_the_arrow_x);

        // Відмаловка осі у із стрілками
        window.draw(Oy);
        window.draw(right_side_of_the_arrow_y);
        window.draw(left_side_of_the_arrow_y);

        // Відмаловка осі підписів осей
        window.draw(x_image);
        window.draw(y_image);

        // Відмальовка міток осей
        for (index = 0; index < 2*number_of_segments_x-1; index++)
        {
            window.draw(number_x[index]);
            if(index<=16 && index!= 8)
                window.draw(number_y[index]);
        }

        // Відмальовка одиничних відрізків
        window.draw(positive_segments_x);
        window.draw(negative_segments_x);
        window.draw(positive_segments_y);
        window.draw(negative_segments_y);

        // Відмальовка індивідуального графіка, якщо він вибраний
        if(F_x_.show_function()){
            for (index = 0; index < number_N; index++){
                point1.setPosition(F_x_.get_point_coordinates_x(index),F_x_.get_point_coordinates_y(index));
                window.draw(point1);
            }
        }

        // Відмальовка графіка косинуса, якщо він вибраний
        if(F_cos_.show_function()){
            for (index = 0; index < number_N; index++){
                point2.setPosition(F_cos_.get_point_coordinates_x(index),F_cos_.get_point_coordinates_y(index));
                window.draw(point2);
            }
        }

        // Відмальовка графіка сінуса, якщо він вибраний
        if(F_sin_.show_function()){
            for (index = 0; index < number_N; index++){
                point3.setPosition(F_sin_.get_point_coordinates_x(index),F_sin_.get_point_coordinates_y(index));
                window.draw(point3);
            }
        }

        // Відмальовка випадкового графіка, якщо він вибраний
        if (F_rand_.show_function() && !text_assistant_A2.empty() && !text_assistant_B2.empty()) {
            if(number_N==1)
            {
                point4.setPosition(F_rand_.get_point_coordinates_x(0),F_rand_.get_point_coordinates_y(0));
                point4.setFillColor(Color(184, 134, 11));
                window.draw(point4);
            }
            else{
                Vertex line[number_N];
                for (int i = 0; i < number_N - 1; i++) {    
                    line[i].position = Vector2f(F_rand_.get_point_coordinates_x(i),F_rand_.get_point_coordinates_y(i));
                    line[i].color = Color(184, 134, 11);
                    line[i + 1].position = Vector2f(F_rand_.get_point_coordinates_x(i+1),F_rand_.get_point_coordinates_y(i+1));
                    line[i + 1].color = Color(184, 134, 11);
                }
                window.draw(line, number_N, LinesStrip);
            }
        }

        // Відмальовка поля меню та шапки
        window.draw(user_background);
        window.draw(head_background);

        // Відмальовка підказок для введення, для чого тескт
        window.draw(user_hint);
        window.draw(user_hint_A);
        window.draw(user_hint_B);
        window.draw(user_hint_N);
        window.draw(user_hint_k);
        window.draw(user_hint_K);

        // Відмальовка підказок для натискання кнопок
        window.draw(user_hint_F_x); 
        window.draw(user_hint_F); 
        window.draw(user_hint_cos);
        window.draw(user_hint_sin);
        window.draw(user_hint_rand);
        window.draw(user_hint_move_x);
        window.draw(user_hint_move_y);
        window.draw(user_hint_shrink_x);
        window.draw(user_hint_shrink_y);
        window.draw(user_hint_F_x_move); 

        // Відмальовка підказок для введення, де саме буде текст
        window.draw(user_A_wright);
        window.draw(user_B_wright);
        window.draw(user_N_wright);
        window.draw(user_k_wright);
        window.draw(user_K_wright);
        
        // Відмальовка написаного користувачем значень
        window.draw(text_display_written_A);
        window.draw(text_display_written_B);
        window.draw(text_display_written_N);
        window.draw(text_display_written_k);
        window.draw(text_display_written_K);

        // відмальовка кнопок
        window.draw(about_button);
        window.draw(open_button);
        window.draw(save_button);
        window.draw(generate_button);
        window.draw(f_x.get_button());
        window.draw(f_cos_x.get_button());
        window.draw(f_sin_x.get_button());
        window.draw(f_rand_x.get_button());
        window.draw(move_x.get_button());
        window.draw(move_y.get_button());
        window.draw(compress_x.get_button());
        window.draw(compress_y.get_button());
        
    
        // Відмальовка текстів до кнопок
        window.draw(about_button_text); 
        window.draw(open_button_text); 
        window.draw(save_button_text); 
        window.draw(generate_button_text); 
        

        // Відмальовка позначки що графік вибраний
        if(F_x_.show_function())  window.draw(f_x.get_button_text());
        if(F_cos_.show_function())  window.draw(f_cos_x.get_button_text());
        if(F_sin_.show_function())  window.draw(f_sin_x.get_button_text());
        if(F_rand_.show_function() && F_rand_.show_function() && !text_assistant_A2.empty() && !text_assistant_B2.empty() ) window.draw(f_rand_x.get_button_text());

        // Відмальовка проміжка х для випадкової функції, якщо він є
        if(!text_assistant_A2.empty()) window.draw(text_display_written);

        window.display();
    }
    return 0;
}