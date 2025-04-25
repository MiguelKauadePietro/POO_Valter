# 📦 Sistema de Controle de Estoque em C++

> Um projeto acadêmico orientado a objetos (POO) para gerenciamento de produtos e pedidos, escrito em C++.

---

## ✨ Visão Geral

Este projeto é um sistema de controle de estoque feito com **C++** utilizando os princípios fundamentais de **Programação Orientada a Objetos (POO)**. Ele permite o cadastro, alteração e remoção de produtos, bem como o gerenciamento de pedidos compostos por múltiplos itens.

Este sistema foi construído para fins de aprendizado, visando demonstrar boas práticas com classes, encapsulamento, composição, enums, vetores e modularização de código.

---

## 🧠 Conceitos de POO Utilizados

- ✅ Encapsulamento com classes (`Produto`, `Item`, `Pedido`)
- ✅ Composição entre objetos (`Pedido` contém `Item`, que contém `Produto`)
- ✅ Enumeração com método de conversão (`Categoria`)
- ✅ Modularização e separação de responsabilidades por arquivos `.h` / `.cpp`
- ✅ Uso de ponteiros e vetores
- ✅ Menu interativo em terminal
- ✅ Validações e tratamento de erros simples

---

## 🗂️ Estrutura do Projeto

```text
.
├── Categoria.h          # Enum class com categorias de produtos
├── Produto.h / .cpp     # Definição e implementação da classe Produto
├── Item.h / .cpp        # Classe Item contendo Produto e quantidade
├── Pedido.h / .cpp      # Classe Pedido contendo uma lista de Itens
├── Main_produtos.cpp    # Função main com menu principal e lógica do programa
```

---

## 🔧 Como Compilar

Você pode compilar o projeto utilizando `g++`:

```bash
g++ *.h *.cpp -o estoque
```

E executá-lo com:

```bash
./estoque
```

> Certifique-se de estar com todos os arquivos `.cpp` e `.h` na mesma pasta.

---

## 📚 Funcionalidades

- 📌 **Cadastrar Produtos:** com nome, código, preço e categoria
- 📝 **Editar Produtos:** atualize nome, código ou preço
- ❌ **Remover Produtos:** exclusão por código
- 📦 **Cadastrar Pedido:** com múltiplos itens e cálculo de total
- ➕ **Adicionar Itens em Pedidos existentes**
- ❌ **Remover Itens de um Pedido**
- 📃 **Listar todos os Produtos e Pedidos**

---

## 🔎 Exemplo de Uso (Terminal)

```text
Menu:
1. Cadastrar novo Produto
2. Alterar um Produto
3. Remover um Produto
4. Cadastrar um novo Pedido
5. Remover item de um Pedido
6. Adicionar itens a um Pedido
7. Listar todos os Pedidos
8. Listar todos os Produtos
9. Sair
Escolha uma opção:
```

---

## 📁 Categorias Disponíveis

Utilizadas via `enum` com conversão automática para string:

| Código | Categoria     |
|--------|---------------|
| 0      | Alimento      |
| 1      | Bebida        |
| 2      | Eletrônico    |
| 3      | Vestuário     |
| 4      | Livro         |
| 5      | Limpeza       |

---

## 🛠️ Melhorias Futuras

- 🔒 Validação mais robusta de entrada
- 💾 Persistência em arquivo (salvar e carregar)
- 📈 Relatórios (total por pedido, ranking de produtos)

---
