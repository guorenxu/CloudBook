#include "MultiWidget.h"
#include "SideBarWidget.h"

using namespace Wt;

MultiWidget::MultiWidget(GameLogic* gamelogic, SideBarWidget* gamemenuwidget, WContainerWidget *parent)
    : WContainerWidget(parent)
{
	setContentAlignment(AlignCenter);

	setWidth(1730);

	GameMenuWidget = gamemenuwidget;

	GameMapWidget = new MapWidget("resources/MapF.png", GameMenuWidget, this);
	PlayerTownWidget = new TownWidget(gamelogic, GameMenuWidget, this);
	PlayerBarracksWidget = new BarracksWidget(gamelogic, GameMenuWidget, this);
	GameSettingsWidget = new SettingsWidget(gamelogic, this);

	Map_Style = WCssDecorationStyle();
	Map_Style.setBackgroundColor(WColor(255, 255, 230));

	setDecorationStyle(Map_Style);

	Test_Text = new WText(this);
	Test_Text->setText("Map is here");
	this->removeWidget(Test_Text);
	this->removeWidget(PlayerTownWidget);
	this->removeWidget(PlayerBarracksWidget);
	this->removeWidget(GameSettingsWidget);
}

void MultiWidget::SingleBreak()
{
	new WBreak(this);
}

void MultiWidget::DoubleBreak()
{
	new WBreak(this);
	new WBreak(this);
}

void MultiWidget::Set_Multi_State(short int game_menu_state)
{
	switch (game_menu_state) 
	{
		case Map:
			this->removeWidget(Test_Text);
			this->removeWidget(PlayerTownWidget);
			this->removeWidget(PlayerBarracksWidget);
			this->removeWidget(GameSettingsWidget);
			this->addWidget(GameMapWidget);
			break;

		case Mailbox:
			this->addWidget(Test_Text);
			Test_Text->setText("Mailbox is here");
			this->removeWidget(GameMapWidget);
			this->removeWidget(PlayerTownWidget);
			this->removeWidget(PlayerBarracksWidget);
			this->removeWidget(GameSettingsWidget);
			break;

		case Reports:
			this->addWidget(Test_Text);
			Test_Text->setText("Reports is here");
			this->removeWidget(GameMapWidget);
			this->removeWidget(PlayerTownWidget);
			this->removeWidget(PlayerBarracksWidget);
			this->removeWidget(GameSettingsWidget);
			break;

		case Settings:
			this->removeWidget(Test_Text);
			this->addWidget(GameSettingsWidget);
			this->removeWidget(GameMapWidget);
			this->removeWidget(PlayerTownWidget);
			this->removeWidget(PlayerBarracksWidget);
			break;

		case Help:
			this->addWidget(Test_Text);
			Test_Text->setText("Help is here");
			this->removeWidget(GameMapWidget);
			this->removeWidget(PlayerTownWidget);
			this->removeWidget(PlayerBarracksWidget);
			this->removeWidget(GameSettingsWidget);
			break;

		case Town:
			this->addWidget(PlayerTownWidget);
			this->removeWidget(GameMapWidget);
			this->removeWidget(PlayerBarracksWidget);
			break;

		case Barracks:
			this->addWidget(PlayerBarracksWidget);
			this->removeWidget(PlayerTownWidget);
			this->removeWidget(GameMapWidget);
			break;

		default:
		  // Code
		  break;
	}
}