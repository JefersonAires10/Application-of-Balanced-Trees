#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "pessoa.h"
//#include "data.csv"
#include "avl.h"
#include "node.h"
#include "data.h"

using namespace std;

void readFile(vector<Pessoa> &pessoas, string filename) {

    ifstream file(filename);
    string line;

    while (getline(file, line)) {

        stringstream ss(line);
        string cpf, nome, sobrenome, data, cidade;
        getline(ss, cpf, ',');
        getline(ss, nome, ',');
        getline(ss, sobrenome, ',');
        getline(ss, data, ',');
        getline(ss, cidade, ',');

        for (int i = 0; i < cpf.size(); i++) {
            if (cpf[i] == '.' || cpf[i] == '-') {
                cpf.erase(i--, 1);
            }
        }

        stringstream ss2(data);
        int dia, mes, ano;
        ss >> dia;
        ss.ignore(1);
        ss >> mes;
        ss.ignore(1);
        ss >> ano;
        Date dataDeNascimento(dia, mes, ano);

        if (dataDeNascimento == Date(0, 0, 0)) {
            cout << "Data inválida: " << data << endl;
            continue;
        }

        if  (cpf.size() != 11) {
            cout << "CPF inválido: " << cpf << endl;
            continue;
        }

        Pessoa pessoa(stoll(cpf), nome + " " + sobrenome, dataDeNascimento);
        pessoas.push_back(pessoa);

        ss.clear();
        ss2.clear();
    }
}
void preencherArvores(avl_tree<int> &Cpf, avl_tree<string> &Nome, avl_tree<Date> &data_nascimento, vector<Pessoa> &pessoas) {
    for (int i = 0; i < pessoas.size(); i++) {
        Cpf.add(pessoas[i].getCpf());
        Nome.add(pessoas[i].getNome());
        data_nascimento.add(pessoas[i].getDataNascimento());
    }
}


int main() {

    system("chcp 65001 > nul");

    vector<Pessoa> pessoas;
    readFile(pessoas, "data.csv");

    avl_tree<int> Cpf;
    avl_tree<string> Nome;
    avl_tree<Date> data_nascimento;

    preencherArvores(Cpf, Nome, data_nascimento, pessoas);

    cout << "Arvore de CPFs: " << endl;
    Cpf.bshow();
    cout << endl;

    cout << "Arvore de Nomes: " << endl;
    Nome.bshow();
    cout << endl;

    cout << "Arvore de Datas de Nascimento: " << endl;
    data_nascimento.bshow();
    cout << endl;

}