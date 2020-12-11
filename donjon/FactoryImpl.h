#pragma once
#include <vector>
#include "IDungeon.h"

namespace donjon
{
	class IDungeon;
	class Dungeon;
	struct Option;

	class FactoryImpl
	{
	public:
		IDungeon* CreateDungeon(const Option& option);

	private:
		void InitializeCells(const Option&, Dungeon&) const;
		void RoundMask(const Option&, Dungeon&) const;
		void EmplaceRooms(const Option&, Dungeon&) const;
		void PackRooms(const Option&, Dungeon&) const;
		void ScatterRooms(const Option&, Dungeon&) const;
		// return: count of rooms
		size_t EmplaceRoom(Dungeon&, size_t row, size_t col, size_t roomCount) const;
		void AllocateRooms(const Option&) const;
		void OpenRooms(const Option&, Dungeon&) const;
		void LabelRooms(const Option&, Dungeon&) const;
		void EmplaceCorridors(const Option&, Dungeon&) const;
		void EmplaceStairs(const Option&, Dungeon&) const;
		void ClearDungeon(const Option&, Dungeon&) const;

	};
}
