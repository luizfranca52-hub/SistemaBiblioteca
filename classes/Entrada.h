#ifndef ENTRADA_H
#define ENTRADA_H

#include <string>

enum Estado {
    LIVRE,
    OCUPADO,
    REMOVIDO
};

class Entrada {
private:
    std::string chave;
    Estado estado;

public:
    Entrada();

    void setChave(const std::string& chave);
    std::string getChave() const;

    void setEstado(Estado estado);
    Estado getEstado() const;
};

#endif