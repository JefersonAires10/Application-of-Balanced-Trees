#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include "data.h"

class Pessoa {
    private:
        std::string cpf;
        std::string nome;
        Date dataDeNascimento;
    
    public:
        Pessoa() = default; // Construtor padrão
        // Construtor
        Pessoa(std::string cpf, std::string nome, Date dataDeNascimento) : cpf(cpf), nome(nome), dataDeNascimento(dataDeNascimento) {}

        // Getters e Setters
        std::string getCpf() { return this->cpf; }
        void setCpf(int novoCpf) { this->cpf = novoCpf; }
        std::string getNome() { return this->nome; }
        void setNome(std::string novoNome) { this->nome = novoNome; }
        Date& getDataNascimento() { return this->dataDeNascimento; }
        void setDataNascimento(Date novaData) { this->dataDeNascimento = novaData; }

        // função para printar informações da pessoa
        /*void print(const Pessoa& pessoa) {
            std::cout << "CPF: " << pessoa.getCpf() << std::endl;
            std::cout << "Nome: " << pessoa.getNome() << std::endl;
            std::cout << "Data de nascimento: " << pessoa.getDataNascimento() << std::endl;
        }*/
    
};

#endif // PESSOA_H