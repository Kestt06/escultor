#include "sculptor.h"
#include <iostream>

int main(void){
    Sculptor teste(30,30,30);
    teste.setColor(0,0,1,1);
    teste.putBox(0,10,0,10,0,10);
    teste.writeOFF("alo.off");
    return 0;
}
