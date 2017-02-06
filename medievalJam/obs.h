//
// Created by margoul_1 on 27/03/16.
//

#ifndef OBS_OBS_H
#define OBS_OBS_H

# include "..\GameEngine\KekEngine\includes\graphicHandler.h"
#include <SFML/Audio.hpp>

class Obs
{
public:
    Obs() {};
    ~Obs();
    const int   init();
    const int   start();
    const int   playerInit();
	const int	MapCrusade();
    const int   menu();
	const int   gameCore();
	void        enemy1Init();
	const int   levelInit();

private:
    GraphicHandler *_graphicHandler;
    MediaHandler   *_mediaHandler;
    TilesetHandler *_tilesetHandler;
	LivingEntity   *_map_crusade;
	LivingEntity   *_enemy1;
    sf::Text        _text;
    sf::Text        _menuStart;
	sf::Clock       _clock; 
    bool            _inTheMenu;
	bool			_firstCycleiTitleScreen;
	int             _stateMenu;
	int				_gameDifficulty;
	sf::Text _introText;
	sf::Text _introText2;
	sf::Text _introText3;
	sf::Text _introText4;
	sf::Text _introText5;
	sf::Text _difficultyCursor;
	sf::Text _info;
	std::vector<std::string> _introSentences;

	typedef struct s_reliques
	{
		std::string    _name;
		bool           _isGetRelique;
		sf::Vector2f   _reliquePos;
		sf::IntRect    _reliqueTile;
	} t_reliques;

	std::vector<t_reliques> _reliques;
};

#endif //OBS_OBS_H
