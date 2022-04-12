#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"

class myActionInit : public G4VUserActionInitialization
{
public:

	myActionInit();
	~myActionInit();

	virtual void Build() const;

};

#endif