#include <iostream>
#include <stdexcept>
#include "bst.h"

BST::BST() {  // Construtor
    root = nullptr; 
} 
    
BST::~BST() {  // Destrutor
    root = clear(root);
} 

// Esta funcao recebe um ponteiro para um node e libera
// os nos da arvore enraizada nesse node. A funcao devolve
// nullptr apos apagar a arvore enraizada em node
Node *BST::clear(Node *node) {  
    if(node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
    }
    return nullptr;
}

// Esta funcao recebe um ponteiro para node e uma key e:
// (1) devolve nullptr caso key nao esteja na arvore;
// (2) devolve um ponteiro para o no contendo key caso contrario.
Node* BST::search(Node *node, int key) {
    if(node == nullptr || node->key == key) { // caso base
        return node;
    }
    if(key > node->key) { // Caso geral: ainda não achei o pai, vamos procurá-lo
        return search(node->right, key);
    }
    else {
        return search(node->left, key);
    }
} 

bool BST::contains(int key) {
    return search(root, key) != nullptr;
}
 
// Esta funcao insere o no com chave key na arvore
// enraizada em node, somente se a chave key nao for repetida.
// Devolve um ponteiro para a raiz da nova arvore 
// enraizada em node.
Node* BST::add(Node *node, int key) {
    if(node == nullptr) { // Caso base 1
        node = new Node(key, nullptr, nullptr);
        return node;
    }
    // Casos gerais
    if(key > node->key) {
        node->right = add(node->right, key);
    }
    else if(key < node->key) {
        node->left = add(node->left, key);
    }
    return node;
} 

// função publica
void BST::add(int key) {
    root = add(root, key);
}

// Recebe um ponteiro para a arvore enraizada em node e:
// (1) devolve o ponteiro para o no contendo o minimo; ou
// (2) devolve nullptr se a arvore for vazia.
Node *BST::minimum(Node *node) {
    if(node != nullptr && node->left != nullptr)  // Caso node atual não é o mínimo
        return minimum(node->left);
    return node;
}

// funcao publica. Devolve a chave minima da arvore
int BST::minimum() {
    if(root == nullptr) // arvore vazia
        throw std::runtime_error("erro: arvore vazia");
    else 
        return minimum(root)->key;
}

void BST::inorder() {
    inorder(root);
}

void BST::inorder(Node *node) {
    if(node != nullptr) {
        inorder(node->left);
        std::cout << node->key << " ";
        inorder(node->right);
    }
}

// Essa funcao recebe uma chave e remove o no contendo
// essa chave somente se ela existir na arvore
void BST::remove(int key) {
    root = remove(key, root);		
} 


Node *BST::remove(int k, Node *node) {
    if(node == nullptr) // Arvore vazia 
        return nullptr; 
    if(k == node->key) // Achou o no a ser removido
        return removeRoot(node); // funcao auxiliar 
    // Ainda nao achamos o no, vamos busca-lo
    if(k < node->key) 
        node->left = remove(k, node->left);
    else 
        node->right = remove(k, node->right);
    return node;
}

// Recebe um ponteiro node para a raiz de uma arvore e 
// remove a raiz, rearranjando a arvore de modo que ela 
// continue sendo de busca. Devolve o endereco da nova raiz 
Node *BST::removeRoot(Node *node) {
    Node *pai, *q;
    if(node->right == nullptr)
        q = node->left;
    else {
        pai = node;
        q = node->right;
        while(q->left != nullptr) {
            pai = q;
            q = q->left;
        }
        if(pai != node) {
            pai->left = q->right;
            q->right = node->right;
        }
        q->left = node->left;
    }
    delete node;
    return q;
}


// ------------------------------------------------------
// As funcoes abaixo devem ser implementadas
// ------------------------------------------------------
/*
// Devolve o ponteiro para o no sucessor do no x
// passado como parametro. A funcao tambem recebe
// como parametro a raiz da arvore.
Node *BST::successor(Node *x, Node *raiz) {
    // TODO
}

Node *BST::ancestral_sucessor(Node *x, Node *raiz) {
    // TODO
}

int BST::successor(int k) {
    // TODO
}

// Retorna o ponteiro para o no antecessor do no x
// passado como parametro. A funcao tambem recebe 
// como parametro a raiz da arvore.
Node* BST::predecessor(Node *x, Node* raiz) {
    // TODO
}

Node *BST::ancestral_predecessor(Node *x, Node* raiz) {
    // TODO
}

int BST::predecessor(int k) {
    // TODO
}

// Recebe um ponteiro para a arvore enraizada em node e:
// (1) devolve o ponteiro para o no contendo o maximo; ou
// (2) devolve nullptr se a arvore for vazia.
Node *BST::maximum(Node *node) {
    // TODO
}

// Funcao publica. Devolve a chave maxima da arvore
int BST::maximum() {
    // TODO
}
*/





