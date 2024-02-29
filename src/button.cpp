#include "button.h"
#include "consts.h"

Button::Button()
    :m_location(sf::Vector2f(0, 0)), m_size(0, 0), m_nameOfButton("")
{

}

void Button::setButtonLocation(int index)//index of button
{
    m_size.x = WIDTH/7;
    m_size.y = HEIGHT/15;
    m_location.x = WIDTH/15;
    m_location.y = (HEIGHT/20) + (m_size.y + HEIGHT / 40)*index;
}
void Button::setText(const std::string &text)
{
    m_nameOfButton = text;
}

sf::RectangleShape Button::makeButtonRectangle() const
{
    sf::RectangleShape shape;
    
    shape.setSize(m_size);
    shape.setOutlineThickness(3);
    shape.setPosition(m_location);
    shape.setOutlineColor(sf::Color::Black);
    shape.setFillColor(sf::Color(196, 164, 132, 255));
    shape.setTexture(NULL);

    return shape;
}
sf::Text Button::makeButtonText(sf::Font &font) const
{
    sf::Text text;
    text.setString(m_nameOfButton);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(3);
    text.setFont(font);  
    text.setOrigin(m_size.x / 2, m_size.y / 2);
    text.setCharacterSize(50);

    sf::FloatRect textBounds = text.getLocalBounds();

    float textPosX = m_location.x + m_size.x - textBounds.width / 2;
    float textPosY = m_location.y + m_size.y - textBounds.height / 1.5;

    // Set the position of the text
    text.setPosition(textPosX, textPosY);

    return text;
}