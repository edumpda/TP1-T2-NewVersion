#include "containers.h"

ContainerUsuario* ContainerUsuario::instancia = nullptr;

//------------------------------------------------------------------------------------
// Implementações de métodos de classe container.

ContainerUsuario* ContainerUsuario::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerUsuario();
    return instancia;
}

bool ContainerUsuario::cadastrar(Usuario usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail().getEmail() == usuario.getEmail().getEmail()){
            return false;
        }
    }
    container.push_back(usuario);                               // Incluir objeto.
    return true;
}


bool ContainerUsuario::descadastrar(Usuario usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail().getEmail() == usuario.getEmail().getEmail()){
            container.erase(elemento);                          // Remover objeto localizado.
            return true;
        }
    }
    return false;
}

bool ContainerUsuario::editar(Usuario usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail().getEmail() == usuario.getEmail().getEmail()){
            *elemento = usuario;
            return true;
        }
    }
    return false;
}


ContainerHospedagem* ContainerHospedagem::instancia = nullptr;

//------------------------------------------------------------------------------------
// Implementações de métodos de classe container.

ContainerHospedagem* ContainerHospedagem::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerHospedagem();
    return instancia;
}

bool ContainerHospedagem::cadastrar(Hospedagem hospedagem){
    for(list<Hospedagem>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getCodigo() == hospedagem.getCodigo().getCodigo()){
            return false;
        }
    }
    container.push_back(hospedagem);                               // Incluir objeto.
    return true;
}


bool ContainerHospedagem::descadastrar(Hospedagem hospedagem){
    for(list<Hospedagem>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getCodigo() == hospedagem.getCodigo().getCodigo()){
            container.erase(elemento);                          // Remover objeto localizado.
            return true;
        }
    }
    return false;
}

bool ContainerHospedagem::editar(Hospedagem hospedagem){
    for(list<Hospedagem>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getCodigo() == hospedagem.getCodigo().getCodigo()){
            *elemento = hospedagem;
            return true;
        }
    }
    return false;
}