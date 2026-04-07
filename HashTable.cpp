#include <iostream>
#include <list>
#include <stdlib.h>
#include <vector>

using namespace std;

class HashTable{
private:
    int buckets;

    //vetor contendo listas
    vector<list<int>> table;

public:
    //construtor: recebe a qntd de buckets e define o tamanho do vetor
    HashTable(int buckets){
        this->buckets = buckets;
        table.resize(buckets);
    }

    //insercao
    void insert(int n){
        //funcao simples TO DO: criar funcao melhor!!
        int bucket = n % buckets;

        table[bucket].push_back(n);
    };

    //print
    void print(){
        for(int i = 0; i < buckets; i++){
            cout << "| Bucket " << i << " | ";
            for(auto j : table[i]){
                cout << "-> | " << j << " | ";
            }
        cout << endl;
        }
        cout << "\n " << endl;
    };

    //procura valor especifico e retorno o bucket q ele esta
    void search(int n){
        int bucket = n % buckets;

        for(auto i : table[bucket]){
            if(i == n){
                cout << "Bucket: " << bucket << endl;
                return;
            }
        }
        cout << "Não encontrado" << endl;
    };

    //remover valor especifico
    void remove(int n){
        int bucket = n % buckets;

        //para fazer erase() eh necessario usar iterador (auto i : table[bucket] nao funciona)
        for(auto i = table[bucket].begin(); i != table[bucket].end(); i++){
            if(*i == n){
                table[bucket].erase(i);
                cout << "Valor: " << n <<" removido do Bucket: " << bucket << endl;
                return;
            }
        }
        cout << "Não encontrado" << endl; 
    };
};

//testes
int main(){
    //cria hash com 8 buckets
    HashTable hash(8);

    //inserindo 20 numeros aleatorios
    for(int i = 0; i < 20; i++){
        hash.insert(rand() % 100);
    }
    hash.print();

    //teste insere
    hash.insert(10);
    hash.print();

    //teste busca
    hash.search(10);

    //teste remove
    hash.remove(10);
    hash.print();

    return 0;
}
