# goose_game_in_c

  Este é um projeto para a disciplina de Computação 1 (programação em C) da UFRJ, período de 2021.2.
  
  Nossa proposta é programar o jogo de tabuleiro "Jogo do Ganso" (Game of the Goose) em C usando apenas as bibliotecas explicadas em sala de aula (time.h, string.h, stdio.h...), 
nos limitando ao terminal padrão (stdout) para qualquer troca de informação entre a máquina e o jogador.

  Este projeto utiliza arquivos interligado para algumas de suas funções. Para acessar a completude deste projeto, clone-o através do link https://github.com/Rayder006/goose_game_in_c.git 


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

   O jogo funciona em 3 fases: a leitura de quantidade de jogadores, que precisa ser entre 2 e 4; a leitura dos nomes dos jogadores, que funciona em um loop 'for' que é utilizado 
para inicializar os jogadores corretamente; e o Game loop principal, que é repetido até algum jogador zerar o jogo (chegar à casa 63).

   O Game Loop funciona usando uma função chamada dadoAleatorio(), que printa o resultado de dois dados aleatorios e retorna a soma deles, que é usada para dizer quantas casas 
o jogador que rodou os dados andou. Após andar as casas, o Ciclo chega se o jogador caiu em alguma das 6 Casas de Evento (citadas mais tarde) ou em alguma Casa de Ganso: Se ele 
tiver caído em uma Casa de Evento, será submetido ao efeito daquela casa; se cair em um Casa de Ganso ele roda os dados de novo e anda mais uma vez.

  O jogo termina quando o primeiro jogador chegar à casa 63, mas há um porém: É necessário cair exatamente na casa 63. Se for tirado, nos dados, um número maior do que o necessário, 
o jogador volta as casas "restantes" após bater na 63 e, se cair num ganso, terá de continuar voltando!

  No código, também foram usadas funções dos cabeçalhos time.h e stdio.h para rodas "animações" utilizando apenas caracteres ASCII. Mas estes, por sua vez, tem sua visualização 
otimizada utilizando o terminal do VSCode, podendo não funcionar corretamente quando visualizada diretamente pelo arquivo .exe

   Casas de Evento:
   
   Casa 6: A Ponte – avança até a casa 12.

  Casa 19: O Albergue – fica uma vez sem jogar.

  Casa 31: O Poço – espera outro jogador chegar ali e volta para a casa de onde ele saiu.

  Casa 42: O Labirinto – volta até a casa 37.

  Casa 52: A Prisão – fique 3 rodadas sem jogar.

  Casa 58: A Morte – retorna para recomeçar da casa número 1.
