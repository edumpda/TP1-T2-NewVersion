#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include <string>

using namespace std;
class Usuario {
private:
    Nome      nome;
    Email     email;
    Senha     senha;
    Idioma    idioma;
    Aniversario       aniversario;
    Descricao descricao;
public:
    void setNome(const Nome&);
    Nome getNome() const;

    void setEmail(const Email&);
    Email getEmail() const;

    void setSenha(const Senha&);
    Senha getSenha() const;

    void setIdioma(const Idioma&);
    Idioma getIdioma() const;

    void setAniversario(const Aniversario&);
    Aniversario getAniversario() const;

    void setDescricao(const Descricao&);
    Descricao getDescricao() const;

};

inline void Usuario::setNome(const Nome& valor_criado){
    this->nome = valor_criado;
}

inline Nome Usuario::getNome() const {
    return nome;
}

inline void Usuario::setEmail(const Email& valor_criado){
    this->email = valor_criado;
}

inline Email Usuario::getEmail() const {
    return email;
}

inline void Usuario::setSenha(const Senha& valor_criado){
    this->senha = valor_criado;
}

inline Senha Usuario::getSenha() const {
    return senha;
}

inline void Usuario::setIdioma(const Idioma& valor_criado){
    this->idioma = valor_criado;
}

inline Idioma Usuario::getIdioma() const {
    return idioma;
}

inline void Usuario::setAniversario(const Aniversario& valor_criado) {
    this->aniversario = valor_criado;
}

inline Aniversario Usuario::getAniversario() const{
    return aniversario;
}

inline void Usuario::setDescricao(const Descricao& valor_criado){
    this->descricao = valor_criado;
}

inline Descricao Usuario::getDescricao() const {
    return descricao;
}


//HOSPEDAGEM
class Hospedagem{
private:
    Codigo codigo;
    Pais pais;
    Cidade cidade;
    Nota nota;
    Descricao descricao;
public:
    void setCodigo(const Codigo&);
    Codigo getCodigo() const;
    void setPais(const Pais&);
    Pais getPais() const;
    void setCidade(const Cidade&);
    Cidade getCidade() const;
    void setNota(const Nota&);
    Nota getNota() const;
    void setDescricao(const Descricao&);
    Descricao getDescricao() const;

};

inline void Hospedagem::setCodigo(const Codigo& valor_criado){
    this->codigo = valor_criado;
}
inline Codigo Hospedagem::getCodigo() const{
    return codigo;
}
inline void Hospedagem::setPais(const Pais& valor_criado){
    this->pais = valor_criado;
}
inline Pais Hospedagem::getPais() const{
    return pais;
}
inline void Hospedagem::setCidade(const  Cidade& valor_criado){
    this->cidade = valor_criado;
}
inline Cidade Hospedagem::getCidade() const{
    return cidade;
}
inline void Hospedagem::setNota(const  Nota& valor_criado){
    this->nota = valor_criado;
}
inline Nota Hospedagem::getNota() const{
    return nota;
}

inline void Hospedagem::setDescricao(const  Descricao& valor_criado){
    this->descricao = valor_criado;
}
inline Descricao Hospedagem::getDescricao() const{
    return descricao;
}

class Avaliacao{
private:
    Codigo codigo;
    Nota nota;
    Descricao descricao;
public:
    void setCodigo(const Codigo&);
    Codigo getCodigo() const;
    void setNota(const Nota&);
    Nota getNota() const;
    void setDescricao(const Descricao&);
    Descricao getDescricao() const;
};

inline void Avaliacao::setCodigo(const Codigo& valor_criado){
    this->codigo = valor_criado;
}
inline Codigo Avaliacao::getCodigo() const{
    return codigo;
}
inline void Avaliacao::setNota(const Nota& valor_criado){
    this->nota = valor_criado;
}
inline Nota Avaliacao::getNota() const{
    return nota;
}
inline void Avaliacao::setDescricao(const Descricao& valor_criado){
    this->descricao = valor_criado;
}
inline Descricao Avaliacao::getDescricao() const{
    return descricao;
}
#endif // ENTIDADES_H_INCLUDED
