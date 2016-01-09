#include "BarracksWidget.h"

using namespace Wt;

BarracksWidget::BarracksWidget(GameLogic* gamelogic, SideBarWidget* gamemenuwidget, WContainerWidget *parent)
    : WContainerWidget(parent)
{
	GameMenuWidget = gamemenuwidget;

	setContentAlignment(AlignCenter);

	BarracksStyle = WCssDecorationStyle();
	BarracksStyle.setBackgroundColor(WColor(255, 210, 220));

	setDecorationStyle(BarracksStyle);

	Gameplay = gamelogic;

	new WText("Welcome to the Barracks!", this);
	DoubleBreak();

	ScoutImage = new WImage("resources/Scout.png", this);
	ScoutImage->setOffsets(50, Left);
	ScoutImage->setOffsets(50, Top);
	ScoutImage->setToolTip("Scout");

	ScoutCountText = new WText(IntToString(Gameplay->GetScoutCount()) + " Scouts", this);
	ScoutCountText->setMargin(60, Left);

	ScoutCostText = new WText(MakeCostString(Gameplay->GameCosts->ScoutCosts), this);
	ScoutCostText->setMargin(60, Left);

	ScoutPurchaseCountSpinBox = new WSpinBox(this);
	ScoutPurchaseCountSpinBox->setValue(0);
	ScoutPurchaseCountSpinBox->setRange(0, 1000);
	ScoutPurchaseCountSpinBox->setSingleStep(1);
	ScoutPurchaseCountSpinBox->setMargin(60, Left | Right);

	PurchaseScoutButton = new WPushButton("Purchase Scouts!", this);
	PurchaseScoutButton->setOffsets(60, Left);

	DoubleBreak();

	SwordmanImage = new WImage("resources/Swordman.png", this);
	SwordmanImage->setOffsets(50, Left);
	SwordmanImage->setOffsets(50, Top);
	SwordmanImage->setToolTip("Swordman");

	SwordmanCountText = new WText(IntToString(Gameplay->GetSwordmanCount()) + " Swordmen", this);
	SwordmanCountText->setMargin(60, Left);

	SwordmanCostText = new WText(MakeCostString(Gameplay->GameCosts->SwordmanCosts), this);
	SwordmanCostText->setMargin(60, Left);

	SwordmanPurchaseCountSpinBox = new WSpinBox(this);
	SwordmanPurchaseCountSpinBox->setValue(0);
	SwordmanPurchaseCountSpinBox->setRange(0, 1000);
	SwordmanPurchaseCountSpinBox->setSingleStep(1);
	SwordmanPurchaseCountSpinBox->setMargin(60, Left | Right);

	PurchaseSwordmanButton = new WPushButton("Purchase Swordmen!", this);
	PurchaseSwordmanButton->setOffsets(60, Left);

	DoubleBreak();

	IceMageImage = new WImage("resources/IceMage.png", this);
	IceMageImage->setOffsets(50, Left);
	IceMageImage->setOffsets(50, Top);
	IceMageImage->setToolTip("Ice Mage");

	IceMageCountText = new WText(IntToString(Gameplay->GetIceMageCount()) + " Ice Mages", this);
	IceMageCountText->setMargin(60, Left);

	IceMageCostText = new WText(MakeCostString(Gameplay->GameCosts->IceMageCosts), this);
	IceMageCostText->setMargin(60, Left);

	IceMagePurchaseCountSpinBox = new WSpinBox(this);
	IceMagePurchaseCountSpinBox->setValue(0);
	IceMagePurchaseCountSpinBox->setRange(0, 1000);
	IceMagePurchaseCountSpinBox->setSingleStep(1);
	IceMagePurchaseCountSpinBox->setMargin(60, Left | Right);

	PurchaseIceMageButton = new WPushButton("Purchase Ice Mages!", this);
	PurchaseIceMageButton->setOffsets(60, Left);

	DoubleBreak();

	PurchaseScoutButton->clicked().connect(this, &BarracksWidget::BuyScout);
	PurchaseSwordmanButton->clicked().connect(this, &BarracksWidget::BuySwordman);
	PurchaseIceMageButton->clicked().connect(this, &BarracksWidget::BuyIceMage);
}

void BarracksWidget::BuyScout()
{
	if (Gameplay->AttemptUnitPurchase(0, ScoutPurchaseCountSpinBox->value()))
	{
		ScoutCountText->setText(IntToString(Gameplay->GetScoutCount()) + " Scouts");
	}
}

void BarracksWidget::BuySwordman()
{
	if (Gameplay->AttemptUnitPurchase(1, SwordmanPurchaseCountSpinBox->value()))
	{
		SwordmanCountText->setText(IntToString(Gameplay->GetSwordmanCount()) + " Swordmen");
	}
}

void BarracksWidget::BuyIceMage()
{
	if (Gameplay->AttemptUnitPurchase(2, IceMagePurchaseCountSpinBox->value()))
	{
		IceMageCountText->setText(IntToString(Gameplay->GetIceMageCount()) + " Ice Mages");
	}
}

void BarracksWidget::SingleBreak()
{
	new WBreak(this);
}

void BarracksWidget::DoubleBreak()
{
	new WBreak(this);
	new WBreak(this);
}

std::string BarracksWidget::MakeCostString(TotalCost* cost)
{
	std::string CostString = ""; 

	CostString = CostString + "Cost Per Unit: ";

	if (cost->FiveCost[0] != 0)
	{
		CostString = CostString + IntToString(cost->FiveCost[0]) + " Wood ";
	}

	if (cost->FiveCost[1] != 0)
	{
		CostString = CostString + IntToString(cost->FiveCost[1]) + " Coins ";
	}

	if (cost->FiveCost[2] != 0)
	{
		CostString = CostString + IntToString(cost->FiveCost[2]) + " Stone ";
	}

	if (cost->FiveCost[3] != 0)
	{
		CostString = CostString + IntToString(cost->FiveCost[3]) + " Steel ";
	}

	if (cost->FiveCost[4] != 0)
	{
		CostString = CostString + IntToString(cost->FiveCost[4]) + " Mana   ";
	}

	return CostString;
}