#include "pch.h"
#include "IDungeon.h"
#include "FactoryImpl.h"

namespace donjon
{
	IDungeon* CreateDungeon(const Option& option)
	{
		return FactoryImpl().CreateDungeon(option);
	}
}