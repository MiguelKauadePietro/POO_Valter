#include <iostream>
#include <string>
using namespace std;

class Cargo {


public:
    enum Valor {
        CEO,
        CTO,
        Secretaria,
        Presidente,
        Estagiario
    };

 private:
    Valor valor;


public:
    
    Cargo(Valor v) : valor(v) {}
    
    Cargo() : valor() {}  //construtor padrão
    
   
    
    string toString() const {
        switch (valor) {
            case CEO: return "CEO";
            case CTO: return "CTO";
            case Secretaria: return "Secretária";
            case Presidente: return "Presidente";
            case Estagiario: return "Estagiário";
            default: return "Desconhecido";
        }
    }

    // operador de comparação se quiser usar em ifs
    //bool operator==(const Cargo& outro) const {
    //    return valor == outro.valor;
    //}

 


};
