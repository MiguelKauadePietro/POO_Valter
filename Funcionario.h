#include <bits/stdc++.h>
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#endif

using namespace std;

class Funcionario{
    private: //! Atributos
    int codigo;
    std::string nome;
    int idade;

    public: //! Métodos
    Funcionario(int c, std::string n, int i); //! Criando um construtor(assinatura) dos métodos para que os atributos sejam inicializados com algum valor
    void apresentar();
    void setCodigo(int c);
    int getCodigo();
    void setNome(std::string s);
    std::string getNome();
    void setIdade(int i);
    int getIdade();

};