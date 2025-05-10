#include <bits/stdc++.h>
#include "Endereco.h"
#ifndef CLIENTE_H
#define CLIENTE_H


using namespace std;


class Cliente{

    protected:
        int codigo;
        string nome;
        Endereco endereco;

    public:
        Cliente();
        Cliente(const int& codigo, const string& nome);
        Cliente(const int& codigo, const string& nome, const Endereco& endereco);

        void setCodigo(const int& codigo);
        int getCodigo() const;

        void setNome(const string& nome);
        string getNome() const;

        virtual void mostrarDados() const = 0;

        virtual float calcularDesconto() const = 0;

        virtual ~Cliente() {}

};


#endif