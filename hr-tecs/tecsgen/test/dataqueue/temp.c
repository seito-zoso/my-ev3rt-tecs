#include <stdio.h>

main()
{
	int  fd[2];
	int  er;
	char buf[256];

#define MSG "hello"

	er = pipe( fd );
	write( fd[1], MSG, strlen(MSG) + 1 );
	read( fd[0], buf, sizeof buf );
	puts( buf );
}
