#ifndef FASEMUSICA_HPP
#define FASEMUSICA_HPP


#include "ASCII_Engine/Fase.hpp"
#include "Seta.hpp"
#include "MatrizSetas.hpp"
#include <fstream>
#include <string>

class FaseMusica: public Fase {

public:
	FaseMusica(std::string name, const Sprite &bkg, std::string caminho_musica) : Fase(name,bkg), m(caminho_musica) {}
	FaseMusica(std::string name, const SpriteAnimado &bkg, std::string caminho_musica) : Fase(name,bkg), m(caminho_musica) {}
	virtual ~FaseMusica() {}
	
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
	
	bool colideComBloco() const;
	
private:
    ObjetoDeJogo *s;
	int velocidadeMusica;
	MatrizSetas m;	
};

#endif