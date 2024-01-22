//Yasmim Mendes - UEMG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//estrutura das cartas
typedef struct carta {
  int numero;
  char naipe;
} Carta;

//estrutura de cada elemento das pilhas
typedef struct elementoPilha {
  Carta carta;
  struct elementoPilha *anterior;
} ElementoPilha;

//estrutura da pilha
typedef struct pilha {
  ElementoPilha *topo;
} Pilha;

//estrutura do jogador
typedef struct jogador {
  int id;
  char nome[50];
  Pilha *pilha;
} Jogador;

//estrutura de cada elemento da fila
typedef struct elementoFila {
  Jogador jogador;
  struct elementoFila *proximo;
} ElementoFila;

//estrutura da fila
typedef struct fila {
  ElementoFila *inicio;
  ElementoFila *final;
} Fila;

//estrutura de cada elemento da lista
typedef struct elementoLista {
  Carta carta;
  struct elementoLista *proximo;
} ElementoLista;

//estrutura da lista
typedef struct lista {
  ElementoLista *inicio;
} Lista;

//------------------------------------------------------------------------------------------------

//recebe carta e imprime sua representação
void imprimeCarta (Carta cartaDaVez){
  if (cartaDaVez.naipe == 'A'){

    if (cartaDaVez.numero == 1){
      printf ("Ás de Paus\n");
    }
    else if (cartaDaVez.numero == 11){
    printf ("Valete de Paus\n");
    }
    else if (cartaDaVez.numero == 12){
    printf ("Dama de Paus\n");
    }
    else if (cartaDaVez.numero == 13){
    printf ("Rei de Paus\n");
    }
    else {
    printf ("%d de Paus\n", cartaDaVez.numero);
    }

  }
  else if (cartaDaVez.naipe == 'B'){
    if (cartaDaVez.numero == 1){
      printf ("Ás de Copas\n");
    }
    else if (cartaDaVez.numero == 11){
      printf ("Valete de Copas\n");
    }
    else if (cartaDaVez.numero == 12){
    printf ("Dama de Copas\n");
    }
    else if (cartaDaVez.numero == 13){
    printf ("Rei de Copas\n");
    }
    else {
    printf ("%d de Copas\n", cartaDaVez.numero);
    }
  }
  else if (cartaDaVez.naipe == 'C'){
    if (cartaDaVez.numero == 1){
      printf ("Ás de Espadas\n");
    }
    else if (cartaDaVez.numero == 11){
      printf ("Valete de Espadas\n");
    }
    else if (cartaDaVez.numero == 12){
      printf ("Dama de Espadas\n");
    }
    else if (cartaDaVez.numero == 13){
      printf ("Rei de Espadas\n");
    }
  else {
    printf ("%d de Espadas\n", cartaDaVez.numero);
    }
  }
  else if (cartaDaVez.naipe == 'D'){
    if (cartaDaVez.numero == 1){
      printf ("Ás de Ouros\n");
    }
    else if (cartaDaVez.numero == 11){
      printf ("Valete de Ouros\n");
    }
    else if (cartaDaVez.numero == 12){
      printf ("Dama de Ouros\n");
    }
    else if (cartaDaVez.numero == 13){
      printf ("Rei de Ouros\n");
    }
    else {
    printf ("%d de Ouros\n", cartaDaVez.numero);
    }
  }
}

//pausa a execucao e espera o usuário apertar enter
void aguardarEnter(){
  printf("\nPressione Enter para continuar...");
  setbuf (stdin, NULL);
  getchar();
}




//------------------------------------------------------------------------------------------------




//função que cria uma pilha
Pilha* criarPilha(){
  //aloca memória
  Pilha* novaPilha = (Pilha*)malloc(sizeof(Pilha));

  //inicializa o topo da pilha como NULL
  novaPilha->topo = NULL;

  return novaPilha;
}

//função que libera memória da pilha
void liberaPilha(Pilha *pilha){
  //caso o ponteiro pilha não aponte para nenhum lugar na memória, encerra a função
  if (pilha == NULL) {
    return;
  }

  ElementoPilha *atual = pilha->topo;
  ElementoPilha *proximo;

  while (atual != NULL){
    proximo = atual->anterior;
    free(atual);
    atual = proximo;
  }

  free(pilha);

}

//verifica se a pilha está vazia
int pilhaVazia(Pilha *pilha){
  if (pilha->topo == NULL){
    return 1;
  }
  else {
    return 0;
  }
}

//recebe uma carta e a empilha na pilha desejada
void empilhar(Pilha *pilha, Carta carta){
  ElementoPilha* novoElemento = (ElementoPilha*)malloc(sizeof(ElementoPilha));
  if (novoElemento == NULL){
    return;
  }

  novoElemento->carta = carta;
  novoElemento->anterior = pilha->topo;
  pilha->topo = novoElemento;
}

//embaralha uma pilha de determinado tamanho
void empilharEmbaralhado(Pilha *pilhaCompra, int nbaralhos){
  int ncartas = 52 * nbaralhos;
  ElementoPilha *novoElemento = (ElementoPilha *)malloc(sizeof(ElementoPilha) * ncartas);

  // inicializa os baralhos
  int aux = 0;
  for (int k = 0; k < nbaralhos; k++){
    for (int i = 0; i < 4; ++i){
      for (int j = 0; j < 13; ++j){
        novoElemento[aux].carta.naipe = 'A' + i;
        novoElemento[aux].carta.numero = 1 + j;
        ++aux;
      }
    }

    free(novoElemento);
  }

  // embaralha os baralhos
  srand((unsigned int)time(NULL));

  for (int i = ncartas - 1; i > 0; --i){
    int j = rand() % (i + 1);

    ElementoPilha temp = novoElemento[i];
    novoElemento[i] = novoElemento[j];
    novoElemento[j] = temp;
  }

  // empilha na pilha de compra
  for (int i = 0; i < ncartas; ++i){
    empilhar(pilhaCompra, novoElemento[i].carta);
  }
}

//retira a carta do topo da pilha desejada
Carta desempilhar(Pilha *pilha){
  //nao tem o que desempilhar
  if (pilhaVazia(pilha) == 1){
    exit(EXIT_FAILURE);
  }

  ElementoPilha *elementoRemovido = pilha->topo;
  pilha->topo = elementoRemovido->anterior;

  Carta cartaRemovida = elementoRemovido->carta;
  free(elementoRemovido);

  return cartaRemovida;
}

//imprime a pilha desejada na tela
void imprimirPilha(Pilha *pilha){
  if (pilha == NULL || pilhaVazia(pilha) == 1) {
    return;
  }

  ElementoPilha *atual = pilha->topo;

  while (atual != NULL){
    imprimeCarta(atual->carta);
    atual = atual->anterior;
  }

  printf("\n");
}

//limpa a memoria da pilha
void limparPilha(Pilha* pilha){
  while (pilha->topo != NULL){
    ElementoPilha* temp = pilha->topo;
    pilha->topo = temp->anterior;
    free(temp);
  }
}





//------------------------------------------------------------------------------------------------




//funçao que cria uma nova fila
Fila* criarFila(){
  //aloca memoria
  Fila* novaFila = (Fila*)malloc(sizeof(Fila));

  //verifica se a memoria foi alocada
  if (novaFila == NULL){
    exit(EXIT_FAILURE);
  }

  //inicializa o inicio e o fim da fila como NULL
  novaFila->inicio = NULL;
  novaFila->final = NULL;

  return novaFila;
}

//libera memoria alocada da fila
void liberaFila(Fila *fila){
  if (fila->inicio == NULL){
    return;
  }

  ElementoFila *atual = fila->inicio;
  ElementoFila *proximo;

  while (atual != NULL){
    proximo = atual->proximo;
    free(atual);
    atual = proximo;
  }

  free(fila);
}

//verifica se a fila esta vazia
int estaVazia(Fila *fila){
  if (fila->inicio == NULL && fila->final == NULL){
    return 1;
  }
  else {
    return 0;
  }
}

//recebe um jogador e o coloca na fila
void enfileirar(Fila *fila, Jogador jogador){
  ElementoFila* novoElemento = (ElementoFila*)malloc(sizeof(ElementoFila));

  if (novoElemento == NULL){
    return;
  }

  novoElemento->jogador = jogador;
  novoElemento->proximo = NULL;

  if (estaVazia(fila)){
    fila->inicio = novoElemento;
    fila->final = novoElemento;
  } 
  else {
    fila->final->proximo = novoElemento;
    fila->final = novoElemento;
  }
}

//retira o jogador do inicio da fila
Jogador desenfileirar(Fila *fila){
  Jogador jogadorDesenfileirado;

  if (estaVazia(fila) == 1){
    exit(EXIT_FAILURE);
  }

  jogadorDesenfileirado = fila->inicio->jogador;

  ElementoFila *temporario = fila->inicio;
  fila->inicio = fila->inicio->proximo;

  free(temporario);

  if (fila->inicio == NULL){
    fila->final = NULL;
  }

  return jogadorDesenfileirado;
}

//avanca para o proximo jogador da fila
Jogador avancarTurno(Fila *fila){
  if (estaVazia(fila)){
    Jogador jogadorVazio;
    jogadorVazio.id = -1;
    strcpy(jogadorVazio.nome, "Vazio");
    return jogadorVazio; 
  }

  Jogador jogadorAtual = desenfileirar(fila);
  enfileirar(fila, jogadorAtual);

  return jogadorAtual;
}

//imprime a fila na tela
void imprimirFila(Fila *fila){
  if (fila->inicio == NULL || estaVazia(fila)){
    printf("A fila está vazia.\n");
    return;
  }

  ElementoFila *atual = fila->inicio;

  printf("\nOrdem dos jogadores:\n");

  while (atual != NULL){
    printf("%s\n", atual->jogador.nome);
    atual = atual->proximo;
  }

  printf("\n");
}

//limpa a memoria de uma fila
void limparFila(Fila* fila){
  while (fila->inicio != NULL){
    ElementoFila* temp = fila->inicio;
    fila->inicio = temp->proximo;
    free(temp);
  }
  fila->final = NULL;
}



//------------------------------------------------------------------------------------------------



//cria uma nova lista
Lista* criarLista(){
  //aloca memoria
  Lista* novaLista = (Lista*)malloc(sizeof(Lista));

  //verifica se a memoria foi alocada
  if (novaLista == NULL){
    exit(EXIT_FAILURE); 
  }

  //inicializa o inicio da lista como NULL
  novaLista->inicio = NULL;

  return novaLista;
}

//libera a memoria da lista
void limparLista(Lista *lista){
  if (lista == NULL) {
    return;
  }

  ElementoLista *atual = lista->inicio;
  ElementoLista *proximo;

  while (atual != NULL){
    proximo = atual->proximo;
    free(atual);
    atual = proximo;
  }

  lista->inicio = NULL;
}


//verifica se a lista esta vazia
int listaVazia(Lista *lista){
  if (lista == NULL || lista->inicio == NULL){
    return 1;
  }
  else {
    return 0;
  }
}

//recebe uma carta e coloca na lista
void inserirItem(Lista *lista, Carta carta){
  ElementoLista* novoElemento = (ElementoLista*)malloc(sizeof(ElementoLista));

  if (novoElemento == NULL){
    return;
  }

  novoElemento->carta = carta;
  novoElemento->proximo = NULL;

  if (lista->inicio == NULL){
    lista->inicio = novoElemento;
  } 
  else {
    ElementoLista *atual = lista->inicio;
    while (atual->proximo != NULL){
      atual = atual->proximo;
    }
    atual->proximo = novoElemento;
  }
}

//remove um item da lista
ElementoLista* removerItem(Lista *lista, int posicao){
  if (listaVazia(lista) == 1){
    return NULL;
  }

  ElementoLista *elementoRemovido;

  if (posicao == 0){
    elementoRemovido = lista->inicio;
    lista->inicio = lista->inicio->proximo;
  } 
  else {
    ElementoLista *anterior = NULL;
    ElementoLista *atual = lista->inicio;
    int i = 0;

    while (i < posicao && atual != NULL){
      anterior = atual;
      atual = atual->proximo;
      i++;
    }

    if (atual != NULL){
      elementoRemovido = atual;
      anterior->proximo = atual->proximo;
      } 
    else {
      return NULL;
    }
  }

  elementoRemovido->proximo = NULL;

  return elementoRemovido;
}

//recebe um item e procura por um item igual na lista
int buscarItem(Lista *lista, int chave){
  if (listaVazia(lista) == 1){
    return -1;
  }

  ElementoLista *atual = lista->inicio;
  int posicao = 0;

  while (atual != NULL){
    if (atual->carta.numero == chave){
    return posicao;
    }
    atual = atual->proximo;
    posicao++;
  }

  return -1;
}	

//imprime a lista na tela
void imprimirLista(Lista *lista){
  if (listaVazia(lista) == 1){
    printf ("Lista vazia.\n");
    return;
  }	

  ElementoLista *atual = lista->inicio;

  while (atual != NULL){
    imprimeCarta(atual->carta);
    atual = atual->proximo;
  }
  printf("\n");
}




//------------------------------------------------------------------------------------------------



//recebe a carta da vez e verifica se ela e igual a carta do topo do monte do jogador atual
int igualProprioMonte(Carta cartaDaVez, Jogador *jogadorAtual){
  if (jogadorAtual->pilha->topo != NULL && jogadorAtual->pilha->topo->carta.numero == cartaDaVez.numero) {
    if (jogadorAtual->pilha->topo->anterior != NULL){
      printf("Sua carta da vez é igual a carta do topo do seu monte.\n");
      return 0;
    }
  }
  printf("Sua carta da vez não é igual a carta do topo do seu monte.\n");
  return 1;
}


//recebe a carta da vez e verifica se ela e igual a alguma carta da area de descarte
int igualAreaDescarte(Lista *areaDescarte, Jogador *jogadorAtual, Carta cartaDaVez){
  int posicao = buscarItem(areaDescarte, cartaDaVez.numero);

  if (posicao != -1){
    printf("\nSua carta da vez é igual a uma carta da Área de Descarte.\n");
    return 0;
  } 
  else {
    printf("\nSua carta da vez não é igual a nenhuma carta da Área de Descarte.\n\n");
    return 1;
  }
}

//recebe a carta da vez e verifica se ela e igual a carat do topo do monte de algum adversario
int igualMonteAdversario(Carta cartaDaVez, Jogador *jogador, Jogador *jogadorAtual){
  if (jogador->pilha->topo != NULL && cartaDaVez.numero == jogador->pilha->topo->carta.numero){
    printf("Sua carta da vez é igual a carta do topo do monte de %s.\n", jogador->nome);
    return 0;
  }

  printf("Sua carta da vez não é igual a carta do topo do monte de %s.\n", jogador->nome);
  return 1;
}

//recebe a carta da vez e verifica se ela e diferente de todas as cartas do topo do monte dos adversarios, da pilha de compra e da area de descarte
int diferente(Carta cartaDaVez, Lista *areaDescarte, Pilha *pilhaJogador, Fila *fila, int njogadores, Jogador *jogadorAtual, Jogador *jogador) {
  int adversario = 0;
  int cont = 0; //controla se o jogador ganhou ou nao alguma carta na partida
  char decisao[4];

  if (igualProprioMonte(cartaDaVez, jogadorAtual) == 1){
    cont++; //se a carta da vez for diferente do topo do monte do proprio jogador atual, adiciona 1 ao contador
  } 
  else { //se for igual
    printf("Adicionar carta da vez ao seu monte? (sim ou nao)\n");
    setbuf(stdin, NULL);
    fgets(decisao, 4, stdin);
    getchar();

    if (strcmp(decisao, "sim") == 0){
      empilhar(jogadorAtual->pilha, cartaDaVez);
      printf("Você recebeu uma carta!\n\n");
    }
  }

  if (igualAreaDescarte(areaDescarte, jogadorAtual, cartaDaVez) == 1){
    cont++; //se a carta da vez for diferente de todas as cartas da area de descarte, adiciona 1 ao contador
  } 
  else { //se for igual
    printf("Adicionar carta da vez e carta da Área de Descarte ao seu monte? (sim ou nao)\n");
    setbuf(stdin, NULL);
    fgets(decisao, 4, stdin);
    getchar();
    if (strcmp(decisao, "sim") == 0){
      ElementoLista *elementoRemovido = removerItem(areaDescarte, buscarItem(areaDescarte, cartaDaVez.numero));
      Carta cartaRemovida = elementoRemovido->carta;
      free(elementoRemovido);

      empilhar(jogadorAtual->pilha, cartaRemovida);
      empilhar(jogadorAtual->pilha, cartaDaVez);
      printf("Você recebeu duas cartas!\n\n");
    }
  }

  for (int i = 0; i < njogadores; i++){ //percorre o vetor de jogadores
    if (jogador[i].id != jogadorAtual->id){ //o jogador atual não entra nessa condição para nao ser comparado com ele mesmo
      if (igualMonteAdversario(cartaDaVez, &jogador[i], jogadorAtual) == 1){
        adversario++; //contabiliza quantos adversarios tem a carta do topo do monte diferente da sua carta da vez
      } 
      else { //se for igual
        printf("Adicionar monte do adversário ao seu monte? (sim ou nao)\n");
        setbuf(stdin, NULL);
        fgets(decisao, 4, stdin);
        getchar();
        if (strcmp(decisao, "sim") == 0){
          printf("Cartas recebidas: \n");
          while (jogador[i].pilha->topo != NULL){ //percorre todo o monte do adversario
            Carta cartaRemovida = desempilhar(jogador[i].pilha);
            imprimeCarta(cartaRemovida);

            empilhar(jogadorAtual->pilha, cartaRemovida); //recebe todo o monte do adversario
          }
          printf("Você recebeu todas as cartas do adversário!\n\n");
        }
      }
    }
  }

  if (adversario == njogadores - 1){
    cont++; //se nenhum adiversario teve a carta do topo do monte igual a sua carta da vez, adiciona 1 ao contabilizador
  }

  if (cont == 3){ //se a carta da vez é diferente de tudo
    inserirItem(areaDescarte, cartaDaVez); //carta da vez vai pra area de descarte
    printf("\n\nSua carta da vez foi para a Área de Descarte.\n");
    return 0; //não ganhou cartas
  }

  return 1; //ganhou cartas
}



//------------------------------------------------------------------------------------------------



//recebe determindados jogadores e os inverte
void trocarJogadores(Jogador *a, Jogador *b){
  Jogador temp = *a;
  *a = *b;
  *b = temp;
}

//recebe uma pilha e conta quantas cartas tem
int contarElementos(Pilha *pilha){
  int contador = 0;

  if (pilha != NULL){
    ElementoPilha *atual = pilha->topo;

    while (atual != NULL){ //percorre toda a pilha
      contador++;
      atual = atual->anterior;
    }
  }

  return contador;
}

//parte do quicksort, coloca os jogadores com menos cartas a esquerda do vetor e coloca os jogadores com mais cartas a direita
void particionar(int esq, int dir, int i, int j, Jogador jogador[]){
  int x, temp;
  i = esq;
  j = dir;
  x = contarElementos(jogador[(i + j) / 2].pilha);

  do {
    while (x < contarElementos(jogador[i].pilha)){
      ++i;
    }
    while (x > contarElementos(jogador[j].pilha)){
      --j;
    }
    if (i <= j){
      trocarJogadores(&jogador[i], &jogador[j]);
      ++i;
      --j;
    }
  } while (i <= j);
}

//quicksort para ordenar a fila de jogadores
void ordenarJogadores(int esq, int dir, Jogador jogador[]) {
  int i, j;
  if (esq < dir) {
    particionar(esq, dir, i, j, jogador);
    if (esq < j) {
      ordenarJogadores(esq, j, jogador);
    }
    if (i < dir) {
      ordenarJogadores(i, dir, jogador);
    }
  }
}





//------------------------------------------------------------------------------------------------




int main(void) {
  int njogadores;
  int nbaralhos;
  Pilha *pilhaCompra = criarPilha(); //pilha de compra
  Fila *fila = criarFila(); //fila de jogadores
  Lista *areaDescarte = criarLista(); //area de descarte
  Jogador *jogador; 
  srand(time(NULL)); //semente para geracao de numeros aleatorios

  printf("ROUBA MONTES\n\n");

  printf("REGRAS:\n1. OBJETIVO:\n- Acumular o maior número de cartas no monte pessoal.\n..............................................................................................\n2. PREPARAÇÃO:\n- Baralho embaralhado forma a pilha de compra.\n..............................................................................................\n3. INÍCIO:\n- O jogador da vez retira uma carta da pilha de compra (carta da vez).\n..............................................................................................\n4. AÇÕES POSSÍVEIS:\nSe a carta da vez for igual a:\n- uma das cartas da Área de Descarte, jogador da vez recebe a carta da vez e a carta da Área de Descarte.\n- carta do topo do próprio monte, jogador recebe a carta da vez.\n- carta do topo do monte de algum oponente, jogador recebe o monte todo do oponente.\n\nCaso contrário, a carta da vez vai pra Área de Descarte.\n..............................................................................................\n6. FIM DO TURNO:\n- Se o jogador receber alguma carta, o próximo turno também será dele.\n- Se não, o próximo turno será do próximo jogador na lista.\n..............................................................................................\n7. FIM DE JOGO:\n- Pilha de compra esgotada.\n- Vencedor com mais cartas no monte pessoal.\n.............................................................................................\n\n\n\n");

  printf("Informe a quantidade de jogadores: ");
  scanf("%d", &njogadores);

  jogador = (Jogador *)malloc(sizeof(Jogador) * njogadores); //cria um vetor temporario de jogadores com o numero recebido

  for (int i = 0; i < njogadores; i++){
    jogador[i].pilha = criarPilha(); //cria uma pilha pra cada jogador

    //recebe informações de cada jogador e armazena
    printf("Informe o nome do jogador %d: ", i + 1);
    setbuf(stdin, NULL);
    fgets(jogador[i].nome, 50, stdin);
    size_t length = strlen(jogador[i].nome);
    if (length > 0 && jogador[i].nome[length - 1] == '\n') {
      jogador[i].nome[length - 1] = '\0';
    }
    jogador[i].id = i;

    enfileirar(fila, jogador[i]); //enfileira os jogadores
  }

  printf("\nInforme a quantidade de baralhos utilizados no jogo (um baralho contém 52 cartas): ");
  scanf("%d", &nbaralhos);
  empilharEmbaralhado(pilhaCompra, nbaralhos); //embaralha os baralhos de acordo com o numero de baralhos recebidos

  imprimirFila(fila); //imprime a ordem dos jogadores

  Jogador jogadorAtual = avancarTurno(fila); //define o jogador atual
  Carta cartaDaVez;

  int aux = 0;

  while (pilhaCompra->topo != NULL){ //enquanto a pilha de compra não estiver vazia
    cartaDaVez = desempilhar(pilhaCompra); //define a carta da vez
    if (aux != 0){ //se nao é a primeira partida
      aguardarEnter(); //espera o jogador pressionar enter a cada rodada
    }
    printf("\n\n\n-------------------------------------------------------------------------------------------------");
    printf("\n%s, sua carta da vez é um ", jogadorAtual.nome);
    imprimeCarta(cartaDaVez);

    printf("\nCartas na área de descarte:\n");
    imprimirLista(areaDescarte); //mostra na tela a area de descarte

    printf ("\n");

    for (int i = 0; i < njogadores; i++){ //percorre todos os jogadores
      if (jogador[i].id != jogadorAtual.id){ //menos o jogador atual
        printf ("Carta do topo do monte de %s:\n", jogador[i].nome);
          if (jogador[i].pilha->topo != NULL){ //se o monte do adversario nao esta vazio
            imprimeCarta(jogador[i].pilha->topo->carta); //mostra na tela a carta do topo  do monte de cada adversario
            printf ("\n\n\n");
          }
          else {
            printf ("Monte vazio.\n\n\n");
          }
      }
    }

    if (diferente(cartaDaVez, areaDescarte, jogadorAtual.pilha, fila, njogadores, &jogadorAtual, jogador) == 0){ //chama todas as funções de regras do jogo
      jogadorAtual = avancarTurno(fila); //se o jogador nao receber nenhuma carta, avanca o turno
    }
    aux++; //conta o numero de partidas
  }

  if (pilhaVazia(pilhaCompra) == 1){
    printf ("\n\n\n-------------------------------------------------------------------------------------------------\nFIM DE JOGO!\n\n"); //se a pilha de compra esta vazia, acaba o jogo

    ordenarJogadores(0, njogadores - 1, jogador);
    int posicaoAtual = 1;

    for (int i = 0; i < njogadores; i++){
      if (i > 0 && contarElementos(jogador[i].pilha) != contarElementos(jogador[i - 1].pilha)){
        posicaoAtual = i + 1; //caso seja empate, a posição se mantém
      }
      //imprime o ranking como o numero de cartas e as cartas de cada
      printf ("%dº lugar: %s\nNúmero de cartas: %d\nCartas:\n", posicaoAtual, jogador[i].nome, contarElementos(jogador[i].pilha)); //imprime o ranking como o numero de cartas e as cartas de cada jogador
      imprimirPilha(jogador[i].pilha);
    }

    printf ("\n\n");
  }

  limparPilha(pilhaCompra);
  limparFila(fila);
  limparLista(areaDescarte);
  for (int i = 0; i < njogadores; i++){
    limparPilha(jogador[i].pilha);
  }

  return 0;
}