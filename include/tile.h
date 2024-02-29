#pragma once
#include "consts.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile
{
public:
	Tile();
	void setLocation(int number_of_cols, int number_of_rows, const float TILE_SIZE_X, const float TILE_SIZE_Y);
	sf::RectangleShape makeRectangle() const;
	sf::Vector2f getLocation() const;
	sf::Vector2f getSize() const;
	void setTexture(sf::Texture *current_tex);
	sf::Texture* getTexture() const;


private:
	sf::Texture* m_texture;
	sf::Vector2f m_my_location,
	             m_size;
};