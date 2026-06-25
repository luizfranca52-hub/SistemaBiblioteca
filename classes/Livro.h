#ifndef LIVRO_H
#define LIVRO_H

#include <string>

class Livro {
private:
    std::string titulo;
    std::string autor;
    bool disponivel;

public:
    Livro();
    Livro(std::string titulo, std::string autor, bool disponivel = true);

    std::string getTitulo() const;
    std::string getAutor() const;
    bool isDisponivel() const;
    
    void setDisponivel(bool status);
};

#endif