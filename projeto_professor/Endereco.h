#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>

using namespace std;

class Endereco {
private:
    string rua;
    string cidade;
    string estado;
    string cep;

public:
    Endereco();
    Endereco(const string rua, const string cidade, const string estado, const string cep);
    void exibirEndereco() const;
    
    void setRua(const string);
    void setCidade(const string);
    void setEstado(const string);
    void setCep(const string);
    
    string getRua();
    string getCidade();
    string getEstado();
    string getCep();

};
#endif