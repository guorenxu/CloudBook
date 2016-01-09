#ifndef _SIDEBARWIDGET_H
#define _SIDEBARWIDGET_H 1

#include "Util.h"

using namespace Wt;

enum SideBarStates
{
	Map = 0, 
	Mailbox = 1, 
	Reports = 2,
	Settings = 3,
	Help = 4,
	Town = 5,
	Barracks = 6
};

class SideBarWidget : public Wt::WContainerWidget
{
public:
    SideBarWidget(const std::string &name, Wt::WContainerWidget *parent = 0);

	short int Side_Bar_State;

	void TownPressed();		//Town Pressed by map widget

	void BarracksPressed();	//Barracks pressed by town widget

    Signal<short int>& Menu_State_Signal() { return Menu_State_Signal_; }

private:
	Signal<short int> Menu_State_Signal_;

	WCssDecorationStyle Menu_Style;
	WCssDecorationStyle Button_Style;

	WText* Map_Text;
	WText* Mail_Text;
	WText* Reports_Text;
	WText* Settings_Text;
	WText* Help_Text;

	WImage *Map_Button;
	WImage *Mail_Button;
	WImage *Reports_Button;
	WImage *Settings_Button;
	WImage *Help_Button;

	void Map_Pressed(const Wt::WMouseEvent& event);
	void Mail_Pressed(const Wt::WMouseEvent& event);
	void Reports_Pressed(const Wt::WMouseEvent& event);
	void Settings_Pressed(const Wt::WMouseEvent& event);
	void Help_Pressed(const Wt::WMouseEvent& event);

	void Map_Unpressed();
	void Mail_Unpressed();
	void Reports_Unpressed();
	void Settings_Unpressed();
	void Help_Unpressed();

	void Map_Mouseover();
	void Mail_Mouseover();
	void Reports_Mouseover();
	void Settings_Mouseover();
	void Help_Mouseover();

	void Map_Mouseout();
	void Mail_Mouseout();
	void Reports_Mouseout();
	void Settings_Mouseout();
	void Help_Mouseout();

	void Active_Check();

	void SingleBreak();
	void DoubleBreak();
};

#endif