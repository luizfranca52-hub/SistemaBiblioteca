#include "TabelaHash.h"
#include <iostream>
using namespace std;

TabelaHash::TabelaHash(int capacidadeInicial) {
    capacidade = capacidadeInicial;
    quantidade = 0;

    tabela = new Entrada[capacidade];
}

TabelaHash::~TabelaHash() {
    delete[] tabela;
}

int TabelaHash::hash(const std::string& chave) const { 
    int soma = 0;
    for (char c : chave) {
        soma = soma + c;
    }
    return soma % capacidade;
}

double TabelaHash::alfa() const {
    return (double) quantidade / capacidade;
}

void TabelaHash::redimensionar(int novaCapacidade) {
    Entrada* tabelaAntiga = tabela;
    int capacidadeAntiga = capacidade;
    tabela = new Entrada[novaCapacidade];
    capacidade = novaCapacidade;
    quantidade = 0;
    for (int i = 0; i < capacidadeAntiga; i++) {
        if (tabelaAntiga[i].getEstado() == OCUPADO) {
            inserir(tabelaAntiga[i].getChave());
        }
    }
    delete[] tabelaAntiga;
}

void TabelaHash::inserir(const std::string& livro) {
    if (alfa() > 0.5) {
        redimensionar(capacidade * 2);
    }
    int indice = hash(livro);
    for (int i = 0; i < capacidade; i++) {
        int posicao = (indice + i) % capacidade;
        if (tabela[posicao].getEstado() == LIVRE || tabela[posicao].getEstado() == REMOVIDO) {
            tabela[posicao].setChave(livro);
            tabela[posicao].setEstado(OCUPADO);
            quantidade++;
            return;
        }

        if (tabela[posicao].getEstado() == OCUPADO && tabela[posicao].getChave() == livro) {
            return;
        }
    }
}

void TabelaHash::remover(const std::string& livro) {
    int indice = hash(livro);

    for (int i = 0; i < capacidade; i++) {
        int posicao = (indice + i) % capacidade;
        if (tabela[posicao].getEstado() == LIVRE) {
            return;
        }

        if (tabela[posicao].getEstado() == OCUPADO && tabela[posicao].getChave() == livro) {
            tabela[posicao].setEstado(REMOVIDO);
            quantidade--;

            if (alfa() < 0.125 && capacidade > 8) {
                redimensionar(capacidade / 2);
            }
            return;
        }
    }
}

bool TabelaHash::buscar(const std::string& livro) const {
    int indice = hash(livro);

    for (int i = 0; i < capacidade; i++) {
        int posicao = (indice + i) % capacidade;
        if (tabela[posicao].getEstado() == LIVRE) {
            return false;
        }
        if (tabela[posicao].getEstado() == OCUPADO && tabela[posicao].getChave() == livro) {

            return true;
        }
    }

    return false;
}

void TabelaHash::imprimir() const{
    for (int i = 0; i < capacidade; i++) {
        if(tabela[i].getEstado() == OCUPADO){ 
            cout << tabela[i].getChave() << endl;
        }
    }
}