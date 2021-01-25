#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#define TAM 50
typedef struct{
 	char name[30];
 	int codigo;
 	float renda;
 	int x;
 }candidato;
 
char cabecalho(int tam){
	int i;
	for(i=0;i<=tam;++i){
		printf("=");
	}
}
int main(void){
 	int qn,num,i,j,OP,high,a=0,b;
 	int cont=0,aux;
 	float percent;
 	char highName[20];
 	setlocale(LC_ALL,"");
	
 	printf("Informe a quantidade de candidatos: ");
 	scanf("%d",&qn);
 	candidato cand[qn];
 	
 		for(i=0;i<qn;++i){
 			
 			fflush(stdin); //
 			printf("\nDigite o nome do %dº candidato: ",i+1);
 			gets(cand[i].name);
 			printf("Digite o número do %dº candidato: ",i+1);
 			scanf("%d",&cand[i].codigo);
 			printf("Digite a renda do %dº candidato: ",i+1);
 			scanf("%f",&cand[i].renda);
 			cand[i].x=0;
 			cabecalho(35);
 			printf("\n");
		 }
 	do{
 		system("cls");
 		printf("	| CANDIDATOS CADASTRADOS |\n");
 			for(i=0;i<qn;++i)
 				printf("%dºCANDIDATO: Nome:%-10s 	Número do candidato:%-25d\n",i+1,cand[i].name,cand[i].codigo);
		printf("=========== MENU URNA ELETRÔNICA ===============\n");
		printf("1.Registrar voto\n");
		printf("2.Apuracao por quantidade de votos\n");
		printf("3.Apuracao em porcentagem\n");
		printf("4.Encerrar votação e eleger candidato\n");
		printf("5.Sair do programa\n");
		scanf("%d",&OP);
		switch(OP){
			case 1:
				aux=0;
			    printf("Informe o número do seu candidato para realizar o voto: ");
			    scanf("%d",&num);
			    
			       	for(i=0;i<qn;++i){
			       		if(num == cand[i].codigo){
			       			cont++;
			       			aux++;
			       			cand[i].x++;
						}
					}
				if(aux == 0)
					printf("# ERRO - O NÚMERO DIGITADO NÃO EXISTE\n");
				else
					printf("SEU VOTO FOI REGISTRADO \n");	   
				system("pause");
			break;
			
			case 2:
				for(i=0;i<qn;++i)
					printf("%dºCANDIDATO: Nome:%-10s 	Número candidato:%-25d  | VOTOS = %d votos\n",i+1,cand[i].name,cand[i].codigo,cand[i].x);	
				system("pause");
			break;
			
			case 3:
				//printf("CONT %d\n",cont);
				for(i=0;i<qn;++i){
					percent = 0;
					percent = (cand[i].x * 100) / cont; // total voto do candidato * 100 / pelo total de votos
					printf("%dºCANDIDATO: Nome:%-10s 	Número candidato:%-25d  | PERCENTUAL = %.1f porcento \n",i+1,cand[i].name,cand[i].codigo,percent);	
				}
				system("pause");
			break;
			
			case 4:
				high = cand[0].x;
				//strcpy(highName,cand[0].name);
				//a=0;
				b=0;
				for(i=0;i<cont;++i){
					for(j=i+1;j<cont;++j){
						if(cand[j].x > high){
							high = cand[j].x;
							//highName = cand[j].name;
							strcpy(highName,cand[j].name);
						}
					}						
				}
				printf("Vencedor: %s %d voto[s]\n",highName,high);
				system("pause");
				OP = 5;
			break;
			
			case 5:
				printf("\n  O programa será finalizado  ... \n");
				system("pause");
			break;
			
			default:
				printf("\n	Opção inválida !! \n");
				system("pause");
			break;
		}	
	 }while(OP != 5);
}
