#include <iostream>
#include <vector>
#include <string>
#include "Funcionario.h"
#include "Projeto.h"  // Novo include
using namespace std;

void exibirMenu() {
    cout << "\nMenu:\n";
    cout << "1. Cadastrar novo funcionário\n";
    cout << "2. Alterar funcionário\n";
    cout << "3. Remover funcionário\n";
    cout << "4. Listar todos os funcionários\n";
    cout << "5. Adicionar projeto a um funcionário\n";  // Nova opção
    cout << "6. Sair\n";
    cout << "Escolha uma opcao: ";
}

void cadastrarFuncionario(vector<Funcionario>& funcionarios) {
    int codigo, idade, cargoOpcao;
    string nome, rua, cidade, estado, cep;

    cout << "Digite o codigo: ";
    cin >> codigo;
    cout << "Digite o nome: ";
    cin.ignore(); // descarta um caracter do buffer anterior de entrada. isso é bom quando teve uma leitura anterior
    getline(cin, nome); //o comando acima é bom para evitar que o getline leia uma linha vazia
    cout << "Digite a idade: ";
    cin >> idade;

    cout << "Digite a rua: ";
    cin.ignore();
    getline(cin, rua);
    cout << "Digite a cidade: ";
    getline(cin, cidade);
    cout << "Digite o estado: ";
    getline(cin, estado);
    cout << "Digite o CEP: ";
    getline(cin, cep);
    Endereco endereco(rua, cidade, estado, cep);

    cout << "Escolha o cargo:\n";
    cout << "0 - CEO\n1 - CTO\n2 - Secretária\n3 - Presidente\n4 - Estagiário\n";
    cout << "Escolha a opcao do cargo (0 a 4): ";
    cin >> cargoOpcao;

    Cargo cargo(static_cast<Cargo::Valor>(cargoOpcao));   //transformando o valor escolhido para um tipo do enum

    Funcionario f(codigo, nome, idade, endereco, cargo);
    funcionarios.push_back(f);
    cout << "Funcionario cadastrado com sucesso!" << endl;
}

void alterarFuncionario(vector<Funcionario>& funcionarios) {
    int codigoAlterar;
    cout << "Digite o codigo do funcionario a ser alterado: ";
    cin >> codigoAlterar;

    for (auto& f : funcionarios) {   //faz o compilador deduzir o tipo do f automaticamente
        if (f.getCodigo() == codigoAlterar) {
            string nome;
            int idade;
            cout << "Digite o novo nome: ";
            cin.ignore();
            getline(cin, nome);
            f.setNome(nome);
            cout << "Digite a nova idade: ";
            cin >> idade;
            f.setIdade(idade);
            cout << "Funcionario alterado com sucesso!" << endl;
            return;
        }
    }
    cout << "Funcionario nao encontrado!" << endl;
}

void removerFuncionario(vector<Funcionario>& funcionarios) {
    int codigoRemover;
    cout << "Digite o codigo do funcionario a ser removido: ";
    cin >> codigoRemover;

    for (auto it = funcionarios.begin(); it != funcionarios.end(); ++it) {  //usando um interador
        if (it->getCodigo() == codigoRemover) {
            funcionarios.erase(it);
            cout << "Funcionario removido com sucesso!" << endl;
            return;
        }
    }
    cout << "Funcionario nao encontrado!" << endl;
}

void listarFuncionarios(const vector<Funcionario>& funcionarios) {
    cout << "\nLista de funcionarios:\n";
    for (const auto& f : funcionarios) {
        f.apresentar();
        cout << "------------------------\n";
    }
}

void adicionarProjetoFuncionario(vector<Funcionario>& funcionarios) {
    int codigoFuncionario;
    cout << "Digite o codigo do funcionario: ";
    cin >> codigoFuncionario;

    for (auto& f : funcionarios) {
        if (f.getCodigo() == codigoFuncionario) {
            int codigoProjeto;
            string titulo, descricao;
            cout << "Digite o codigo do projeto: ";
            cin >> codigoProjeto;
            cout << "Digite o titulo do projeto: ";
            cin.ignore();
            getline(cin, titulo);
            cout << "Digite a descricao do projeto: ";
            getline(cin, descricao);

            Projeto p(codigoProjeto, titulo);
            f.adicionarProjeto(p);
            cout << "Projeto adicionado com sucesso ao funcionario!\n";
            return;
        }
    }

    cout << "Funcionario nao encontrado!" << endl;
}

int main() {
    vector<Funcionario> funcionarios;
    int opcao;

    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarFuncionario(funcionarios);
                break;
            case 2:
                alterarFuncionario(funcionarios);
                break;
            case 3:
                removerFuncionario(funcionarios);
                break;
            case 4:
                listarFuncionarios(funcionarios);
                break;
            case 5:
                adicionarProjetoFuncionario(funcionarios);
                break;
            case 6:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida! Tente novamente.\n";
        }
    } while (opcao != 6);

    return 0;
}
