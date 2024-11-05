// Grafo.h
#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>
#include <string>

class Grafo {
private:
    int vertices;
    std::vector<std::list<int>> listaAdj;

public:
    // Construtor que inicializa o grafo a partir de um arquivo
    Grafo(const std::string& caminho);

    // Função para adicionar uma aresta
    void adicionarAresta(int u, int v);

    // Função para exibir o grafo
    void exibir() const;

    // Retorna os graus de todos os vértices
    std::vector<std::pair<int, int>> pegarGraus() const;

    // Retorna os vizinhos de um vértice
    std::list<int> pegarVizinhos(int v) const;
};

#endif