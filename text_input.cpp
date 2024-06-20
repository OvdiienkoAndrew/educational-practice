// Підключення хедр файлу Text_input, де написані функції, які треба визначити, надати тіло.
#include "Text_input.h"

// Функція для заповнення проміжків відображення функцій та коефіцієнта зсуву
void text_input_for_A_B_k(Event& event, string& text_assistant, Text& text_display_written, float& number)
{
    // Якщо наснута операція видалення, то якщо є символи в рядку є - видаляється останній
    if (event.text.unicode == '\b'){
        if (!text_assistant.empty())
            text_assistant.pop_back();
    }
                    
    else
        // Можна вводити числа від 0 до 9, лише одну крапку та мінус лише першим
        if ((event.text.unicode >= '0' && event.text.unicode <= '9') || (event.text.unicode == '.' && text_assistant.find('.') == string::npos) || (event.text.unicode == '-' && text_assistant.empty()))
            text_assistant += (event.text.unicode);

    // Надання виводу тексту на єкран введеного текста
    text_display_written.setString(text_assistant);

    // Перекидання лише 20 символів у дробову змінну
    char text[21];
    strncpy(text, text_assistant.c_str(), 20);
    number = atof(text);
}

// Функція для заповнення кількості точок для відображення графіка
void text_input_for_N(Event& event, string& text_assistant, Text& text_display_written, int& number)
{
    // Якщо наснута операція видалення, то якщо є символи в рядку є - видаляється останній
    if (event.text.unicode == '\b'){
        if (!text_assistant.empty())
            text_assistant.pop_back();
    }
                    
    else
        // Можна вводити числа від 0 до 9
        if ((event.text.unicode >= '0' && event.text.unicode <= '9'))
            text_assistant += (event.text.unicode);

    // Надання виводу тексту на єкран введеного текста
    text_display_written.setString(text_assistant);

    // Перекидання лише 20 символів у цілу змінну
    char text[21];
    strncpy(text, text_assistant.c_str(), 20);
    number = atof(text);
}

// Функція для заповнення коефіцієнта стискання
void text_input_for_K(Event& event, string& text_assistant, Text& text_display_written, float& number)
{
    // Якщо наснута операція видалення, то якщо є символи в рядку є - видаляється останній
    if (event.text.unicode == '\b'){
        if (!text_assistant.empty())
            text_assistant.pop_back();
    }
                    
    else
        // Можна вводити числа від 0 до 9 та лише одну крапку
        if ((event.text.unicode >= '0' && event.text.unicode <= '9') || (event.text.unicode == '.' && text_assistant.find('.') == string::npos))
            text_assistant += (event.text.unicode);

    // Надання виводу тексту на єкран введеного текста
    text_display_written.setString(text_assistant);

    // Перекидання лише 20 символів у дробову змінну
    char text[21];
    strncpy(text, text_assistant.c_str(), 20);
    number = atof(text);
}