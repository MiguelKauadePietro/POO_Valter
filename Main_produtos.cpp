#include <bits/stdc++.h>
#include "Item.h"
#include "Pedido.h"
#include "Produto.h"
#include "Categoria.h"
#include "Cliente.h"
#include "Fisico.h"
#include "Juridico.h"
#include "Endereco.h"

using namespace std;

//* Vetores globais (simples e diretos)
vector<Produto> produtos; //* Vetor de Produtos(armazenará os produtos cadastrados)
vector<Pedido> pedidos; //* Vetor de pedidos que armazenará os pedidos quando cadastrarmos pedidos
vector<Cliente*> clientes; //* Vetor de ponteiro para Clientes(motivo: temos uma herança)

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
    cout << "9. Cadastrar um novo Cliente\n";
    cout << "10. Listar Clientes\n";
    cout << "11. Sair\n";
    cout << "Escolha uma opção: ";
}

//* Funções Estáticas poderosas para evitar digitação de um campo importante como o "código" e assim evitando o erro humano
int gerarCodigoCliente(){
    static int proximoCodigo = 1; //! Usando uma variável "static" para manter o valor do código do cliente na memória
    return proximoCodigo++; //! Depois retorno este código, depois de retornado incremento ele, e como é static, vai manter o valor incrementado, assim evitamos os erros de códigos repetidos pelo erro do user(desprovido de inteligência)
}

//! Gerando código do produto automaticamente
int gerarCodigoProduto() {
    static int codigo = 1;
    return codigo++;
}

//! Gerando código do pedido automaticamente
int gerarCodigoPedido() {
    static int codigo = 1;
    return codigo++;
}

//! Gerando código do item automaticamente
int gerarCodigoItem(){
    static int codigo = 1;
    return codigo++;
}

#pragma region Funções de Produtos

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

    // cout << "Código do produto: ";
    // cin >> codigo;

    // if (buscarProduto(codigo)) {
        //     cout << "Produto com esse código já existe!\n";
        //     return;
        // }

    codigo = gerarCodigoProduto();

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

    
    // cout << "Código do pedido: ";
    // cin >> codPedido;
    // cin.ignore();

    codPedido = gerarCodigoPedido();
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

    cout << "Insira a quantidade de produtos que você deseja adicionar: ";
    cin >> qtdProdutos;



    for (int i = 0; i < qtdProdutos; i++)
    {
        codItem = gerarCodigoItem();

        cout << "Código do produto: ";
        cin >> codigoProduto;

        Produto* p = buscarProduto(codigoProduto);
        if (!p) {
            cout << "Produto não encontrado ou não está cadastrado, por favor cadastre este produto.\n";
            return;
        }

        cout << "Quantidade: ";
        cin >> quantidade;

        Item novoItem(codItem, quantidade, *p);
        itensPedido.push_back(novoItem);
    }

    Pedido novoPedido(codPedido, descricao, itensPedido, cliente);
    pedidos.push_back(novoPedido);


    cout << "Pedido cadastrado com sucesso!\n";
}

//! FUNÇÃO RESPONSÁVEL DE REMOVER UM ITEM DE UM PEDIDO, ISSO SE O VETOR DE ITENS NÃO ESTIVER VAZIO
void removerItemPedido() {

    int numItem, codPedido;
    cout << "Número do item: ";
    cin >> numItem;
    cout << "Código do pedido a ser removido um item: ";
    cin >> codPedido;

    for (auto& p : pedidos) {
        if (p.getCodigoPedido() == codPedido) {
            vector<Item> itens = p.getItens();

            if (itens.empty())
            {
                cout << "Cadastre itens antes!\n" << endl;
                return;
            }

            for (auto it = itens.begin(); it != itens.end(); ++it) {
                if (it->getNumero() == numItem) {
                    itens.erase(it);
                    p.setItens(itens);
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

    cout << "Código do pedido a adicionar um item: ";
    cin >> codPedido;

    for (auto& p : pedidos) {
        if (p.getCodigoPedido() == codPedido) {
            cout << "Código do produto a adicionar: ";
            cin >> codigoProduto;

            Produto* produto = buscarProduto(codigoProduto);
            if (!produto) {
                cout << "Produto não encontrado.\n";
                return;
            }

            cout << "Quantidade: ";
            cin >> quantidade;

            // Número do item é o próximo da sequência
            int numeroItem = p.getItens().size() + 1;

            Item novoItem(numeroItem, quantidade, *produto);
            p.adicionarItem(novoItem);

            cout << "Item adicionado ao pedido com sucesso!\n";
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

Cliente *cadastrarCliente(){
    int tipoCliente;
    int codigoCliente;
    string nomeCliente;

    //! Cadastro genérico

    cout << "Selecione o tipo de cliente que você deseja cadastrar(1 = Físico, 2 = Jurídico): ";
    cin >> tipoCliente;
    cin.ignore();

    //! Método 1:
    // cout << "Insira o código do cliente que você deseja cadastrar: " << endl;
    // cin >> codigoCliente;

    // if (buscarCliente(codigoCliente))
    // {
    //     cout << "Cliente com este código já existe no sistema!\n" << endl;
    //     return;
    // }

    //! Método 2:
    codigoCliente = gerarCodigoCliente();

    cout << "Insira o nome do cliente: ";
    getline(cin, nomeCliente);

    //* Cadastro do endereço

    string rua, bairro, cidade;
    int numeroCasa;

    cout << "Cadastro do endereço: ";
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
    if (clientes.empty())
    {
        cout << "Nenhum cliente cadastrado!" << endl;
        return;
    }

    cout << "\n=== Lista de Clientes cadastrados ===\n" << endl;
    
    for (auto& c : clientes)
    {
        c->mostrarDados();
        cout << endl;
    }
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
            case 8: listarProdutos();
            break;
            case 9: cadastrarCliente();
            break;
            case 10: listarClientes();
            break;
            case 11: cout << "Saindo do sistema...\n";
            break;
            default: cout << "Opção inválida.\n";
        }

    } while (opcao != 11);

    for (Cliente* c : clientes) {
        delete c;
    }
    clientes.clear();

    return 0;
}
