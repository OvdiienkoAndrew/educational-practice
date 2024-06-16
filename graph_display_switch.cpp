#include "Graph_display_switch.h"

square_buttons_with_selection_of_displayed_functions::square_buttons_with_selection_of_displayed_functions(Font& font, const int& k) {
    show_Fx.setSize(Vector2f(30, 30));
    show_Fx.setPosition(1300, 350 + k*50);
    show_Fx.setFillColor(Color::White);

    show_Fx_border.setSize(Vector2f(30, 30));
    show_Fx_border.setFillColor(Color::Transparent);
    show_Fx_border.setOutlineColor(Color::Black);
    show_Fx_border.setOutlineThickness(2);
    show_Fx_border.setPosition(1300, 350 + k*50);

    show_Fx_button_text.setFont(font);
    show_Fx_button_text.setString("+");
    show_Fx_button_text.setCharacterSize(24);
    show_Fx_button_text.setFillColor(Color::Black);

    FloatRect textBounds = show_Fx_button_text.getLocalBounds();
    show_Fx_button_text.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
    show_Fx_button_text.setPosition(1300 + show_Fx.getSize().x / 2, 350 + k * 50 + show_Fx.getSize().y / 2);

    click_show_Fx = false;
}

RectangleShape& square_buttons_with_selection_of_displayed_functions::get_F() {return show_Fx;}

RectangleShape& square_buttons_with_selection_of_displayed_functions::get_F_border() {return show_Fx_border;}

Text& square_buttons_with_selection_of_displayed_functions::get_Fx_button_text() {return show_Fx_button_text;}

bool square_buttons_with_selection_of_displayed_functions::isClicked(){return click_show_Fx;}

void square_buttons_with_selection_of_displayed_functions::setClicked(bool clicked) {click_show_Fx = clicked;}