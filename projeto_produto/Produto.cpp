#include <bits/stdc++.h>
// #include <string>
#include "Produto.h"

using namespace std;

Produto::Produto() {}
Produto::Produto(const int c, const string n, const float p)
    :codigo(c), nome(n), preco(p){}

void Produto::apresentar_produto(){
    cout << "DADOS DO PRODUTO" << endl;

    cout << "Código: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    cout << "Preço: " << preco << endl;

}

void Produto::setCodigo(const int c){
    this->codigo = c;
}

int Produto::getCodigo() const{
    return codigo;
}

void Produto::setNome(const string n){
    this->nome = n;
}

string Produto::getNome() const {
    return nome;
}

void Produto::setPreco(const float p){
    this->preco = p;
}

float Produto::getPreco() const {
    return preco;
}