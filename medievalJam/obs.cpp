//
// Created by margoul_1 on 27/03/16.
// Modified in gameJam by guigur on 05/02/17.
//

#include "obs.h"

Obs::~Obs() {
    delete this->_graphicHandler;
}

const int   Obs::menu()
{
	this->_graphicHandler->draw(*this->_mediaHandler->getSprite("titleWallpaper"));
	sf::Vector2f currentCameraPos = this->_graphicHandler->getCameraPos();
	int limit = -4550 + (760 + 380);

	sf::Time elapsed1 = this->_clock.getElapsedTime();
	this->_graphicHandler->draw(this->_introText);
	this->_graphicHandler->draw(this->_introText2);

	


	if (this->_stateMenu == 0)
	{
		if (elapsed1.asSeconds() > 0.0f)
		{
			this->_introText.setString(this->_introSentences[0]);
			this->_introText2.setString(this->_introSentences[1]);
		}
		if (elapsed1.asSeconds() > 4.5f)
		{
			this->_introText.setString(this->_introSentences[2]);
			this->_introText2.setString(this->_introSentences[3]);
		}
		if (elapsed1.asSeconds() > 9.0f) 
		{
			this->_introText.setString(this->_introSentences[4]);
			this->_introText2.setString(this->_introSentences[5]);
		}
		if (elapsed1.asSeconds() > 13.5f) 
		{
			this->_introText.setString(this->_introSentences[6]);
			this->_introText2.setString(this->_introSentences[7]);
		}
		if (elapsed1.asSeconds() > 18.0f) 
		{
			this->_introText.setString(this->_introSentences[8]);
			this->_introText2.setString(this->_introSentences[9]);
		}
		if (elapsed1.asSeconds() > 22.5f)
		{
			this->_introText.setString(this->_introSentences[10]);
			this->_introText2.setString("");
		}
		if (elapsed1.asSeconds() > 27.0f) //27.0f
		{
			this->_stateMenu = 1;
		}
	}
	if (currentCameraPos.y >= limit  && this->_stateMenu == 1)
	{
		this->_graphicHandler->moveCamera(GraphicHandler::Directions::UP, 0.035);  //0.03
	}
	if (elapsed1.asSeconds() > 41.0f || this->_stateMenu == 2) // 43.0f
	{
		if (this->_firstCycleiTitleScreen == true)
		{
			if (this->_stateMenu == 2)
				this->_graphicHandler->moveCameraToPos(0, -4550.0f + 760.0f);

			this->_mediaHandler->getMusic("mus_intro")->stop();
			this->_mediaHandler->getMusic("mus_title")->play();
			this->_firstCycleiTitleScreen = false;
		}

		if (this->_gameDifficulty == 0)
			this->_difficultyCursor.setPosition(170.0f, -3287.0f);
		else
			this->_difficultyCursor.setPosition(170.0f, -3247.0f);
		this->_graphicHandler->draw(this->_difficultyCursor);

		this->_stateMenu = 2;
		this->_graphicHandler->draw(this->_introText3);
		this->_graphicHandler->draw(this->_introText4);
		this->_graphicHandler->draw(this->_introText5);
		this->_graphicHandler->draw(*this->_mediaHandler->getSprite("logo"));
	}
	return (0);
}

void   Obs::enemy1Init()
{
	this->_mediaHandler->addNewTexture("../GameEngine/medias/textures/angry crusader.png", "crusader");
	this->_enemy1 = new LivingEntity(500, 500, 1, 0, true, sf::milliseconds(100), this->_mediaHandler->getTexture("crusader"));
}

const int   Obs::playerInit()
{
    this->_mediaHandler->addNewTexture("../GameEngine/medias/textures/angry crusader.png", "crusader");
    this->_graphicHandler->initPlayer((this->_graphicHandler->getWindowWidth() / 2) - 64,(this->_graphicHandler->getWindowHeight() / 2) - 64, 20, 5.0, true, sf::seconds(0.2f), this->_mediaHandler->getTexture("crusader"));
    //Animation Still
	this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::STILL, sf::IntRect(0, 0, 128, 128));
    //Animation UP
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::UP, sf::IntRect(128, 0, 128, 128));
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::UP, sf::IntRect(128, 128, 128, 128));
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::UP, sf::IntRect(128, 256, 128, 128));
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::UP, sf::IntRect(128, 384, 128, 128));
    //Animation DOWN
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::DOWN, sf::IntRect(0, 0, 128, 128));
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::DOWN, sf::IntRect(0, 128, 128, 128));
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::DOWN, sf::IntRect(0, 256, 128, 128));
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::DOWN, sf::IntRect(0, 384, 128, 128));
    //Animation RIGHT
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::RIGHT, sf::IntRect(384, 0, 128, 128));
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::RIGHT, sf::IntRect(384, 128, 128, 128));
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::RIGHT, sf::IntRect(384, 256, 128, 128));
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::RIGHT, sf::IntRect(384, 384, 128, 128));
    //Animation LEFT
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::LEFT, sf::IntRect(256, 0, 128, 128));
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::LEFT, sf::IntRect(256, 128, 128, 128));
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::LEFT, sf::IntRect(256, 256, 128, 128));
    this->_graphicHandler->getPlayer()->addFrameState(LivingEntity::Direction::LEFT, sf::IntRect(256, 384, 128, 128));
	return (1);
}

const int   Obs::MapCrusade()
{
	this->_map_crusade = new LivingEntity(500, 500, 1, 0, true, sf::milliseconds(100), this->_mediaHandler->getTexture("tex_map_crusade"));
	this->_map_crusade->addFrameState(LivingEntity::Direction::STILL, sf::IntRect(0, 0, 1152, 569));
	this->_map_crusade->addFrameState(LivingEntity::Direction::STILL, sf::IntRect(0, 569, 1152, 569));
	this->_map_crusade->addFrameState(LivingEntity::Direction::STILL, sf::IntRect(0, 1138, 1152, 569));
	this->_map_crusade->addFrameState(LivingEntity::Direction::STILL, sf::IntRect(0, 1707, 1152, 569));
	return (1);
}

// huge mess of files vvvv
const int   Obs::init()
{
	this->_firstCycleiTitleScreen = true;
	this->_inTheMenu = true;
	this->_stateMenu = 0;
	this->_gameDifficulty = 0;
    this->_graphicHandler = new GraphicHandler("Medieval Jam", "../GameEngine/medias/fonts/DTM-Mono.otf");
    this->_tilesetHandler = this->_graphicHandler->getBaseMap();
    this->_mediaHandler = this->_graphicHandler->getMediaHandler();
    this->_mediaHandler->addNewTexture("../GameEngine/medias/textures/Castle_3.png", "map_tileset");
    this->_mediaHandler->addNewTexture("../GameEngine/medias/textures/scroll_intro.png", "titleWallpaper");
	this->_mediaHandler->addNewTexture("../GameEngine/medias/textures/mega_crusade_logo.png", "logo");
	this->_mediaHandler->addNewTexture("../GameEngine/medias/textures/test.png", "test");

	this->_mediaHandler->addNewTexture("../GameEngine/medias/textures/map_crusade.jpg", "tex_map_crusade");
	this->_mediaHandler->addNewMusic("../GameEngine/medias/music/megaman2intro.ogg", "mus_intro");
	this->_mediaHandler->addNewMusic("../GameEngine/medias/music/megaman2title.ogg", "mus_title");

	this->_mediaHandler->addNewMusic("../GameEngine/medias/music/megaman2title.ogg", "mus_title");
	this->_mediaHandler->addNewMusic("../GameEngine/medias/music/MegaMan3StageSelectTheme.ogg", "mus_main");
	//this->_mediaHandler->addNewMusic("../GameEngine/medias/sound/gfx1.ogg", "gfx_1");

    this->_tilesetHandler->init(this->_mediaHandler->getTexture("map_tileset"), sf::Vector2u(128, 128), "../GameEngine/medias/maps/base", 0, 0);
    this->_mediaHandler->addNewFont("../GameEngine/medias/fonts/DTM-Mono.otf", "dtm-mono");
	this->_mediaHandler->addNewFont("../GameEngine/medias/fonts/megaman_2.ttf", "mega2");

    this->_mediaHandler->addNewSprite(this->_mediaHandler->getTexture("titleWallpaper"), "titleWallpaper", false, sf::Vector2i(0,0));
	this->_mediaHandler->addNewSprite(this->_mediaHandler->getTexture("logo"), "logo", false, sf::Vector2i(0, 0));
	this->_mediaHandler->addNewSprite(this->_mediaHandler->getTexture("test"), "test", false, sf::Vector2i(0, 0));

	this->_mediaHandler->addNewSprite(this->_mediaHandler->getTexture("map_tileset"), "relique1", false, sf::Vector2i(0, 0));

	this->MapCrusade();
	this->_mediaHandler->getMusic("mus_intro")->play();
	std::cout << this->_graphicHandler->getWindowHeight() << std::endl;

	this->_introSentences.push_back("          IN THE YEAR OF 11XX,");
	this->_introSentences.push_back("A SUPER CRUSADER NAMED... TIM");
	this->_introSentences.push_back("                    WAS BORN.");
	this->_introSentences.push_back("THE CRUSADES WERE CREATED");
	this->_introSentences.push_back("TO STOP THE EVIL DESIRES");
	this->_introSentences.push_back("         OF THE HERETICS.");
	this->_introSentences.push_back("HOWEVER, AFTER THE FAILURE");
	this->_introSentences.push_back("       OF THE FIRST CRUSADE");
	this->_introSentences.push_back("   THE FORCES OF EVIL ARE MORE");
	this->_introSentences.push_back("         POWERFUL THAN EVER");
	this->_introSentences.push_back("AND WANT TO COUNTER YOU.");
	
	this->_mediaHandler->getSprite("titleWallpaper")->setPosition(0, -4550+760);

	this->_mediaHandler->getSprite("logo")->setPosition(0, -4550+760);

	this->_mediaHandler->getSprite("test")->setPosition(0, 0);

	this->_introText.setFont(*this->_mediaHandler->getFont("mega2"));
	this->_introText.setCharacterSize(18);
	this->_introText.setPosition(320.0f, 650.0f);
	this->_introText2.setFont(*this->_mediaHandler->getFont("mega2"));
	this->_introText2.setCharacterSize(18);
	this->_introText2.setPosition(320.0f, 700.0f);
	this->_introText3.setFont(*this->_mediaHandler->getFont("mega2"));
	this->_introText3.setString("PRESS ENTER");
	this->_introText3.setCharacterSize(24);
	this->_introText3.setPosition(200.0f,  -3150.0f);
	this->_introText4.setFont(*this->_mediaHandler->getFont("mega2"));
	this->_introText4.setString("NORMAL");
	this->_introText4.setCharacterSize(24);
	this->_introText4.setPosition(200.0f, -3250.0f);
	this->_introText5.setFont(*this->_mediaHandler->getFont("mega2"));
	this->_introText5.setString("DIFFICULT");
	this->_introText5.setCharacterSize(24);
	this->_introText5.setPosition(200.0f, -3290.0f);
	this->_difficultyCursor.setFont(*this->_mediaHandler->getFont("mega2"));
	this->_difficultyCursor.setString(">");
	this->_difficultyCursor.setCharacterSize(24);
	this->_info.setFont(*this->_mediaHandler->getFont("mega2"));
	this->_info.setCharacterSize(24);
	this->_info.setPosition(200.0f, 0.0f);
	//{ 0, 1024, 128, 128 } 
	this->_reliques.push_back({"THE HOLY GRAIL", false, {100.0f, 200.0f}, {0, 1666, 128, 128} });
	this->_reliques.push_back({"THE LAMP OF THE POPE", false, {200.0f, 0.0f}, {512, 768, 128, 128} });
	this->_reliques.push_back({"THE FORGOTTEN COBRA COIN", false,{ 300.0f, 200.0f }, { 0, 1538, 128, 128 } });
	this->_reliques.push_back({"THE RUBBER DUCK", false,{ 400.0f, 20.0f },{ 0, 1408, 128, 128 } });

    return (0);
}

const int  Obs::levelInit()
{
	
	unsigned int i = 0;
	std::cout << "size " << this->_reliques.size() << std::endl;
	while (i < this->_reliques.size())
	{

		i++;
	}


	return (0);
}

const int	Obs::gameCore()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->_graphicHandler->moveLivingEntity(this->_graphicHandler->getPlayer(), LivingEntity::Direction::LEFT, true, true);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->_graphicHandler->moveLivingEntity(this->_graphicHandler->getPlayer(), LivingEntity::Direction::RIGHT, true, true);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->_graphicHandler->moveLivingEntity(this->_graphicHandler->getPlayer(), LivingEntity::Direction::UP, true, true);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->_graphicHandler->moveLivingEntity(this->_graphicHandler->getPlayer(), LivingEntity::Direction::DOWN, true, true);

	unsigned int i = 0;

	while (i < this->_reliques.size())
	{
		if (this->_reliques[i]._isGetRelique == false &&
			(this->_graphicHandler->getPlayer()->getX() >= this->_reliques[i]._reliquePos.x - 32 && this->_graphicHandler->getPlayer()->getY() >= this->_reliques[i]._reliquePos.y - 32) &&
			(this->_graphicHandler->getPlayer()->getX() <= this->_reliques[i]._reliquePos.x + 32 && this->_graphicHandler->getPlayer()->getY() <= this->_reliques[i]._reliquePos.y + 32))
		{
			this->_reliques[i]._isGetRelique = true;
			std::cout << "you got " << this->_reliques[i]._name << std::endl;
			this->_graphicHandler->draw(this->_info);

		}

		if (this->_reliques[i]._isGetRelique == false)
		{
			this->_mediaHandler->getSprite("relique1")->setPosition(this->_reliques[i]._reliquePos.x, this->_reliques[i]._reliquePos.y);
			this->_mediaHandler->getSprite("relique1")->setTextureRect(sf::IntRect(this->_reliques[i]._reliqueTile.left, this->_reliques[i]._reliqueTile.top, this->_reliques[i]._reliqueTile.width, this->_reliques[i]._reliqueTile.height));
			this->_graphicHandler->draw(*this->_mediaHandler->getSprite("relique1"));
		}
		i++;
	}

	this->_graphicHandler->getPlayer()->update(this->_graphicHandler->getClock()->getLastFrameTime());
	this->_graphicHandler->draw(*this->_graphicHandler->getPlayer()->getAnimation());
	this->_map_crusade->update(this->_graphicHandler->getClock()->getLastFrameTime());
	return 0;
}

const int   Obs::start() {
    if (this->_graphicHandler->init()) {
        std::cout << "There was a problem with the graphical initialization" << std::endl;
        return 1;
    }
    this->_graphicHandler->launch();
    while (this->_graphicHandler->getIsAlive())
    {
		while (this->_graphicHandler->pollEvent())
		{
			if (this->_graphicHandler->eventTriggered(sf::Event::Closed) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				this->_graphicHandler->terminate();
			}
			if (this->_graphicHandler->eventTriggered(sf::Event::KeyPressed))
			{
				if (this->_inTheMenu == true)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
					{
						std::cout << this->_stateMenu << std::endl;
						if (this->_stateMenu < 2)
						{
							this->_stateMenu = 2;
						}
						else if (this->_stateMenu == 2)
						{
							this->_stateMenu = 3;
							this->_inTheMenu = false;
							this->_mediaHandler->getMusic("mus_title")->stop();
							this->_mediaHandler->getMusic("mus_main")->play();

							this->_graphicHandler->resetCamera();
							this->playerInit();
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->_stateMenu == 2)
						this->_gameDifficulty = 0;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->_stateMenu == 2)
						this->_gameDifficulty = 1;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9))
				{
					this->_graphicHandler->toggleFpsDebug();
				}
			}
		}
		if (this->_inTheMenu == true)
			this->menu();
		else
			this->gameCore();
        this->_graphicHandler->loop();
    }
    return (0);
}