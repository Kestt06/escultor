#include "sculptor.h"
#include <iostream>

int main(void){
    Sculptor teste(10,10,10);
    teste.setColor(0.5,0,1,1);
    teste.putBox(0,3,0,3,0,3);
    teste.putVoxel(9,9,9);
    teste.cutBox(1,2,1,2,1,3);
    teste.writeOFF("teste.off");
    return 0;
}
