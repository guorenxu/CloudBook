#ifndef _BARRACKSWIDGET_H
#define _BARRACKSWIDGET_H 1

#include "Util.h"
#include "GameLogic.h"
#include "SideBarWidget.h"

using namespace Wt;

class BarracksWidget : public Wt::WContainerWidget
{
public:
    BarracksWidget(GameLogic* gamelogic, SideBarWidget* gamemenuwidget, Wt::WContainerWidget *parent = 0);

private:
	GameLogic* Gameplay;

	SideBarWidget* GameMenuWidget;

	WImage* ScoutImage;
	WImage* SwordmanImage;
	WImage* IceMageImage;

	WSpinBox* ScoutPurchaseCountSpinBox;
	WSpinBox* SwordmanPurchaseCountSpinBox;
	WSpinBox* IceMagePurchaseCountSpinBox;

	WPushButton* PurchaseScoutButton;
	WPushButton* PurchaseSwordmanButton;
	WPushButton* PurchaseIceMageButton;

	WText* ScoutCostText;
	WText* SwordmanCostText;
	WText* IceMageCostText;

	WText* ScoutCountText;
	WText* SwordmanCountText;
	WText* IceMageCountText;

	WCssDecorationStyle BarracksStyle;

	std::string MakeCostString(TotalCost* cost);

	void BuyScout();				//Functions for button click binding
	void BuySwordman();
	void BuyIceMage();

	void SingleBreak();
	void DoubleBreak();
};

#endif