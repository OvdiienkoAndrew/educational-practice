#!/bin/bash
# Відкривання командної строки в данному середовищі

# Компіляція програми та встановлення шляху до OpenGL
g++ main.cpp files.cpp error_windows.cpp text_input.cpp functions.cpp f_x.cpp f_cos.cpp f_sin.cpp f_rand.cpp additional_windows.cpp additional_functions.cpp graph_display_switch.cpp graph_displacement_and_compression.cpp -o Graph_of_a_function -I/opt/homebrew/include -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lglfw -framework OpenGL

# Відкривання
./Graph_of_a_function
