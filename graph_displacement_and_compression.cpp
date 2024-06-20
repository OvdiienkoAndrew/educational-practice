// Підключення хедр файлу Graph_displacement_and_compression, де написані функції, які треба визначити, надати тіло.
#include "Graph_displacement_and_compression.h"

// Визначення конструктора з двома параметрами
round_buttons_for_moving_and_compressing_graphs::round_buttons_for_moving_and_compressing_graphs(Font& font, const int& k) {
    
    // Встановлення розмірру позиції та кольору кнопки
    button.setRadius(15.f);
    button.setPosition(1300, 350 + k * 50);
    button.setFillColor(Color::Transparent);
    button.setFillColor(Color::White);
    button.setOutlineColor(Color::Black);
    button.setOutlineThickness(2);

    click_button = false;
}

// Визначення функції для повернення кнопки
CircleShape& round_buttons_for_moving_and_compressing_graphs::get_button() {return button;}

// Визначення функції для перевірки натискання на кнопку
bool round_buttons_for_moving_and_compressing_graphs::isClicked() {return click_button;}

// Визначення функції для встановлення значення чи натиснута кнопка
void round_buttons_for_moving_and_compressing_graphs::setClicked(bool clicked) {click_button = clicked;}