#ifndef SETA_HPP
#define SETA_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"

class Seta: public ObjetoDeJogo {

public:        
    Seta(const ObjetoDeJogo &obj, char a, int p) : ObjetoDeJogo(obj), ativa(a == '1'), posicao(p) {}

    Seta(char a, int p): ObjetoDeJogo("seta", pegaSprite(p), 99, getPosicaoInicial(p)), ativa(a == '1'), posicao(p) {
        if(a=='1')
            this->ativarObj();
        else
            this->desativarObj();
        
    }
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
            return 4;
        case 1:
            return 28;
        case 2:
            return 52;
        case 3:
            return 76;
        default:
            return 0;
        }
        
    }


};




#endif

