#include "Administrador.h"

#include <iostream>
#include <fstream>
#include <sstream>


void Administrador::carregarArquivo(std::string livros.txt)
{

    std::ifstream arquivo(livros.txt);
    if(!arquivo.is_open())
    {
        std::cout << "Arquivo não encontrado.\n";
        return;
    }

    std::string linha;

    while(getline(arquivo, linha)){
        std::stringstream ss(linha);

        std::string idString;
        std::string titulo;
        std::string autor;
        std::string anoString;
        getline(ss, idString, ';');
        getline(ss, titulo, ';');
        getline(ss, autor, ';');
        getline(ss, anoString, ';');

        int id = stoi(idString);
        int ano = stoi(anoString);

        Livro livro(
            id,
            titulo,
            autor,
            ano
        );

        tabela.inserir(
            id,
            livro
        );

    }
    arquivo.close();

}

void Administrador::salvarArquivo(std::string nomeArquivo){

    std::ofstream arquivo(nomeArquivo);
    if(!arquivo.is_open()){
        std::cout << "Erro ao abrir arquivo.\n";
        return;
    }



    /*
        Aqui precisamos percorrer a tabela hash.

        Exemplo:

        tabela.percorrer(
            [&](int chave, Livro livro)
            {
                arquivo << ...
            }
        );

    */


    tabela.percorrer(
        [&](int chave, Livro livro)
        {

            arquivo
            << livro.getId()
            << ";"
            << livro.getTitulo()
            << ";"
            << livro.getAutor()
            << ";"
            << livro.getAno()
            << "\n";

        }
    );



    arquivo.close();

}

void Administrador::inserirLivro(Livro livro){
    int id = livro.getId();
    tabela.inserir(
        id,
        livro
    );
}

bool Administrador::removerLivro(int id){
    return tabela.remover(id);
}

std::optional<Livro> Administrador::buscarLivro(int id){
    return tabela.obter(id);
}

void Administrador::listarLivros()
{

    tabela.percorrer(
        [](int chave, Livro livro)
        {

            std::cout
            << "ID: "
            << livro.getId()
            << "\n";


            std::cout
            << "Titulo: "
            << livro.getTitulo()
            << "\n";


            std::cout
            << "Autor: "
            << livro.getAutor()
            << "\n";


            std::cout
            << "Ano: "
            << livro.getAno()
            << "\n";


            std::cout
            << "-----------------\n";

        }
    );

}