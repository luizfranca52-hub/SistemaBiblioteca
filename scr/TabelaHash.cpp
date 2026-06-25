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
            inserir(tabelaAntiga[i].getLivro());
        }
    }
    delete[] tabelaAntiga;
}

void TabelaHash::inserir(const Livro& livro) {
    if (alfa() > 0.5) {
        redimensionar(capacidade * 2);
    }
    int indice = hash(livro.getTitulo());
    for (int i = 0; i < capacidade; i++) {
        int posicao = (indice + i) % capacidade;
        if (tabela[posicao].getEstado() == LIVRE || tabela[posicao].getEstado() == REMOVIDO) {
            tabela[posicao].setChave(livro.getTitulo());
            tabela[posicao].setLivro(livro);
            tabela[posicao].setEstado(OCUPADO);
            quantidade++;
            return;
        }

        if (tabela[posicao].getEstado() == OCUPADO && tabela[posicao].getChave() == livro.getTitulo()) {
            tabela[posicao].setLivro(livro); 
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

Livro* TabelaHash::buscar(const std::string& livro) const {
    int indice = hash(livro);

    for (int i = 0; i < capacidade; i++) {
        int posicao = (indice + i) % capacidade;
        if (tabela[posicao].getEstado() == LIVRE) {
            return nullptr;
        }
        if (tabela[posicao].getEstado() == OCUPADO && tabela[posicao].getChave() == livro) {
            return &(const_cast<Entrada*>(tabela)[posicao].getLivro());
        }
    }
    return nullptr;
}

void TabelaHash::imprimir() const {
    for (int i = 0; i < capacidade; i++) {
        if(tabela[i].getEstado() == OCUPADO){ 
            Livro l = tabela[i].getLivro();
            cout << "Titulo: " << l.getTitulo() << " | Autor: " << l.getAutor() << " | Status: " << (l.isDisponivel() ? "Disponivel" : "Emprestado") << endl;
        }
    }
}