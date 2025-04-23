#include <bits/stdc++.h>
#include "Item.h"
#include "Categoria.h"

using namespace std;

    Item::Item() {} //* Construtor vazio, padrão usado para inicializar valores sem a necessidade de parâmetros/argumentos

    Item::Item(const int& numero, const int& quantidade) //* Construtor que inicializa os atributos numero e quantidade
        :numero(numero), quantidade(quantidade) {}

    Item::Item(const int& numero, const int& quantidade, const Produto& produto)
        : numero(numero), quantidade(quantidade), produto(produto) {}

    void Item::exibir_item() const{
        cout << "--------------------------------------------" << endl;
        cout << "Printando DADOS: " << endl;
        cout << "Número do Produto: " << numero << "\n" << "Quantidade do Produto: " << quantidade << endl; //* Imprimindo a categoria como string e não como enum pela função categoriaToString()

        produto.apresentar_produto();

        cout << "--------------------------------------------" << endl;
    }

    //* Métdos Gets e Sets

    void Item::setNumero(const int& num){
        this->numero = num;
    }

    int Item::getNumero() const{
        return this->numero;
    }

    void Item::setQuantidade(const int& qtd){
        this->quantidade = qtd;
    }

    int Item::getQuantidade() const {
        return this->quantidade;
    }

    void Item::setProduto(const Produto& produto){
        this->produto = produto;
    }

    Produto Item::getProduto() const {
        return this->produto;
    }

    //! CORPO DA FUNÇÃO QUE CALCULA O PREÇO TOTAL DE UM ITEM
    float Item::preco_total(const int& quantidade, const Produto& produto){
        return this->quantidade * this->produto.getPreco();
    }