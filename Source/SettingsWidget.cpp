#include "SettingsWidget.h"

using namespace Wt;

SettingsWidget::SettingsWidget(GameLogic* gamelogic, Wt::WContainerWidget *parent)
    : WPaintedWidget(parent)
{
	//setContentAlignment(AlignCenter);

	Gameplay = gamelogic;

	resize(639, 1310);  // Provide a default size.

	WRectArea* LumbermillCoords = new WRectArea(0, 0, 60, 60);
	LumbermillCoords->setCursor(PointingHandCursor);

	this->addArea(LumbermillCoords);

	//SettingsStyle = WCssDecorationStyle();
	//SettingsStyle.setBackgroundColor(WColor(255, 195, 190));

	//setDecorationStyle(SettingsStyle);

	//TimeControlText = new WText("Here you can control how fast time passes :", this);

	//DoubleBreak();

	//NormalSpeedButton = new WPushButton("Normal Speed", this);
	//DoubleBreak();

	//TenTimesSpeedButton = new WPushButton("10x Speed", this);
	//DoubleBreak();

	//OneHundredTimesSpeedButton = new WPushButton("100x Speed", this);
	//DoubleBreak();

	//NormalSpeedButton->clicked().connect(this, &SettingsWidget::NormalSpeedPressed);
	//TenTimesSpeedButton->clicked().connect(this, &SettingsWidget::TenTimesSpeedPressed);
	//OneHundredTimesSpeedButton->clicked().connect(this, &SettingsWidget::OneHundredTimesSpeedPressed);
}

void SettingsWidget::paintEvent(Wt::WPaintDevice *paintDevice) 
{
	Wt::WPainter painter(paintDevice);

	Wt::WPainter::Image image("resources/townbase.png", 639, 354);
	painter.drawImage(0.0, 0.0, image);
}

void SettingsWidget::NormalSpeedPressed()
{
}

void SettingsWidget::TenTimesSpeedPressed()
{
}

void SettingsWidget::OneHundredTimesSpeedPressed()
{
}

void SettingsWidget::SingleBreak()
{
//	new WBreak(this);
}

void SettingsWidget::DoubleBreak()
{
//	new WBreak(this);
//	new WBreak(this);
}