#include <bits/stdc++.h>
#include "Item.h"
#ifndef PEDIDO_H
#define PEDIDO_H

using namespace std;


class Pedido{
    private:
        int codigo;
        string descricao;
        vector<Item> itens;

    public:

    Pedido(); //* Construtor padrão
    Pedido(const int& codigo, const string& descricao); //* Construtor com parâmetros

    //* Printando os dados do pedido
    void imprimindo_pedido() const;

    //* Métodos Get e Set

    void setCodigoPedido(const int& c);
    int getCodigoPedido() const;

    void setDescPedido(const string& n);
    string getDescPedido() const;

    //! MÉTODOS DE ITENS


    //! Métodos para os pedidos

    //! Gets e Sets de Pedidos
    void setItens(const vector<Item>&);
    vector<Item> getItens() const;

    Item getItemPorNumero(const int& num) const; //! Procurando um determinado pedido através de seu código

    void adicionarItem(const Item& i); //! Método para adicionar um pedido ao vetor de Pedidos
};

// cout << "\nPedidos relacionados a este item:\n";
// for (const Pedido& pedido: pedidos)
// {
//     pedido.imprimindo_pedido();
// }

// cout << "--------------------------------------------" << endl;
// }

// Pedido Item::getPedidoPorCodigo(const int& codigo) const{
// for(const Pedido& pedido: pedidos){
//     if(pedido.getCodigoPedido() == codigo){
//         return pedido;
//     }
// }
// throw runtime_error("Esse código não pertence à nenhum Pedido.");
// }

// void Item::adicionarPedido(const Pedido& pedido){
// pedidos.push_back(pedido);
// }

#endif