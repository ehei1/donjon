#include "pch.h"
#include "Dungeon.h"
#include "FactoryImpl.h"

namespace donjon
{
	IDungeon* FactoryImpl::CreateDungeon(const Option& option)
	{
		auto dungeon = new Dungeon(option.mRow, option.mColumn);

		InitializeCells(option, *dungeon);

		return dungeon;
	}

	void FactoryImpl::InitializeCells(const Option& option, Dungeon& dungeon) const
	{
		std::srand(option.mSeed);

		switch (option.mDungeonLayout) {
		case DungeonLayout::Box: {
			break;
		}
		case DungeonLayout::Round: {
			RoundMask(option, dungeon);
			break;
		}
		default:
			throw std::invalid_argument("not implemented");
		}
	}

	void FactoryImpl::RoundMask(const Option& option, Dungeon& dungeon) const
	{
		auto centerRow = option.mRow / 2;
		auto centerCol = option.mColumn / 2;

		for (size_t row{}; row < option.mRow; ++row) {
			for (size_t col{}; col < option.mColumn; ++col) {
				auto distance = sqrt(pow(row - centerRow, 2) + pow(col - centerCol, 2));

				if (distance > centerCol) {
					dungeon.Update(row, col, CellType::Blocked);
				}
			}
		}
	}
}
