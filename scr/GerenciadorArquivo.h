#ifndef GERENCIADORARQUIVO_H
#define GERENCIADORARQUIVO_H

#include "TabelaHash.h"
#include <string>

class GerenciadorArquivo {
private:
    std::string nomeArquivo;

public:
    GerenciadorArquivo(std::string arquivo = "livros.txt");

    // Preenche a tabela hash com o arquivo TXT
    void carregarArquivoParaHash(TabelaHash& tabela);

    // Preenche o arquivo de texto com a tabela hash
    void salvarHashNoArquivo(const TabelaHash& tabela);
};

#endif