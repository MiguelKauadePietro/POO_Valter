#include <bits/stdc++.h>
#include "Juridico.h"

using namespace std;

Juridico::Juridico() {}

Juridico::Juridico(const int& codigo, const string& nome, const Endereco& endereco)
    : Cliente(codigo, nome, endereco) {}

Juridico::Juridico(const int& codigo, const string& nome, const Endereco& endereco, const string& cnpj)
    : Cliente(codigo, nome, endereco), cnpj(cnpj) {}

void Juridico::setCNPJ(const string& cnpj){
    this->cnpj = cnpj;
}

string Juridico::getCNPJ() const{
    return this->cnpj;
}

void Juridico::mostrarDados() const{
    cout << "-----------------------------" << endl;
    cout << "IMPRIMINDO DADOS: " << endl;
    cout << "Código: " << getCodigo() << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "CNPJ" << cnpj << endl;
    cout << "-----------------------------" << endl;

    endereco.exibirEndereco();

}

float Juridico::calcularDesconto() const{
    float descontoJuridico = 0.01;
    return descontoJuridico;
}