#ifndef POMO_PRINTER_H
#define POMO_PRINTER_H
#pragma once
#include <iostream>
#include "pomoSettings.h"

class pomoPrinter {
    public:
    pomoSettings* setto;
        pomoPrinter(pomoSettings* rules);
        ~pomoPrinter();
        friend class Settings;
    private:
        void printSettingsMenu();
        int getAnswerMinutes();
        int getAnswerAmount();
    public:
        void printMainMenu();
};
#endif
