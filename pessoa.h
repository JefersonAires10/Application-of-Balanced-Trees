#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include "data.h"

/**
 * @brief Classe Pessoa que contém os atributos de uma pessoa
*/
class Pessoa {
    private:
        std::string cpf;
        std::string nome;
        Date dataDeNascimento;
        std::string cidade;
    
    public:
        Pessoa() = default; // Construtor padrão
        // Construtor
        /**
         * @brief Construtor da classe Pessoa
        */
        Pessoa(std::string cpf, std::string nome, Date dataDeNascimento, std::string cidade) : cpf(cpf), nome(nome), dataDeNascimento(dataDeNascimento), cidade(cidade) {}

        /**
         * @brief getCpf da classe Pessoa
         * @return cpf
        */
        std::string getCpf() { return this->cpf; }
        /**
         * @brief setCpf da classe Pessoa   
         * @param novoCpf
        */
        void setCpf(int novoCpf) { this->cpf = novoCpf; }

        /**
         * @brief getNome da classe Pessoa
         * @return nome
        */
        std::string getNome() { return this->nome; }
        /**
         * @brief setNome da classe Pessoa
         * @param novoNome
        */
        void setNome(std::string novoNome) { this->nome = novoNome; }
        /**
         * @brief getDataNascimento da classe Pessoa
         * @return dataDeNascimento
        */
        Date& getDataNascimento() { return this->dataDeNascimento; }
        void setDataNascimento(Date novaData) { this->dataDeNascimento = novaData; }
        /**
         * @brief getCidade da classe Pessoa
         * @return cidade
        */
        std::string getCidade() { return this->cidade; }
        /**
         * @brief setCidade da classe Pessoa
         * @param novaCidade
        */
        void setCidade(std::string novaCidade) { this->cidade = novaCidade; }
    
};

#endif // PESSOA_H