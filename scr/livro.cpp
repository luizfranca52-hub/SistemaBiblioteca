#include "Livro.h"

Livro::Livro() : titulo(""), autor(""), disponivel(true) {}

Livro::Livro(std::string titulo, std::string autor, bool disponivel) {
    this->titulo = titulo;
    this->autor = autor;
    this->disponivel = disponivel;
}

std::string Livro::getTitulo() const { return titulo; }
std::string Livro::getAutor() const { return autor; }
bool Livro::isDisponivel() const { return disponivel; }
void Livro::setDisponivel(bool status) { disponivel = status; }