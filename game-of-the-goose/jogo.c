#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "animacoes.c"

int andou;

/* Declaração das Structs*/
struct Jogador{
    int id;
    char nome[20];
    unsigned int casa;
    int stasis_rounds_left;
    unsigned int ultima_casa;
    char direcao; /* pode ser 'f' (frente) ou 't' (tras)*/
};

/* Declaração das funções */
int dadoAleatorio();
void checaEvento(struct Jogador *structPtr);
void checaGanso(struct Jogador *structPtr);
void evento1(struct Jogador *structPtr);
void evento2(struct Jogador *structPtr);
void evento3(struct Jogador *structPtr);
void evento4(struct Jogador *structPtr);
void evento5(struct Jogador *structPtr);
void evento6(struct Jogador *structPtr);
void eventoGanso(struct Jogador *structPtr);

int main(void){
    lePonte();
    int num_jogadores, i, rodada=0;
    
    /*Introdução e leitura da quantidade de jogadores (só é permitido de 2 a 4)*/
    printf("Ola! Seja bem vindo ao Jogo do Ganso!\n");
    while(1){
        puts("Quantos jogadores irao jogar?");
        scanf("%d", &num_jogadores);
        if(num_jogadores<2||num_jogadores>4) printf("Opa, perae! Esse jogo so suporta de 2 a 4 jogadores.\n");
        else break;
    }

    const int a = num_jogadores;
    struct Jogador jogadores[a];

    /*leitura do nome de cada jogador e inicialização de suas Structs*/
    printf("Ok entao, %d jogadores!\nPoderiam me dizer seus nomes?\nLembre-se, so ate 20 caracteres, hein! :P\n", num_jogadores);
    for(i=0;i<num_jogadores;i++){
        fflush(stdin);
        gets(jogadores[i].nome);
        jogadores[i].id=i+1;
        jogadores[i].stasis_rounds_left=0;
        jogadores[i].casa=0;
        jogadores[i].direcao='f';

        printf("Oi %s, voce sera o jogador numero %d\n", jogadores[i].nome, jogadores[i].id);
        if (i==num_jogadores-2 && num_jogadores!=2) printf("Finalmente, o ultimo nome:\n");
        else if(i!=num_jogadores-1) printf("Agora o proximo:\n");
    }
    puts("\n");

    /*Ciclo onde o jogo acontece até o final*/
    puts("Ok, ja computei os nomes de voces, agora vamos comecar!");
    while(1){
        for(i=0;i<num_jogadores;i++){
            printf("Vez do jogador %d.\n", jogadores[i].id);
            /* Checa se o jogador está paralisado*/
            if(jogadores[i].stasis_rounds_left>0){
                printf("%s pulou a rodada.\n", jogadores[i].nome);
                jogadores[i].stasis_rounds_left--;
                continue;
            }
            puts("Aperte enter para rolar os dados...");
            fflush(stdin);
            getchar();
            /* Roda os dados */
            andou=dadoAleatorio();

            /* Muda a posição do jogador de acordo com sua orientação (pode ser pra frente ou para trás) */
            if(jogadores[i].direcao=='f'){
                jogadores[i].casa+=andou;
                if(jogadores[i].casa==63) goto end;
                else if(jogadores[i].casa>63){
                    jogadores[i].casa=63-(jogadores[i].casa-63);
                    jogadores[i].direcao='t';
                }
            }
            else if (jogadores[i].direcao=='t'){
                jogadores[i].casa-=andou;
                if(jogadores[i].casa<0){
                    jogadores[i].casa=0-jogadores[i].casa;
                    jogadores[i].direcao='f';
                }   
            }
            else printf("deu alguma bosta no codigo.\n");

            checaEvento(&jogadores[i]);

            printf("O jogador %s esta agora na %d casa.\n\n", jogadores[i].nome, jogadores[i].casa);
        }
    }

end:
    printf("\nParabens %s, voce chegou ao jardim dos Gansos! Uhuull!!\n", jogadores[i].nome);
    return 0;
}


int dadoAleatorio(){
    int n, i, total=0;
    int max = 6;

    srand(time(NULL));
    for(i=0;i<2;i++){
        n = rand (); /* gera um número inteiro entre 0 e RAND_MAX */
        n = n % max ; /* passa este numero para o intervalo 0 - max */
        printf("%do dado: %d\n", i+1, n+1);
        total+=n+1;
    }
    return total;
}

void checaEvento(struct Jogador *structPtr){
    switch ((*structPtr).casa)
    {
    case 6:
        evento1(structPtr);
        break;
    case 19:
        evento2(structPtr);
        break;
    case 31:
        evento3(structPtr);
        break;
    case 42:
        evento4(structPtr);
        break;
    case 52:
        evento5(structPtr);
        break;
    case 58:
        evento6(structPtr);
        break;
    
    default:
        printf("%s andou %d casas!\n\n", (*structPtr).nome, andou);
        break;
    }
}

void checaGanso(struct Jogador *structPtr){
    switch ((*structPtr).casa)
    {
    case 5:
        eventoGanso(structPtr);
        break;
    case 9:
        eventoGanso(structPtr);    
        break;
    case 14:
        eventoGanso(structPtr);    
        break;
    case 18:
        eventoGanso(structPtr);    
        break;
    case 23:
        eventoGanso(structPtr);    
        break;
    case 27:
        eventoGanso(structPtr);    
        break;
    case 32:
        eventoGanso(structPtr);
        break;
    case 36:
        eventoGanso(structPtr);    
        break;
    case 41:
        eventoGanso(structPtr);    
        break;
    case 45:
        eventoGanso(structPtr);    
        break;
    case 50:
        eventoGanso(structPtr);    
        break;
    case 54:
        eventoGanso(structPtr);    
        break;
    case 59:
        eventoGanso(structPtr);    
        break;
    
    
    default:
        printf("O jogador %s esta agora na %d casa.\n", (*structPtr).nome, (*structPtr).casa);
        break;
    }
}

void eventoGanso(struct Jogador *structPtr){
    /*Evento Ganso: Casas específicas que, se um jogador cair, ele pode jogar os dados novamente. */
    printf("Que sorte! O jogador %s caiu numa casa de ganso e poderá jogar de novo!", (*structPtr).nome);
    printf("Aperte Enter para jogar os dados novamente.\n");
    getchar();
    andou=dadoAleatorio();
    printf("%s andou %d casas!", (*structPtr).nome, andou);


    if((*structPtr).direcao=='f') (*structPtr).casa+=andou;
    else (*structPtr).casa-=andou;
    

    checaEvento(structPtr);
    checaGanso(structPtr);
}

void evento1(struct Jogador *structPtr){
    /*Evento 1: Casa 6 - A Ponte*/
    printf("%s chegou à Ponte...\nA Ponte serviu de atalho e o fez chegar rapidamente à casa 12!\n", (*structPtr).nome);
    (*structPtr).casa=12;
    animacaoPonte();
}

void evento2(struct Jogador *structPtr){
    /*Evento 2: Casa 19 - O Albergue*/
    printf("O jogador %s chegou ao Albergue...\nEle resolveu descansar e não poderá jogar a próxima rodada!\n", (*structPtr).nome);
    (*structPtr).stasis_rounds_left=1;
}

void evento3(struct Jogador *structPtr){
    /*Evento 3: Casa 31 - O Poço*/
    printf("O jogador %s caiu no Poco!\nNão poderá jogar ate que alguem o resgate!\n", (*structPtr).nome);
    (*structPtr).stasis_rounds_left=3;
}

void evento4(struct Jogador *structPtr){
    /*Evento 4: Casa 42 - O Labirinto*/
    printf("O jogador %s chegou ao Labirinto.\nEle se perdeu e acabou voltando a casa 37!\n", (*structPtr).nome);
    (*structPtr).casa=37;
}

void evento5(struct Jogador *structPtr){
    /*Evento 5: Casa 52 - A Prisão*/
    printf("O jogador %s encontrou a Prisão!\nPor motivos de sonegacao de impostos, ele nao ficou detido e nao podera jogar por 3 rodadas...\n", (*structPtr).nome);
    (*structPtr).stasis_rounds_left=3;
}

void evento6(struct Jogador *structPtr){
    /*Evento 6: Casa 58 - A Morte*/
    printf("O jogador %s encontrou a Morte...\nO azar bateu em sua porte, e ele terá de recomecar o jogo da casa 1.\n", (*structPtr).nome);
    (*structPtr).casa=1;
    (*structPtr).direcao='f';
}