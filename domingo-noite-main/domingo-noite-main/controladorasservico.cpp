#include "controladorasservico.h"

//--------------------------------------------------------------------------------------------
// Implementa��es de m�todos de classes controladoras da camada de servi�o.

bool CntrServicoAutenticacao::autenticar(Email email, Senha senha){

    // ---------------------------------------------------------------------------------------
    // Instanciar container de usu�rios.
    // ---------------------------------------------------------------------------------------

    // ---------------------------------------------------------------------------------------
    // Recuperar e comparar senha de usu�rio.
    // ---------------------------------------------------------------------------------------

    // ---------------------------------------------------------------------------------------
    // Retornar resultado.
    // ---------------------------------------------------------------------------------------

    return true;
}

//--------------------------------------------------------------------------------------------

bool CntrServicoUsuario::cadastrarUsuario(Usuario usuario){

    // Instancia container de usu�rios.

    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    // Solicitar cadastramento de usu�rio e retornar resultado da solicita��o de servi�o.

    return container->cadastrar(usuario);
}

bool CntrServicoUsuario::editarUsuario(Usuario usuario){

    // Instancia container de usu�rios.

    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    // Solicitar cadastramento de usu�rio e retornar resultado da solicita��o de servi�o.

    return container->editar(usuario);
}

bool CntrServicoUsuario::descadastrarUsuario(Usuario usuario){

    // Instancia container de usu�rios.

    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    // Solicitar cadastramento de usu�rio e retornar resultado da solicita��o de servi�o.

    return container->descadastrar(usuario);
}
//--------------------------------------------------------------------------------------------



