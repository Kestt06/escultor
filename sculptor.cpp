#include "sculptor.h"
#include <iostream>

Sculptor::Sculptor(int _nx, int _ny, int _nz){ //construtor
    int i,j,k;
    nx = _nx; ny= _ny; nz= _nz;

    v = new Voxel**[nx];

    for (i=0;i<nx;i++){
        v[i] = new Voxel*[ny];
            for(j=0;j<ny;j++){
            v[i][j] = new Voxel[nz];
        }
    }
    //inicializando (limpando lixo)
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                v[i][j][k].show = false;
            }
        }
    }
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                std::cout << v[i][j][k].show;
            }
        }
    }

}

Sculptor::~Sculptor(){ //destrutor
    int i,j;
    for (i=0;i<nx;i++){
        for (j=0;j<ny;j++){
            delete[] v[i][j];
        }
        delete[] v[i];
    }

    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    this->r = r;
    this->g = g;
    this->b = b;
    a = alpha;
}
void Sculptor::putVoxel(int x, int y, int z){
    if (x >= nx || x<0){
        std::cout << "voxel em posicao invalida" << std::endl;
        return;
    }
     if (y >= ny || y<0){
        std::cout << "voxel em posicao invalida" << std::endl;
        return;
    }
    if (z >= nz || z<0){
        std::cout << "voxel em posicao invalida" << std::endl;
        return;
    }
    std::cout << "passou" << std::endl;
   //criando voxel
    v[x][y][z].show = 1;
    v[x][y][z].r = this->r;
    v[x][y][z].g = this->g;
    v[x][y][z].b = this->b;
    v[x][y][z].a = this->a;
}
void Sculptor::writeOFF(const char *filename){
    int i,j,k;
    int contagem = 0;
    //contagem de .show
        for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if (v[i][j][k] = 1){
                    contagem++;
                }
            }
        }
    }
        std::cout << contagem;
}
