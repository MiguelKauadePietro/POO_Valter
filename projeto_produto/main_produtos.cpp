#include <bits/stdc++.h>
// #include "Produto.h"
#include "Item.h"

using namespace std;

int main()
{

    Produto p1(1, "Monster de manga(Mango loko)", 7.45);
    Produto *p2 = new Produto(2, "NORGET DE FRANGO GRANDÃO", 4.50);

    item i1(19, 6, p1);
    item i2(19, 10, *p2); //* Cometi o erro de não usar o operador de "de referência", pois
    //* o construtor item espera um produto passado por referência, e como p2 é um ponteiro para produtos, eu teria que apontar para aquele endereço na hora de declarar os parâmetros nesse objeto i2

    //* Exibindo os itens atuais(não houve nenhuma modificação)
    i1.exibir_item();
    i2.exibir_item();

    //* ALTERAÇÕES
    p1.setCodigo(19);
    i1.setQuantidade(18);
    i1.setProduto(p1);

    i2.setNumero(20);
    p2->setCodigo(10);
    i2.setProduto(*p2);

    //! EXIBINDO AS ALTERAÇÕES FEITAS
    i1.exibir_item();
    i2.exibir_item();

    return 0;
}
