#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declara��es de classes stub.

class StubServicoAutenticacao : public IServicoAutenticacao
{
private:
    static const string INVALIDO;

public:
    bool autenticar(Email, Senha);
};

//--------------------------------------------------------------------------------------------

class StubServicoUsuario : public IServicoUsuario
{
private:
    static const string INVALIDO;

public:
    bool cadastrarUsuario(Usuario);
    bool editarUsuario(Usuario);
    bool descadastrarUsuario(Email);
};

//--------------------------------------------------------------------------------------------

class StubServicoHospedagem : public IServicoHospedagem
{
private:
    static const string INVALIDO;

public:
    bool cadastrarHospedagem(Hospedagem, Email);
    bool recuperarHospedagem(Hospedagem*);
    bool descadastrarHospedagem(Codigo, Email);
    bool editarHospedagem(Hospedagem, Email);
    bool cadastrarAvaliacao(Avaliacao, Email, Codigo);
    bool descadastrarAvaliacao(Codigo);
    bool editarAvaliacao(Avaliacao, Email);
    bool recuperarAvaliacao(Avaliacao*);
};

//--------------------------------------------------------------------------------------------

#endif // STUBS_H_INCLUDED
