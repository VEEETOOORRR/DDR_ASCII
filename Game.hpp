#ifndef GAME_HPP
#define GAME_HPP

#include "FaseMusica.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(200,89);
	
		FaseMusica start("FaseStart",Sprite("rsc/Background.img"), "rsc/Músicas/a_geisha_dream/a_geisha_dream.sm");
		
		start.init();
		start.run(buffer);
		
		/*buffer.clear();
		faseMusic.init();
		int ret1 = fase1.run(buffer);
		if ( ret1 != Fase::GAME_OVER && ret1 != Fase::END_GAME){
		
			buffer.clear();
			faseFinal.init();
			faseFinal.run(buffer);
		}
		else
			std::cout << "GAME OVER" << std::endl;
		
		std::cout << "Saindo..." << std::endl;*/
	}

};

#endif // GAME_HPP