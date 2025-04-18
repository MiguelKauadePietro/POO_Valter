#include <bits/stdc++.h>
#include "Item.h"
#include "Categoria.h"

using namespace std;

    item::item() {} //* Construtor vazio, padrão usado para inicializar valores sem a necessidade de parâmetros/argumentos

    item::item(const int& numero, const int& quantidade) //* Construtor que inicializa os atributos numero e quantidade
        :numero(numero), quantidade(quantidade) {}

    item::item(const int& numero, const int& quantidade, const Produto& produto)
        : numero(numero), quantidade(quantidade), produto(produto) {}

    item::item(const int& numero, const int& quantidade, const Produto& produto, const Categoria& categoria)
        : numero(numero), quantidade(quantidade), produto(produto), categoria(categoria) {}

    void item::exibir_item(){
        cout << "--------------------------------------------" << endl;
        cout << "Printando DADOS: " << endl;
        cout << "Número do Produto: " << numero << "\n" << "Quantidade do Produto: " << quantidade << endl;
        cout << "Categoria do item: " << categoria.categoriaToString() << endl; //* Imprimindo a categoria como string e não como enum pela função categoriaToString()

        produto.apresentar_produto();

        for (const Pedido& pedido: pedidos)
        {
            pedido.imprimindo_pedido();
        }

        cout << "--------------------------------------------" << endl;
    }

    Pedido item::getPedidoPorCodigo(const int& codigo) const{
        for(const Pedido& pedido: pedidos){
            if(pedido.getCodigoPedido() == codigo){
                return pedido;
            }
        }
        throw runtime_error("Esse código não pertence à nenhum Pedido.");
    }

    void item::adicionarPedido(const Pedido& pedido){
        pedidos.push_back(pedido);
    }

    //* Métdos Gets e Sets

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

    void item::setCategoria(const Categoria& categoria){
        this->categoria = categoria;
    }

    Categoria item::getCategoria() const {
        return this->categoria;
    }

