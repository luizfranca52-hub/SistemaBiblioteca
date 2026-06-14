#ifndef USUARIO_H
#define USUARIO_H
#include <string>
    
class usuario{
    protected: 
    int id;
    std::string nome;
    std::string cpf;

    public: 
    virtual void exibirPainel() = 0; //A gente bota algum comportamento para a classe base?
};


#endif