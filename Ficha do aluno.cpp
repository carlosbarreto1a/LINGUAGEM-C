#include <stdio.h>
#include <string.h>

struct FichaDeAluno {
	char nome[50];
 	char disciplina[30];
 	float notaProva1;
 	float notaProva2;
};

int main() {
	struct FichaDeAluno aluno1, aluno2, alunos[10];
	
	strcpy(aluno1.nome, "Maria");
	strcpy(aluno1.disciplina, "LP");
	aluno1.notaProva1 = 7.5;
	aluno1.notaProva2 = 10;
	
	printf("ALUNO 1:\n");
	printf("%s\n", aluno1.nome);
	printf("%s\n", aluno1.disciplina);
	printf("%.2f\n", aluno1.notaProva1);
	printf("%.2f\n\n", aluno1.notaProva2);
	
	fflush(stdin);
	printf("Informe o nome do aluno 2: ");
	gets(aluno2.nome);
	
	printf("Informe a disciplina do aluno 2: ");
	gets(aluno2.disciplina);
	
	printf("Informe a nota da prova 1 do aluno 2: ");
	scanf("%f", &aluno2.notaProva1);	
		
	printf("Informe a nota da prova 2 do aluno 2: ");
	scanf("%f", &aluno2.notaProva2);	
	
	printf("\nALUNO 2:\n");
	printf("%s\n", aluno2.nome);
	printf("%s\n", aluno2.disciplina);
	printf("%.2f\n", aluno2.notaProva1);
	printf("%.2f\n\n", aluno2.notaProva2);
	
	alunos[0].notaProva1 = 10;
	alunos[0].notaProva2 = 7.7;

	for(int i = 0; i < 10; i++) {
		fflush(stdin);
		printf("Informe o nome do aluno %d: ", i);
		gets(alunos[i].nome);
		
		printf("Informe a disciplina do aluno %d: ", i);
		gets(alunos[i].disciplina);
		
		printf("Informe a nota da prova 1 do aluno %d: ", i);
		scanf("%f", &alunos[i].notaProva1);	
			
		printf("Informe a nota da prova 2 do aluno %d: ", i);
		scanf("%f", &alunos[i].notaProva2);		
	}
}




