#include "sculptor.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>

Sculptor::Sculptor(int _nx, int _ny, int _nz){ //construtor da classe
    int i,j,k;
    nx = _nx; ny= _ny; nz= _nz;

    //alocacao do espaco para a matriz na memoria
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
    //testando se o voxel escolhido esta na posicao correta
    if (x >= nx || x<0){
        return;
    }
     if (y >= ny || y<0){
        return;
    }
    if (z >= nz || z<0){
        return;
    }

   //criando voxel
    v[x][y][z].show = 1;
    v[x][y][z].r = this->r;
    v[x][y][z].g = this->g;
    v[x][y][z].b = this->b;
    v[x][y][z].a = this->a;
}

void Sculptor::writeOFF(const char *filename){
    int i,j,k;
    int faces, vertices;
    int add =0; //auxiliar para criar faces
    int contagem = 0; //contar quantos voxels tem
    //contagem de .show
        for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if (v[i][j][k].show == true){
                    contagem++;
                }
            }
        }
    }

    //quantidade de faces e vertices total
    faces = 6 * contagem;
    vertices = 8 * contagem;

    //etapa de criacao do arquivo
    std::ofstream fout;
    fout.open(filename);
    fout << std::fixed << std::setprecision(2); //para sempre exibir numero no formato de float
    if (!fout.is_open()){
        exit(1);
    }

    //cabecalho do arquivo
    fout << "OFF\n";
    fout << vertices << " " << faces << " " << "0" << std::endl;

    //escrevendo os pontos no arquivo
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if (v[i][j][k].show == true){
                    //vertices
                    fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                    fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                }
            }
        }
    }
    //escrevendo as faces no arquivo
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if (v[i][j][k].show == true){
                    fout << "4 " << 0 + add << " " << 3 + add << " " << 2 + add << " " << 1 + add <<
                    " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;

                    fout << "4 " << 4 + add << " " << 5 + add << " " << 6 + add << " " << 7 + add <<
                    " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;

                    fout << "4 " << 0 + add << " " << 1 + add << " " << 5 + add << " " << 4 + add <<
                    " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;

                    fout << "4 " << 0 + add << " " << 4 + add << " " << 7 + add << " " << 3 + add <<
                    " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;

                    fout << "4 " << 7 + add << " " << 6 + add << " " << 2 + add << " " << 3 + add <<
                    " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;

                    fout << "4 " << 1 + add << " " << 2 + add << " " << 6 + add << " " << 5 + add <<
                    " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    add = add +8;
                }
            }
        }
    }
fout.close();
std::cout << "Arquivo criado!" << std::endl;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].show = 0;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int i,j,k;
    for (i=x0;i<x1+1;i++){
        for (j=y0;j<y1+1;j++){
            for (k=z0;k<z1+1;k++){
                Sculptor::putVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int i,j,k;
    for (i=x0;i<x1+1;i++){
        for (j=y0;j<y1+1;j++){
            for (k=z0;k<z1+1;k++){
                Sculptor::cutVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    int i,j,k;
    float dCenter; //distancia de um ponto ao centro da esfera

    //considerando os limites de um quadrado em que a circunferencia esta dentro
    for (i = xcenter-radius ; i< xcenter +radius +1; i++){
        for (j = ycenter-radius ; j< ycenter +radius +1; j++){
            for (k = zcenter-radius ; k< zcenter +radius +1; k++){
                dCenter = sqrt( (i-xcenter)*(i-xcenter) + (j-ycenter)*(j-ycenter) + (k-zcenter)*(k-zcenter));
                    if (dCenter <= radius){
                    Sculptor::putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int i,j,k;
    float dCenter; //distancia de um ponto ao centro da esfera

    //considerando os limites de um quadrado em que a circunferencia esta dentro
    for (i = xcenter-radius ; i< xcenter +radius +1; i++){
        for (j = ycenter-radius ; j< ycenter +radius +1; j++){
            for (k = zcenter-radius ; k< zcenter +radius +1; k++){
                dCenter = sqrt( (i-xcenter)*(i-xcenter) + (j-ycenter)*(j-ycenter) + (k-zcenter)*(k-zcenter));
                if (dCenter <= radius){
                    Sculptor::cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
int i,j,k;
float x,y,z; //usado pra calcular a equacao da elipse
float equ; //equacao da elipse
for (i = xcenter-rx ; i< xcenter +rx +1; i++){
    for (j = ycenter-ry ; j< ycenter +ry +1; j++){
        for (k = zcenter-rz ; k< zcenter +rz +1; k++){
            x=i-xcenter;
            y=j-ycenter;
            z=k-zcenter;
            equ = ((x*x)/(rx*rx)) + ((y*y)/(ry*ry)) + ((z*z)/(rz*rz));
            if (equ <= 1){
                Sculptor::putVoxel(i,j,k);
            }
        }
    }
}
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int i,j,k;
    float x,y,z; //usado pra calcular a equacao da elipse
    float equ; //equacao da elipse
    for (i = xcenter-rx ; i< xcenter +rx +1; i++){
        for (j = ycenter-ry ; j< ycenter +ry +1; j++){
            for (k = zcenter-rz ; k< zcenter +rz +1; k++){
                x=i-xcenter;
                y=j-ycenter;
                z=k-zcenter;
                equ = ((x*x)/(rx*rx)) + ((y*y)/(ry*ry)) + ((z*z)/(rz*rz));
                if (equ <= 1){
                    Sculptor::cutVoxel(i,j,k);
                }
            }
        }
    }
}
