/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*           UNIFAL − Universidade Federal de Alfenas.
*            BACHARELADO EM CIENCIA DA COMPUTACAO.
* Trabalho..: Atividade 1
* Disciplina: Programacao
* Professor.: Luiz Eduardo da Silva
* Aluno.....: Vinícius Eduardo de Souza Honório
* Data......: 02/07/2021
*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

#include <stdio.h>

int main (void)
{
	/* Declaração das variáveis para a coleta dos dados fornescidos */
	
	int id;
	char sexo;
	int idade;
	
	/* Declaração das variáveis para o cálculo das informações retornadas */
	
	float somaIdade = 0;
	float somaPessoas = 0;
	int somaHomens = 0;
	int somaMulheres = 0;
	int somaOutros = 0;
	float mediaIdade = 0.0;
	int maiorIdade, maiorId, menorIdade, menorId;
	
	/* Leitura dos dados inseridos pelo usuário */

	printf ("\nQuando for digitado '0' na entrada do ID, 'x' na entrada do sexo e '0' na entrada da idade; o programa irá processar os dados informados");
	
	printf ("\nDigite o ID de quatro dígitos, o sexo (M/F/O) e a idade da pessoa; separados por espaço: ");
	 scanf ("%d %c %d", &id, &sexo, &idade);
	
	maiorIdade = idade;
	maiorId = id;
	menorIdade = idade;
	menorId = id;
	
	/* Inserção dos dados nas variáveis de calculo da tabela */
	
	while (id != 0 && sexo != 'x' && idade != 0)
	{
		somaIdade = (somaIdade + idade);

		somaPessoas = (somaPessoas + 1);
		
		if (sexo == 'm' || sexo == 'M')
		{
			somaHomens = (somaHomens + 1);
		}
		else
		{
			if (sexo == 'f' || sexo == 'F')
			{
				somaMulheres = (somaMulheres + 1);
			}
			else
			{
				somaOutros = (somaOutros + 1);
			}
		}

		if (idade >= maiorIdade)
		{
			maiorIdade = idade;
			maiorId = id;
		}
		
		if (idade <= menorIdade)
		{
			menorIdade = idade;
			menorId = id;
		}
		
		printf ("Digite o ID de quatro dígitos, o sexo (M/F/O) e a idade da pessoa; separados por espaço: ");
		 scanf ("%d %c %d", &id, &sexo, &idade);
	}
	
	mediaIdade = (somaIdade / somaPessoas);
	
	/* Impressão da tabela de resultados */

	printf ("\n+------------------+--------+");
	printf ("\n| Soma das idades  |%7.0f |", somaIdade);
	printf ("\n| Total de pessoas |%7.0f |", somaPessoas);
	printf ("\n| Media de idades  |%7.1f |", mediaIdade);
	printf ("\n| Homens           |%7d |", somaHomens);
	printf ("\n| Mulheres         |%7d |", somaMulheres);
	printf ("\n| Outros           |%7d |", somaOutros);
	printf ("\n| Maior idade      |%7d |", maiorIdade);
	printf ("\n| ID do mais velho |%7d |", maiorId);
	printf ("\n| Menor idade      |%7d |", menorIdade);
	printf ("\n| ID Do mais novo  |%7d |", menorId);
	printf ("\n+------------------+--------+");
	return 0;
}