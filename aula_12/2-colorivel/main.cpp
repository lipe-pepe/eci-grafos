#include "../../lib/Grafo.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

// Como podemos definir se um grafo é 2 colorível? Ou seja se ele pode ser colorido com somente 2 cores?

// Função auxiliar para comparar vértices por grau
bool comparaGraus(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second > b.second; // Ordem decrescente
}

bool checa2Colorivel(const Grafo& grafo) {
    // Obter os vértices ordenados em ordem decrescente de graus
    std::vector<std::pair<int, int>> graus = grafo.pegarGraus();
    std::sort(graus.begin(), graus.end(), comparaGraus);

    // Mapeia cada vértice para sua cor
    std::map<int, int> coresVertices;

    // Para cada vértice
    for (const auto& grau : graus) {
        int v = grau.first;

        // Pegar a cor de todos os vizinhos
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

        // Se a cor for igual ou maior que 2, não é 2 colorível
        if (color >= 2) {
            return false;
        } else {
            // Atribui a cor ao vértice
            coresVertices[v] = color;
        }
    }

    // Se chegou aqui, é 2 colorível
    return true;
}

int main() {
    // Inicializa o grafo a partir de um arquivo
    Grafo grafo("grafo2.txt");
    
    // Executa o algoritmo de coloração
    std::cout << checa2Colorivel(grafo) << std::endl;

    return 0;
}