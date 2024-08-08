#include <cstddef>
#include<iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;


class Settings {
    public:
        Settings() {
            myfile.open("settings.txt");
            initSettings();
            myfile.close();
        }

        void writeSettings() {
            myfile.open("settings.txt");
            string newSettings = to_string(t_pomo) + "\n";
            newSettings = newSettings + to_string(t_amount) + "\n";
            newSettings = newSettings + to_string(t_shortBreak) + "\n";
            newSettings = newSettings + to_string(t_longBreak) + "\n";
            cout << newSettings << endl;
            myfile << newSettings;
            myfile.close();
        }
        int getPomo() {
           return t_pomo;
        }
        int getAmount() {
           return t_amount ;
        }
        int getShortbreak() {
            return t_shortBreak;
        }
        int getLongbreak() {
            return t_longBreak;
        }


        void changePomo() {
            system("clear");
            cout << "How long should one Pomodoro be? (minutes)" << endl;
            cin >> t_pomo;
            writeSettings();
        }

        void changeAmount() {
            system("clear");
            cout << "How many Rounds of Pomos do you want?" << endl;
            cin >> t_amount;
            writeSettings();
        }

        void changeShortbreak() {
            system("clear");
            cout << "How long is a shortbreak?(minutes)" << endl;
            cin >> t_shortBreak;
            writeSettings();
        }

        void changeLongbreak() {
            system("clear");
            cout << "How long is a long break?(minutes)" << endl;
            cin >> t_shortBreak;
            writeSettings();
        }

        void changeAll() {
            changePomo();
            changeAmount();
            changeShortbreak();
            changeLongbreak();
        }

        void changeDefault() {
            system("clear");
            t_amount = 4;
            t_pomo = 25;
            t_shortBreak = 5;
            t_longBreak = 5;
            writeSettings();
        }


    private:
        void initSettings () {
            string line;
            for (int i = 0; i < 4; ++i) {
                getline(myfile,line);
                int a = stoi(line);
                switch (i) {
                    case 0: {
                                t_pomo = a;
                                break;
                            }
                    case 1:
                            t_amount = a;
                            break;
                    case 2:
                            t_shortBreak = a;
                            break;
                    case 3:
                            t_longBreak = a;
                            break;
                }
            }
        }

        fstream myfile;
        int t_shortBreak;
        int t_longBreak;
        int t_pomo;
        int t_amount;

};

class Pomo {
    public:
        Pomo(Settings* rules) : setto(rules) {
            for (int i = 1; i <= setto -> getAmount();++i ) {
                system("clear");
                startPomo();
               (i % 4 == 0) ? startLongbreak():startShortbreak();
            }
        }
        Settings* setto = NULL;
        time_t timer;
        int m_curTime;
        int m_tarTime;
    private:
    void startPomo() {

        system("clear");
        cout << time(&timer) << endl;
        m_curTime = int(time(&timer));
        cout << m_curTime;
    }

    void startLongbreak() {
        system("clear");
        cout << "Start long break?" << endl;
        cout << "(Y)es" << endl << "(E)xit";
        int temp_char;
        cin >> temp_char;
        cout << "longbreak";

    }
    void startShortbreak() {
        system("clear");
        cout << "shortbreak";

    }
};

class Printer {
    public:
        Printer(Settings* rules) : setto(rules) {
            printMainMenu();
        }
        friend class Settings;
    private:
        Settings* setto = NULL;
        void printSettingsMenu() {
            int temp_Answer;
            system("clear");
            cout << "What do you want to change?" << endl;
            cout << "(1) Amount of Pomos" << endl;
            cout << "(2) Length of Pomos" << endl;
            cout << "(3) Shortbreak" << endl;
            cout << "(4) Longbreak" << endl;
            cout << "(5) Change All" << endl;
            cout << "(6) Defaults " << endl;
            cin >> temp_Answer;
            switch(temp_Answer) {
                case 1:
                    setto -> changePomo();
                    break;
                case 2:
                    setto -> changeAmount();
                    break;
                case 3:
                    setto -> changeShortbreak();
                case 4:
                    setto -> changeLongbreak();
                    break;
                case 5:
                    setto -> changeAll();
                    break;
                case 6:
                    setto -> changeDefault();
                    break;
                default:
                    cout << "Please enter a valid number" << endl;
                    printSettingsMenu();
            }
        }

    public:
        void printMainMenu() {
            system("clear");
            cout << "Welcome to \33[31m Pomo \33[0m and Doro" << endl;
            int temp_Answer;
            cout << "What do you want to do?" << endl;
            cout << "(1)\33[5m Create new Pomo\33[0m";
            cout << "\t (2) Change Settings" << endl;
            cin >> temp_Answer;
            switch(temp_Answer) {
                case 1: {
                            Pomo new_Pomo(setto);
                            printMainMenu();
                            break;

                        }
                case 2:
                        printSettingsMenu();
                        printMainMenu();
                        break;
            }
        }
};


int main() {
    Settings setti;
    Settings* pSetti = &setti ;
    Printer printo(pSetti);
}
