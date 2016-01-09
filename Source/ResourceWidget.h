#ifndef _RESOURCEWIDGET_H
#define _RESOURCEWIDGET_H 1

#include "Util.h"
#include "SingleResourceWidget.h"
#include "TimeWidget.h"
#include "GameLogic.h"

using namespace Wt;

class ResourceWidget : public Wt::WContainerWidget
{
public:
    ResourceWidget(GameLogic* gamelogic, long int start, Wt::WContainerWidget *parent = 0);

	void Update();									//Updates the player's resources using application run time

    //Wt::Signal<int>& scoreUpdated() { return scoreUpdated_; }

private:
	GameLogic* Gameplay;

	WPushButton *Wood_Button;
	WPushButton *Coins_Button;

	WCssDecorationStyle Resource_Style;

	SingleResourceWidget* WoodResourceWidget;
	SingleResourceWidget* CoinsResourceWidget;
	SingleResourceWidget* StoneResourceWidget;
	SingleResourceWidget* SteelResourceWidget;
	SingleResourceWidget* FavorResourceWidget;

	TimeWidget* GameTimeWidget;

	void SingleBreak();
	void DoubleBreak();

	void PassMinute();
	void PassHour();

	long int TimePassed(long int start);
};

#endif