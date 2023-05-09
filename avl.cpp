#include <iostream>
#include "node.h"
#include "avl.h"
#include "data.h"

using namespace std;

template <typename T>
int avl_tree<T>::height(Node<T> *node) {
    return (node == nullptr) ? 0 : node->height;
}

template <typename T>
int avl_tree<T>::balance(Node<T> *node) {
    return height(node->right) - height(node->left);
}

template <typename T>
Node<T>* avl_tree<T>::rightRotation(Node<T> *p) {
    Node<T> *u = p->left;
    p->left = u->right;
    u->right = p;
    // recalcular as alturas de p e de u
    p->height = 1 + max(height(p->left),height(p->right));
    u->height = 1 + max(height(u->left),height(u->right));
    return u;
}

template <typename T>
Node<T>* avl_tree<T>::leftRotation(Node<T> *p) {
    Node<T> *u = p->right;
    p->right = u->left;
    u->left = p;
    // recalcular as alturas de p e de u
    p->height = 1 + max(height(p->right),height(p->left));
    u->height = 1 + max(height(u->left),height(u->right));
    return u;
}

template <typename T> 
void avl_tree<T>::add(T key) {
    root = add(root, key);
}

template <typename T>
Node<T>* avl_tree<T>::add(Node<T> *p, T key) {
    if(p == nullptr)
        return new Node<T>(key);
    if(key == p->key) 
        return p;
    if(key < p->key)
        p->left = add(p->left, key);
    else 
        p->right = add(p->right, key);
    
    p = fixup_node(p, key);

    return p;
}

template <typename T>
Node<T>* avl_tree<T>::fixup_node(Node<T> *p, T key) {
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

template <typename T>
void avl_tree<T>::clear() {
    root = clear(root);
}

template <typename T>
Node<T> *avl_tree<T>::clear(Node<T> *node) {
    if(node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
    }
    return nullptr;
}

template <typename T>
avl_tree<T>::~avl_tree() {
    clear();
}

template <typename T>
void avl_tree<T>::bshow() const {
    bshow(root, "");
}
            
template <typename T>
void avl_tree<T>::bshow(Node<T> *node, string heranca) const {
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

template <typename T>
void avl_tree<T>::remove(T key) {
    root = remove(root, key);
}

template <typename T>
Node<T>* avl_tree<T>::remove(Node<T> *node, T key) {
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

template <typename T>
Node<T>* avl_tree<T>::remove_successor(Node<T> *root, Node<T> *node) {
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

template <typename T>
Node<T>* avl_tree<T>::fixup_deletion(Node<T> *node) {
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

template class avl_tree<int>;
template class avl_tree<string>;
template class avl_tree<Date>;