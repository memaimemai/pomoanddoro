#include<iostream>
#include "pomoSettings.h"
#include "pomoPrinter.h"
using namespace std;



void createPomo() {
    pomoSettings setti;
    pomoSettings* pSetti = &setti;
    pomoPrinter printi(pSetti);
  //  pomoPomo pomori(*setti);
}

int main() {
    cout << "Hello World" << endl;
    bool cont = 1;
    while (cont) {
    createPomo();
    }
    return 0;
}
