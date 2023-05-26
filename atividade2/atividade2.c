/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*           UNIFAL − Universidade Federal de Alfenas.
*            BACHARELADO EM CIENCIA DA COMPUTACAO.
* Trabalho..: Atividade 2
* Disciplina: Programacao
* Professor.: Luiz Eduardo da Silva
* Aluno.....: Vinícius Eduardo de Souza Honório
* Data......: 23/07/2021
*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

#include <stdio.h>
#include <string.h>

int main (void)
{
	/* Variáveis da Matriz da imagem
	* i, j = usados para interação com as linhas e colunas da matriz
	* piso = representa a matriz que será usada para a impressão da imagem
	*/

	int i, j;
	int piso [20] [20];

	/* Variáveis de posição, movimentação e ação da tartagura
	* x, y = indicam as coordenadas de posição da tartaruga
	* n = variável usada para o cálculo do sentido
	* sentido = sentido para o qual a tartuga se encontra virada
	* passos = número de passos que a tartaruga deverá andar
	* caneta = indica a situação da caneta (abaixada ou levantada)
	* apagador = indica a situação do apagador (abaixado ou levantado)
	*/

	int x = 0;
	int y = 0;
	int n = 0;
	int sentido;
	int passos = 0;
    int caneta = 0;
	int apagador = 0;

	/* Variáveis de leitura das instruções
	* contador = usado para controlar repetições dentro do código
	* comando = armazena um comando que será executado
	*/

	int contador;
	char comando [3];
	
	/* Inicialização da Matriz, zerada */
	
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			piso [i] [j] = 0;
		}
	}
	
	/* Interpretação e execução dos comandos inseridos (A execução será feita logo após a leitura dos comandos) */

	scanf ("%s", comando);
    while (comando [0] != 'e')
    {
        switch (comando [0])
        {
            case 'u':
             caneta = 0;
			break;

            case 'd':
			 apagador = 0;
             caneta = 1;
			 piso [y] [x] = 1;
			break;
            
            /*
            * 0 = caneta levantada
            * 1 = caneta abaixada
            */
            
            case 'r':
             n++;
			break;

            case 'l':
             n--;
			break;
			 
             /*
             * 0 = direita
             * 1 = baixo
             * 2 = esquerda
             * 3 = cima
             *
             * n será usado para calcular valor que define o sentido "sentido = |n % 4|"
             */

			case 'w':
			 scanf ("%s", comando);
             while (n < 0)
             {
                 n = (n + 4);
			 }
             sentido = (n % 4);
			 for (contador = 0; contador < strlen (comando); contador++)
			 {
				 passos = passos * 10 + (comando [contador] - '0');
			 }
			 for (passos = passos; passos > 0; passos--)
			 {
				 switch (sentido)
				 {
					 case 0:
					  x++;
					 break;

					 case 1:
					  y++;
					 break;

					 case 2:
					  x--;
					 break;

					 case 3:
					  y--;
					 break;
				 }
				 if (caneta == 1)
				 {
					 piso [y] [x] = 1;
				 }
				 if (apagador == 1)
				 {
					 piso [y] [x] = 0;
				 }
			 }
			break;

			case 'p':
			 for (i = 0; i < 20; i++)
			 {
				 printf ("\n");
				 for (j = 0; j < 20; j++)
				 {
					 if (piso [i] [j] == 0)
					 {
						 printf (". ");
					 }
					 else
					 {
						 printf ("* ");
					 }
				 }
			 }
			 printf ("\n");
			break;

			case 'i':
			 for (j = 0; j < 20; j++)
			 {
				 for (i = 0; i < 20; i++)
				 {
					 if (piso [i] [j] == 0)
					 {
						 piso [i] [j] = 1;
					 }
					 
					 else
					 {
						 piso [i] [j] = 0;
					}
				 }
			 }
			break;

			case 'x':
			 caneta = 0;
			 apagador = 1;
			 piso [y] [x] = 0;
			break;

			/*
			* 0 = apagador levantado
			* 1 = apagador abaixado
			*/

			case 'b':
			 scanf ("%s", comando);
             while (n < 0)
             {
                 n = (n + 4);
             }
             sentido = (n % 4);
			 for (contador = 0; contador < strlen (comando); contador++)
			 {
				 passos = passos * 10 + (comando[contador] - '0');
			 }
			 for (passos = passos; passos > 0; passos--)
			 {
				 switch (sentido)
				 {
					 case 0:
					  x--;
					 break;

					 case 1:
					  y--;
					 break;

					 case 2:
					  x++;
					 break;

					 case 3:
					  y++;
					 break;
				 }
				 if (caneta == 1)
				 {
					 piso [y] [x] = 1;
				 }
				 if (apagador == 1)
				 {
					 piso [y] [x] = 0;
				 }
			 }
			break;
        }
		scanf ("%s", comando);
		if (x > 19 || x < 0 || y > 19 || y < 0)
		{
			printf ("A tartaruga saiu da grade");
			comando [0] = 'e';
		}
    }
	return 0;
}

/*
*   - Comandos Adicionais -
* i = Inverte o desenho ("." vira "*" e vice-versa).
* b n = Faz a tartaruga andar n passos, mas para trás.
* x = Ativa o "Modo Apagador" (a tartaruga passa a apagar em vez de escrever).¹ ²
*   1 = Caso seja ativado enquanto a caneta estiver abaixada, esta será automaticamente levantada.
*   2 = O comando "u" faz com que ambos a caneta e o apagador sejam levantados.
*/