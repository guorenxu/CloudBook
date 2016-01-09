#ifndef _MAPWIDGET_H
#define _MAPWIDGET_H 1

#include "Util.h"
#include "SideBarWidget.h"

using namespace Wt;

enum MapCoordTypes
{
	PLAINS = 0, 
	MOUNTAINS = 1, 
	LAKE = 2,
	PLATEAU = 3,
	HILLS = 4,
	FOREST = 5,
	PLAYERTOWN = 6,
	ENEMYTOWN = 7
};

class MapWidget : public WContainerWidget
{
public:
    MapWidget(WLink imagelink, SideBarWidget* gamemenuwidget, WContainerWidget *parent = 0);

private:

	WImage *Map_Image;

	SideBarWidget* GameMenuWidget;

	WCssDecorationStyle Map_Style;

	void PlayerTownMessageBox();
	void EnemyTownMessageBox();
};

#endif