#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Particle.h"
#include "Utilities.h"

namespace pf
{
	class ParticleSystem
	{
	private:
		sf::RenderWindow *window;
		sf::Vector2i *pointOfReference;
		std::vector<Particle*> particle;
	public:
		ParticleSystem();
		ParticleSystem(sf::RenderWindow &window, int particleCount);
		~ParticleSystem();
		int getParticleCount();
		void addParticles(int n);
		std::vector<Particle*>& getParticleVectorPtr();
		void setPointOfReference(sf::Vector2i *point);
		sf::Vector2i& getPointOfReferencePtr();
		sf::Vector2i getPointOfReference();
		void clear();
		void update();
		void draw();
	};
}

#endif // !PARTICLESYSTEM_H
