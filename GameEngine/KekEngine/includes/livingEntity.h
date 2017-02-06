//
// Created by storm on 26/03/16.
//

#ifndef MAPEDITINGTOOL_LIVINGENTITY_H
#define MAPEDITINGTOOL_LIVINGENTITY_H

# include "entity.h"
# include "..\..\animations\Animation.hpp"
# include "..\..\animations\AnimatedSprite.hpp"
# include <array>

class LivingEntity : public Entity
{
public:
    enum Direction {
        STILL = 0,
        UP = 1,
        DOWN = 2,
        LEFT = 3,
        RIGHT = 4,
        DirectionCount = 5
    };
public:
    LivingEntity(const int &x, const int &y, const int &hp, const float &speed=10.0, const bool animated=false, const sf::Time &animationSpeed=sf::Time::Zero, sf::Texture *spriteSheet=NULL);
    ~LivingEntity() {};
    void    addFrameState(const LivingEntity::Direction &direction, const sf::IntRect &rect);
    void    changeDirection(const LivingEntity::Direction &direction);
	LivingEntity::Direction    getCurrentDirection();
    void    move(const float &x, const float &y);
    void    update(const sf::Time &time);
    const float &getSpeed() const;
    AnimatedSprite* getAnimation() const;
protected:
    int _hp;
    bool _animated;
    float _speed;
    sf::Time _animationSpeed;
    std::array<Animation*, LivingEntity::DirectionCount> _animations;
    AnimatedSprite *_animation;
    Direction _direction;
};

#endif //MAPEDITINGTOOL_LIVINGENTITY_H
