#include "TimeWidget.h"

using namespace Wt;

TimeWidget::TimeWidget(WContainerWidget *parent)
    : WContainerWidget(parent)
{
	Displayed_Time = 0;

	setContentAlignment(AlignCenter);

	Time_Style = WCssDecorationStyle();
	Time_Style.setBackgroundColor(WColor(255, 230, 200));

	setDecorationStyle(Time_Style);

	this->addWidget(new WText("Game Time : "));

	Time_Text = new WText(this);
	Time_Text->setText(IntToString(Displayed_Time));
}

void TimeWidget::SetTime(long int time)
{
	Displayed_Time = time;

	Time_Text->setText(IntToString(Displayed_Time));
}

void TimeWidget::SingleBreak()
{
	new WBreak(this);
}

void TimeWidget::DoubleBreak()
{
	new WBreak(this);
	new WBreak(this);
}