#include <iostream>
#include <vector>
using namespace std;

/*
    Ex 5 de Algoritmos Avançados - Contando Inversoes
    Rafael C. G. Conrado
    Em homenagem a Vina
*/

long long merge(vector<int> &vet, int esq, int meio, int dir) {
    
    long long int contagem = 0;
    int i = esq, j = meio, k = 0;
    int aux[(dir - esq + 1)];

    while(i < meio && j <= dir) {
        if(vet[i] <= vet[j]) {
            aux[k] = vet[i];
            i++;
            k++;
        }
        
        else {
            aux[k] = vet[j];
            contagem += (meio - i);
            j++;
            k++;

        }
    }

    while(i < meio) {
        aux[k] = vet[i];
        i++;
        k++;
    }

    while(j <= dir) {
        aux[k] = vet[j];
        k++;
        j++;
    }

    for(i = esq, k = 0; i <= dir; i++, k++) vet[i] = aux[k];
    
    return contagem;
}


long long int mergeSort(vector<int> &vet, int esq, int dir) {
    long long contagem = 0;
    
    if (vet.size() == 1) {
        return 0;
    }

    if(dir > esq) {
        int meio = (dir+esq) / 2;
        contagem = mergeSort(vet, esq, meio);
        contagem += mergeSort(vet, meio+1, dir);
        contagem += merge(vet, esq, meio + 1, dir);
    }
    return contagem;
}



int main() {

    int n, an;
    vector<int> vet;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> an;
        vet.push_back(an);
    }

    long long int count = mergeSort(vet, 0, n - 1);
    cout << count << "\n";

    return 0;
}