#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // Para std::remove_if

// Classe Seta para armazenar o valor 0 ou 1
class Seta {
public:
    int valor;
    int posicao;

    // Construtor que recebe o valor
    Seta(int v, int pos) : valor(v), posicao(pos) {}

    // Exibir o valor da seta
    void exibir() const {
        std::cout << valor;
    }
};

// Função para remover espaços em branco no início e no fim de uma string
std::string trim(const std::string& str) {
    std::string trimmed = str;
    trimmed.erase(std::remove_if(trimmed.begin(), trimmed.end(), ::isspace), trimmed.end());
    return trimmed;
}

// Função para processar um conjunto de linhas
void processarConjunto(const std::vector<std::string>& linhas, std::vector<std::vector<Seta*>> *matriz) {
    int linhas_conjunto = linhas.size();
    
    std::cout << "Processando conjunto com " << linhas_conjunto << " linhas." << std::endl; // Debug

    if(linhas_conjunto == 4){
        for (int i = 0; i < linhas_conjunto; ++i) {
            // Adicionar a linha do conjunto
            std::vector<Seta*> linha;
            for (int j = 0; j < 4; ++j) {
                linha.push_back(new Seta(linhas[i][j] - '0',j));  // Alocar dinamicamente a seta
            }
            matriz->push_back(linha);

            std::vector<Seta*> linha_vazia;
            for (int j = 0; j < 4; ++j) {
                linha_vazia.push_back(new Seta(0,j));  // Alocar dinamicamente a seta
            }
            for (int k = 0; k < 3; ++k){
            matriz->push_back(linha_vazia);
            }
        }
    }

    else if(linhas_conjunto == 8){
        for (int i = 0; i < linhas_conjunto; ++i) {
            // Adicionar a linha do conjunto
            std::vector<Seta*> linha;
            for (int j = 0; j < 4; ++j) {
                linha.push_back(new Seta(linhas[i][j] - '0',j));  // Alocar dinamicamente a seta
            }
            matriz->push_back(linha);

            std::vector<Seta*> linha_vazia;
            for (int j = 0; j < 4; ++j) {
                linha_vazia.push_back(new Seta(0,j));  // Alocar dinamicamente a seta
            }
            matriz->push_back(linha_vazia);
            }
        }
    
    else if(linhas_conjunto == 16){
        for (int i = 0; i < linhas_conjunto; ++i) {
            // Adicionar a linha do conjunto
            std::vector<Seta*> linha;
            for (int j = 0; j < 4; ++j) {
                linha.push_back(new Seta(linhas[i][j] - '0',j));  // Alocar dinamicamente a seta
            }
            matriz->push_back(linha);

        }
    }
}

int main() {
    std::ifstream arquivo("a_geisha_dream.sm");
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return 1;
    }

    std::string linha;
    std::vector<std::string> linhas_atual;
    std::vector<std::vector<Seta*>> m;
    
    while (std::getline(arquivo, linha)) {
        linha = trim(linha); // Remove espaços em branco da linha
        if (linha == "," || linha == ";") {
            // Quando encontra uma vírgula ou ponto e vírgula, processa o conjunto de linhas
            processarConjunto(linhas_atual, &m);
            linhas_atual.clear();  // Limpa o vetor para o próximo conjunto

            // Se encontrar ponto e vírgula, é o fim do arquivo
            if (linha == ";") {
                break;
            }
        } else {
            // Adiciona a linha ao vetor
            if (linha.size() == 4) { // Garante que a linha tenha 4 caracteres
                linhas_atual.push_back(linha);
            } else {
                std::cerr << "Aviso: A linha \"" << linha << "\" não tem 4 caracteres." << std::endl;
            }
        }
    }

    // Processar o último conjunto (se não terminar com ponto e vírgula)
    if (!linhas_atual.empty()) {
        processarConjunto(linhas_atual, &m);
    }

    std::cout << "Matriz de setas:" << std::endl;
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[i].size(); ++j) {
            m[i][j]->exibir();
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    // Liberar memória alocada
    for (auto& linha : m) {
        for (auto& seta : linha) {
            delete seta;  // Desalocar cada objeto 'Seta'
        }
    }

    arquivo.close();
    return 0;
}
