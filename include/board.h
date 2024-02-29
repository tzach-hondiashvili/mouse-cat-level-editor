#pragma once
#include "row.h"
#include <vector>
#include "consts.h"


class Board
{
public:
	Board();
	void makeNewLevel(int num_of_cols,int num_of_rows, const float TILE_SIZE_X, const float TILE_SIZE_Y);
	std::vector <Row> &getBoard();

private:
	std::vector <Row> m_board;
};