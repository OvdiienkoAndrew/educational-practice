// Підключення хедр файлу Graph_displacement_and_compression, де написані функції, які треба визначити, надати тіло.
#include "Graph_display_switch.h"

// Визначення конструктора з двома параметрами
square_buttons_with_selection_of_displayed_functions::square_buttons_with_selection_of_displayed_functions(Font& font, const int& k) {
    
    // Встановлення розмірру позиції та кольору кнопки
    button.setSize(Vector2f(30, 30));
    button.setPosition(1300, 350 + k*50);
    button.setFillColor(Color::Transparent);
    button.setFillColor(Color::White);
    button.setOutlineColor(Color::Black);
    button.setOutlineThickness(2);

    // Встановлення шрифта, текста, розмірата кольора
    button_text.setFont(font);
    button_text.setString("+");
    button_text.setCharacterSize(24);
    button_text.setFillColor(Color::Black);

    // Централізація текста відносно кнопки
    button_text.setOrigin(button_text.getLocalBounds().left + button_text.getLocalBounds().width / 2, button_text.getLocalBounds().top + button_text.getLocalBounds().height / 2);
    button_text.setPosition(1300 + button.getSize().x / 2, 350 + k * 50 + button.getSize().y / 2);

    click_button = false;
}

// Визначення функції для повернення кнопки
RectangleShape& square_buttons_with_selection_of_displayed_functions::get_button() {return button;}

// Визначення функції для повернення текста кнопки
Text& square_buttons_with_selection_of_displayed_functions::get_button_text() {return button_text;}

// Визначення функції для перевірки натискання на кнопку
bool square_buttons_with_selection_of_displayed_functions::isClicked() {return click_button;}

// Визначення функції для встановлення значення чи натиснута кнопка
void square_buttons_with_selection_of_displayed_functions::setClicked(bool clicked) {click_button = clicked;}