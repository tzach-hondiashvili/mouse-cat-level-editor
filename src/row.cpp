#include "row.h"


Row::Row(const Row& other)
{
	m_size = other.m_size;
	m_row = new Tile[m_size];
	for (int i = 0; i < m_size; ++i) {
		m_row[i] = other.m_row[i];
	}
}

Row::~Row()
{
	if(m_row!= NULL)
	{
		delete [] m_row;
	}
	
}

Row::Row(int size, const Tile& value)
{
	m_size = size;
	m_row = new Tile[size];
	for (int i = 0; i < size; i++)
	{
		m_row[i] = value;
	}
}

const Tile& Row::at(int index) const
{
	return m_row[index];
}

Tile& Row::at(int index)
{
	return m_row[index];
}

void Row::pushBack(const Tile& val)
{
	m_size++;
	Tile* temp = new Tile[m_size];
	for (int i = 0 ; i<m_size-1 ; i++)
	{
		temp[i] = m_row[i];
	}
	temp[m_size - 1] = val;

	delete[] m_row;
	m_row = temp;
}

Row& Row::operator = (const Row& other)
{
	if (this != &other)
	{
		// Perform deep copy
		delete[] m_row; // Deallocate old memory
		m_size = other.m_size;
		m_row = new Tile[m_size]; // Allocate new memory

		// Copy elements
		for (int i = 0; i < m_size; i++)
		{
			m_row[i] = other.m_row[i];
		}
	}

	return *this;
}
bool Row::empty() const
{
	return (m_size == 0);
}
int Row::size() const
{
	return m_size;
}
