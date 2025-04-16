#ifndef ITEM_H
#define ITEM_H
#include <bits/stdc++.h>
#include "Produto.h"

using namespace std;

class item{
    private:
        int numero;
        int quantidade;
        Produto produto;
    
    public:
        item();

        item(const int& numero, const int& quantidade);

        item(const int& numero, const int& quantidade, const Produto& produto);

        void exibir_item();

        void setNumero(const int& numero);
        int getNumero() const;

        void setQuantidade(const int& quantidade);
        int getQuantidade() const;

        void setProduto(const Produto&);
        Produto getProduto() const;
};

#endif