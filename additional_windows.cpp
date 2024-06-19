// Підключення хедр файлу Additional_windows, де написані функції, які треба визначити, надати тіло.
#include "Additional_windows.h"
// Підключення хедр файлів Text_input та Error_windows, для використання в цьому модулі функцій з цих файлів
#include "Text_input.h"
#include "Error_windows.h"

// Додавання проміжків для рандомної функції
void Random_function_settings_A_B(Font& font, string& A, string& B) {

    // Створення вікна
    RenderWindow window(VideoMode(500, 250), "Introduce an additional interval for the rand function");

    //Створення підказок, що має ввести користувач
    Text user_hint("User Input", font, 24);
    user_hint.setFillColor(Color::Black);
    user_hint.setStyle(Text::Bold);
    user_hint.setPosition((500 - user_hint.getLocalBounds().width)/2,10);

    Text user_hint_A("A", font, 24);
    user_hint_A.setFillColor(Color::Black);
    user_hint_A.setStyle(Text::Bold);
    user_hint_A.setPosition(5*user_hint_A.getLocalBounds().width, 50 + user_hint.getLocalBounds().height);

    Text user_hint_B("B", font, 24);
    user_hint_B.setFillColor(Color::Black);
    user_hint_B.setStyle(Text::Bold);
    user_hint_B.setPosition(5*user_hint_A.getLocalBounds().width, 100 + user_hint.getLocalBounds().height + user_hint_B.getLocalBounds().height);

    // Створення білих прямокутників із чорною оболочкою візуального розуміння де буде текст та куди клікати, щоб його написати
    RectangleShape user_A_wright(Vector2f(15 * user_hint_A.getLocalBounds().width, user_hint_A.getLocalBounds().height)); 
    user_A_wright.setFillColor(Color::Transparent);
    user_A_wright.setFillColor(Color::White);
    user_A_wright.setOutlineColor(Color::Black);
    user_A_wright.setOutlineThickness(2);
    user_A_wright.setPosition(7*user_hint_A.getLocalBounds().width, 57 + user_hint.getLocalBounds().height);

    RectangleShape user_B_wright(Vector2f(15 * user_hint_A.getLocalBounds().width, user_hint_A.getLocalBounds().height)); 
    user_B_wright.setFillColor(Color::Transparent);
    user_B_wright.setFillColor(Color::White);
    user_B_wright.setOutlineColor(Color::Black);
    user_B_wright.setOutlineThickness(2);
    user_B_wright.setPosition(7*user_hint_A.getLocalBounds().width, 107 + user_hint.getLocalBounds().height + user_hint_B.getLocalBounds().height);

    // Створення обʼєктів для відображення введеного тексту
    Text text_display_written_A("", font, 24);
    text_display_written_A.setFillColor(Color::Black);
    text_display_written_A.setPosition(7*user_hint_A.getLocalBounds().width, 50 + user_hint.getLocalBounds().height);

    Text text_display_written_B("", font, 24);
    text_display_written_B.setFillColor(Color::Black);
    text_display_written_B.setPosition(7*user_hint_A.getLocalBounds().width,  100 + user_hint.getLocalBounds().height + user_hint_B.getLocalBounds().height);

    // Створення прямокутної кнопки
    RectangleShape generate_button(Vector2f(150, 50));
    generate_button.setPosition((500 - generate_button.getLocalBounds().width)/2, (150 + user_hint.getLocalBounds().height + user_hint_B.getLocalBounds().height));
    generate_button.setFillColor(Color::White);

    // Створення грані для кнопки
    RectangleShape generate_button_border(Vector2f(150, 50));
    generate_button_border.setPosition((500 - generate_button.getLocalBounds().width)/2, (150 + user_hint.getLocalBounds().height + user_hint_B.getLocalBounds().height));
    generate_button_border.setOutlineThickness(2);
    generate_button_border.setOutlineColor(Color::Black);
    generate_button_border.setFillColor(Color::Transparent);

    // Створення назви кнопки
    Text generate_button_text("Generate", font, 24);
    generate_button_text.setFillColor(Color::Black);
    generate_button_text.setOrigin(generate_button_text.getLocalBounds().left + generate_button_text.getLocalBounds().width / 2, generate_button_text.getLocalBounds().top + generate_button_text.getLocalBounds().height / 2);
    generate_button_text.setPosition(generate_button_border.getPosition().x + generate_button_border.getSize().x / 2, generate_button_border.getPosition().y + generate_button_border.getSize().y / 2);
    
    // Змінні для розрахункових дій
    float number_A = 0.0;
    float number_B = 0.0;

    // Змінні для перевірки натискання
    bool click_A = false;
    bool click_B = false;
    bool click_generate_button = false;

    // змінні для перевірки вводу
    string text_assistant_A;
    string text_assistant_B;

    while (window.isOpen()) {

        Event event;

        // Обробка події
        while (window.pollEvent(event)) {

            // Опрацювання кнопки закриття
            if (event.type == Event::Closed)
                window.close();

            // Опрацювання кліку миші
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                Vector2i mousePosition = Mouse::getPosition(window);
                Vector2f mousePositionF(mousePosition.x, mousePosition.y);

                // Якщо мишка коікнула в області вводу для значення А
                if (user_A_wright.getGlobalBounds().contains(mousePositionF)) {
                    click_A = true;
                    click_B = false;
                    click_generate_button = false;
                }

                // Якщо мишка коікнула в області вводу для значення И
                if (user_B_wright.getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = true;
                    click_generate_button = false;
                }

                // Якщо мишка коікнула в області кнопки генерації
                if (generate_button.getGlobalBounds().contains(mousePositionF) || generate_button_border.getGlobalBounds().contains(mousePositionF) || generate_button_text.getGlobalBounds().contains(mousePositionF)) {
                    click_A = false;
                    click_B = false;
                    click_generate_button = true;
                }
            }

            // Опрацювання дій коли користувач вводить текст
            if (event.type == Event::TextEntered) {
                // Якщо клікнули в області вводу А - можна вводити числа в області А і вони будуть зберігатися та відтворюватися на екрані
                if(click_A)
                    text_input_for_A_B_k(event, text_assistant_A, text_display_written_A, number_A);
                
                // Якщо клікнули в області вводу В - можна вводити числа в області В і вони будуть зберігатися та відтворюватися на екрані
                if(click_B)
                    text_input_for_A_B_k(event, text_assistant_B, text_display_written_B, number_B);
            }
            
            // Якщо натиснута кнопка генерації
            if(click_generate_button)
            {
                // Якщо значення А та В порожні - виводиться вікно про помилку
                if(text_assistant_A.empty() || text_assistant_B.empty())
                    A_B_N_were_not_entered(font);
        
                // Якщо початкове значення більше ніж кінцеве - змінити місцями значення А та В, вивісти відповідне повідомлення
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

                // Надання значень проміжків, які було написані в цьому вікні.
                A = text_assistant_A;
                B = text_assistant_B;

                window.close();
            }
        
        }

        window.clear(Color::White);

        window.draw(user_hint);
        window.draw(user_hint_A);
        window.draw(user_hint_B);

        window.draw(user_A_wright);
        window.draw(user_B_wright);

        window.draw(generate_button);
        window.draw(generate_button_border); 
        window.draw(generate_button_text);

        window.draw(text_display_written_A);
        window.draw(text_display_written_B); 

        window.display();
 
    }
}

// Вікно з інформацією про програму та користувача
void job_information(Font& font){

    // Створення вікна
    RenderWindow window(VideoMode(1700, 900), "Job_information");

    // Створення тексту для повідомлення
    char text[] = "Program name: Graph of a function.\n\nAuthor's name: Andrey.\n\nAuthor's last name: Ovdienko.\n\nAuthor's patronymic: Vladimirovich.\n\nGender: male.\n\nDate of birth: 05/17/2005.\n\nPlace of study: Faculty of Applied Mathematics (113) DNU named after. Olesya Gonchar.\n\nGroup: PA-22-2.\n\nProgramming language: C++.\n\nArchitectural Software: Apple M1 Pro.\n\nPurpose: educational practice.\n\nMission: Demonstrate programming skills in C++, as well as knowledge of OOP.\n\nMain library: SFML.\n\nDownload the core library and learn how to use it: https://www.sfml-dev.org/.\n\nTarget audience: people involved in graphical programming.\n\nReason for choosing SFML: completing the course \"Computer Graphics and Animation\" in the C++ programming language, using OpenGL libraries.";

    // Створення тексту для виводу на екран
    Text Message(text, font, 24);
    Message.setFillColor(Color::Black);
    Message.setStyle(Text::Bold);
    Message.setPosition((1700 - Message.getLocalBounds().width)/2, (900 - Message.getLocalBounds().height)/2);

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

// Вікно з інформацією про упішне збереження
void program_save(Font& font, string& text){

    // Створення вікна
    RenderWindow window(VideoMode(500, 500), "");

    string str = "Program saved: " + text;
    
    // Створення тексту для виводу на екран
    Text Message(str, font, 24);
    Message.setFillColor(Color::Black);
    Message.setStyle(Text::Bold);
    Message.setPosition((500 - Message.getLocalBounds().width)/2, (250 - Message.getLocalBounds().height)/2);

    // Створення прямокутної кнопки
    RectangleShape ok_button(Vector2f(100, 100));
    ok_button.setFillColor(Color::White);
    ok_button.setPosition((500 - ok_button.getLocalBounds().width)/2, (500 - Message.getLocalBounds().height)/2 + 3*Message.getLocalBounds().height );

    // Створення грані для кнопки
    RectangleShape ok_button_border(Vector2f(100, 50));
    ok_button_border.setFillColor(Color::Transparent);
    ok_button_border.setOutlineColor(Color::Black);
    ok_button_border.setOutlineThickness(2);
    ok_button_border.setPosition((500 - ok_button.getLocalBounds().width)/2, (500 - Message.getLocalBounds().height)/2 + 3*Message.getLocalBounds().height );

    // Створення назви кнопки
    Text ok_button_text("OK", font, 24);
    ok_button_text.setFillColor(Color::Black);
    ok_button_text.setOrigin(ok_button_text.getLocalBounds().left + ok_button_text.getLocalBounds().width / 2, ok_button_text.getLocalBounds().top + ok_button_text.getLocalBounds().height / 2);
    ok_button_text.setPosition(ok_button_border.getPosition().x + ok_button_border.getSize().x / 2, ok_button_border.getPosition().y + ok_button_border.getSize().y / 2);

    // Змінна для перевірки натискання
    bool click_ok_button = false;

    while (window.isOpen()) {

        Event event;

        // Обробка події
        while (window.pollEvent(event)) {

            // Опрацювання кнопки закриття
            if (event.type == Event::Closed)
                window.close();

            // Опрацювання кліку пиші
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                Vector2i mousePosition = Mouse::getPosition(window);
                Vector2f mousePositionF(mousePosition.x, mousePosition.y);

                // Якщо мишка коікнула в області значення кнопки згоди
                if (ok_button.getGlobalBounds().contains(mousePositionF) || ok_button_border.getGlobalBounds().contains(mousePositionF) || ok_button_text.getGlobalBounds().contains(mousePositionF))
                    click_ok_button = true;
            }
        }

        // Опрацювання дії при натиснені кнопки ОК
        if(click_ok_button)
            window.close();

        window.clear(Color::White);

        window.draw(Message);

        window.draw(ok_button);
        window.draw(ok_button_border);
        window.draw(ok_button_text);
            
        window.display();
        
    }
}

// Вікно з інформацією про упішне відкриття
void program_open(Font& font, string& text){

    // Створення вікна
    RenderWindow window(VideoMode(500, 500), "");

    string str = "Program opened: " + text;
    
    // Створення тексту для виводу на екран
    Text Message(str, font, 24);
    Message.setFillColor(Color::Black);
    Message.setStyle(Text::Bold);
    Message.setPosition((500 - Message.getLocalBounds().width)/2, (250 - Message.getLocalBounds().height)/2);

    // Створення прямокутної кнопки
    RectangleShape ok_button(Vector2f(100, 100));
    ok_button.setFillColor(Color::White);
    ok_button.setPosition((500 - ok_button.getLocalBounds().width)/2, (500 - Message.getLocalBounds().height)/2 + 3*Message.getLocalBounds().height );

    // Створення грані для кнопки
    RectangleShape ok_button_border(Vector2f(100, 50));
    ok_button_border.setFillColor(Color::Transparent);
    ok_button_border.setOutlineColor(Color::Black);
    ok_button_border.setOutlineThickness(2);
    ok_button_border.setPosition((500 - ok_button.getLocalBounds().width)/2, (500 - Message.getLocalBounds().height)/2 + 3*Message.getLocalBounds().height );

    // Створення назви кнопки
    Text ok_button_text("OK", font, 24);
    ok_button_text.setFillColor(Color::Black);
    ok_button_text.setOrigin(ok_button_text.getLocalBounds().left + ok_button_text.getLocalBounds().width / 2, ok_button_text.getLocalBounds().top + ok_button_text.getLocalBounds().height / 2);
    ok_button_text.setPosition(ok_button_border.getPosition().x + ok_button_border.getSize().x / 2, ok_button_border.getPosition().y + ok_button_border.getSize().y / 2);

    // Змінна для перевірки натискання
    bool click_ok_button = false;

    while (window.isOpen()) {

        Event event;

        // Обробка події
        while (window.pollEvent(event)) {

            // Опрацювання кнопки закриття
            if (event.type == Event::Closed)
                window.close();

            // Опрацювання кліку пиші
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                Vector2i mousePosition = Mouse::getPosition(window);
                Vector2f mousePositionF(mousePosition.x, mousePosition.y);

                // Якщо мишка коікнула в області значення кнопки згоди
                if (ok_button.getGlobalBounds().contains(mousePositionF) || ok_button_border.getGlobalBounds().contains(mousePositionF) || ok_button_text.getGlobalBounds().contains(mousePositionF))
                    click_ok_button = true;
            }
        }

        // Опрацювання дії при натиснені кнопки ОК
        if(click_ok_button)
            window.close();

        window.clear(Color::White);

        window.draw(Message);

        window.draw(ok_button);
        window.draw(ok_button_border);
        window.draw(ok_button_text);
            
        window.display();
        
    }
}

// Вікно з інформацією про невдачу зберегти файл
void program_does_not_save(Font& font, string& text){

    // Створення вікна
    RenderWindow window(VideoMode(500, 500), "");

    string str = "Program didn't save: " + text;
    
    // Створення тексту для виводу на екран
    Text Message(str, font, 24);
    Message.setFillColor(Color::Black);
    Message.setStyle(Text::Bold);
    Message.setPosition((500 - Message.getLocalBounds().width)/2, (250 - Message.getLocalBounds().height)/2);

    // Створення прямокутної кнопки
    RectangleShape ok_button(Vector2f(100, 100));
    ok_button.setFillColor(Color::White);
    ok_button.setPosition((500 - ok_button.getLocalBounds().width)/2, (500 - Message.getLocalBounds().height)/2 + 3*Message.getLocalBounds().height );

    // Створення грані для кнопки
    RectangleShape ok_button_border(Vector2f(100, 50));
    ok_button_border.setFillColor(Color::Transparent);
    ok_button_border.setOutlineColor(Color::Black);
    ok_button_border.setOutlineThickness(2);
    ok_button_border.setPosition((500 - ok_button.getLocalBounds().width)/2, (500 - Message.getLocalBounds().height)/2 + 3*Message.getLocalBounds().height );

    // Створення назви кнопки
    Text ok_button_text("OK", font, 24);
    ok_button_text.setFillColor(Color::Black);
    ok_button_text.setOrigin(ok_button_text.getLocalBounds().left + ok_button_text.getLocalBounds().width / 2, ok_button_text.getLocalBounds().top + ok_button_text.getLocalBounds().height / 2);
    ok_button_text.setPosition(ok_button_border.getPosition().x + ok_button_border.getSize().x / 2, ok_button_border.getPosition().y + ok_button_border.getSize().y / 2);

    // Змінна для перевірки натискання
    bool click_ok_button = false;

    while (window.isOpen()) {

        Event event;

        // Обробка події
        while (window.pollEvent(event)) {

            // Опрацювання кнопки закриття
            if (event.type == Event::Closed)
                window.close();

            // Опрацювання кліку пиші
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                Vector2i mousePosition = Mouse::getPosition(window);
                Vector2f mousePositionF(mousePosition.x, mousePosition.y);

                // Якщо мишка коікнула в області значення кнопки згоди
                if (ok_button.getGlobalBounds().contains(mousePositionF) || ok_button_border.getGlobalBounds().contains(mousePositionF) || ok_button_text.getGlobalBounds().contains(mousePositionF))
                    click_ok_button = true;
            }
        }

        // Опрацювання дії при натиснені кнопки ОК
        if(click_ok_button)
            window.close();

        window.clear(Color::White);

        window.draw(Message);

        window.draw(ok_button);
        window.draw(ok_button_border);
        window.draw(ok_button_text);
            
        window.display();
        
    }
}

// Вікно з інформацією про невдачу відкрити файл
void program_does_not_open(Font& font, string& text){

    // Створення вікна
    RenderWindow window(VideoMode(500, 500), "");

    string str = "Program didn't open: " + text;
    
    // Створення тексту для виводу на екран
    Text Message(str, font, 24);
    Message.setFillColor(Color::Black);
    Message.setStyle(Text::Bold);
    Message.setPosition((500 - Message.getLocalBounds().width)/2, (250 - Message.getLocalBounds().height)/2);

    // Створення прямокутної кнопки
    RectangleShape ok_button(Vector2f(100, 100));
    ok_button.setFillColor(Color::White);
    ok_button.setPosition((500 - ok_button.getLocalBounds().width)/2, (500 - Message.getLocalBounds().height)/2 + 3*Message.getLocalBounds().height );

    // Створення грані для кнопки
    RectangleShape ok_button_border(Vector2f(100, 50));
    ok_button_border.setFillColor(Color::Transparent);
    ok_button_border.setOutlineColor(Color::Black);
    ok_button_border.setOutlineThickness(2);
    ok_button_border.setPosition((500 - ok_button.getLocalBounds().width)/2, (500 - Message.getLocalBounds().height)/2 + 3*Message.getLocalBounds().height );

    // Створення назви кнопки
    Text ok_button_text("OK", font, 24);
    ok_button_text.setFillColor(Color::Black);
    ok_button_text.setOrigin(ok_button_text.getLocalBounds().left + ok_button_text.getLocalBounds().width / 2, ok_button_text.getLocalBounds().top + ok_button_text.getLocalBounds().height / 2);
    ok_button_text.setPosition(ok_button_border.getPosition().x + ok_button_border.getSize().x / 2, ok_button_border.getPosition().y + ok_button_border.getSize().y / 2);

    // Змінна для перевірки натискання
    bool click_ok_button = false;

    while (window.isOpen()) {

        Event event;

        // Обробка події
        while (window.pollEvent(event)) {

            // Опрацювання кнопки закриття
            if (event.type == Event::Closed)
                window.close();

            // Опрацювання кліку пиші
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                Vector2i mousePosition = Mouse::getPosition(window);
                Vector2f mousePositionF(mousePosition.x, mousePosition.y);

                // Якщо мишка коікнула в області значення кнопки згоди
                if (ok_button.getGlobalBounds().contains(mousePositionF) || ok_button_border.getGlobalBounds().contains(mousePositionF) || ok_button_text.getGlobalBounds().contains(mousePositionF))
                    click_ok_button = true;
            }
        }

        // Опрацювання дії при натиснені кнопки ОК
        if(click_ok_button)
            window.close();

        window.clear(Color::White);

        window.draw(Message);

        window.draw(ok_button);
        window.draw(ok_button_border);
        window.draw(ok_button_text);
            
        window.display();
        
    }
}