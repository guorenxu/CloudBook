#ifndef _MULTIWIDGET_H
#define _MULTIWIDGET_H 1

#include "Util.h"
#include "MapWidget.h"
#include "TownWidget.h"
#include "BarracksWidget.h"
#include "SettingsWidget.h"

using namespace Wt;

class MultiWidget : public Wt::WContainerWidget
{
public:
    MultiWidget(GameLogic* gamelogic, SideBarWidget* gamemenuwidget, Wt::WContainerWidget *parent = 0);

	void Set_Multi_State(short int game_menu_state);

private:
	MapWidget* GameMapWidget;

	TownWidget* PlayerTownWidget;

	BarracksWidget* PlayerBarracksWidget;

	SideBarWidget* GameMenuWidget;

	SettingsWidget* GameSettingsWidget;

	WText* Test_Text;

	WCssDecorationStyle Map_Style;

	void SingleBreak();
	void DoubleBreak();
};

#endif