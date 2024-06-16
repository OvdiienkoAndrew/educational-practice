#ifndef Graph_display_switch
#define Graph_display_switch

#include <SFML/Graphics.hpp>
using namespace sf;

class square_buttons_with_selection_of_displayed_functions {

    private:

    RectangleShape show_Fx;
    RectangleShape show_Fx_border;
    Text show_Fx_button_text;
    bool click_show_Fx;

    public:

    square_buttons_with_selection_of_displayed_functions(Font& font, const int& k);

    RectangleShape& get_F();

    RectangleShape& get_F_border();

    Text& get_Fx_button_text();

    bool isClicked();

    void setClicked(bool clicked);

};

#endif