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

    cout << "\Itens relacionados a este item:\n";
    for (const Item& item: itens)
    {
        item.exibir_item();
    }
}

void Pedido::setCodigoPedido(const int& c){
    this->codigo = c;
}

int Pedido::getCodigoPedido() const {
    return this->codigo;
}

void Pedido::setDescPedido(const string& d){
    this->descricao = d;
}

string Pedido::getDescPedido() const {
    return this->descricao;
}

//! MÉTODOS DE ITENS

void Pedido::setItens(const vector<Item>& itens){
    this->itens = itens;
}

vector<Item> Pedido::getItens() const {
    return this->itens;
}

Item Pedido::getItemPorNumero(const int& numero) const{
        for(const Item& item: itens){
            if(item.getNumero() == numero){
                return item;
            }
        }
        throw runtime_error("Esse código não pertence à nenhum Pedido.");
    }
    
    void Pedido::adicionarItem(const Item& item){
        itens.push_back(item);
    }
    
