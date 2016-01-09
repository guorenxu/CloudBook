#include "SideBarWidget.h"

using namespace Wt;

SideBarWidget::SideBarWidget(const std::string &name, WContainerWidget *parent)
    : WContainerWidget(parent),
	Menu_State_Signal_(this)
{
	Side_Bar_State = 0;

	setContentAlignment(AlignLeft);

	setWidth(130);

	setMinimumSize(130, 800);
	setMaximumSize(130, 800);

	Menu_Style = WCssDecorationStyle();
	Menu_Style.setBackgroundColor(WColor(230, 255, 255));

	setDecorationStyle(Menu_Style);

	Button_Style = WCssDecorationStyle();
	Button_Style.setCursor(PointingHandCursor);

	Map_Button = new WImage(Wt::WLink("resources/MapButtonBase.png"), this);
	Map_Button->setDecorationStyle(Button_Style);
	Map_Button->setMargin(5, Top);
	Map_Button->setMargin(5, Left);
	Map_Button->setToolTip("Open the map");
	//Map_Text = new WText(this);
	//Map_Text->setText("Open the map!");

	DoubleBreak();

	Mail_Button = new WImage(Wt::WLink("resources/MailButtonMO.png"), this);
	Mail_Button->setDecorationStyle(Button_Style);
	Mail_Button->setMargin(5, Left);
	Mail_Button->setToolTip("Open the mailbox");
	//Mail_Text = new WText(this);
	//Mail_Text->setText("Open the mailbox!");

	DoubleBreak();

	Reports_Button = new WImage(Wt::WLink("resources/ReportsButtonMO.png"), this);
	Reports_Button->setDecorationStyle(Button_Style);
	Reports_Button->setMargin(5, Left);
	Reports_Button->setToolTip("Open reports");
	//Reports_Text = new WText(this);
	//Reports_Text->setText("Open the reports window!");

	DoubleBreak();

	Settings_Button = new WImage(Wt::WLink("resources/SettingsButtonMO.png"), this);
	Settings_Button->setDecorationStyle(Button_Style);
	Settings_Button->setMargin(5, Left);
	Settings_Button->setToolTip("Open the settings");
	//Settings_Text = new WText(this);
	//Settings_Text->setText("Open the settings window!");

	DoubleBreak();

	Help_Button = new WImage(Wt::WLink("resources/HelpButtonMO.png"), this);
	Help_Button->setDecorationStyle(Button_Style);
	Help_Button->setMargin(5, Left);
	Help_Button->setToolTip("I need help!");
	//Help_Text = new WText(this);
	//Help_Text->setText("Open the help window!");

	DoubleBreak();

	Map_Button->mouseWentDown().connect(this, &SideBarWidget::Map_Pressed);
	Mail_Button->mouseWentDown().connect(this, &SideBarWidget::Mail_Pressed);
	Reports_Button->mouseWentDown().connect(this, &SideBarWidget::Reports_Pressed);
	Settings_Button->mouseWentDown().connect(this, &SideBarWidget::Settings_Pressed);
	Help_Button->mouseWentDown().connect(this, &SideBarWidget::Help_Pressed);

	Map_Button->mouseWentUp().connect(this, &SideBarWidget::Map_Unpressed);
	Mail_Button->mouseWentUp().connect(this, &SideBarWidget::Mail_Unpressed);
	Reports_Button->mouseWentUp().connect(this, &SideBarWidget::Reports_Unpressed);
	Settings_Button->mouseWentUp().connect(this, &SideBarWidget::Settings_Unpressed);
	Help_Button->mouseWentUp().connect(this, &SideBarWidget::Help_Unpressed);

	Map_Button->mouseWentOver().connect(this, &SideBarWidget::Map_Mouseover);
	Mail_Button->mouseWentOver().connect(this, &SideBarWidget::Mail_Mouseover);
	Reports_Button->mouseWentOver().connect(this, &SideBarWidget::Reports_Mouseover);
	Settings_Button->mouseWentOver().connect(this, &SideBarWidget::Settings_Mouseover);
	Help_Button->mouseWentOver().connect(this, &SideBarWidget::Help_Mouseover);

	Map_Button->mouseWentOut().connect(this, &SideBarWidget::Map_Mouseout);
	Mail_Button->mouseWentOut().connect(this, &SideBarWidget::Mail_Mouseout);
	Reports_Button->mouseWentOut().connect(this, &SideBarWidget::Reports_Mouseout);
	Settings_Button->mouseWentOut().connect(this, &SideBarWidget::Settings_Mouseout);
	Help_Button->mouseWentOut().connect(this, &SideBarWidget::Help_Mouseout);
}

void SideBarWidget::Map_Pressed(const Wt::WMouseEvent& event)
{
	if( event.button() == WMouseEvent::LeftButton )
	{
		Side_Bar_State = Map;

		Active_Check();

		Map_Button->setImageLink("resources/MapButtonClicked.png");

		Menu_State_Signal_.emit(Side_Bar_State);
	}
}

void SideBarWidget::Mail_Pressed(const Wt::WMouseEvent& event)
{
	if( event.button() == WMouseEvent::LeftButton )
	{
		Side_Bar_State = Mailbox;

		Active_Check();

		Mail_Button->setImageLink("resources/MailButtonClicked.png");

		Menu_State_Signal_.emit(Side_Bar_State);
	}
}

void SideBarWidget::Reports_Pressed(const Wt::WMouseEvent& event)
{
	if( event.button() == WMouseEvent::LeftButton )
	{
		Side_Bar_State = Reports;

		Active_Check();

		Reports_Button->setImageLink("resources/ReportsButtonClicked.png");

		Menu_State_Signal_.emit(Side_Bar_State);
	}
}

void SideBarWidget::Settings_Pressed(const Wt::WMouseEvent& event)
{
	if( event.button() == WMouseEvent::LeftButton )
	{
		Side_Bar_State = Settings;

		Active_Check();

		Settings_Button->setImageLink("resources/SettingsButtonClicked.png");

		Menu_State_Signal_.emit(Side_Bar_State);
	}
}

void SideBarWidget::Help_Pressed(const Wt::WMouseEvent& event)
{
	if( event.button() == WMouseEvent::LeftButton )
	{
		Side_Bar_State = Help;

		Active_Check();

		Help_Button->setImageLink("resources/HelpButtonClicked.png");

		Menu_State_Signal_.emit(Side_Bar_State);
	}
}

void SideBarWidget::Map_Unpressed()
{
	Map_Button->setImageLink("resources/MapButtonBase.png");
}

void SideBarWidget::Mail_Unpressed()
{
	Mail_Button->setImageLink("resources/MailButtonBase.png");
}

void SideBarWidget::Reports_Unpressed()
{
	Reports_Button->setImageLink("resources/ReportsButtonBase.png");
}

void SideBarWidget::Settings_Unpressed()
{
	Settings_Button->setImageLink("resources/SettingsButtonBase.png");
}

void SideBarWidget::Help_Unpressed()
{
	Help_Button->setImageLink("resources/HelpButtonBase.png");
}

void SideBarWidget::SingleBreak()
{
	new WBreak(this);
}

void SideBarWidget::DoubleBreak()
{
	new WBreak(this);
	new WBreak(this);
}

void SideBarWidget::Map_Mouseover()
{
	Map_Button->setImageLink("resources/MapButtonBase.png");
}

void SideBarWidget::Mail_Mouseover()
{
	Mail_Button->setImageLink("resources/MailButtonBase.png");
}

void SideBarWidget::Reports_Mouseover()
{
	Reports_Button->setImageLink("resources/ReportsButtonBase.png");
}

void SideBarWidget::Settings_Mouseover()
{
	Settings_Button->setImageLink("resources/SettingsButtonBase.png");
}

void SideBarWidget::Help_Mouseover()
{
	Help_Button->setImageLink("resources/HelpButtonBase.png");
}

void SideBarWidget::Map_Mouseout()
{
	if (Side_Bar_State == Map)
	{
		Map_Button->setImageLink("resources/MapButtonBase.png");
	}
	else
	{
		Map_Button->setImageLink("resources/MapButtonMO.png");
	}
}

void SideBarWidget::Mail_Mouseout()
{
	if (Side_Bar_State == Mailbox)
	{
		Mail_Button->setImageLink("resources/MailButtonBase.png");
	}
	else
	{
		Mail_Button->setImageLink("resources/MailButtonMO.png");
	}
}

void SideBarWidget::Reports_Mouseout()
{
	if (Side_Bar_State == Reports)
	{
		Reports_Button->setImageLink("resources/ReportsButtonBase.png");
	}
	else
	{
		Reports_Button->setImageLink("resources/ReportsButtonMO.png");
	}
}

void SideBarWidget::Settings_Mouseout()
{
	if (Side_Bar_State == Settings)
	{
		Settings_Button->setImageLink("resources/SettingsButtonBase.png");
	}
	else
	{
		Settings_Button->setImageLink("resources/SettingsButtonMO.png");
	}
}

void SideBarWidget::Help_Mouseout()
{
	if (Side_Bar_State == Help)
	{
		Help_Button->setImageLink("resources/HelpButtonBase.png");
	}
	else
	{
		Help_Button->setImageLink("resources/HelpButtonMO.png");
	}
}

void SideBarWidget::TownPressed()
{
	Side_Bar_State = Town;

	Active_Check();

	Menu_State_Signal_.emit(Side_Bar_State);
}

void SideBarWidget::BarracksPressed()
{
	Side_Bar_State = Barracks;

	Active_Check();

	Menu_State_Signal_.emit(Side_Bar_State);
}

void SideBarWidget::Active_Check()
{
	Map_Mouseout();
	Mail_Mouseout();
	Reports_Mouseout();
	Settings_Mouseout();
	Help_Mouseout();
}
