#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include "Utilities.h"

namespace pf
{

	class Particle : public sf::CircleShape
	{
	private:
		sf::Vector2f velocity, acceleration;
		unsigned int speed;
		float mass;

	public:
		bool collision = false;
		Particle();
		Particle(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, unsigned int speed, float mass, sf::Color color, float radius);
		~Particle();

		sf::Vector2f getVelocity();
		void setVelocity(sf::Vector2f velocity);
		sf::Vector2f getAcceleration();
		void setAcceleration(sf::Vector2f acceleration);
		unsigned int getSpeed();
		void setSpeed(unsigned int speed);
		float getMass();
		void setMass(float mass);
		bool particleCollisionDetection(const Particle &p);
		void wallCollisionDetection();
		void elasticCollision(Particle &p);
		void update(sf::Vector2i mousePosition);
	};

}
#endif // !PARTICLE_H

