#include "TownWidget.h"

using namespace Wt;

TownWidget::TownWidget(GameLogic* gamelogic, SideBarWidget* gamemenuwidget, WContainerWidget *parent)
    : WPaintedWidget(parent)
{
	resize(1000, 650);

	GameMenuWidget = gamemenuwidget;

	BuildingDrawCoords[0] = new Vector2D(124, 120);
	BuildingDrawCoords[1] = new Vector2D(217, 262);
	BuildingDrawCoords[2] = new Vector2D(0, 491);
	BuildingDrawCoords[3] = new Vector2D(750, 0);
	BuildingDrawCoords[4] = new Vector2D(438, 194);
	BuildingDrawCoords[5] = new Vector2D(512, 376);
	BuildingDrawCoords[6] = new Vector2D(702, 193);
	BuildingDrawCoords[7] = new Vector2D(0, 0);
	//BuildingDrawCoords[8] = new Vector2D(0, 0);

	for (int i = 0; i <= 7; i++)
	{
		BuildingRects[i] = new WRectArea(BuildingDrawCoords[i]->X, BuildingDrawCoords[i]->Y, 150, 150);
		BuildingRects[i]->setCursor(PointingHandCursor);
		this->addArea(BuildingRects[i]);
	}

	//TownStyle = WCssDecorationStyle();
	//TownStyle.setBackgroundColor(WColor(250, 230, 215));

	//setDecorationStyle(TownStyle);

	Gameplay = gamelogic;

	//new WText("You currently have in your city :", this);
	//DoubleBreak();

	if (Gameplay->GetHasLumbermill())
	{
		BuildingRects[0]->setToolTip("Lumbermill Lv" + IntToString(Gameplay->GetLumbermillLevel()));
	}
	else
	{
		BuildingRects[0]->setToolTip("No Lumbermill");
	}

	if (Gameplay->GetHasHouses())
	{
		BuildingRects[1]->setToolTip("Houses Lv" + IntToString(Gameplay->GetHousesLevel()));
	}
	else
	{
		BuildingRects[1]->setToolTip("No Houses");
	}

	if (Gameplay->GetHasQuarry())
	{
		BuildingRects[2]->setToolTip("Quarry Lv" + IntToString(Gameplay->GetQuarryLevel()));
	}
	else
	{
		BuildingRects[2]->setToolTip("No Quarry");
	}

	if (Gameplay->GetHasMines())
	{
		BuildingRects[3]->setToolTip("Mines Lv" + IntToString(Gameplay->GetMinesLevel()));
	}
	else
	{
		BuildingRects[3]->setToolTip("No Mines");
	}

	if (Gameplay->GetHasMagicCrystal())
	{
		BuildingRects[4]->setToolTip("Magic Crystal Lv" + IntToString(Gameplay->GetMagicCrystalLevel()));
	}
	else
	{
		BuildingRects[4]->setToolTip("No Magic Crystal");
	}

	if (Gameplay->GetHasBarracks())
	{
		BuildingRects[5]->setToolTip("Barracks Lv" + IntToString(Gameplay->GetBarracksLevel()));
	}
	else
	{
		BuildingRects[5]->setToolTip("No Barracks");
	}

	if (Gameplay->GetHasRallyingPoint())
	{
		BuildingRects[6]->setToolTip("Rallying Point Lv" + IntToString(Gameplay->GetRallyingPointLevel()));
	}
	else
	{
		BuildingRects[6]->setToolTip("No Rallying Point");
	}

	if (Gameplay->GetHasAcademy())
	{
		BuildingRects[7]->setToolTip("Academy Lv" + IntToString(Gameplay->GetAcademyLevel()));
	}
	else
	{
		BuildingRects[7]->setToolTip("No Academy");
	}

	//DoubleBreak();

	//WText* FooOne = new WText("Your current resource collection rates per hour: ", this);

	//DoubleBreak();

	//new WText("Wood: ", this);
	//WoodRate = new WText(IntToString(Gameplay->GetWoodRate() * 3600), this);
	//SingleBreak();

	//new WText("Coins: ", this);
	//CoinsRate = new WText(IntToString(Gameplay->GetCoinsRate() * 3600), this);
	//SingleBreak();

	//new WText("Stone: ", this);
	//StoneRate = new WText(IntToString(Gameplay->GetStoneRate() * 3600), this);
	//SingleBreak();

	//new WText("Steel: ", this);
	//SteelRate = new WText(IntToString(Gameplay->GetSteelRate() * 3600), this);
	//SingleBreak();

	//new WText("Mana: ", this);
	//ManaRate = new WText(IntToString(Gameplay->GetManaRate() * 3600), this);
	//SingleBreak();

	//DoubleBreak();

	//LumbermillButton = new WPushButton(MakeCostString(Gameplay->GetHasLumbermill(), "Lumbermill", 
	//	Gameplay->GameCosts->LumbermillCosts[Gameplay->GetHasLumbermill() + Gameplay->GetLumbermillLevel()]), this);               // create a button
	//LumbermillButton->setMargin(0, Left); 
	//DoubleBreak();

	//HousesButton = new WPushButton(MakeCostString(Gameplay->GetHasHouses(), "Houses", 
	//	Gameplay->GameCosts->HousesCosts[Gameplay->GetHasLumbermill() + Gameplay->GetHousesLevel()]), this);               // create a button
	//HousesButton->setMargin(0, Left); 
	//DoubleBreak();

	//QuarryButton = new WPushButton(MakeCostString(Gameplay->GetHasQuarry(), "Quarry", 
	//	Gameplay->GameCosts->QuarryCosts[Gameplay->GetHasQuarry() + Gameplay->GetQuarryLevel()]), this);               // create a button
	//QuarryButton->setMargin(0, Left); 
	//DoubleBreak();

	//MinesButton = new WPushButton(MakeCostString(Gameplay->GetHasMines(), "Mines", 
	//	Gameplay->GameCosts->MinesCosts[Gameplay->GetHasMines() + Gameplay->GetMinesLevel()]), this);               // create a button
	//MinesButton->setMargin(0, Left); 
	//DoubleBreak();

	//MagicCrystalButton = new WPushButton(MakeCostString(Gameplay->GetHasMagicCrystal(), "Magic Crystal", 
	//	Gameplay->GameCosts->MagicCrystalCosts[Gameplay->GetHasMagicCrystal() + Gameplay->GetMagicCrystalLevel()]), this);               // create a button
	//MagicCrystalButton->setMargin(0, Left); 
	//DoubleBreak();

	//BarracksButton = new WPushButton(MakeCostString(Gameplay->GetHasBarracks(), "Barracks", 
	//	Gameplay->GameCosts->BarracksCosts[Gameplay->GetHasBarracks() + Gameplay->GetBarracksLevel()]), this);               // create a button
	//BarracksButton->setMargin(0, Left); 
	//DoubleBreak();

	//RallyingPointButton = new WPushButton(MakeCostString(Gameplay->GetHasRallyingPoint(), "Rallying Point", 
	//	Gameplay->GameCosts->RallyingPointCosts[Gameplay->GetHasRallyingPoint() + Gameplay->GetRallyingPointLevel()]), this);               // create a button
	//RallyingPointButton->setMargin(0, Left); 
	//DoubleBreak();

	//AcademyButton = new WPushButton(MakeCostString(Gameplay->GetHasAcademy(), "Academy", 
	//	Gameplay->GameCosts->AcademyCosts[Gameplay->GetHasAcademy() + Gameplay->GetAcademyLevel()]), this);               // create a button
	//AcademyButton->setMargin(0, Left); 
	//DoubleBreak();

	//GoToBarracksButton = new WPushButton("Go to the Barracks", this);               // create a button
	//GoToBarracksButton->setMargin(0, Left); 
	//DoubleBreak();

	//LumbermillButton->clicked().connect(this, &TownWidget::BuyLumbermill);
	//HousesButton->clicked().connect(this, &TownWidget::BuyHouses);
	//QuarryButton->clicked().connect(this, &TownWidget::BuyQuarry);
	//MinesButton->clicked().connect(this, &TownWidget::BuyMines);
	//MagicCrystalButton->clicked().connect(this, &TownWidget::BuyMagicCrystal);
	//BarracksButton->clicked().connect(this, &TownWidget::BuyBarracks);
	//RallyingPointButton->clicked().connect(this, &TownWidget::BuyRallyingPoint);
	//AcademyButton->clicked().connect(this, &TownWidget::BuyAcademy);
	//GoToBarracksButton->clicked().connect(this, &TownWidget::GoToBarracksClicked);

	BuildingRects[0]->mouseWentDown().connect(this, &TownWidget::LumbermillClicked);
	BuildingRects[1]->mouseWentDown().connect(this, &TownWidget::HousesClicked);
	BuildingRects[2]->mouseWentDown().connect(this, &TownWidget::QuarryClicked);
	BuildingRects[3]->mouseWentDown().connect(this, &TownWidget::MinesClicked);
	BuildingRects[4]->mouseWentDown().connect(this, &TownWidget::MagicCrystalClicked);
	BuildingRects[5]->mouseWentDown().connect(this, &TownWidget::BarracksClicked);
	BuildingRects[6]->mouseWentDown().connect(this, &TownWidget::RallyingPointClicked);
}

void TownWidget::paintEvent(Wt::WPaintDevice *paintDevice)
{
	WPainter painter(paintDevice);

	WPainter::Image townimage("resources/townbase.png", 1000, 650);
	painter.drawImage(0, 0, townimage);

	WPainter::Image lmimage("resources/Lumbermill.png", 1000, 650);
	painter.drawImage(0, 0, lmimage);

	WPainter::Image himage("resources/Houses.png", 1000, 650);
	painter.drawImage(0, 0, himage);

	WPainter::Image qimage("resources/Quarry.png", 1000, 650);
	if (Gameplay->GetHasQuarry())
	{
		painter.drawImage(0, 0, qimage);
	}

	WPainter::Image mimage("resources/Mines.png", 1000, 650);
	if (Gameplay->GetHasMines())
	{
		painter.drawImage(0, 0, mimage);
	}

	WPainter::Image mcimage("resources/MagicCrystal.png", 1000, 650);
	if (Gameplay->GetHasMagicCrystal())
	{
		painter.drawImage(0, 0, mcimage);
	}

	WPainter::Image bimage("resources/Barracks.png", 1000, 650);
	if (Gameplay->GetHasBarracks())
	{
		painter.drawImage(0, 0, bimage);
	}

	WPainter::Image rpimage("resources/RallyingPoint.png", 1000, 650);
	if (Gameplay->GetHasRallyingPoint())
	{
		painter.drawImage(0, 0, rpimage);
	}
}

void TownWidget::LumbermillClicked()
{
	std::string partone = "";

	if (Gameplay->GetHasLumbermill())
	{
		partone = partone + "You have a Lumbermill Lv" + IntToString(Gameplay->GetLumbermillLevel()) + ". It is producing " + IntToString(Gameplay->GetWoodRate() * 3600) + " wood per hour. Do you want to upgrade your Lumbermill? " + MakeCostString(Gameplay->GetHasLumbermill(), "Lumbermill", Gameplay->GameCosts->LumbermillCosts[Gameplay->GetHasLumbermill() + Gameplay->GetLumbermillLevel()]);
	}
	else
	{
		partone = partone + "You don't have a Lumbermill yet. ";
	}

	WMessageBox *messageBox = new WMessageBox
	("Lumbermill",
	 partone,
	 Wt::Information, Wt::Yes | Wt::No);

	messageBox->setModal(true);

	messageBox->show();

    messageBox->buttonClicked().connect(std::bind([=] () {
		if (messageBox->buttonResult() == Wt::Yes)
		{
			BuyLumbermill();
			delete messageBox;
		}
		else
		{
			delete messageBox;
		}
	}));
}

void TownWidget::HousesClicked()
{
	std::string partone = "";

	if (Gameplay->GetHasHouses())
	{
		partone = partone + "You have a Houses Lv" + IntToString(Gameplay->GetHousesLevel()) + ". It is producing " + IntToString(Gameplay->GetCoinsRate() * 3600) + " coins per hour. Do you want to upgrade your Houses? " + MakeCostString(Gameplay->GetHasHouses(), "Houses", Gameplay->GameCosts->HousesCosts[Gameplay->GetHasHouses() + Gameplay->GetHousesLevel()]);
	}
	else
	{
		partone = partone + "You don't have Houses yet. ";
	}

	WMessageBox *messageBox = new WMessageBox
	("Houses",
	 partone,
	 Wt::Information, Wt::Yes | Wt::No);

	messageBox->setModal(true);

	messageBox->show();

    messageBox->buttonClicked().connect(std::bind([=] () {
		if (messageBox->buttonResult() == Wt::Yes)
		{
			BuyHouses();
			delete messageBox;
		}
		else
		{
			delete messageBox;
		}
	}));
}

void TownWidget::QuarryClicked()
{
	std::string partone = "";

	if (Gameplay->GetHasQuarry())
	{
		partone = partone + "You have a Quarry Lv" + IntToString(Gameplay->GetQuarryLevel()) + ". It is producing " + IntToString(Gameplay->GetStoneRate() * 3600) + " stone per hour. Do you want to upgrade your Quarry? " + MakeCostString(Gameplay->GetHasQuarry(), "Quarry", Gameplay->GameCosts->QuarryCosts[Gameplay->GetHasQuarry() + Gameplay->GetQuarryLevel()]);
	}
	else
	{
		partone = partone + "You don't have Quarry yet. Do you want to build one? " + MakeCostString(Gameplay->GetHasQuarry(), "Quarry", Gameplay->GameCosts->QuarryCosts[Gameplay->GetHasQuarry() + Gameplay->GetQuarryLevel()]);
	}

	WMessageBox *messageBox = new WMessageBox
	("Quarry",
	 partone,
	 Wt::Information, Wt::Yes | Wt::No);

	messageBox->setModal(true);

	messageBox->show();

    messageBox->buttonClicked().connect(std::bind([=] () {
		if (messageBox->buttonResult() == Wt::Yes)
		{
			BuyQuarry();
			delete messageBox;
		}
		else
		{
			delete messageBox;
		}
	}));
}

void TownWidget::MinesClicked()
{
	std::string partone = "";

	if (Gameplay->GetHasMines())
	{
		partone = partone + "You have a Mines Lv" + IntToString(Gameplay->GetMinesLevel()) + ". It is producing " + IntToString(Gameplay->GetSteelRate() * 3600) + " steel per hour. Do you want to upgrade your Mines? " + MakeCostString(Gameplay->GetHasMines(), "Mines", Gameplay->GameCosts->MinesCosts[Gameplay->GetHasMines() + Gameplay->GetMinesLevel()]);
	}
	else
	{
		partone = partone + "You don't have Mines yet. Do you want to build one? " + MakeCostString(Gameplay->GetHasMines(), "Quarry", Gameplay->GameCosts->MinesCosts[Gameplay->GetHasMines() + Gameplay->GetMinesLevel()]);
	}

	WMessageBox *messageBox = new WMessageBox
	("Mines",
	 partone,
	 Wt::Information, Wt::Yes | Wt::No);

	messageBox->setModal(true);

	messageBox->show();

    messageBox->buttonClicked().connect(std::bind([=] () {
		if (messageBox->buttonResult() == Wt::Yes)
		{
			BuyMines();
			delete messageBox;
		}
		else
		{
			delete messageBox;
		}
	}));
}

void TownWidget::MagicCrystalClicked()
{
	std::string partone = "";

	if (Gameplay->GetHasMagicCrystal())
	{
		partone = partone + "You have a Magic Crystal Lv" + IntToString(Gameplay->GetMagicCrystalLevel()) + ". It is producing " + IntToString(Gameplay->GetManaRate() * 3600) + " mana per hour. Do you want to upgrade your Magic Crystal? " + MakeCostString(Gameplay->GetHasMagicCrystal(), "Magic Crystal", Gameplay->GameCosts->MagicCrystalCosts[Gameplay->GetHasMagicCrystal() + Gameplay->GetMagicCrystalLevel()]);
	}
	else
	{
		partone = partone + "You don't have a Magic Crystal yet. Do you want to build one? " + MakeCostString(Gameplay->GetHasMagicCrystal(), "Magic Crystal", Gameplay->GameCosts->MagicCrystalCosts[Gameplay->GetHasMagicCrystal() + Gameplay->GetMagicCrystalLevel()]);
	}

	WMessageBox *messageBox = new WMessageBox
	("Magic Crystal",
	 partone,
	 Wt::Information, Wt::Yes | Wt::No);

	messageBox->setModal(true);

	messageBox->show();

    messageBox->buttonClicked().connect(std::bind([=] () {
		if (messageBox->buttonResult() == Wt::Yes)
		{
			BuyMagicCrystal();
			delete messageBox;
		}
		else
		{
			delete messageBox;
		}
	}));
}

void TownWidget::BarracksClicked()
{
	std::string partone = "";

	if (Gameplay->GetHasBarracks())
	{
		partone = partone + "You have a Barracks Lv" + IntToString(Gameplay->GetBarracksLevel()) + ". Do you want to upgrade your Barracks? " + MakeCostString(Gameplay->GetHasBarracks(), "Barracks", Gameplay->GameCosts->BarracksCosts[Gameplay->GetHasBarracks() + Gameplay->GetBarracksLevel()]);
	}
	else
	{
		partone = partone + "You don't have a Barracks yet. Do you want to build one? " + MakeCostString(Gameplay->GetHasBarracks(), "Barracks", Gameplay->GameCosts->BarracksCosts[Gameplay->GetHasBarracks() + Gameplay->GetBarracksLevel()]);
	}
	if (Gameplay->GetHasBarracks())
	{
		WMessageBox *messageBox = new WMessageBox
		("Barracks",
		 "Do you want to go to the Barracks interface? Press Yes to go to the barracks screen or No to access the build screen.",
		 Wt::Information, Wt::Yes | Wt::No);

		messageBox->setModal(true);

		messageBox->show();

		messageBox->buttonClicked().connect(std::bind([=] () {
			if (messageBox->buttonResult() == Wt::Yes)
			{
				delete messageBox;
				GoToBarracksClicked();
			}
			else
			{
				delete messageBox;
					WMessageBox *messageBox = new WMessageBox
					("Barracks",
					 partone,
					 Wt::Information, Wt::Yes | Wt::No);

					messageBox->setModal(true);

					messageBox->show();

					messageBox->buttonClicked().connect(std::bind([=] () {
						if (messageBox->buttonResult() == Wt::Yes)
						{
							BuyBarracks();
							delete messageBox;
						}
						else
						{
							delete messageBox;
						}
					}));
			}
		}));
	}
	else
	{
		WMessageBox *messageBox = new WMessageBox
					("Barracks",
					 partone,
					 Wt::Information, Wt::Yes | Wt::No);

					messageBox->setModal(true);

					messageBox->show();

					messageBox->buttonClicked().connect(std::bind([=] () {
						if (messageBox->buttonResult() == Wt::Yes)
						{
							BuyBarracks();
							delete messageBox;
						}
						else
						{
							delete messageBox;
						}
					}));
	}
}

void TownWidget::RallyingPointClicked()
{
	std::string partone = "";

	if (Gameplay->GetHasRallyingPoint())
	{
		partone = partone + "You have a Rallying Point Lv" + IntToString(Gameplay->GetRallyingPointLevel()) + ". Do you want to upgrade your Rallying Point? " + MakeCostString(Gameplay->GetHasRallyingPoint(), "Rallying Point", Gameplay->GameCosts->RallyingPointCosts[Gameplay->GetHasRallyingPoint() + Gameplay->GetRallyingPointLevel()]);
	}
	else
	{
		partone = partone + "You don't have a Rallying Point yet. Do you want to build one? " + MakeCostString(Gameplay->GetHasRallyingPoint(), "Rallying Point", Gameplay->GameCosts->RallyingPointCosts[Gameplay->GetHasRallyingPoint() + Gameplay->GetRallyingPointLevel()]);
	}
	if (Gameplay->GetHasRallyingPoint())
	{
		WMessageBox *messageBox = new WMessageBox
		("Rallying Point",
		 "This is your Rallying Point. You can send attacks and choose combat strategies here.",
		 Wt::Information, Wt::Cancel);

		messageBox->setModal(true);

		messageBox->show();

		messageBox->buttonClicked().connect(std::bind([=] () {
			if (messageBox->buttonResult() == Wt::Cancel)
			{
				delete messageBox;
			}
			else
			{
				delete messageBox;
			}
		}));
	}
	else
	{
		WMessageBox *messageBox = new WMessageBox
					("RallyingPoint",
					 partone,
					 Wt::Information, Wt::Yes | Wt::No);

					messageBox->setModal(true);

					messageBox->show();

					messageBox->buttonClicked().connect(std::bind([=] () {
						if (messageBox->buttonResult() == Wt::Yes)
						{
							BuyRallyingPoint();
							delete messageBox;
						}
						else
						{
							delete messageBox;
						}
					}));
	}
}

void TownWidget::BuyLumbermill()
{
	if (Gameplay->AttemptPurchase(0))
	{
		BuildingRects[0]->setToolTip("Lumbermill Lv" + IntToString(Gameplay->GetLumbermillLevel()));
		this->update();
	}
}

void TownWidget::BuyHouses()
{
	if (Gameplay->AttemptPurchase(1))
	{
		BuildingRects[1]->setToolTip("Houses Lv" + IntToString(Gameplay->GetHousesLevel()));
		this->update();
	}
}

void TownWidget::BuyQuarry()
{
	if (Gameplay->AttemptPurchase(2))
	{
		BuildingRects[2]->setToolTip("Quarry Lv" + IntToString(Gameplay->GetQuarryLevel()));
		this->update();
	}
}

void TownWidget::BuyMines()
{
	if (Gameplay->AttemptPurchase(3))
	{
		BuildingRects[3]->setToolTip("Mines Lv" + IntToString(Gameplay->GetMinesLevel()));
		this->update();
	}
}

void TownWidget::BuyMagicCrystal()
{
	if (Gameplay->AttemptPurchase(4))
	{
		BuildingRects[4]->setToolTip("Magic Crystal Lv" + IntToString(Gameplay->GetMagicCrystalLevel()));
		this->update();
	}
}

void TownWidget::BuyBarracks()
{
	if (Gameplay->AttemptPurchase(5))
	{
		BuildingRects[5]->setToolTip("Barracks Lv" + IntToString(Gameplay->GetBarracksLevel()));
		this->update();
	}
}

void TownWidget::BuyRallyingPoint()
{
	if (Gameplay->AttemptPurchase(6))
	{
		BuildingRects[6]->setToolTip("Rallying Point Lv" + IntToString(Gameplay->GetRallyingPointLevel()));
		this->update();
	}
}

void TownWidget::BuyAcademy()
{
	if (Gameplay->AttemptPurchase(0))
	{
		BuildingRects[7]->setToolTip("Academy Lv" + IntToString(Gameplay->GetAcademyLevel()));
		this->update();
	}
}

void TownWidget::GoToBarracksClicked()
{
	GameMenuWidget->BarracksPressed();
}

void TownWidget::SingleBreak()
{
//	new WBreak(this);
}

void TownWidget::DoubleBreak()
{
//	new WBreak(this);
//	new WBreak(this);
}

std::string TownWidget::MakeCostString(bool hasbuilding, std::string buildingname, TotalCost* cost)
{
	std::string CostString;

	CostString = "It will cost: ";

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