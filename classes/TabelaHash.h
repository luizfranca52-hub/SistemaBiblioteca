#ifndef TABELAHASH_H
#define TABELAHASH_H

#include "Entrada.h"
#include <string>

class TabelaHash {
private:
    Entrada* tabela;

    int capacidade;
    int quantidade;

    int hash(const std::string& chave) const;
    double alfa() const;

    void redimensionar(int novaCapacidade);

public:
    TabelaHash(int capacidadeInicial = 8);
    ~TabelaHash();

    void inserir(const std::string& livro);
    void remover(const std::string& livro);

    bool buscar(const std::string& livro) const;

    void imprimir() const;
};

#endif