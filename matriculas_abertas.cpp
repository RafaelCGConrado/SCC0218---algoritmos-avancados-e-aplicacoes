#include <iostream>
#include <iterator>
#include <map>
using namespace std;

/*
    Ex 1 de Algoritmos Avançados - Matriculas Abertas
    Rafael C. G. Conrado - 13671806
*/

int main() {

    int n, k;
    int aluno;

    //Mapeia Aluno -> Curso
    map<int, int> matricula;
    cin >> n;

    //Armazena quantidade de alunos em cada curso
    int cursos[n];

    for(int i = 0; i < n; i++) {
        cursos[i] = 0;
        cin >> k;
        
        for(int j = 0; j < k; j++) {
            cin >> aluno;

            //Aluno já matriculado
            if(matricula.find(aluno) != matricula.end()) {

                if(matricula[aluno] != i && cursos[matricula[aluno]] > 0) {
                    cursos[matricula[aluno]]--;
                    matricula[aluno] = -1;
                    
                }
            }

            //Aluno ainda não matriculado em nenhum curso
            else {
                matricula.insert(make_pair(aluno, i));
                cursos[i]++;
    
            }
        }
    }
    
    //Printa quantidade de inscritos em cada curso
    for(int i = 0; i < n; i++) {
        cout << cursos[i] << " ";
    }
    cout << "\n";
    
    return 0;
}