#include "Funcionario.h"
#include <iostream>

using namespace std;

Funcionario::Funcionario(int c, string n, int i, Endereco& end, const Cargo& car)
    : codigo(c), nome(n), idade(i), endereco(end), cargo(car) {}

Funcionario::Funcionario(int c, string n, int i, Endereco& end)
    : codigo(c), nome(n), idade(i), endereco(end) {}

Funcionario::Funcionario(string n, int i)
    : codigo(0), nome(n), idade(i) {}

Funcionario::Funcionario() {}

void Funcionario::apresentar() const {
    cout << "--- PRINTANDO DADOS ---" << endl;

    cout << "Codigo: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Cargo: " << cargo.toString() << endl;

    endereco.exibirEndereco();

    cout << "Projetos do funcionário:" << endl;
    for (const Projeto& p : projetos) {
        p.imprimir();
    }

    cout << "------------------" << endl;
}

void Funcionario::setEndereco(const Endereco& end) {
    this->endereco = end;
}

Endereco Funcionario::getEndereco() {
    return this->endereco;
}

void Funcionario::setCodigo(const int codigo) {
    this->codigo = codigo;
}

int Funcionario::getCodigo() {
    return codigo;
}

void Funcionario::setNome(const string nome) {
    this->nome = nome;
}

string Funcionario::getNome() {
    return nome;
}

void Funcionario::setIdade(const int idade) {
    this->idade = idade;
}

int Funcionario::getIdade() const {
    return idade;
}

void Funcionario::setCargo(const Cargo& c) {
    this->cargo = c;
}

Cargo Funcionario::getCargo() {
    return this->cargo;
}

// Métodos para projetos

void Funcionario::setProjetos(const vector<Projeto>& novosProjetos) {
    this->projetos = novosProjetos;
}

vector<Projeto> Funcionario::getProjetos() const {
    return this->projetos;
}

Projeto Funcionario::getProjetoPorCodigo(const int codigo) const {
    for (const Projeto& p : projetos) {
        if (p.getCodigo() == codigo) {
            return p;
        }
    }
    throw std::runtime_error("Projeto com o código informado não encontrado.");
}


void Funcionario::adicionarProjeto(const Projeto& p) {
    projetos.push_back(p);
}