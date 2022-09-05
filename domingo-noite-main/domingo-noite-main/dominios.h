#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
//=========================================================//
//=========================================================//
//=========================================================//

class Nome {
private:
        string nome;
        static void validar(string);
        const static unsigned int TAMANHO_MIN = 5;
        const static unsigned int TAMANHO_MAX = 20;
public:
        Nome();

        Nome(string);

        void setNome(string);

        string getNome() const
        {
            return nome;
        }
};

//=========================================================//
//=========================================================//
//=========================================================//

class Email {
private:
    string email;
    static void validar(string);
public:
    Email();
    Email(string);

    void setEmail(string);

    string getEmail() const
    {
        return email;
    }
};

//=========================================================//
//=========================================================//
//=========================================================//

class Senha {
private:
    string senha;
    static void validar(string);
public:
    Senha();
    Senha(string);

    void setSenha(string);

    string getSenha() const
    {
        return senha;
    }
};

//=========================================================//
//=========================================================//
//=========================================================//

class Idioma {
private:
    string idioma;
    static void validar(string);
public:
    Idioma();
    Idioma(string);

    void setIdioma(string);

    string getIdioma() const
    {
        return idioma;
    }
};

//=========================================================//
//=========================================================//
//=========================================================//

class Aniversario {
private:
    string aniversario;
    static void validar(string);
public:
    Aniversario();
    Aniversario(string);

    void setAniversario(string);

    string getAniversario() const
    {
        return aniversario;
    }
};

//=========================================================//
//=========================================================//
//=========================================================//

class Descricao {
private:
    string descricao;
    static void validar(string);
public:
    Descricao();
    Descricao(string);

    void setDescricao(string);

    string getDescricao() const
    {
        return descricao;
    }
};

//=========================================================//
//=========================================================//
//=========================================================//

class Codigo {
private:
    string codigo;
    const static unsigned int TAMANHO_MAX = 7;
    void validar(string);
public:
    Codigo(); // default
    Codigo(string);

    void setCodigo(string);

    string getCodigo() const
    {
        return codigo;
    }
};

//=========================================================//
//=========================================================//
//=========================================================//
class Pais {
private:
    string pais;
    void validar(string);
public:
    Pais(); // default
    Pais(string);

    void setPais(string);

    string getPais() const
    {
        return pais;
    }
};

//=========================================================//
//=========================================================//
//=========================================================//

class Cidade {
private:
    string cidade;
    void validar(string);
public:
    Cidade(); // default
    Cidade(string);

    void setCidade(string);

    string getCidade() const
    {
        return cidade;
    }
};

//=========================================================//
//=========================================================//
//=========================================================//

class Nota
{
private:
    string nota;
    void validar(string);

public:
    Nota(); // default

    Nota(string);

    void setNota(string);

    string getNota() const
    {
        return nota;
    }
};

#endif // DOMINIOS_H_INCLUDED
