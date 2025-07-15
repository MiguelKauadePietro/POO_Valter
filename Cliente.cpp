#include <bits/stdc++.h>
#include "Cliente.h"

using namespace std;

Cliente::Cliente() {}

Cliente::Cliente(const int& codigo, const string& nome)
    : codigo(codigo), nome(nome) {}

Cliente::Cliente(const int& codigo, const string& nome, const Endereco& endereco)
    : codigo(codigo), nome(nome), endereco(endereco) {}

//! GETTERS E SETTERS

void Cliente::setCodigo(const int& code){
    this->codigo = code;
}

int Cliente::getCodigo() const {
    return this->codigo;
}

void Cliente::setNome(const string& nome){
    this->nome = nome;
}

string Cliente::getNome() const{
    return this->nome;
}

int Cliente::gerarCodigoCliente(){
    static int proximoCodigo = 1; //! Usando uma variável "static" para manter o valor do código do cliente na memória
    return proximoCodigo++; //! Depois retorno este código, depois de retornado incremento ele, e como é static, vai manter o valor incrementado, assim evitamos os erros de códigos repetidos pelo erro do user(desprovido de inteligência)
}