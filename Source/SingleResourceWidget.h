#ifndef _SINGLERESOURCEWIDGET_H
#define _SINGLERESOURCEWIDGET_H 1

#include "Util.h"

using namespace Wt;

class SingleResourceWidget : public WContainerWidget
{
public:
    SingleResourceWidget(std::string resourcename, WLink imagelink, WContainerWidget *parent = 0);

	void SetResourceCount(float resource_count);

private:
	float fResource_Count;

	WText* Resource_Count_Text;

	WImage *Resource_Image;

	WCssDecorationStyle Resource_Style;

	void SingleBreak();
	void DoubleBreak();
};

#endif