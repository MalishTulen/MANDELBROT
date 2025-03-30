#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "picun.h"

const int WINDOW_LENGTH = 800;
const int WINDOW_HIGHT = 600;
const int R2MAX       = 100;

float scale = 1;
float offset_x = 0;
float offset_y = 0;

//const int START_SCALE = 1;

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({WINDOW_LENGTH, WINDOW_HIGHT}), "MANDELBROT_HUI_TE_V_ROT");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // clear the window with black color

        for (;;)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            break;}

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            offset_y --;
            std::cout << "Moving up! Offset Y: " << offset_y << std::endl;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                offset_y ++;
                std::cout << "Moving down! Offset Y: " << offset_y << std::endl;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                offset_x --;
                std::cout << "Moving left! Offset X: " << offset_x << std::endl;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                offset_x ++;
                std::cout << "Moving right! Offset X: " << offset_x << std::endl;
            }

            window.clear(sf::Color::Black);
            do_manda_v_rot ( window );
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            break;}

        //print_pixel ( window, 100, 200, sf::Color::Red );
        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }
}


int do_manda_v_rot ( sf::RenderWindow& window )
{
    for ( float iy = 0; iy < WINDOW_HIGHT; iy++ )
    {
        float y0 = ( iy - WINDOW_HIGHT/2 + offset_y )/200 * scale;

        for ( float ix = 0; ix < WINDOW_LENGTH; ix++ )
        {
            float x0 = ( ix - WINDOW_LENGTH/2 + offset_x )/200 * scale;


            float X = x0;
            float Y = y0;
            int N = 1;
            for ( ; N < 256; N++ )
            {
                float x2 = X*X;
                float y2 = Y*Y;
                float xy = X*Y;

                float r2 = x2 + y2;

                if ( r2 >= R2MAX ) break;

                X = x2 - y2 + x0;
                Y = xy + xy + y0;
            }

            if ( N < 5)
                print_pixel ( window, ix, iy, sf::Color::Red );
            else if ( N < 10)
                print_pixel ( window, ix, iy, sf::Color::Yellow );
            else if ( N < 50)
                print_pixel ( window, ix, iy, sf::Color::Green );
            else if ( N < 100)
                print_pixel ( window, ix, iy, sf::Color::Blue );
            else if ( N < 255)
                print_pixel ( window, ix, iy, sf::Color::Magenta );

        }
    }
    return 0;
}

int print_pixel ( sf::RenderWindow& window, float x, float y, sf::Color color ) //
{
        sf::RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(1, 1));
        rectangle.setFillColor(color);
        rectangle.setPosition({x, y});
        window.draw(rectangle);


        return 0;
}
