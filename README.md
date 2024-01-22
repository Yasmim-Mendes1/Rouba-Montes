# Jogo Rouba Montes

O programa "Rouba Montes" é uma implementação do jogo de cartas com o objetivo de acumular o maior número de cartas no monte pessoal. Ele simula as ações de retirada de cartas da pilha de compra, comparação com cartas da área de descarte e montes de outros jogadores, e a possível adição de cartas ao monte pessoal do jogador da vez.


## Descrição dos Tipos Abstratos de Dados (TADs) e Estruturas de Dados Utilizadas:

### 1. Pilha:
   * Representa o monte de cartas de cada jogador.
   * Operações: Empilhar, Desempilhar, Verificar se está vazia.

### 2. Fila:
   * Mantém a ordem dos jogadores.
   * Operações: Enfileirar, Desenfileirar, Verificar se está vazia.

### 3. Lista:
   * Armazena as cartas na área de descarte.
   * Operações: Inserir item, Remover item, Verificar se está vazia.


## Descrição dos Módulos e Sua Interdependência:

### 1. Módulo Main:
   * Controla o fluxo principal do jogo.
   * Gerencia a ordem dos jogadores e o turno de cada jogador.

### 2. Módulos de Ações do Jogo:
   * Contêm funções para comparar e realizar ações com as cartas, como verificar se são iguais a cartas de outros jogadores, da área de descarte ou do próprio monte.

### 3. Módulos de Estruturas de Dados:
   * Implementam as estruturas de pilha, fila e lista utilizadas no jogo.


## Formato de Entrada dos Dados:
A quantidade de jogadores e o número de baralhos são solicitados ao usuário durante a execução do programa.

## Formato de Saída dos Dados:
A saída do programa consiste em mensagens informativas sobre as ações realizadas pelos jogadores e o estado atual do jogo.

## Como Utilizar o Programa:
O usuário é guiado durante a execução, recebendo mensagens sobre as ações disponíveis e respondendo a prompts.

## Estudo da Complexidade do Programa:
O programa utiliza estruturas de dados simples, e as operações principais são relacionadas ao número de cartas e jogadores. A complexidade é, em geral, O(n).
