#include <bits/stdc++.h>
#include "Item.h"
#include "Pedido.h"
#include "Produto.h"
#include "Categoria.h"
#include "Cliente.h"
#include "Fisico.h"
#include "Juridico.h"
#include "Endereco.h"
#include "Estoque.h"
#include "DescontoClienteOuro.h"
#include "DescontoPorQuantidade.h"
#include "CalculadoraDesconto.h"
#include "EstoqueInsuficienteException.h"
#include "ProdutoNaoEncontradoException.h"

using namespace std;

//* Vetores globais (simples e diretos)
// vector<Produto> produtos; //* Vetor de Produtos(armazenará os produtos cadastrados)
Estoque estoque; //* Substituindo vetor de produtos por esse objeto da classe Estoque(onde tem um vector de produtos e um vector de inteiros referentes às quantidades desses produtos)
vector<Pedido> pedidos; //* Vetor de pedidos que armazenará os pedidos quando cadastrarmos pedidos
vector<Cliente*> clientes; //* Vetor de ponteiro para Clientes(motivo: temos uma herança)

void exibirMenu() { //* Função que exibe o menu de opções
    cout << "\nMenu:\n";
    cout << "1. Cadastrar um novo Produto no estoque\n";
    cout << "2. Alterar um Produto\n";
    cout << "3. Remover um Produto\n";
    cout << "4. Cadastrar um novo Pedido\n";
    cout << "5. Remover item de um Pedido\n";
    cout << "6. Adicionar itens a um Pedido\n";
    cout << "7. Listar todos os Pedidos\n";
    cout << "8. Listar o Estoque\n";
    cout << "9. Cadastrar um novo Cliente\n";
    cout << "10. Listar Clientes\n";
    cout << "11. Ver Descontos no último Pedido\n";
    cout << "12. Sair\n";
    cout << "Escolha uma opção: ";
}


#pragma region Funções de Produtos

//! CRIANDO UMA FUNÇÃO ONDE BUSCA A OCORRÊNCIA DE UM PRODUTO, ESSA FUNÇÃO RETORNA UM PONTEIRO, SE ACHAR O PRODUTO ELA RETORNA SEU ENDEREÇO, CASO NÃO ACHE ELA RETORNA UM PONTEIRO NULO(NULLPTR)
Produto* buscarProduto(int codigo) {
    return estoque.buscarProdutoPorCodigo(codigo);
}

//! Função que cadastra um produto a partir do vetor global de produtos, nessa função ela pede os dados do produto(codigo, nome e preço) e no fim instancia um novo objeto de produto e "envia" essas variáveis para o construtor para serem inicializados e esse objeto é adicionado ao vetor de produtos.
void cadastrarProduto() {
    int codigo;
    string nome;
    float preco;
    int categoriaValor;
    int qtd;

    // cout << "Código do produto: ";
    // cin >> codigo;

    // if (buscarProduto(codigo)) {
        //     cout << "Produto com esse código já existe!\n";
        //     return;
        // }

    codigo = Produto::gerarCodigoProduto();

    cin.ignore();
    cout << "Nome do produto: ";
    getline(cin, nome);

    cout << "Preço: ";
    cin >> preco;

    cout << "Categoria (0-alimento, 1-bebida, 2-eletrônico, 3-vestuário, 4-livro, 5-limpeza): ";
    cin >> categoriaValor;
    Categoria categoria(static_cast<Categoria::Valor>(categoriaValor)); //! TRANSFORMANDO O VALOR ESCOLHIDO PARA UM TIPO DO ENUM

    Produto novo(codigo, nome, preco, categoria);

    cout << "Quantidade inicial no estoque: " << endl;
    cin >> qtd;

    estoque.adicionarProduto(novo, qtd);
    cout << "Produto cadastrado com sucesso!\n";
}

/* //!Alterando o produto, essa função entra com o código do produto que deseja alterar e     percorre o vetor de produtos até encontrá-lo, caso encontre, teremos que entrar com o novo código, preço e nome do produto

! a condição &outro != &p é para mostrar que o produto atual não é para ser comparado no caso de existir um mesmo código ou nome, isso mostra que o endereço de "outro" não pode ser o mesmo endereço do índice p, do primeiro for

*/
void alterarProduto() {
    int codigo;
    cout << "Código do produto a alterar: ";
    cin >> codigo;

    Produto* p = buscarProduto(codigo);
    if (!p) {
        cout << "Produto não encontrado.\n";
        return;
    }

    int novoCodigo;
    string nome;
    float preco;

    cout << "Novo código: ";
    cin >> novoCodigo;

    Produto* existente = buscarProduto(novoCodigo);
    if (existente && existente != p) {
        cout << "ERRO: Já existe um produto com este código!\n";
        return;
    }

    cin.ignore();
    cout << "Novo nome: ";
    getline(cin, nome);

    for (const auto& prod : estoque.getProdutos()) {
        if (prod.getNome() == nome && &prod != p) {
            cout << "ERRO: Já existe outro produto com esse mesmo nome.\n";
            return;
        }
    }

    cout << "Novo preço: ";
    cin >> preco;

    // Novo produto atualizado
    Produto atualizado(novoCodigo, nome, preco, p->getCategoria());

    // Atualiza o produto no estoque
    bool sucesso = estoque.atualizarProduto(codigo, atualizado);
    if (!sucesso) {
        cout << "Erro ao atualizar o produto no estoque.\n";
        return;
    }

    // Quantidade (após atualizar o produto)
    int novaQuantidade;
    cout << "Deseja alterar a quantidade? (digite -1 para manter): ";
    cin >> novaQuantidade;

    if (novaQuantidade >= 0) {
        estoque.atualizarQuantidadePorCodigo(novoCodigo, novaQuantidade);
    }

    cout << "Produto alterado com sucesso!\n";
}

//! FUNÇÃO QUE REMOVE UM PRODUTO DO VETOR GLOBAL DE PRODUTOS A PARTIR DE SEU CÓDIGO, ISSO SE ESSE PRODUTO EXISTIR DENTRO DO VETOR, E TAMBÉM SE O VETOR CONTÉM PRODUTOS
void removerProduto() {
    if (estoque.vazio()) {
        cout << "Cadastre produtos no estoque primeiro antes de removê-los!\n" << endl;
        return;
    }

    int codigo;
    cout << "Código do produto a remover: ";
    cin >> codigo;

    bool removido = estoque.removerProdutoPorCodigo(codigo);
    if (removido) {
        cout << "Produto removido com sucesso!\n";
    } else {
        cout << "Produto não encontrado.\n";
    }
}

//! FUNÇÃO RESPONSÁVEL POR LISTAR TODOS OS PRODUTOS REGISTRADOS, ISSO SE O VETOR DE PRODUTOS NÃO ESTIVER VAZIO
void listarProdutosNoEstoque() {
    if (estoque.vazio()) {
        cout << "Nenhum produto cadastrado no estoque.\n";
        return;
    }

    const vector<Produto>& produtos = estoque.getProdutos();
    const vector<int>& quantidades = estoque.getQuantidade();

    Produto maisBarato = produtos[0];
    Produto maisCaro = produtos[0];

    estoque.listarEstoque();

    //! Utilizando os operadores sobrecarregados "<" e ">" para achar o produto mais barato e o mais caro

    for (const auto& p : produtos) {
        if (p < maisBarato) maisBarato = p;
        if (p > maisCaro) maisCaro = p;
    }

    cout << "\nResumo de preços:\n";
    cout << "Produto mais barato: " << maisBarato.getNome() << " - R$ " << fixed << setprecision(2) << maisBarato.getPreco() << endl;

    cout << "Produto mais caro: " << maisCaro.getNome() << " - R$ " << fixed << setprecision(2) << maisCaro.getPreco() << endl;
    cout << "----------------------\n";
}

#pragma endregion

#pragma region Funções de Pedidos, Itens e clientes(relacionamento também)

Cliente* buscarCliente(int codigoCliente){
    for (auto& c : clientes)
    {
        if(c->getCodigo() == codigoCliente){
            return c;
        }
    }
    return nullptr;
}

//! FUNÇÃO QUE CADASTRA UM NOVO PEDIDO A PARTIR DO CADASTRO DE UM NOVO ITEM, QUE DEPENDE DO CADASTRO DE PRODUTOS(Agora depende também do cadastro do Cliente)
void cadastrarPedido() {
    int codigoProduto, quantidade, codPedido, qtdProdutos, codCliente, codItem;
    float total;
    string descricao;
    vector<Item> itensPedido;

    codPedido = Pedido::gerarCodigoPedido();
    cin.ignore();

    cout << "Descrição do pedido: ";
    getline(cin, descricao);

    cout << "Código do cliente associado ao pedido: ";
    cin >> codCliente;

    Cliente* cliente = buscarCliente(codCliente);
    if (!cliente) {
        cout << "Cliente não encontrado. Pedido não será cadastrado.\n";
        return;
    }

    cout << "Insira a quantidade de itens que você deseja adicionar: ";
    cin >> qtdProdutos;

    try {
        for (int i = 0; i < qtdProdutos; i++) {
            codItem = Item::gerarNumeroItem();

            cout << "Código do produto: ";
            cin >> codigoProduto;

            Produto* p = estoque.buscarProdutoPorCodigo(codigoProduto);

            cout << "Quantidade: ";
            cin >> quantidade;

            int quantidadeDisponivel = estoque.consultarQuantidade(*p);

            if (quantidadeDisponivel < quantidade) {
                throw EstoqueInsuficienteException();
            }

            // Criação e adição do item
            Item novoItem(codItem, quantidade, *p);

            bool jaExiste = false;
            for (auto& item : itensPedido) {
                if (item.getProduto() == novoItem.getProduto()) {
                    item = item + quantidade;  // operador + do Item
                    jaExiste = true;
                    break;
                }
            }

            if (!jaExiste) {
                itensPedido.push_back(novoItem);
            }

            // Atualiza o estoque (subtrai)
            estoque.atualizarQuantidade(*p, quantidadeDisponivel - quantidade);
        }

        Pedido novoPedido(codPedido, descricao, itensPedido, cliente);
        pedidos.push_back(novoPedido);

        cout << "Pedido cadastrado com sucesso!\n";
    }
    catch (const ProdutoNaoEncontradoException& e) {
        cout << "Erro: " << e.what() << endl;
        return;
    }
    catch (const EstoqueInsuficienteException& e) {
        cout << "Erro: " << e.what() << endl;
        return;
    }
}



//! FUNÇÃO RESPONSÁVEL DE REMOVER UM ITEM DE UM PEDIDO, ISSO SE O VETOR DE ITENS NÃO ESTIVER VAZIO
void removerItemPedido() {
    int numItem, codPedido;
    cout << "Código do pedido a ser removido um item: ";
    cin >> codPedido;

    cout << "Número do item: ";
    cin >> numItem;

    for (auto& pedido : pedidos) {
        if (pedido.getCodigoPedido() == codPedido) {

            vector<Item> itens = pedido.getItens();

            if (itens.empty()) {
                cout << "Este pedido não possui itens.\n";
                return;
            }

            for (auto it = itens.begin(); it != itens.end(); ++it) {
                if (it->getNumero() == numItem) {
                    Item itemParaRemover = *it;

                    //* Restaura a quantidade ao estoque
                    Produto produto = itemParaRemover.getProduto();
                    int quantidadeAtual = estoque.consultarQuantidade(produto);
                    int quantidadeRemovida = itemParaRemover.getQuantidade();

                    estoque.atualizarQuantidade(produto, quantidadeAtual + quantidadeRemovida);

                    //* Remove o item do pedido
                    pedido = pedido - itemParaRemover;

                    cout << "Item removido do Pedido com sucesso!\n";
                    return;
                }
            }

            cout << "Item não encontrado nesse pedido.\n";
            return;
        }
    }

    cout << "Pedido não encontrado.\n";
}


//! FUNÇÃO RESPONSÁVEL POR ADICIONAR UM ITEM À UM PEDIDO
void adicionarItemPedido() {
    int numeroItem, codigoProduto, quantidade, codPedido;

    cout << "Código do pedido ao qual deseja adicionar um item: ";
    cin >> codPedido;

    for (auto& pedido : pedidos) {
        if (pedido.getCodigoPedido() == codPedido) {

            try {
                cout << "Código do produto a adicionar: ";
                cin >> codigoProduto;

                Produto* produto = estoque.buscarProdutoPorCodigo(codigoProduto);

                cout << "Quantidade: ";
                cin >> quantidade;

                int qtdDisponivel = estoque.consultarQuantidade(*produto);

                if (qtdDisponivel < quantidade) {
                    throw EstoqueInsuficienteException();
                }

                // Verifica se item já existe no pedido
                bool itemExistente = false;
                for (int i = 0; i < pedido.getItens().size(); ++i) {
                    if (pedido[i].getProduto() == *produto) {
                        pedido[i] = pedido[i] + quantidade;
                        itemExistente = true;
                        break;
                    }
                }

                if (!itemExistente) {
                    numeroItem = Item::gerarNumeroItem();
                    Item novoItem(numeroItem, quantidade, *produto);
                    pedido = pedido + novoItem;
                }

                // Atualiza o estoque (subtrai)
                estoque.atualizarQuantidade(*produto, qtdDisponivel - quantidade);

                cout << "Item adicionado ao pedido com sucesso!\n";
                return;
            }
            catch (const ProdutoNaoEncontradoException& e) {
                cout << "Erro: " << e.what() << endl;
                return;
            }
            catch (const EstoqueInsuficienteException& e) {
                cout << "Erro: " << e.what() << endl;
                return;
            }
        }
    }

    cout << "Pedido não encontrado.\n";
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

Cliente *cadastrarCliente(){
    int tipoCliente;
    int codigoCliente;
    string nomeCliente;

    //! Cadastro genérico

    cout << "Selecione o tipo de cliente que você deseja cadastrar(1 = Físico, 2 = Jurídico): ";
    cin >> tipoCliente;
    cin.ignore();


    codigoCliente = Cliente::gerarCodigoCliente();

    cout << "Insira o nome do cliente: ";
    getline(cin, nomeCliente);

    //* Cadastro do endereço

    string rua, bairro, cidade;
    int numeroCasa;

    cout << "Cadastro do endereço: " << endl;
    cout << "Insira a Rua: ";
    getline(cin, rua);

    cout << "Insira o Bairro: ";
    getline(cin, bairro);

    cout << "Insira a Cidade: ";
    getline(cin, cidade);

    cout << "Insira o Número da casa: ";
    cin >> numeroCasa;
    cin.ignore();

    Endereco endereco(rua, numeroCasa, bairro, cidade);

    if (tipoCliente == 1)
    {
        string cpf;

        cout << "Insira o CPF: ";
        getline(cin, cpf);

        Cliente* novo = new Fisico(codigoCliente, nomeCliente, endereco, cpf);
        clientes.push_back(novo);

        cout << "Cliente cadastrado com sucesso" << endl;

        return novo;
    }else if(tipoCliente == 2){
        string cnpj;

        cout << "Insira o CNPJ: ";
        getline(cin, cnpj);

        Cliente* novo = new Juridico(codigoCliente, nomeCliente, endereco, cnpj);
        clientes.push_back(novo);

        cout << "\nCliente cadastrado com sucesso" << endl;

        return novo;
    }else{
        cout << "Tipo inválido" << endl;
        return nullptr;
    }

}

void listarClientes(){
    int i = 1;
    if (clientes.empty())
    {
        cout << "Nenhum cliente cadastrado!" << endl;
        return;
    }

    cout << "\n=== Lista de Clientes cadastrados ===\n" << endl;

    for (auto& c : clientes)
    {
        cout << "Cliente " << i << ":" << endl;
        c->mostrarDados();
        i++;
        cout << endl;
    }
}

void verDescontosUltimoPedido() {
    if (pedidos.empty()) {
        cout << "Nenhum pedido cadastrado.\n";
        return;
    }

    Pedido& p = pedidos.back();

    double descOuro = CalculadoraDesconto<DescontoClienteOuro>::calcular(p);
    double descQtd  = CalculadoraDesconto<DescontoPorQuantidade>::calcular(p);

    cout << "Desconto Cliente Ouro: " << descOuro * 100 << "%" << endl;
    cout << "Desconto por Quantidade: " << descQtd * 100 << "%" << endl;
}


#pragma endregion

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
            case 8: listarProdutosNoEstoque();
            break;
            case 9: cadastrarCliente();
            break;
            case 10: listarClientes();
            break;
            case 11: verDescontosUltimoPedido();
            break;
            case 12: cout << "Saindo do sistema...\n";
            break;
            default: cout << "Opção inválida.\n";
        }

    } while (opcao != 12);

    for (Cliente* c : clientes) {
        delete c;
    }
    clientes.clear();

    return 0;
}

//! Adicionar um estoque para manipulação dos produtos da maneira correta