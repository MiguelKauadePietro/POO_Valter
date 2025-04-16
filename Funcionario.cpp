#include <bits/stdc++.h>
#include "Funcionario.h" //! Incluindo o corpo da classe

using namespace std;


Funcionario::Funcionario(int c, std::string n, int i)
    :codigo(c), nome(n), idade(i){}


void Funcionario::apresentar(){
    cout << "DADOS DO FUNCIONÁRIO" << endl;
    cout << "Código: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
}

void Funcionario::setCodigo(int c){
    this->codigo = c;
}

int Funcionario::getCodigo(){
    return codigo;
}

void Funcionario::setNome(std::string n){
    this->nome = n;
}

std::string Funcionario::getNome(){
    return nome;
}

void Funcionario::setIdade(int i){
    this->idade = i;
}

int Funcionario::getIdade(){
    return idade;
}

int main()
{
    //! Forma estática de instanciar uma classe
    // Funcionario Binho(1, "Binho", 19);
    // Binho.apresentar();

    //! Forma dinâmica de instanciar uma classe
    // Funcionario *Binho = new Funcionario(1, "Binho", 19);
    // Binho->apresentar();
    // delete Binho; //! Apagando o objeto alocado

    //! Exemplo:
    Funcionario c(1, "Carlos", 30);
    Funcionario r(2, "Roberta", 47);
    Funcionario v(3, "Valter", 50);

    c.apresentar();
    r.apresentar();
    v.apresentar();

    cin.get();

    c.setIdade(32);

    cout << "A idade do " << c.getNome() << " foi mudada para " << c.getIdade() << endl;

    return 0;
}
