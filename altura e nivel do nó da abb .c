
//Deixei o valor 1 a 20 na função adicionar so pra deixar mais facil, se quiser mudar vai funcionar também


#include<stdio.h>
#include<stdlib.h>

typedef struct vertice{
    int chave;
    struct vertice * dir;
    struct vertice * esq;
}VERTICE;


VERTICE * raiz = NULL;
int tam = 0;

VERTICE* buscar(int x, VERTICE *aux){ //Código da Aula
    if(aux == NULL){
        return NULL;
    }else if (x == aux->chave){
        return aux;
    }else if(x < aux->chave){
        if(aux->esq == NULL){
            return aux;
        }else{
            return buscar(x, aux->esq);
        }
    }else{
        if(aux->dir == NULL){
            return aux;
        }else{
            return buscar(x, aux->dir);
        }
    }
}

void adicionar(int chave){ //Código da Aula
    VERTICE* aux = buscar(chave, raiz);
    if(aux != NULL && aux->chave == chave){
        printf("insercao invalida!\n");
    }else{
        VERTICE* novo = malloc(sizeof(VERTICE));
        novo->chave = chave;
        novo->esq = NULL;
        novo->dir = NULL;
        if(aux == NULL){
            raiz = novo;
        }else if(chave < aux->chave){
            aux->esq = novo;
        }else{
            aux->dir = novo;
        }
    }
}

void in_ordem(VERTICE *aux){ //Código da Aula

    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }

    printf("%d ", aux->chave);

    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}

//Questão 1 - Função que mostra a altura de um nó
VERTICE* buscarNO(VERTICE *raiz, int chave){
    if(raiz == NULL)
        {return 0;}
    else{
        if(raiz->chave == chave)
            {return raiz;}
        else{
            if(chave < raiz->chave) 
                {return buscarNO(raiz->esq, chave);}
            else
                {return buscarNO(raiz->dir, chave);}}}}

int altura_arvore(VERTICE *raiz){
    if(raiz == NULL || raiz->dir == NULL && raiz->esq == NULL)
        {return 0;}
    else{
        int esq = 1 + altura_arvore(raiz->esq);
        int dir = 1 + altura_arvore(raiz->dir);
        if(esq > dir)
            {return esq;}
        else 
            {return dir;}}}

int altura_no(int chave){
    VERTICE *aux = buscarNO(raiz, chave);
    if(aux)
        {return altura_arvore(aux);}
    else 
        {return -1;}}



//Questão 2 - Função que mostra o nível de um nó
int nivel_no (int chave, VERTICE *aux){
    if(aux == NULL){
        return 0; }
    else if (chave == aux->chave){
        return 0;}
    else if(chave < aux->chave){
        if(aux->esq == NULL)
            {return 0;}
        else{
            return nivel_no(chave, aux->esq) + 1;}}
        else{
            if(aux->dir == NULL){
                return 0;}  
            else{
            return nivel_no(chave, aux->dir) + 1;}}}



int main(){
    int no_escolhido;
    int opcao;

    adicionar(8); 
    adicionar(5);
    adicionar(9); 
    adicionar(1); 
    adicionar(6); 
    adicionar(7); 
    adicionar(16); 
    adicionar(2); 
    adicionar(4); 
    adicionar(15); 
    adicionar(12); 
    adicionar(3); 
    adicionar(17); 
    adicionar(10); 
    adicionar(19); 
    adicionar(18); 
    adicionar(13); 
    adicionar(20); 
    adicionar(11); 
    adicionar(14); 

    printf("Insira o que voce deseja fazer\n1- Mostrar a altura de um No\n2- Mostrar o nivel de um No:\n");
    scanf("%d",&opcao);

    while(opcao < 1 || opcao > 2){
        printf("!!OPCAO INVALIDA!!\n");
        printf("Insira o que voce deseja fazer\n1- Mostrar a altura de um No\n2- Mostrar o nivel de um No: ");
        scanf("%d",&opcao);}


    switch(opcao){

        case 1: 
            printf("Qual No (entre 1 e 20) voce deseja consultar a altura?: ");
            scanf("%d",&no_escolhido);
            while(no_escolhido < 1 || no_escolhido > 20){
                printf("\n!!OPCAO INVALIDA!!\n");
                printf("Insira um valor entre 1 e 20: ");
                scanf("%d",&no_escolhido);}
            printf("\nImprimindo arvore...\n");
            in_ordem(raiz);
            printf("\nAltura do No %d: %d",no_escolhido, altura_no(no_escolhido));
            break;

    case 2: 
            printf("Qual No (entre 1 e 20) voce deseja consultar o nivel?: ");
            scanf("%d",&no_escolhido);
            while(no_escolhido < 1 || no_escolhido > 20){
                printf("\n!!OPCAO INVALIDA!!\n");
                printf("Insira um valor entre 1 e 20: ");
                scanf("%d",&no_escolhido);}
            printf("\nImprimindo arvore...\n");
            in_ordem(raiz);
            printf("\nNivel do No %d: %d",no_escolhido, nivel_no(no_escolhido,raiz));
            break;}}
