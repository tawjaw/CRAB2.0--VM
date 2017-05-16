#ifndef CRAB_H
#define CRAB_H

#include <Wt/WApplication>

#include "ui_crab.h"

class CRAB : public Wt::WApplication
{

public:
	CRAB(const Wt::WEnvironment& env);
	~CRAB();

	// declare slots here

private:
	Ui_CRAB *ui;
	
};

#endif // CRAB_H
