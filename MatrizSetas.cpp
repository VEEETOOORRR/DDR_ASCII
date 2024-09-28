#include "MatrizSetas.hpp"

// Construtor que lê o arquivo e constrói a matriz
MatrizSetas::MatrizSetas(const std::string& caminhoSimfile) : caminhoSimfile(caminhoSimfile) {
    std::ifstream arquivo(caminhoSimfile);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }

    std::string linha;
    std::vector<std::string> linhas_atual;

    while (std::getline(arquivo, linha)) {
        linha = trim(linha);  // Remove espaços em branco

        if (linha == "," || linha == ";") {
            // Quando encontra uma vírgula ou ponto e vírgula, processa o conjunto de linhas
            processarConjunto(linhas_atual);
            linhas_atual.clear();

            // Se encontrar ponto e vírgula, é o fim do arquivo
            if (linha == ";") {
                break;
            }
        } else {
            // Adiciona a linha ao vetor se ela tiver 4 caracteres
            if (linha.size() == 4) {
                linhas_atual.push_back(linha);
            } else {
                std::cerr << "Aviso: A linha \"" << linha << "\" não tem 4 caracteres." << std::endl;
            }
        }
    }

    // Processar o último conjunto se existir
    if (!linhas_atual.empty()) {
        processarConjunto(linhas_atual);
    }

    arquivo.close();
}

// Destrutor para liberar memória
MatrizSetas::~MatrizSetas() {
    for (auto& linha : matriz) {
        for (auto& seta : linha) {
            delete seta;
        }
    }
}

// Função para retornar a matriz
Seta* MatrizSetas::getSeta(int linha, int coluna) {
    if (linha >= 0 && linha < matriz.size()) {  // Verifica se a linha está dentro dos limites
        if (coluna >= 0 && coluna < matriz[linha].size()) {  // Verifica se a coluna está dentro dos limites
            return matriz[linha][coluna];
        }
    }
    return nullptr;  // Retorne nullptr se o índice estiver fora dos limites
}

// Retorna o número de linhas da matriz
int MatrizSetas::getNumLinhas() const {
    return matriz.size();  // O tamanho do vetor externo representa o número de linhas
}

// Retorna o número de colunas da matriz (supondo que todas as linhas têm o mesmo número de colunas)
int MatrizSetas::getNumColunas() const {
    if (!matriz.empty()) {
        return matriz[0].size();  // O tamanho de qualquer linha representa o número de colunas
    }
    return 0;  // Se a matriz estiver vazia
}



// Função para remover espaços em branco
std::string MatrizSetas::trim(const std::string& str) {
    std::string trimmed = str;
    trimmed.erase(std::remove_if(trimmed.begin(), trimmed.end(), ::isspace), trimmed.end());
    return trimmed;
}

// Função para processar um conjunto de linhas e adicionar à matriz
void MatrizSetas::processarConjunto(const std::vector<std::string>& linhas) {
    int linhas_conjunto = linhas.size();
    
    if (linhas_conjunto == 4) {
        for (int i = 0; i < linhas_conjunto; ++i) {
            std::vector<Seta*> linha;
            for (int j = 0; j < 4; ++j) {
                linha.push_back(new Seta(static_cast<int>(linhas[i][j]), j));
            }
            matriz.push_back(linha);

            // Adiciona linhas vazias
            for (int k = 0; k < 3; ++k) {
                std::vector<Seta*> linha_vazia;
                for (int j = 0; j < 4; ++j) {
                    linha_vazia.push_back(new Seta(0, j));
                }
                matriz.push_back(linha_vazia);
            }
        }
    } else if (linhas_conjunto == 8) {
        for (int i = 0; i < linhas_conjunto; ++i) {
            std::vector<Seta*> linha;
            for (int j = 0; j < 4; ++j) {
                linha.push_back(new Seta(static_cast<int>(linhas[i][j]), j));
            }
            matriz.push_back(linha);

            // Adiciona linha vazia
            std::vector<Seta*> linha_vazia;
            for (int j = 0; j < 4; ++j) {
                linha_vazia.push_back(new Seta(0, j));
            }
            matriz.push_back(linha_vazia);
        }
    } else if (linhas_conjunto == 16) {
        for (int i = 0; i < linhas_conjunto; ++i) {
            std::vector<Seta*> linha;
            for (int j = 0; j < 4; ++j) {
                linha.push_back(new Seta(static_cast<int>(linhas[i][j]), j));
            }
            matriz.push_back(linha);
        }
    }
}
