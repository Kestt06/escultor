#include "sculptor.h"
#include <iostream>

int main(void){
    Sculptor teste(30,30,30);
    teste.setColor(0.5,0,1,1);
    teste.putVoxel(29,29,29);
    teste.putEllipsoid(20,20,20,10,3,3);
    teste.writeOFF("teste.off");
    return 0;
}
