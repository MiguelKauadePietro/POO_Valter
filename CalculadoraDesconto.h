#ifndef CALCULADORADESCONTO_H
#define CALCULADORADESCONTO_H

#include "Pedido.h"

template <typename Strategy>
class CalculadoraDesconto {
public:
    static double calcular(const Pedido& pedido) {
        return Strategy::calcularDesconto(pedido);
    }
};

#endif
