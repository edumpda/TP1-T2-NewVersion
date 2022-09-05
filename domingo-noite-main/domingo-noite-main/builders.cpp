#include "builders.h"

CntrApresentacaoControle *BuilderSistema::construir()
{

    // Instanciar controladoras da camada de apresentação.

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoUsuario = new CntrApresentacaoUsuario();
    cntrApresentacaoHospedagem = new CntrApresentacaoHospedagem();
    cntrApresentacaoAvaliacao = new CntrApresentacaoAvaliacao();

    // Instanciar controladoras da camada de serviço.

    cntrServicoUsuario = new CntrServicoUsuario();

    // --------------------------------------------------------------------------------------------
    // Substituir instancia de stub de CntrServicoAutenticacao por instância da controladora.
    // --------------------------------------------------------------------------------------------

    cntrServicoAutenticacao = new StubServicoAutenticacao();

    // ---------------------------------------------------------------------------------------------
    // Substituir instancia de stub de CntrServicoProdutosFinanceiros por instância da controladora.
    // ---------------------------------------------------------------------------------------------

    cntrServicoHospedagem = new StubServicoHospedagem();

    // Interligar as controladoras.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoUsuario(cntrApresentacaoUsuario);
    cntrApresentacaoControle->setCntrApresentacaoHospedagem(cntrApresentacaoHospedagem);
    cntrApresentacaoControle->setCntrApresentacaoAvaliacao(cntrApresentacaoAvaliacao);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);
    cntrApresentacaoUsuario->setCntrServicoUsuario(cntrServicoUsuario);
    cntrApresentacaoHospedagem->setCntrServicoHospedagem(cntrServicoHospedagem);
    cntrApresentacaoAvaliacao->setCntrServicoHospedagem(cntrServicoHospedagem);

    // Retornar referência para instância de CntrApresentacaoControle.

    return cntrApresentacaoControle;
}

BuilderSistema::~BuilderSistema()
{
    delete cntrApresentacaoControle;
    delete cntrApresentacaoAutenticacao;
    delete cntrApresentacaoUsuario;
    delete cntrApresentacaoHospedagem;
    delete cntrServicoAutenticacao;
    delete cntrServicoUsuario;
    delete cntrServicoHospedagem;
}
