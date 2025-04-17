#include <bits/stdc++.h>
#include "Pedido.h"

using namespace std;

Pedido::Pedido() {}

Pedido::Pedido(const int& codigo, const string& nome)
    : codigo(codigo), nome(nome) {}

void Pedido::imprimindo_pedido() const{
    cout << "--------------------------" << endl;
    cout << "IMPRIMINDO DADOS DO PEDIDO" << endl;
    cout << "Nome do pedido: " << nome << endl;
    cout << "Código do pedido: " << codigo << endl;
    cout << "--------------------------" << endl;
}

void Pedido::setCodigoPedido(const int& c){
    this->codigo = c;
}

int Pedido::getCodigoPedido() const {
    return this->codigo;
}

void Pedido::setNomePedido(const string& n){
    this->nome = n;
}

string Pedido::getNomePedido() const {
    return this->nome;
}

