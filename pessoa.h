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
    std::string Cpf;
    std::string Nome;
    Date data_nascimento;
    
    Pessoa() = default;
    Pessoa(std::string cpf, std::string nome, Date data_nascimento);
    std::string getCpf();
    std::string getNome();
    Date getDataNascimento();

    void setCpf(std::string cpf);
    void setNome(std::string nome);
    void setdataNascimento(Date data_nascimento);

    static Pessoa fromString(const std::string& line);
};

#endif //PESSOA_H