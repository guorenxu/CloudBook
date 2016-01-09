#include "Costs.h"

Costs::Costs()
{
	LumbermillCosts[0] = new TotalCost(0, 0, 0, 0, 0);
	LumbermillCosts[1] = new TotalCost(0, 500, 0, 0, 0);
	LumbermillCosts[2] = new TotalCost(0, 600, 100, 0, 0);
	LumbermillCosts[3] = new TotalCost(0, 700, 200, 0, 0);
	LumbermillCosts[4] = new TotalCost(0, 1000, 200, 50, 0);

	HousesCosts[0] = new TotalCost(0, 0, 0, 0, 0);
	HousesCosts[1] = new TotalCost(700, 0, 0, 0, 0);
	HousesCosts[2] = new TotalCost(900, 0, 100, 0, 0);
	HousesCosts[3] = new TotalCost(1000, 0, 200, 0, 0);
	HousesCosts[4] = new TotalCost(1000, 0, 200, 50, 0);

	QuarryCosts[0] = new TotalCost(1000, 1000, 0, 0, 0);
	QuarryCosts[1] = new TotalCost(0, 1000, 0, 0, 0);
	QuarryCosts[2] = new TotalCost(0, 1300, 0, 50, 0);
	QuarryCosts[3] = new TotalCost(0, 1600, 0, 200, 0);
	QuarryCosts[4] = new TotalCost(0, 2000, 0, 300, 50);

	MinesCosts[0] = new TotalCost(0, 500, 1500, 0, 0);
	MinesCosts[1] = new TotalCost(1000, 0, 200, 0, 0);
	MinesCosts[2] = new TotalCost(2000, 0, 400, 0, 10);
	MinesCosts[3] = new TotalCost(3000, 2000, 600, 0, 50);
	MinesCosts[4] = new TotalCost(5000, 2500, 1200, 0, 200);

	MagicCrystalCosts[0] = new TotalCost(0, 0, 0, 2000, 0);
	MagicCrystalCosts[1] = new TotalCost(0, 1500, 0, 100, 0);
	MagicCrystalCosts[2] = new TotalCost(0, 2000, 0, 200, 0);
	MagicCrystalCosts[3] = new TotalCost(0, 5000, 1000, 300, 0);
	MagicCrystalCosts[4] = new TotalCost(0, 1000, 1500, 500, 0);

	BarracksCosts[0] = new TotalCost(600, 600, 50, 0, 0);
	BarracksCosts[1] = new TotalCost(1200, 1000, 100, 60, 0);
	BarracksCosts[2] = new TotalCost(2000, 1400, 160, 140, 10);
	BarracksCosts[3] = new TotalCost(2000, 1400, 300, 300, 50);
	BarracksCosts[4] = new TotalCost(4000, 4000, 2000, 600, 300);

	RallyingPointCosts[0] = new TotalCost(300, 300, 20, 0, 0);
	RallyingPointCosts[1] = new TotalCost(600, 700, 40, 120, 0);
	RallyingPointCosts[2] = new TotalCost(1000, 1200, 100, 250, 0);
	RallyingPointCosts[3] = new TotalCost(1100, 1400, 250, 550, 0);
	RallyingPointCosts[4] = new TotalCost(2000, 3600, 1100, 750, 0);

	AcademyCosts[0] = new TotalCost(1000, 2000, 600, 50, 100);
	AcademyCosts[1] = new TotalCost(0, 0, 0, 0, 600);
	AcademyCosts[2] = new TotalCost(0, 0, 0, 0, 0);
	AcademyCosts[3] = new TotalCost(0, 0, 0, 0, 0);
	AcademyCosts[4] = new TotalCost(0, 0, 0, 0, 0);

	ScoutCosts = new TotalCost(100, 140, 0, 0, 0);
	SwordmanCosts = new TotalCost(0, 400, 0, 50, 0);
	IceMageCosts = new TotalCost(0, 800, 75, 0, 50);
}
