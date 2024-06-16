#include "Text_input.h"

void text_input_for_A_B_k(Event& event, string& text_assistant, Text& text_display_written, float& number)
{
    if (event.text.unicode == '\b'){
        if (!text_assistant.empty())
            text_assistant.pop_back();
    }
                    
    else
        if ((event.text.unicode >= '0' && event.text.unicode <= '9') || (event.text.unicode == '.' && text_assistant.find('.') == string::npos) || (event.text.unicode == '-' && text_assistant.empty()))
            text_assistant += (event.text.unicode);

    text_display_written.setString(text_assistant);
    char text[21];
    strncpy(text, text_assistant.c_str(), 20);
    number = atof(text);
}

void text_input_for_N(Event& event, string& text_assistant, Text& text_display_written, int& number)
{
    if (event.text.unicode == '\b'){
        if (!text_assistant.empty())
            text_assistant.pop_back();
    }
                    
    else
        if ((event.text.unicode >= '0' && event.text.unicode <= '9'))
            text_assistant += (event.text.unicode);

    text_display_written.setString(text_assistant);
    char text[21];
    strncpy(text, text_assistant.c_str(), 20);
    number = atof(text);
}

void text_input_for_K(Event& event, string& text_assistant, Text& text_display_written, float& number)
{
    if (event.text.unicode == '\b'){
        if (!text_assistant.empty())
            text_assistant.pop_back();
    }
                    
    else
        if ((event.text.unicode >= '0' && event.text.unicode <= '9') || (event.text.unicode == '.' && text_assistant.find('.') == string::npos))
            text_assistant += (event.text.unicode);

    text_display_written.setString(text_assistant);
    char text[21];
    strncpy(text, text_assistant.c_str(), 20);
    number = atof(text);
}