#include<iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

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


	private:
		void initSettings () {
		string line;
		for (int i = 0; i < 4; ++i) {
		getline(myfile,line);
		int a = stoi(line);
		switch (i + 0) {
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
		Pomo() {
		}
	private:
};

class Printer {
    public:
    Printer(Settings* rules) : setto(rules) {
        printMainMenu();
    }
    friend Settings;
        private:
        Settings* setto = nullptr;
    void printSettingsMenu() {
        int temp_Answer;
        system("clear");
        cout << "What do you want to change?" << endl;
        cout << "(1) Amount of Pomos" << endl;
        cout << "(2) Length of Pomos" << endl;
        cout << "(3) Shortbreak" << endl;
        cout << "(4) Longbreak" << endl;
        cout << "(5) Change All" << endl;
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
       Pomo new_Pomo;
       }
      case 2:
      printSettingsMenu();
      printMainMenu();
   }
	}
};


int main() {
    Settings setti;
   Settings* pSetti = &setti ;
    Printer printo(pSetti);
}
