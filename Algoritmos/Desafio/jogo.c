#include <stdio.h>
#include <windows.h>
#include <locale.h>

int main()
{
    SetConsoleOutputCP(65001); /** coloquei isso para aparecer os acentos, não consegui colocar o locale.h, não funcionou de jeito nenhum, a principio ele serve para deixar o console com a saída em UTF-8(codigo 65001)**/
    char nome[50];
    int item = 0, homemcurado = 0, senha = 0, senha2 = 0;
    int escolhaPrincipal = 0, escolhaDireita1 = 0, escolhaEsquerda1 = 0, escolhaDireita2 = 0, escolhaEsquerda2 = 0, escolhaItem = 0, escolhaItem2 = 0, voltarEsquerda = 0;
    int item2 = 0;
    
    printf(" Insira seu nome:  ");
    scanf("%s", nome);
    printf("\n Olá %s, bem vindo a torre secreta, você deve encontrar a saída. O que deseja levar nessa jornada?", nome);
    printf(" Os itens são: \n\n (1) - Espada\n (2) - Corda\n (3) - Tocha\n (4) - Poção de cura\n (5) - Poção de força\n (6) - Poção de fraqueza\n");
    printf("Escolha dois: ");
    
    /** validação **/
    while (item < 1 || item > 6)
    {
        scanf("%d", &item);
        if (item < 1 || item > 6)
        {
            printf("Inválido - Digite Novamente:");
        }
    }
    
    printf("Proximo item: ");
    while (item2 < 1 || item2 > 6)
    {
        scanf("%d", &item2);
        if (item2 < 1 || item2 > 6)
        {
            printf("Inválido - Digite Novamente:");
        }
    }
    /** fim validação de item*/

    printf(" Muito bem, agora para que lado você começa?\n");
    printf("Caminhos disponíveis:\n (1) - Esquerda\n (2) - Direita\n");
    printf("Caminho: ");

    while (escolhaPrincipal < 1 || escolhaPrincipal > 2)
    {
        scanf("%d", &escolhaPrincipal);

        if (escolhaPrincipal < 1 || escolhaPrincipal > 2)
        {
            printf("Inválido - Digite Novamente:");
        }
    }
     
    /** Inicio Caminho da esquerda **/
    
    if (escolhaPrincipal == 1)
    {
        printf("Você encontrou uma ponte.\n");
        printf("Opções disponíveis:\n (1) - Cruzar a ponte\n (2) - Voltar e ir para a direita\n");
        printf("Opção: ");
        scanf("%d", &escolhaEsquerda1);
        
        if(escolhaEsquerda1 == 2)
        {
            voltarEsquerda = 1;
        }
        
        else if(escolhaEsquerda1 == 1)
        {
            printf("Ao cruzar a ponte encontra um urso\n");
            
            if(item == 1 && item2 == 2 || item == 1 && item2 == 5 || item == 1 && item2 == 6 || item2 == 1 && item == 2 || item2 == 1 && item == 5 || item2 == 1 && item == 6 || item == 1 && item2 == 3 || item == 1 && item2 == 4 || item == 3 && item2 == 1 || item == 4 && item2 == 1)
            {
                printf("Opções disponíveis:\n (1) - Fugir\n (2) - Batalhar com o urso\n");
                printf("Opção: ");
                scanf("%d", &escolhaEsquerda2);
                
                if(escolhaEsquerda2 == 1)
                {
                    printf("O urso correu mais rápido que você e te devorou!");
                }
                
                else if(escolhaEsquerda2 == 2)
                {
                    printf("Após uma dura batalha você derrotou o urso, mas você está sangrando muito.\n");
                    printf("Você morreu!");
                }
            }
            
            else
            {
                printf("Opções disponíveis:\n (1) - Fugir\n");
                printf("Opção: ");
                scanf("%d", &escolhaEsquerda2);
                
                if(escolhaEsquerda2 == 1)
                {
                    printf("O urso correu mais rápido que você e te devorou!");
                }
            }
        }
    }
    
    /** Inicio Caminho da direita **/
    if (escolhaPrincipal == 2 || voltarEsquerda == 1)
    {
        printf("Você encontrou um homem muito debilitado, o que vai fazer?\n");
        printf("Opções disponíveis:\n (1) - Ignorá-lo\n (2) - Tentar ajudar\n");
        printf("Opção: ");
        scanf("%d", &escolhaDireita1);
        
        /** rota ignorar **/		
        if (escolhaDireita1 == 1)
        {
            printf("Após continuar o seu caminho, encontra uma porta, mas está escuro e não consegue abrir\n");
            
            if(item == 3 && item2 == 1 || item == 3 && item2 == 2 || item == 3 && item2 == 4 || item2 == 3 && item == 5 || item2 == 3 && item == 6 || item == 1 && item2 == 3 || item == 2 && item2 == 3 || item == 4 && item2 == 3 || item2 == 5 && item == 3 || item2 == 6 && item == 3)
            {
                printf("Opções disponíveis:\n (1) - Arrombar a porta\n (2) - Usar a tocha para iluminar\n");
                printf("Opção: ");
                scanf("%d", &escolhaDireita2);
                    
                    if(escolhaDireita2 == 1)
                    {
                        printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                    }
                        
                    if(escolhaDireita2 == 2)
                    {
                        printf("Na porta esta escrito que deve inserir uma senha para abri-la.\n");
                        printf("Opções disponíveis:\n (1) - Arrombar a porta\n (2) - Inserir uma senha\n");
                        printf("Opção: ");
                        scanf("%d", &senha);
                        
                        if(senha == 1) 
                        {
                            printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                        }
                        else
                        {
                            printf("Digite a senha: ");
                            scanf("%d", &senha2);
                            printf("Errou!\nUma horda de monstros surge das sombras e te devora.");
                        }
                    }
            }
            
            if(item != 3 || item2 != 3)
            {
                printf("Opções disponíveis:\n (1) - Arrombar a porta\n");
                printf("Opção: ");
                scanf("%d", &escolhaDireita2);
                
                if(escolhaDireita2 == 1)
                {
                    printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                }
            }
        }
        /** fim da rota ignorar **/
        
        /** inicio rota ajudar **/
        else if (escolhaDireita1 == 2)
        {
            printf("Você o sacode e percebe que ele está quase inconsciente e sofrendo, O que você pode fazer?\n");
            
            /** ter apenas item poção de cura **/
            if (item == 4 && item2 == 5 || item == 5 && item2 == 4 || item == 4 && item2 == 2 || item == 4 && item2 == 6 || item2 == 4 && item == 2 || item2 == 4 && item == 5 || item2 == 4 && item == 6)
            {
                printf("Opções disponíveis:\n (1) - Usar o item poção de cura\n");
                printf("Opção: ");
                scanf("%d", &escolhaItem);
                
                if(escolhaItem == 1)
                {
                    printf("Você curou o homem e ele te segue no resto da jornada\n");
                    homemcurado = 1;
                    printf("Vocês encontram uma porta, mas está muito escuro.\n");
                    printf("Opções disponíveis:\n (1) - Arrombar a porta\n");
                    printf("Opção: ");
                    scanf("%d", &escolhaDireita2);
                    printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                }
            }
            /** fim dessa rota **/
            
            /** rota espada e poção de cura **/
            else if (item == 4 && item2 == 1 || item == 1 && item2 == 4)
            {
                printf("Opções disponíveis:\n (1) - Usar o item poção de cura\n (2) - Usar o item espada\n");
                printf("Opção: ");
                scanf("%d", &escolhaItem);
                
                if(escolhaItem == 1)
                {
                    printf("Você curou o homem e ele te segue no resto da jornada\n");
                    homemcurado = 1;
                    printf("Vocês encontram uma porta, mas está muito escuro.\n");
                    printf("Opções disponíveis:\n (1) - Arrombar a porta\n");
                    printf("Opção: ");
                    scanf("%d", &escolhaDireita2);
                    printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                }
                
                if(escolhaItem == 2)
                {
                    printf("Você matou o homem e terminou com o seu sofrimento, pode seguir em frente\n\n...");
                    printf("Você encontrou uma porta, mas está muito escuro e não consegue abrir\n");
                    printf("Opções disponíveis:\n (1) - Arrombar a porta\n");
                    printf("Opção: ");
                    scanf("%d", &escolhaDireita2);
                    printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                }
            }
            /** fim dessa rota **/
            
            /** inicio rota da espada **/
            else if (item == 1 && item2 == 2 || item == 1 && item2 == 5 || item == 1 && item2 == 6 || item2 == 1 && item == 2 || item2 == 1 && item == 5 || item2 == 1 && item == 6)
            {
                printf("Opções disponíveis:\n (1) - Ignorá-lo e continuar a jornada \n (2) - Usar o item espada\n");
                printf("Opção: ");
                scanf("%d", &escolhaItem);
                
                if(escolhaItem == 1)
                {
                    printf("Você encontra uma porta, mas está muito escuro.\n");
                    printf("Opções disponíveis:\n (1) - Arrombar a porta\n");
                    printf("Opção: ");
                    scanf("%d", &escolhaDireita2);
                    printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                }
                
                if(escolhaItem == 2)
                {
                    printf("Você matou o homem e terminou com o seu sofrimento, pode seguir em frente\n\n...");
                    printf("Você encontrou uma porta, mas está muito escuro e não consegue abrir\n");
                    printf("Opções disponíveis:\n (1) - Arrombar a porta\n");
                    printf("Opção: ");
                    scanf("%d", &escolhaDireita2);
                    printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                }
            }
            /** fim da rota **/
            
            /** rota final do jogo **/
            else if ((item == 4 && item2 == 3) || (item == 3 && item2 == 4))
            {
                printf("Opções disponíveis:\n (1) - Usar o item poção de cura\n");
                printf("Opção: ");
                scanf("%d", &escolhaItem);
                
                if(escolhaItem == 1)
                {
                    printf("Você curou o homem e ele te segue no resto da jornada\n...\n");
                    homemcurado = 1;
                    printf("Vocês encontram uma porta, mas está muito escuro.\n");
                    
                    if(item == 3 || item2 == 3)
                    {
                        printf("Opções disponíveis:\n (1) - Arrombar a porta\n (2) - Usar a tocha para iluminar\n");
                        printf("Opção: ");
                        scanf("%d", &escolhaDireita2);
                        
                        if(escolhaDireita2 == 1)
                        {
                            printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                        }
                        
                        if(escolhaDireita2 == 2)
                        {
                            printf("Na porta esta escrito que deve inserir uma senha para abri-la.\n");
                            
                            if(homemcurado == 1)
                            {
                                printf("O homem que você salvou diz que sabe a senha\n O que você deseja fazer?\n ");
                                printf("Opções disponíveis:\n (1) - Deixar o homem digitar a senha\n (2) - Tentar você mesmo a senha\n");
                                printf("Opção: ");
                                scanf("%d", &senha);
                                
                                if(senha == 1) 
                                {
                                    printf("Parabéns, você conseguiu se libertar.");
                                }
                                else
                                {
                                    printf("Digite a senha: ");
                                    scanf("%d", &senha2);
                                    printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                                }
                            }
                        }
                    }
                }
            }
            /** fim da rota **/	
            
            /** inicio da rota apenas tocha **/
            else if ((item == 3 && item2 == 2) || (item == 3 && item2 == 5) || (item == 3 && item2 == 6) || (item == 5 && item2 == 3) || (item == 6 && item2 == 3) || (item == 6 && item2 == 3))
            {
                printf("Opções disponíveis:\n (1) - Ignorá-lo e continuar o caminho\n");
                printf("Opção: ");
                scanf("%d", &escolhaItem);
                
                if(escolhaItem == 1)
                {
                    printf("Você encontra uma porta, mas está muito escuro.\n");
                    printf("Opções disponíveis:\n (1) - Arrombar a porta\n (2) - Usar a tocha para iluminar\n");
                    printf("Opção: ");
                    scanf("%d", &escolhaDireita2);
                        
                    if(escolhaDireita2 == 1)
                    {
                        printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                    }
                        
                    if(escolhaDireita2 == 2)
                    {
                        printf("Na porta esta escrito que deve inserir uma senha para abri-la.\n");
                        printf("Opções disponíveis:\n (1) - Arrombar a porta\n (2) - Inserir uma senha\n");
                        printf("Opção: ");
                        scanf("%d", &senha);
                        
                        if(senha == 1) 
                        {
                            printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                        }
                        else
                        {
                            printf("Digite a senha: ");
                            scanf("%d", &senha2);
                            printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                        }
                    }
                }
            }
            /** fim da rota **/
            
            /** inicio tocha e espada **/
            else if ((item == 3 && item2 == 1) || (item == 1 && item2 == 3))
            {
                printf("Opções disponíveis:\n (1) - Ignorá-lo e continuar o caminho\n (2) - Usar a espada\n");
                printf("Opção: ");
                scanf("%d", &escolhaItem);
                
                 if(escolhaItem == 2)
                {
                    printf("Você matou o homem e terminou com o seu sofrimento, pode seguir em frente\n\n...");
                    printf("Você encontrou uma porta, mas está muito escuro e não consegue abrir\n");
                    printf("Opções disponíveis:\n (1) - Arrombar a porta\n (2) - Usar a tocha para iluminar\n");
                    printf("Opção: ");
                    scanf("%d", &escolhaDireita2);
                    
                    if(escolhaDireita2 == 1)
                    {
                        printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                    }
                        
                    if(escolhaDireita2 == 2)
                    {
                        printf("Na porta esta escrito que deve inserir uma senha para abri-la.\n");
                        printf("Opções disponíveis:\n (1) - Arrombar a porta\n (2) - Inserir uma senha\n");
                        printf("Opção: ");
                        scanf("%d", &senha);
                        
                        if(senha == 1) 
                        {
                            printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                        }
                        else
                        {
                            printf("Digite a senha: ");
                            scanf("%d", &senha2);
                            printf("Errou a senha!!\n Uma horda de monstros surge das sombras e te devora.");
                        }
                    }
                }
                
                else if(escolhaItem == 1)
                {
                    printf("Você encontrou uma porta, mas está muito escuro e não consegue abrir\n");
                    printf("Opções disponíveis:\n (1) - Arrombar a porta\n (2) - Usar a tocha para iluminar\n");
                    printf("Opção: ");
                    scanf("%d", &escolhaDireita2);
                    
                    if(escolhaDireita2 == 1)
                    {
                        printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                    }
                        
                    if(escolhaDireita2 == 2)
                    {
                        printf("Na porta esta escrito que deve inserir uma senha para abri-la.\n");
                        printf("Opções disponíveis:\n (1) - Arrombar a porta\n (2) - Inserir uma senha\n");
                        printf("Opção: ");
                        scanf("%d", &senha);
                        
                        if(senha == 1) 
                        {
                            printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                        }
                        else
                        {
                            printf("Digite a senha: ");
                            scanf("%d", &senha2);
                            printf("Errou a senha!!\n Uma horda de monstros surge das sombras e te devora.");
                        }
                    }
                }
            }
            /** fim da rota **/
            
            /** rota contendo nada importante **/
            else if(item == 2 || item == 6 || item == 5 || item2 == 2 || item2 == 6 || item2 == 5)
            {
                printf("Opções disponíveis:\n (1) - Ignorá-lo e continuar o caminho\n");
                printf("Opção: ");
                scanf("%d", &escolhaItem);
                	
                if(escolhaItem == 1)
                {
                    printf("Você encontra uma porta, mas está muito escuro.\n");
                    printf("Opções disponíveis:\n (1) - Arrombar a porta\n");
                    printf("Opção: ");
                    scanf("%d", &escolhaDireita2);
                        
                    if(escolhaDireita2 == 1)
                    {
                        printf("Ao arrombar a porta, uma horda de monstros surge das sombras e te devora.");
                    }
                }
            }
            /** fim da rota **/
        }
    }

    return 0;
}