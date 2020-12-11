#include "pch.h"
#include <stdexcept>
#include "Dungeon.h"

namespace donjon
{
	Dungeon::Dungeon(size_t row, size_t column) : mRow{ row }, mColumn{ column }
	{
		__super::resize(row * column);
	}

	void Dungeon::Update(size_t row, size_t col, CellType type)
	{
		auto index = row * mRow + col;

		if (index < size()) {
			operator[](index) = type;
		}
		else {
			throw std::range_error("out or range");
		}
	}

	CellType Dungeon::Get(size_t row, size_t col) const
	{
		auto index = row * mRow + col;

		if (index < size()) {
			return operator[](index);
		}
		else {
			throw std::range_error("out or range");
		}
	}
}