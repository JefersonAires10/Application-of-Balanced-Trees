#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "pessoa.h"
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
        ss2 >> dia;
        ss2.ignore(1);
        ss2 >> mes;
        ss2.ignore(1);
        ss2 >> ano;
        Date dataDeNascimento(dia, mes, ano);

        Pessoa pessoa(cpf, nome + " " + sobrenome, dataDeNascimento);
        pessoas.push_back(pessoa);

    }
}

void preencherArvores(avl_tree<string> &Cpf, avl_tree<string> &Nome, avl_tree<Date> &data_nascimento, vector<Pessoa> &pessoas) {
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

    avl_tree<string> Cpf;
    avl_tree<string> Nome;
    avl_tree<Date> data_nascimento;

    preencherArvores(Cpf, Nome, data_nascimento, pessoas);

    /*cout << "Arvore de CPFs: " << endl;
    Cpf.bshow();
    cout << endl;*/
    
    Cpf.searchCpf(Cpf, "99795525140");


    /*cout << "Arvore de Nomes: " << endl;
    Nome.bshow();
    cout << endl;

    cout << "Arvore de Datas de Nascimento: " << endl;
    data_nascimento.bshow();
    cout << endl;*/

}