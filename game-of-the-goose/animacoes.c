#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

char ponte[109];
char poco[15];
char player[4] = {'\\', 'o', '/', '\0'};
char ganso1[50], ganso2[50];
char albergue[35];
char prisao1[70], prisao2[70], prisao3[70];
// char prisao[70][3];
char morte[800];
char morte1[20], morte2[20];
char shrek[470];
char lab0[470], lab1[470], lab2[470], lab3[470], lab4[470], lab5[470], lab6[470], lab7[470], lab8[470], lab9[470], lab10[470], lab11[470], lab12[470];

void lePonte();
void animacaoPonte();
void lePoco();
void animacaoPoco();
void leGanso();
void animacaoGanso();
void animacaoAndou(int casa_init, int andou_casas);
void animacaoAlbergue();
void animacaoPrisao();
void leLabirinto();
void leShrek();

// int main(){
//     leSprites();
//     printf("⠿");
//     return 0;
// }

void leSprites(){
    lePonte();
    lePoco();
    leAlbergue();
    lePrisao();
    leGanso();
    leLabirinto();
    leMorte();
    leShrek();
}

void leShrek(){
    FILE *shrek_file;
    char cur_line[50];
    shrek_file=fopen("sprites/shrek.txt", "r");
    while(fgets(cur_line, 470, shrek_file) != NULL){
        strcat(shrek, cur_line);
    }
    fclose(shrek_file);
}

void leLabirinto(){
    FILE *labpointer;
    char cur_line[50];
    labpointer=fopen("sprites/labirinto/lab0.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab0, cur_line);
    }
    fclose(labpointer);
    labpointer=fopen("sprites/labirinto/lab1.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab1, cur_line);
    }
    fclose(labpointer);
    labpointer=fopen("sprites/labirinto/lab2.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab2, cur_line);
    }
    fclose(labpointer);
    labpointer=fopen("sprites/labirinto/lab3.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab3, cur_line);
    }
    fclose(labpointer);
    labpointer=fopen("sprites/labirinto/lab4.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab4, cur_line);
    }
    fclose(labpointer);
    labpointer=fopen("sprites/labirinto/lab5.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab5, cur_line);
    }
    fclose(labpointer);
    labpointer=fopen("sprites/labirinto/lab6.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab6, cur_line);
    }
    fclose(labpointer);
    labpointer=fopen("sprites/labirinto/lab7.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab7, cur_line);
    }
    fclose(labpointer);
    labpointer=fopen("sprites/labirinto/lab8.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab8, cur_line);
    }
    fclose(labpointer);
    labpointer=fopen("sprites/labirinto/lab9.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab9, cur_line);
    }
    fclose(labpointer);
    labpointer=fopen("sprites/labirinto/lab10.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab10, cur_line);
    }
    fclose(labpointer);
    labpointer=fopen("sprites/labirinto/lab11.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab11, cur_line);
    }
    fclose(labpointer);
    labpointer=fopen("sprites/labirinto/lab12.txt", "r"); 
    while(fgets(cur_line, 470, labpointer) != NULL){
        strcat(lab12, cur_line);
    }
    fclose(labpointer);
}

void leMorte(){
    FILE *morte_file;
    char cur_line[50];
    morte_file=fopen("sprites/morte/morte.txt", "r");
    while(fgets(cur_line, 1000, morte_file) != NULL){
        strcat(morte, cur_line);
    }
    fclose(morte_file);
    morte_file=fopen("sprites/morte/pequena_morte1.txt", "r");
    while(fgets(cur_line, 20, morte_file) != NULL){
        strcat(morte1, cur_line);
    }
    fclose(morte_file);
    morte_file=fopen("sprites/morte/pequena_morte2.txt", "r");
    while(fgets(cur_line, 20, morte_file) != NULL){
        strcat(morte2, cur_line);
    }
}

void lePrisao(){
    FILE *prisao_file;
    prisao_file=fopen("sprites/prisao/prisao1.txt", "r");
    char cur_line[20];
    while(fgets(cur_line, 70, prisao_file) != NULL){
        strcat(prisao1, cur_line);
    }
    fclose(prisao_file);
    prisao_file=fopen("sprites/prisao/prisao2.txt", "r");
    while(fgets(cur_line, 70, prisao_file) != NULL){
        strcat(prisao2, cur_line);
    }
    fclose(prisao_file);
    prisao_file=fopen("sprites/prisao/prisao3.txt", "r");
    while(fgets(cur_line, 70, prisao_file) != NULL){
        strcat(prisao3, cur_line);
    }
    fclose(prisao_file);
}

void lePonte(){
    FILE *ponte_file;
    ponte_file=fopen("sprites/ponte/ponte.txt", "r");
    char cur_line[50];
    while(fgets(cur_line, 105, ponte_file) != NULL){
        strcat(ponte, cur_line);
    }
    fclose(ponte_file);
}

void lePoco(){
    FILE *poco_file;
    poco_file=fopen("sprites/poco/poco.txt", "r");
    char cur_line[10];
    while(fgets(cur_line, 5, poco_file) != NULL){
        strcat(poco, cur_line);
    }
    fclose(poco_file);
}

void leAlbergue(){
    FILE *alb_file;
    alb_file=fopen("sprites/albergue/albergue.txt", "r");
    char cur_line[50];
    while(fgets(cur_line, 105, alb_file) != NULL){
        strcat(albergue, cur_line);
    }
    fclose(alb_file);
}

void leGanso(){
    FILE *ganso_file;
    ganso_file=fopen("sprites/gansos/ganso1.txt", "r");
    char cur_line[50];
    while(fgets(cur_line, 30, ganso_file) != NULL){
        strcat(ganso1, cur_line);
    }
    fclose(ganso_file);
    ganso_file=fopen("sprites/gansos/ganso2.txt", "r");
    while(fgets(cur_line, 40, ganso_file) != NULL){
        strcat(ganso2, cur_line);
    }
    fclose(ganso_file);
}


//animações

void animacaoPonte(){
    printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
    int spaces=0;
    for(int i=0;i<25;i++){
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
            if(((time_clock2-time_clock)/CLOCKS_PER_SEC)*1000>100) break;
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
            if(((time_clock2-time_clock)/CLOCKS_PER_SEC)*1000>80) break;
        }
        if(spaces>0) spaces--;
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
            if(((time_clock2-time_clock)/CLOCKS_PER_SEC)*1000>180) break;
        }
        spaces++;
    }
}

void animacaoAndou(int casa_init, int andou_casas){
    printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
    int spaces=0, frame=1, counter_casa=casa_init+1;
    for(int i=0;i<andou_casas*3;i++){
        double time_clock=clock();
        printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
        if((frame)%3!=2){
            printf("\n");
        }
        if(casa_init>=10) printf(" ");
        for(int j=0;j<spaces;j++){
            printf(" ");
        }
        printf("%s\n", player);
        if((frame)%3==2){
            printf("\n");
        }
        for(int j=0;j<andou_casas+1;j++){
            if(casa_init+j<=63) printf(" %d", casa_init+j);
            else printf(" %d", 63-((casa_init+j)-63));
        }
        double time_clock2;
        while(1){
            time_clock2=clock();
            if(((time_clock2-time_clock)/CLOCKS_PER_SEC)*1000>100) break;
        }
        if((frame%3)!=0||counter_casa>=10)spaces++;
        else counter_casa++;
        frame++;
    }
}

void animacaoMorte(){
    printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
    int spaces=13, frame=0;
    for(int i=0;i<42;i++){
        double time_clock=clock();
        printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
        if(frame<=36)printf("%s", morte1);
        else printf("%s", morte2);
        for(int j=0;j<spaces;j++){
            printf(" ");
        }
        printf("%s\n", player);
        //controlador de framerate
        double time_clock2;
        while(1){
            time_clock2=clock();
            if(((time_clock2-time_clock)/CLOCKS_PER_SEC)*1000>150) break;
        }
        if(frame%3==0&&!(spaces<4))spaces--;
        frame++;
    }
    printf("\n\n%s\n\n", morte);
}

void animacaoAlbergue(){
    printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
    int spaces=4;
    for(int i=0;i<10;i++){
        double time_clock=clock();
        printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
        if(i<8) printf("\n\n");
        else if(i==8) printf("\n      o\n");
        else if(i==9) printf("      o\n       O\n");
        puts(albergue);
        for(int j=0;j<spaces;j++){
            printf("\n");
        }
        if(spaces>-2) printf("%s\n", player);
        double time_clock2;
        while(1){
            time_clock2=clock();
            if(((time_clock2-time_clock)/CLOCKS_PER_SEC)*1000>330) break;
        }
        spaces--;
    }
}

void animacaoPrisao(){
    printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
    int spaces=4, frame=1;
    for(int i=0;i<11;i++){
        double time_clock=clock();
        printf("\e[1;1H\e[2J");  //regex pra limpar a tela;
        for(int j=0;j<4-spaces;j++){
            printf("\n");
        }
        if(frame<6) printf("      %s\n", player);
        else printf("\n");
        for(int j=0;j<spaces;j++){
            printf("\n");
        }
        if(frame<8) printf("%s", prisao1);
        else if(frame==9||frame==8) printf("%s", prisao2);
        else printf("%s", prisao3);
        double time_clock2;
        while(1){
            time_clock2=clock();
            if(((time_clock2-time_clock)/CLOCKS_PER_SEC)*1000>400) break;
        }
        if(spaces!=0) spaces--;
        frame++;
    }
}

void animacaoLabirinto(){

}