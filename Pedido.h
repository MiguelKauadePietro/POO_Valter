#include <bits/stdc++.h>
#include "Item.h"
#include "Cliente.h"
#ifndef PEDIDO_H
#define PEDIDO_H

using namespace std;


class Pedido{
    private:
        int codigo;
        string descricao;
        vector<Item> itens;
        Cliente *cliente;

    public:

    Pedido(); //* Construtor padrão
    Pedido(const int& codigo, const string& descricao); //* Construtor com parâmetros
    Pedido(const int& codigo, const string& descricao, const vector<Item>& itens); //* Construtor com parâmetros(vetor de itens incluido)
    Pedido(const int& codigo, const string& descricao, const vector<Item>& itens, Cliente *cliente); //* Construtor com parâmetros(vetor de itens e cliente incluidos)

    //* Printando os dados do pedido
    void imprimindo_pedido() const;

    //* Métodos Get e Set

    void setCodigoPedido(const int& c);
    int getCodigoPedido() const;

    void setDescPedido(const string& n);
    string getDescPedido() const;

    static int gerarCodigoPedido();

    //! MÉTODOS DE ITENS

    //! Gets e Sets de Itens
    void setItens(const vector<Item>&);
    vector<Item> getItens() const;

    Item getItemPorNumero(const int& num) const; //! Procurando um determinado pedido através de seu código

    //! Métodos para manipular os Itens

    void adicionarItem(const Item& i); //! Método para adicionar um pedido ao vetor de Pedidos

    void calcularPrecoPedido(const vector<Item>& itens, float& total) const;

    //! Métodos referente ao atributo Cliente

    void setCliente(Cliente *cliente);
    Cliente *getCliente() const;

    float definirValorComDesconto(float& total, const Cliente *cli) const;

    //! Sobrecarga dos operadores relacionados aos pedidos

    Item& operator[](int index);
    const Item& operator[](int index) const;

    Pedido operator+(const Item& item);
    Pedido operator-(const Item& item);
};


#endif