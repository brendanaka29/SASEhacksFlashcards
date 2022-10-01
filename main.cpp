#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
using namespace std; 

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    //sf::CircleShape shape(100.f);
    //sf::shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {   
        sf::Event event; 
        sf::Texture red;
        sf::Texture blue;
        sf::Texture green;
        sf::Sprite redsprite;
        sf::Sprite bluesprite;
        sf::Sprite greensprite;

        sf::Texture easy;
        sf::Sprite easysprite;
        sf::Texture medium;
        sf::Sprite mediumsprite;
        sf::Texture hard; 
        sf::Sprite hardsprite;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 400 && event.mouseButton.x < 600 && event.mouseButton.y > 800 && event.mouseButton.y < 1000) {
                    //cout << "easy" << endl;
                    theList.insert(theList.begin() + third, *current);
                    break;
                }
                if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 600 && event.mouseButton.x < 800 && event.mouseButton.y > 800 && event.mouseButton.y < 1000) {
                    theList.insert(theList.begin() + twoThird, *current);
                    break;
                    //cout << "medium" << endl;
                }
                if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 800 && event.mouseButton.x < 1000 && event.mouseButton.y > 800 && event.mouseButton.y < 1000) {
                    //cout << "hard" << endl;
                    theList.push_back(*current);
                    break;
                }
            }
        }
        if (red.loadFromFile("red.png")) {
            redsprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
            redsprite.setTexture(red);
            redsprite.setPosition(sf::Vector2f(800, 800));
            //sprite.scale(sf::Vector2f(2.0f,2.0f));
        }
        if (blue.loadFromFile("blue.png")) {
            bluesprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
            bluesprite.setTexture(blue);
            bluesprite.setPosition(sf::Vector2f(600,800));
        }
        if (green.loadFromFile("green.png")) {
            greensprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
            greensprite.setTexture(green);
            greensprite.setPosition(sf::Vector2f(400,800));
        }
        if (easy.loadFromFile("easy.png")) {
            easysprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
            easysprite.setTexture(easy);
            easysprite.setPosition(sf::Vector2f(440, 875));
        }
        if (medium.loadFromFile("medium.png")) {
            mediumsprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
            mediumsprite.setTexture(medium);
            mediumsprite.setPosition(sf::Vector2f(605, 875));
        }
        if (hard.loadFromFile("hard.png")) {
            hardsprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
            hardsprite.setTexture(hard);
            hardsprite.setPosition(sf::Vector2f(840, 875));
        }

        window.clear(sf::Color(255, 255, 255, 255));
        //window.draw(shape);
        window.draw(redsprite);
        window.draw(bluesprite);
        window.draw(greensprite);
        window.draw(easysprite);
        window.draw(mediumsprite);
        window.draw(hardsprite);
        window.display();
    }


    return 0;
}