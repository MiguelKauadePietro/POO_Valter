#include <bits/stdc++.h>
#include "Pedido.h"

using namespace std;

Pedido::Pedido() {}

Pedido::Pedido(const int& codigo, const string& descricao)
    : codigo(codigo), descricao(descricao) {}

void Pedido::imprimindo_pedido() const{
    cout << "IMPRIMINDO DADOS DO PEDIDO" << endl;
    cout << "Código do pedido: " << codigo << endl;
    cout << "Descrição do pedido: " << descricao << endl;
}

void Pedido::setCodigoPedido(const int& c){
    this->codigo = c;
}

int Pedido::getCodigoPedido() const {
    return this->codigo;
}

void Pedido::setNomePedido(const string& d){
    this->descricao = d;
}

string Pedido::getNomePedido() const {
    return this->descricao;
}

