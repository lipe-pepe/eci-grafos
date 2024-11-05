#include "../../lib/Grafo.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

// Como podemos colorir um grafo com o menor número de cores possível?

// Função auxiliar para comparar vértices por grau
bool comparaGraus(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second > b.second; // Ordem decrescente
}

// Algoritmo de coloração
void Colorir(const Grafo& grafo) {
    // Obter o vetor de graus dos vértices
    std::vector<std::pair<int, int>> graus = grafo.pegarGraus();

    // Ordena os vértices em ordem decrescente de grau
    std::sort(graus.begin(), graus.end(), comparaGraus);

    // Mapeia cada vértice para sua cor
    std::map<int, int> coresVertices;

    // Processa cada vértice
    for (const auto& grau : graus) {
        int v = grau.first;

        // Encontra as cores dos vizinhos
        std::set<int> coresVizinhos;
        for (int vizinho : grafo.pegarVizinhos(v)) {
            if (coresVertices.find(vizinho) != coresVertices.end()) {
                coresVizinhos.insert(coresVertices[vizinho]);
            }
        }

        // Encontra a menor cor disponível que não é usada pelos vizinhos
        int color = 0;
        while (coresVizinhos.find(color) != coresVizinhos.end()) {
            ++color;
        }

        // Atribui a cor ao vértice
        coresVertices[v] = color;
    }

    // Exibe as cores atribuídas
    std::cout << "Coloração dos vértices:" << std::endl;
    for (const auto& vc : coresVertices) {
        std::cout << "Vértice " << vc.first << ": Cor " << vc.second << std::endl;
    }
}

int main() {
    // Inicializa o grafo a partir de um arquivo
    Grafo grafo("grafo.txt");
    
    // Executa o algoritmo de coloração
    Colorir(grafo);

    return 0;
}