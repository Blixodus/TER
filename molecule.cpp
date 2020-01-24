#include "molecule.h"
#include "typemolecule.h"
#include <cmath>
#include <time.h>

Molecule::Molecule(TypeMolecule t, float xx, float yy, float zz): x(xx), y(yy), z(zz), type(t){}
Molecule::Molecule(TypeMolecule t): type(t){}

void Molecule::move(Simultation* s, int d, float& x_arg, float& y_arg, float& z_arg){
    
    srand(time(NULL));
    float pi = 3.14159f
    float r = s->getType(type).getSpeed();
    int size = s->getType(type).getSize();
    float theta = rand()/(float)RAND_MAX )* pi;
    float phi =  rand()/(float)RAND_MAX )*2*pi;

    float new_x = x + r*cos(phi)*cos(theta);
    float new_y = y + r*cos(phi)*sin(theta);
    float new_z = z + r*sin(phi); 

    if(new_x*new_x + new_y*new_y + new_z*new_z > (d - size)*(d - size)) {
        x_arg = x;
        y_arg = y;
        z_arg = z;
    } 
    else {
        x_arg = new_x;
        y_arg = new_y;
        z_arg = new_z;
    }
}

void Molecule::getPos(float &x, float &y, float &z){
    x = x;
    y = y;
    z = z;
}