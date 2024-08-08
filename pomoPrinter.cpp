#include"pomoPrinter.h"
#include <cstddef>
#include "pomoPomo.h"
using namespace std;

pomoSettings* setto = NULL;
pomoPrinter::pomoPrinter(pomoSettings* rules) : setto(rules) {
    printMainMenu();
}
pomoPrinter::~pomoPrinter() {
}

void pomoPrinter::printMainMenu() {
    //system("clear");
    cout << "Welcome to  \33\[31m Pomo \33[0m and Doro" << endl;
    int temp_Answer;
    cout << "What do you want to do?" << endl;
    cout << "(1) Create new Pomo";
    cout << "\t(2) Change Settings" << endl;
    cin >> temp_Answer;
    switch (temp_Answer) {
        case 1: {
            break;
        }
        case 2: {
            printSettingsMenu();
            printMainMenu();
            break;
        }
    }
}

void pomoPrinter::printProgress(double curPercent) {
    int barWidth = 70;
    int pos = barWidth * curPercent;
    cout << "{";
    for (int i = 0; i < barWidth; ++i) {
            if (i < pos) {
            cout << "-";
            } else if ( i == pos ) {
            cout << ">"; 
            } else {
            cout << " ";
            }
    }
            cout << "} " << int(curPercent * 100.0) << "%\r";
            cout.flush();
}
void pomoPrinter::printSettingsMenu() {
    int temp_Answer;
    //system("clear");
    cout << "What do you want to change?" << endl;
    cout << "(1) Amount of Pomos" << endl;
    cout << "(2) Length of Pomos" << endl;
    cout << "(3) Shortbreak" << endl;
    cout << "(4) Longbreak" << endl;
    cout << "(5) Change ALL" << endl;
    cout << "(6) Revert to Default" << endl;
    cin >> temp_Answer;
    switch(temp_Answer) {
        case 1:
            setto -> setAmount(setto -> getAnswerAmount());
            break;
        case 2:
            setto -> setPomo(setto -> getAnswerMinutes());
            break;
        case 3:
            setto -> setShortbreak(setto -> getAnswerMinutes());
            break;
        case 4:
            setto -> setLongbreak(setto -> getAnswerMinutes());
            break;
        case 5: {
            setto -> setAmount(setto -> getAnswerAmount());
            setto -> setPomo(setto -> getAnswerMinutes());
            setto -> setShortbreak(setto -> getAnswerMinutes());
            setto -> setLongbreak(setto -> getAnswerMinutes());
            break;
        }
        case 6:
            setto -> setDefault();
            break;
        default:
            cout << "Please enter a valid number" << endl;
            printSettingsMenu();
}
}
