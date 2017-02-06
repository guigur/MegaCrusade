//
// Created by storm on 18/03/16.
//

#ifndef MAPEDITINGTOOL_GRAPHICHANDLER_H
# define MAPEDITINGTOOL_GRAPHICHANDLER_H

# include <string>
# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include "tilesetHandler.h"
# include "mediaHandler.h"
# include "..\..\frameclock\frameClock.h"
# include "..\..\frameclock\clockHUD.h"
# include "cameraHandler.h"
# include "player.h"

class GraphicHandler
{
public:
    enum class Directions
    {
        UP = 0,
        DOWN = 1,
        LEFT = 2,
        RIGHT = 3
    };
public:
    GraphicHandler(const std::string &title, const std::string &mainFontPath, unsigned int modeWidth = 1024, unsigned int modeHeight = 768, const bool resizable=false, const bool cameraDelimited=false, const sf::IntRect &cameraDelimitation=sf::IntRect(0, 0, 0, 0), unsigned int modeBitsPerPixel=0, const bool fixedSize = true, const bool fpsDebug = false, const float cameraSpeed=10.0);
    ~GraphicHandler();
    const int   init();
    void        loop();
    void        launch();
    void        terminate();
    void        drawBaseMap() const;
    const bool  getIsAlive();
    TilesetHandler* getBaseMap();
    MediaHandler*   getMediaHandler();
    //Events
    const bool  pollEvent();
    const bool  eventTriggered(const sf::Event::EventType& eventType);
    bool        isKeyDown(const sf::Keyboard::Key &key);
    //Camera
    CameraHandler*  getCamera();
    void            moveCamera(const Directions &direction);
	void            moveCamera(const Directions &direction, double speed);
	void            moveCameraUntil(const Directions & direction, double speed, sf::IntRect endPos);
	void            cameraOnEntity(Entity *entity);
    //Debug
    void        setFpsDebug(const bool &option);
	void        toggleFpsDebug();
    //Drawing
    void        draw(const sf::Drawable &drawable) const;
	void        disableStillPlayer();
    void        moveStaticObjects(const bool mode=false);
	void        resetCamera();
	sf::Vector2f getCameraPos();
	void        moveCameraToPos(float x, float y);
    //Entities
    void        moveLivingEntity(LivingEntity *entity, const LivingEntity::Direction &direction, const bool &moveCamera=false, const bool &isPlayer=false);
    //Player
    void        initPlayer(const int &x, const int &y, const int &hp, const float &speed=10.0, const bool animated=false, const sf::Time &animationSpeed=sf::Time::Zero, sf::Texture *spriteSheet=NULL, const bool focusCamera=true);
    Player*     getPlayer() const;
    //CLock
    sfx::FrameClock* getClock() const;
    //Mutex
    sf::Mutex   _mutex;
    //lol
    unsigned int         getWindowHeight();
    unsigned int         getWindowWidth();
private:
    //Window object
    sf::RenderWindow  *_window;
    //Window properties
    unsigned int _modeWidth;
    unsigned int _modeHeight;
    unsigned int _modeBitsPerPixel;
    std::string  _title;
    bool         _resizable;
    //Window options
    bool         _fixedSize;
    //Event object
    sf::Event    _event;
    //Event settings
    std::array<bool, sf::Keyboard::Key::KeyCount> _keyStates;
    //Cameras
    CameraHandler  *_mainCamera;
    //Camera settings
    float           _cameraSpeed;
    bool            _cameraDelimited;
    sf::IntRect     _cameraDelimitation;
    Entity*         _cameraOnEntity;
    //Thread loop
    sf::Thread      *_loop;
    //Handlers
    MediaHandler   *_mediaHandler;
    TilesetHandler *_baseMap;
    //Cycle
    bool            _isAlive;
    //Clock
    sfx::FrameClock *_clock;
    ClockHUD        *_clockHUD;
    //Player
    Player*         _player;
    bool            _playerMoved;
	bool            _disableStillPlayer;
    //Fonts
    std::string      _mainFontPath;
    sf::Font         _mainFont;
    //Debug
    bool             _fpsDebug;
};

#endif //MAPEDITINGTOOL_GRAPHICHANDLER_H
