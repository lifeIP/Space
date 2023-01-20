#include <SFML/Graphics.hpp>
#include <iostream>

#include <functional>

void mini_start_window(sf::RenderWindow* window) {
    window->setActive(true);
    window->close();
    window->create(sf::VideoMode(400, 200), "My window", sf::Style::None);
    
    //customizing the appearance of the window+
    sf::Texture texture;
    if (!texture.loadFromFile(".\\foto\\science, plans, additive technologies, minimalism, black and white, logo, 3d.png"))
    {
        return;
    }
    sf::RectangleShape rect;
    rect.setTexture(&texture, 0);
    rect.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    //customizing the appearance of the window-
    
    window->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width/2 - window->getSize().x/2, 
        sf::VideoMode::getDesktopMode().height/2 - window->getSize().y / 2));

    // the rendering loop
    while (window->isOpen())
    {
        sf::Event some_event;

        while (window->pollEvent(some_event))
        {
            if (some_event.type == sf::Event::EventType::KeyPressed) {
                switch (some_event.key.code)
                {
                case sf::Keyboard::E:
                    break;
                case sf::Keyboard::Escape:
                    window->close();
                    break;
                }
            }
            else if (some_event.type == sf::Event::EventType::MouseButtonReleased) {
                switch (some_event.mouseButton.button)
                {
                case sf::Mouse::Left:
                    break;
                case sf::Mouse::Right:

                    break;
                }
            }
        }
        
        window->clear(sf::Color::Black);
        window->draw(rect);
        window->display();
    }
    return;
}

int main()
{
    sf::RenderWindow window;
    
    bool flags[20];

    sf::Thread thread(mini_start_window, &window);
    thread.launch();

    //everything you need to work is loaded here+

    //everything you need to work is loaded here-

    while (window.isOpen())
    {
        sf::Event some_event;

        while (window.pollEvent(some_event))
        {
            if (some_event.type == sf::Event::EventType::KeyPressed) {
                switch (some_event.key.code)
                {
                case sf::Keyboard::E:
                    break;
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                }
            }
            else if (some_event.type == sf::Event::EventType::MouseButtonReleased) {
                switch (some_event.mouseButton.button)
                {
                case sf::Mouse::Left:
                    break;
                case sf::Mouse::Right:

                    break;
                }
            }
        }

    }
    return 0;
}