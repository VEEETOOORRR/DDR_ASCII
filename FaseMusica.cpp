#include <iostream>

#include "FaseMusica.hpp"

void FaseMusica::init(){

    //s = new ObjetoDeJogo("SetaTeste",Sprite("rsc/seta_baixo.img"),12,100);
    //objs.push_back(s);

	m = MatrizSetas("rsc/Músicas/a_geisha_dream/a_geisha_dream.sm");
	for(int i = 0; i < m.getNumLinhas(); i++){
		for(int j=0; j < 4; j++){
			objs.push_back(m.getSeta(i,j));
			//std::cout << "Carregando..." << i << " " << j << std::endl;
		}
	}

	//objs.push_back(m.getSeta(1,1));
}


unsigned FaseMusica::run(SpriteBuffer &screen){

	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	while (true){
        getline(std::cin,ent);







		//padrão
		update();
		draw(screen);
		system("clear");
		show(screen);
    }

	return Fase::END_GAME; // não necessário
}