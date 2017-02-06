//
// Created by storm on 19/03/16.
//

#ifndef MAPEDITINGTOOL_MEDIAHANDLER_H
#define MAPEDITINGTOOL_MEDIAHANDLER_H

# include <string>
# include <iostream>
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include "..\..\collisions\Collision.h"

class MediaHandler
{
public:
    typedef struct s_staticParameters
    {
        std::string name;
        sf::Vector2f offsets;
    }              t_staticParameters;

	typedef struct s_styleText
	{
		sf::Font	    _font;
		sf::Color	    _color;
		unsigned int    _size;
		sf::Text::Style _style;
	} t_styleText;

public:
    MediaHandler() {};
    ~MediaHandler() {};
    const int   addNewTexture(const std::string &path, const std::string &name);
    const int   addNewSprite(sf::Texture *texture, const std::string &spriteName, const bool isGui=false, const sf::Vector2i &position=sf::Vector2i(0, 0));
    const int   addNewShape(sf::Shape *shape, const std::string &shapeName, const bool isGui=false, const sf::Vector2i &position=sf::Vector2i(0, 0));
    const int   addNewFont(const std::string &path, const std::string &name);
	const int   addNewStyleText(MediaHandler::t_styleText, const std::string &name);
	const int   addNewMusic(const std::string &path, const std::string &name);
	//const int   addNewSoundBuffer(const std::string &path, const std::string &name);
	//const int   addNewSound(const std::string &path, const std::string &name);


    sf::Shape					*getShape(const std::string &name);
    sf::Texture					*getTexture(const std::string &name);
    sf::Sprite					*getSprite(const std::string &name);
    std::vector<std::pair<sf::Transformable *, MediaHandler::t_staticParameters>> &getStaticElems();
    sf::Font					*getFont(const std::string &name);
	MediaHandler::t_styleText	*getStyleText(const std::string &name);
	sf::Music					*getMusic(const std::string &name);
	//sf::SoundBuffer   *getSoundBuffer(const std::string &name);
	//sf::Sound   *getSound(const std::string &name);
    //Clean the vectors
    void        wipeAll();

private:
    std::vector<std::pair<sf::Texture *, const std::string>>						_textures;
    std::vector<std::pair<sf::Sprite *, const std::string>>							_sprites;
    std::vector<std::pair<sf::Shape *, const std::string>>							_shapes;
    std::vector<std::pair<sf::Transformable *, MediaHandler::t_staticParameters>>	_staticElems;
    std::vector<std::pair<sf::Font *, const std::string>>							_fonts;
	std::vector<std::pair<MediaHandler::t_styleText *, const std::string>>			_styleText;
	std::vector<std::pair<sf::Music *, const std::string>>							_music;
	std::vector<std::pair<sf::SoundBuffer *, const std::string>>					_soundBuffer;
	std::vector<std::pair<sf::Sound *, const std::string>>							_sound;
};

#endif //MAPEDITINGTOOL_MEDIAHANDLER_H
