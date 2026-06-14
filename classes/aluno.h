#ifndef ALUNO_H
#define ALUNO_H
#include <string>

class aluno : public usuario{
        protected: 
            std::string matricula;
            int limiteLivros = 3;

        public:
            int alugados;
            void exibirPainel() override;   
};


#endif