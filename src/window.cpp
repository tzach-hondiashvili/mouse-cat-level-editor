#include "window.h"
#include <fstream>

Window::Window()
	:m_window(sf::VideoMode(WIDTH,HEIGHT),"Level_Editor")
{

}

void Window::runEditor()
{
	int num_of_cols = 0,
		num_of_rows = 0;

	sf::Texture* current_tex = NULL;
	std::vector <sf::Texture> textures;
	fillTextures(textures);

	std::cout << "enter number of rows:" << std::endl;
	std::cin >> num_of_rows;

	std::cout << "enter number of cols:" << std::endl;
	std::cin >> num_of_cols;

	const float TILE_SIZE_X = float((WIDTH - BOARD_STARTING_X - WIDTH / 20) / num_of_cols);
	const float TILE_SIZE_Y = float((HEIGHT - BOARD_STARTING_Y - HEIGHT / 20) / num_of_rows);

	sf::Font font;
	font.loadFromFile("BN Machine.ttf");

	m_tooli.fillTools();

	m_board.makeNewLevel(num_of_cols, num_of_rows, TILE_SIZE_X, TILE_SIZE_Y);

	while (m_window.isOpen())
	{
		m_window.clear(sf::Color(53, 69, 141, 255)); //bright navy blue

		printWindow(num_of_rows, num_of_cols);

		printToolBox(font);

		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased:
				handleClick(event.mouseButton, textures, current_tex);
				break;
			}
		}
		m_window.display();
	}
}

void Window::handleClick(const sf::Event::MouseButtonEvent& event, std::vector<sf::Texture>& textures, sf::Texture* &current_tex)
{
	static bool mouse_exists = false;

	for (int i = 0; i < textures.size(); i++)
	{
		if (m_tooli.getTools()[i].makeButtonRectangle().getGlobalBounds().contains(
			m_window.mapPixelToCoords({ event.x, event.y })))
		{
			current_tex = &textures[i];
			return;
		}
	}

	if (m_tooli.getTools()[7].makeButtonRectangle().getGlobalBounds().contains(
		m_window.mapPixelToCoords({ event.x, event.y })))//Reset
	{
		m_window.close();
		mouse_exists = false;
		auto new_level = Window();
		new_level.runEditor();
		return;
	}
	else if (m_tooli.getTools()[8].makeButtonRectangle().getGlobalBounds().contains(
		m_window.mapPixelToCoords({ event.x, event.y })))//Delete
	{
		current_tex = NULL;
	}
	else if (m_tooli.getTools()[9].makeButtonRectangle().getGlobalBounds().contains(
		m_window.mapPixelToCoords({ event.x, event.y })))//Save
	{
		saveLevel(textures);
	}
	else if (checkIfBoard(event))//clicking on the board
	{
		if ((current_tex == &textures[5]))
		{
			if (!mouse_exists)
			{
				mouse_exists = true;
			}
			else
			{
				return;
			}
		}

		updateTextureInWantedTile(event ,current_tex,mouse_exists,textures);
	}
}


void Window::printWindow(int num_of_rows, int num_of_cols)
{
	for (int i = 0; i < num_of_rows; i++)
	{
		for (int j = 0; j < num_of_cols; j++)
		{
			
				m_window.draw(m_board.getBoard()[i].at(j).makeRectangle());

			if(m_board.getBoard()[i].at(j).getTexture() != NULL)
			{

				sf::Sprite sprite;

				
				sf::Vector2f tilePosition = m_board.getBoard()[i].at(j).getLocation();
				sf::Vector2f tileSize = m_board.getBoard()[i].at(j).getSize();

				sprite.setPosition(tilePosition);
				sprite.setTexture(*m_board.getBoard()[i].at(j).getTexture());
				sprite.setScale((tileSize.x - 4) / sprite.getLocalBounds().width, (tileSize.y - 4) / sprite.getLocalBounds().height);
				m_window.draw(sprite);

			}
			
		}
	}
}

void Window::fillTextures(std::vector<sf::Texture>& textures) const
{
	std::vector<std::string> objNames = { "cat.png",
										   "cheese.png",
										   "door.jpg",
										   "gift.png",
										   "key.png",
										   "mouse.png",
										   "wall.jpg" };

	sf::Texture temp;
	for (int pic = 0; pic < objNames.size(); pic++)
	{
		if (temp.loadFromFile(objNames[pic]))
		{
			textures.push_back(temp);
		}
		else
		{
			std::cerr << "Failed to load texture: " << objNames[pic] << std::endl;
		}
	}
}


void Window::printToolBox(sf::Font &font)
{
	const std::vector<Button>& tools = m_tooli.getTools(); // Get the const reference to the vector of tools

	for (int i = 0; i < tools.size(); i++)
	{
		m_window.draw(tools[i].makeButtonRectangle());
		m_window.draw(tools[i].makeButtonText(font));
	}
}

bool Window::checkIfBoard(const sf::Event::MouseButtonEvent& event)
{
	for (int i = 0; i < m_board.getBoard().size(); i++)
	{
		for (int j = 0; j < m_board.getBoard()[i].size(); j++)
		{
			if (m_board.getBoard()[i].at(j).makeRectangle().getGlobalBounds().contains(m_window.mapPixelToCoords({ event.x, event.y })))
			{
				return true;
			}
		}
	}
	return false;
}

void Window::updateTextureInWantedTile(const sf::Event::MouseButtonEvent& event , sf::Texture *texture, bool &mouse_exists,const std::vector<sf::Texture>& textures)
{
	
	for (int i = 0; i < m_board.getBoard().size(); i++)
	{
		for (int j = 0; j < m_board.getBoard()[i].size(); j++)
		{
			if (m_board.getBoard()[i].at(j).makeRectangle().getGlobalBounds().contains(m_window.mapPixelToCoords({ event.x, event.y })))
			{
				if (texture !=  &textures[5] && m_board.getBoard()[i].at(j).getTexture() == &textures[5])
				{
					mouse_exists = false;
				}
				m_board.getBoard()[i].at(j).setTexture(texture);
				
				return;
			}
		}
	}
}

void Window::saveLevel(const std::vector<sf::Texture>& textures)
{
	std::ofstream file("Board.txt", std::ios::out | std::ios::trunc);
	if (!file) 
	{
		std::cerr << "Failed to open the file for writing!" << std::endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < m_board.getBoard().size(); i++)
	{
		for (int j = 0; j < m_board.getBoard()[i].size(); j++)
		{
			if (m_board.getBoard()[i].at(j).getTexture() == &textures[0])
			{
				file << '^';
			}
			else if (m_board.getBoard()[i].at(j).getTexture() == &textures[1])
			{
				file << '*';
			}
			else if (m_board.getBoard()[i].at(j).getTexture() == &textures[2])
			{
				file << 'D';
			}
			else if (m_board.getBoard()[i].at(j).getTexture() == &textures[3])
			{
				file << '$';
			}
			else if (m_board.getBoard()[i].at(j).getTexture() == &textures[4])
			{
				file << 'F';
			}
			else if (m_board.getBoard()[i].at(j).getTexture() == &textures[5])
			{
				file << '%';
			}
			else if (m_board.getBoard()[i].at(j).getTexture() == &textures[6])
			{
				file << '#';
			}
			else if (m_board.getBoard()[i].at(j).getTexture() == NULL)
			{
				file << ' ';
			}
		}
		file << std::endl;
	}
	file.close();
}