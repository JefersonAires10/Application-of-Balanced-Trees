#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {
    // atributos
    T key;
    int height;
    Node<T> *left;
    Node<T> *right;
    Pessoa *pessoa;
    
    // Construtor
    Node (T key, Node<T> *left = nullptr, Node<T> *right = nullptr, int height = 1, Pessoa *pessoa = nullptr)
        : key(key), height(height), left(left), right(right), pessoa(pessoa)
    {
    }

    // Sobrecarga do construtor
    Node (T key, Pessoa *pessoa)
        : key(key), height(1), left(nullptr), right(nullptr), pessoa(pessoa)
    {
    }

};

#endif 
