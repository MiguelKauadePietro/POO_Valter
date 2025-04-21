#include <bits/stdc++.h>
// #include "Produto.h"
#include "Item.h"

using namespace std;

void exibirMenu() {
    cout << "\nMenu:\n";
    cout << "1. Cadastrar novo Produto\n";
    cout << "2. Alterar um Produto\n";
    cout << "3. Remover um Produto\n";
    cout << "4. Cadastrar um novo Pedido\n";
    cout << "5. Remover item de um Pedido\n";
    cout << "6. Adicionar itens a um Pedido\n";
    cout << "7. Listar todos os Pedidos\n";
    cout << "8. Listar todos os Produtos\n";
    cout << "9. Sair\n";
    cout << "Escolha uma opcao: ";
}

//* CADASTRANDO PRODUTOS
void cadastrarProduto(vector<Produto>& produtos){
    int codigo;
    string nome;
    float preco;

    cout << "Insira o código do Produto: " << endl;
    cin >> codigo;
    cin.ignore(); //! Limpando o buffer de entrada

    cout << "Insira o nome do Produto: " << endl;
    getline(cin, nome); //* utilizando o getline para pegar o nome(evitar outros erros relacionados ao buffer como ler uma linha vazia)

    cout << "Insira o preço do Produto: " << endl;
    cin >> preco;

    Produto novoProduto(codigo, nome, preco); //* Criando uma instância para a classe Produto com as variáveis criadas na função
    produtos.push_back(novoProduto);

    cout << "Produto cadastrado com sucesso!" << endl;
}

//* ALTERANDO PRODUTOS
void alterarProduto(vector<Produto>& produtos){
    int codigoAltProduto;

    cout << "Insira o código do produto que você deseja alterar: " << endl;
    cin >> codigoAltProduto;

    for(auto&p : produtos){ //* procurando o código solicitado no vetor de produtos, "auto" faz com que o tipo da variável p seja automaticamente definida(nesse caso, o tipo sera Produto)

        if(p.getCodigo() == codigoAltProduto){
            int codigo;
            string nome;
            float preco;

            cout << "Insira o novo código: " << endl;
            cin >> codigo;
            p.setCodigo(codigo);

            cout << "Insira o novo nome: " << endl;
            cin.ignore();
            getline(cin, nome);
            p.setNome(nome);

            cout << "Insira um novo preço: " << endl;
            cin >> preco;
            p.setPreco(preco);

            cout << "As informações do produto foram alteradas com sucesso!" << endl;

            return;
        }
        cout << "Produto não encontrado" << endl;
    }
}

//* REMOVENDO PRODUTOS
void removerProduto(vector<Produto>& produtos){
    int codigoRemProduto;

    cout << "Insira o código do produto que você deseja remover" << endl;
    cin >> codigoRemProduto;

    for(auto code = produtos.begin(); code != produtos.end(); ++code){ //* Utilizando um iterador para percorrer o vetor de produtos
        if(code->getCodigo() == codigoRemProduto){
            produtos.erase(code);
            cout << "Produto removido com sucesso!" << endl;
            return; //* MATANDO o loop quando achar o produto que deseja remover
        }
        cout << "Produto não encontrado" << endl;
    }
}

//* LISTANDO/VISUALIZANDO PRODUTOS
void listarProdutos(const vector<Produto>& produtos){
    cout << "Lista de Produtos: " << endl;

    for(const auto& p : produtos){
        p.apresentar_produto();
        cout << "---------------------" << endl;
    }
}

//* CADASTRANDO UM NOVO PEDIDO
void cadastrarPedido(vector<Item>& itens){
    if(itens.empty()){ //* VERIFICANDO SE ALGUM ITEM JÁ FOI CADASTRADO, PARA QUE EU POSSA CRIAR PEDIDOS
        cout << "Nenhum item cadastrado. Cadastre itens antes de criar pedidos.\n";
        return; //* SAI DA FUNÇÃO
    }

    int numeroItem;
    cout << "Insira o número do item no qual deseja adicionar um pedido" << endl;
    cin >> numeroItem;

    for(auto& i : itens){
        if(i.getNumero() == numeroItem){
            string descricao;
            int codigo;

            cout << "Insira o código do pedido: " << endl;
            cin >> codigo;

            cin.ignore();
            cout << "Insira uma descrição do pedido: " << endl;
            getline(cin, descricao);

            Pedido novoPedido(codigo, descricao);
            i.adicionarPedido(novoPedido);

            cout << "Pedido adicionado com sucesso ao item " << numeroItem << "!\n";
            return;
        }
    }

    cout << "Item com esse número não encontrado.\n"; //* Só é possível chegar aqui se não achou nenhum item condizente com o códigoItem
}

void removerItemPedido(vector<Item>& itens, vector<Pedido> pedidos){
    int codigoItem, codigoPedido;

    cout << "Exiba o código do item no qual deseja remover o pedido: " << endl;
    cin >> codigoItem;

    cout << "Exiba o código do pedido no qual deseja ser removido: " << endl;
    cin >> codigoPedido;

    for (auto& i : itens)
    {
        if(i.getNumero() == codigoItem){
            for (auto itP = pedidos.begin(); itP != pedidos.end(); ++itP)
            {
                if(itP->getCodigoPedido() == codigoPedido){
                    pedidos.erase(itP);
                    cout << "Pedido removido do item, cujo código é "<< codigoItem << " foi removido com sucesso!" << endl;
                    return;
                }
            }
            cout << "Pedido não encontrado dentro do item." << endl;
            return;
        }
    }

    cout << "Item com esse código não encontrado." << endl;
}

void adicionarItensPedidos(const vector<Item>& itens, vector<Pedido>& pedidos){
    int codigoPedido;
}





int main()
{

    // Produto p1(1, "Monster de manga(Mango loko)", 7.45);
    // Produto *p2 = new Produto(2, "NORGET DE FRANGO GRANDÃO", 4.50);

    // item i1(19, 6, p1);
    // item i2(19, 10, *p2); //* Cometi o erro de não usar o operador de "de referência", pois
    // //* o construtor item espera um produto passado por referência, e como p2 é um ponteiro para produtos, eu teria que apontar para aquele endereço na hora de declarar os parâmetros nesse objeto i2

    // //* Exibindo os itens atuais(não houve nenhuma modificação)
    // i1.exibir_item();
    // i2.exibir_item();

    // //* ALTERAÇÕES
    // p1.setCodigo(19);
    // i1.setQuantidade(18);
    // i1.setProduto(p1);

    // i2.setNumero(20);
    // p2->setCodigo(10);
    // i2.setProduto(*p2);

    // //! EXIBINDO AS ALTERAÇÕES FEITAS
    // i1.exibir_item();
    // i2.exibir_item();



    return 0;
}
