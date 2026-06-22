#include "Entrada.h"

Entrada::Entrada() {
    chave = "";
    estado = LIVRE;
}

void Entrada::setChave(const std::string& chave) {
    this->chave = chave;
}

std::string Entrada::getChave() const {
    return chave;
}

void Entrada::setEstado(Estado estado) {
    this->estado = estado;
}

Estado Entrada::getEstado() const {
    return estado;
}