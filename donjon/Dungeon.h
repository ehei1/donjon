#pragma once
#include <vector>
#include "IDungeon.h"

namespace donjon
{
	class Dungeon : protected std::vector<CellType>, public IDungeon
	{
	public:
		Dungeon(size_t row, size_t column);

		void Update(size_t row, size_t col, CellType);
		CellType Get(size_t row, size_t col) const;

	private:
		size_t mRow{};
		size_t mColumn{};
	};

}