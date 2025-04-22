#include <bits/stdc++.h>
#include "Item.h"

using namespace std;

//* Vetores globais (simples e diretos)
vector<Produto> produtos; //* Vetor de Produtos(armazenará os produtos cadastrados)
vector<Item> itens; //* Vetor de itens que armazenará os itens quando cadastrarmos pedidos

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

Produto* buscarProduto(int codigo) { //* CRIANDO UMA FUNÇÃO ONDE BUSCA A OCORRÊNCIA DE UM PRODUTO, ESSA FUNÇÃO RETORNA UM PONTEIRO, SE ACHAR O PRODUTO ELA RETORNA SEU ENDEREÇO, CASO NÃO ACHE ELA RETORNA UM PONTEIRO NULO(NULLPTR)
    for (auto& p : produtos)
        if (p.getCodigo() == codigo)
            return &p;
    return nullptr;
}

//* Função que cadastra um produto a partir do vetor global de produtos, nessa função ela pede os dados do produto(codigo, nome e preço) e no fim instancia um novo objeto de produto e "envia" essas variáveis para o construtor para serem inicializados e esse objeto é adicionado ao vetor de produtos.
void cadastrarProduto() {
    int codigo;
    string nome;
    float preco;

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

    Produto novo(codigo, nome, preco);
    produtos.push_back(novo);

    cout << "Produto cadastrado com sucesso!\n";
}

/* //*Alterando o produto, essa função entra com o código do produto que deseja alterar e     percorre o vetor de produtos até encontrá-lo, caso encontre, teremos que entrar com o novo código, preço e nome do produto

* a condição &outro != &p é para mostrar que o produto atual não é para ser comparado no caso de existir um mesmo código ou nome, isso mostra que o endereço de "outro" não pode ser o mesmo endereço do índice p, do primeiro for

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
                    cout << "ERRO: Já existe outro produto com esse mesmo código" << endl;
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

//* FUNÇÃO QUE REMOVE UM PRODUTO DO VETOR GLOBAL DE PRODUTOS A PARTIR DE SEU CÓDIGO, ISSO SE ESSE PRODUTO EXISTIR DENTRO DO VETOR, E TAMBÉM SE O VETOR CONTÉM PRODUTOS
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

//* FUNÇÃO QUE CADASTRA UM NOVO PEDIDO A PARTIR DO CADASTRO DE UM NOVO ITEM, QUE DEPENDE DO CADASTRO DE PRODUTOS
void cadastrarPedido() {
    int numeroItem, codigoProduto, quantidade, codPedido, categoriaValor;
    string descricao;

    cout << "Número do novo item: ";
    cin >> numeroItem;

    cout << "Código do produto: ";
    cin >> codigoProduto;

    Produto* p = buscarProduto(codigoProduto);
    if (!p) {
        cout << "Produto não encontrado.\n";
        return;
    }

    cout << "Quantidade: ";
    cin >> quantidade;

    cout << "Categoria (0-alimento, 1-bebida, 2-eletrônico, 3-vestuário, 4-livro, 5-limpeza): ";
    cin >> categoriaValor;
    Categoria categoria(static_cast<Categoria::Valor>(categoriaValor)); //* TRANSFORMANDO O VALOR ESCOLHIDO PARA UM TIPO DO ENUM

    cout << "Código do pedido: ";
    cin >> codPedido;
    cin.ignore();
    cout << "Descrição do pedido: ";
    getline(cin, descricao);

    Pedido novoPedido(codPedido, descricao);

    Item novoItem(numeroItem, quantidade, *p, categoria);
    novoItem.adicionarPedido(novoPedido);
    itens.push_back(novoItem);

    cout << "Pedido cadastrado com sucesso!\n";
}

//* FUNÇÃO RESPONSÁVEL DE REMOVER UM ITEM DE UM PEDIDO, ISSO SE O VETOR DE ITENS NÃO ESTIVER VAZIO
void removerItemPedido() {

    if (itens.empty())
    {
        cout << "Cadastre itens antes de removê-los de pedidos!\n" << endl;
        return;
    }

    int numItem, codPedido;
    cout << "Número do item: ";
    cin >> numItem;
    cout << "Código do pedido a remover: ";
    cin >> codPedido;

    for (auto& i : itens) {
        if (i.getNumero() == numItem) {
            vector<Pedido> pedidos = i.getPedidos();
            for (auto it = pedidos.begin(); it != pedidos.end(); ++it) {
                if (it->getCodigoPedido() == codPedido) {
                    pedidos.erase(it);
                    i.setPedidos(pedidos);
                    cout << "Pedido removido do item com sucesso!\n";
                    return;
                }
            }
            cout << "Pedido não encontrado nesse item.\n";
            return;
        }
    }
    cout << "Item não encontrado.\n";
}

//* FUNÇÃO RESPONSÁVEL POR ADICIONAR UM ITEM À UM PEDIDO
void adicionarItemPedido() {
    int numeroItem, codigoProduto, quantidade, codPedido, categoriaValor;
    string descricao;

    cout << "Número do item existente: ";
    cin >> numeroItem;

    for (auto& i : itens) {
        if (i.getNumero() == numeroItem) {
            cout << "Código do pedido a adicionar: ";
            cin >> codPedido;
            cin.ignore();
            cout << "Descrição do pedido: ";
            getline(cin, descricao);

            Pedido novoPedido(codPedido, descricao);
            i.adicionarPedido(novoPedido); //* FUNÇÃO DA CLASSE ITEM RESPOSÁVEL POR ADICIONAR PEDIDO

            cout << "Pedido adicionado ao item com sucesso!\n";
            return;
        }
    }

    cout << "Item não encontrado.\n";
}

//* FUNÇÃO RESPONSÁVEL POR LISTAR TODOS OS PEDIDOS REGISTRADOS, ISSO SE O VETOR DE ITENS NÃO ESTIVER VAZIO
void listarPedidos() {
    if (itens.empty()) {
        cout << "Nenhum pedido registrado.\n";
        return;
    }

    for (auto& item : itens) {
        item.exibir_item();
    }
}

//* FUNÇÃO RESPONSÁVEL POR LISTAR TODOS OS PRODUTOS REGISTRADOS, ISSO SE O VETOR DE PRODUTOS NÃO ESTIVER VAZIO
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

//* MAIN
int main() {
    int opcao;

    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: alterarProduto(); break;
            case 3: removerProduto(); break;
            case 4: cadastrarPedido(); break;
            case 5: removerItemPedido(); break;
            case 6: adicionarItemPedido(); break;
            case 7: listarPedidos(); break;
            case 8: listarProdutos(); break;
            case 9: cout << "Saindo do sistema...\n"; break;
            default: cout << "Opção inválida.\n";
        }

    } while (opcao != 9);

    return 0;
}

#pragma region 

/*

#include <bits/stdc++.h>
#include "Produto.h"
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

    Produto p1(1, "Monster de manga(Mango loko)", 7.45);
    Produto *p2 = new Produto(2, "NORGET DE FRANGO GRANDÃO", 4.50);

    item i1(19, 6, p1);
    item i2(19, 10, *p2); //* Cometi o erro de não usar o operador de "de referência", pois
    * o construtor item espera um produto passado por referência, e como p2 é um ponteiro para produtos, eu teria que apontar para aquele endereço na hora de declarar os parâmetros nesse objeto i2

    * Exibindo os itens atuais(não houve nenhuma modificação)
    i1.exibir_item();
    i2.exibir_item();

    * ALTERAÇÕES
    p1.setCodigo(19);
    i1.setQuantidade(18);
    i1.setProduto(p1);

    i2.setNumero(20);
    p2->setCodigo(10);
    i2.setProduto(*p2);

    ! EXIBINDO AS ALTERAÇÕES FEITAS
    i1.exibir_item();
    i2.exibir_item();



    return 0;
}

*/

#pragma endregion
