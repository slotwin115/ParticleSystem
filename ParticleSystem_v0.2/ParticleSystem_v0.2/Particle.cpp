#include "Particle.h"

pf::Particle::Particle()
{
	float r = 15;
	setPosition(0.0f, 0.0f);
	setVelocity(sf::Vector2f());
	setAcceleration(sf::Vector2f());
	setSpeed(5);
	setMass(r / 3.14f);
	setFillColor(sf::Color::White);
	setRadius(r);
	setOrigin(r, r);
}

pf::Particle::Particle(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, unsigned int speed, float mass, sf::Color color, float radius)
{
	setPosition(position);
	setVelocity(velocity);
	setAcceleration(acceleration);
	setSpeed(speed);
	setMass(mass);
	setFillColor(color);
	setRadius(radius);
	setOrigin(radius, radius);
}

pf::Particle::~Particle()
{
}

sf::Vector2f pf::Particle::getVelocity()
{
	return velocity;
}

void pf::Particle::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

sf::Vector2f pf::Particle::getAcceleration()
{
	return acceleration;
}

void pf::Particle::setAcceleration(sf::Vector2f acceleration)
{
	this->acceleration = acceleration;
}

unsigned int pf::Particle::getSpeed()
{
	return speed;
}

void pf::Particle::setSpeed(unsigned int speed)
{
	this->speed = speed;
}

float pf::Particle::getMass()
{
	return mass;
}

void pf::Particle::setMass(float mass)
{
	this->mass = mass;
}

bool pf::Particle::particleCollisionDetection(const pf::Particle &p)
{
	sf::Vector2f distance = getPosition() - p.getPosition();
	float d = pf::magnitude(distance);
	d *= d;
	float r = getRadius() + p.getRadius();
	r *= r;
	if (d <= r)
	{
		return true;
	}

	return false;
}

void pf::Particle::wallCollisionDetection()
{
	sf::Vector2f res(1024, 768);

	sf::Vector2f pos = getPosition();
	float r = getRadius();

	if (pos.x - r <= 0)
		velocity.x = abs(velocity.x);
	if(pos.x + r >= res.x)
		velocity.x = abs(velocity.x) * -1;
	if (pos.y - r <= 0)
		velocity.y = abs(velocity.y);
	if (pos.y + r >= res.y)
		velocity.y = abs(velocity.y) * -1;
}

void pf::Particle::elasticCollision(pf::Particle &p)
{
	sf::Vector2f x = getPosition() - p.getPosition();
	float d = pf::magnitude(x);

	sf::Vector2f minimumTranslation = x * ((getRadius() + p.getRadius() - d) / d);

	float m1 = getMass();
	float m2 = p.getMass();

	setPosition(getPosition() + minimumTranslation * (m2 / (m1 + m2)));
	p.setPosition(p.getPosition() + minimumTranslation * (m1 / (m1 + m2)));


	sf::Vector2f velocityDiff = getVelocity() - p.getVelocity();
	float vn = pf::dot(velocityDiff, pf::normalize(minimumTranslation));
	if (vn > 0.0f)
		return;

	x = pf::normalize(x);

	sf::Vector2f v1 = getVelocity();
	float x1 = pf::dot(x, v1);

	sf::Vector2f v1x = x * x1;
	sf::Vector2f v1y = v1 - v1x;

	x = -x;
	sf::Vector2f v2 = p.getVelocity();
	float x2 = pf::dot(x, v2);

	sf::Vector2f v2x = x * x2;
	sf::Vector2f v2y = v2 - v2x;

	float M = m1 + m2;

	setVelocity(((v1x * ((m1 - m2) / M)) + (v2x * ((2.f - m2) / M)) + v1y));
	p.setVelocity(((v1x * ((2.f * m1) / M)) + (v2x * ((m2 - m1) / M)) + v2y));
}

void pf::Particle::update(sf::Vector2i mousePosition)
{
	sf::Vector2f distance = mousePosition - getPosition();

	if (!collision)
	{
		acceleration = 0.1f * pf::normalize(distance);
		velocity = velocity + acceleration;
	}

	if (velocity.x > speed)
		velocity.x = speed * velocity.x / pf::magnitude(velocity);
	if (velocity.y > speed)
		velocity.y = speed * velocity.y / pf::magnitude(velocity);

	wallCollisionDetection();

	move(velocity);

	collision = false;
}
