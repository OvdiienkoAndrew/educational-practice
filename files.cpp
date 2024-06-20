// Підключення хедр файлу Files, де написані функції, які треба визначити, надати тіло.
#include "Files.h"

// Фунуція для записання дданних у файл
void input_file(Font& font, string& str) {

    string text;

    // Створення вікна
    RenderWindow window(VideoMode(1700, 800),"Input file");

    // Створення підказок, що має ввести користувач
    Text user_hint_Message("Write the path and file name and it will be saved in txt format.\n\n\t\t\t\tIf the text does not fit, enter it using Enter.", font, 24);
    user_hint_Message.setFillColor(Color::Black);
    user_hint_Message.setPosition((1700 - user_hint_Message.getLocalBounds().width)/2, 2*user_hint_Message.getLocalBounds().height);
    
    // Створення білих прямокутників із чорною оболочкою візуального розуміння де буде текст та куди клікати, щоб його написати
    RectangleShape user_wright(Vector2f(1680, 3*user_hint_Message.getLocalBounds().height)); 
    user_wright.setFillColor(Color::Transparent);
    user_wright.setFillColor(Color::White);
    user_wright.setOutlineColor(Color::Black);
    user_wright.setOutlineThickness(2);
    user_wright.setPosition(10, 5*user_hint_Message.getLocalBounds().height);

    // Створення обʼєктів для відображення введеного тексту
    Text text_display_written("", font, 24);
    text_display_written.setFillColor(Color::Black);
    text_display_written.setPosition(10, 5*user_hint_Message.getLocalBounds().height);

    // Створення прямокутної кнопки
    RectangleShape save_button(Vector2f(100, user_hint_Message.getLocalBounds().height/2));
    save_button.setFillColor(Color::White);
    save_button.setPosition((1700 - save_button.getLocalBounds().width)/2, 3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height + ((3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height) - save_button.getLocalBounds().height)/2);

    // Створення грані для кнопки
    RectangleShape save_button_border(Vector2f(100, 50));
    save_button_border.setFillColor(Color::Transparent);
    save_button_border.setOutlineColor(Color::Black);
    save_button_border.setOutlineThickness(2);
    save_button_border.setPosition((1700 - save_button.getLocalBounds().width)/2, 3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height + ((3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height) - save_button.getLocalBounds().height)/2);

    // Створення назви кнопки
    Text save_button_text("Save", font, 24);
    save_button_text.setFillColor(Color::Black);
    save_button_text.setOrigin(save_button_text.getLocalBounds().left + save_button_text.getLocalBounds().width / 2, save_button_text.getLocalBounds().top + save_button_text.getLocalBounds().height / 2);
    save_button_text.setPosition(save_button_border.getPosition().x + save_button_border.getSize().x / 2, save_button_border.getPosition().y + save_button_border.getSize().y / 2);

    // Змінні для перевірки натискання
    bool click_user_wright = false;
    bool click_save_button = false;

    while (window.isOpen()) {

        Event event;

        // Обробка події
        while (window.pollEvent(event)) {

            // Опрацювання кнопки закриття
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                Vector2i mousePosition = Mouse::getPosition(window);
                Vector2f mousePositionF(mousePosition.x, mousePosition.y);

                // Якщо мишка клікнула в області вводу для значення файлу
                if (user_wright.getGlobalBounds().contains(mousePositionF))
                {
                    click_user_wright = true;
                    click_save_button = false;
                }

                // Якщо мишка клікнула в області кнопки зберігання
                if (save_button.getGlobalBounds().contains(mousePositionF) || save_button_border.getGlobalBounds().contains(mousePositionF) || save_button_border.getGlobalBounds().contains(mousePositionF))
                {
                    click_user_wright = false;
                    click_save_button = true;
                }
            }

            // Перевірка, чи подія є введенням тексту
            if (event.type == Event::TextEntered) {

                // Якщо вибрана область для написання назви файлу зберігання
                if(click_user_wright)
                {
                    // Якщо натиснута клавіша видалення елемента, то у випадку коли поле вводу не порожнє - видаляється останній елемент
                    if (event.text.unicode == '\b'){
                        if (!text.empty())
                            text.pop_back();
                    }
                    // Якщо клавіша не для ввидалення - додаємо символ до строки
                    else text += (event.text.unicode);
                    text_display_written.setString(text);
                }
            }
        
            // Якщо натиснута кнопка збереження, то строці, яка передається - передається на зовні, а вікно закривається
            if(click_save_button)
            {
                str = text;
                window.close(); 
            }

            window.clear(Color::White);
            window.draw(user_hint_Message);
            window.draw(user_wright);
            window.draw(text_display_written);
            window.draw(save_button);
            window.draw(save_button_border);
            window.draw(save_button_text);
            window.display();
        }
    }
}

// Функція для надання данних із файлу
void output_file(Font& font, string& text) {

    RenderWindow window(VideoMode(1700, 800),"Output file");

    // Створення вікна
    Text user_hint_Message("Write the path and file name and it will be open.\n\n\t If the text does not fit, enter it using Enter.", font, 24);
    user_hint_Message.setFillColor(Color::Black);
    user_hint_Message.setPosition((1700 - user_hint_Message.getLocalBounds().width)/2, 2*user_hint_Message.getLocalBounds().height);
    
    // Створення підказок, що має ввести користувач
    RectangleShape user_wright(Vector2f(1680, 3*user_hint_Message.getLocalBounds().height)); 
    user_wright.setFillColor(Color::Transparent);
    user_wright.setFillColor(Color::White);
    user_wright.setOutlineColor(Color::Black);
    user_wright.setOutlineThickness(2);
    user_wright.setPosition(10, 5*user_hint_Message.getLocalBounds().height);

    // Створення обʼєктів для відображення введеного тексту
    Text text_display_written("", font, 24);
    text_display_written.setFillColor(Color::Black);
    text_display_written.setPosition(10, 5*user_hint_Message.getLocalBounds().height);

    // Створення прямокутної кнопки
    RectangleShape open_button(Vector2f(100, user_hint_Message.getLocalBounds().height/2));
    open_button.setFillColor(Color::White);
    open_button.setPosition((1700 - open_button.getLocalBounds().width)/2, 3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height + ((3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height) - open_button.getLocalBounds().height)/2);

    // Створення грані для кнопки
    RectangleShape open_button_border(Vector2f(100, 50));
    open_button_border.setFillColor(Color::Transparent);
    open_button_border.setOutlineColor(Color::Black);
    open_button_border.setOutlineThickness(2);
    open_button_border.setPosition((1700 - open_button.getLocalBounds().width)/2, 3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height + ((3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height) - open_button.getLocalBounds().height)/2);

    // Створення назви кнопки
    Text open_button_text("Open", font, 24);
    open_button_text.setFillColor(Color::Black);
    open_button_text.setOrigin(open_button_text.getLocalBounds().left + open_button_text.getLocalBounds().width / 2, open_button_text.getLocalBounds().top + open_button_text.getLocalBounds().height / 2);
    open_button_text.setPosition(open_button_border.getPosition().x + open_button_border.getSize().x / 2, open_button_border.getPosition().y + open_button_border.getSize().y / 2);

    // Змінні для перевірки натискання
    bool click_user_wright = false;
    bool click_open_button = false;

    while (window.isOpen()) {

        Event event;

        // Обробка події
        while (window.pollEvent(event)) {

            // Опрацювання кнопки закриття
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                Vector2i mousePosition = Mouse::getPosition(window);
                Vector2f mousePositionF(mousePosition.x, mousePosition.y);

                // Якщо мишка клікнула в області вводу для значення файлу
                if (user_wright.getGlobalBounds().contains(mousePositionF))
                {
                    click_user_wright = true;
                    click_open_button = false;
                }

                // Якщо мишка клікнула в області кнопки зберігання
                if (open_button.getGlobalBounds().contains(mousePositionF) || open_button_border.getGlobalBounds().contains(mousePositionF) || open_button_border.getGlobalBounds().contains(mousePositionF))
                {
                    click_user_wright = false;
                    click_open_button = true;
                }
            }

            // Перевірка, чи подія є введенням тексту
            if (event.type == Event::TextEntered) {

                // Якщо вибрана область для написання назви файлу зберігання
                if(click_user_wright)
                {
                    // Якщо натиснута клавіша видалення елемента, то у випадку коли поле вводу не порожнє - видаляється останній елемент
                    if (event.text.unicode == '\b'){
                        if (!text.empty())
                            text.pop_back();
                    }
                    // Якщо клавіша не для ввидалення - додаємо символ до строки
                    else text += (event.text.unicode);
                    text_display_written.setString(text);
                }
            }

            // Якщо натиснута кнопка відкриття, то вікно закривається
            if(click_open_button)
                window.close();

            window.clear(Color::White);
            window.draw(user_hint_Message);
            window.draw(user_wright);
            window.draw(text_display_written);
            window.draw(open_button);
            window.draw(open_button_border);
            window.draw(open_button_text);
            window.display();
        }
    }
}