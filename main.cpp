#include "sculptor.h"
#include <iostream>

int main(void){
    Sculptor teste(30,30,30);
    teste.setColor(0.5,0,1,1);
    teste.putBox(0,3,0,3,0,3);
    teste.putVoxel(29,29,29);
    teste.putEllipsoid(10,10,10,5,10,10);
    teste.writeOFF("teste.off");
    return 0;
}
