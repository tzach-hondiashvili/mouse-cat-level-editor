#include "board.h"

Board::Board()
	:m_board ({})
{

}

std::vector <Row> &Board::getBoard()
{
	return m_board;
}

void Board::makeNewLevel(int num_of_cols,int num_of_rows, const float TILE_SIZE_X, const float TILE_SIZE_Y)
{
	Row temp;
	for (int i = 0; i < num_of_rows; i++)
	{
		temp = Row();
		for (int j = 0; j < num_of_cols; j++)
		{
			temp.pushBack(Tile()); //expand row dynamically
			temp.at(j).setLocation(j,i, TILE_SIZE_X, TILE_SIZE_Y);
		}
		m_board.push_back(temp);
	}
}


