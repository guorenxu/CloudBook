#include "GameLogic.h"

GameLogic::GameLogic(long int start)
{
	WoodCount = 0;							//Set starting resources to 0
	CoinsCount = 0;
	StoneCount = 0;
	SteelCount = 0;
	ManaCount = 0;

	ScoutCount = 0;							//Set starting unit counts to 0
	SwordmanCount = 0;
	IceMageCount = 0;

	GameCosts = new Costs();

	ResourceUpdateTime = 0;					//Initialize to 0, will be set each time when update happens
	StartTime = start;						//One time setting of when the application started

	ButtonDelta = 0;						//No buttons pressed yet, so no time added

	HasLumbermill = true;					//Set the player to only having a lumbermill and houses when they start
	HasHouses = true;
	HasQuarry = false;
	HasMines = false;
	HasMagicCrystal = false;

	HasBarracks = false;					//Player doesn't start with any of these
	HasRallyingPoint = false;
	HasAcademy = false;

	WoodBaseRate = 0.12f;					//Base rate for unupgraded structure
	CoinsBaseRate = 0.1f;
	StoneBaseRate = 0.045f;
	SteelBaseRate = 0.008f;
	ManaBaseRate = 0.003f;

	LumbermillUpgradeRate = 0.07f;			//How much does each upgrade level improve resource collection?
	HousesUpgradeRate = 0.05f;
	QuarryUpgradeRate = 0.02f;
	MinesUpgradeRate = 0.005f;
	MagicCrystalUpgradeRate = 0.002f;		

	LumbermillLevel = 0;					//Player starts with no upgrades to anything
	HousesLevel = 0;
	QuarryLevel = 0;
	MinesLevel = 0;
	MagicCrystalLevel = 0;

	BarracksLevel = 0;
	RallyingPointLevel = 0;
	AcademyLevel = 0;

	GameTime = 0;							//Initialize to 0

	TimeMultiplier = 1;						//Initialize to real time

	WoodCount = 0;							//Set starting resources to 0
	CoinsCount = 0;
	StoneCount = 0;
	SteelCount = 0;
	ManaCount = 0;
}

float GameLogic::GetWoodRate()				//Returns TOTAL rate of resource regen per second
{
	if (HasLumbermill)
	{
		return (WoodBaseRate + (LumbermillLevel * LumbermillUpgradeRate));
	}
	else
	{
		return 0;
	}
}

float GameLogic::GetCoinsRate()
{
	if (HasHouses)
	{
		return (CoinsBaseRate + (HousesLevel * HousesUpgradeRate));
	}
	else
	{
		return 0;
	}
}

float GameLogic::GetStoneRate()
{
	if (HasQuarry)
	{
		return (StoneBaseRate + (QuarryLevel * QuarryUpgradeRate));
	}
	else
	{
		return 0;
	}
}

float GameLogic::GetSteelRate()
{
	if (HasMines)
	{
		return (SteelBaseRate + (MinesLevel * MinesUpgradeRate));
	}
	else
	{
		return 0;
	}
}

float GameLogic::GetManaRate()
{
	if (HasMagicCrystal)
	{
		return (ManaBaseRate + (MagicCrystalLevel * MagicCrystalUpgradeRate));
	}
	else
	{
		return 0;
	}
}

float GameLogic::GetWoodCount()				//Returns the amount of resources the player has
{
	return WoodCount;
}

float GameLogic::GetCoinsCount()
{
	return CoinsCount;
}

float GameLogic::GetStoneCount()
{
	return StoneCount;
}

float GameLogic::GetSteelCount()
{
	return SteelCount;
}

float GameLogic::GetManaCount()
{
	return ManaCount;
}

int GameLogic::GetScoutCount()
{
	return ScoutCount;
}

int GameLogic::GetSwordmanCount()
{
	return SwordmanCount;
}

int GameLogic::GetIceMageCount()
{
	return IceMageCount;
}

bool GameLogic::GetHasLumbermill()						//Does the player have the structure?
{
	return HasLumbermill;
}

bool GameLogic::GetHasHouses()
{
	return HasHouses;
}

bool GameLogic::GetHasQuarry()
{
	return HasQuarry;
}

bool GameLogic::GetHasMines()
{
	return HasMines;
}

bool GameLogic::GetHasMagicCrystal()
{
	return HasMagicCrystal;
}

bool GameLogic::GetHasBarracks()
{
	return HasBarracks;
}

bool GameLogic::GetHasRallyingPoint()
{
	return HasRallyingPoint;
}

bool GameLogic::GetHasAcademy()
{
	return HasAcademy;
}

int GameLogic::GetLumbermillLevel()					//Returns the player's structure's upgrade level
{
	return LumbermillLevel;
}

int GameLogic::GetHousesLevel()
{
	return HousesLevel;
}

int GameLogic::GetQuarryLevel()
{
	return QuarryLevel;
}

int GameLogic::GetMinesLevel()
{
	return MinesLevel;
}

int GameLogic::GetMagicCrystalLevel()
{
	return MagicCrystalLevel;
}

int GameLogic::GetBarracksLevel()
{
	return BarracksLevel;
}

int GameLogic::GetRallyingPointLevel()
{
	return RallyingPointLevel;
}

int GameLogic::GetAcademyLevel()
{
	return AcademyLevel;
}

void GameLogic::UpdatePlayerResources()
{
	GameTime = GetTickCount() - StartTime + ButtonDelta;		//Set current to the amount of time passed so far plus manual clock adjustments
	long int delta = GameTime - ButtonDelta - ResourceUpdateTime;				//Set delta has the difference between current time and when resources were last updated
	ResourceUpdateTime = GameTime - ButtonDelta;								//Set update time to now
			
	float deltaseconds = (delta / 1000.0f);						//Calculate in seconds

	WoodCount = WoodCount + (deltaseconds * GetWoodRate());			//Increase resource count by time passed and factored rate
	CoinsCount = CoinsCount + (deltaseconds * GetCoinsRate());
	StoneCount = StoneCount + (deltaseconds * GetStoneRate());
	SteelCount = SteelCount + (deltaseconds * GetSteelRate());
	ManaCount = ManaCount + (deltaseconds * GetManaRate());
}

long int GameLogic::GetGameTime()					//Gets the Game Time in ms
{
	return GameTime;
}

long int GameLogic::GetGameTimeInSeconds()		//Gets the Game Time in seconds
{
	return GameTime / 1000;
}

void GameLogic::PassMinute()
{
	PassTime(60);
}

void GameLogic::PassHour()
{
	PassTime(3600);
}

void GameLogic::PassTime(long int seconds)
{
	ButtonDelta = ButtonDelta + (seconds * 1000);
	long int deltaseconds = seconds;

	WoodCount = WoodCount + (deltaseconds * GetWoodRate());			//Increase resource count by time passed and factored rate
	CoinsCount = CoinsCount + (deltaseconds * GetCoinsRate());
	StoneCount = StoneCount + (deltaseconds * GetStoneRate());
	SteelCount = SteelCount + (deltaseconds * GetSteelRate());
	ManaCount = ManaCount + (deltaseconds * GetManaRate());
}

bool GameLogic::AttemptPurchase(int structureID)
{
	if (structureID == 0)
	{
		if (CanAfford(GameCosts->LumbermillCosts[HasLumbermill + LumbermillLevel]))
		{
			SubtractFromResourcePool(GameCosts->LumbermillCosts[HasLumbermill + LumbermillLevel]);

			if (HasLumbermill)
			{
				LumbermillLevel++;
				return true;
			}
			else
			{
				HasLumbermill = true;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else if (structureID == 1)
	{
		if (CanAfford(GameCosts->HousesCosts[HasHouses + HousesLevel]))
		{
			SubtractFromResourcePool(GameCosts->HousesCosts[HasHouses + HousesLevel]);

			if (HasHouses)
			{
				HousesLevel++;
				return true;
			}
			else
			{
				HasHouses = true;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else if (structureID == 2)
	{
		if (CanAfford(GameCosts->QuarryCosts[HasQuarry + QuarryLevel]))
		{
			SubtractFromResourcePool(GameCosts->QuarryCosts[HasQuarry + QuarryLevel]);

			if (HasQuarry)
			{
				QuarryLevel++;
				return true;
			}
			else
			{
				HasQuarry = true;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else if (structureID == 3)
	{
		if (CanAfford(GameCosts->MinesCosts[HasMines + MinesLevel]))
		{
			SubtractFromResourcePool(GameCosts->MinesCosts[HasMines + MinesLevel]);

			if (HasMines)
			{
				MinesLevel++;
				return true;
			}
			else
			{
				HasMines = true;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else if (structureID == 4)
	{
		if (CanAfford(GameCosts->MagicCrystalCosts[HasMagicCrystal + MagicCrystalLevel]))
		{
			SubtractFromResourcePool(GameCosts->MagicCrystalCosts[HasMagicCrystal + MagicCrystalLevel]);

			if (HasMagicCrystal)
			{
				MagicCrystalLevel++;
				return true;
			}
			else
			{
				HasMagicCrystal = true;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else if (structureID == 5)
	{
		if (CanAfford(GameCosts->BarracksCosts[HasBarracks + BarracksLevel]))
		{
			SubtractFromResourcePool(GameCosts->BarracksCosts[HasBarracks + BarracksLevel]);

			if (HasBarracks)
			{
				BarracksLevel++;
				return true;
			}
			else
			{
				HasBarracks = true;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else if (structureID == 6)
	{
		if (CanAfford(GameCosts->RallyingPointCosts[HasRallyingPoint + RallyingPointLevel]))
		{
			SubtractFromResourcePool(GameCosts->RallyingPointCosts[HasRallyingPoint + RallyingPointLevel]);

			if (HasRallyingPoint)
			{
				RallyingPointLevel++;
				return true;
			}
			else
			{
				HasRallyingPoint = true;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else if (structureID == 7)
	{
		if (CanAfford(GameCosts->AcademyCosts[HasAcademy + AcademyLevel]))
		{
			SubtractFromResourcePool(GameCosts->AcademyCosts[HasAcademy + AcademyLevel]);

			if (HasAcademy)
			{
				AcademyLevel++;
				return true;
			}
			else
			{
				HasAcademy = true;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool GameLogic::AttemptUnitPurchase(int unittype, int tobuycount)
{
	if (unittype == 0)
	{
		if (CanAfford(GameCosts->ScoutCosts, tobuycount))
		{
			SubtractFromResourcePool(GameCosts->ScoutCosts, tobuycount);
			ScoutCount = ScoutCount + tobuycount;

			return true;
		}
		else
		{
			return false;
		}
	}
	else if (unittype == 1)
	{
		if (CanAfford(GameCosts->SwordmanCosts, tobuycount))
		{
			SubtractFromResourcePool(GameCosts->SwordmanCosts, tobuycount);
			SwordmanCount = SwordmanCount + tobuycount;

			return true;
		}
		else
		{
			return false;
		}
	}
	else if (unittype == 2)
	{
		if (CanAfford(GameCosts->IceMageCosts, tobuycount))
		{
			SubtractFromResourcePool(GameCosts->IceMageCosts, tobuycount);
			IceMageCount = IceMageCount + tobuycount;

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool GameLogic::CanAfford(TotalCost* itemcost)
{
	if (WoodCount >= itemcost->FiveCost[0] &&
	CoinsCount >= itemcost->FiveCost[1] &&
	StoneCount >= itemcost->FiveCost[2] &&
	SteelCount >= itemcost->FiveCost[3] &&
	ManaCount >= itemcost->FiveCost[4])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GameLogic::CanAfford(TotalCost* itemcost, int count)
{
	if (WoodCount >= itemcost->FiveCost[0] * count &&
	CoinsCount >= itemcost->FiveCost[1] * count &&
	StoneCount >= itemcost->FiveCost[2] * count &&
	SteelCount >= itemcost->FiveCost[3] * count &&
	ManaCount >= itemcost->FiveCost[4] * count)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameLogic::SubtractFromResourcePool(TotalCost* itemcost)
{
	WoodCount = WoodCount - itemcost->FiveCost[0];
	CoinsCount = CoinsCount - itemcost->FiveCost[1];
	StoneCount = StoneCount - itemcost->FiveCost[2];
	SteelCount = SteelCount - itemcost->FiveCost[3];
	ManaCount = ManaCount - itemcost->FiveCost[4];
}

void GameLogic::SubtractFromResourcePool(TotalCost* itemcost, int count)
{
	WoodCount = WoodCount - itemcost->FiveCost[0] * count;
	CoinsCount = CoinsCount - itemcost->FiveCost[1] * count;
	StoneCount = StoneCount - itemcost->FiveCost[2] * count;
	SteelCount = SteelCount - itemcost->FiveCost[3] * count;
	ManaCount = ManaCount - itemcost->FiveCost[4] * count;
}