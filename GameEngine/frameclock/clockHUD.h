#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

#include <SFML/Graphics.hpp>
#include "frameClock.h"
#include "../KekEngine/includes/graphicHandler.h"

class ClockHUD : public sf::Drawable
{
    struct Stat
    {
        sf::Color color;
        std::string str;
    };

    typedef std::vector<Stat> Stats_t;

public:

    ClockHUD(const sfx::FrameClock& clock, const sf::Font& font)
            : m_clock (&clock)
            , m_font  (&font)
    {
        _posX = 800.0f;
        _posY = 600.0f;
    }

public:
    float   _posX;
    float   _posY;
	sf::Vector2f _cameraPos;
	void setCameraPos(sf::Vector2f pos)
	{
		_cameraPos = pos;
	}
    void setPosXY(const float &posX, const float &posY)
    {
        _posX = posX;
        _posY = posY;
    }
private:
    void draw(sf::RenderTarget& rt, sf::RenderStates states) const
    {
        // Gather the available frame time statistics.
        const Stats_t stats = build();

        sf::Text elem;
        elem.setFont(*m_font);
        elem.setCharacterSize(16);
        elem.setPosition(_posX, _posY);

        // Draw the available frame time statistics.
        for (std::size_t i = 0; i < stats.size(); ++i)
        {
            elem.setString(stats[i].str);
            elem.setFillColor(stats[i].color);

            rt.draw(elem, states);

            // Next line.
            elem.move(0.0f, 16.0f);
        }
    }

private:

    template<typename T>
    static std::string format(std::string name, std::string resolution, T value)
    {
        std::ostringstream os;
        os.precision(4);
        os << std::left << std::setw(5);
        os << name << " : ";
        os << std::setw(5);
        os << value << " " << resolution;
        return os.str();
    }

    Stats_t build() const
    {
        const int count = 12;
        const Stat stats[count] = {
                { sf::Color::Yellow, format("Time",  "(sec)", m_clock->getTotalFrameTime().asSeconds())        },
                { sf::Color::White,  format("Frame", "",      m_clock->getTotalFrameCount())                   },
                { sf::Color::Green,  format("FPS",   "",      m_clock->getFramesPerSecond())                   },
                { sf::Color::Green,  format("min.",  "",      m_clock->getMinFramesPerSecond())                },
                { sf::Color::Green,  format("avg.",  "",      m_clock->getAverageFramesPerSecond())            },
                { sf::Color::Green,  format("max.",  "",      m_clock->getMaxFramesPerSecond())                },
                { sf::Color::Cyan,   format("Delta", "(ms)",  m_clock->getLastFrameTime().asMilliseconds())    },
                { sf::Color::Cyan,   format("min.",  "(ms)",  m_clock->getMinFrameTime().asMilliseconds())     },
                { sf::Color::Cyan,   format("avg.",  "(ms)",  m_clock->getAverageFrameTime().asMilliseconds()) },
                { sf::Color::Cyan,   format("max.",  "(ms)",  m_clock->getMaxtFrameTime().asMilliseconds())    },
				{ sf::Color::Red,   format("Pos.",  "X",  _cameraPos.x) },
				{ sf::Color::Red,   format("Pos.",  "Y",  _cameraPos.y) },
        };
        return Stats_t(&stats[0], &stats[0] + count);
    }

private:

    const sf::Font* m_font;
    const sfx::FrameClock* m_clock;
};