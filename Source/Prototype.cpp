#include "ResourceWidget.h"
#include "SideBarWidget.h"
#include "MultiWidget.h"
#include "Util.h"
#include "GameLogic.h"

using namespace Wt;

long int Start;


class CloudBookApplication : public WApplication
{
public:
	CloudBookApplication(const WEnvironment& env);

	void SingleBreak();
	void DoubleBreak();

	void SetMultiWidget(short int menu_state);

	void Update(); //The grand update function

private:
	ResourceWidget* GameResourceWidget;
	SideBarWidget* GameMenuWidget;
	MultiWidget* GameMultiWidget;
	GameLogic* Gameplay;
	WTimer* TickTimer;
};

/*
* The env argument contains information about the new session, and
* the initial request. It must be passed to the WApplication
* constructor so it is typically also an argument for your custom
* application constructor.
*/
CloudBookApplication::CloudBookApplication(const WEnvironment& env)
	: WApplication(env)
{
	setTitle("Cloud Book Prototype");                      // application title

	Gameplay = new GameLogic(Start);
	GameResourceWidget = new ResourceWidget(Gameplay, Start, root());
	GameMenuWidget = new SideBarWidget("GameMenuWidget", root());
	GameMultiWidget = new MultiWidget(Gameplay, GameMenuWidget, root());


	TickTimer = new WTimer();
	TickTimer->setInterval(251);

	WContainerWidget *container = new WContainerWidget(root());

	WCssDecorationStyle Main_Style = WCssDecorationStyle();
	Main_Style.setBackgroundColor(WColor(240, 240, 240));

	container->setDecorationStyle(Main_Style);

	WVBoxLayout *vbox = new WVBoxLayout();
	container->setLayout(vbox);

	vbox->addWidget(GameResourceWidget, 1);

	WHBoxLayout *hbox = new WHBoxLayout();
	vbox->addLayout(hbox);

	hbox->addWidget(GameMenuWidget);

	hbox->addWidget(GameMultiWidget);

	GameMenuWidget->Menu_State_Signal().connect(this, &CloudBookApplication::SetMultiWidget);

	TickTimer->timeout().connect(this, &CloudBookApplication::Update);
	TickTimer->start();
}

WApplication *createApplication(const WEnvironment& env)
{
	/*
	* You could read information from the environment to decide whether
	* the user has permission to start a new application
	*/
	return new CloudBookApplication(env);
}

int main(int argc, char **argv)
{
	/*
	* Your main method may set up some shared resources, but should then
	* start the server application (FastCGI or httpd) that starts listening
	* for requests, and handles all of the application life cycles.
	*
	* The last argument to WRun specifies the function that will instantiate
	* new application objects. That function is executed when a new user surfs
	* to the Wt application, and after the library has negotiated browser
	* support. The function should return a newly instantiated application
	* object.
	*/
	Start = GetTickCount();

	return WRun(argc, argv, &createApplication);
}

void CloudBookApplication::SingleBreak()
{
	root()->addWidget(new WBreak());                       // insert a line break
}

void CloudBookApplication::DoubleBreak()
{
	root()->addWidget(new WBreak());                       // insert a line break
	root()->addWidget(new WBreak());                       // insert a line break
}

void CloudBookApplication::SetMultiWidget(short int menu_state)
{
	GameMultiWidget->Set_Multi_State(menu_state);
}

void CloudBookApplication::Update()
{
	Gameplay->UpdatePlayerResources();
	GameResourceWidget->Update();
}