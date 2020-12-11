#include "pch.h"
#include "Dungeon.h"
#include "FactoryImpl.h"

namespace donjon
{
	IDungeon* FactoryImpl::CreateDungeon(const Option& option)
	{
		auto dungeon = new Dungeon(option.mRow, option.mColumn);

		InitializeCells(option, *dungeon);
		RoundMask(option, *dungeon);
		EmplaceRooms(option, *dungeon);
		OpenRooms(option, *dungeon);
		LabelRooms(option, *dungeon);
		EmplaceCorridors(option, *dungeon);
		EmplaceStairs(option, *dungeon);
		ClearDungeon(option, *dungeon);

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

	void FactoryImpl::EmplaceRooms(const Option& option, Dungeon& dungeon) const
	{
		switch (option.mRoomLayout) {
		case RoomLayout::Packed:
			PackRooms(option, dungeon);
			break;
		case RoomLayout::Scattered:
			ScatterRooms(option, dungeon);
			break;
		}
	}

	void FactoryImpl::PackRooms(const Option& option, Dungeon& dungeon) const
	{
		auto rowMax = option.mRow / 2;
		auto colMax = option.mColumn / 2;
		size_t roomCount = 0;

		for (size_t row{}; row < rowMax; ++row) {
			for (size_t col{}; col < colMax; ++col) {
				if (CellType::Room == dungeon.Get(row, col)) {
					continue;
				}
				else if ((!row || !col) && (std::rand() % 2)) {
					continue;
				}

				roomCount = EmplaceRoom(dungeon, row, col, roomCount);
			}
		}
	}

	void FactoryImpl::ScatterRooms(const Option& option, Dungeon& dungeon) const
	{

	}

	void FactoryImpl::ScatterRooms(const Option& option, Dungeon& dungeon) const
	{

	}

	void FactoryImpl::AllocateRooms(const Option& option) const
	{

	}

	size_t FactoryImpl::EmplaceRoom(Dungeon& dungeon, size_t row, size_t col, size_t roomCount) const
	{
		if (999 == roomCount) {
			return 999;
		}

		return roomCount + 1;
	}

	void FactoryImpl::OpenRooms(const Option& option, Dungeon& dungeon) const
	{

	}

	void FactoryImpl::LabelRooms(const Option& option, Dungeon& dungeon) const
	{

	}

	void FactoryImpl::EmplaceCorridors(const Option& option, Dungeon& dungeon) const
	{

	}

	void FactoryImpl::EmplaceStairs(const Option& option, Dungeon& dungeon) const
	{

	}

	void FactoryImpl::ClearDungeon(const Option& option, Dungeon& dungeon) const
	{

	}
}
