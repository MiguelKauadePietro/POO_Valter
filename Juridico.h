#include <bits/stdc++.h>
#include "Cliente.h"
#ifndef JURIDICO_H
#define JURIDICO_H

using namespace std;

class Juridico: public Cliente {

    private:
        string cnpj;
    
    public:
        Juridico();
        Juridico(const int& codigo, const string& nome);
        Juridico(const int& codigo, const string& nome, const string& cnpj);

        void setCNPJ(const string& cnpj);
        string getCNPJ() const;

        void mostrarDados() const override;

        float calcularDesconto() const override;

};


#endif