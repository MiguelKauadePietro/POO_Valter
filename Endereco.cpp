#include <bits/stdc++.h>
#include "Endereco.h"

using namespace std;

Endereco::Endereco() {}

Endereco::Endereco(const string rua, const int& numero, const string& bairro, const string& cidade)
    : rua(rua), numero(numero), bairro(bairro), cidade(cidade) {}

void Endereco::setRua(const string& rua){
    this->rua = rua;
}

string Endereco::getRua() const{
    return this->rua;
}

void Endereco::setNumeroCasa(const int& numero){
    this->numero = numero;
}

int Endereco::getNumeroCasa() const{
    return this->numero;
}

void Endereco::setBairro(const string& bairro){
    this->bairro = bairro;
}

string Endereco::getBairro() const{
    return this->bairro;
}

void Endereco::setCidade(const string& cidade){
    this->cidade = cidade;
}

string Endereco::getCidade() const{
    return this->cidade;
}

void Endereco::exibirEndereco() const{
    cout << "-----------------------------" << endl;
    cout << "IMPRIMINDO DADOS DO ENDEREÇO DO CLIENTE: " << endl;
    cout << "Rua: " << getRua() << endl;
    cout << "Número da casa: " << getNumeroCasa() << endl;
    cout << "Bairro: " << getBairro() << endl;
    cout << "Cidade: " << getCidade() << endl;
    cout << "-----------------------------" << endl;
}