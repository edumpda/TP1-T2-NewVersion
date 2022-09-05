#include "stubs.h"

//--------------------------------------------------------------------------------------------
// Valores usados como gatilhos de erros.

const string StubServicoAutenticacao::INVALIDO = "12344";
const string StubServicoUsuario::INVALIDO = "12344";
const string StubServicoHospedagem::INVALIDO = "12345";

//--------------------------------------------------------------------------------------------
// Implementa��es dos m�todos de classes stub.

inline bool StubServicoAutenticacao::autenticar(Email email, Senha senha){
  if (email.getEmail().compare(INVALIDO) == 0)
    return false;
  return true;
}

inline bool StubServicoUsuario::cadastrarUsuario(Usuario usuario)
{
  if (usuario.getEmail().getEmail().compare(INVALIDO) == 0)
    return false;
  return true;
}

inline bool StubServicoUsuario::editarUsuario(Usuario usuario)
{
  if (usuario.getEmail().getEmail().compare(INVALIDO) == 0)
    return false;
  return true;
}

inline bool StubServicoUsuario::descadastrarUsuario(Email email)
{
  if (email.getEmail().compare(INVALIDO) == 0)
    return false;
  return true;
}

//############################################################################################

inline bool StubServicoHospedagem::cadastrarHospedagem(Hospedagem hospedagem, Email Email) {
  if (hospedagem.getCodigo().getCodigo().compare(INVALIDO) == 0)
    return false;
  return true;
}

inline bool StubServicoHospedagem::recuperarHospedagem(Hospedagem *hospedagem)
{
  if (hospedagem->getCodigo().getCodigo().compare(INVALIDO) == 0)
  {
    return false;
  }
}

inline bool StubServicoHospedagem::descadastrarHospedagem(Codigo codigo, Email email)
{
  if (codigo.getCodigo().compare(INVALIDO) == 0)
    return false;
  return true;
}

inline bool StubServicoHospedagem::editarHospedagem(Hospedagem hospedagem, Email email)
{
  if (hospedagem.getCodigo().getCodigo().compare(INVALIDO) == 0)
    return false;
  return true;
}

//############################################################################################
inline bool StubServicoHospedagem::cadastrarAvaliacao(Avaliacao avaliacao, Email email, Codigo codigo)
{
  if (avaliacao.getCodigo().getCodigo().compare(INVALIDO) == 0)
    return false;
  return true;
}
inline bool StubServicoHospedagem::recuperarAvaliacao(Avaliacao *avaliacao)
{
  if (avaliacao->getCodigo().getCodigo().compare(INVALIDO) == 0)
  {
    return false;
  }
}

inline bool StubServicoHospedagem::descadastrarAvaliacao(Codigo codigo)
{
  if (codigo.getCodigo().compare(INVALIDO) == 0)
    return false;
  return true;
}

inline bool StubServicoHospedagem::editarAvaliacao(Avaliacao avaliacao, Email)
{
  if (avaliacao.getCodigo().getCodigo().compare(INVALIDO) == 0)
    return false;

  return true;
}
