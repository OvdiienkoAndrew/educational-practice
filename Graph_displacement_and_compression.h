#ifndef Graph_displacement_and_compression
#define Graph_displacement_and_compression

// Підключення бібліотеки sfml для вграфіки та простору імен sf
#include <SFML/Graphics.hpp>
using namespace sf;

// Створення класу кнопок для переміщення та стиснення
class round_buttons_for_moving_and_compressing_graphs {

    // Створюємо приватні змінні
    private:

    // Кнопка
    CircleShape button;

    // Змінна для зберігання умови натиснення на кнопку
    bool click_button;

    // Відкриття публічного доступу
    public:

    // Оголошення конструктора з двома параметрами
    round_buttons_for_moving_and_compressing_graphs(Font& font, const int& k);

    // Функція для повернення кнопки
    CircleShape& get_button();

    // Функція для перевірки натискання на кнопку
    bool isClicked();

    // Функція для встановлення значення чи натиснута кнопка
    void setClicked(bool clicked);
};

#endif