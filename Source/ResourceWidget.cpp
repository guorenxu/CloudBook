#include "ResourceWidget.h"

using namespace Wt;

ResourceWidget::ResourceWidget(GameLogic* gamelogic, long int start, WContainerWidget *parent)
    : WContainerWidget(parent)
{
	setContentAlignment(AlignCenter);

	Resource_Style = WCssDecorationStyle();
	Resource_Style.setBackgroundColor(WColor(255, 230, 255));

	setDecorationStyle(Resource_Style);

	Gameplay = gamelogic;

	WoodResourceWidget = new SingleResourceWidget("Wood", "resources/WoodResourcePng.png", this);
	CoinsResourceWidget = new SingleResourceWidget("Coins", "resources/CoinsResourcePng.png", this);
	StoneResourceWidget = new SingleResourceWidget("Stone", "resources/StoneResourcePng.png", this);
	SteelResourceWidget = new SingleResourceWidget("Steel", "resources/SteelResourcePng.png", this);
	FavorResourceWidget = new SingleResourceWidget("Mana", "resources/FavorResourcePng.png", this);

	GameTimeWidget = new TimeWidget(this);

	Wood_Button	= new WPushButton("Pass One Minute", this);               // create a button
	Wood_Button->setMargin(0, Left); 

	Coins_Button = new WPushButton("Pass One Hour", this);               // create a button
	Coins_Button->setMargin(0, Left);

	WVBoxLayout *vbox = new WVBoxLayout();
	this->setLayout(vbox);

	//vbox->addWidget(new WText("Total Time Passed: "));  // show some text
	vbox->addWidget(GameTimeWidget); 

	WHBoxLayout *hbox = new WHBoxLayout();
	vbox->addLayout(hbox);

	hbox->addWidget(WoodResourceWidget);
	hbox->addWidget(CoinsResourceWidget);
	hbox->addWidget(StoneResourceWidget);
	hbox->addWidget(SteelResourceWidget);
	hbox->addWidget(FavorResourceWidget);

	vbox->addWidget(new WBreak());

	vbox->addWidget(Wood_Button); 
	vbox->addWidget(Coins_Button); 

	Wood_Button->clicked().connect(this, &ResourceWidget::PassMinute);
	Coins_Button->clicked().connect(this, &ResourceWidget::PassHour);
}

void ResourceWidget::SingleBreak()
{
	new WBreak(this);
}

void ResourceWidget::DoubleBreak()
{
	new WBreak(this);
	new WBreak(this);
}

void ResourceWidget::Update()
{
	GameTimeWidget->SetTime(Gameplay->GetGameTimeInSeconds());

	WoodResourceWidget->SetResourceCount(Gameplay->GetWoodCount());
	CoinsResourceWidget->SetResourceCount(Gameplay->GetCoinsCount());
	StoneResourceWidget->SetResourceCount(Gameplay->GetStoneCount());
	SteelResourceWidget->SetResourceCount(Gameplay->GetSteelCount());
	FavorResourceWidget->SetResourceCount(Gameplay->GetManaCount());
}

void ResourceWidget::PassMinute()
{
	Gameplay->PassMinute();
}
	
	
void ResourceWidget::PassHour()
{
	Gameplay->PassHour();
}
