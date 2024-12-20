#include "sculptor.h"
#include <iostream>

int main(void){
    Sculptor teste(30,30,30);
    teste.setColor(0.5,0,1,1);
    teste.putVoxel(29,29,29);
    teste.putEllipsoid(20,25,20,10,3,3);
    teste.putBox(0,3,0,3,0,3);
    teste.cutBox(2,3,2,3,2,3);
    teste.putSphere(25,9,9,3);
    teste.cutSphere(20,25,20,3);
    teste.setColor(1,0,0,0.1);
    teste.putBox(8,18,8,15,8,18);
    teste.setColor(0.5,0,1,1);
    teste.cutEllipsoid(13,13,13,5,6,2);
    teste.cutVoxel(0,0,0);
    teste.writeOFF("exemplo.off");
    return 0;
}
