#ifndef _TOWNWIDGET_H
#define _TOWNWIDGET_H 1

#include "Util.h"
#include "GameLogic.h"
#include "SideBarWidget.h"

using namespace Wt;

class TownWidget : public WPaintedWidget
{
public:
    TownWidget(GameLogic* gamelogic, SideBarWidget* gamemenuwidget, Wt::WContainerWidget *parent = 0);

	void paintEvent(Wt::WPaintDevice *paintDevice);

private:
	GameLogic* Gameplay;

	SideBarWidget* GameMenuWidget;

	Vector2D* BuildingDrawCoords[8];

	WRectArea* BuildingRects[8];

	WPushButton* LumbermillButton;
	WPushButton* HousesButton;
	WPushButton* QuarryButton;
	WPushButton* MinesButton;
	WPushButton* MagicCrystalButton;

	WPushButton* BarracksButton;
	WPushButton* RallyingPointButton;
	WPushButton* AcademyButton;
	
	WPushButton *GoToBarracksButton;

	WText* WoodRate;
	WText* CoinsRate;
	WText* StoneRate;
	WText* SteelRate;
	WText* ManaRate;

	WText* LMLevel;
	WText* HLevel;
	WText* QLevel;
	WText* MLevel;
	WText* MCLevel;

	WText* BLevel;
	WText* RPLevel;
	WText* ALevel;

	WCssDecorationStyle TownStyle;

	std::string MakeCostString(bool hasbuilding, std::string buildingname, TotalCost* cost);

	void BuyLumbermill();				//Functions for button click binding
	void BuyHouses();
	void BuyQuarry();
	void BuyMines();
	void BuyMagicCrystal();

	void BuyBarracks();
	void BuyRallyingPoint();
	void BuyAcademy();

	void GoToBarracksClicked();

	void SingleBreak();
	void DoubleBreak();

	void LumbermillClicked();
	void HousesClicked();
	void QuarryClicked();
	void MinesClicked();
	void MagicCrystalClicked();
	void BarracksClicked();
	void RallyingPointClicked();
};

#endif