#ifndef AVL_H
#define AVL_H
#include <vector>
#include <string>
#include "node.h"
#include "data.h"


template<typename T>
class avl_tree {
public:
    avl_tree() = default;
    avl_tree(const avl_tree& t); 
    avl_tree& operator=(const avl_tree& t); 
    int height() const;
    void bshow() const;
    ~avl_tree();

    void add(T key);                                 // O(lg n)
    Node<T>* search(T key);                          // O(lg n)
    void clear();                                    // O(n)
    void remove(T key);                              // O(lg n)
    void access_keys_inorder(void (*f)(T& key));      // O(n)
    void keys_as_vector(std::vector<T>& v) const;     // O(n)

                        
private:
    Node<T> *root {nullptr};            

    int height(Node<T> *node);
    int balance(Node<T> *node);
    Node<T>* search(Node<T> *node, T key);
    Node<T>* rightRotation(Node<T> *p);
    Node<T>* leftRotation(Node<T> *p);
    Node<T>* add(Node<T> *p, T key);
    Node<T>* fixup_node(Node<T> *p, T key);
    void bshow(Node<T> *node, std::string heranca) const;
    Node<T>* clear(Node<T> *node);
    Node<T>* remove(Node<T> *node, T key); 
    Node<T>* remove_successor(Node<T> *root, Node<T> *node);
    Node<T>* fixup_deletion(Node<T> *node);
};

#endif
