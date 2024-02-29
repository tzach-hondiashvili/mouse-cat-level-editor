#pragma once
#include <SFML/Graphics.hpp>
#include "board.h"
#include "consts.h"
#include "toolbox.h"



class Window
{
public:
	Window();
	void runEditor();
	void printWindow(int num_of_rows, int num_of_cols);
	void fillTextures(std::vector <sf::Texture> &textures) const;
	void printToolBox(sf::Font &font);
	void handleClick(const sf::Event::MouseButtonEvent& event,std::vector <sf::Texture>& textures, sf::Texture* &current_tex);
	bool checkIfBoard(const sf::Event::MouseButtonEvent&event);
	void updateTextureInWantedTile(const sf::Event::MouseButtonEvent& event , sf::Texture *texture, bool &mouse_exists, const std::vector<sf::Texture>& textures);
	void saveLevel(const std::vector<sf::Texture>&textures);

private:
	sf::RenderWindow m_window;
	Board m_board;
	ToolBox m_tooli;
};