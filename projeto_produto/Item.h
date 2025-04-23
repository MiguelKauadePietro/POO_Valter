#ifndef ITEM_H
#define ITEM_H
#include <bits/stdc++.h>
#include "Produto.h"
#include "Categoria.h"
#include "Pedido.h"

using namespace std;

class Item{
    //! ATRIBUTOS
    private:
        int numero;
        int quantidade;
        Produto produto; //! Instância para a classe Produto
    public:
        Item();

        Item(const int& numero, const int& quantidade);

        Item(const int& numero, const int& quantidade, const Produto& produto);

        void exibir_item() const;

        void setNumero(const int& numero);
        int getNumero() const;

        void setQuantidade(const int& quantidade);
        int getQuantidade() const;

        void setProduto(const Produto&);
        Produto getProduto() const;

        //! FUNÇÃO QUE CÁLCULA O TOTAL DE UM ITEM
        float preco_total(const int& quantidade, const Produto& produto);
};

#endif