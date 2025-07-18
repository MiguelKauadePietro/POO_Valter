#include <bits/stdc++.h>
#include "Produto.h"
#include "Categoria.h"

using namespace std;

Produto::Produto() {} //* Construtor Vazio, para padronização de inicialização
Produto::Produto(const int& c, const string& n, const float& p, const Categoria& cat ) //* Construtor Parâmetrizado
    :codigo(c), nome(n), preco(p), categoria(cat) {} //* Lista de inicialização

void Produto::apresentar_produto() const{ //* Função que printa os dados do produto(Código, Nome e Preço)
    cout << "DADOS DO PRODUTO" << endl;

    cout << *this << endl;

}

void Produto::setCodigo(const int& c){
    this->codigo = c;
}

int Produto::getCodigo() const{
    return codigo;
}

void Produto::setNome(const string& n){
    this->nome = n;
}

string Produto::getNome() const {
    return nome;
}

void Produto::setPreco(const float& p){
    this->preco = p;
}

float Produto::getPreco() const {
    return preco;
}

void Produto::setCategoria(const Categoria& categoria){
    this->categoria = categoria;
}

Categoria Produto::getCategoria() const {
    return this->categoria;
}

bool Produto::operator==(const Produto& outroProd) const{
    return codigo == outroProd.codigo;
}

bool Produto::operator!=(const Produto& outroProd) const{
    return codigo != outroProd.codigo;
}

bool Produto::operator<(const Produto& outro) const {
    return preco < outro.preco;
}

bool Produto::operator>(const Produto& outro) const {
    return preco > outro.preco;
}

ostream& operator<<(ostream& os, const Produto& p) {
    os << "Código: " << p.codigo << "\n"
       << "Nome: " << p.nome << "\n"
       << "Preço: R$ " << fixed << setprecision(2) << p.preco << "\n"
       << "Categoria: " << p.categoria.categoriaToString();
    return os;
}

int Produto::gerarCodigoProduto(){
    static int codigo = 1;
    return codigo++;
}


