#include <bits/stdc++.h>
#ifndef PRODUTO_H
#define PRODUTO_H

using namespace std;


class Produto{
    private:

        int codigo;
        string nome;
        float preco;


    public:

        Produto();
        Produto(const int c, const string n, const float p);
        void apresentar_produto();
        void setCodigo(const int c);
        int getCodigo() const;
        void setNome(const string n);
        string getNome() const;
        void setPreco(const float p);
        float getPreco() const;
};

#endif
