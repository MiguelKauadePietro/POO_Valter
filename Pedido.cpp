#include <bits/stdc++.h>
#include "Pedido.h"
#include "Item.h"

using namespace std;

Pedido::Pedido() {}

Pedido::Pedido(const int& codigo, const string& descricao)
    : codigo(codigo), descricao(descricao) {}

Pedido::Pedido(const int& codigo, const string& descricao, const vector<Item>& itens)
    : codigo(codigo), descricao(descricao), itens(itens) {}

Pedido::Pedido(const int& codigo, const string& descricao, const vector<Item>& itens, Cliente *cli)
    : codigo(codigo), descricao(descricao), itens(itens), cliente(cli) {}

void Pedido::imprimindo_pedido() const{
    float total = 0;
    float totalDesconto = 0;
    cout << "\n-----------------------------" << endl;
    cout << "IMPRIMINDO DADOS DO PEDIDO" << endl;
    cout << "Código do pedido: " << codigo << endl;
    cout << "Descrição do pedido: " << descricao << endl;
    cout << "-----------------------------\n" << endl;

    cout << "-----------------------------" << endl;
    cout << "Itens relacionados a este pedido:\n";
    for (const auto& item: itens)
    {
        item.exibir_item();
    }

    calcularPrecoPedido(itens, total);

    totalDesconto = definirValorComDesconto(total, cliente);

    cout << "\n-----------------------------" << endl;
    cout << "Total Bruto: " << total << endl;
    cout << "Total com descontos: " << totalDesconto<< endl;
    cout << "-----------------------------\n" << endl;

    cout << "Imprimindo dados do cliente associado à esse pedido: \n" << endl;

    cliente->mostrarDados();
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

void Pedido::calcularPrecoPedido(const vector<Item>& itens, float& total) const{
    for (const Item& i : itens)
    {
        total += i.preco_item(i.getQuantidade(), i.getProduto());
    }
}

//! Métodos de Cliente

void Pedido::setCliente(Cliente *cliente){
    this->cliente = cliente;
}

Cliente* Pedido::getCliente() const{
    return this->cliente;
}

float Pedido::definirValorComDesconto(float& totalPreco, const Cliente *cli) const{

    return totalPreco - (totalPreco * cli->calcularDesconto());
}
