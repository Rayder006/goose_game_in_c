#include <stdio.h>
#include <time.h>
#include <string.h>

char ponte[105];
char poco[5][3];
char player[4] = {'\\', 'o', '/', '\0'};
char ganso1[30], ganso2[40];
char casas_andou[13] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '\0'};

void lePonte();
void animacaoPonte();
void lePoco();
void animacaoPoco();
void leGanso();
void animacaoGanso();
void animacaoAndou(num_casas);

int main(){
    lePoco();
    lePonte();
    leGanso();

    animacaoAndou(1, 1);

    return 0;
}

void lePonte(){
    FILE *ponte_file;
    ponte_file=fopen("ponte.txt", "r");
    char cur_line[50];
    while(fgets(cur_line, 105, ponte_file) != NULL){
        strcat(ponte, cur_line);
    }
}

void lePoco(){
    FILE *poco_file;
    poco_file=fopen("poco.txt", "r");
    char cur_line[10];
    while(fgets(cur_line, 5, poco_file) != NULL){
        strcat(poco, cur_line);
    }
}

void animacaoPonte(){
    printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
    int spaces=0;
    for(int i=0;i<24;i++){
        double time_clock=clock();
        printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
        for(int j=0;j<spaces;j++){
            printf(" ");
        }
        printf("%s\n", player);
        puts(ponte);
        double time_clock2;
        while(1){
            time_clock2=clock();
            if(((time_clock2-time_clock)/CLOCKS_PER_SEC)*1000>1000) break;
        }
        spaces++;
    }
}

void animacaoPoco(){
    printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
    int spaces=10, stasis_frame=10, falling_frames=1;
    for(int i=0;i<24;i++){
        double time_clock=clock();
        printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
        printf("%s", poco);
        for(int j=0;j<spaces;j++){
            printf(" ");
        }
        if(spaces>=0&&stasis_frame>0){
            printf("%s", player);
            
        }
        else{
            if(falling_frames>3) break;
            for(int k=0;k<falling_frames;k++) puts(" ");
            printf("%s", player);
            falling_frames++;
        }
        if(spaces<=0)stasis_frame--;
        double time_clock2;
        while(1){
            time_clock2=clock();
            if(((time_clock2-time_clock)/CLOCKS_PER_SEC)*1000>150) break;
        }
        if(spaces>0) spaces--;
    }
}

void leGanso(){
    FILE *ganso_file;
    ganso_file=fopen("ganso1.txt", "r");
    char cur_line[50];
    while(fgets(cur_line, 30, ganso_file) != NULL){
        strcat(ganso1, cur_line);
    }
    ganso_file=fopen("ganso2.txt", "r");
    while(fgets(cur_line, 40, ganso_file) != NULL){
        strcat(ganso2, cur_line);
    }
}

void animacaoGanso(){
    printf("\e[1;1H\e[2J");  //regex pra limpar a tela;

    int spaces=1, frame=1;
    for(int i=0;i<24;i++){
        double time_clock=clock();
        printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
        // for(int j=0;j<spaces;j++){
        //     printf(" ");
        // }
        if(frame==1){
            printf("%s", ganso1);
            if(spaces%3==0) frame=0;
        }
        else{
            printf("%s", ganso2);
            if(spaces%3==0) frame=1;
        }

        double time_clock2;
        while(1){
            time_clock2=clock();
            if(((time_clock2-time_clock)/CLOCKS_PER_SEC)*1000>300) break;
        }
        spaces++;
    }
}

void animacaoAndou(int casa_init, int andou_casas){
    casa_init=1, andou_casas=5;
    printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
    int spaces=0, frame=1, counter_casa=casa_init;
    for(int i=0;i<andou_casas*3;i++){
        double time_clock=clock();
        printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
        if((frame)%3!=2){
            printf("\n");
        }
        for(int j=0;j<spaces;j++){
            printf(" ");
        }
        printf("%s\n", player);
        if((frame)%3==2){
            printf("\n");
        }
        for(int j=0;j<andou_casas+1;j++){
            printf(" %d", casa_init+j);

        }
        double time_clock2;
        while(1){
            time_clock2=clock();
            if(((time_clock2-time_clock)/CLOCKS_PER_SEC)*1000>100) break;
        }
        if((frame%3)!=0)spaces++;
        else counter_casa++;
        frame++;
    }
}