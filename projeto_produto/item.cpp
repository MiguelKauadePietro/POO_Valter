#include <bits/stdc++.h>
#include "Item.h"
#include "Categoria.h"

using namespace std;

    Item::Item() {} //* Construtor vazio, padrão usado para inicializar valores sem a necessidade de parâmetros/argumentos

    Item::Item(const int& numero, const int& quantidade) //* Construtor que inicializa os atributos numero e quantidade
        :numero(numero), quantidade(quantidade) {}

    Item::Item(const int& numero, const int& quantidade, const Produto& produto)
        : numero(numero), quantidade(quantidade), produto(produto) {}

    Item::Item(const int& numero, const int& quantidade, const Produto& produto, const Categoria& categoria)
        : numero(numero), quantidade(quantidade), produto(produto), categoria(categoria) {}

    void Item::exibir_item(){
        cout << "--------------------------------------------" << endl;
        cout << "Printando DADOS: " << endl;
        cout << "Número do Produto: " << numero << "\n" << "Quantidade do Produto: " << quantidade << endl;
        cout << "Categoria do Item: " << categoria.categoriaToString() << endl; //* Imprimindo a categoria como string e não como enum pela função categoriaToString()

        produto.apresentar_produto();

        cout << "\nPedidos relacionados a este item:\n";
        for (const Pedido& pedido: pedidos)
        {
            pedido.imprimindo_pedido();
        }

        cout << "--------------------------------------------" << endl;
    }

    Pedido Item::getPedidoPorCodigo(const int& codigo) const{
        for(const Pedido& pedido: pedidos){
            if(pedido.getCodigoPedido() == codigo){
                return pedido;
            }
        }
        throw runtime_error("Esse código não pertence à nenhum Pedido.");
    }

    void Item::adicionarPedido(const Pedido& pedido){
        pedidos.push_back(pedido);
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

    void Item::setCategoria(const Categoria& categoria){
        this->categoria = categoria;
    }

    Categoria Item::getCategoria() const {
        return this->categoria;
    }

    void Item::setPedidos(const vector<Pedido>& pedidos){
        this->pedidos = pedidos;
    }

    vector<Pedido> Item::getPedidos() const {
        return this->pedidos;
    }