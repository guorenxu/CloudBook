#ifndef _SETTINGSWIDGET_H
#define _SETTINGSWIDGET_H 1

#include "Util.h"
#include "GameLogic.h"

using namespace Wt;

class SettingsWidget : public WPaintedWidget
{
public:
    SettingsWidget(GameLogic* gamelogic, Wt::WContainerWidget *parent = 0);

	void paintEvent(Wt::WPaintDevice *paintDevice);

private:
	GameLogic* Gameplay;

	WText* TimeControlText;
	WPushButton *NormalSpeedButton;
	WPushButton *TenTimesSpeedButton;
	WPushButton *OneHundredTimesSpeedButton;

	WCssDecorationStyle SettingsStyle;

	void SingleBreak();
	void DoubleBreak();

	void NormalSpeedPressed();
	void TenTimesSpeedPressed();
	void OneHundredTimesSpeedPressed();
};

#endif