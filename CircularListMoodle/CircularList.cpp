#include <sstream>
#include <string>
#include "Node.h" 
#include "CircularList.h" 

void CircularList::push_back(const Item& val) { 
    if (m_head == nullptr) {
        Node* aux = new Node(val, nullptr);
        m_head = aux;
        m_head->next = m_head;
    } else {
        Node* aux = m_head;
        while (aux->next != m_head){
            aux = aux->next;
        }
        Node* novo = new Node(val, m_head);
        aux->next = novo;
    }
    m_size++;
}

void CircularList::pop_back() {
    if (m_head == nullptr) {
        return;
    } else if (m_head->next == m_head) {
        delete m_head;
        m_head = nullptr;
    } else {
        Node* aux = m_head;
        while (aux->next->next != m_head) {
            aux = aux->next;
        }
        delete aux->next;
        aux->next = m_head;
    }
    m_size--;
}

std::string CircularList::toString() const {
    std::stringstream ss;
    if (m_head == nullptr) {
        return "";
    } else {
        Node* aux = m_head;
        while (aux->next != m_head) {
            ss << aux->value << " ";
            aux = aux->next;
        }
        ss << aux->value;
    }
    return ss.str();
}

Item& CircularList::operator[](int index) {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("Indice invalido");
    } else {
        Node* aux = m_head;
        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }
        return aux->value;
    }
}

const Item& CircularList::operator[](int index) const {
    if(index < 0 || index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    Node *aux = m_head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->value;
}

void CircularList::clear() {
    if (m_head == nullptr) {
        return;
    } else {
        Node* aux = m_head;
        while (aux->next != m_head) {
            Node* aux2 = aux;
            aux = aux->next;
            delete aux2;
        }
        delete aux;
        m_head = nullptr;
    }
    m_size = 0;
}

void clearRecursiva(Node *nodeAtual, Node* head){
    if (nodeAtual->next == head) {
        delete nodeAtual;
    }
    clearRecursiva(nodeAtual->next, head);
    delete nodeAtual;
}

void CircularList::clear_recursive(){
    clearRecursiva(m_head, m_head);
}

CircularList::~CircularList() {
    clear();
}

void CircularList::insert(int index, const Item& value){
    if (index < 0 || index > m_size) {
        throw std::out_of_range("Indice invalido");
    } else if (index == 0) {
        Node* novo = new Node(value, m_head);
        Node* aux = m_head;
        while (aux->next != m_head) {
            aux = aux->next;
        }
        aux->next = novo;
        m_head = novo;
    } else {
        Node* aux = m_head;
        for (int i = 0; i < index - 1; i++) {
            aux = aux->next;
        }
        Node* novo = new Node(value, aux->next);
        aux->next = novo;
    }
    m_size++;
}

CircularList::CircularList(const CircularList& other) {
    if (other.m_head == nullptr) {
        m_head = nullptr;
    } else {
        Node* aux = other.m_head;
        while (aux->next != other.m_head) {
            push_back(aux->value);
            aux = aux->next;
        }
        push_back(aux->value);
    }
    m_size = other.m_size;
}

void CircularList::remove(const Item& value) {
    if (m_head == nullptr) {
        return;
    }
    if (m_head->next == m_head) {
        if (m_head->value == value) {
            delete m_head;
            m_head = nullptr;
            m_size--;
        }
    } else {
        Node *aux = m_head;
        if (aux->value == value){
            while (aux->next != m_head) {
                aux = aux->next;
            }
            m_head = m_head->next;
            delete aux->next;
            aux->next = m_head;
            m_size--;
        }
        else{
            while (aux->next->value != value && aux->next != m_head) {
                aux = aux->next;
            }
            Node *temp = aux->next;
            aux->next = temp->next;
            delete temp;
            m_size--;
        }
    }
}  