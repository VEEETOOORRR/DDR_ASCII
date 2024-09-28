#ifndef MATRIZSETAS_HPP
#define MATRIZSETAS_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Seta.hpp"

class MatrizSetas {
public:
    // Construtor que recebe o caminho do simfile
    MatrizSetas(const std::string& caminhoSimfile);
    
    // Destrutor
    ~MatrizSetas();

    // Função para obter a matriz de setas
    Seta* getSeta(int linha, int coluna);

    int getNumLinhas() const;
    int getNumColunas() const;

private:
    std::string caminhoSimfile;
    std::vector<std::vector<Seta*>> matriz;

    // Função auxiliar para remover espaços em branco
    std::string trim(const std::string& str);

    // Função para processar o conjunto de linhas
    void processarConjunto(const std::vector<std::string>& linhas);
};

#endif
