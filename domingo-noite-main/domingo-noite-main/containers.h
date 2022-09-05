#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>

using namespace std;

//----------------------------------------------------------------------------------------
// Declaração de classe container.
//
// Declaração adota padrão de projeto Singleton.

class ContainerUsuario{
    private:
        list<Usuario> container;                        // Lista de usuários.
        static ContainerUsuario *instancia;             // Ponteiro para instância da classe.
        ContainerUsuario(){};                           // Construtor.
    public:
        static  ContainerUsuario* getInstancia();       // Método para instanciar classe.
        bool cadastrar(Usuario);
        bool descadastrar(Usuario);                         // Métodos responsáveis por prestar serviços.
        bool editar(Usuario);
};

class ContainerHospedagem{
    private:
        list<Hospedagem> container;                        // Lista de usuários.
        static ContainerHospedagem *instancia;             // Ponteiro para instância da classe.
        ContainerHospedagem(){};                           // Construtor.
    public:
        static  ContainerHospedagem* getInstancia();       // Método para instanciar classe.
        bool cadastrar(Hospedagem);
        bool descadastrar(Hospedagem);                          // Métodos responsáveis por prestar serviços.
        bool editar(Hospedagem);
};

#endif // CONTROLADORAS_H_INCLUDED
