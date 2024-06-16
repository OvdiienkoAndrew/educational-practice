#include "Graph_displacement_and_compression.h"

round_buttons_for_moving_and_compressing_graphs::round_buttons_for_moving_and_compressing_graphs(Font& font, const int& k) {
    
    show_Fx.setRadius(15.f);
    show_Fx.setPosition(1300, 350 + k * 50);
    show_Fx.setFillColor(Color::White);

    show_Fx_border.setRadius(15.f);
    show_Fx_border.setFillColor(Color::Transparent);
    show_Fx_border.setOutlineColor(Color::Black);
    show_Fx_border.setOutlineThickness(2);
    show_Fx_border.setPosition(1300, 350 + k * 50);

    click_show_Fx = false;
}

CircleShape& round_buttons_for_moving_and_compressing_graphs::get_F() {return show_Fx;}

CircleShape& round_buttons_for_moving_and_compressing_graphs::get_F_border() {return show_Fx_border;}

bool round_buttons_for_moving_and_compressing_graphs::isClicked() {return click_show_Fx;}

void round_buttons_for_moving_and_compressing_graphs::setClicked(bool clicked) {click_show_Fx = clicked;}