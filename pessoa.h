#ifndef PESSOA_H
#define PESSOA_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "data.h"
#include "node.h"   
#include "avl.h"

class Pessoa {
public:
    int Cpf;
    std::string Nome;
    Date data_nascimento;
    
    Pessoa() = default;
    Pessoa(int cpf, std::string nome, Date data_nascimento);
    int getCpf();
    std::string getNome();
    Date getDataNascimento();

    void setCpf(int cpf);
    void setNome(std::string nome);
    void setdataNascimento(Date data_nascimento);

};

#endif //PESSOA_H