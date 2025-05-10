#include <bits/stdc++.h>
#ifndef ENDERECO_H
#define ENDERECO_H


using namespace std;

class Endereco{

    private:
        string rua;
        int numero;
        string bairro;
        string cidade;

    public:

        Endereco();
        Endereco(const string rua, const int& numero, const string& bairro, const string& cidade);

        void setRua(const string& rua);
        string getRua() const;

        void setNumeroCasa(const int& numero);
        int getNumeroCasa() const;

        void setBairro(const string& bairro);
        string getBairro() const;

        void setCidade(const string& cidade);
        string getCidade() const;

        void exibirEndereco() const;

};


#endif