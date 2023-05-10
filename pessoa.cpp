#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "pessoa.h"
#include "data.h"
#include "node.h"
#include "avl.h"

using namespace std;
using std::vector;

Pessoa::Pessoa(string Cpf, string Nome, Date data_nascimento) {
    this->Cpf = Cpf;
    this->Nome = Nome;
    this->data_nascimento = data_nascimento;
}

string Pessoa::getCpf() {
    return this->Cpf;
}
string Pessoa::getNome() {
    return this->Nome;
}
Date Pessoa::getDataNascimento() {
    return this->data_nascimento;
}

void Pessoa::setCpf(string Cpf) {
    this->Cpf = Cpf;
}
void Pessoa::setNome(string Nome) {
    this->Nome = Nome;
}
void Pessoa::setdataNascimento(Date data_nascimento) {
    this->data_nascimento = data_nascimento;
}

Pessoa Pessoa::fromString(const string& line) {
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
    return pessoa;
}
