#include <string>
#include <iostream>
using namespace std;

class Sensor{
private:
    int id;
    string tipo;
    string localizacao;
    double ultimaLeitura;

public:
    //construtor
    Sensor(int id, string tipo, string localizacao, double ultimaLeitura){
        this->id = id;
        this->tipo = tipo;
        this->localizacao = localizacao;
        this->ultimaLeitura = 0;
    }

    //getters
    int getId(){return id;}
    string getTipo(){return tipo;}
    string getLocalizacao(){return localizacao;}
    double getUltimaLeitura(){return ultimaLeitura;}

    void atualizarLeitura(double valor){
        ultimaLeitura = valor;
    }

    void print(){
        cout << "Id: " << id;
        cout << " Tipo: " << tipo;
        cout << " Local: " << localizacao;
        cout << " UltimaLeitura: " << ultimaLeitura;
    }

};