#include <iostream>
#include <vector>
using namespace std;

/*
    Ex de Algoritmos Avançados - Destruicao de Estatuas
    Rafael C. G. Conrado
*/

//Faz a melhor distribuição das bombas de acordo com um raio fornecido
//e verifica se é o suficiente para destruir todas as estatuas
//dado o numero de bombas
//(foi reaproveitado o algoritmo do ex anterior dos guardas)
bool testaRaio(int distancia, vector<int> &vet, int k) {
    int qtdBombas = 1, posicaoBomba, andou = false;

    posicaoBomba = vet[0];
    for(int i = 0; i < vet.size(); i++) {
        
        if(posicaoBomba + distancia < vet[i] && andou == false) {
            posicaoBomba += distancia;
            andou = true;
        }
        
        if(posicaoBomba + distancia < vet[i] && andou == true) {
            posicaoBomba = vet[i];
            qtdBombas++;
            andou = false;
        }
        
    }

    if(qtdBombas > k) return false;
    return true;

}

//Faz a busca binaria e verifica se o raio encontrado
//é o suficiente para destruir todas as estatuas
int busca(vector<int> &vet, int esq, int dir, int k) {
    
    int posicao;
    while(esq < dir) {
        posicao = (esq + dir) / 2;
        if(testaRaio(posicao, vet, k)) dir = posicao;
        else esq = posicao + 1;
    }

    return esq;
}


int main() { 

    int n, k, pos;
    vector<int> estatuas;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        cin >> pos;
        estatuas.push_back(pos);
    }

    int raioMax = busca(estatuas, 0, estatuas.back() - 1, k);
    cout << raioMax << "\n";

    return 0;
}