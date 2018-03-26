#ifndef UTILITIES_H
#define UTILITIES_H

#include <SFML/Graphics.hpp>

namespace pf
{
	float magnitude(sf::Vector2f v);
	float dot(sf::Vector2f a, sf::Vector2f b);
	float dot(sf::Vector2f a, sf::Vector2i b);
	sf::Vector2f normalize(sf::Vector2f v);
	sf::Vector2f operator-(sf::Vector2f lv, const sf::Vector2i &rv);
	sf::Vector2f operator+(sf::Vector2f lv, const sf::Vector2i &rv);
	sf::Vector2f operator-(const sf::Vector2i &lv, const sf::Vector2f &rv);
	sf::Vector2f operator+(const sf::Vector2i &lv, const sf::Vector2f &rv);
	sf::Vector2f operator/(sf::Vector2f lv, const float &rv);
	sf::Vector2f operator*(sf::Vector2f lv, const float &rv);
	sf::Vector2f operator/(const float &rv, sf::Vector2f lv);
	sf::Vector2f operator*(const float &rv, sf::Vector2f lv);
}

#endif // !UTILITIES_H
