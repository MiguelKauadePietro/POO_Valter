#include <bits/stdc++.h>
#ifndef PRODUTO_NAO_ENCONTRADO_EXCEPTION_H
#define PRODUTO_NAO_ENCONTRADO_EXCEPTION_H


using namespace std;

class ProdutoNaoEncontradoException : public runtime_error {
public:
    ProdutoNaoEncontradoException()
        : runtime_error("Produto não encontrado no estoque.") {}
};

#endif
