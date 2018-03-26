#include "ParticleSystem.h"
#include <vector>
#include <iostream>

void main()
{
	std::srand(time(nullptr));

	sf::RenderWindow window(sf::VideoMode(1024, 768), "Particle System", sf::Style::Close);
	//window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	pf::ParticleSystem ps = pf::ParticleSystem(window, 1);

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;


			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
				{
					window.close();
					break;
				}

				case sf::Event::MouseButtonReleased:
				{
					if (event.mouseButton.button == sf::Mouse::Left)
						ps.addParticles(1);
					break;
				}

				default:
					break;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
				ps.clear();

			ps.update();
		}


		window.clear(sf::Color::Black);
		ps.draw();
		window.display();
	}

	return;
}