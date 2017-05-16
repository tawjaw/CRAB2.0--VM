#include "crab.h"


#define USE_SCROLL_AREA

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
	return new CRAB(env);
}

int main(int argc, char *argv[])
{
	return Wt::WRun(argc, argv, &createApplication);
}
