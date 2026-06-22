#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <string>
#include "usuario.h"

class administrador : public usuario{
    private:
        std::string siape;
        std::string setor;
        int nivelAcesso;

    public:
        void exibirPainel() override;
};

#endif