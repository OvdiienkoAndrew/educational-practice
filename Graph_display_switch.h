#ifndef Graph_display_switch
#define Graph_display_switch

// Підключення бібліотеки sfml для вграфіки та простору імен sf
#include <SFML/Graphics.hpp>
using namespace sf;

// Створення класу кнопок для відображення функцій
class square_buttons_with_selection_of_displayed_functions {

    // Створюємо приватні змінні
    private:

    // Кнопка
    RectangleShape button;

    // Текст кнопки
    Text button_text;
    
    // Змінна для зберігання умови натиснення на кнопку
    bool click_button;

    // Відкриття публічного доступу
    public:

    // Оголошення конструктора з двома параметрами
    square_buttons_with_selection_of_displayed_functions(Font& font, const int& k);

    // Функція для повернення кнопки
    RectangleShape& get_button();

    // Функція для відображення тексту кнопки
    Text& get_button_text();

    // Функція для перевірки натискання на кнопку
    bool isClicked();

    // Функція для встановлення значення чи натиснута кнопка
    void setClicked(bool clicked);
};

#endif