#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "board.h"
using namespace sf;

#include <iostream>
#include <string>
#include "flashcard.h"
#include <vector>
#include <algorithm>
#include<fstream>
using namespace std;

void ReadFile(string file, vector<flashcard>& theList) {
    string line;
    string question = "";
    string answer = "";
    int count = 0;
    ifstream myfile("load.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
            int excalamation = line.find("!");
            question = line.substr(0, excalamation);
            answer = line.substr(excalamation + 1);
            flashcard* current = new flashcard(question, answer);
            theList.push_back(*current);
        }
        myfile.close();
    }
    else {
        cout << "Unable to open file";
    }
    /*for (int i = 0; i < theList.size(); i++) {
        cout << "question: " << theList[i].getQuestion() << endl;
        cout << "answer: " << theList[i].getAnswer() << endl;
    }*/
}

void WriteFile(vector<flashcard>& theList) {
    ofstream MyFile("load.txt");

    for (int i = 0; i < theList.size(); i++) {
        string line = theList[i].getQuestion() + "!" + theList[i].getAnswer();
        MyFile << line << endl;
    }


    // Close the file
    MyFile.close();
}

void input(vector<flashcard>& theList) {
    string question = "";
    string answer = "";

    while (true) {
        cout << "Type in question" << endl;
        getline(cin, question);
        if (question == "stop") {
            break;
        }
        cout << "Type in answer" << endl;
        getline(cin, answer);
        flashcard* current = new flashcard(question, answer);
        theList.push_back(*current);
    }
    /*for (int i = 0; i < theList.size(); i++) {
        cout << theList[i].getQuestion() << endl;
        cout << theList[i].getAnswer() << endl;
    }*/
    random_shuffle(theList.begin(), theList.end());

    WriteFile(theList);
}

void options(int option, vector<flashcard>& theList) {
    string newQuestion = theList[0].getQuestion();
    string newAnswer = theList[0].getAnswer();
    flashcard* current = new flashcard(newQuestion, newAnswer);

    int third = theList.size() / 3;
    int twoThird = 2 * (theList.size() / 3);
    theList.erase(theList.begin());

    switch (option) {
    case 1:
        theList.insert(theList.begin() + third, *current);
        break;
    case 2:
        theList.insert(theList.begin() + twoThird, *current);
        break;
    case 3:
        theList.push_back(*current);
        break;
    }
}

int main() {
    //Input question and answer until the user types in stop
    vector<flashcard> theList;
    string mOrl = "";

    cout << "Would you like to manually input your flashcards (m) or load a file (l)?" << endl;
     getline(cin, mOrl);

    if (mOrl == "m") {
        input(theList);
    }
    else if (mOrl == "l") {
        //ReadFile("load.txt", theList);
    }


    /*cout << "After shuffle" << endl;
    for (int i = 0; i < theList.size(); i++) {
        cout << theList[i].getQuestion() << endl;
        cout << theList[i].getAnswer() << endl;
    }*/

    //options(1, theList);
    /*cout << "After options" << endl;
    for (int i = 0; i < theList.size(); i++) {
        cout << theList[i].getQuestion() << endl;
        cout << theList[i].getAnswer() << endl;
    }*/

    board board;
    /*board.SetQuestion(theList[0].getQuestion());
    board.SetAnswer(theList[0].getAnswer());*/
    //board.SetButtons(theList, theList[0].getQuestion(), theList[0].getAnswer());

    board.DrawBoard(theList, theList[0].getQuestion(), theList[0].getAnswer());

}