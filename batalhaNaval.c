#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    #include <stdio.h>

int menu_direcao(){

    int menu;

    printf("Em qual sentido deseja inserir o navio?\n");
    printf("1 - Horizontal.\n");
    printf("2 - Vertical.\n");
    printf("3 - diagonal.\n");
    scanf("%d", &menu);

    return menu;

}

int main(){
    int opcao;
    int rep = 0;   
    int linha;
    int coluna;
    int tabuleiro[10][10] = {
                                
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0}
                                
                            };

// Nesta etapa eu vou exibir o tabuleiro completamente preenchido por 0, representando a água.

    for(int i = 0 ; i < 10 ; i++){
            for(int j = 0 ; j < 10 ; j++){

                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    while(rep != 2){
    // Nessa etapa vou selecionar 

        opcao = menu_direcao();

        if(opcao == 1){
            
            printf("selecione a linha onde quer posicionar o navio\n");
            scanf("%d", &linha);
            printf("selecione a coluna onde quer posicionar o navio\n");
            scanf("%d", &coluna);

            if( (coluna > 8 || coluna < 1) || (tabuleiro[linha - 1][coluna - 1] == 3 && tabuleiro[linha - 1][coluna] == 3 && tabuleiro[linha - 1][coluna + 1] == 3) ) {

                printf("A posicao selecionada é inválida ou excede as casas do tabuleiro..");

            }else{

            for(int j = coluna ; j < coluna + 3 ; j++){

                tabuleiro[linha - 1][j - 1] = 3;
            }

            for(int i = 0 ; i < 10 ; i++){
                for(int j = 0 ; j < 10 ; j++){

                    printf("%d ", tabuleiro[i][j]);
                }
                printf("\n");
            }

            }
        }else if(opcao == 2){

            printf("selecione a linha onde quer posicionar o navio\n");
            scanf("%d", &linha);
            printf("selecione a coluna onde quer posicionar o navio\n");
            scanf("%d", &coluna);

            if( linha > 8 || linha < 1 || tabuleiro[linha - 1][coluna - 1] == 3 || tabuleiro[linha][coluna - 1] == 3 || tabuleiro[linha + 1][coluna - 1] == 3){


                printf("A posicao selecionada é inválida ou excede as casas do tabuleiro..");
            
            }else{
                for(int i = linha ; i < linha + 3 ; i++){
                    
                    tabuleiro[i - 1][coluna - 1] = 3;
                }

                for(int i = 0 ; i < 10 ; i++){
                    for(int j = 0 ; j < 10 ; j++){

                        printf("%d ", tabuleiro[i][j]);
                    }
                    printf("\n");
                }        
            }   
        }

        rep++;
    }
}

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
#include <stdio.h>

int menu(){
    int escolha;

    printf("------BATALHA NAVAL------\n");
    printf("Selecione o sentido que deseja posicionar o navio:\n");
    printf("1 - Horizontal.\n");
    printf("2 - Vertical.\n");
    printf("3 - Diagonal.\n\n");
    scanf("%d", &escolha);

    if(escolha > 3 || escolha < 1){
        printf("Selecione uma opcao valida...\n\n");

    }else{
        return escolha;  
    }
}

int cordlinha(){
    int i;

    printf("Digite a coordenada da linha onde deseja posicionar o navio:");
    scanf("%d", &i);

    return i;
}

int cordcoluna(){
    int j;

    printf("Digite a coordenada da coluna onde deseja posicionar o navio:");
    scanf("%d", &j);

    return j;
}

int main(){
    int tabuleiro[10][10];
    int linha;
    int opcao;
    int coluna;

//tabuleiro
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            tabuleiro[i][j] = 0;

            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

//Menu de selecao de posicionamento do navio
    int rep = 0;

    while(rep < 4){
        opcao = menu();
        
        if(opcao == 1){
            linha = cordlinha();
            coluna = cordcoluna();
                if(tabuleiro[linha - 1][coluna - 1] == 3 || tabuleiro[linha - 1][coluna] == 3 || tabuleiro[linha - 1][coluna + 1] == 3 || linha > 10 || linha < 1 || coluna < 1 || coluna > 8){
                    printf("Posicao invalida...\n");

                }else{
                    for(int i = coluna ; i < coluna + 3 ; i++){
                        tabuleiro[linha - 1][i - 1] = 3;
                    }

                    for(int i = 0 ; i < 10 ; i++){
                        for(int j = 0 ; j < 10 ; j++){
                        
                            printf("%d ", tabuleiro[i][j]);
                        }
                    printf("\n");
                    }
                }
                

        }else if(opcao == 2){
            linha = cordlinha();
            coluna = cordcoluna();
                if(tabuleiro[linha - 1][coluna - 1] == 3 || tabuleiro[linha][coluna - 1] == 3 || tabuleiro[linha + 1][coluna - 1] == 3 || linha > 8 || linha < 1 || coluna > 10 || coluna < 1 ){
                    printf("Posicao invalida...");

                }else{
                    for(int i = linha ; i < linha + 3 ; i++){
                        tabuleiro[i - 1][coluna - 1] = 3;
                    }

                    for(int i = 0 ; i < 10 ; i++){
                        for(int j = 0 ; j < 10 ; j++){
                        
                            printf("%d ", tabuleiro[i][j]);
                        }
                    printf("\n");
                    }
            }

        }else if(opcao == 3){
            linha = cordlinha();
            coluna = cordcoluna();
                if(tabuleiro[linha - 1][coluna - 1] == 3 || tabuleiro[linha][coluna] == 3 || tabuleiro[linha + 1][coluna + 1] == 3 || linha > 8 || linha < 1 || coluna > 10 || coluna < 1 ){
                    printf("Posicao invalida...");
                    
                }else{
                    for(int i = linha, j = coluna ; i < linha + 3 ; i++, j++){
                        tabuleiro[i - 1][j - 1] = 3;
                    }

                    for(int i = 0 ; i < 10 ; i++){
                        for(int j = 0 ; j < 10 ; j++){
                        
                            printf("%d ", tabuleiro[i][j]);
                        }
                    printf("\n");

                    }
                }
        rep++;
        }
    }
}
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
