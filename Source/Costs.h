#ifndef _COSTS_H
#define _COSTS_H 1

#include "Util.h"

class Costs
{
public:
    Costs();

	TotalCost* LumbermillCosts[5];
	TotalCost* HousesCosts[5];
	TotalCost* QuarryCosts[5];
	TotalCost* MinesCosts[5];
	TotalCost* MagicCrystalCosts[5];
	TotalCost* BarracksCosts[5];
	TotalCost* RallyingPointCosts[5];
	TotalCost* AcademyCosts[5];

	TotalCost* ScoutCosts;
	TotalCost* SwordmanCosts;
	TotalCost* IceMageCosts;
};

#endif