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
		void EmplaceRooms(const Option&, Dungeon&) {}
		void OpenRooms(const Option&, Dungeon&) {}
	};
}
