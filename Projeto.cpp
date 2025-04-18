#include "Projeto.h"

// Construtor com parâmetros
Projeto::Projeto(const int c, const string& n) : codigo(c), nome(n) {}

// Construtor padrão
Projeto::Projeto() : codigo(0), nome("") {}

// Métodos set
void Projeto::setCodigo(const int c) {
    codigo = c;
}

void Projeto::setNome(const string& n) {
    nome = n;
}

// Métodos get
int Projeto::getCodigo() const {
    return codigo;
}

string Projeto::getNome() const {
    return nome;
}

// Método para imprimir os dados
void Projeto::imprimir() const {
    cout << "Projeto Código: " << codigo << ", Nome: " << nome << endl;
}
