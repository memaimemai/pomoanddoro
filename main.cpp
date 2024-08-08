#include<iostream>
#include "pomoSettings.h"
#include "pomoPomo.h"
#include "pomoPrinter.h"
using namespace std;



void createPomo() {
    pomoSettings setti;
    pomoSettings* pSetti = &setti;
    pomoPrinter printi(pSetti);
    pomoPrinter* pPrinti = &printi;
    pomoPomo pomori(setti.getPomo(),
            setti.getAmount(),
            setti.getShortbreak(),
            setti.getLongbreak(),
            pPrinti);
}

int main() {
    cout << "Hello World" << endl;
    bool cont = 1;
    while (cont) {
    createPomo();
    }
    return 0;
}
