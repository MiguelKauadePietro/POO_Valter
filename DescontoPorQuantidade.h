#include <bits/stdc++.h>
#include "Pedido.h"
#ifndef DESCONTOQTD_H
#define DESCONTOQTD_H

class DescontoPorQuantidade {
public:
    static double calcularDesconto(const Pedido& pedido) {
        int totalItens = 0;
        for (const auto& item : pedido.getItens()) {
            totalItens += item.getQuantidade();
        }

        if (totalItens >= 5) {
            return 0.05; // 5% de desconto
        }

        return 0.0;
    }
};


#endif