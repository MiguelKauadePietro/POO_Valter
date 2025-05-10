#include <bits/stdc++.h>
#include "Item.h"
#include "Pedido.h"
#include "Produto.h"
#include "Categoria.h"
#include "Cliente.h"

using namespace std;

//* Vetores globais (simples e diretos)
vector<Produto> produtos; //* Vetor de Produtos(armazenará os produtos cadastrados)
vector<Pedido> pedidos; //* Vetor de pedidos que armazenará os pedidos quando cadastrarmos pedidos
vector<Item> itens; //* Vetor de Itens que serão relacionados com pedidos
vector<Cliente> clientes; //* Vetor de Clientes que serão relacionados com pedidos

void exibirMenu() { //* Função que exibe o menu de opções
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
    cout << "Escolha uma opção: ";
}

//! CRIANDO UMA FUNÇÃO ONDE BUSCA A OCORRÊNCIA DE UM PRODUTO, ESSA FUNÇÃO RETORNA UM PONTEIRO, SE ACHAR O PRODUTO ELA RETORNA SEU ENDEREÇO, CASO NÃO ACHE ELA RETORNA UM PONTEIRO NULO(NULLPTR)
Produto* buscarProduto(int codigo) {
    for (auto& p : produtos)
        if (p.getCodigo() == codigo)
            return &p;
    return nullptr;
}

//! Função que cadastra um produto a partir do vetor global de produtos, nessa função ela pede os dados do produto(codigo, nome e preço) e no fim instancia um novo objeto de produto e "envia" essas variáveis para o construtor para serem inicializados e esse objeto é adicionado ao vetor de produtos.
void cadastrarProduto() {
    int codigo;
    string nome;
    float preco;
    int categoriaValor;

    cout << "Código do produto: ";
    cin >> codigo;

    if (buscarProduto(codigo)) {
        cout << "Produto com esse código já existe!\n";
        return;
    }

    cin.ignore();
    cout << "Nome do produto: ";
    getline(cin, nome);

    cout << "Preço: ";
    cin >> preco;

    cout << "Categoria (0-alimento, 1-bebida, 2-eletrônico, 3-vestuário, 4-livro, 5-limpeza): ";
    cin >> categoriaValor;
    Categoria categoria(static_cast<Categoria::Valor>(categoriaValor)); //! TRANSFORMANDO O VALOR ESCOLHIDO PARA UM TIPO DO ENUM

    Produto novo(codigo, nome, preco, categoria);
    produtos.push_back(novo);

    cout << "Produto cadastrado com sucesso!\n";
}

/* //!Alterando o produto, essa função entra com o código do produto que deseja alterar e     percorre o vetor de produtos até encontrá-lo, caso encontre, teremos que entrar com o novo código, preço e nome do produto

! a condição &outro != &p é para mostrar que o produto atual não é para ser comparado no caso de existir um mesmo código ou nome, isso mostra que o endereço de "outro" não pode ser o mesmo endereço do índice p, do primeiro for

*/
void alterarProduto() {
    int codigo;
    cout << "Código do produto a alterar: ";
    cin >> codigo;

    for (auto& p : produtos) {
        if (p.getCodigo() == codigo) {
            int novoCodigo;
            string nome;
            float preco;

            cout << "Novo código: ";
            cin >> novoCodigo;

            for (const auto& outro : produtos)
            {
                if (outro.getCodigo() == novoCodigo && &outro != &p)
                {
                    cout << "ERRO: Já existe um produto com este código!\n" << endl;
                    return;
                }
            }

            cin.ignore();

            cout << "Novo nome: ";
            getline(cin, nome);

            for (const auto& outro : produtos)
            {
                if (outro.getNome() == nome && &outro != &p){
                    cout << "ERRO: Já existe outro produto com esse mesmo nome" << endl;
                    return;
                }
            }

            cout << "Novo preço: ";
            cin >> preco;

            p.setCodigo(novoCodigo);
            p.setNome(nome);
            p.setPreco(preco);

            cout << "Produto alterado com sucesso!\n";
            return;
        }
    }
    cout << "Produto não encontrado.\n";
}

//! FUNÇÃO QUE REMOVE UM PRODUTO DO VETOR GLOBAL DE PRODUTOS A PARTIR DE SEU CÓDIGO, ISSO SE ESSE PRODUTO EXISTIR DENTRO DO VETOR, E TAMBÉM SE O VETOR CONTÉM PRODUTOS
void removerProduto() {

    if(produtos.empty()){
        cout << "Cadastre produtos primeiro antes de removê-los!\n" << endl;
        return;
    }

    int codigo;
    cout << "Código do produto a remover: ";
    cin >> codigo;

    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->getCodigo() == codigo) {
            produtos.erase(it);
            cout << "Produto removido com sucesso!\n";
            return;
        }
    }
    cout << "Produto não encontrado.\n";
}

//! FUNÇÃO QUE CADASTRA UM NOVO PEDIDO A PARTIR DO CADASTRO DE UM NOVO ITEM, QUE DEPENDE DO CADASTRO DE PRODUTOS
void cadastrarPedido() {
    int codigoProduto, quantidade, codPedido, qtdProdutos;
    float total;
    string descricao;

    
    cout << "Código do pedido: ";
    cin >> codPedido;
    cin.ignore();

    cout << "Descrição do pedido: ";
    getline(cin, descricao);

    cout << "Insira a quantidade de produtos que você deseja adicionar: ";
    cin >> qtdProdutos;



    for (int i = 0; i < qtdProdutos; i++)
    {

        cout << "Código do produto: ";
        cin >> codigoProduto;

        Produto* p = buscarProduto(codigoProduto);
        if (!p) {
            cout << "Produto não encontrado ou não está cadastrado, por favor cadastre este produto.\n";
            return;
        }

        cout << "Quantidade: ";
        cin >> quantidade;

        Item novoItem(i, quantidade, *p);
        itens.push_back(novoItem);
    }

    Pedido novoPedido(codPedido, descricao, itens);
    pedidos.push_back(novoPedido);

    cout << "Pedido cadastrado com sucesso!\n";
}

//! FUNÇÃO RESPONSÁVEL DE REMOVER UM ITEM DE UM PEDIDO, ISSO SE O VETOR DE ITENS NÃO ESTIVER VAZIO
void removerItemPedido() {

    if (itens.empty())
    {
        cout << "Cadastre itens antes de removê-los de pedidos!\n" << endl;
        return;
    }

    int numItem, codPedido;
    cout << "Número do item: ";
    cin >> numItem;
    cout << "Código do pedido a ser removido um item: ";
    cin >> codPedido;

    for (auto& p : pedidos) {
        if (p.getCodigoPedido() == codPedido) {
            vector<Item> itens = p.getItens();
            for (auto it = itens.begin(); it != itens.end(); ++it) {
                if (it->getNumero() == numItem) {
                    itens.erase(it);
                    p.setItens(itens);
                    cout << "Item removido do Pedido com sucesso!\n";
                    return;
                }
            }
            cout << "Pedido não encontrado nesse item.\n";
            return;
        }
    }
    cout << "Item não encontrado.\n";
}

//! FUNÇÃO RESPONSÁVEL POR ADICIONAR UM ITEM À UM PEDIDO
void adicionarItemPedido() {
    int numeroItem, codigoProduto, quantidade, codPedido;

    cout << "Código do pedido a adicionar um item: ";
    cin >> codPedido;

    for (auto& p : pedidos) {
        if (p.getCodigoPedido() == codPedido) {
            cout << "Número do item existente: ";
            cin >> numeroItem;
            cin.ignore();

            for (auto& i : itens)
            {
                if (i.getNumero() == numeroItem)
                {
                    Item novoItem(numeroItem, quantidade, i.getProduto());
                    p.adicionarItem(novoItem); //* FUNÇÃO DA CLASSE ITEM RESPOSÁVEL POR ADICIONAR PEDIDO
                }
            }
            cout << "Pedido adicionado ao item com sucesso!\n";
            return;
        }
    }

    cout << "Item não encontrado.\n";
}

//! FUNÇÃO RESPONSÁVEL POR LISTAR TODOS OS PEDIDOS REGISTRADOS, ISSO SE O VETOR DE ITENS NÃO ESTIVER VAZIO
void listarPedidos() {
    if (pedidos.empty()) {
        cout << "Nenhum pedido registrado.\n";
        return;
    }

    for (const auto& p : pedidos) {
        p.imprimindo_pedido();
    }
}

//! FUNÇÃO RESPONSÁVEL POR LISTAR TODOS OS PRODUTOS REGISTRADOS, ISSO SE O VETOR DE PRODUTOS NÃO ESTIVER VAZIO
void listarProdutos() {
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado.\n";
        return;
    }

    for (const auto& p : produtos) {
        p.apresentar_produto();
        cout << "----------------------\n";
    }
}

//! MAIN
int main() {
    int opcao;

    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarProduto(); 
            break;
            case 2: alterarProduto(); 
            break;
            case 3: removerProduto(); 
            break;
            case 4: cadastrarPedido(); 
            break;
            case 5: removerItemPedido(); 
            break;
            case 6: adicionarItemPedido(); 
            break;
            case 7: listarPedidos(); 
            break;
            case 8: listarProdutos(); 
            break;
            case 9: cout << "Saindo do sistema...\n"; break;
            default: cout << "Opção inválida.\n";
        }

    } while (opcao != 9);

    return 0;
}
