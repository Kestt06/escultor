#include "sculptor.h"
#include <iostream>

int main(void){
    Sculptor teste(2,2,2);
    teste.setColor(0.5,0,1,1);
    teste.putVoxel(0,0,0);
    teste.putVoxel(1,0,0);
    teste.putVoxel(1,1,0);
    teste.cutVoxel(1,0,0);
    teste.writeOFF("teste.off");
    return 0;
}
