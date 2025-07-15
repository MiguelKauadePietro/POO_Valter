#include <bits/stdc++.h>
#include "Pedido.h"
#include "Item.h"
#include "DescontoClienteOuro.h"
#include "CalculadoraDesconto.h"
#include "DescontoPorQuantidade.h"

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
    calcularPrecoPedido(itens, total);

    cout << "\n-----------------------------" << endl;
    cout << "IMPRIMINDO DADOS DO PEDIDO" << endl;
    cout << "Código do pedido: " << codigo << endl;
    cout << "Descrição do pedido: " << descricao << endl;
    cout << "-----------------------------\n" << endl;

    cout << "Itens relacionados a este pedido:\n";
    for (int i = 0; i < itens.size(); ++i)
        (*this)[i].exibir_item();

    cout << "\n-----------------------------" << endl;
    cout << "Total Bruto: R$ " << fixed << setprecision(2) << total << endl;

    //! Descontos personalizados via template
    double descOuro = CalculadoraDesconto<DescontoClienteOuro>::calcular(*this);
    double descQtd = CalculadoraDesconto<DescontoPorQuantidade>::calcular(*this);

    double totalComDescontos = total * (1.0 - descOuro) * (1.0 - descQtd);

    cout << "Desconto Cliente Ouro: " << (descOuro * 100) << "%" << endl;
    cout << "Desconto por Quantidade: " << (descQtd * 100) << "%" << endl;
    cout << "Total com Descontos: R$ " << fixed << setprecision(2) << totalComDescontos << endl;
    cout << "-----------------------------\n" << endl;

    cout << "Imprimindo dados do cliente associado a este pedido: \n" << endl;
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

//! Corpo da sobrecarga dos operadores:
Item& Pedido::operator[](int i) {
    if (i < 0 || i >= itens.size()) {
        cout << "Índice inválido" << endl;
    }
    return itens[i];
}

const Item& Pedido::operator[](int i) const {
    if (i < 0 || i >= itens.size()) {
        cout << "Índice inválido" << endl;
    }
    return itens[i];
}

Pedido Pedido::operator+(const Item& item) {
    Pedido novo = *this;
    novo.itens.push_back(item);
    return novo;
}

Pedido Pedido::operator-(const Item& item) {
    Pedido novo = *this;
    for (auto it = novo.itens.begin(); it != novo.itens.end(); ++it) {
        if (it->getProduto() == item.getProduto()) {
            novo.itens.erase(it);
            novo.setItens(novo.itens);
            break;
        }
    }
    return novo;
}

//! Gerando código do pedido automaticamente
int Pedido::gerarCodigoPedido() {
    static int codigo = 1;
    return codigo++;
}