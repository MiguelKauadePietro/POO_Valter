#include "Endereco.h"
#include <iostream>

using namespace std;

    Endereco::Endereco() {}

    Endereco::Endereco(const string rua, const string cidade, const string estado, const string cep)
        : rua(rua), cidade(cidade), estado(estado), cep(cep) {}

    void Endereco::exibirEndereco() const {
    
        std::cout << "Endereco: " << rua << ", " << cidade << " - " << estado << ", " << cep << endl;
    }
    
    
    void Endereco::setRua(const string novaRua){
        this->rua = novaRua;
    }
    
    string Endereco::getRua(){
        return this->rua;
    }
    
    void Endereco::setCidade(const string cidade){
         this->cidade = cidade;
    }
    
    string Endereco::getCidade(){
        return this->cidade;
    }
    
    void Endereco::setEstado(const string estado){
        this->estado = estado;
    }
    
    string Endereco::getEstado(){
        return this->estado;
    }
    
    void Endereco::setCep(const string cep){
        this->cep = cep;
    }
    
    string Endereco::getCep(){
        return this->cep;
    }
    
    
    
    
    
    
    
    
    