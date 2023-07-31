#include <iostream>
#include <cmath>
#include "Bateria.h"

class Drone {//: public Bateria {

    //Attributes
    protected:
    float eficiencia;
    bool decolado;
    //int posicao[2] = {};
    int posicao[2];
    
    public:
    Bateria bateria; 

    //Constructor
    Drone (float eficiencia, int posicao[2], bool decolado, int cargaAtual, int cargaTotal) //aqui en Drone(..., intcargaAtual, int cargaTotal)
        :bateria(cargaAtual, cargaTotal)
    {
        this->eficiencia = eficiencia;
        this->decolado = decolado;
        this->posicao[0] = posicao[0];
        this->posicao[1] = posicao[1];

    };
    
    //Setters
    void setEficiencia(float novaEficiencia){
        eficiencia = novaEficiencia;
    }
    void setPosicao(int *newPosicao){
        posicao[0] = newPosicao[0];
        posicao[1] = newPosicao[1];
    }
    void setDecolado(bool novoDecolado){
        decolado = novoDecolado;
    }

    //Getters
    float getEficiencia(){
        return eficiencia;
    }
    int *getPosicao(){
        return posicao;
    }
    bool getDecolado(){
        return decolado;
    }

    //Metodos
    bool Takeoff(){
        if(!decolado && bateria.Porcentagem() > 0){  // aqui estaba bateria.Porcentagem()
            //cout << "Drone pronto para decolar" << endl;
            decolado = true;
            return true;
        }
        //cout << "O drone já decolou" << endl; 
        return false;
    }
    bool Pousar(){
        if(decolado){
            //cout << "O drone esta voando" << endl;
            decolado = false;
            return true;
        }
        cout << "O drone pouso" << endl;
        return false;
    }
    bool Voar(int x, int y){
        if (decolado) {
            int *pos = getPosicao();
            float dx = x - pos[0];
            float dy = y - pos[1];
            float op = dx * dx + dy * dy;
            float distancia = sqrt(op);
            //cout << "distancia: " << distancia << endl;
            float cargaNecessaria = distancia * eficiencia;

            if (cargaNecessaria <= bateria.GetCargaAtual()) { //aqui estaba bateria.GetCargaAtual()
                posicao[0] = x;
                posicao[1] = y;
                bateria.setCargaAtual(bateria.GetCargaAtual() - cargaNecessaria); //aqui estaba bateria.setCargaAtual(bateria.GetCargaAtual() ...)
                //cout << cargaNecessaria << "," << bateria.GetCargaAtual() << endl;
                cout << "Foi possivel realizar o voo" << endl;
                return true;
            }
    }
    cout << "Não foi possivel realizar o voo" << endl;
    return false;
    }


};

/*int main() {
    int position[2] = {10,10};
    float cargaAtual = 2000;
    float cargaTotal = 2000;
    Drone mydrone(0.8, position, true, cargaAtual, cargaTotal);
    mydrone.setEficiencia(0.8);
    mydrone.Takeoff();
    mydrone.Pousar();
    Bateria bateria(2000); 
    mydrone.Voar(10,5);
    return 0;
}*/




























/*bool Drone::Voar(int x, int y) {
    if (decolado) {
        float distancia = CalculateDistance(Posicao[0], Posicao[1], x, y);
        float cargaNecessaria = distancia * eficiencia;

        if (cargaNecessaria <= bateria.GetCargaAtual()) {
            Posicao[0] = x;
            Posicao[1] = y;
            bateria.SetCargaAtual(bateria.GetCargaAtual() - cargaNecessaria);
            return true;
        }
    }
    return false;
}







#include <cmath>

float CalculateDistance(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    float distance = std::sqrt(dx * dx + dy * dy);
    return distance;
*/
