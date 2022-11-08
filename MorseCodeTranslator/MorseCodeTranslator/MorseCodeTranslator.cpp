// MorseCodeTranslator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once

#include <iostream>
#include <sstream>
#include "functions.h"
#include <string.h>
#include <Windows.h>

using namespace std;

int main() {
    string userInput;
    string morseCode;

    //until the user quits the program, option to input string or play resultant sound
    while (userInput != "exit") {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Morse Code Translation App" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << endl;
        cout << "Enter the phrase to be translated: ";
        getline(cin >> ws, userInput);
        istringstream parse(userInput);

        morseCode = morseToText(userInput);
        cout << morseCode << endl;

        while (userInput != "new" || userInput != "q") {
            cout << "~~Type 'play' to play the sound~~~~~~~~~" << endl;
            cout << "~~Type 'new' to enter a new translation~" << endl;
            cout << "~~Type 'exit' to close the application~~" << endl;

            cin >> userInput;

            if (userInput == "play") {
                //play morse code sound
                playMorseSound(morseCode);
            }
            else if (userInput == "new") {
                //start new translation
                cout << "New Translation" << endl;
                break;
            }
            else if (userInput == "exit") {
                cout << "Request to exit acknowledged" << endl;
                cout << "Goodbye!" << endl;
                Sleep(1000);
                break;
            }

        }

        //clear terminal
        Clear();
    }
}