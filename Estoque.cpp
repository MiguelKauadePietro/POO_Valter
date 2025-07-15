#include <bits/stdc++.h>
#include "Estoque.h"
#include "ProdutoNaoEncontradoException.h"
#include "EstoqueInsuficienteException.h"

using namespace std;

Estoque::Estoque() {}

void Estoque::adicionarProduto(const Produto& produto, const int& quantidade){
    for (int i = 0; i < produtos.size(); ++i)
    {
        if (produtos[i] == produto)
        {
            quantidades[i] += quantidade;
            return;
        }
    }

    produtos.push_back(produto);
    quantidades.push_back(quantidade);
}

void Estoque::removerProduto(const int& codigo){
    for (int i = 0; i < produtos.size(); ++i)
    {
        if (produtos[i].getCodigo() == codigo)
        {
            produtos.erase(produtos.begin() + i);
            quantidades.erase(quantidades.begin() + i);
            return;
        }
    }

    cout << "Produto não encontrado no estoque." << endl;

}

void Estoque::atualizarQuantidade(const Produto& produto, const int& qtd){
    for (int i = 0; i < produtos.size(); ++i)
    {
        if (produtos[i] == produto)
        {
            quantidades[i] = qtd;
            return;
        }
    }
}

int Estoque::consultarQuantidade(const Produto& produto) const{
    for (int i = 0; i < produtos.size(); ++i)
    {
        if (produtos[i] == produto)
        {
            return quantidades[i];
        }
    }

    throw EstoqueInsuficienteException();
}

Estoque& Estoque::operator++(int){
    for (int i = 0; i < quantidades.size(); ++i)
    {
        quantidades[i]++;
    }
    return *this;
}

bool Estoque::vazio() const{
    return produtos.empty();
}

const vector<Produto>& Estoque::getProdutos() const{
    return this->produtos;
}

const vector<int>& Estoque::getQuantidade() const{
    return this->quantidades;
}

bool Estoque::removerProdutoPorCodigo(int codigo){
    for (size_t i = 0; i < produtos.size(); ++i) {
        if (produtos[i].getCodigo() == codigo) {
            produtos.erase(produtos.begin() + i);
            quantidades.erase(quantidades.begin() + i);
            return true;
        }
    }
    return false;
}

void Estoque::listarEstoque() const{
    for (int i = 0; i < produtos.size(); ++i)
    {
        produtos[i].apresentar_produto();
    }

    for (int i = 0; i < quantidades.size(); ++i)
    {
        cout << "Quantidade em Estoque: " << quantidades[i] << endl;
    }
}

Produto* Estoque::buscarProdutoPorCodigo(const int& codigo){
    for (int i = 0; i < produtos.size(); ++i)
    {
        if (produtos[i].getCodigo() == codigo)
        {
            return &produtos[i];
        }
    }

        throw ProdutoNaoEncontradoException();
    
}

bool Estoque::atualizarQuantidadePorCodigo(int codigo, int novaQtd){
    for (int i = 0; i < produtos.size(); ++i)
    {
        if (produtos[i].getCodigo() == codigo)
        {
            quantidades[i] = novaQtd;
            return true;
        }
    }

    return false;
    
}

bool Estoque::atualizarProduto(int codigoAntigo, const Produto& novoProd){
    for (int i = 0; i < produtos.size(); ++i)
    {
        if (produtos[i].getCodigo() == codigoAntigo)
        {
            produtos[i] = novoProd;
            return true;
        }
    }
    return false;

}