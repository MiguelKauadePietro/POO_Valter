#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Endereco.h"
#include "Cargo.cpp"
#include "Projeto.h"
#include <vector>

using namespace std;

class Funcionario {
private:
    int codigo;
    string nome;
    int idade;
    Endereco endereco;
    Cargo cargo;
    vector<Projeto> projetos; // Lista dinâmica de projetos

public:
    Funcionario(int c, string n, int i, Endereco& endereco, const Cargo&);
    Funcionario(int c, string n, int i, Endereco& endereco);
    Funcionario(string, int);
    Funcionario();

    void apresentar() const;

    void setCodigo(const int);
    int getCodigo();

    void setNome(const string);
    string getNome();

    void setIdade(const int);
    int getIdade() const;

    void setEndereco(const Endereco&);
    Endereco getEndereco();

    void setCargo(const Cargo&);
    Cargo getCargo();

    // Métodos relacionados a projetos
    void setProjetos(const vector<Projeto>&);
    vector<Projeto> getProjetos() const;
    Projeto getProjetoPorCodigo(const int codigo) const;
    void adicionarProjeto(const Projeto& p);  // Método para adicionar um projeto
};

#endif
