#include "HashTable.cpp"
#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std;

void executarTesteDesempenho(){
    const int quantidadeSensores = 1000;
    HashTable tabelaTeste(103);

    cout << "\nExecutando teste automatico com " << quantidadeSensores
         << " sensores...\n";

    chrono::high_resolution_clock::time_point inicioInsercao =
        chrono::high_resolution_clock::now();

    for(int i = 0; i < quantidadeSensores; ++i){
        string tipo = "Tipo" + to_string(i % 5);
        string local = "Setor" + to_string(i % 20);
        double leitura = 20.0 + (i % 100) * 0.37;

        tabelaTeste.insert(Sensor(i, tipo, local, leitura));
    }

    chrono::high_resolution_clock::time_point fimInsercao =
        chrono::high_resolution_clock::now();

    chrono::high_resolution_clock::time_point inicioBusca =
        chrono::high_resolution_clock::now();

    int encontrados = 0;
    for(int i = 0; i < quantidadeSensores; ++i){
        if(tabelaTeste.search(i, false) != nullptr){
            encontrados++;
        }
    }

    chrono::high_resolution_clock::time_point fimBusca =
        chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tempoInsercao = fimInsercao - inicioInsercao;
    chrono::duration<double, milli> tempoBusca = fimBusca - inicioBusca;

    cout << fixed << setprecision(3);
    cout << "Tempo de insercao: " << tempoInsercao.count() << " ms\n";
    cout << "Tempo de busca: " << tempoBusca.count() << " ms\n";
    cout << "Sensores encontrados: " << encontrados << "/" << quantidadeSensores << "\n";
    cout << "Numero de colisoes: " << tabelaTeste.getTotalColisoes() << "\n";
    cout << "Capacidade da tabela de teste: " << tabelaTeste.getCapacidade() << "\n";
}

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
        cout << "6. Executar teste de desempenho\n";
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

        else if(opcao == 6){
            executarTesteDesempenho();
        }

    }while(opcao != 0);;

    return 0;
}
