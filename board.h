#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "flashcard.h"
using namespace std;
using namespace sf;


class board {
	//add sprites here (buttons)
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

	sf::Font font;
	sf::Text questionText;
	sf::Text answerText;
	sf::Text title; //do we want title?
	bool showAnswer;
	bool showNext;

public:
	void DrawBoard(vector<flashcard>& theList, string newQuestion, string newAnswer);
	board();
	void SetQuestion(string question); //sets text to show question on board
	void SetAnswer(string answer);
	//void SetButtons(vector<flashcard>& theList, string newQuestion, string newAnswer);
};