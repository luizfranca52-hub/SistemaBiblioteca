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

    void inserir(const Livro& livro);
    void remover(const std::string& livro);
    Livro* buscar(const std::string& livro) const;

    void imprimir() const;

    // vms usar no nas operações do arquivo de texto
    int getCapacidade() const { return capacidade; }
    Entrada* getTabela() const { return tabela; }
};

#endif