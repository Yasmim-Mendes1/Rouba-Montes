# Jogo Rouba Montes

O código em C apresenta a implementação do "Rouba Montes", um jogo de cartas onde o objetivo é acumular o maior número de cartas. O código utiliza estruturas de dados como pilhas, filas e listas para representar os elementos do jogo, como cartas, jogadores e a área de descarte. As funções implementadas gerenciam a criação, manipulação e limpeza dessas estruturas, além de aplicar as regras do jogo, como verificar se a carta da vez é igual a alguma carta na área de descarte, no próprio monte ou nos montes dos adversários. Ao final do jogo, o programa exibe um ranking dos jogadores com base no número de cartas em seus montes.

<br>
## Funções:
1. **imprimeCarta:** Recebe uma carta e imprime sua representação, considerando número e naipe.
2. **aguardarEnter:** Pausa a execução e espera o usuário pressionar Enter.
3. **criarPilha:** Cria e retorna uma nova pilha alocada dinamicamente.
4. **liberaPilha:** Libera a memória alocada para uma pilha, incluindo todos os elementos.
5. **pilhaVazia:** Verifica se a pilha está vazia.
6. **empilhar:** Recebe uma pilha e uma carta, empilhando a carta no topo da pilha.
7. **empilharEmbaralhado:** Embaralha e empilha as cartas de um ou mais baralhos em uma pilha.
8. **desempilhar:** Desempilha a carta do topo de uma pilha e a retorna.
9. **imprimirPilha:** Imprime na tela os elementos de uma pilha.
10. **limparPilha:** Libera a memória de uma pilha, removendo todos os elementos.
11. **criarFila:** Cria e retorna uma nova fila alocada dinamicamente.
12. **liberaFila:** Libera a memória alocada para uma fila, incluindo todos os elementos.
13. **estaVazia:** Verifica se a fila está vazia.
14. **enfileirar:** Adiciona um jogador ao final da fila.
15. **desenfileirar:** Remove e retorna o jogador do início da fila.
16. **avancarTurno:** Move o jogador atual para o final da fila e retorna o próximo jogador.
17. **imprimirFila:** Imprime na tela a ordem dos jogadores na fila.
18. **limparFila:** Libera a memória de uma fila, removendo todos os elementos.
19. **criarLista:** Cria e retorna uma nova lista alocada dinamicamente.
20. **limparLista:** Libera a memória alocada para uma lista, incluindo todos os elementos.
21. **listaVazia:** Verifica se a lista está vazia.
22. **inserirItem:** Insere uma carta no final da lista.
23. **removerItem:** Remove e retorna um item da lista em uma posição específica.
24. **buscarItem:** Busca um item na lista e retorna sua posição.
25. **imprimirLista:** Imprime na tela os elementos de uma lista.
26. **igualProprioMonte:** Verifica se a carta da vez é igual à do topo do próprio monte.
27. **igualAreaDescarte:** Verifica se a carta da vez é igual a alguma carta na Área de Descarte.
28. **igualMonteAdversario:** Verifica se a carta da vez é igual à do topo do monte de algum adversário.
29. **diferente:** Verifica se a carta da vez é diferente de todas as cartas relevantes e realiza as ações correspondentes.
30. **trocarJogadores:** Troca a posição de dois jogadores em um vetor.
31. **contarElementos:** Conta o número de cartas em uma pilha.
32. **particionar:** Particiona o vetor de jogadores para o quicksort.
33. **ordenarJogadores:** Ordena os jogadores com base no número de cartas em seus montes usando o quicksort.
34. **main:** Função principal que implementa o jogo de "Rouba Montes" seguindo as regras definidas.

<br>
## TADs e estruturas de dados:
1. **Carta**: Estrutura que representa uma carta do baralho, contendo número e naipe.
2. **ElementoPilha**: Elemento da pilha que armazena uma carta e uma referência ao elemento anterior.
3. **Pilha**: Estrutura de dados do tipo pilha, contendo um ponteiro para o topo.
4. **ElementoFila**: Elemento da fila que armazena um jogador e uma referência ao próximo elemento.
5. **Fila**: Estrutura de dados do tipo fila, contendo ponteiros para o início e fim.
6. **ElementoLista**: Elemento da lista que armazena uma carta e uma referência ao próximo elemento.
7. **Lista**: Estrutura de dados do tipo lista encadeada, contendo um ponteiro para o início.
8. **Jogador**: Estrutura que representa um jogador, contendo um identificador, nome e uma pilha de cartas.

<br>
## Formato de Entrada dos Dados:
1. **Quantidade de Jogadores (`njogadores`):** O usuário deve informar a quantidade de jogadores que participarão do jogo.
2. **Informações dos Jogadores:** Para cada jogador, o usuário é solicitado a fornecer o nome do jogador.
3. **Quantidade de Baralhos (`nbaralhos`):** O usuário informa a quantidade de baralhos utilizados no jogo. Um baralho padrão contém 52 cartas.

<br>
## Formato de Saída dos Dados:
1. **Informações Iniciais:**
   - Regras do jogo são exibidas.
   - Solicitação do número de jogadores.
   - Solicitação do número de baralhos utilizados.
2. **Informações dos Jogadores:**
   - Solicitação do nome de cada jogador.
   - Ordem dos jogadores na fila é mostrada.
3. **Desenvolvimento do Jogo (para cada rodada):**
   - Carta da vez é revelada para o jogador atual.
   - Estado da Área de Descarte é exibido.
   - Carta do topo do monte de cada adversário é mostrada.
   - Para cada ação possível (igual/diferente):
      - Ações do jogador são exibidas.
      - Se o jogador recebeu cartas, as cartas são mostradas.
      - Próximo turno é anunciado.
4. **Resultado Final:**
   - Fim de jogo é declarado.
   - Jogadores são classificados pelo número de cartas acumuladas.
   - Ranking é exibido com o número de cartas e as cartas de cada jogador.

<br>
## Complexidade:
1. **Empilhar Embaralhado:**
   - Complexidade de tempo: O(nbaralhos * 52), onde nbaralhos é o número de baralhos utilizados.
   - Justificativa: A função percorre cada carta em todos os baralhos, realizando operações como atribuição e troca de elementos.
2. **Avançar Turno:**
   - Complexidade de tempo: O(1)
   - Justificativa: A função envolve apenas operações de enfileiramento e desenfileiramento, ambas operações de tempo constante.
3. **Diferente:**
   - Complexidade de tempo: O(njogadores * 52)
   - Justificativa: A função envolve iterações sobre o vetor de jogadores, cada uma envolvendo operações em pilhas que podem conter até 52 cartas.
4. **Ordenar Jogadores (Quicksort):**
   - Complexidade de tempo: O(njogadores * log(njogadores))
   - Justificativa: O algoritmo de ordenação Quicksort tem uma complexidade média de O(n * log(n)), onde n é o número de elementos.

<br>
## Como Utilizar o Programa:
1. **Compilar o Código:**
   - Copie e cole o código C em um arquivo com extensão `.c`.
   - Compile o código utilizando um compilador C, como o GCC (GNU Compiler Collection).
2. **Executar o Programa:**
   - Após a compilação, execute o programa.
3. **Entrada de Dados:**
   - O programa solicitará informações, como a quantidade de jogadores e a quantidade de baralhos a serem utilizados.
   - Informe os nomes dos jogadores.
4. **Andamento do Jogo:**
   - O jogo será iniciado, e cada jogador terá seu turno.
   - Siga as instruções exibidas na tela para interagir com o jogo.
   - Pressione Enter para avançar para o próximo turno.
5. **Final do Jogo:**
   - O jogo continuará até a pilha de compra ser esgotada.
   - No final, o programa exibirá o ranking dos jogadores com base na quantidade de cartas em seus montes.
6. **Encerramento:**
   - O programa será encerrado, e você pode visualizar os resultados do jogo.
