#include <bits/stdc++.h>
#ifndef ESTOQUE_INSUFICIENTE_EXCEPTION_H
#define ESTOQUE_INSUFICIENTE_EXCEPTION_H

using namespace std;

class EstoqueInsuficienteException : public runtime_error {
public:
    EstoqueInsuficienteException()
        : runtime_error("Estoque insuficiente para o produto.") {}
};

#endif