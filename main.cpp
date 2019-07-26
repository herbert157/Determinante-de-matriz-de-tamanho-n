#include <iostream>
#include <locale.h>

void printar_matriz(int qtdlinha,int qtdcoluna,float **matriz);
float Multi_diagonal(int qtdlinha,int qtdcoluna, float **matriz);
float **Alocar_matriz(int qtdlinha,int qtdcoluna);	
float **pivor_zero(int qtdlinha,int qtdcoluna,int contador1,int contador2,float **matriz);


int main(int argc, char** argv) {
	
	int qtdlinha,qtdcoluna,contador1=0,contador2=0;
	float aux1,aux2;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("******Programa para calcular o determinante de uma matriz quadratica******\n\nDigite a dimensão da matriz\n");
	scanf("%d",&qtdlinha);
	
	qtdcoluna=qtdlinha;	
	
	float **matriz=Alocar_matriz(qtdlinha,qtdcoluna);
	
	for(int i=0;i<qtdlinha;i++){
		for(int j=0;j<qtdcoluna;j++){
			printf("Digite o %d elemento da matriz:\n",(j+1)+(i)*(qtdcoluna));
			scanf("%f",&matriz[i][j]);
		}
	}	
	
	float *coluna_aux= new float[qtdcoluna];
	
	printar_matriz(qtdlinha,qtdcoluna,matriz);
	
	while(contador2!=qtdcoluna){
		printf("\n");
		aux1=matriz[contador1][contador2];
		
		for(int i=0;i<qtdcoluna;i++){
			coluna_aux[i]=matriz[contador1][i];
		}
	
		if((matriz[contador1][contador2]!=1)&&(matriz[contador1][contador2]!=0)){
			for(int i=0;i<qtdcoluna;i++){
				coluna_aux[i]=coluna_aux[i]/aux1;
			}
	 	}
		
		if(matriz[contador1][contador2]==0){

			matriz=pivor_zero(qtdlinha,qtdcoluna,contador1,contador2,matriz);
			aux1=matriz[contador1][contador2];
			
			for(int j=0;j<qtdcoluna;j++){
				coluna_aux[j]=matriz[contador1][j];				
			}
			
			if(aux1!=0){
				for(int i=0;i<qtdcoluna;i++){
					coluna_aux[i]=coluna_aux[i]/aux1;
				}
			} 
			for(int i=0;i<qtdcoluna;i++){				 
				matriz[contador1][i]=(-1)*matriz[contador1][i];             
			}
		
		}
		
		for(int i=0;i<qtdlinha;i++){
			aux2=matriz[i][contador2];
			for(int j=0;j<qtdcoluna;j++){
				if(i!=contador1){
					matriz[i][j]=matriz[i][j]-aux2*(coluna_aux[j]);
				}	
			}
		}
		
		contador1++;contador2++;		
		printar_matriz(qtdlinha,qtdcoluna,matriz);		
	}
	float determinante=Multi_diagonal(qtdlinha,qtdcoluna,matriz);
	
	printf("\n==>O determinante dessa matriz é igual a %.3f\n",determinante);	
	
	
	for(int i=0;i<qtdlinha;i++){
		delete matriz[i];
	}
	
	delete matriz;
	
	delete coluna_aux;	

	return 0;
}


void printar_matriz(int qtdlinha,int qtdcoluna,float **matriz){
	
	for(int i=0;i<qtdlinha;i++){
		for(int j=0;j<qtdcoluna;j++){
			printf(" %.2f ",matriz[i][j]);
		}
		printf("\n");	
	}
	
}
	
float Multi_diagonal(int qtdlinha,int qtdcoluna, float **matriz){
	
	float determinante=1;
	
	for(int i=0;i<qtdlinha;i++){
		determinante=determinante*matriz[i][i];
	}
	
	return determinante;
}

float **Alocar_matriz(int qtdlinha,int qtdcoluna){
	
	float **matriz=new float*[qtdlinha];
	
	for(int i=0;i<qtdlinha;i++){
		matriz[i]=new float[qtdcoluna];
	}	
	return matriz;	
}

float **pivor_zero(int qtdlinha,int qtdcoluna,int contador1,int contador2,float **matriz){
	float aux;
	
	float *aux2;
	
	for(int i=contador1;i<qtdlinha;i++){
		aux=matriz[i][contador2];
		if(aux!=0){
			aux2=matriz[contador1];
			matriz[contador1]=matriz[i];
			matriz[i]=aux2;
			break;
		}
	}
	return matriz;
}
	
