#include <iostream>
using namespace std;

class Bateria{

    //Attributes
    private:
    float cargaAtual;
    float cargaTotal;

    public:
    //Constructor
    Bateria(int cargaAtual,int cargaTotal){
        this->cargaAtual = cargaAtual;
        this->cargaTotal = cargaTotal;
    };

    //Getters
    int GetCargaAtual(){
        return cargaAtual;
    };
    int GetCargaTotal(){
        return cargaTotal;
    };

    //Setters
    void setCargaAtual(int novaCargaAtual){
        cargaAtual = novaCargaAtual;
        //cout << novaCargaAtual << endl;
    };
    void setCargaTotal(int novaCargaTotal){
        cargaTotal = novaCargaTotal;

        //cout << "nova carga" << novaCargaTotal << endl;
        //cout << "carga" << cargaTotal << endl;
    }

    //Methods
    float Porcentagem()
    {
        
        float P = (cargaAtual * 100)/ cargaTotal;
        //cout << "The battery charge is on " << P << " %" << endl;
        return P;
    }
    void Carregar(){
        if(cargaAtual < cargaTotal){
            setCargaAtual(2000);
            //cout << "Bateria Carregada!" << endl;
            //cout << cargaAtual << endl;
        }
    }
};


/*int main(){
    Bateria bateria(2000);
    bateria.setCargaTotal(2000);
    bateria.setCargaAtual(35.09);
    bateria.Porcentagem();
    bateria.Carregar();
    //bateria.GetCargaAtual();

};*/
