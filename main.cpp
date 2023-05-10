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

void preencherArvores_Cpf (avl_tree<string> &Cpf, vector<Pessoa> &pessoas) {
    for (int i = 0; i < pessoas.size(); i++) {  
        Cpf.add(pessoas[i].getCpf());
    }
}

void preencherArvores_Nome (avl_tree<string> &Nome, vector<Pessoa> &pessoas) {
    for (int i = 0; i < pessoas.size(); i++) {
        Nome.add(pessoas[i].getNome());
    }
}

void preencherArvores_Data (avl_tree<Date> &data_nascimento, vector<Pessoa> &pessoas) {
    for (int i = 0; i < pessoas.size(); i++) {
        data_nascimento.add(pessoas[i].getDataNascimento());
    }
}

// Consultar uma única pessoa pelo seu CPF e exibir seus dados na tela.
void consultaporCpf(avl_tree<string> &Cpf, avl_tree<string>&Nome, avl_tree<Date>&data_nascimento, const string& cpf) {
    if (Cpf.search(cpf) != nullptr) {
        Node<string>* node = Cpf.search(cpf);
        string pessoaStr = node->key;
        Pessoa pessoa = Pessoa::fromString(pessoaStr);

        Node<string>* nodeNome = Nome.search(pessoa.getNome());
        if (nodeNome != nullptr) {
            string nomeStr = nodeNome->key;
            pessoa.setNome(nomeStr
            );
        }
        Node<Date>* nodeData = data_nascimento.search(pessoa.getDataNascimento());
        if (nodeData != nullptr) {
            Date data = nodeData->key;
            pessoa.setdataNascimento(data);
        }
        if (nodeNome == nullptr || nodeData == nullptr) {
            cout << "Dados incompletos." << endl;
        }
        cout << "Nome: " << pessoa.getNome() << endl;
        cout << "CPF: " << pessoa.getCpf() << endl;
        cout << "Data de Nascimento: " << pessoa.getDataNascimento().strPrint() << endl;
    }
    else {
        cout << "CPF não encontrado." << endl;
    }
}


int main() {

    system("chcp 65001 > nul");

    vector<Pessoa> pessoas;
    readFile(pessoas, "data.csv");

    avl_tree<string> Cpf;
    avl_tree<string> Nome;
    avl_tree<Date> data_nascimento;

    preencherArvores_Cpf(Cpf, pessoas);
    preencherArvores_Nome(Nome, pessoas);   
    preencherArvores_Data(data_nascimento, pessoas);

    string cpf_consulta;
    cout << "Digite o CPF da pessoa que deseja consultar: ";
    cin >> cpf_consulta;
    consultaporCpf(Cpf, Nome, data_nascimento, cpf_consulta);
    
    /*cout << "Arvore de CPFs: " << endl;
    Cpf.bshow();
    cout << endl;

    cout << "Arvore de Nomes: " << endl;
    Nome.bshow();
    cout << endl; 

    cout << "Arvore de Datas de Nascimento: " << endl;
    data_nascimento.bshow();
    cout << endl;*/ 

}