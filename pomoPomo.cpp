#include"pomoPomo.h"
using namespace std;
using namespace std::chrono_literals;

pomoPomo::pomoPomo(int a, int b, int c, int d,pomoPrinter* printo) : 
    m_Pomo(a),
    m_Amount(b),
    m_ShortBreak(c),
    m_LongBreak(d),
    m_printo(printo){
        system("clear");
        cout << "What's the theme for this Pomodoro-Session ?" <<endl;
        cin >> m_Theme;
        system("clear");
        startPomo();
    }
pomoPomo::~pomoPomo() {
}
void pomoPomo::setTimes(int curLength) {
    m_StartTime = time(&timer);
    m_EndTime = m_StartTime + (curLength * 60);
    m_Duration = m_EndTime - m_StartTime;
}

void pomoPomo::runPomo() {
    setTimes(m_Pomo);
    string curType = "Pomodoro";
    printHere(curType);

}
void pomoPomo::printHere(string curType) {
    double curPercent = 0.0;
    cout << "Theme: " << m_Theme << endl;
    cout << curType << endl;
    while (curPercent < 1.0) {
        int elapsedTime = int(time(&timer)) - m_StartTime;
        int remainingTime = m_Duration - elapsedTime;
        curPercent = double(elapsedTime) / m_Duration;
        m_printo -> printProgress(curPercent);
        this_thread::sleep_for(1000ms);
    }
    cout << "Done!" << endl;
}


void pomoPomo::runLongBreak() {
    setTimes(m_Pomo);
    string curType = "Longbreak!";
    printHere(curType);


}

void pomoPomo::runShortBreak() {
    setTimes(m_Pomo);
    string curType = "Shortbreak";
    printHere(curType);


}

void pomoPomo::startPomo() {
    for (int i = 1; i <= m_Amount; ++i) {
        runPomo();
        (i % 4 == 0) ? runLongBreak() : runShortBreak();
    }
}



