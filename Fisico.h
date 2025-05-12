#include <bits/stdc++.h>
#include "Cliente.h"
#include "Endereco.h"
#ifndef FISICO_H
#define FISICO_H


using namespace std;

class Fisico: public Cliente{

    private:
        string cpf;
    
    public:
        Fisico();
        Fisico(const int& codigo, const string& nome, const Endereco& endereco);
        Fisico(const int& codigo, const string& nome, const Endereco& endereco, const string& cpf);

        void setCPF(const string& cpf);
        string getCPF() const;

        void mostrarDados() const override;

        float calcularDesconto() const override;

};

#endif