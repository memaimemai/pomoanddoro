#ifndef POMO_POMO_H
#define POMO_POMO_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "pomoSettings.h"
#include "pomoPrinter.h"

class pomoPomo {
    public:
        pomoPomo(int a, int b, int c, int d);
        ~pomoPomo();

    private:
        int m_StartTime;
        int m_CurTime;
        int m_EndTime;
        int m_Pomo;
        int m_ShortBreak;
        int m_LongBreak;
        int m_Amount; 
        int setStart();
        int setEnd();
};
#endif
