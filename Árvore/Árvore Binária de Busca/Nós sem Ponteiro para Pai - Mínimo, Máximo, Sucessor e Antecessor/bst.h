#ifndef BST_H
#define BST_H
#include <stdexcept>
#include <iostream>

/*******************************
 * Definicao do struct Node
 *******************************/
struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l, Node *r)
        : key(k), left(l), right(r) 
        { }

    ~Node() {
        std::cout << "Node removed: " << this->key << std::endl;
    }
};

/*******************************
 * class BST
 *******************************/
class BST { // classe BST (Binary Search Tree)
public:
    BST();
    ~BST();
    void bshow();
    void add(int key);       // Adicionar chave 
    bool contains(int key);  // contem chave key?
    int minimum();           // Devolve chave minima
    int maximum();           // Devolve chave maxima
    int successor(int k);    // Devolve chave sucessora de k
    int predecessor(int k);  // Devolve chave antecessora de k
private:
    Node *root;
    void bshow(Node *node, std::string heranca);
    Node *add(Node *node, int key);
    Node *search(Node *node, int key);
    Node *clear(Node *node);
    Node *minimum(Node *node);                          // ----> implementar
    Node *maximum(Node *node);                          // ----> implementar
    Node *sucessor(Node *x, Node *raiz);                // ----> implementar
    Node *predecessor(Node *x, Node* raiz);             // ----> implementar
    Node *ancestral_sucessor(Node *x, Node *raiz);      // ----> implementar
    Node *ancestral_predecessor(Node *x, Node* raiz);   // ----> implementar
};

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
Node *BST::search(Node *node, int key) {
    if(node == nullptr || node->key == key)
        return node;
    if(key > node->key)
        return search(node->right, key);
    else 
        return search(node->left, key);
} 

bool BST::contains(int key) {
    return search(root, key) != nullptr;
}
 
// Esta funcao insere o no com chave key na arvore
// enraizada em node, somente se a chave key nao for repetida.
// Devolve um ponteiro para a raiz da nova arvore 
// enraizada em node.
Node *BST::add(Node *node, int key) {
    if(node == nullptr) { // Condicao de Parada
        node = new Node(key, nullptr, nullptr);
        return node;
    }
    // Casos Gerais
    if(key > node->key)
        node->right = add(node->right, key);
    else if(key < node->key)
        node->left = add(node->left, key);
    return node;
} 

void BST::add(int key) {
    root = add(root, key);
}

// Recebe um ponteiro para a arvore enraizada em node e:
// (1) devolve o ponteiro para o no contendo o minimo; ou
// (2) devolve nullptr se a arvore for vazia.
Node *BST::minimum(Node *node) { // TODO
    if(node == nullptr) {
        return nullptr;
    }
    if(node->left == nullptr) {
        return node;
    }
    return minimum(node->left);
}

// funcao publica. Devolve a chave minima da arvore
int BST::minimum() { // TODO
    Node *min = minimum(root);
    if(min == nullptr) {
        throw std::runtime_error("Empty tree");
    }
    return min->key;
}

// Recebe um ponteiro para a arvore enraizada em node e:
// (1) devolve o ponteiro para o no contendo o maximo; ou
// (2) devolve nullptr se a arvore for vazia.
Node *BST::maximum(Node *node) { // TODO
    if(node == nullptr){
        return nullptr;
    }
    if(node->right == nullptr) {   
        return node;
    }
    return maximum(node->right);
}

// Funcao publica. Devolve a chave maxima da arvore
int BST::maximum() { // TODO
    Node *max = maximum(root);
    if (max == nullptr) {
        throw std::runtime_error("Empty tree");
    }
    return max->key;
}

// Devolve o ponteiro para o no sucessor do no x
// passado como parametro. A funcao tambem recebe
// como parametro a raiz da arvore.
Node *BST::sucessor(Node *x, Node *raiz) { // TODO
    if(x == nullptr) {
        return nullptr;
    }
    if(x->right != nullptr) {
        return minimum(x->right);
    }
    Node *y = ancestral_sucessor(x, raiz);
    return y;
}

Node *BST::ancestral_sucessor(Node *x, Node *raiz) { // TODO
    if(x == nullptr) {
        return nullptr;
    }
    if(x->key < raiz->key) {
        return raiz;
    }
    return ancestral_sucessor(x, raiz->right);
}

int BST::successor(int k) { // TODO
    Node *x = search(root, k);
    if(x == nullptr) {
        throw std::runtime_error("Key not found");
    }
    Node *y = sucessor(x, root);
    if(y == nullptr) {
        throw std::runtime_error("No successor");
    }
    return y->key;
}

// Retorna o ponteiro para o no antecessor do no x
// passado como parametro. A funcao tambem recebe 
// como parametro a raiz da arvore.
Node* BST::predecessor(Node *x, Node* raiz) { // TODO
    if(x == nullptr) {
        return nullptr;
    }
    if(x->left != nullptr) {
        return maximum(x->left);
    }
    Node *y = ancestral_predecessor(x, raiz);
    return y;
}

Node *BST::ancestral_predecessor(Node *x, Node* raiz) { // TODO
    if(x == nullptr) {
        return nullptr;
    }
    if(x->key > raiz->key) {
        return raiz;
    }
    return ancestral_predecessor(x, raiz->left);
}

int BST::predecessor(int k) { // TODO
    Node *x = search(root, k);
    if(x == nullptr) {
        throw std::runtime_error("Key not found");
    }
    Node *y = predecessor(x, root);
    if(y == nullptr) {
        throw std::runtime_error("No predecessor");
    }
    return y->key;
}

#endif