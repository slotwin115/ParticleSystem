#include "Utilities.h"

float pf::magnitude(sf::Vector2f v)
{
	return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

float pf::dot(sf::Vector2f a, sf::Vector2f b)
{
	return a.x * b.x + a.y * b.y;
}

float pf::dot(sf::Vector2f a, sf::Vector2i b)
{
	return a.x * b.x + a.y * b.y;
}

sf::Vector2f pf::normalize(sf::Vector2f v)
{
	v.x /= magnitude(v);
	v.y /= magnitude(v);
	return v;
}

sf::Vector2f pf::operator-(sf::Vector2f lv, const sf::Vector2i &rv)
{
	lv.x -= rv.x;
	lv.y -= rv.y;
	return lv;
}

sf::Vector2f pf::operator+(sf::Vector2f lv, const sf::Vector2i &rv)
{
	lv.x += rv.x;
	lv.y += rv.y;
	return lv;
}

sf::Vector2f pf::operator-(const sf::Vector2i &lv, const sf::Vector2f &rv)
{
	sf::Vector2f lhs((float)lv.x, (float)lv.y);

	lhs.x -= rv.x;
	lhs.y -= rv.y;
	return lhs;
}

sf::Vector2f pf::operator+(const sf::Vector2i &lv, const sf::Vector2f &rv)
{
	sf::Vector2f lhs((float)lv.x, (float)lv.y);

	lhs.x += rv.x;
	lhs.y += rv.y;
	return lhs;
}

sf::Vector2f pf::operator/(sf::Vector2f lv, const float &rv)
{
	lv.x /= rv;
	lv.y /= rv;
	return lv;
}

sf::Vector2f pf::operator*(sf::Vector2f lv, const float &rv)
{
	lv.x *= rv;
	lv.y *= rv;
	return lv;
}

sf::Vector2f pf::operator/(const float &lv, sf::Vector2f rv)
{
	rv.x /= lv;
	rv.y /= lv;
	return rv;
}

sf::Vector2f pf::operator*(const float &lv, sf::Vector2f rv)
{
	rv.x *= lv;
	rv.y *= lv;
	return rv;
}
