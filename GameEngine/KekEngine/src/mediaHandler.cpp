//!!
// Created by storm on 19/03/16.
//

# include "../includes/mediaHandler.h"

void        MediaHandler::wipeAll()
{
   /* for (std::vector<std::pair<sf::Texture *, const std::string>>::iterator it = this->_textures.begin(); it != this->_textures.end(); ++it)
        delete it->first;
    this->_textures.clear();*/
    for (std::vector<std::pair<sf::Font *, const std::string>>::iterator it = this->_fonts.begin(); it != this->_fonts.end(); ++it)
        delete it->first;
    this->_fonts.clear();
    for (std::vector<std::pair<sf::Sprite *, const std::string>>::iterator it = this->_sprites.begin(); it != this->_sprites.end(); ++it)
        delete it->first;
    this->_sprites.clear();
    for (std::vector<std::pair<sf::Shape *, const std::string>>::iterator it = this->_shapes.begin(); it != this->_shapes.end(); ++it)
        delete it->first;
	for (std::vector<std::pair<sf::Music *, const std::string>>::iterator it = this->_music.begin(); it != this->_music.end(); ++it)
		delete it->first;
	this->_music.clear();
    this->_shapes.clear();
    this->_staticElems.clear();
}

const int   MediaHandler::addNewTexture(const std::string &path, const std::string &name)
{
    this->_textures.emplace_back(std::make_pair(new sf::Texture, name));
    if (!Collision::CreateTextureAndBitmask(this->_textures.back().first, path))
    {
        delete this->_textures.back().first;
        std::cout << "Problem while loading the texture" << std::endl;
        return (1);
    }
    return (0);
}

const int   MediaHandler::addNewShape(sf::Shape *shape, const std::string &name, const bool isGui, const sf::Vector2i &position)
{
    if (isGui)
    {
        MediaHandler::t_staticParameters staticParams;

        staticParams.name = name;
        staticParams.offsets = sf::Vector2f(position.x, position.y);
        this->_staticElems.emplace_back(std::make_pair(shape, staticParams));
        this->_staticElems.back().first->setPosition(staticParams.offsets.x, staticParams.offsets.y);
    }
    this->_shapes.emplace_back(std::make_pair(shape, name));
    return (0);
}

std::vector<std::pair<sf::Transformable *, MediaHandler::t_staticParameters>>   &MediaHandler::getStaticElems()
{
    return (this->_staticElems);
}

const int   MediaHandler::addNewSprite(sf::Texture *texture, const std::string &spriteName, const bool isGui, const sf::Vector2i &position)
{
    this->_sprites.emplace_back(std::make_pair(new sf::Sprite, spriteName));
    this->_sprites.back().first->setTexture(*texture);
    if (isGui)
    {
        MediaHandler::t_staticParameters staticParams;

        staticParams.name = spriteName;
        staticParams.offsets = sf::Vector2f(position.x, position.y);
        this->_staticElems.emplace_back(std::make_pair(this->_sprites.back().first, staticParams));
        this->_staticElems.back().first->setPosition(staticParams.offsets.x, staticParams.offsets.y);
    }
    return (0);
}

const int   MediaHandler::addNewFont(const std::string &path, const std::string &name)
{
    this->_fonts.emplace_back(std::make_pair(new sf::Font, name));
    if (! this->_fonts.back().first->loadFromFile(path))
    {
        std::cout << "Problem while loading the font" << std::endl;
        delete this->_fonts.back().first;
        return (1);
    }
    return (0);
}

const int   MediaHandler::addNewMusic(const std::string &path, const std::string &name)
{
	this->_music.emplace_back(std::make_pair(new sf::Music, name));
	if (!this->_music.back().first->openFromFile(path))
	{
		std::cout << "Problem while loading the music" << std::endl;
		delete this->_music.back().first;
		return (1);
	}
	return (0);
}
/*
const int   MediaHandler::addNewSoundBuffer(const std::string &path, const std::string &name)
{
	this->_soundBuffer.emplace_back(std::make_pair(new sf::Music, name));
	if (!this->_soundBuffer.back().first->loadFromFile(path))
	{
		std::cout << "Problem while loading the music" << std::endl;
		delete this->_soundBuffer.back().first;
		return (1);
	}
	return (0);
}

const int   MediaHandler::addNewSound(const std::string &path, const std::string &name)
{
	this->_sound.emplace_back(std::make_pair(new sf::Music, name));
	delete this->_sound.back().first;
	return (0);
}
*/
sf::Shape* MediaHandler::getShape(const std::string &name)
{
    if (this->_shapes.size() == 0)
        return (NULL);
    auto it = std::find_if(this->_shapes.begin(), this->_shapes.end(), [&name](const std::pair<sf::Shape *, const std::string>& obj) {return obj.second == name;});
    if (it != this->_shapes.end())
        return (it->first);
    else
    {
        std::cout << "Couldn't find a texture for " << name << " in the registered textures" << std::endl;
        return (NULL);
    }
}

sf::Texture* MediaHandler::getTexture(const std::string &name)
{
    if (this->_textures.size() == 0)
        return (NULL);
    auto it = std::find_if(this->_textures.begin(), this->_textures.end(), [&name](const std::pair<sf::Texture *, const std::string>& obj) {return obj.second == name;});
    if (it != this->_textures.end())
        return (it->first);
    else
    {
        std::cout << "Couldn't find a texture for " << name << " in the registered textures" << std::endl;
        return (NULL);
    }
}

sf::Sprite*  MediaHandler::getSprite(const std::string &name)
{
    if (this->_sprites.size() == 0)
        return (NULL);
    auto it = std::find_if(this->_sprites.begin(), this->_sprites.end(), [&name](const std::pair<sf::Sprite *, const std::string>& obj) {return obj.second == name;});
    if (it != this->_sprites.end())
        return (it->first);
    else
    {
        std::cout << "Couldn't find a sprite for " << name << " in the registered sprites" << std::endl;
        return (NULL);
    }
}

sf::Font* MediaHandler::getFont(const std::string &name)
{
   /* std::cout << "get font here" << std::endl;*/
    if (this->_fonts.size() == 0)
        return (NULL);
    auto it = std::find_if(this->_fonts.begin(), this->_fonts.end(), [&name](const std::pair<sf::Font *, const std::string>& obj) {return obj.second == name;});
    if (it != this->_fonts.end())
        return (it->first);
    else
    {
        std::cout << "Couldn't find a font for " << name << " in the registered fonts" << std::endl;
        return (NULL);
    }
}

sf::Music* MediaHandler::getMusic(const std::string &name)
{
	if (this->_music.size() == 0)
		return (NULL);
	auto it = std::find_if(this->_music.begin(), this->_music.end(), [&name](const std::pair<sf::Music *, const std::string>& obj) {return obj.second == name; });
	if (it != this->_music.end())
		return (it->first);
	else
	{
		std::cout << "Couldn't find a music for " << name << " in the registered musics" << std::endl;
		return (NULL);
	}
}

