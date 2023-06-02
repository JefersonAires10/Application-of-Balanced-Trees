#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "node.h"
#include "data.h"
#include "pessoa.h"

template<typename T>
class avl_tree {
public:

    /**
     * @brief Construtor default da classe avl_tree
     * 
    */
    avl_tree() = default;
    
    /**
     * @brief Construtor da classe avl_tree
     * 
     * @param t 
     */
    avl_tree(const avl_tree& t); 

    /**
     * @brief Função para printar a árvore organizada
     * @param root
     * */    
    void bshow() const { bshow(root, ""); }

    /**
     * @brief Destrutor da classe avl_tree
    */
    ~avl_tree() { clear(); }

    /**
     * @brief Função para adicionar um novo nó na árvore
     * @param Key tipo T, Ponteiro para Pessoa
    */
    void add(T key, Pessoa *pessoa) { root = add(root, key, pessoa); }    

    /**
     * @brief Função para limpar a árvore
     * @param root
    */
    void clear() { root = clear(root); } 

    /**
     * @brief Função de busca na árvore
     * @param root, Key tipo T
    */
    Node<T>* search(T key) { return search(root, key); }                          

    /**
     * @brief Função de busca na árvore de nomes, através do nome (completo)
     * @param referencia para a árvore de nomes, Key tipo T 
    */
    void exibirCidade(const avl_tree<T>& arvoreNome, T key) {
        Node<T> *nodeNome = search(key); // Busca o nó na árvore de nomes através da search
        if (nodeNome != nullptr) { // Se o nó existir
            Pessoa *pessoa = nodeNome->pessoa; // Eu tenho um ponteiro pra pessoa, atribuo o ponteiro do nó para o ponteiro da pessoa
            std::cout << "A(o) " << nodeNome->key << " é de " << pessoa->getCidade() << std::endl; // Pego o getCidade da pessoa
        }
        else {
            std::cout << "O nome informado é inexistente!" << std::endl; // Se o nó não existir
        }
    }
    
    /**
     * @brief Função de consulta através do CPF na árvore de CPFs
     * @param referencia para a árvore de CPFs, Key tipo T
    */
    void searchCpf(const avl_tree<T>& arvoreCpf, T key) {
        Node<T> *nodeCpf = search(key); // Busca o nó na árvore de CPFs através da search, pois o cpf é único para cada pessoa
        if(nodeCpf != nullptr) { // Se o nó existir
            Pessoa *pessoa = nodeCpf->pessoa; // Eu tenho um ponteiro pra pessoa, atribuo o ponteiro do nó para o ponteiro da pessoa
            /*Imprimo as informações do nó encontrado, através das funções get, da classe Pessoa*/
            std::cout << "CPF: " << nodeCpf->key << std::endl; 
            std::cout << "Nome: " << pessoa->getNome() << std::endl;
            std::cout << "Data de nascimento: " << pessoa->getDataNascimento() << std::endl;
        
        }
        else {
            std::cout << "O Cpf informado é inexistente!" << std::endl; // Se o nó não existir
        }
    }

    /**
     * @brief Função pública para a consulta de pessoas por prefixo
     * @param referencia para a árvore de nomes, referencia para T key 
    */
    void searchName(const avl_tree<T>& arvoreNome, const T& key) {
        searchNameHelper(arvoreNome.root, key);
    }

    /**
     * @brief Função pública para a consulta de pessoas por um intervalo de datas
     * @param referencia para a árvore de datas, referencia para T dataInicial, referencia para T dataFinal
    */
    void searchDate(const avl_tree<T>& arvoreData, const T& dataInicial, const T& dataFinal) {
        searchDateHelper(arvoreData.root, dataInicial, dataFinal);
    }
    
private:

    Node<T> *root {nullptr};            
    /**
     * @brief Função privada para calcular a altura de um nó
     * @param ponteiro para o Node
     * @return altura do nó
    */
    int height(Node<T> *node) { return (node == nullptr) ? 0 : node->height; }

    /**
     * @brief Função retorna o fator de balanceamento de um nó
     * @param ponteiro para o Node
     * @return fator de balanceamento do nó
    */
    int balance(Node<T> *node) { return height(node->right) - height(node->left); } 

    /**
     * @brief Função privada para consulta de nome por prefixo
     * @param ponteiro para o Node nome e uma referencia constante para T key
    */
    void searchNameHelper(const Node<T>* nodeNome, const T& key) {
        if (nodeNome == nullptr) { // Se o nó for nulo, retorna
            return; 
        }

        /*
            Aqui é feita a comparação do prefixo da chave key com o prefixo da chave do nó,
            através da função compare, uma função da bibilioteca string, que retorna 0 se as strings forem iguais.
            A função compara o valor de key com o valor do nó, até o tamanho da string key.
            Onde key é o prefixo que o usuário digitou e nodeNome->key é o prefixo da chave do nó atual
            O primeiro parametro é o indice inicial da string, ou seja, de onde vai começar a comparação
            O segundo parametro pega o tamanho da string que vai ser comparada
            E o terceiro parametro é a string que vai ser comparada.
        */
        if (nodeNome->key.compare(0, key.length(), key) == 0) { // Se todo o valor da comparação for igual a 0
            // O quer diz que o prefixo da chave do nó é igual ao prefixo da chave key
            Pessoa *pessoa = nodeNome->pessoa; // atribuo o ponteiro do nó para o ponteiro da pessoa
            std::cout << nodeNome->key << std::endl; // imprimo a chave do nó
            /* E imprimo os dados da pessoa através das funções get, da classe Pessoa.*/
            std::cout << "Nome: " << pessoa->getNome() << std::endl;
            std::cout << "CPF: " << pessoa->getCpf() << std::endl;
            std::cout << "Data de nascimento: " << pessoa->getDataNascimento() << std::endl;
            std::cout << std::endl;

            /*
            Na minha classe Node, eu tenho um vector de ponteiros para pessoas, chamado chavesIguais.
            Eu vou preenchendo esse vector com os ponteiros para as pessoas que tem o mesmo prefixo.
            Então, se o vector não estiver vazio, eu percorro ele e imprimo os dados das pessoas.   
            */
            if (!nodeNome->chavesIguais.empty()) { // Se o vector não estiver vazio
                /*
                Fiz usando um for range, que itera sobre os elementos do vector
                Cada elemento é acessado por referencia, uso o auto para que o tipo seja deduzido pelo compilador
                */
                for (const auto& pessoa : nodeNome->chavesIguais) { // Para cada pessoa no vector
                    /* 
                    imprimo também as informações dessas pessoas, pois a busca é por prefixo
                    e podemos ter mais de uma pessoa com o mesmo prefixo
                    */
                    std::cout << "CPF: " << pessoa->getCpf() << std::endl;
                    std::cout << "Nome: " << pessoa->getNome() << std::endl;
                    std::cout << "Data de nascimento: " << pessoa->getDataNascimento() << std::endl;
                    std::cout << std::endl;
                }
            }
        }
        /*
        Aqui eu comparo o prefixo da chave key com o prefixo da chave do nó atual
        Se o prefixo da chave key for menor que o prefixo da chave do nó atual
        E o nó da esquerda não for nulo, eu chamo a função recursivamente passando o nó da esquerda
        Isso serve para que eu possa percorrer a árvore toda, e não só o nó atual, através do prefixo da chave
        Lexicograficamente, se o prefixo da chave key for menor que o prefixo da chave do nó atual
        Então o prefixo da chave key está antes na ordem alfabética
        */
        if (key[0] <= nodeNome->key[0] && nodeNome->left != nullptr) { 
            searchNameHelper(nodeNome->left, key);
        }
        
        /*
        Faço a mesma coisa de cima, só que agora comparando se o prefixo da chave key é maior que o prefixo da chave do nó atual
        e chamando a função recursivamente para a direita, se o nó da direita não for uma folha
        */
        if (key[0] >= nodeNome->key[0] && nodeNome->right != nullptr) {
            searchNameHelper(nodeNome->right, key);
        }
        
    }
    /*
    Para implemetar essa função eu usei uma lógica parecida com a da função searchNameHelper
    só que como essa consula é dentro de um intervalo, eu tenho como parametro uma referencia constante para 
    T dataInicial e T dataFinal, que são as datas que o usuário vai digitar. E e o nó atual, que é o nó da data.
    */

   /**
    * @brief Função privada para consulta por intervalo de datas
    * @param ponteiro para o Node data, uma referencia constante para T dataInicial e T dataFinal
   */
    void searchDateHelper(Node<T>* nodeDate, const T& dataInicial, const T& dataFinal) {
        
        /*
        Criei um nó auxiliar que recebe o nó atual e vai me auxiliar a percorrer a árvore recursivamente
        */
        Node<T>* aux = nodeDate;
        // Se   
        if (nodeDate == nullptr || aux->key > dataFinal) {
            return;
        }
        /*
        Se o meu aux->left for diferente de nulo, quer dizer que eu tenho filhos esquerdo
        E se o máximo da minha subárvore esquerda é maior ou igual a data inicial que foi buscada no intervalo, 
        isso quer dizer que a maior chave da minha subárvore esquerda está dentro do intervalo, pois ela é maior que 
        a data inicial, que é o limite inferior do intervalo. Então, vale a pena eu percorrer a subárvore esquerda.
        Então eu chamo a função recursivamente passando o nó da esquerda, a data inicial e a data final.
        */
        if (aux->left != nullptr && (maximum(aux->left)->key) >= dataInicial) {
            searchDateHelper(aux->left, dataInicial, dataFinal);
        }
        /*
        As consultas que caem nestes if's, são consultas que com certeza estão dentro do intervalo,
        pois o meu nó ele é maior ou igual a data inicial e menor ou igual a data final. 
        então eu pego o ponteiro pra pessoa e imprimo os dados das pessoas, através das funções get da classe Pessoa.
        */
        if (aux->key >= dataInicial && aux->key <= dataFinal) {
            /*715.379.468-97,Luis,Sousa,03/15/1946,Vitória*/
            Pessoa *pessoa = aux->pessoa;
            std::cout << pessoa->getCpf() << ", " << pessoa->getNome()  << ", " << pessoa->getDataNascimento() << ", " << pessoa->getCidade() << std::endl;  
            /*
            Se o vector de chaves iguais não estiver vazio, quer dizer que eu tenho mais de uma pessoa com o mesmo prefixo
            Então eu percorro esse vector e imprimo os dados das pessoas que tem o mesmo prefixo.
            */
            if (!aux->chavesIguais.empty()) {
                /*Fiz usando um for range, que itera sobre os elementos do vector
                Cada elemento é acessado por referencia, uso o auto para que o tipo seja deduzido pelo compilador*/
                for (const auto& pessoa : nodeDate->chavesIguais) {
                    std::cout << pessoa->getCpf() << ", " << pessoa->getNome()  << ", " << pessoa->getDataNascimento() << ", " << pessoa->getCidade() << std::endl;  
                }
            }
        }

        /*
        Uso a mesma lógica busca para a subárvore esquerda, só que agora para a direita.
        Verifico se meu nó da direita não é nulo e se o menor elemento da minha subárvore direita é menor ou igual a data final
        Se for, quer dizer que o menor elemento da minha subárvore direita pode está dentro do intervalo, então vale a pena eu percorrer
        a subárvore direita. Faço isso chamando a função de forma recursiva passando o nó da direita, a data inicial e a data final.
        */
        if (aux->right != nullptr && (minimum(aux->right)->key) <= dataFinal) {
            searchDateHelper(aux->right, dataInicial, dataFinal);
        }
    }

    /**
    @brief Função privada que retorna o nó com a menor chave
    @param ponteiro para o Node<T> node
    @return ponteiro para o Node<T> aux
    */
    Node<T>* minimum(Node<T> *node) {
        Node<T> *aux = root;
        while (aux != nullptr && aux->left != nullptr) {
            if (aux->left == nullptr) { return aux; }
            else { aux = aux->left; }
        }
        return aux;
    }

    /**
     * @brief Função privada que retorna o nó com a maior chave
     * @param ponteiro para o Node<T> node
     * @return ponteiro para o Node<T> aux
    */
    Node<T>* maximum(Node<T> *node) {
        Node<T> *aux = root;
        while (aux != nullptr && aux->right != nullptr) {
            if (aux->right == nullptr) { return aux; }
            else { aux = aux->right; }
        }
        return aux;
    }

    /**
     * @brief Função privada de busca de um nó na árvore
     * @param ponteiro para o Node<T> p, T key
     * @return ponteiro para o Node<T> p
    */
    Node<T>* search(Node<T> *p, T key) {
        if(p == nullptr || p->key == key)
            return p;
        if(key < p->key)
            return search(p->left, key);
        else
            return search(p->right, key);
    }
    /**
     * @brief Função privada de rotação para a direita AVL
     * @param ponteiro para o Node<T> p
     * @return ponteiro para o Node<T> u
    */
    Node<T>* rightRotation(Node<T> *p) {
        Node<T> *u = p->left;
        p->left = u->right;
        u->right = p;
        // recalcular as alturas de p e de u
        p->height = 1 + std::max(height(p->left),height(p->right));
        u->height = 1 + std::max(height(u->left),height(u->right));
        return u;
    }
    /**
     * @brief Função privada de rotação para a esquerda AVL
     * @param ponteiro para o Node<T> p
     * @return ponteiro para o Node<T> u
    */
    Node<T>* leftRotation(Node<T> *p) {
        Node<T> *u = p->right;
        p->right = u->left;
        u->left = p;
        // recalcular as alturas de p e de u
        p->height = 1 + std::max(height(p->right),height(p->left));
        u->height = 1 + std::max(height(u->left),height(u->right));
        return u;
    }
    /**
     * @brief Função privada para adicionar um nó na árvore
     * @param ponteiro para o Node<T> p, T key, Pessoa *pessoa
     * @return ponteiro para o Node<T> p
    */
    Node<T>* add(Node<T> *p, T key, Pessoa *pessoa) {
        /*
        Tive que alterar a minha add, pois agora eu preciso que os 
        nós sejam adicionados na árvore
        com um ponteiro para pesso
        */
        if(p == nullptr)
            return new Node<T>(key, pessoa);
        if(key < p->key)
            p->left = add(p->left, key, pessoa);
        else if(key > p->key) {
            p->right = add(p->right, key, pessoa);
        }
        /*
        Aqui é a lógica para adicionar os nós com prefixos iguais.
        Se não entrar nos outros ifs, quer dizer que a chave é igual
        então eu mando essas chaves pro vector, que foi criado na classe Node
        e percorro esse vector nas minhas funções de consulta por prefixo e por intervalo de datas.
        */
        else 
            p->chavesIguais.push_back(pessoa);
        
        p = fixup_node(p, key);

        return p;
        
    }

    /**
     * @brief Função privada para corrigrir o balanceamento da árvore após insersão ou remoção de um nó
     * @param ponteiro para o Node<T> p, T key
     * @return ponteiro para o Node<T> p
    */
    Node<T>* fixup_node(Node<T> *p, T key) {
        // recalcula a altura de p
        p->height = 1 + std::max(height(p->left),height(p->right));

        // calcula o balanço do p
        int bal = balance(p);

        if(bal >= -1 && bal <= 1) {
            return p;
        }

        if(bal < -1 && key < p->left->key) {
            p = rightRotation(p);
        }
        else if(bal < -1 && key > p->left->key) {
            p->left = leftRotation(p->left);
            p = rightRotation(p);
        }
        else if(bal > 1 && key > p->right->key) {
            p = leftRotation(p);
        }
        else if(bal > 1 && key < p->right->key) {
            p->right = rightRotation(p->right);
            p = leftRotation(p);
        }
        return p;
    }
    /**
     * @brief Função privada para deletar a árvore
     * @param ponteiro para o Node<T> node
     * @return nullptr
    */
    Node<T> *clear(Node<T> *node) {
        if(node != nullptr) {
            node->left = clear(node->left);
            node->right = clear(node->right);
            delete node;
        }
        return nullptr;
    }
    /**
     * @brief Função privada para printar a árvore organizada
     * @param ponteiro para o Node<T> node, std::string heranca
    */  
    void bshow(Node<T> *node, std::string heranca) const {
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            bshow(node->right , heranca + "r");
        for(int i = 0; i < (int) heranca.size() - 1; i++)
            std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
        if(heranca != "")
            std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
        if(node == nullptr){
            std::cout << "#" << std::endl;
            return;
        }
        std::cout << node->key << std::endl;
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            bshow(node->left, heranca + "l");
    }

};

#endif // AVL_TREE_H