#include "GerenciadorArquivo.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

GerenciadorArquivo::GerenciadorArquivo(string arquivo) {
    nomeArquivo = arquivo;
}

void GerenciadorArquivo::carregarArquivoParaHash(TabelaHash& tabela) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        return; 
    }

    string linha;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;

        stringstream ss(linha);
        string titulo, autor, dispStr;

        getline(ss, titulo, ';');
        getline(ss, autor, ';');
        getline(ss, dispStr, ';');

        bool disponivel = (dispStr == "1");
        Livro livroCarregado(titulo, autor, disponivel);
        tabela.inserir(livroCarregado);
    }
    arquivo.close();
}
void GerenciadorArquivo::salvarHashNoArquivo(const TabelaHash& tabela) {
    ofstream arquivo(nomeArquivo, ios::trunc); 
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para gravacao!" << endl;
        return;
    }

    Entrada* entradas = tabela.getTabela();
    int cap = tabela.getCapacidade();

    for (int i = 0; i < cap; i++) {
        if (entradas[i].getEstado() == OCUPADO) {
            Livro l = entradas[i].getLivro(); //Titulo;Autor;Disponibilidade
            arquivo << l.getTitulo() << ";"
                    << l.getAutor() << ";"
                    << (l.isDisponivel() ? "1" : "0") << "\n";
        }
    }
    arquivo.close();
}