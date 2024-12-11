#include <iostream>
#include <sculptor.h>

int main(){
    Sculptor teste(2,3,3);
    teste.setColor(1,0,1,0.5);
    teste.putVoxel(0,0,0);
    teste.setColor(0,1,0,1);
    teste.putVoxel(1,0,0);
    teste.putVoxel(1,1,0);
    teste.writeOFF("teste.off");
}

