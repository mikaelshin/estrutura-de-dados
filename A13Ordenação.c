#include <stdio.h>
#define n 10

//selectionsort
void selectionSort(int[] vetor){
    int aux, i, j, min;
    for(i = 0; i = n - 2; i++){
        min = i;
        for(j = i + 1; i < n - 1; i++){
            if(vetor[min] > vetor[j]){
                min = j;
            }    
            aux = vetor[min];
            vetor[min] = vetor[i];
            vetor[i] = aux;
        }
    }
}

//bubblesort
void bubbleSort(int[] vetor){
    int aux, i, j, trocas;
    for(i = n - 1; i >= 0; i--){
        trocas = 0;
        for(j = 1; j < i; j++){
            if(vetor[j - 1] < vetor[j]){
                aux = vetor[j - 1];
                vetor[j - 1] = vetor[j]; 
                vetor[j] = aux;
                trocas++;
            }
        }
        if(trocas == 0)
            break;
    }
}

//mergesort
void mergeSort(int[] vetor, int ini, int fim){
    int meio;
    if(ini < fim){
        meio = (ini + fim)/2
        mergeSort(vetor, ini, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, ini, meio, fim);
    }
}

void merge(int[] vetor, int ini, int meio, int fim){
    int c1 = ini;
    int c2 = meio + 1;
    int aux = 0;
    int tam = fim - ini + 1;
    int *vetAux;
    vetAux = (int*) malloc(tam*sizeof(int));

    while(c1 <= meio && c2 <= fim){
        if(vetor[c1] < vetor[c2]){
            vetAux[aux] = vetor[c1];
            c1++;
        } else {
            vetAux[aux] = vetor[c2];
            c2++;
        }
        aux++;
    }

    while(c1 <= meio){
        vetAux[aux] = vetor[c1]
        aux++;
        c1++;
    }
    
    while(c2 <= fim){
        vetAux[aux] = vetor[c2];
        aux++;
        c2++;
    }
    
    for(aux = ini; aux < fim; aux++){
        vetor[aux] = vetAux[aux - 1];
    }
    free(vetAux);
}

/* COUTINHO:

	public static void merge(int [] a, int ini, int med, int fim){
	
		int [] b = new int[fim - ini + 1];
		int i = ini;
		int j = med + 1;
		int k = 0;

		while(i <= med && j <= fim) {

			if(a[i] <= a[j]){
		
				b[k] = a[i];
				i++;
			}
			else {

				b[k] = a[j];
				j++;
			}

			k++;
		}

		while(i <= med) {

			b[k] = a[i];
			i++;
			k++;
		}

		while(j <= fim) {

			b[k] = a[j];
			j++;
			k++;
		}

		for(k = 0; k < b.length; k++){

			a[ini + k] = b[k];
		}
	}

	public static void mergeSortRec(int [] a, int ini, int fim){

		if(ini < fim){

			int med = (ini + fim) / 2;

			mergeSortRec(a, ini, med);
			mergeSortRec(a, med + 1, fim);
			merge(a, ini, med, fim);
		}
	}

*/


//quicksort

void quickSort(int[] vetor, int ini, int fim){
    int p;
    if(ini < fim){
        p = partition(vetor, ini, fim);
        quickSort(vetor, i, p - 1);
        quickSort(vetor, p + 1, fim);
    }
}

void partition(int[] vetor, int ini, int fim){
    int ultElem = vetor[fim];
    int priPos = ini - 1;
    int ultPos = fim;
    int aux;
    ///////////////////////
    do {
        do {
            priPos++;
        } while (vetor[priPos] < ultElem && priPos < fim);
        do {
            ultPos--;
        } while(vetor[ultPos] > ultElem && ultPos > 0);
        aux = vetor[priPos];
        vetor[priPos] = vetor[ultPos];
        vetor[ultPos] = aux;
    } while (priPos > ini)
    ////////////////////////
    vetor[ultPos] = vetor[priPos];
    vetor[priPos] = vetor[fim];
    vetor[fim] = aux;
    return priPos;
}

/* COUTINHO:

	public static int particiona(int [] a, int ini, int fim){

		int x = a[ini];
		int i = ini - 1;
		int j = fim + 1;

		while(true){

			do{ 
				j--;

			} while(a[j] > x);
			
			do{
				i++;

			} while(a[i] < x);

			if(i < j){

				// troca a[i] com a[j]

				int temp = a[i];
				a[i] = a[j]; 				
				a[j] = temp;
			}
			else return j;
		}
	}

	public static void quickSortRec(int [] a, int ini, int fim){

		if(ini < fim) {

			// subvetor a[ini .. fim] tem pelo menos 2 elementos

			int q = particiona(a, ini, fim);
			quickSortRec(a, ini, q);
			quickSortRec(a, q + 1, fim);
		}
	}
*/  