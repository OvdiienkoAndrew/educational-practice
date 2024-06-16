#ifndef Graph_displacement_and_compression
#define Graph_displacement_and_compression

#include <SFML/Graphics.hpp>
using namespace sf;

class round_buttons_for_moving_and_compressing_graphs {

    private:

    CircleShape show_Fx;
    CircleShape show_Fx_border;
    bool click_show_Fx;

    public:

    round_buttons_for_moving_and_compressing_graphs(Font& font, const int& k);

    CircleShape& get_F();

    CircleShape& get_F_border();

    bool isClicked();

    void setClicked(bool clicked);
};

#endif