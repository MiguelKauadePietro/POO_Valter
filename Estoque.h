#include <bits/stdc++.h>
#include "Produto.h"
#ifndef ESTOQUE_H
#define ESTOQUE_H

using namespace std;

class Estoque{
    private:
        vector<Produto> produtos;
        vector<int> quantidades;


    public:
        Estoque();

        void adicionarProduto(const Produto& produto, const int& quantidade);
        void removerProduto(const int& codigo);
        void listarEstoque() const;
        Produto* buscarProdutoPorCodigo(const int& codigo);

        void atualizarQuantidade(const Produto& produto, const int& qtd);
        int consultarQuantidade(const Produto& produto) const;

        Estoque& operator++(int);

        bool vazio() const;

        const vector<Produto>& getProdutos() const;

        const vector<int>& getQuantidade() const;

        bool removerProdutoPorCodigo(int codigo);
};



#endif