#include "TabelaHash.h"
#include <iostream>
using namespace std;

int main() {

    TabelaHash tabela;
    tabela.inserir("1980");
    tabela.inserir("Harry Potter");
    tabela.inserir("Os três porquinhos");
    tabela.inserir("Turma da Monica");

    if(tabela.buscar("Harry Potter")){
        cout << "tem harry potter" << endl;;
    } else {
        cout << "Não tem hp" << endl;
    }

    if( 
    tabela.buscar("Os 7 maridos de Evelyn Hugo")){
        cout << "tem o7meh" << endl;
    }else{
        cout << "Nao tem o7meh" << endl;
    }

    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    tabela.imprimir();
    cout << endl << "Pós remoção:" << endl;
    tabela.remover("Os três porquinhos");
    tabela.imprimir();
    
    


    return 0;
}