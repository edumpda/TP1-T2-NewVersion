#include "controladorasapresentacao.h"
//#include <string>
//--------------------------------------------------------------------------------------------
// Implementacoes dos metodos de classes controladoras.

void CntrApresentacaoControle::executar()
{

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Acessar sistema.";
    char texto3[] = "2 - Cadastrar usuario.";
    char texto4[] = "3 - Acessar dados sobre hospedagens.";
    char texto5[] = "4 - Acessar dados sobre avaliacoes.";
    char texto6[] = "5 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de selecao de servico.

    char texto7[] = "Selecione um dos servicos : ";
    char texto8[] = "1 - Selecionar servicos de usuarios.";
    char texto9[] = "2 - Selecionar servicos relacionados a hospedagens.";
    char texto10[] = "3 - Selecionar servicos relacionados a avaliações.";
    char texto11[] = "4 - Encerrar sessao.";

    char texto12[] = "Falha na autenticacao. Digite algo para continuar."; // Mensagem a ser apresentada.

    int campo;

    bool apresentar = true;

    while (apresentar)
    {

        // Apresenta tela inicial.

        CLR_SCR; // Limpa janela.

        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cout << texto4 << endl; // Imprime nome do campo.
        cout << texto5 << endl; // Imprime nome do campo.
        cout << texto6 << endl; // Imprime nome do campo.

        campo = getch() - 48; // Leitura do campo de entrada e conversao de ASCII.

        switch (campo)
        {
        case 1:
            if (cntrApresentacaoAutenticacao->autenticar(&email))
            { // Solicita autenticacao.
                bool apresentar = true;
                while (apresentar)
                {

                    // Apresenta tela de sele��o de servi�o.

                    CLR_SCR; // Limpa janela.

                    cout << texto7 << endl;  // Imprime nome do campo.
                    cout << texto8 << endl;  // Imprime nome do campo.
                    cout << texto9 << endl;  // Imprime nome do campo.
                    cout << texto10 << endl; // Imprime nome do campo.
                    cout << texto11 << endl; // Imprime nome do campo.

                    campo = getch() - 48; // Leitura do campo de entrada e conversao de ASCII.

                    switch (campo)
                    {
                    case 1:
                        cntrApresentacaoUsuario->executar(email); // Solicita servico de usuario.
                        break;
                    case 2:
                        cntrApresentacaoHospedagem->executar(email); // Solicita servico de hospedagem.
                        break;
                    case 3:
                        cntrApresentacaoAvaliacao->executar(email); // Solicita servico de avaliacao
                        break;
                    case 4:
                        apresentar = false;
                        break;
                    }
                }
            }
            else
            {
                CLR_SCR;                 // Limpa janela.
                cout << texto12 << endl; // Imprime mensagem.
                getch();                 // Leitura de caracter digitado.
            }
            break;
        case 2:
            cntrApresentacaoUsuario->cadastrar();
            break;
        case 3:
            cntrApresentacaoHospedagem->executar();
            break;
        case 4:
            cntrApresentacaoAvaliacao->executar();
            break;
        case 5:
            apresentar = false;
            break;
        }
    }
    return;
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoAutenticacao::autenticar(Email *email)
{

    // Mensagens a serem apresentadas na tela de autentica��o.

    char texto1[] = "Digite o email  : ";
    char texto2[] = "Digite a senha: ";
    char texto3[] = "Dado em formato incorreto. Digite algo.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    Senha senha; // Instancia a classe Senha.

    while (true)
    {

        // Apresenta tela de autenticacao.

        CLR_SCR; // Limpa janela.

        cout << texto1 << " "; // Imprime nome do campo.
        cin >> campo1;         // Le valor do campo.
        cout << texto2 << " "; // Imprime nome do campo.
        cin >> campo2;         // Le valor do campo.

        try
        {
            email->setEmail(string(campo1)); // Atribui valor ao CPF.
            senha.setSenha(string(campo2));  // Atribui Valor a senha.
            break;                           // Abandona laco em caso de formatos corretos.
        }
        catch (invalid_argument &exp)
        {                           // Captura excecao devido a formato incorreto.
            CLR_SCR;                // Limpa janela.
            cout << texto3 << endl; // Informa formato incorreto.
            getch();                // Le caracter digitado.
        }
    }
    return (cntr->autenticar(*email, senha)); // Solicita servico de autenticacao.
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::executar(Email email)
{

    // Mensagens a serem apresentadas na tela de selecao de servico..

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Editar Dados do Usuário.";
    char texto3[] = "2 - Excluir Cadastro do Usuário.";
    char texto4[] = "3 - Retornar.";

    int campo; // Campo de entrada.

    bool apresentar = true; // Controle de laco.

    while (apresentar)
    {

        // Apresenta tela de selecao de servico.

        CLR_SCR;                // Limpa janela.
        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cout << texto4 << endl; // Imprime nome do campo.

        campo = getch() - 48; // Leitura do campo de entrada e conversao de ASCII.

        switch (campo)
        {
        case 1:
            editarUsuario(email);
            break;
        case 2:
            // editarDadosUsuario();
            break;
        case 3:
            apresentar = false;
            break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::cadastrar()
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Nome            :";
    char texto3[] = "Email           :";
    char texto4[] = "Senha           :";
    char texto5[] = "Dados em formato incorreto. Digite algo.";
    char texto6[] = "Sucesso no cadastramento. Digite algo.";
    char texto7[] = "Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.

    // Instancia os dominios.

    Nome nome;
    Email email;
    Senha senha;

    // Apresenta tela de cadastramento.

    CLR_SCR; // Limpa janela.

    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cin.getline(campo1, sizeof(campo1));
    cout << texto3 << endl; // Imprime nome do campo.
    cin >> campo2;          // Le valor do campo.
    cout << texto4 << endl; // Imprime nome do campo.
    cin >> campo3;          // Le valor do campo.

    try
    {
        nome.setNome(string(campo1));
        email.setEmail(string(campo2));
        senha.setSenha(string(campo3));
    }

    catch (invalid_argument &exp)
    {
        cout << texto5 << endl; // Informa formato incorreto.
        getch();                // Leitura de caracter digitado.
        return;
    }

    // Instancia e inicializa entidades.

    Usuario usuario;

    usuario.setNome(nome);
    usuario.setEmail(email);
    usuario.setSenha(senha);

    // Cadastra usuario.

    if (cntrServicoUsuario->cadastrarUsuario(usuario))
    {
        cout << texto6 << endl; // Informa sucesso.
        getch();
        return;
    }
    cout << texto7 << endl; // Informa falha.
    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::consultarDadosUsuario()
{

    // Mensagens a serem apresentadas na tela de apresenta��o de dados pessoais.

    char texto[] = "Servico consultar dados pessoais nao implementado. Digite algo."; // Mensagem a ser apresentada.
    CLR_SCR;                                                                          // Limpa janela.
    cout << texto << endl;                                                            // Imprime nome do campo.
    getch();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::editarUsuario(Email email)
{

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Nome            :";
    char texto3[] = "Senha           :";
    char texto4[] = "Dados em formato incorreto. Digite algo.";
    char texto5[] = "Sucesso na alteração. Digite algo.";
    char texto6[] = "Falha na alteração. Digite algo.";

    char campo1[80], campo2[80]; // Cria campos para entrada dos dados.

    // Instancia os dominios.

    Nome nome;
    Senha senha;

    // Apresenta tela de cadastramento.

    CLR_SCR; // Limpa janela.

    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cin >> campo1;          // Le valor do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    cin >> campo2;          // Le valor do campo.
    try
    {
        nome.setNome(string(campo1));
        senha.setSenha(string(campo2));
    }
    catch (invalid_argument &exp)
    {
        cout << texto4 << endl; // Informa formato incorreto.
        // Desabilita eco.
        getch(); // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Usuario usuario;

    usuario.setNome(nome);
    usuario.setSenha(senha);

    if (cntrServicoUsuario->editarUsuario(usuario))
    {
        cout << texto5 << endl; // Informa sucesso.

        getch();

        return;
    }

    cin >> texto6; // Informa falha.

    getch();

    return;
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoUsuario::descadastrar(Usuario usuario)
{
    char texto1[] = "Sucesso. Usuario descadastrado.";
    char texto2[] = "Falha no descadastramento.";
    CLR_SCR;

    if (cntrServicoUsuario->descadastrarUsuario(usuario))
    {
        cout << texto1 << endl; //Informa sucesso.

        getch();

        return true;
    }

    cin >> texto2; //Informa falha;

    getch();

    return false;
}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
// Controladoras Hospedagem

void CntrApresentacaoHospedagem::executar()
{

    // Mensagens a serem apresentadas na tela simplificada de hospedagem.

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Consultar hospedagens.";
    char texto3[] = "2 - Retornar.";

    int campo; // Campo de entrada.

    bool apresentar = true; // Controle de la�o.

    while (apresentar)
    {
        // Apresenta tela simplificada de hospedagem.

        CLR_SCR;                // Limpa janela.
        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.

        campo = getch() - 48; // Leitura do campo de entrada e conversao de ASCII.

        switch (campo)
        {
        case 1:
            // listarHospedagem();
            break;
        case 2:
            apresentar = false;
            break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoHospedagem::executar(Email email)
{

    // Mensagens a serem apresentadas tela completa de hospedagem.

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Cadastrar Hospedagem.";
    char texto3[] = "2 - Consultar Hospedagem.";
    char texto4[] = "3 - Editar Hospedagem.";
    char texto5[] = "4 - Excluir Hospedagem.";
    char texto6[] = "5 - Retornar.";

    int campo; // Campo de entrada.

    // Habilita eco.

    bool apresentar = true; // Controle de la�o.

    // Habilita eco.

    while (apresentar)
    {
        // Apresenta tela completa de hospedagens.

        CLR_SCR;                // Limpa janela.
        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cout << texto4 << endl; // Imprime nome do campo.
        cout << texto5 << endl; // Imprime nome do campo.
        cout << texto6 << endl; // Imprime nome do campo.

        campo = getch() - 48; // Leitura do campo de entrada e conversao de ASCII.
        switch (campo)
        {
        case 1:
            cadastrarHospedagem(email);
            break;
        case 2:
            consultarHospedagem(email);
            break;
        case 3:
            editarHospedagem(email);
            break;
        case 4:
            descadastrarHospedagem(email);
            break;
        case 5:
            apresentar = false;
            break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoHospedagem::consultarHospedagem(Email email)
{
    char texto[] = "Servico consultar conta nao implementado. Digite algo."; // Mensagem a ser apresentada.
    CLR_SCR;                                                                 // Limpa janela.
    cout << texto << endl;                                                   // Imprime nome do campo.
    getch();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoHospedagem::cadastrarHospedagem(Email email)
{
    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Codigo          :";
    char texto3[] = "Pais          :";
    char texto4[] = "Cidade            :";
    char texto5[] = "Descricao          :";
    char texto6[] = "Dados em formato incorreto. Digite algo.";
    char texto7[] = "Sucesso no cadastramento. Digite algo.";
    char texto8[] = "Falha no cadastramento. Digite algo.";

    char campo0[80], campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.

    // Instancia os dominios.
    Codigo codigo;
    Pais pais;
    Cidade cidade;
    Descricao descricao;

    // Apresenta tela de cadastramento.

    CLR_SCR; // Limpa janela.

    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cin >> campo0;          // Le valor do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    cin >> campo1;          // Le valor do campo.
    cout << texto4 << endl; // Imprime nome do campo.
    cin >> campo2;          // Le valor do campo.
    cout << texto5 << endl; // Imprime nome do campo.
    cin >> campo3;          // Le valor do campo.
    try
    {
        codigo.setCodigo(campo0);
        pais.setPais(campo1);
        cidade.setCidade(campo2);
        descricao.setDescricao(campo3);
    }
    catch (invalid_argument &exp)
    {
        cout << texto6 << endl; // Informa formato incorreto.
        // Desabilita eco.
        getch(); // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Hospedagem hospedagem;

    hospedagem.setCodigo(codigo);
    hospedagem.setPais(pais);
    hospedagem.setCidade(cidade);
    hospedagem.setDescricao(descricao);

    if (cntrServicoHospedagem->cadastrarHospedagem(hospedagem, email))
    {
        cout << texto7 << endl; // Informa sucesso.

        getch();

        return;
    }

    cout << texto8 << endl; // Informa falha.

    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoHospedagem::editarHospedagem(Email email)
{
    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Codigo da hospedagem que você quer editar          :";
    char texto3[] = "Pais          :";
    char texto4[] = "Cidade            :";
    char texto5[] = "Descricao          :";
    char texto6[] = "Dados em formato incorreto. Digite algo.";
    char texto7[] = "Sucesso no cadastramento. Digite algo.";
    char texto8[] = "Falha no cadastramento. Digite algo.";

    char campo0[80], campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.

    // Instancia os dominios.
    Codigo codigo;
    Pais pais;
    Cidade cidade;
    Descricao descricao;

    // Apresenta tela de cadastramento.

    CLR_SCR; // Limpa janela.

    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cin >> campo0;          // Le valor do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    cin >> campo1;          // Le valor do campo.
    cout << texto4 << endl; // Imprime nome do campo.
    cin >> campo2;          // Le valor do campo.
    cout << texto5 << endl; // Imprime nome do campo.
    cin >> campo3;          // Le valor do campo.
    try
    {
        codigo.setCodigo(campo0);
        pais.setPais(campo1);
        cidade.setCidade(campo2);
        descricao.setDescricao(campo3);
    }
    catch (invalid_argument &exp)
    {
        cout << texto6 << endl; // Informa formato incorreto.
        // Desabilita eco.
        getch(); // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Hospedagem hospedagem;

    hospedagem.setCodigo(codigo);
    hospedagem.setPais(pais);
    hospedagem.setCidade(cidade);
    hospedagem.setDescricao(descricao);

    if (cntrServicoHospedagem->cadastrarHospedagem(hospedagem, email))
    {
        cout << texto7 << endl; // Informa sucesso.

        getch();

        return;
    }

    cout << texto8 << endl; // Informa falha.

    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoHospedagem::descadastrarHospedagem(Email email)
{
    // Mensagens a serem apresentadas na tela de cadastramento.
    char texto1[] = "Descadastrar hospedagem: ";
    char texto2[] = "Codigo          :";
    char texto3[] = "Dado em formato incorreto. Digite algo.";
    char texto4[] = "Sucesso no descadastramento. Digite algo.";
    char texto5[] = "Falha no descadastramento. Digite algo.";

    char campo1[80];

    Codigo codigo;

    CLR_SCR;                // Limpa janela.
    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cin >> campo1;          // L� valor do campo.

    try
    {
        codigo.setCodigo(campo1);
    }
    catch (invalid_argument &exp)
    {
        cout << texto3 << endl; // Informa falha.
        // Desabilita eco.
        getch(); // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    if (cntrServicoHospedagem->descadastrarHospedagem(codigo, email) && campo1 != "")
    {
        cout << texto4 << endl; // Informa sucesso.

        getch();

        return;
    }

    cout << texto5 << endl; // Informa falha.

    getch();

    return;
}

void CntrApresentacaoHospedagem::ListarHospedagem(Email email)
{
    char texto[] = "Servico listar hospedagens nao implementado. Digite algo."; // Mensagem a ser apresentada.
    CLR_SCR;                                                                    // Limpa janela.
    cout << texto << endl;                                                      // Imprime nome do campo.
    getch();
}

//--------------------------------------------------------------------------------------------
// Controladoras de Avaliacao

void CntrApresentacaoAvaliacao::executar()
{

    // Mensagens a serem apresentadas na tela simplificada de Avaliacao.

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Consultar avaliacoes.";
    char texto3[] = "2 - Retornar.";

    int campo; // Campo de entrada.

    bool apresentar = true; // Controle de laco.

    while (apresentar)
    {
        // Apresenta tela simplificada de hospedagem.

        CLR_SCR;                // Limpa janela.
        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.

        campo = getch() - 48; // Leitura do campo de entrada e conversao de ASCII.

        switch (campo)
        {
        case 1:
            // listarAvaliacao();
            break;
        case 2:
            apresentar = false;
            break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoAvaliacao::executar(Email email)
{
    // Mensagens a serem apresentadas tela completa de avaliacoes.

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Cadastrar Avaliação.";
    char texto3[] = "2 - Consultar Avaliação.";
    char texto4[] = "3 - Editar Avaliação.";
    char texto5[] = "4 - Excluir Avaliação.";
    char texto6[] = "5 - Retornar.";

    int campo; // Campo de entrada.

    // Habilita eco.

    bool apresentar = true; // Controle de laco.

    // Habilita eco.

    while (apresentar)
    {

        // Apresenta tela completa de produtos financeiros.

        CLR_SCR;                // Limpa janela.
        cout << texto1 << endl; // Imprime nome do campo.
        cout << texto2 << endl; // Imprime nome do campo.
        cout << texto3 << endl; // Imprime nome do campo.
        cout << texto4 << endl; // Imprime nome do campo.
        cout << texto5 << endl; // Imprime nome do campo.
        cout << texto6 << endl; // Imprime nome do campo.

        campo = getch() - 48; // Leitura do campo de entrada e conversao de ASCII.

        switch (campo)
        {
        case 1:
            // cadastrarAvaliacao(email);
            break;
        case 2:
            // consultarAvaliacao(email);
            break;
        case 3:
            // editarAvaliacao(email);
            break;
        case 4:
            // descadastrarAvaliacao(email);
            break;
        case 5:
            apresentar = false;
            break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoAvaliacao::cadastrarAvaliacao(Email email)
{
    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Codigo              :";
    char texto3[] = "Nota                :";
    char texto4[] = "Descricao             :";
    char texto5[] = "Codigo da Hospedagem  :";
    char texto6[] = "Dados em formato incorreto. Digite algo.";
    char texto7[] = "Sucesso no cadastramento. Digite algo.";
    char texto8[] = "Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80]; // Cria campos para entrada dos dados.

    // Instancia os dominios.
    Codigo codigo;
    Nota nota;
    Descricao descricao;
    Codigo codigoHospedagem;

    // Apresenta tela de cadastramento.

    CLR_SCR; // Limpa janela.

    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cin >> campo1;          // Le valor do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    cin >> campo2;          // Le valor do campo.
    int icampo2 = atoi(campo2);

    cout << texto4 << endl; // Imprime nome do campo.
    cin >> campo3;          // Le valor do campo.
    cout << texto5 << endl; // Imprime nome do campo.
    cin >> campo4;          // Le valor do campo.

    try
    {
        // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
        codigo.setCodigo(campo1);
        nota.setNota(to_string(icampo2));
        descricao.setDescricao(campo3);
        codigoHospedagem.setCodigo(campo4);
    }
    catch (invalid_argument &exp)
    {
        cout << texto6 << endl; // Informa formato incorreto.
        // Desabilita eco.
        getch(); // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Avaliacao avaliacao;

    avaliacao.setCodigo(codigo);
    avaliacao.setNota(nota);
    avaliacao.setDescricao(descricao);
    // avaliacao.setIdioma(idioma);
    // sessao.setCodigo(codigoHospedagem);

    if (cntrServicoHospedagem->cadastrarAvaliacao(avaliacao, email, codigoHospedagem))
    {
        cout << texto7 << endl; // Informa sucesso.

        getch();

        return;
    }

    cout << texto8 << endl; // Informa falha.

    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoAvaliacao::consultarAvaliacao(Email email)
{
    char texto[] = "Servico consultar avaliacao nao implementado. Digite algo."; // Mensagem a ser apresentada.
    CLR_SCR;                                                                     // Limpa janela.
    cout << texto << endl;                                                       // Imprime nome do campo.
    getch();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoAvaliacao::editarAvaliacao(Email email)
{
    // Mensagens a serem apresentadas na tela de edicao.

    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Codigo da avaliacao que você quer editar          :";
    char texto3[] = "Nova nota          :";
    char texto4[] = "Nova Descricao            :";
    char texto5[] = "Codigo da Hospedagem          :";
    char texto6[] = "Dados em formato incorreto. Digite algo.";
    char texto7[] = "Sucesso no cadastramento. Digite algo.";
    char texto8[] = "Falha no cadastramento. Digite algo.";

    char campo0[80], campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.

    // Instancia os dominios.
    Codigo codigo;
    Nota nota;
    Descricao descricao;
    Codigo codigoHospedagem;

    // Apresenta tela de cadastramento.

    CLR_SCR; // Limpa janela.

    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cin >> campo0;          // Le valor do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    cin >> campo1;          // Le valor do campo.
    cout << texto4 << endl; // Imprime nome do campo.
    cin >> campo2;          // Le valor do campo.
    cout << texto5 << endl; // Imprime nome do campo.
    cin >> campo3;          // Le valor do campo.
    try
    {
        codigo.setCodigo(campo0);
        nota.setNota(campo1);
        descricao.setDescricao(campo2);
        codigoHospedagem.setCodigo(campo3);
    }
    catch (invalid_argument &exp)
    {
        cout << texto6 << endl; // Informa formato incorreto.
        // Desabilita eco.
        getch(); // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Avaliacao avaliacao;

    avaliacao.setCodigo(codigo);
    avaliacao.setNota(nota);
    avaliacao.setDescricao(descricao);

    if (cntrServicoHospedagem->cadastrarAvaliacao(avaliacao, email, codigoHospedagem))
    {
        cout << texto7 << endl; // Informa sucesso.

        getch();

        return;
    }

    cout << texto8 << endl; // Informa falha.

    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoAvaliacao::descadastrarAvaliacao(Email email)
{
    // Mensagens a serem apresentadas na tela de descadastramento.
    char texto1[] = "Descadastrar avaliacao: ";
    char texto2[] = "Codigo da avaliacao         :";
    char texto3[] = "Dado em formato incorreto. Digite algo.";
    char texto4[] = "Sucesso no descadastramento. Digite algo.";
    char texto5[] = "Falha no descadastramento. Digite algo.";

    char campo1[80];

    Codigo codigo;

    CLR_SCR;                // Limpa janela.
    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cin >> campo1;          // L valor do campo.

    try
    {
        codigo.setCodigo(campo1);
    }
    catch (invalid_argument &exp)
    {
        cout << texto3 << endl; // Informa falha.
        // Desabilita eco.
        getch(); // Leitura de caracter digitado.
        // Habilita eco.
        return;
    }

    if (cntrServicoHospedagem->descadastrarAvaliacao(codigo) && campo1 != "")
    {
        cout << texto4 << endl; // Informa sucesso.

        getch();

        return;
    }

    cout << texto5 << endl; // Informa falha.

    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoAvaliacao::listarAvaliacoes(Email email)
{
    char texto[] = "Servico listar avaliacoes nao implementado. Digite algo."; // Mensagem a ser apresentada.
    CLR_SCR;                                                                   // Limpa janela.
    cout << texto << endl;                                                     // Imprime nome do campo.
    getch();
}
