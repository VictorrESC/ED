/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "ForwardList.h"

/***************************************************
 * Implementacao das funcoes-membro da classe
 ***************************************************/

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstAtual = lst.m_head->next;
    Node *thisLast = m_head;
    while(lstAtual != nullptr) {
        thisLast->next = new Node(lstAtual->value, nullptr);
        lstAtual = lstAtual->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const {
    return m_head->next == nullptr;
}

int ForwardList::size() const {
    return m_size;
}

void ForwardList::clear() {
    while(m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

Item& ForwardList::operator[](int index) {
    int count = 0;
    Node *atual = m_head->next;
    while(count < index) {
        atual = atual->next;
        count++;
    }
    return atual->value;
}

const Item& ForwardList::operator[](int index) const {
    int count = 0;
    Node *atual = m_head->next;
    while(count < index) {
        atual = atual->next;
        count++;
    }
    return atual->value;
}

void ForwardList::insert_at(int index, const Item& val) {
    int count = 0;
    Node *atual = m_head;
    while(count < index) {
        atual = atual->next;
        count++;
    }
    Node *newNode = new Node(val, atual->next);
    atual->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index) {
    int count = 0;
    Node *atual = m_head;
    while(count < index) {
        atual = atual->next;
        count++;
    }
    Node *temp = atual->next;
    atual->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString() {
    std::string str = "[ ";
    Node *ptr = m_head->next;
    while(ptr != nullptr) {
        str += std::to_string(ptr->value) + " ";
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/***********************************************************
 * Funcoes adicionais - Parte 2
 ***********************************************************/

    // Concatena a lista atual com a lista lst.
    // A lista lst eh modificada apos essa operacao.
    // Por exemplo, seja l1 = [ 1 2 3 4 ] e l2 = [ 7 9 8 ]
    // Após fazer l1.concat(l2) você deve obter
    // l1 = [ 1 2 3 4 7 9 8] e l2 = [ ]
    // Restricao: estar proibido usar funcoes auxiliares para resolver esta questao,
    // inclusive qualquer dos operadores sobrecarregados
void ForwardList::concat(ForwardList& lst) {
    Node *atual = m_head;
    while(atual->next != nullptr) {
        atual = atual->next;
    }
    atual->next = lst.m_head->next;
    m_size += lst.m_size;
    lst.m_head->next = nullptr;
    lst.m_size = 0;
}

    // Remove da lista todas as ocorrencias do Item val.
    // Se a lista estiver vazia, esta funcao nao faz nada.
    // Restricao: Esta funcao deve ter complexidade O(n) no pior caso.
    // Restricao: estar proibido usar funcoes auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados 
void ForwardList::remove(const Item& val) {
    Node *atual = m_head;
    while(atual->next != nullptr) {
        if(atual->next->value == val) {
            Node *temp = atual->next;
            atual->next = temp->next;
            delete temp;
            m_size--;
        } else {
            atual = atual->next;
        }
    }
}

    // Devolve um ponteiro para uma copia desta lista.
    // Veja que uma copia nao eh a mesma lista, ela contem uma copia dos dados
    // Esta funcao deve ter complexidade O(n) no pior caso
    // Restricao: estar proibido usar funcoes auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
ForwardList* ForwardList::clone() {
    ForwardList *lst = new ForwardList();
    Node *atual = m_head->next;
    Node *last = lst->m_head;
    while(atual != nullptr) {
        last->next = new Node(atual->value, nullptr);
        last = last->next;
        atual = atual->next;
    }
    lst->m_size = m_size;
    return lst;
}

    // Copia os elementos do vector vec para o final da lista.
    // Esta funcao deve ter complexidade O(n) no pior caso
    // Restricao: estar proibido usar funcoes auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
void ForwardList::appendVector(const std::vector<Item>& vec) {
    Node *atual = m_head;
    while(atual->next != nullptr) {
        atual = atual->next;
    }
    for(int i = 0; i < vec.size(); i++) {
        atual->next = new Node(vec[i], nullptr);
        atual = atual->next;
        m_size++;
    }
}

    // Troca o conteudo dessa lista pelo conteudo de lst. 
    // Os tamanhos das listas podem diferir.
    // Apos a chamada para esta funcao, os elementos nesta lista
    // sao aqueles que estavam em lst antes da chamada, 
    // e os elementos de lst sao aqueles que estavam nesta lista.
void ForwardList::swap(ForwardList& lst) {
    Node *temp = m_head;
    m_head = lst.m_head;
    lst.m_head = temp;

    int temp2 = m_size;
    m_size = lst.m_size;
    lst.m_size = temp2;
}


    // Determina se a lista lst, passada por parametro, eh igual
    // a lista em questao. Duas listas sao iguais se elas tem o mesmo tamanho
    // e o valor do k-esimo elemento da primeira lista eh igual ao
    // k-esimo valor da segunda lista.
    // Restricao: estar proibido usar funcoes auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
bool ForwardList::equals(const ForwardList& lst) const {
    if(m_size != lst.m_size) {
        return false;
    }
    Node *atual = m_head->next;
    Node *lstAtual = lst.m_head->next;
    while(atual != nullptr) {
        if(atual->value != lstAtual->value) {
            return false;
        }
        atual = atual->next;
        lstAtual = lstAtual->next;
    }
    return true;
}

    // Inverte a ordem dos nos (o primeiro node passa a ser o ultimo, 
    // o segundo passa a ser o penultimo, etc.)
    // Restricao: Essa operacao faz isso sem criar novos nodes, apenas altera os ponteiros.
    // Voce pode criar ponteiros auxiliares (um numero constante deles),
    // mas nao pode alocar novos nos.
    // Repetindo: estar proibido chamar o operador new nesta questao.
    // Restricao: Tambem nao eh permitido usar funções auxiliares nesta questao
void ForwardList::reverse() {
    Node *atual = m_head->next;
    Node *prev = nullptr;
    while(atual != nullptr) {
        Node *next = atual->next;
        atual->next = prev;
        prev = atual;
        atual = next;
    }
    m_head->next = prev;
}

    // retorna o elemento na posicao 'index'
    // Se index < 0 ou index >= m_size então lance uma excecao std::range_error com a
    // mensagem de erro "index out of range". Caso contrario retorne o elemento.
    // Sera preciso incluir o cabecalho <stdexcept> para a excecao ser reconhecida
Item& ForwardList::get(int index) {
    int count = 0;
    Node *atual = m_head->next;
    while(count < index) {
        atual = atual->next;
        count++;
    }
    return atual->value;
}

    // retorna o elemento na posicao 'index'
    // Se index < 0 ou index >= m_size então lance uma excecao std::range_error com a
    // mensagem de erro "index out of range". Caso contrario retorne o elemento.
    // Sera preciso incluir o cabecalho <stdexcept> para a excecao ser reconhecida
const Item& ForwardList::get(int index) const {
    int count = 0;
    Node *atual = m_head->next;
    while(count < index) {
        atual = atual->next;
        count++;
    }
    return atual->value;
}
