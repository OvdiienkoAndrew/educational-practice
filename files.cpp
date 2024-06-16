#include "Files.h"

void input_file(Font& font, string& str) {

    string text;

    RenderWindow window(VideoMode(1700, 800),"Input file");

    Text user_hint_Message("Write the path and file name and it will be saved in txt format.\n\n\t\t\t\tIf the text does not fit, enter it using Enter.", font, 24);
    user_hint_Message.setFillColor(Color::Black);
    user_hint_Message.setPosition((1700 - user_hint_Message.getLocalBounds().width)/2, 2*user_hint_Message.getLocalBounds().height);
    
    RectangleShape user_wright(Vector2f(1680, 3*user_hint_Message.getLocalBounds().height)); 
    user_wright.setFillColor(Color::Transparent);
    user_wright.setFillColor(Color::White);
    user_wright.setOutlineColor(Color::Black);
    user_wright.setOutlineThickness(2);
    user_wright.setPosition(10, 5*user_hint_Message.getLocalBounds().height);

    Text text_display_written("", font, 24);
    text_display_written.setFillColor(Color::Black);
    text_display_written.setPosition(10, 5*user_hint_Message.getLocalBounds().height);

    RectangleShape save_button(Vector2f(100, user_hint_Message.getLocalBounds().height/2));
    save_button.setFillColor(Color::White);
    save_button.setPosition((1700 - save_button.getLocalBounds().width)/2, 3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height + ((3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height) - save_button.getLocalBounds().height)/2);

    RectangleShape save_button_border(Vector2f(100, 50));
    save_button_border.setFillColor(Color::Transparent);
    save_button_border.setOutlineColor(Color::Black);
    save_button_border.setOutlineThickness(2);
    save_button_border.setPosition((1700 - save_button.getLocalBounds().width)/2, 3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height + ((3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height) - save_button.getLocalBounds().height)/2);

    Text save_button_text("Save", font, 24);
    save_button_text.setFillColor(Color::Black);
    save_button_text.setOrigin(save_button_text.getLocalBounds().left + save_button_text.getLocalBounds().width / 2, save_button_text.getLocalBounds().top + save_button_text.getLocalBounds().height / 2);
    save_button_text.setPosition(save_button_border.getPosition().x + save_button_border.getSize().x / 2, save_button_border.getPosition().y + save_button_border.getSize().y / 2);

    bool click_user_wright = false;
    bool click_save_button = false;

    while (window.isOpen()) {

        Event event;

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                Vector2i mousePosition = Mouse::getPosition(window);
                Vector2f mousePositionF(mousePosition.x, mousePosition.y);

                if (user_wright.getGlobalBounds().contains(mousePositionF))
                {
                    click_user_wright = true;
                    click_save_button = false;
                }

                if (save_button.getGlobalBounds().contains(mousePositionF) || save_button_border.getGlobalBounds().contains(mousePositionF) || save_button_border.getGlobalBounds().contains(mousePositionF))
                {
                    click_user_wright = false;
                    click_save_button = true;
                }
            }

            if (event.type == Event::TextEntered) {

                if(click_user_wright)
                {
                    if (event.text.unicode == '\b'){
                        if (!text.empty())
                            text.pop_back();
                    } else text += (event.text.unicode);
                    text_display_written.setString(text);
                }
            }
        
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

void output_file(Font& font, string& text) {

    RenderWindow window(VideoMode(1700, 800),"Output file");

    Text user_hint_Message("Write the path and file name and it will be open.\n\n\t If the text does not fit, enter it using Enter.", font, 24);
    user_hint_Message.setFillColor(Color::Black);
    user_hint_Message.setPosition((1700 - user_hint_Message.getLocalBounds().width)/2, 2*user_hint_Message.getLocalBounds().height);
    
    RectangleShape user_wright(Vector2f(1680, 3*user_hint_Message.getLocalBounds().height)); 
    user_wright.setFillColor(Color::Transparent);
    user_wright.setFillColor(Color::White);
    user_wright.setOutlineColor(Color::Black);
    user_wright.setOutlineThickness(2);
    user_wright.setPosition(10, 5*user_hint_Message.getLocalBounds().height);

    Text text_display_written("", font, 24);
    text_display_written.setFillColor(Color::Black);
    text_display_written.setPosition(10, 5*user_hint_Message.getLocalBounds().height);

    RectangleShape open_button(Vector2f(100, user_hint_Message.getLocalBounds().height/2));
    open_button.setFillColor(Color::White);
    open_button.setPosition((1700 - open_button.getLocalBounds().width)/2, 3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height + ((3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height) - open_button.getLocalBounds().height)/2);

    RectangleShape open_button_border(Vector2f(100, 50));
    open_button_border.setFillColor(Color::Transparent);
    open_button_border.setOutlineColor(Color::Black);
    open_button_border.setOutlineThickness(2);
    open_button_border.setPosition((1700 - open_button.getLocalBounds().width)/2, 3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height + ((3*user_hint_Message.getLocalBounds().height + text_display_written.getLocalBounds().height + user_wright.getLocalBounds().height) - open_button.getLocalBounds().height)/2);

    Text open_button_text("Open", font, 24);
    open_button_text.setFillColor(Color::Black);
    open_button_text.setOrigin(open_button_text.getLocalBounds().left + open_button_text.getLocalBounds().width / 2, open_button_text.getLocalBounds().top + open_button_text.getLocalBounds().height / 2);
    open_button_text.setPosition(open_button_border.getPosition().x + open_button_border.getSize().x / 2, open_button_border.getPosition().y + open_button_border.getSize().y / 2);

    bool click_user_wright = false;
    bool click_open_button = false;

    while (window.isOpen()) {

        Event event;

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                Vector2i mousePosition = Mouse::getPosition(window);
                Vector2f mousePositionF(mousePosition.x, mousePosition.y);

                if (user_wright.getGlobalBounds().contains(mousePositionF))
                {
                    click_user_wright = true;
                    click_open_button = false;
                }

                if (open_button.getGlobalBounds().contains(mousePositionF) || open_button_border.getGlobalBounds().contains(mousePositionF) || open_button_border.getGlobalBounds().contains(mousePositionF))
                {
                    click_user_wright = false;
                    click_open_button = true;
                }
            }

            if (event.type == Event::TextEntered) {

                if(click_user_wright)
                {
                    if (event.text.unicode == '\b'){
                        if (!text.empty())
                            text.pop_back();
                    } else text += (event.text.unicode);
                    text_display_written.setString(text);
                }
            }

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