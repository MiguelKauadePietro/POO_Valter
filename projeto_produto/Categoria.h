#include <bits/stdc++.h>
#ifndef CATEGORIA_H
#define CATEGORIA_H

using namespace std;

class Categoria{

    public:
        enum Valor{

            alimento, //* 0
            bebida, //* 1
            eletronico, //* 2
            vestuario, //* 3
            livro, //* 4
            limpeza //* 5
        };

        Categoria(Valor v): valor(v) {}

        Categoria(): valor(){} //* Inicializando a categoria como alimento por padrão;

        string categoriaToString() const{
            switch (valor)
            {
            case alimento: return "Alimento";
            case bebida: return "Bebida";
            case eletronico: return "Eletrônico";
            case vestuario: return "Vestuário";
            case livro: return "Livro";
            case limpeza: return "Limpeza";
            default: return "Categoria desconhecida";
            }
        }


    private:
        Valor valor;

};

#endif