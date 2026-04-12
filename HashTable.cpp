#include <iostream>
#include <list>
#include <stdlib.h>
#include <vector>
#include "Sensor.cpp"

using namespace std;

class HashTable{
private:
    int buckets;

    //vetor contendo listas
    vector<list<Sensor>> table;

public:
    //construtor: recebe a qntd de buckets e define o tamanho do vetor
    HashTable(int buckets){
        this->buckets = buckets;
        table.resize(buckets);
    }

    //funcao simples TO DO: criar funcao melhor!!
    int hashFunction(int id, int buckets) {
        return id % buckets;
    }

    //insercao
    void insert(Sensor s){
        int bucket =  hashFunction(s.getId(), buckets);

        table[bucket].push_back(s);
    };

    //print
    void print(){
        for(int i = 0; i < buckets; i++){
            cout << "| Bucket " << i << " | ";
            for(auto &s : table[i]){
                s.print();
            }
        cout << endl;
        }
        cout << "\n " << endl;
    };

    //procura valor especifico e retorno o bucket q ele esta
    Sensor* search(int id){
        int bucket = hashFunction(id, buckets);

        for(auto &s : table[bucket]){
            if(s.getId() == id){
                cout << "Bucket: " << bucket << endl;
                return &s;
            }
        }
        return nullptr;
    };

    //remover valor especifico
    void remove(int id){
        int bucket = hashFunction(id, buckets);

        //para fazer erase() eh necessario usar iterador (auto i : table[bucket] nao funciona)
        for(auto i = table[bucket].begin(); i != table[bucket].end(); i++){
            if(i->getId() == id){
                table[bucket].erase(i);
                cout << "Sensor removido" << endl;
                return;
            }
        }
        cout << "Não encontrado" << endl;
    };

    void atualizarLeitura(int id, double valor) {
        Sensor* s = search(id);
        if (s != nullptr) {
            s->atualizarLeitura(valor);
            cout << "Leitura atualizada!\n";
        } else {
            cout << "Sensor nao encontrado!\n";
            }
    }

};
