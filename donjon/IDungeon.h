#pragma once

namespace donjon
{
	enum class DungeonLayout
	{
		Box,
		Cross,
		Round,
	};

	enum class RoomLayout
	{
		Packed,
		Scattered,
	};

	enum class CorridorLayout
	{
		Labyrinth,
		Bent,
		Straight,
	};

	enum class MapStyle
	{
		Standard,
	};

	enum class CellType
	{
		Nothing,
		Blocked = 0x1,
		Room = 0x2,
		Corridor = 0x4,
		Perimeter = 0x10,
		Entrance = 0x20,
		RoomID = 0xffc0,
		Arch = 0x10000,
		Door = 0x20000,
		Locked = 0x40000,
		Trapped = 0x80000,
		Secret = 0x100000,
		Portc = 0x200000,
		StairOn = 0x400000,
		StairUp = 0x800000,
		Label = 0xf000000,
		OpenSpace = Room | Corridor,
		DoorSpace = Arch | Door | Locked | Trapped | Secret | Portc,
		Espace = Entrance | DoorSpace | Label,
		Stairs = StairOn | StairUp,
		BlockRoom = Blocked | Room,
		BlockCorridor = Blocked | Perimeter | Corridor,
		BlockDoor = Blocked | DoorSpace,
	};

	struct Option
	{
		friend class FactoryImpl;

	public:
		Option(size_t seed, size_t row, size_t column, DungeonLayout dungeonLayout, size_t roomMin, size_t roomMax, RoomLayout roomLayout, CorridorLayout corridorLayout, size_t removeDeadends, size_t addStairs, MapStyle mapStyle, size_t cellSize) : mSeed{ seed }, mRow{ row }, mColumn{ column }, mDungeonLayout{ dungeonLayout }, mRoomMin{ roomMin }, mRoomMax{ roomMax }, mRoomLayout{ roomLayout }, mCorridorLayout{ corridorLayout }, mRemoveDeadends{ removeDeadends }, mAddStairs{ addStairs }, mMapStyle{ mapStyle }, mCellSize{ cellSize }
		{}

	private:
		const size_t mSeed;
		const size_t mRow;
		const size_t mColumn;
		const DungeonLayout mDungeonLayout;
		const size_t mRoomMin;
		const size_t mRoomMax;
		const RoomLayout mRoomLayout;
		const CorridorLayout mCorridorLayout;
		const size_t mRemoveDeadends;
		const size_t mAddStairs;
		const MapStyle mMapStyle;
		const size_t mCellSize;
	};

	class IDungeon
	{
	public:
	};

	class Factory
	{
	public:
		static IDungeon* CreateDungeon(const Option&);
	};
};