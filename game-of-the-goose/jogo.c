#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "animacoes.c"

int andou;
double time_clock, time_clock2;

/* Declaração das Structs*/
struct Jogador{
    int id;
    char nome[20];
    int casa;
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
    int num_jogadores, i, rodada=0, j, controlador=0, pular;
    char cheat[8] = {'V', 'a', 'l', 'e', 'r', 'i', 'a', '\0'}; 
    
    leSprites();  
    /*Introdução e leitura da quantidade de jogadores (só é permitido de 2 a 4)*/
    printf("Ola! Seja bem vindo ao Jogo do Ganso!\n");

    while(1){
        puts("Quantos jogadores irao jogar?");
        fflush(stdin);
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
        //cheat do jogo
        pular=strcmp(cheat, jogadores[i].nome);

        if(pular==0){
            goto end; /* Goto implementado para ir direto ao final do jogo. É ativado se um dos players se chamar "Valeria" */
        }
        //fim do cheat
        printf("Oi %s, voce sera o jogador numero %d\n", jogadores[i].nome, jogadores[i].id);
        if (i==num_jogadores-2 && num_jogadores!=2) printf("Finalmente, o ultimo nome:\n");
        else if(i!=num_jogadores-1) printf("Agora o proximo:\n");
    }
    puts("\n");

    /*Ciclo onde o jogo acontece até o final*/
    puts("Ok, ja computei os nomes de voces, agora vamos comecar!");
    while(controlador!=3){
        for(i=0;i<num_jogadores;i++){
            time_clock=clock();
            printf("Vez do jogador %d.\n", jogadores[i].id);
            /* Checa se o jogador está paralisado*/
            if(jogadores[i].stasis_rounds_left>0 && jogadores[j].casa != 31){
                printf("%s pulou a rodada.\n", jogadores[i].nome);
                jogadores[i].stasis_rounds_left--;
                continue;
            }
            if(jogadores[i].stasis_rounds_left>0 && jogadores[i].casa == 31){
                /* Checa a ultima casa e casa atual de todos os jogadores pra ver se alguém passou pelo poço */
                for(j=0;j<num_jogadores;j++){
                    if(jogadores[j].ultima_casa<31 && jogadores[j].casa>=31 && i != j){
                        jogadores[i].casa = jogadores[j].ultima_casa;
                        jogadores[i].stasis_rounds_left = 0;
                        printf("O jogador %s foi salvo do poco e agora esta na casa %d\n", jogadores[i].nome, jogadores[i].casa); 
                        continue;
                    }
                }
                if(jogadores[i].stasis_rounds_left==0) continue;
                printf("%s esta preso no poco por mais rounds %d.\n", jogadores[i].nome, jogadores[i].stasis_rounds_left-1);
                jogadores[i].stasis_rounds_left--;
                continue;
            }
            jogadores[i].ultima_casa = jogadores[i].casa;
            puts("Aperte enter para rolar os dados...");
            fflush(stdin);
            getchar();
            /* Roda os dados */
            andou=dadoAleatorio();

            /* Muda a posição do jogador de acordo com sua orientação (pode ser pra frente ou para trás) */
            if(jogadores[i].direcao=='f'){
                animacaoAndou(jogadores[i].casa, andou);
                jogadores[i].casa+=andou;
                if(jogadores[i].casa==63) controlador=3;
                else if(jogadores[i].casa>63){
                    jogadores[i].casa=63-(jogadores[i].casa-63);
                    jogadores[i].direcao='t';
                }
            }
            else {
                printf("Deu algo de errado no codigo... Estamos resolvendo\n");
                jogadores[i].direcao='f';
            }

            checaEvento(&jogadores[i]);
            checaGanso(&jogadores[i]);        
            jogadores[i].direcao='f';
            if(jogadores[i].casa==63) controlador=3;

            printf("O jogador %s esta agora na %d casa.\n\n", jogadores[i].nome, jogadores[i].casa);
        }
    }
end:
    animacaoGanso();
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
        break;
    }
}

void eventoGanso(struct Jogador *structPtr){
    /*Evento Ganso: Casas específicas que, se um jogador cair, ele pode jogar os dados novamente. */
    while(1){
        time_clock2=clock();
        if(((time_clock2-time_clock)/CLOCKS_PER_SEC)*1000>600) break;
    }
    puts(ganso1);
    printf("Que sorte! %s caiu numa casa de ganso e podera jogar de novo!\n", (*structPtr).nome);
    fflush(stdin);
    printf("Aperte Enter para jogar os dados novamente.\n");
    getchar();
    andou=dadoAleatorio();

    if((*structPtr).direcao=='t'){
        printf("%s voltou %d casas!\n\n", (*structPtr).nome, andou);
        (*structPtr).casa-=andou;
        (*structPtr).direcao='f';
    }
    else {
        printf("%s andou %d casas!\n\n", (*structPtr).nome, andou);
        (*structPtr).casa+=andou;
    }

    fflush(stdin);
    if((*structPtr).casa>63) (*structPtr).casa=63-((*structPtr).casa-63);

    checaEvento(structPtr);
    checaGanso(structPtr);
}

void evento1(struct Jogador *structPtr){
    /*Evento 1: Casa 6 - A Ponte*/
    fflush(stdin);
    getchar();
    animacaoPonte();
    printf("%s chegou a Ponte...\nA Ponte serviu de atalho e o fez chegar rapidamente a casa 12!\n", (*structPtr).nome);
    (*structPtr).casa=12;
}

void evento2(struct Jogador *structPtr){
    /*Evento 2: Casa 19 - O Albergue*/
    fflush(stdin);
    getchar();
    animacaoAlbergue();
    printf("O jogador %s chegou ao Albergue...\nEle resolveu descansar e nao podera jogar a proxima rodada!\n", (*structPtr).nome);
    structPtr->stasis_rounds_left=1;
}

void evento3(struct Jogador *structPtr){
    /*Evento 3: Casa 31 - O Poço*/
    fflush(stdin);
    getchar();
    animacaoPoco();
    printf("O jogador %s caiu no Poco!\nNão podera jogar ate que alguem o resgate!\n", (*structPtr).nome);
    (*structPtr).stasis_rounds_left=4;
}

void evento4(struct Jogador *structPtr){
    /*Evento 4: Casa 42 - O Labirinto*/
    fflush(stdin);
    getchar();
    animacaoLabirinto();
    printf("O jogador %s chegou ao Labirinto.\nEle se perdeu e acabou voltando a casa 37!\n", (*structPtr).nome);
    (*structPtr).casa=37;
}

void evento5(struct Jogador *structPtr){
    /*Evento 5: Casa 52 - A Prisão*/
    fflush(stdin);
    getchar();
    animacaoPrisao();
    printf("O jogador %s encontrou a Prisao!\nPor motivos de sonegacao de impostos, ele nao ficou detido e nao podera jogar por 3 rodadas...\n", (*structPtr).nome);
    (*structPtr).stasis_rounds_left=3;
}

void evento6(struct Jogador *structPtr){
    /*Evento 6: Casa 58 - A Morte*/
    fflush(stdin);
    getchar();
    animacaoMorte();
    printf("Ola velho amigo, infelizmente sua hora chegou...\n\nO jogador %d caiu na casa da morte e tera que recomecar da casa 1.\n", (*structPtr).id);
    getchar();
    (*structPtr).casa=1;
    (*structPtr).direcao='f';
}