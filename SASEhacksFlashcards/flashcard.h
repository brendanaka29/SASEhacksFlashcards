//
// Created by matth on 9/30/2022.
//
#include <string>
using namespace std;
#ifndef FLASHCARDS_FLASHCARD_H
#define FLASHCARDS_FLASHCARD_H


class flashcard {

private:
    string question;
    string answer;

public:
    flashcard(string question, string answer){
        this->question = question;
        this->answer = answer;
    }

    string getQuestion(){
        return question;
    }

    string getAnswer(){
        return answer;
    }
};


#endif //FLASHCARDS_FLASHCARD_H
