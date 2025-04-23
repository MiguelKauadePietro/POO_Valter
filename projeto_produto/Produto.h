#include <bits/stdc++.h>
#ifndef PRODUTO_H
#define PRODUTO_H

using namespace std;


class Produto{
    private:

        int codigo;
        string nome;
        float preco;
        Categoria categoria; //! Instância para a classe enum Categoria


    public:

        Produto();
        Produto(const int& c, const string& n, const float& p, const Categoria& categoria);
        void apresentar_produto() const;
        void setCodigo(const int& c);
        int getCodigo() const;
        void setNome(const string& n);
        string getNome() const;
        void setPreco(const float& p);
        float getPreco() const;
        void setCategoria(const Categoria&);
        Categoria getCategoria() const;
};

#endif
