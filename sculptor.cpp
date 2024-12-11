#include "sculptor.h"
#include <iostream>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    int i,j;
    nx = _nx; ny= _ny; nz= _nz;

    v = new Voxel**[nx];

    for (i=0;i<nx;i++){
        v[i] = new Voxel*[ny];
            for(j=0;j<ny;j++){
            v[i][j] = new Voxel[nz];
        }
    }

}

Sculptor::~Sculptor(){
    int i,j;
    for (i=0;i<nx;i++){
        for (j=0;j<ny;j++){
            delete[] v[i][j];
        }
        delete[] v[i];
    }

    delete[] v;
}
