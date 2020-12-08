#include "pch.h"
#include "Dungeon.h"

namespace donjon
{
	Dungeon::Dungeon(size_t row, size_t column) : mRow{ row }, mColumn{ column }
	{
		__super::resize(row* column);
	}

	void Dungeon::Update(size_t row, size_t col, CellType type)
	{
		operator[](row* mRow + col) = type;
	}

}