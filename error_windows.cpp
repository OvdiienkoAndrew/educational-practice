// Підключення хедр файлу "Error_windows, де написані функції, які треба визначити, надати тіло.
#include "Error_windows.h"

// Вікно про нульовий коефіцієнт, який немає сенсу
void zero_coefficient(Font& font){

    // Створення вікна
    RenderWindow window(VideoMode(500, 200), "Notification:");

    // Створення тексту для виводу на екран
    Text Message("I don't see the point in a zero coefficient.\n\nIf you add zero, nothing changes.\n\nIf you multiply by zero, nothing remains.", font, 24);
    Message.setFillColor(Color::Black);
    Message.setPosition((500 - Message.getLocalBounds().width)/2, (200 - Message.getLocalBounds().height)/2);
    
    while (window.isOpen()) {

        Event event;

        // Обробка події
        while (window.pollEvent(event))
            // Опрацювання кнопки закриття
            if (event.type == Event::Closed)
                window.close();

        window.clear(Color::White);
        window.draw(Message);
        window.display();
    }
}

// Вікно про помилку, коли людина намагається перемістити чи масштабувати неіснуюче
void there_is_a_coefficient_but_there_is_no_graph(Font& font) {

    // Створення вікна
    RenderWindow window(VideoMode(600, 150), "Error:");

    // Створення тексту для виводу на екран
    Text Message("The function must be created and selected.", font, 24);
    Message.setFillColor(Color::Red);
    Message.setPosition((600 - Message.getLocalBounds().width)/2, (150 - Message.getLocalBounds().height)/2);
    
    while (window.isOpen()) {

        Event event;

        // Обробка події
        while (window.pollEvent(event))
            // Опрацювання кнопки закриття
            if (event.type == Event::Closed)
                window.close();

        window.clear(Color::White);
        window.draw(Message);
        window.display();
    }
}

// Вікно про помилку, коли початкове значення проміжка А і В більше ніж кінцеве
void the_beginning_is_greater_than_the_end(Font& font) {

    // Створення вікна
    RenderWindow window(VideoMode(300, 150), "Error:");

    // Створення тексту для виводу на екран
    Text Message("A must be less than B.\n\t(A, B) = (B, A).", font, 24);
    Message.setFillColor(Color::Red);
    Message.setPosition((300 - Message.getLocalBounds().width)/2, (150 - Message.getLocalBounds().height)/2);

    while (window.isOpen()) {

        Event event;

        // Обробка події
        while (window.pollEvent(event))
            // Опрацювання кнопки закриття
            if (event.type == Event::Closed)
                window.close();

        window.clear(Color::White);
        window.draw(Message);
        window.display();
    }
}

// Вікно про помилку, коли А, В чи N не введені
void A_B_N_were_not_entered(Font& font) {

    // Створення вікна
    RenderWindow window(VideoMode(500, 150), "Error:");

    // Створення тексту для виводу на екран
    Text Message("Values entered incorrectly: A, B, N.\nA < B\n0 < N <= 100 000\nAnd firstly click a button \"Generate\"", font, 24);
    Message.setFillColor(Color::Red);
    Message.setPosition((500 - Message.getLocalBounds().width)/2, (150 - Message.getLocalBounds().height)/2);

    while (window.isOpen()) {

        Event event;

        // Обробка події
        while (window.pollEvent(event))
            // Опрацювання кнопки закриття
            if (event.type == Event::Closed)
                window.close();

        window.clear(Color::White);
        window.draw(Message);
        window.display();
    }
}