#ifndef BUILDERS_H_INCLUDED
#define BUILDERS_H_INCLUDED

#include "interfaces.h"
#include "controladorasapresentacao.h"
#include "controladorasservico.h"
#include "stubs.h"
#include "stubs.cpp"

class BuilderSistema {
    private:
        CntrApresentacaoControle *cntrApresentacaoControle;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoUsuario *cntrApresentacaoUsuario;
        IApresentacaoHospedagem *cntrApresentacaoHospedagem;
        IApresentacaoAvaliacao *cntrApresentacaoAvaliacao;
        IServicoUsuario *cntrServicoUsuario;
        IServicoAutenticacao *cntrServicoAutenticacao;
        IServicoHospedagem *cntrServicoHospedagem;
    public:
        CntrApresentacaoControle* construir();
        ~BuilderSistema();
};

#endif // BUILDERS_H_INCLUDED
