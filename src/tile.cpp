#include "tile.h"

Tile::Tile()
: m_texture(NULL), m_my_location (sf::Vector2f(0,0)), m_size(0,0)
{

}

void Tile::setLocation(int number_of_col,int number_of_row, const float TILE_SIZE_X, const float TILE_SIZE_Y)//tile location
{
	m_my_location.x = float (BOARD_STARTING_X + (TILE_SIZE_X * number_of_col)) ;
	m_my_location.y = float (BOARD_STARTING_Y + (TILE_SIZE_Y * number_of_row)) ;
    m_size.x = TILE_SIZE_X;
    m_size.y = TILE_SIZE_Y;
}

sf::RectangleShape Tile::makeRectangle() const
{
    sf::RectangleShape shape;

    shape.setSize(m_size);
    shape.setOutlineThickness(3);
    shape.setPosition(m_my_location);
    shape.setOutlineColor(sf::Color::Black);
    shape.setTexture(m_texture);

    return shape;
}

sf::Vector2f Tile::getLocation() const
{
    return m_my_location;
}

sf::Vector2f Tile::getSize() const
{
    return m_size;
}

void Tile::setTexture(sf::Texture *current_tex)
{

    m_texture = current_tex;
}


sf::Texture* Tile::getTexture() const
{
    return m_texture;
}

