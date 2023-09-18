#include <iostream>
#include <vector>
#include <set>
using namespace std; 

/*
    Ex 4 de Algoritmos Avançados - Jota Bee Movie
    Rafael C. G. Conrado
*/


//Algoritmo que encontra todos os subconjuntos possíveis
//por meio de recursão
void backtracking(vector<int> &vet, vector<vector<int>> &subres, vector<int> &sub, int posicao) {
    
    for(int i = posicao; i < vet.size(); i++) {

        //Insere no vector de subconjuntos
        sub.push_back(vet[i]);

        //Insere no vector resultante
        subres.push_back(sub);

        //Chama a função de forma recursiva e aumenta a posicao em +1
        backtracking(vet, subres, sub, i+1);
        sub.pop_back();
    }

}

//Função que realiza a contagem das somas dos subconjuntos
//A ideia aqui é utilizar um set para que haja apenas uma
//ocorrência de cada valor, facilitanto a contagem final
int contagem(vector<vector<int>> &result, set<int> &conjunto) {

    int countSubsets = 0;
    int soma;

    for(auto it:result) {
        soma = 0;

        for(auto subiterador:it) {
            soma += subiterador;
            
        }

        //Insere o resultado da soma do subconjunto
        //em um set
        conjunto.insert(soma);
        
    }


    //Faz a contagem e retorna
    countSubsets = conjunto.size();
    return countSubsets - 1;
}


int main() {

    int n, xi;
    vector<int> vet;

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> xi;
        vet.push_back(xi);
    }

    vector<int> sub;
    vector<vector<int>> result;

    result.push_back(sub);
    backtracking(vet, result, sub, 0);

    set<int> set;
    int count = contagem(result, set);
    cout << count << "\n";

    return 0;
}