/**
 * @file BinaryTree.cpp
 * @author Victor Emanuel (victorwmanuel.costa@alu.ufc.br)
 * @brief 
 * @version 0.1
 * @date 2022-11-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <sstream>
#include "Node.h"
#include "BinaryTree.h"
using namespace std;

/**
 * @brief Construct a new empty Binary Tree object
 */
BinaryTree::BinaryTree() {
    root =  nullptr;
}

/**
 * @brief Construct a new Binary Tree with two subtrees.
 * The subtrees become empty after this operation
 * 
 * @param value The data at the root
 * @param lchild The left subtree
 * @param rchild The right subtree
 */
BinaryTree::BinaryTree(int value, BinaryTree& lchild, BinaryTree& rchild) {
    root = new Node(value, lchild.root, rchild.root);
    lchild.root = nullptr;
    rchild.root = nullptr;
}

/**
 * @brief Indicate that this is the empty tree.
 * 
 * @return true if tree is empty
 * @return false if tree is not empty
 */
bool BinaryTree::is_empty() const {
    return root == nullptr;
}

/**
 * @brief Indicate that this tree is a leaf.
 * 
 * @return true if tree is a leaf
 * @return false if tree is not a leaf
 */
bool BinaryTree::is_leaf() const {
    return !is_empty() && root->left == nullptr && root->right == nullptr;
}

/**
 * @brief função recursiva que recebe uma raiz de árvore e retorna
 * ture se ela contém o valor.
 */
bool contains_recursive(Node *node, int value) {
    if (node == nullptr) {
        return false;
    } else if (node->key == value) {
        return true;
    } else {
        return contains_recursive(node->left, value) || contains_recursive(node->right, value);
    }
}

/**
 * @brief Indicate if the tree contains the given value
 * 
 * @return true if the tree contains the given value
 * @return false if the tree does not contains the given value
 */
bool BinaryTree::contains(int value) const {
    return contains_recursive(root, value);
}

// função recursiva que imprime todas as chaves da arvore enraizada no ponteiro node
void print_keys_recursive(Node *node) {
    if(node == nullptr) { // caso de parada
        return;
    } else if (node != nullptr) {
        cout << node->key << " ";
        print_keys_recursive(node->left);
        print_keys_recursive(node->right);
    }
}
/**
 * @brief Print the keys saved on the tree
 */
void BinaryTree::print_keys() const {
    print_keys_recursive(root);
}

Node* clear_recursive(Node *node) {
    if (node == nullptr) {
        return nullptr;
    } else {
        clear_recursive(node->left);
        clear_recursive(node->right);
        delete node;

        return nullptr;
    }
}

/**
 * @brief empties the tree
 */
void BinaryTree::clear() {
    root = clear_recursive(root); 
}

BinaryTree::~BinaryTree() {
    clear();
}

// função recursiva que recebe uma raiz de árvore e retorna uma string com a serialização da árvore
void serialization_recursive(Node *node, stringstream& ss) {
    if (node == nullptr) {
        ss << "#" << " ";
        return;
    } else {
        ss << node->key << " ";
        serialization_recursive(node->left, ss);
        serialization_recursive(node->right, ss);
    }
}

// função recursiva que recebe uma string e uma raiz de árvore e retorna em ss a serialização da árvore
std::string BinaryTree::serialization() const {
    stringstream ss;
    serialization_recursive(root, ss);
    return ss.str();
}

// função recursiva que recebe uma string e retorna uma árvore
Node* serializeTree(stringstream& ss) {
    string valor;
    ss >> valor;
    if (valor == "#") {
        return nullptr;
    } else {
        int value = stoi(valor);
        Node *aux = new Node(value, nullptr, nullptr);
        aux->left = serializeTree(ss);
        aux->right = serializeTree(ss);
        return aux;
    }
}

BinaryTree::BinaryTree(std::string serialization) {
    stringstream ss(serialization);
    root = serializeTree(ss);
}