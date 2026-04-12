#include "HashTable.cpp"
#include <iostream>

using namespace std;

int main(){
    HashTable hash(10);
    int opcao;

    do{
        cout << "\n===== SISTEMA DE SENSORES =====\n";
        cout << "1. Cadastrar sensor\n";
        cout << "2. Atualizar leitura\n";
        cout << "3. Buscar sensor\n";
        cout << "4. Remover sensor\n";
        cout << "5. Exibir sensores\n";
        cout << "0. Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        if(opcao == 1){
            int id;
            string tipo, local;
            double leitura;

            cout << "ID: ";
            cin >> id;

            cout << "Tipo: ";
            cin >> tipo;

            cout << "Localizacao: ";
            cin >> local;

            cout << "Leitura inicial: ";
            cin >> leitura;

            Sensor s(id, tipo, local, leitura);
            hash.insert(s);

            cout << "Sensor cadastrado!\n";
        }

        else if(opcao == 2){
            int id;
            double valor;

            cout << "ID do sensor: ";
            cin >> id;

            cout << "Nova leitura: ";
            cin >> valor;

            hash.atualizarLeitura(id, valor);
        }

        else if(opcao == 3){
            int id;

            cout << "ID do sensor: ";
            cin >> id;

            Sensor* s = hash.search(id);

            if(s != nullptr){
                s->print();
                cout << endl;
            } else {
                cout << "Sensor nao encontrado!\n";
            }
        }

        else if(opcao == 4){
            int id;

            cout << "ID do sensor: ";
            cin >> id;

            hash.remove(id);
        }

        else if(opcao == 5){
            hash.print();
        }

    }while(opcao != 0);

    cout << "Encerrando sistema...\n";

    return 0;
}