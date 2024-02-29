#pragma once
#include "tile.h"

class Row
{
public:
	explicit Row(int size = 0, const Tile &value = Tile());
	Row(const Row& other);
	~Row();
	Row& operator = (const Row& other);

	const Tile& at(int index) const;
	Tile& at(int index);
	void pushBack(const Tile &val);
	int size() const;
	bool empty() const;


private:
	Tile* m_row;
	int m_size;
};