#include <iostream>
#include "Drone.h"
//#include "Bateria.h" //esto estaba comentado
using namespace std;

class Outdoor { //: public Drone {

//Attributes 

private:
float cargaMapear;

public:
Drone myDrone; //esto estaba comentado


Outdoor(float cargaMapear, float eficiencia, int posicao[2], bool decolado, int cargaAtual, int cargaTotal)//, const Bateria& bateria)
    : myDrone (eficiencia, posicao, decolado, cargaAtual, cargaTotal) //aqui era Drone
    {
        this->cargaMapear = cargaMapear;
    }

//Setter
void setcargaMapear(float cargamap){
    cargaMapear = cargamap;
}

//getter
float getcargaMapear(){
    return cargaMapear;
}

//Methods
bool Mapear(){
    cout << !myDrone.getDecolado() << endl;
    if (myDrone.getDecolado() && myDrone.bateria.GetCargaAtual() >= cargaMapear) { //aqui erra decolado y bateria.getcargaatual()
        cout << "Mapeamento concluido" << endl;
        myDrone.bateria.setCargaAtual(myDrone.bateria.GetCargaAtual() - cargaMapear);
        return true;
    } else {
        cout << "Impossível completar o mapeamento" << endl;
        return false;
    }
}


};

/*
int main() {
    int poss[2] = {0,0};
    Bateria bateria(2000, 2000);
    Outdoor outdoor(300.0, 0.8, poss, true, 2000, 2000);//, bateria);
    outdoor.Mapear();
    return 0;
}*/

//The problem was a "null pointer", while defining the outdoor parameters on main, I was giving a 0 to the pointer posicao[2] big mistake because it takes two values insted of one and that zero represent a null pointer