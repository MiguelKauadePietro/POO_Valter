#include <bits/stdc++.h>
// #include <string>
#include "Produto.h"

using namespace std;

Produto::Produto() {} //* Construtor Vazio, para padronização de inicialização
Produto::Produto(const int& c, const string& n, const float& p) //* Construtor Parâmetrizado
    :codigo(c), nome(n), preco(p){} //* Lista de inicialização

void Produto::apresentar_produto() const{ //* Função que printa os dados do produto(Código, Nome e Preço)
    cout << "DADOS DO PRODUTO" << endl;

    cout << "Código: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    cout << "Preço: " << preco << endl;

}

void Produto::setCodigo(const int& c){
    this->codigo = c;
}

int Produto::getCodigo() const{
    return codigo;
}

void Produto::setNome(const string& n){
    this->nome = n;
}

string Produto::getNome() const {
    return nome;
}

void Produto::setPreco(const float& p){
    this->preco = p;
}

float Produto::getPreco() const {
    return preco;
}