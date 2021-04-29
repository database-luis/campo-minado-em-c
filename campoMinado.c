//Luis Gustavo Cardoso dos Santos - 21950639
//=============================================
//TRABALHO PRATICO 1 DE AED I
//=============================================

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//PROTÓTIPO Q MOSTRA A QT DE BOMBAS AO REDOR
int n_bombas(int l, int c,  int n, char M[][n]);

// PROTOTIPO Q IMPRIME A MATRIZ
void imprime_mat(int n, char mat[][n]);

//PROTOTIPO Q SORTEIA BOMBAS ALEATORIAMENTE
void sortearBombas(int n, char mat[][n]);

//PROTOTIPO QUE COLOCA AS BOMBAS NA MATRIZ
void colocarBombas(int n, char mat[][n]);

//PROTOTIPO Q DIZ SE UMA COORDENADA É BOMBA
void eh_bomba (int *l, int *c, int n, char matR[][n], char mat[][n]);

//PROTOTIPO QUE RECEBE AS ENTRADAS
void ler_elementos(int *l, int *c, int n, char mat[][n], char matR[][n]);

//PROTOTIPO QUE FAZ A CONVERSAO DE INT PRA CHAR
void converte_n_bomba(int n, char m[][n]);

//PROTOTIPO QUE FAZ O JOGO RODAR
void jogo(int *l, int *c, int n, char mat[][n], char matR[][n]);
//======================================================================================================

void imprime_mat(int n, char mat[][n]){
    int conti, contj;

    for(conti = 0; conti < n; conti++){
        
        printf("%d |", conti + 1);
        for(contj = 0; contj < n; contj++){
            printf("%c ", mat[conti][contj]);
        }
        printf("\n");
        
    }


    printf("  ");
    for(contj = 0; contj < n; contj++){
        printf("--");
    }
    
    printf("\n");
    printf("   ");

    for(contj = 0; contj < n; contj++){
        printf("%d ", contj + 1);
    }

    printf("\n");
}

void ler_elementos(int *l, int *c, int n, char mat[][n], char matR[][n]){
    printf("Digite a linha e a coluna desejada: ");
    scanf("%d %d", l, c);

    if(*l < 1 || *l > n || *c < 1 || *c > n){
        printf("Entrada invalida.\n");
        imprime_mat(n, mat);
        ler_elementos(l, c, n, mat, matR);
    }

    else{
        mat[*l-1][*c-1] = matR[*l-1][*c-1];
        eh_bomba(l, c, n, matR, mat);
    }
}

void eh_bomba(int *l, int *c, int n, char matR[][n], char mat[][n]){
    int conti, contj;

    if(matR[*l-1][*c-1] == '*'){
        printf("VOCE PERDEU! FIM DO JOGO.\n");
        for(conti = 0; conti < n; conti++){
            for(contj = 0; contj < n; contj++){
                if(matR[conti][contj] == '*')
                    mat[conti][contj] = matR[conti][contj];
            }
        }
        
        imprime_mat(n, mat);
    }

    else{
        jogo(l, c, n, mat, matR);
    }
}

void jogo(int *l, int *c, int n, char mat[][n], char matR[][n]){
    int conti, contj, acum, sinal;
    
    acum = n*n;
    sinal = 0.2*(n * n);

    for(conti = 0; conti < n; conti++){
        for(contj = 0; contj < n; contj++){
            if(mat[conti][contj] != '?'){
                acum--;
            }
        }
    }

    if(acum != sinal){
        mat[*l-1][*c-1] = matR[*l-1][*c-1];
        imprime_mat(n, mat);
        ler_elementos(l, c, n, mat, matR);
    }

    else{
        printf("PARABENS!! VOCE VENCEU!");
        printf("\n");
        imprime_mat(n, matR);
    }
}

int n_bombas(int l, int c, int n, char mat[][n]){
	int numBomb;
	
	numBomb = 0;
	
	if(mat[l][c] != '*'){
		if(l == 0 && c == 0){
			if(mat[l][c+1] == '*'){
				numBomb++;
			}
			if(mat[l+1][c] == '*'){
				numBomb++;
			}
			if(mat[l+1][c+1] == '*'){
				numBomb++;
			}
			return numBomb;
		}
		
		else if(l == 0 && c == n - 1){
			if(mat[l][c-1] == '*'){
				numBomb++;
			}
			if(mat[l+1][c-1] == '*'){
				numBomb++;
			}
			if(mat[l+1][c] == '*'){
				numBomb++;
			}
			return numBomb;
		}
		
		else if((l == 0 && c != n - 1) && (l == 0 && c != 0)){
			if(mat[l][c-1] == '*'){
				numBomb++;
			}
			if(mat[l][c+1] == '*'){
				numBomb++;
			}
			if(mat[l+1][c-1] == '*'){
				numBomb++;
			}
			if(mat[l+1][c] == '*'){
				numBomb++;
			}
			if(mat[l+1][c+1] == '*'){
				numBomb++;
			}
			return numBomb++;
		}
		
		else if(l == n - 1 && c == 0){
			if(mat[l-1][c] == '*'){
				numBomb++;
			}
			if(mat[l-1][c+1] == '*'){
				numBomb++;
			}
			if(mat[l][c+1] == '*'){
				numBomb++;
			}
			return numBomb;
		}
		
		else if(l == n - 1 && c == n - 1){
			if(mat[l-1][c-1] == '*'){
				numBomb++;
			}
			if(mat[l-1][c] == '*'){
				numBomb++;
			}
			if(mat[l][c-1] == '*'){
				numBomb++;
			}
			return numBomb;
		}
		
		else if((l == n - 1 && c != n - 1) && (l == n - 1 && c != 0)){
			if(mat[l-1][c-1] == '*'){
				numBomb++;
			}
			if(mat[l-1][c] == '*'){
				numBomb++;
			}
			if(mat[l-1][c+1] == '*'){
				numBomb++;
			}
			if(mat[l][c-1] == '*'){
				numBomb++;
			}
			if(mat[l][c+1] == '*'){
				numBomb++;
			}
			return numBomb;
		}
		
		else if(l != 0 && c == 0){
			if(mat[l-1][c] == '*'){
				numBomb++;
			}
			if(mat[l-1][c+1] == '*'){
				numBomb++;
			}
			if(mat[l][c+1] == '*'){
				numBomb++;
			}
			if(mat[l+1][c+1] == '*'){
				numBomb++;
			}
			if(mat[l+1][c] == '*'){
				numBomb++;
			}
			return numBomb++;
		}
		
		else if(l != 0 && c == n - 1){
			if(mat[l-1][c] == '*'){
				numBomb++;
			}
			if(mat[l-1][c-1] == '*'){
				numBomb++;
			}
			if(mat[l][c-1] == '*'){
				numBomb++;
			}
			if(mat[l+1][c-1] == '*'){
				numBomb++;
			}
			if(mat[l+1][c] == '*'){
				numBomb++;
			}
			return numBomb;
		}
		
		else{
			if(mat[l-1][c-1] == '*'){
				numBomb++;
			}
			if(mat[l-1][c] == '*'){
				numBomb++;
			}
			if(mat[l-1][c+1] == '*'){
				numBomb++;
			}
			if(mat[l][c-1] == '*'){
				numBomb++;
			}
			if(mat[l][c+1] == '*'){
				numBomb++;
			}
			if(mat[l+1][c-1] == '*'){
				numBomb++;
			}
			if(mat[l+1][c] == '*'){
				numBomb++;
			}
			if(mat[l+1][c+1] == '*'){
				numBomb++;
			}
			return numBomb;
		}
	}
	
	return 0;
}


void converte_n_bomba(int n, char mat[][n]){
    int conti, contj, numBomb;
    char paraChar;

    for(conti = 0; conti < n; conti++){
        for(contj = 0; contj < n; contj++){
            numBomb = n_bombas(conti, contj, n, mat);
            if(numBomb > 0){
                paraChar = numBomb + '0';
                mat[conti][contj] = paraChar;
            }
        }
    }
}

void sortearBombas(int n, char mat[][n]){

	int linhaAleat, colunaAleat;

    linhaAleat = rand() % n;
    colunaAleat = rand() % n;
    if(mat[linhaAleat][colunaAleat] == '*') {
	    sortearBombas(n, mat);
    }
    
    else {
	    mat[linhaAleat][colunaAleat] = '*';
	}
}

void colocarBombas(int n, char mat[][n]){
    int taxa, cont;
    taxa = 0.2 * (n * n);

    for(cont = 0; cont < taxa; cont++){
        sortearBombas(n, mat);
    }
}

void preencheMat(int n, char mat[][n]){
    int conti, contj;
    char carac;

    carac = '0';

    for(conti = 0; conti < n; conti++){
        for(contj = 0; contj < n; contj++){
            mat[conti][contj] = carac;
        }
    }
}


int main(){
    int n, conti, contj, l, c;

    printf("Digite o tamanho da matriz desejada: ");
    scanf("%d", &n);
    char mat[n][n], matR[n][n];

    srand(time(NULL));

    converte_n_bomba(n, matR);

    for(conti = 0; conti < n; conti++){
        for(contj = 0; contj < n; contj++){
            matR[conti][contj] = '0';
        }
    }
    
    colocarBombas(n, matR);
    converte_n_bomba(n, matR);
    
    for(conti = 0; conti < n; conti++){
        for(contj = 0; contj < n; contj++){
            mat[conti][contj] = '?';
        }
    }
    
    imprime_mat(n, mat);
    ler_elementos(&l, &c, n, mat, matR);

}