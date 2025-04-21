#ifndef ITEM_H
#define ITEM_H
#include <bits/stdc++.h>
#include "Produto.h"
#include "Categoria.h"
#include "Pedido.h"

using namespace std;

class Item{
    private:
        int numero;
        int quantidade;
        Produto produto;
        Categoria categoria;
        vector<Pedido> pedidos; //* instância para um vetor de pedidos
    
    public:
        Item();

        Item(const int& numero, const int& quantidade);

        Item(const int& numero, const int& quantidade, const Produto& produto);

        Item(const int& numero, const int& quantidade, const Produto& produto, const Categoria& categoria);

        void exibir_item();

        void setNumero(const int& numero);
        int getNumero() const;

        void setQuantidade(const int& quantidade);
        int getQuantidade() const;

        void setProduto(const Produto&);
        Produto getProduto() const;

        void setCategoria(const Categoria&);
        Categoria getCategoria() const;

        //* Métodos para os pedidos

        //* Gets e Sets de Pedidos
        void setPedidos(const vector<Pedido>&);
        vector<Pedido> getPedidos() const;

        Pedido getPedidoPorCodigo(const int& codigo) const; //* Procurando um determinado pedido através de seu código

        void adicionarPedido(const Pedido& p); //* Método para adicionar um pedido ao vetor de Pedidos
};

#endif