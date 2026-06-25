#ifndef ENTRADA_H
#define ENTRADA_H

#include "Livro.h"

enum Estado { LIVRE, OCUPADO, REMOVIDO };

class Entrada {
private:
    std::string chave;
    Livro livro;
    Estado estado;

public:
    Entrada();
    std::string getChave() const;
    void setChave(const std::string& c);
    Livro& getLivro(); 
    void setLivro(const Livro& l);
    Estado getEstado() const;
    void setEstado(Estado e);
};

#endif