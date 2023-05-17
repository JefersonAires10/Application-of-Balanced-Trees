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
    int height() const { return root->height; }
    void bshow() const { bshow(root, ""); }
    ~avl_tree() { clear(); }

    void add(T key, Pessoa *pessoa) { root = add(root, key, pessoa); }                                 // O(lg n)
    void clear() { root = clear(root); }                                          // O(n)
    void remove(T key) { root = remove(root,key); }                              // O(lg n)

    Node<T>* search(T key) { return search(root, key); }                          // O(lg n)
    
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
            cout << "CPF não encontrado!" << endl;
        }
    }
    // Consultar todas as pessoas cujo nome comece com uma string informada pelo
    // usuário e exibir na tela todos os dados dessas pessoas na forma de lista.
    void searchName(const avl_tree<T>& arvoreNome, T key) {
        Node<T>* nodeNome = search(key);
        if (nodeNome == nullptr) {
            return;
        }
        if (nodeNome->left) {
            if (key == predecessor(nodeNome)->key) {
                searchName(arvoreNome, nodeNome->left->key);
            }
        }
        cout << "Nome: " << nodeNome->key << endl;
        Pessoa *pessoa = nodeNome->pessoa;
        cout << "CPF: " << pessoa->getCpf() << endl;
        cout << "Data de nascimento: " << pessoa->getDataNascimento() << endl;

        if (nodeNome->right) {
            if (key == sucessor(nodeNome)->key) {
                searchName(arvoreNome, nodeNome->right->key);        
            }
        }
        cout << "Nome: " << nodeNome->key << endl;
        Pessoa *pessoa = nodeNome->pessoa;
        cout << "CPF: " << pessoa->getCpf() << endl;
        cout << "Data de nascimento: " << pessoa->getDataNascimento() << endl;
    }

private:
    Node<T> *root {nullptr};            

    int height(Node<T> *node) { return (node == nullptr) ? 0 : node->height; }
    
    int balance(Node<T> *node) { return height(node->right) - height(node->left); } 

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

    Node<T>* sucessor(Node<T> *node) {
        if (node == nullptr) { return nullptr; } // se o nó não existir, não tem sucessor 

        if (node->right != nullptr) {
            Node<T> *minNode = node->right;
            while (minNode != nullptr && minNode->left != nullptr) {
                if (minNode->left == nullptr) { return minNode; }
                else { minNode = minNode->left; }
            }
        return minNode;
        }
        Node<T> *auxNode = root; // para percorrer a árvore
        Node<T> *aux = nullptr; // nó auxiliar
        while ( auxNode != node ) {
            // encontrando o menor antes
            if (auxNode->key < node->key) { auxNode = auxNode->right; }
            else { aux = auxNode; auxNode = auxNode->left; }
        }
        return aux;
    }

    Node<T>* predecessor(Node<T> *node) {
        // função oposta a função anterior
        if (node == nullptr) { return nullptr; } // se o nó não existir
    
        // mesma lógica da função anterior, buscando o antecessor
        Node<T> *auxNode = root; // para percorrer a árvore
        Node<T> *aux = nullptr; // nó auxiliar
        while ( auxNode != node ) {
            // encontrando o menor antes
            if (auxNode->key > node->key) { auxNode = auxNode->left; }
            else { aux = auxNode; auxNode = auxNode->right; }
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
        if(key == p->key) 
            return p;
        if(key < p->key)
            p->left = add(p->left, key, pessoa);
        else 
            p->right = add(p->right, key, pessoa);
        
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

    Node<T>* remove(Node<T> *node, T key) {
        if(node == nullptr) // node nao encontrado
            return nullptr; /*L\pauseL*/
        if(key < node->key) 
            node->left = remove(node->left, key);
        else if(key > node->key)
            node->right = remove(node->right, key); /*L\pauseL*/
        // encontramos no node
        else if(node->right == nullptr) { // sem filho direito
            Node<T> *child = node->left;
            delete node;
            return child;
        }
        else // tem filho direito: troca pelo sucessor
            node->right = remove_successor(node, node->right); /*L\pauseL*/
        
        // Atualiza a altura do node e regula o node
        node = fixup_deletion(node); 
        return node;
    }

    Node<T>* remove_successor(Node<T> *root, Node<T> *node) {
        if(node->left != nullptr)
            node->left = remove_successor(root, node->left);
        else {
            root->key = node->key;
            Node<T> *aux = node->right;
            delete node;
            return aux;
        }
        // Atualiza a altura do node e regula o node
        node = fixup_deletion(node);
        return node;
    }

    Node<T>* fixup_deletion(Node<T> *node) {
        node->height = 1 + max(height(node->left),height(node->right));

        int bal = balance(node);

        // node pode estar desregulado, ha 4 casos a considerar
        if(bal > 1 && balance(node->right) >= 0) {
            return leftRotation(node);
        }
        else if(bal > 1 && balance(node->right) < 0) {
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }
        else if(bal < -1 && balance(node->left) <= 0) {
            return rightRotation(node);
        }
        else if(bal < -1 && balance(node->left) > 0) { 
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
        return node;
    }
};
#endif // AVL_TREE_H
