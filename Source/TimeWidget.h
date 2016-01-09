#ifndef _TIMEWIDGET_H
#define _TIMEWIDGET_H 1

#include "Util.h"

using namespace Wt;

class TimeWidget : public WContainerWidget
{
public:
    TimeWidget(WContainerWidget *parent = 0);

	void SetTime(long int time);

private:
	WText* Time_Text;

	long int Displayed_Time;

	WCssDecorationStyle Time_Style;

	void SingleBreak();
	void DoubleBreak();
};

#endif