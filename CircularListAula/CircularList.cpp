#include <sstream>
#include <string>
#include "Node.h" 
#include "CircularList.h" 
using namespace std;

// Insere val no final da lista e incrementa o valor de m_size
// Haverá dois casos: lista vazia e lista com elementos
void CircularList::push_back(const Item& val) { 
    if(m_head == nullptr) { // lista vazia
        m_head = new Node(val, nullptr);
        m_head->next = m_head;
    }
    else { // lista com pelo menos 1 elemento
        Node *aux = m_head;
        while(aux->next != m_head) {
            aux = aux->next;
        }
        aux->next = new Node(val, m_head);
    }
    m_size++;
}

Item& CircularList::operator[](int index) {
    Node *aux = m_head;
    for(int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->value;
}

const Item& CircularList::operator[](int index) const {
    Node *aux = m_head;
    for(int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->value;
}

// Retira elemento do final da lista
// Se o elemento for retirado com sucesso, m_size é decrementado
void CircularList::pop_back() {
    if(m_head == nullptr) { // lista vazia
        return;
    }
    if(m_head->next == m_head) { // lista com 1 elemento
        delete m_head;
        m_head = nullptr;
        m_size--;
    }
    else { // lista com pelo menos 2 elementos
        Node *aux = m_head;
        while(aux->next->next != m_head) {
            aux = aux->next;
        }
        delete aux->next;
        aux->next = m_head;
        m_size--;
    }
}

// Retorna lista como uma string
std::string CircularList::toString() const {
    stringstream ss;
    ss << "[ ";
    if(m_head != nullptr) {
        ss << m_head->value << " ";
        Node *aux = m_head;
        while(aux->next != m_head) {
            aux = aux->next;
            ss << aux->value << " ";
        }
    }
    ss << "]";
    return ss.str();
}

// Deixa a lista vazia
void CircularList::clear() { // O(n) 
    if(m_head != nullptr) { 
        Node *aux1 = m_head->next;
        Node *aux2 = m_head->next;
        while(aux1 != m_head) {
            aux2 = aux2->next;
            delete aux1;
            aux1 = aux2;
        }
        delete m_head;
        m_head = nullptr;
        m_size = 0;
    }
}

void clearRecursiva(Node *nodeAtual, Node *head ) { // O(n)
	if(nodeAtual->next == head) {
		delete nodeAtual;
	}
	else {
		clearRecursiva(nodeAtual->next, head);
		delete nodeAtual;
	}
}

void CircularList::clear_recursivo() {
    clearRecursiva(m_head, m_head);
}

CircularList::~CircularList() {
    clear();
}

// Insere um value no indice especificado.
// Se o index for invalido, lança uma exception std::range_error
// deve-se ter 0 <= index <= m_size
void CircularList::insert(int index, const Item& val) {
    if(index < 0 || index > m_size) {
        throw std::range_error("indice invalido");
    }
    if(m_head == nullptr) { // lista vazia
        m_head = new Node(val, nullptr);
        m_head->next = m_head;
        m_size++;
    }
    else if(index == 0) { // lista com pelo menos 1 elemento e insere na frente
        Node *novo = new Node(val, m_head);
        m_size++;
        Node *aux = m_head;
        while(aux->next != m_head) {
            aux = aux->next;
        }
        aux->next = novo;
        m_head = novo;
    }
    else { // lista com pelo menos 1 elemento e insere em outra posicao
        Node *aux = m_head;
        for(int cont = 0; cont < index-1; cont++) {
            aux = aux->next;
        }
        Node *novo = new Node(val, aux->next);
        aux->next = novo;
        m_size++;
    }
} 

// Construtor de copia
CircularList::CircularList(const CircularList& lst) {
    // fazer
}

// Remover a primeira ocorrencia de value da lista
void CircularList::remove(const Item& value) {
    // fazer
}           

