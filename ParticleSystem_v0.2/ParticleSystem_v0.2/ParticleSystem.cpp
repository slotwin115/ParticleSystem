#include "ParticleSystem.h"


pf::ParticleSystem::ParticleSystem()
{
	this->window = nullptr;
}

pf::ParticleSystem::ParticleSystem(sf::RenderWindow &window, int particleCount)
{
	this->window = &window;

	sf::Vector2u windowSize = window.getSize();

	//MAX PARTICLE PROPERTIES:
	//	position		= <0, window size - max particle radius>
	//	velocity		= <-speed, speed>
	//	acceleration	= 0
	//	speed			= <5, 10>
	//	radius			= <5, 20>

	for (int i = 0; i < particleCount; i++)
	{
		sf::Vector2f pos = sf::Vector2f((rand() % windowSize.x + 1) - 20, (rand() % windowSize.y + 1) - 20);
		sf::Vector2f vel = sf::Vector2f(((rand() % 2001) / 100) - 10, ((rand() % 2001) / 100) - 10);
		sf::Vector2f acc = sf::Vector2f();
		unsigned int speed = (rand() % 6) + 5;
		sf::Color col = sf::Color(rand() % 256, rand() % 256, rand() % 256);
		float r = ((rand() % 1500 + 1) / 100) + 10;
		float m = r / 10;

		particle.push_back(new Particle(pos, vel, acc, speed, m, col, r));
	}
}

pf::ParticleSystem::~ParticleSystem()
{
	//delete this->window;
	clear();
}

int pf::ParticleSystem::getParticleCount()
{
	return particle.size();
}

void pf::ParticleSystem::addParticles(int n)
{
	sf::Vector2u windowSize = window->getSize();

	for (int i = 0; i < n; i++)
	{
		sf::Vector2f pos = sf::Vector2f((rand() % windowSize.x + 1) - 20, (rand() % windowSize.y + 1) - 20);
		sf::Vector2f vel = sf::Vector2f(((rand() % 2001) / 100) - 10, ((rand() % 2001) / 100) - 10);
		sf::Vector2f acc = sf::Vector2f();
		unsigned int speed = (rand() % 6) + 5;
		sf::Color col = sf::Color(rand() % 256, rand() % 256, rand() % 256);
		float r = ((rand() % 1500 + 1) / 100) + 10;
		float m = r / 10;

		particle.push_back(new Particle(pos, vel, acc, speed, m, col, r));
	}
}

std::vector<pf::Particle*>& pf::ParticleSystem::getParticleVectorPtr()
{
	return particle;
}

void pf::ParticleSystem::setPointOfReference(sf::Vector2i *point)
{
	pointOfReference = point;
}

sf::Vector2i& pf::ParticleSystem::getPointOfReferencePtr()
{
	return *pointOfReference;
}

sf::Vector2i pf::ParticleSystem::getPointOfReference()
{
	return *pointOfReference;
}

void pf::ParticleSystem::clear()
{
	std::vector<pf::Particle*>::iterator particleIterator;
	for (particleIterator = particle.begin(); particleIterator != particle.end(); particleIterator++)
	{
		delete *particleIterator;
	}

	particle.clear();
}

void pf::ParticleSystem::update()
{
	for (int i = 0; i < particle.size(); i++)
	{
		Particle *tmp = particle[i];
		for (int j = i + 1; j < particle.size(); j++)
		{
			if (tmp->particleCollisionDetection(*particle[j]))
			{
				tmp->elasticCollision(*particle[j]);
				tmp->collision = true;
				particle[j]->collision = true;
			}
		}
	}

	//separate update from collision.

	std::vector<pf::Particle*>::iterator particleIterator;
	for (particleIterator = particle.begin(); particleIterator != particle.end(); particleIterator++)
	{
		(*particleIterator)->update(sf::Mouse::getPosition(*window));
	}
}

void pf::ParticleSystem::draw()
{
	std::vector<pf::Particle*>::iterator particleIterator;
	for (particleIterator = particle.begin(); particleIterator != particle.end(); particleIterator++)
	{
		window->draw(**particleIterator);
	}
}
