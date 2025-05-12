#include <bits/stdc++.h>
#include "Fisico.h"

using namespace std;

Fisico::Fisico() {}

Fisico::Fisico(const int& codigo, const string& nome, const Endereco& endereco)
    : Cliente(codigo, nome, endereco) {}

Fisico::Fisico(const int& codigo, const string& nome, const Endereco& endereco, const string& cpf)
    : Cliente(codigo, nome, endereco), cpf(cpf) {}

void Fisico::setCPF(const string& cpf){
    this->cpf = cpf;
}

string Fisico::getCPF() const{
    return this->cpf;
}

void Fisico::mostrarDados() const{
    cout << "-----------------------------" << endl;
    cout << "IMPRIMINDO DADOS: " << endl;
    cout << "Código: " << getCodigo() << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "CPF" << cpf << endl;
    cout << "-----------------------------" << endl;

    endereco.exibirEndereco();

}

float Fisico::calcularDesconto() const{
    float descontoFisico = 0.015;
    return descontoFisico;
}