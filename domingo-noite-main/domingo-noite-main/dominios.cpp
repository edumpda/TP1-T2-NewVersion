#include <string>
#include "dominios.h"
#include <cstring>
#include <cctype>
#include <utility>
// --------------------------------------------------------------------------
// Implementa��es de m�todos de classe dom�nio.
bool checkLuhn(const string& cardNo)
{
    int nDigits = cardNo.length();

    int nSum = 0, isSecond = false;
    for (int i = nDigits - 1; i >= 0; i--) {

        int d = cardNo[i] - '0';

        if (isSecond == true)
            d = d * 2;

        // We add two digits to handle
        // cases that make two digits after
        // doubling
        nSum += d / 10;
        nSum += d % 10;

        isSecond = !isSecond;
    }
    return (nSum % 10 == 0);
}
//contar numero de espacos
void space(string& str)
{
    int count = 0;
    int length = str.length();
    for (int i = 0; i < length; i++) {
        int c = str[i];
        if (isspace(c))
            if (count > 1)
            {
                throw invalid_argument("Argumento invalido.");
            }
            else
            {
                count++;
            }
        else{
            count = 0;
        }
    }
}
void password(string& str)
{
    int count_letras = 0;
    int count_caracteres = 0;
    int count_num = 0;


    int length = str.length();
    for (int i = 0; i < length; i++) {
        int c = str[i];
        if (isdigit(c))
            count_num++;
        if (isalpha(c))
            count_letras++;
        if(ispunct(c))
            count_caracteres++;

    }
    if (count_caracteres == 0 || count_letras == 0|| count_num == 0)
        throw invalid_argument("Argumento invalido.");
}



//verificar email
//=============================
bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}

// Function to check the character
// is an digit or not
bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}

// Function to check email id is
// valid or not
bool is_valid(string email)
{
    // Check the first character
    // is an alphabet or not
    if (!isChar(email[0])) {

        // If it's not an alphabet
        // email id is not valid
        return 0;
    }
    // Variable to store position
    // of At and Dot
    int At = -1, Dot = -1;

    // Traverse over the email id
    // string to find position of
    // Dot and At
    for (int i = 0;
         i < email.length(); i++) {

        // If the character is '@'
        if (email[i] == '@') {

            At = i;
        }

            // If character is '.'
        else if (email[i] == '.') {

            Dot = i;
        }
    }

    // If At or Dot is not present
    if (At == -1 || Dot == -1)
        return 0;

    // If Dot is present before At
    if (At > Dot)
        return 0;

    // If Dot is present at the end
    return !(Dot >= (email.length() - 1));
}
//=============================


Nome::Nome() = default;

Nome::Nome(string nome)
{
    this->nome = std::move(nome);
}
void Nome::validar( string nome ){
    if(nome.length() > 30)
        throw invalid_argument("Argumento invalido.");
    string str = nome;
    space(str);
    if (islower(nome[0]))
        throw invalid_argument("Argumento invalido.");
}

void Nome::setNome(string nome){
    validar(nome);
    this->nome = nome;
}

//==========================================================================//
//==========================================================================//
//==========================================================================//

Email::Email() = default;

Email::Email(string email)
{
    this->email = std::move(email);
}
void Email::validar( string email ){

    // Function Call
    bool ans = is_valid(email);

    // Print the result
    if (ans == 0)
        throw invalid_argument("Argumento invalido.");
}

void Email::setEmail( string email){
    validar(email);
    this->email = email;
}
//==========================================================================//
//==========================================================================//
//==========================================================================//

Senha::Senha() = default;

Senha::Senha(string senha)
{
    this->senha = std::move(senha);
}
void Senha::validar( string senha ){

    if (senha.length() > 6)
        throw invalid_argument("Argumento invalido.");
    string str = senha;
    password(str);
}

void Senha::setSenha( string senha){
    validar(senha);
    this->senha = senha;
}
//==========================================================================//
//==========================================================================//
//==========================================================================//

Aniversario::Aniversario() = default;

Aniversario::Aniversario(string aniversario)
{
    this->aniversario = std::move(aniversario);
}
void Aniversario::validar( string aniversario ){

    if (aniversario == "43/193")
        throw invalid_argument("Argumento invalido.");
}

void Aniversario::setAniversario( string aniversario){
    validar(aniversario);
    this->aniversario = aniversario;
}
//==========================================================================//
//==========================================================================//
//==========================================================================//

Idioma::Idioma() = default;

Idioma::Idioma(string idioma)
{
    this->idioma = std::move(idioma);
}
void Idioma::validar( string idioma ){
    if (idioma != "Ingles"&&idioma != "Chines Mandarim"&&idioma != "Hindi"&&idioma != "Espanhol"&&idioma != "Frances"&&
        idioma != "Arabe"&&idioma != "Bengali"&&idioma != "Russo"&&idioma != "Portugues"&&idioma != "Indonesio")
        throw invalid_argument("Argumento invalido.");
}

void Idioma::setIdioma( string idioma){
    validar(idioma);
    this->idioma = idioma;
}
//==========================================================================//
//==========================================================================//
//==========================================================================//

Descricao::Descricao() = default;

Descricao::Descricao(string desccricao)
{
    this->descricao = std::move(desccricao);
}
void Descricao::validar( string descricao ){
    if(descricao.length() > 40)
        throw invalid_argument("Argumento invalido.");
    string str = descricao;
    space(str);
}

void Descricao::setDescricao( string descricao){
    validar(descricao);
    this->descricao = descricao;
}
//==========================================================================//
//==========================================================================//
//==========================================================================//

Codigo::Codigo() = default;

Codigo::Codigo(string codigo)
{
    this->codigo = std::move(codigo);
}
void Codigo::validar( string codigo ){
    if (codigo.length() != 11)
        throw invalid_argument("Argumento invalido.");
    if (checkLuhn(codigo) == 0)
        throw invalid_argument("Argumento invalido.");
}

void Codigo::setCodigo( string codigo){
    validar(codigo);
    this->codigo = codigo;
}
//==========================================================================//
//==========================================================================//
//==========================================================================//

Pais::Pais() = default;

Pais::Pais(string pais)
{
    this->pais = std::move(pais);
}
void Pais::validar(string pais ){
    if (pais != "Estados Unidos"&&pais != "Brazil"&&pais != "China"&&pais != "Coreia do Sul"&&pais != "Emirados"&&
        pais != "Franca"&&pais != "India"&&pais != "Japao"&&pais != "Malasia"&&pais != "Reino Unido"&&
        pais != "Tailandia"&&pais != "Turquia")
        throw invalid_argument("Argumento invalido.");
}

void Pais::setPais( string pais){
    validar(pais);
    this->pais = pais;
}
//==========================================================================//
//==========================================================================//
//==========================================================================//

Cidade::Cidade() = default;

Cidade::Cidade(string cidade)
{
    this->cidade = std::move(cidade);
}
void Cidade::validar(string cidade ){
    if (cidade != "Antalya"&&cidade != "Bangkok"&&cidade != "Delhi"&&cidade != "Dubai"&&cidade != "Hong Kong"&&cidade != "Londres"&&cidade != "Macau"&&cidade != "Mumbai"&&cidade != "Paris"&&
        cidade != "Rio de Janeiro"&&cidade != "Sao Paulo"&&cidade != "Seul"&&cidade != "istambul"&&cidade != "Kuala lampur"&&cidade != "Nova York"&&cidade != "Osaka"&&cidade != "Phuket"&&
        cidade != "Shenzen"&&cidade != "Toquio")
        throw invalid_argument("Argumento invalido.");
}


void Cidade::setCidade( string cidade){
    validar(cidade);
    this->cidade = cidade;
}
//==========================================================================//
//==========================================================================//
//==========================================================================//

Nota::Nota() = default;

Nota::Nota(string nota)
{
    this->nota = nota;
}
void Nota::validar(string nota ){
    if (nota != "1" && nota != "2"&& nota != "3"&& nota != "4"&& nota != "5"&& nota != "6"&& nota != "7"&& nota != "8"&& nota != "9"&& nota != "10")
        throw invalid_argument("Argumento invalido.");
}

void Nota::setNota(string nota){
    validar(nota);
    this->nota = nota;
}


// --------------------------------------------------------------------------
// Implementa��es de m�todos de classe dom�nio.
