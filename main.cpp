#include <SFML/Graphics.hpp>
#include <iostream>
#include <omp.h>

using namespace std;

#define PI 3.14159265358979323846



int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "PPS");
    sf::CircleShape circle(30);
    circle.setOrigin(30,30);

    sf::Shader shader;
    shader.loadFromFile("soft_outline.vert", sf::Shader::Vertex);
    shader.setUniform("scale", 1.5f);

    shader.loadFromFile("soft_outline.frag", sf::Shader::Fragment);
 
    while (window.isOpen() )
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
       
        window.clear(sf::Color::Black);
        circle.setFillColor(sf::Color(127,0,0));
        circle.setPosition(60,60);
        window.draw(circle, &shader);

        circle.setPosition(60, 180);
        window.draw(circle, &shader);

        circle.setPosition(180, 60);
        window.draw(circle, &shader);

        circle.setPosition(180, 180);
        window.draw(circle, &shader);

        window.display();     

    }
    return 0;
}
// #include <SFML/Graphics.hpp>
// #include <SFML/Window.hpp>


// int main()
// {
//     sf::Window window(sf::VideoMode(800, 600), "My window");

//     // run the program as long as the window is open
//     while (window.isOpen())
//     {
//         // check all the window's events that were triggered since the last iteration of the loop
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             // "close requested" event: we close the window
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
//     }

//     return 0;
// }