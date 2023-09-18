#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    Ex de Algoritmos Avançados - Apagão
    Rafael C. G. Conrado
*/

//Define vector de inteiros
typedef vector<int> vint;

//Define priority_queue de vint que será
//usada para manter as arestas do grafo sempre ordenadas
//do maior para o menor custo
typedef priority_queue<vint, vector<vint>, greater<vint>> edges;

//Vector de vector de int que usaremos para representar
//o conjunto de arestas (o grafo em si)
edges uv;

//UnionFind utilizada no algoritmo de Kruskal
class UnionFind { 
    private:
        vint parent, rank;

    public:
        UnionFind(int n) {
            parent.assign(n, 0);
            rank.assign(n, 0);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findSet(int i) { 
            if(parent[i] != i) parent[i] = findSet(parent[i]);
            return parent[i];
        }

        bool isSameSet(int i, int j) {
            return (findSet(i) == findSet(j));
        }

        void unionSet(int i, int j) {
            i = findSet(i), j = findSet(j);

            if(rank[i] > rank[j]) parent[j] = i;

            else parent[i] = j;

            if(isSameSet(i, j)) rank[j]++;

        }
};

//Implementação do algoritmo de Kruskal para achar a MST
void kruskal(edges uv, int nVertices) {
    long int custoTotal = 0; //Armazena a soma dos custos da MST
    int arestasMst = 0; //Conta a quantidade de arestas da MST
   
    UnionFind uf(uv.size()); //Cria uma UnionFind para agrupar os vértices

    while(!uv.empty()) {
        vint v = uv.top();
        
        //Se o conjunto de cada vértice é diferente,
        //faz a união de ambos, soma o custo da aresta
        //e aumenta a qtd de arestas da mst
        if(uf.findSet(v[1]) != uf.findSet(v[2])) {
            custoTotal += v[0];
            arestasMst++;
            uf.unionSet(v[1], v[2]);
        }
        uv.pop();
        
    }

    //Uma arvore geradora minima (MST) possui v-1 arestas
    if(arestasMst == nVertices - 1) cout << custoTotal << "\n";
    else cout << "-1" << "\n";

}


int main() {

    int n, m;
    cin >> n >> m;

    int u, v, c;
    //Leitura do grafo
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        uv.push({c, u, v});
        uv.push({c, v, u});
        
    }

    kruskal(uv, n);
    return 0;
}