#include "TextureManager.h"

TextureManager::TextureManager() = default;

TextureManager::~TextureManager()
{
	textures.clear();
}

void TextureManager::addTexture(const std::string & key)
{
	sf::Texture texture;
	texture.loadFromFile(key);
	textures[key] = texture;
}

sf::Texture& TextureManager::getTexture(const std::string & key)
{
	return textures.at(key);
}
