#ifndef POMO_POMO_H
#define POMO_POMO_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "pomoSettings.h"
#include "pomoPrinter.h"
#include <chrono>
#include <thread>

class pomoPomo {
    public:
        pomoPomo(int a, int b, int c, int d, pomoPrinter* printo);
        ~pomoPomo();

    private:
        time_t timer;
        int m_StartTime;
        int m_CurTime;
        int m_EndTime;
        int m_Duration;
        int m_Pomo;
        int m_Amount; 
        int m_ShortBreak;
        int m_LongBreak;
        pomoPrinter* m_printo;
        void setTimes(int curLength);
        int setStart();
        std::string m_Theme; 
        int setEnd();
        void printHere(std::string curType);
        void createPomo();
        void startPomo();
        void runPomo();
        void runLongBreak();
        void runShortBreak();
};
#endif
