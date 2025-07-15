#ifndef DESCONTOCLIENTEOURO_H
#define DESCONTOCLIENTEOURO_H

#include "Pedido.h"
#include "Fisico.h"
#include "Juridico.h"

class DescontoClienteOuro {
public:
    static double calcularDesconto(const Pedido& pedido) {
        float total = 0;

        // Reutiliza o método da classe Pedido
        pedido.calcularPrecoPedido(pedido.getItens(), total);

        // Aplica a nova regra de desconto
        if (total >= 1000) {
            return 0.10; // 10% de desconto
        }

        return 0.0;
    }
};

#endif
