#ifndef _GAMELOGIC_H
#define _GAMELOGIC_H 1

#include "Util.h"
#include "Costs.h"

class GameLogic
{
public:
    GameLogic(long int start);

	Costs* GameCosts;

	void UpdatePlayerResources();			//Give the player resources based on how much time has passed since last update

	float GetWoodCount();					//Returns the current amount of resources the player has
	float GetCoinsCount();
	float GetStoneCount();
	float GetSteelCount();
	float GetManaCount();

	int GetScoutCount();					//Returns the number of units the player currently owns
	int GetSwordmanCount();
	int GetIceMageCount();

	float GetWoodRate();					//Returns the current factored TOTAL regen rate 
	float GetCoinsRate();
	float GetStoneRate();
	float GetSteelRate();
	float GetManaRate();

	bool GetHasLumbermill();						//Does the player have the structure?
	bool GetHasHouses();
	bool GetHasQuarry();
	bool GetHasMines();
	bool GetHasMagicCrystal();

	bool GetHasBarracks();
	bool GetHasRallyingPoint();
	bool GetHasAcademy();

	int GetLumbermillLevel();					//Returns the player's structure's upgrade level
	int GetHousesLevel();
	int GetQuarryLevel();
	int GetMinesLevel();
	int GetMagicCrystalLevel();

	int GetBarracksLevel();
	int GetRallyingPointLevel();
	int GetAcademyLevel();

	long int GetGameTime();					//Gets the Game Time in ms
	long int GetGameTimeInSeconds();		//Gets the Game Time in seconds

	void PassMinute();
	void PassHour();

	bool AttemptPurchase(int resource);

	bool AttemptUnitPurchase(int unittype, int tobuycount);

private:
	float WoodCount;						//The amount of the given resource the player currently has
	float CoinsCount;
	float StoneCount;
	float SteelCount;
	float ManaCount;

	int ScoutCount;							//How many of these units does the player have?
	int SwordmanCount;
	int IceMageCount;

	bool HasLumbermill;						//Does the player have the structure?
	bool HasHouses;
	bool HasQuarry;
	bool HasMines;
	bool HasMagicCrystal;

	bool HasBarracks;						//Military and Research structures
	bool HasRallyingPoint;
	bool HasAcademy;

	int LumbermillLevel;					//Resource collector levels
	int HousesLevel;
	int QuarryLevel;
	int MinesLevel;
	int MagicCrystalLevel;

	int BarracksLevel;						//Military and Research structure levels
	int RallyingPointLevel;
	int AcademyLevel;

	long int ResourceUpdateTime;			//The time the resources were last updated
	long int StartTime;						//The time the application started. Used to calibrate GetTickCount

	long int ButtonDelta;					//The extra time that needs to be added because of button presses

	float WoodBaseRate;						//The base regen rate per second of all the resources
	float CoinsBaseRate;
	float StoneBaseRate;
	float SteelBaseRate;
	float ManaBaseRate;

	float LumbermillUpgradeRate;			//How much does each upgrade level improve resource collection?
	float HousesUpgradeRate;
	float QuarryUpgradeRate;
	float MinesUpgradeRate;
	float MagicCrystalUpgradeRate;

	long int GameTime;						//The total amount of time that has passed in the game in milliseconds

	int TimeMultiplier;						//Used for increasing game speed

	void PassTime(long int seconds);

	bool CanAfford(TotalCost* itemcost);		//Checks if the player can afford the item. Returns true for yes and false for no
	bool CanAfford(TotalCost* itemcost, int count);

	void SubtractFromResourcePool(TotalCost* itemcost);  //Subtracts the cost from the player's resource pool
	void SubtractFromResourcePool(TotalCost* itemcost, int count);  //Subtracts the cost from the player's resource pool
};

#endif