#include "MapWidget.h"

using namespace Wt;
MapWidget::MapWidget(WLink imagelink, SideBarWidget* gamemenuwidget, WContainerWidget *parent)
    : WContainerWidget(parent)
{
	GameMenuWidget = gamemenuwidget;

	setContentAlignment(AlignCenter);

	Map_Style = WCssDecorationStyle();
	Map_Style.setBackgroundColor(WColor(245, 255, 180));

	setDecorationStyle(Map_Style);

	Map_Image = new WImage(imagelink, this);
	Map_Image->setMargin(5, Top);

	short int MapCoordType [8][8] = {
	{PLAINS, PLAINS, FOREST, FOREST, PLAINS, PLATEAU, LAKE, LAKE},
	{MOUNTAINS, MOUNTAINS, MOUNTAINS, PLAINS, HILLS, LAKE, LAKE, LAKE},
	{PLAINS, MOUNTAINS, MOUNTAINS, MOUNTAINS, PLAINS, LAKE, LAKE, PLAINS},
	{FOREST, FOREST, ENEMYTOWN, HILLS, PLAINS, PLAINS, PLAINS, PLAINS},
	{PLAINS, LAKE, LAKE, LAKE, PLAINS, FOREST, FOREST, PLAINS},
	{PLAINS, LAKE, LAKE, LAKE, PLAINS, PLAINS, PLAYERTOWN, PLAINS},
	{PLAINS, PLAINS, LAKE, LAKE, PLAINS, HILLS, PLAINS, MOUNTAINS},
	{PLAINS, HILLS, PLATEAU, PLAINS, PLAINS, MOUNTAINS, MOUNTAINS, MOUNTAINS}};

	WRectArea* MapCoords[8][8];
	std::string MapCoordNames [8][8];				//The tooltop descriptions for the individual tiles

	std::string PlainsString = "Plains";
	std::string MountainsString = "Mountains";
	std::string HillsString = "Hills";
	std::string LakeString = "Lake";
	std::string PlateauString = "Plateau";
	std::string ForestString = "Forest";
	std::string PlayerTownString = "Your Town";
	std::string EnemyTownString = "The Enemy's Town";

	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			if (MapCoordType[i][j] == PLAINS)
			{
				MapCoordNames[i][j] = PlainsString;
			}
			else if (MapCoordType[i][j] == MOUNTAINS)
			{
				MapCoordNames[i][j] = MountainsString;
			}
			else if (MapCoordType[i][j] == HILLS)
			{
				MapCoordNames[i][j] = HillsString;
			}
			else if (MapCoordType[i][j] == LAKE)
			{
				MapCoordNames[i][j] = LakeString;
			}
			else if (MapCoordType[i][j] == PLATEAU)
			{
				MapCoordNames[i][j] = PlateauString;
			}
			else if (MapCoordType[i][j] == FOREST)
			{
				MapCoordNames[i][j] = ForestString;
			}
			else if (MapCoordType[i][j] == ENEMYTOWN)
			{
				MapCoordNames[i][j] = EnemyTownString;
			}
			else if (MapCoordType[i][j] == PLAYERTOWN)
			{
				MapCoordNames[i][j] = PlayerTownString;
			}
		}
	}

	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			std::string temp = "(" + IntToString(1 + j) + ", " + IntToString(8 - i) + ") " + MapCoordNames[i][j];

			MapCoords[i][j] = new WRectArea((21 + (72 * j)), (2 + (72 * i)), 71, 71);
			MapCoords[i][j]->setToolTip(temp);
		}
	}

	MapCoords[3][2]->setCursor(PointingHandCursor);
	MapCoords[5][6]->setCursor(PointingHandCursor);

	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			Map_Image->addArea(MapCoords[i][j]);
		}
	}

	MapCoords[3][2]->mouseWentDown().connect(this, &MapWidget::EnemyTownMessageBox);
	MapCoords[5][6]->mouseWentDown().connect(this, &MapWidget::PlayerTownMessageBox);
}

void MapWidget::PlayerTownMessageBox()
{
	GameMenuWidget->TownPressed();
}

void MapWidget::EnemyTownMessageBox()
{
	WMessageBox *messageBox = new WMessageBox
	("This is the enemy's town.",
	 "Here you will be able to check on how they are doing and declare attacks.",
	 Wt::Information, Wt::Cancel);

	messageBox->setModal(true);

	messageBox->show();

    messageBox->buttonClicked().connect(std::bind([=] () {

	delete messageBox;    }));
}