typedef int ID;
#include <stdio.h>
#include <stdlib.h>
#include "t_stddef.h"
#include "CsSig.hpp"

main()
{
	CsSig  *bridge = CsSig::join( "CPP2TECSsSigBridge" );
	if( bridge == NULL )
	   exit(1);

	bridge->func();

	delete bridge;
}

