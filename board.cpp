#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include "board.h"
#include "flashcard.h"
using namespace sf;
using namespace std;


board::board()
{
    if (!font.loadFromFile("coha.ttf"))
    {
        // error...
    }

    title.setFont(font);
    // set the string to display
    title.setString("Welcome to Flashcards");
    // set the character size
    title.setCharacterSize(80); // in pixels, not points!
    // set the color
    title.setFillColor(sf::Color::Black);
    // set the text style
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);
    title.setPosition(80, 10);

    showAnswer = false; //don't show answer until screen is pressed
    showNext = false;

}

void board::SetQuestion(string question)
{
    if (!font.loadFromFile("coha.ttf")) //todo: we can change font if we want
    {
        // error... (got this from sfml website, not sure whats supposed to happen here)
    }

    questionText.setFont(font);
    // set the string to display
    questionText.setString(question);

    // set the character size
    questionText.setCharacterSize(50); // in pixels, not points!

    // set the color
    questionText.setFillColor(sf::Color::Black);

    // set the text style
    //questionText.setStyle(sf::Text::Bold); //not sure if we want bold, underlined, etc...

    // set the position of the text
    questionText.setPosition(50, 300);
}

void board::SetAnswer(string answer)
{
    if (!font.loadFromFile("coha.ttf")) //todo: we can change font if we want
    {
        // error... (got this from sfml website, not sure whats supposed to happen here)
    }

    answerText.setFont(font);
    // set the string to display
    answerText.setString(answer);

    // set the character size
    answerText.setCharacterSize(50); // in pixels, not points!

    // set the color
    answerText.setFillColor(sf::Color::Black);

    // set the text style
    //answerText.setStyle(sf::Text::Bold); //not sure if we want bold, underlined, etc...

    // set the position of the text
    answerText.setPosition(50, 500);
}

//void board::SetButtons(vector<flashcard>& theList, string newQuestion, string newAnswer)
//{
//    Event event;
//    flashcard* current = new flashcard(newQuestion, newAnswer);
//
//    int third = theList.size() / 3;
//    int twoThird = 2 * (theList.size() / 3);
//    theList.erase(theList.begin());
//
//    if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 400 && event.mouseButton.x < 600 && event.mouseButton.y > 800 && event.mouseButton.y < 1000) {
//        //cout << "easy" << endl;
//        theList.insert(theList.begin() + third, *current);
//    }
//    if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 600 && event.mouseButton.x < 800 && event.mouseButton.y > 800 && event.mouseButton.y < 1000) {
//        theList.insert(theList.begin() + twoThird, *current);
//        //cout << "medium" << endl;
//    }
//    if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 800 && event.mouseButton.x < 1000 && event.mouseButton.y > 800 && event.mouseButton.y < 1000) {
//        //cout << "hard" << endl;
//        theList.push_back(*current);
//    }
//}


void board::DrawBoard(vector<flashcard>& theList, string newQuestion, string newAnswer)
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    window.setTitle("Flashcards");
    /*SetQuestion(theList[0].getQuestion());
    SetAnswer(theList[0].getAnswer());*/

    while (window.isOpen())
    {
        /*cout << "current vector: " << endl;
        for (int i = 0; i < theList.size(); i++) {
            cout << theList[i].getQuestion() << endl;
            cout << theList[i].getAnswer() << endl;
        }*/
       
            SetQuestion(theList[0].getQuestion());
            SetAnswer(theList[0].getAnswer());
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            // if screen was pressed again while answer is showing, move on to next question
            if (showAnswer == true) {
                
                //showAnswer = false;
            }

            if (event.type == sf::Event::Closed)
                window.close();
        
            if (event.type == Event::MouseButtonPressed) { // if flashcard is pressed, set showAnswer = true
                /*cout << event.mouseButton.x << endl;
                cout << event.mouseButton.y << endl;*/
                if (event.mouseButton.x < 1000 && event.mouseButton.y < 800) {
                    showAnswer = true;
                }
            }

            //BRENDAS CODE
     
            if (showAnswer == true && event.type == sf::Event::MouseButtonPressed && event.mouseButton.y > 800 && event.mouseButton.y < 1000) {
                string newQuestion = theList[0].getQuestion();
                string newAnswer = theList[0].getAnswer();
                flashcard* current = new flashcard(newQuestion, newAnswer);

                int third = theList.size() / 3;
                int twoThird = 2 * (theList.size() / 3);

                if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 400 && event.mouseButton.x < 600 && event.mouseButton.y > 800 && event.mouseButton.y < 1000) {
                    //cout << "easy" << endl;
                    theList.push_back(*current);
                    
                    showNext = true;
                    showAnswer = false;

                }
                if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 600 && event.mouseButton.x < 800 && event.mouseButton.y > 800 && event.mouseButton.y < 1000) {
                    theList.insert(theList.begin() + twoThird, *current);
                    //cout << "medium" << endl;
                    showNext = true;
                    showAnswer = false;
                }
                if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 800 && event.mouseButton.x < 1000 && event.mouseButton.y > 800 && event.mouseButton.y < 1000) {
                    //cout << "hard" << endl;
                    theList.insert(theList.begin() + third, *current);
                    showNext = true;
                    showAnswer = false;
                }
                
                theList.erase(theList.begin());
                //cout << "erasing" << endl;
                /*for (int i = 0; i < theList.size(); i++) {
                    cout << theList[i].getQuestion() << endl;
                    cout << theList[i].getAnswer() << endl;
                }*/
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
            bluesprite.setPosition(sf::Vector2f(600, 800));
        }
        if (green.loadFromFile("green.png")) {
            greensprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
            greensprite.setTexture(green);
            greensprite.setPosition(sf::Vector2f(400, 800));
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

        window.clear(sf::Color(255, 253, 208, 255));

        if (showAnswer == true) { // if the screen was pressed, show answer
            //cout << "show answer" << endl;
            window.draw(answerText);
        }

        //window.draw(shape);
        window.draw(redsprite);
        window.draw(bluesprite);
        window.draw(greensprite);
        window.draw(easysprite);
        window.draw(mediumsprite);
        window.draw(hardsprite);
   

        window.draw(questionText);
        window.draw(title);
        window.display();

    }

   
}
