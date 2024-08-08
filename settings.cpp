
using namespace Settings;
#include "settings.h"
#include<iostream>
#include <fstream>
#include <string>

    public:
        Settings() {
            myfile.open("settings.txt");
            initSettings();
            myfile.close();
        }

        void writeSettings() {
            myfile.open("settings.txt");
            std::string newSettings = std::to_string(t_pomo) std:: + "\n";
            newSettings += std::to_string(t_amount) std:: + "\n";
            newSettings += std::to_string(t_shortBreak) std:: + "\n";
            newSettings += std::to_string(t_longBreak) std:: + "\n";
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
            std::cout std:: << "How long should one Pomodoro be? (minutes)"
                            << std::endl;
            std::cin std:: >> t_pomo;
            writeSettings();
        }

        void changeAmount() {
            system("clear");
            std::cout std:: << "How many Rounds of Pomos do you want?"
                            << std::endl;
            std::cin std:: >> t_amount;
            writeSettings();
        }

        void changeShortbreak() {
            system("clear");
            std::cout std:: << "How long is a shortbreak?(minutes)"
                            << std::endl;
            std::cin std:: >> t_shortBreak;
            writeSettings();
        }

        void changeLongbreak() {
            system("clear");
            std::cout std:: << "How long is a long break?(minutes)"
                            << std::endl;
            std::cin std:: >> t_shortBreak;
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


};
