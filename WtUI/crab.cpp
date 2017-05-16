#include "crab.h"

CRAB::CRAB(const Wt::WEnvironment& env) : Wt::WApplication(env), ui(new Ui_CRAB)
{
	ui->setupUi(root());

}

CRAB::~CRAB()
{
	delete ui;

}
