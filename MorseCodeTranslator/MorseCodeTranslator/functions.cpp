#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include <dos.h>


using namespace std;

int* alphabet(char character) {
    /*first element of the array is the size of the array,
      what follows are the morse code for the character */
    static int A[3] = { 3,1,2 };                 //dot-dash
    static int B[5] = { 5,2,1,1,1 };             //dash-dot-dot-dot
    static int C[5] = { 5,2,1,2,1 };             //dash-dot-dash-dot
    static int D[4] = { 4,2,1,1 };               //dash-dot-dot
    static int E[2] = { 2,1 };                   //dot
    static int F[5] = { 5,1,1,2,1 };             //dot-dot-dash-dot
    static int G[4] = { 4,2,2,1 };               //dash-dash-dot
    static int H[5] = { 5,1,1,1,1 };             //dot-dot-dot-dot
    static int I[3] = { 3,1,1 };                 //dot-dot
    static int J[5] = { 5,1,2,2,2 };             //dot-dash-dash-dash
    static int K[4] = { 4,2,1,2 };               //dash-dot-dash
    static int L[5] = { 5,1,2,1,1 };             //dot-dash-dot-dot
    static int M[3] = { 3,2,2 };                 //dash-dash
    static int N[3] = { 3,2,1 };                 //dash-dot
    static int O[4] = { 4,2,2,2 };               //dash-dash-dash
    static int P[5] = { 5,1,2,2,1 };             //dot-dash-dash-dot
    static int Q[5] = { 5,2,2,1,2 };             //dash-dash-dot-dash
    static int R[4] = { 4,1,2,1 };               //dot-dash-dot
    static int S[4] = { 4,1,1,1 };               //dot-dot-dot
    static int T[2] = { 2,2 };                   //dash
    static int U[4] = { 4,1,1,2 };               //dot-dot-dash
    static int V[5] = { 5,1,1,1,2 };             //dot-dot-dot-dash
    static int W[4] = { 4,1,2,2 };               //dot-dash-dash
    static int X[5] = { 5,2,1,1,2 };             //dash-dot-dot-dash
    static int Y[5] = { 5,2,1,2,2 };             //dash-dot-dash-dash
    static int Z[5] = { 5,2,2,1,1 };             //dash-dash-dot-dot
    static int one[6] = { 6,1,2,2,2,2 };         //dot-dash-dash-dash-dash
    static int two[6] = { 6,1,1,2,2,2 };         //dot-dot-dash-dash-dash
    static int three[6] = { 6,1,1,1,2,2 };       //dot-dot-dot-dash-dash
    static int four[6] = { 6,1,1,1,1,2 };        //dot-dot-dot-dot-dash
    static int five[6] = { 6,1,1,1,1,1 };        //dot-dot-dot-dot-dot
    static int six[6] = { 6,2,1,1,1,1 };         //dash-dot-dot-dot-dot
    static int seven[6] = { 6,2,2,1,1,1 };       //dash-dash-dot-dot-dot
    static int eight[6] = { 6,2,2,2,1,1 };       //dash-dash-dash-dot-dot-dot
    static int nine[6] = { 6,2,2,2,2,1 };        //dash-dash-dash-dash-dash-dot
    static int zero[6] = { 6,2,2,2,2,2 };        //dash-dash-dash-dash-dash-dash
    static int stop[7] = { 7,1,2,1,2,1,2 };      //dot-dash-dot-dash-dot-dash
    static int comma[7] = { 7,2,2,1,1,2,2 };     //dash-dash-dot-dot-dash-dash
    static int question[7] = { 7,1,1,2,2,1,1 };  //dot-dot-dash-dash-dot-dot

    //convert input to lowercase
    character = (char)tolower(character);

    //return morse code based on character input
    switch (character) {
    case 'a':
        return A;
        break;
    case 'b':
        return B;
        break;
    case 'c':
        return C;
        break;
    case 'd':
        return D;
        break;
    case 'e':
        return E;
        break;
    case 'f':
        return F;
        break;
    case 'g':
        return G;
        break;
    case 'h':
        return H;
        break;
    case 'i':
        return I;
        break;
    case 'j':
        return J;
        break;
    case 'k':
        return K;
        break;
    case 'l':
        return L;
        break;
    case 'm':
        return M;
        break;
    case 'n':
        return N;
        break;
    case 'o':
        return O;
        break;
    case 'p':
        return P;
        break;
    case 'q':
        return Q;
        break;
    case 'r':
        return R;
        break;
    case 's':
        return S;
        break;
    case 't':
        return T;
        break;
    case 'u':
        return U;
        break;
    case 'v':
        return V;
        break;
    case 'w':
        return W;
        break;
    case 'x':
        return X;
        break;
    case 'y':
        return Y;
        break;
    case 'z':
        return Z;
        break;
    case '1':
        return one;
        break;
    case '2':
        return two;
        break;
    case '3':
        return three;
        break;
    case '4':
        return four;
        break;
    case '5':
        return five;
        break;
    case '6':
        return six;
        break;
    case '7':
        return seven;
        break;
    case '8':
        return eight;
        break;
    case '9':
        return nine;
        break;
    case '0':
        return zero;
        break;
    case '.':
        return stop;
        break;
    case ',':
        return comma;
        break;
    case '?':
        return question;
        break;
    default:
        return 0;
        break;
    }

    return comma;
}

string morseToText(string text) {
    int* morse;
    int arraySize;
    string result;

    //cycle through the lenght of the inputted string
    for (int j = 0; j < text.length(); j++) {
        //if the character is a space, print a backslash and continue
        if (isspace(text.at(j))) {
            result += "/";
            continue;
        }

        //find morse code array for character in string
        morse = alphabet(text.at(j));
        arraySize = *morse;

        //itterate through the returned array and print . or -
        for (int i = 1; i < arraySize; i++) {
            if (*(morse + i) == 1) {
                result += ".";
            }
            else {
                result += "-";
            }
        }
        //add gap between letters
        result += " ";
    }

    cout << endl;
    return result;
}

void playMorseSound(string text) {
    bool played;

    for (int i = 0; i < text.length(); i++) {
        if (text.at(i) == '-') {
            played = PlaySound(TEXT("Dash.wav"), NULL, SND_FILENAME);
            //cout << "Dash Sound: " << played << endl;;
        }
        else if (text.at(i) == '.') {
            played = PlaySound(TEXT("Dot.wav"), NULL, SND_FILENAME);
            //cout << "Dot Sound: " << played << endl;
        }
        else {
            //cout << "GAP" << endl;
            Sleep(200);
        }
    }

    cout << endl;
}

void Clear()
{
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}