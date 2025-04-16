// #include <bits/stdc++.h>
#include <iostream>
#include "Item.h"
// #include "Produto.h"

using namespace std;

    item::item() {}

    item::item(const int& numero, const int& quantidade)
        :numero(numero), quantidade(quantidade) {}

    item::item(const int& numero, const int& quantidade, const Produto& produto)
        : numero(numero), quantidade(quantidade), produto(produto) {}

    void item::exibir_item(){
        cout << "Printando DADOS: " << endl;
        cout << "Número do Produto: " << numero << "\n" << "Quantidade do Produto: " << quantidade << endl;

        produto.apresentar_produto();
    }

    void item::setNumero(const int& num){
        this->numero = num;
    }

    int item::getNumero() const{
        return this->numero;
    }

    void item::setQuantidade(const int& qtd){
        this->quantidade = qtd;
    }

    int item::getQuantidade() const {
        return this->quantidade;
    }

    void item::setProduto(const Produto& produto){
        this->produto = produto;
    }

    Produto item::getProduto() const {
        return this->produto;
    }
