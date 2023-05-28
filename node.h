#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {
    // atributos
    T key;                      // chave do nó
    int height;                 // altura do nó
    Node<T> *left;              // ponteiros para filho esquerdo
    Node<T> *right;             // ponteiros para filho direito
    Pessoa *pessoa;             // ponteiro para a pessoa
    
    /*
    Criei um vector com ponteiro pra Pessoa para armazenar as pessoas que possuem a mesma chave.
    Utilizei dessa estrutura para me auxiliar nas consultas por nome e por intervalo de dadas. 
    */
    std::vector<Pessoa*> chavesIguais;     
    
    // Construtor
    Node (T key, Node<T> *left = nullptr, Node<T> *right = nullptr, int height = 1, Pessoa *pessoa = nullptr)
        : key(key), height(height), left(left), right(right), pessoa(pessoa)
    {
    }

    // Sobrecarga do construtor
    /*
    O primeiro construtor cria o nó com todos os paramentros de Node
    O segundo construtor cria o nó com apenas a chave e a pessoa.
    Como eu tenho um ponteiro para pessoa nos meus nós, eu precisei fazer essa sobrecarga, pois o compilador
    tava dando um erro de conversão de tipo, pois eu estava passando um ponteiro para pessoa no construtor
    do nó, mas o construtor do nó não estava esperando um ponteiro para pessoa, e sim um objeto do tipo pessoa.
    Com essa sobrecarga, eu consigo passar um ponteiro para pessoa no construtor do nó e usar a minha add.
    */

    Node (T key, Pessoa *pessoa)
        : key(key), height(1), left(nullptr), right(nullptr), pessoa(pessoa)
    {
    }

};

#endif 
