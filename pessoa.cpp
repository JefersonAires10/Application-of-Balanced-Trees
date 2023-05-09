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

Pessoa::Pessoa(int Cpf, std::string Nome, Date data_nascimento) {
    this->Cpf = Cpf;
    this->Nome = Nome;
    this->data_nascimento = data_nascimento;
}

int Pessoa::getCpf() {
    return this->Cpf;
}
string Pessoa::getNome() {
    return this->Nome;
}
Date Pessoa::getDataNascimento() {
    return this->data_nascimento;
}

void Pessoa::setCpf(int Cpf) {
    this->Cpf = Cpf;
}
void Pessoa::setNome(string Nome) {
    this->Nome = Nome;
}
void Pessoa::setdataNascimento(Date data_nascimento) {
    this->data_nascimento = data_nascimento;
}