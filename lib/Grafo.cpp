// Grafo.cpp
#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

// Construtor que inicializa o grafo a partir de um arquivo
Grafo::Grafo(const std::string& caminho) {
    std::ifstream arquivo(caminho);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        exit(1);
    }

    // Aqui é onde estava o erro, substituímos 'caminho' por 'arquivo'
    arquivo >> vertices; 
    listaAdj.resize(vertices + 1); // Redimensiona a lista de adjacências

    int u, v;
    while (arquivo >> u >> v) {
        adicionarAresta(u, v); // Adiciona a aresta lida
    }

    arquivo.close(); // Fecha o arquivo após a leitura
}

// Função para adicionar uma aresta
void Grafo::adicionarAresta(int u, int v) {
    listaAdj[u].push_back(v); // Adiciona v na lista de adjacências de u
}

// Função para exibir o grafo
void Grafo::exibir() const {
    for (int i = 1; i <= vertices; ++i) {
        std::cout << i << ": ";
        for (int vizinho : listaAdj[i]) {
            std::cout << vizinho << " ";
        }
        std::cout << std::endl;
    }
}

// Retorna um vetor com o grau de cada vértice
std::vector<std::pair<int, int>> Grafo::pegarGraus() const {
    std::vector<std::pair<int, int>> grausVertices;

    for (int v = 1; v <= vertices; ++v) {
        int grau = listaAdj[v].size();
        grausVertices.push_back({v, grau});
    }

    return grausVertices;
}

// Retorna os vizinhos de um vértice
std::list<int> Grafo::pegarVizinhos(int v) const {
    return listaAdj[v]; // Retorna a lista de adjacências do vértice v
}
