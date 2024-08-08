#include "pomoSettings.h"
using namespace std;

pomoSettings::pomoSettings() {
    myfile.open("settings.txt");
    initSettings();
    myfile.close();
}
pomoSettings::~pomoSettings() {
    cout << "I'm dead";
    myfile.close();
}
int pomoSettings::getAnswerAmount() {
    cout << "Please enter amount " << endl;
    string tmpx;
    cin >> tmpx;
    int a = stoi(tmpx);
    return a;
}

int pomoSettings::getAnswerMinutes() {
    cout << "Please enter Length(minutes) " << endl;
    string tmpx;
    cin >> tmpx;
    int a = stoi(tmpx);
    return a;
}
void pomoSettings::setAmount(int newAmount) {
    t_Amount = newAmount;
    writeSettings();
}

void pomoSettings::setPomo(int newPomo) {
   t_Pomo = newPomo;
   writeSettings();
}

void pomoSettings::setLongbreak(int newLongBreak) {
   t_Longbreak = newLongBreak;
   writeSettings();
}

void pomoSettings::setShortbreak(int newShortbreak) {
   t_Shortbreak = newShortbreak;
   writeSettings();
}

int pomoSettings::getPomo(){
    return t_Pomo;
}

int pomoSettings::getAmount() {
    return t_Amount;
}

int pomoSettings::getLongbreak() {
    return t_Longbreak;
}
int pomoSettings::getShortbreak() {
   return t_Shortbreak;
}

void pomoSettings::setDefault() {
    setPomo(25);
    setAmount(4);
    setLongbreak(15);
    setShortbreak(5);
}

void pomoSettings::initSettings() {
   string line;
   for (int i = 0; i < 4; ++i) {
       getline(myfile,line);
       int a = stoi(line);
       switch (i) {
           case 0:
           t_Pomo = a;
           break;
           case 1:
           t_Amount = a;
           break;
           case 2:
           t_Shortbreak = a;
           break;
           case 3:
           t_Longbreak = a;
           break;
       }
   }
}

   void pomoSettings::writeSettings() {
       myfile.open("settings.txt");
       string newSettings = to_string(t_Pomo) + "\n";
       newSettings = newSettings + to_string(t_Amount) + "\n";
       newSettings = newSettings + to_string(t_Shortbreak) + "\n";
       newSettings = newSettings + to_string(t_Longbreak) + "\n";
       cout << newSettings << endl;
       myfile << newSettings;
       myfile.close();
   }
