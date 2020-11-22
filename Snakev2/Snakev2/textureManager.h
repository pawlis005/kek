#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <string>

class TextureManager
{
private:
	std::map<std::string, sf::Texture > textures;
public:
	TextureManager();
	virtual ~TextureManager();

	void addTexture(const std::string& key);
	sf::Texture& getTexture(const std::string& key);
};

