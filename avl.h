#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <vector>
#include <string>
#include "node.h"
#include "data.h"
#include "pessoa.h"

using namespace std;

template<typename T>
class avl_tree {
public:
    avl_tree() = default;
    
    avl_tree(const avl_tree& t); 
    
    avl_tree& operator=(const avl_tree& t) {
        if(this != &t) {
            clear();
            root = clone_rec(t.root);
        }
        return *this;
    } 
    
    void bshow() const { bshow(root, ""); }

    ~avl_tree() { clear(); }

    void add(T key, Pessoa *pessoa) { root = add(root, key, pessoa); }    

    void clear() { root = clear(root); }                           

    Node<T>* search(T key) { return search(root, key); }                          

    void exibirCidade(const avl_tree<T>& arvoreNome, T key) {
        Node<T> *nodeNome = search(key);
        if (nodeNome != nullptr) {
            Pessoa *pessoa = nodeNome->pessoa;
            cout << "A(o) " << nodeNome->key << " é de " << pessoa->getCidade() << endl;
        }
        else {
            cout << "O nome informado é inexistente!" << endl;
        }
    }
    
    // Consultar uma única pessoa pelo seu CPF e exibir seus dados na tela
    void searchCpf(const avl_tree<T>& arvoreCpf, T key) {
        Node<T> *nodeCpf = search(key);
        if(nodeCpf != nullptr) {
            Pessoa *pessoa = nodeCpf->pessoa;
            cout << "CPF: " << nodeCpf->key << endl;
            cout << "Nome: " << pessoa->getNome() << endl;
            cout << "Data de nascimento: " << pessoa->getDataNascimento() << endl;
        }
        else {
            cout << "O Cpf informado é inexistente!" << endl;
        }
    }

    void searchName(const avl_tree<T>& arvoreNome, const T& key) {
        searchNameHelper(arvoreNome.root, key);
    }

    void searchDate(const avl_tree<T>& arvoreData, const T& dataInicial, const T& dataFinal) {
        searchDateHelper(arvoreData.root, dataInicial, dataFinal);
    }
    
private:
    Node<T> *root {nullptr};            

    int height(Node<T> *node) { return (node == nullptr) ? 0 : node->height; }
    
    int balance(Node<T> *node) { return height(node->right) - height(node->left); } 
    // Consultar todas as pessoas cujo nome comece com uma string informada pelo
    // usuário e exibir na tela todos os dados dessas pessoas na forma de lista.

    void searchNameHelper(const Node<T>* nodeNome, const T& key) {
        if (nodeNome == nullptr) {
            return;
        }

        if (nodeNome->key.compare(0, key.length(), key) == 0) {
            // O prefixo das strings são iguais
            Pessoa *pessoa = nodeNome->pessoa;
            std::cout << nodeNome->key << std::endl;
            std::cout << "Nome: " << pessoa->getNome() << std::endl;
            std::cout << "CPF: " << pessoa->getCpf() << std::endl;
            std::cout << "Data de nascimento: " << pessoa->getDataNascimento() << std::endl;
            cout << endl;

            if (!nodeNome->sameKey.empty()) {
                for (const auto& pessoa : nodeNome->sameKey) {
                    std::cout << "CPF: " << pessoa->getCpf() << std::endl;
                    std::cout << "Nome: " << pessoa->getNome() << std::endl;
                    std::cout << "Data de nascimento: " << pessoa->getDataNascimento() << std::endl;
                    cout << endl;
                }
            }
        }
        if (key[0] <= nodeNome->key[0] && nodeNome->left != nullptr) {
            searchNameHelper(nodeNome->left, key);
        }
        
        if (key[0] >= nodeNome->key[0] && nodeNome->right != nullptr) {
            searchNameHelper(nodeNome->right, key);
        }
    }

    void searchDateHelper(Node<T>* nodeDate, const T& dataInicial, const T& dataFinal) {
        
        Node<T>* aux = nodeDate;
        if (nodeDate == nullptr || aux->key > dataFinal) {
            return;
        }
        if (aux->left != nullptr && (maximum(aux->left)->key) >= dataInicial) {
            searchDateHelper(aux->left, dataInicial, dataFinal);
        }
        if (aux->key >= dataInicial && aux->key <= dataFinal) {
            /*715.379.468-97,Luis,Sousa,03/15/1946,Vitória*/
            Pessoa *pessoa = aux->pessoa;
            cout << pessoa->getCpf() << ", " << pessoa->getNome()  << ", " << pessoa->getDataNascimento() << ", " << pessoa->getCidade() << endl;  

            if (!aux->sameKey.empty()) {
                for (const auto& pessoa : nodeDate->sameKey) {
                    cout << pessoa->getCpf() << ", " << pessoa->getNome()  << ", " << pessoa->getDataNascimento() << ", " << pessoa->getCidade() << endl;  
                }
            }
        }
        if (aux->right != nullptr && (minimum(aux->right)->key) <= dataFinal) {
            searchDateHelper(aux->right, dataInicial, dataFinal);
        }
        
    }

    Node<T>* minimum(Node<T> *node) {
        Node<T> *aux = root;
        while (aux != nullptr && aux->left != nullptr) {
            if (aux->left == nullptr) { return aux; }
            else { aux = aux->left; }
        }
        return aux;
    }

    Node<T>* maximum(Node<T> *node) {
        Node<T> *aux = root;
        while (aux != nullptr && aux->right != nullptr) {
            if (aux->right == nullptr) { return aux; }
            else { aux = aux->right; }
        }
        return aux;
    }

    Node<T>* search(Node<T> *p, T key) {
        if(p == nullptr || p->key == key)
            return p;
        if(key < p->key)
            return search(p->left, key);
        else
            return search(p->right, key);
    }

    Node<T>* rightRotation(Node<T> *p) {
        Node<T> *u = p->left;
        p->left = u->right;
        u->right = p;
        // recalcular as alturas de p e de u
        p->height = 1 + max(height(p->left),height(p->right));
        u->height = 1 + max(height(u->left),height(u->right));
        return u;
    }

    Node<T>* leftRotation(Node<T> *p) {
        Node<T> *u = p->right;
        p->right = u->left;
        u->left = p;
        // recalcular as alturas de p e de u
        p->height = 1 + max(height(p->right),height(p->left));
        u->height = 1 + max(height(u->left),height(u->right));
        return u;
    }

    Node<T>* add(Node<T> *p, T key, Pessoa *pessoa) {
        if(p == nullptr)
            return new Node<T>(key, pessoa);
        if(key < p->key)
            p->left = add(p->left, key, pessoa);
        else if(key > p->key) {
            p->right = add(p->right, key, pessoa);
        }
        else 
            p->sameKey.push_back(pessoa);
        
        p = fixup_node(p, key);

        return p;
        
    }

    Node<T>* fixup_node(Node<T> *p, T key) {
        // recalcula a altura de p
        p->height = 1 + max(height(p->left),height(p->right));

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

    Node<T> *clear(Node<T> *node) {
        if(node != nullptr) {
            node->left = clear(node->left);
            node->right = clear(node->right);
            delete node;
        }
        return nullptr;
    }
                
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