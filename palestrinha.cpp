#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Ex 2 de Algoritmos Avançados - Palestrinha
    Rafael C. G. Conrado
*/

//Função de comparação usada para ordenar o
//vector com base no segundo valor do par
bool comparacao_ordenacao(const pair<int,int> &a, const pair<int, int> &b) {
    return (a.second < b.second);
}

int main() {

    int n, l, r;
    vector <pair <int,int>> vector;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        vector.push_back(make_pair(l, r));
    }

    //Ordena o vector com base no segundo valor do par (tempo de término)
    sort(vector.begin(), vector.end(), comparacao_ordenacao);

    int contagem = 1;
    int terminoAnterior = vector[0].second;

    for(int j = 1; j < n; j++) {
        if(vector[j].first >= terminoAnterior) {
            terminoAnterior = vector[j].second;
            contagem++;

        }
    }

    cout << contagem << "\n";

    return 0;
}
