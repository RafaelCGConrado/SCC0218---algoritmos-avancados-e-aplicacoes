#include <iostream>
using namespace std;

/*
    Ex 3 de Algoritmos Avançados - Estatuas
    Rafael C. G. Conrado
*/

int main() {

    int n, k;
    cin >> n >> k;

    int posicaoEst, posicaoAtual, nroGuardas = 1;
    int andou = 0;

    cin >> posicaoAtual;
    for(int i = 1; i < n; i++) {
        cin >> posicaoEst;

        //O guarda 'atual' precisa se mover e
        //ainda não se movimentou nenhuma vez 
        if(posicaoAtual + k < posicaoEst && andou == 0) {
            posicaoAtual += k;
            andou = 1;
        }

        //O guarda atual precisa se mover para cobrir a próxima estátua
        //mas já andou uma vez. É necessário alocar mais um guarda e 
        //defini-lo como o atual
        if(posicaoAtual + k < posicaoEst && andou == 1) {
            posicaoAtual = posicaoEst;
            nroGuardas++;
            andou = 0;
        }
        
    }

    cout << nroGuardas << "\n";

    return 0;
}