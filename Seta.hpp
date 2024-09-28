#ifndef SETA_HPP
#define SETA_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"

class Seta: public ObjetoDeJogo {

public:        
    Seta(const ObjetoDeJogo &obj, char a, int p) : ObjetoDeJogo(obj), ativa(a == '1'), posicao(p) {}

    Seta(int a, int p): ObjetoDeJogo("seta", pegaSprite(p), 40, getPosicaoInicial(p)), ativa(a == 1), posicao(p) {}
    virtual ~Seta() {}
    void ativarSeta() {ativa = true;}
    void desativarSeta() {ativa = false;}
    bool getAtiva() {return ativa;}

private:
    bool ativa;
    int posicao;
    Sprite pegaSprite(int i){
        switch (i){
        case 0:
            return Sprite("rsc/seta_esquerda.img");
        case 1:
            return Sprite("rsc/seta_baixo.img");
        case 2:
            return Sprite("rsc/seta_cima.img");
        case 3:
            return Sprite("rsc/seta_direita.img");
        default:
            return Sprite("rsc/seta_esquerda.img");
        }
    }

    int getPosicaoInicial(int i){
        switch (i){
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 40;
        case 3:
            return 60;
        default:
            return 0;
        }
        
    }


};




#endif

