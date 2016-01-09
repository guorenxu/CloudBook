#include "SingleResourceWidget.h"

using namespace Wt;

SingleResourceWidget::SingleResourceWidget(std::string resourcename, WLink imagelink, WContainerWidget *parent)
    : WContainerWidget(parent)
{
	setContentAlignment(AlignCenter);

	setWidth(160);

	setMinimumSize(160, 130);

	Resource_Style = WCssDecorationStyle();
	Resource_Style.setBackgroundColor(WColor(235, 255, 200));

	setDecorationStyle(Resource_Style);

	fResource_Count = 0.0f;

	Resource_Image = new WImage(imagelink, this);
	Resource_Image->setMargin(5, Top);
	Resource_Image->setToolTip(resourcename);

	SingleBreak();

	this->addWidget(new WText(resourcename));
	this->addWidget(new WText(": "));

	Resource_Count_Text = new WText(this);
	Resource_Count_Text->setText(IntToString(short int(fResource_Count)));
}

void SingleResourceWidget::SetResourceCount(float resource_count)
{
	fResource_Count = resource_count;

	Resource_Count_Text->setText(IntToString(short int(fResource_Count)));
}

void SingleResourceWidget::SingleBreak()
{
	new WBreak(this);
}

void SingleResourceWidget::DoubleBreak()
{
	new WBreak(this);
	new WBreak(this);
}