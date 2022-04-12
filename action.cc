#include "action.hh"





myActionInit::myActionInit()
{

}


myActionInit::~myActionInit()
{

}

void myActionInit::Build() const
{
	myPrimaryGenerator *gen = new myPrimaryGenerator();
	SetUserAction(gen);

}

