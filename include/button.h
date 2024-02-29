#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Button {
public:
    Button();
    void setButtonLocation(int index);
    void setText(const std::string &text);
    sf::RectangleShape makeButtonRectangle() const;
    sf::Text makeButtonText(sf::Font &font) const;

private:
    sf::Vector2f m_location,
                 m_size;

    std::string m_nameOfButton;
};