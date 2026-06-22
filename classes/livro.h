#ifndef LIVRO_H
#define LIVRO_H
#include <string>

class livro{
    private: 
    int chave;
    std::string título;
    std::string autor;
    bool disponibilidade;

    public: 
    livro(std::string _nome, std::string _autor); 
    ~livro();


    //sobrecarga de operadores aqui?
};


#endif