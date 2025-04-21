#include <bits/stdc++.h>
#ifndef PEDIDO_H
#define PEDIDO_H

using namespace std;


class Pedido{
    private:
        int codigo;
        string descricao;

    public:

    Pedido(); //* Construtor padrão
    Pedido(const int& codigo, const string& descricao); //* Construtor com parâmetros

    //* Printando os dados do pedido
    void imprimindo_pedido() const;

    //* Métodos Get e Set

    void setCodigoPedido(const int& c);
    int getCodigoPedido() const;

    void setNomePedido(const string& n);
    string getNomePedido() const;
};

#endif