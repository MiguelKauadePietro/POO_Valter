#ifndef PROJETO_H
#define PROJETO_H

#include <string>
#include <iostream>
using namespace std;

class Projeto {
private:
    int codigo;
    string nome;

public:
    // Construtores
    Projeto(const int c, const string& n); // Construtor com parâmetros
    Projeto(); // Construtor padrão

    // Métodos get e set
    void setCodigo(const int c);
    int getCodigo() const;

    void setNome(const string& n);
    string getNome() const;

    // Método para imprimir os dados
    void imprimir() const;
};

#endif
