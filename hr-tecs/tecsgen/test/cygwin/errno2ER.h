#ifndef __errno2ER_h_
#define __errno2ER_h_

/* POSIX errno を ITRON,TOPPERS/ASP ER に変換 */
Inline
ER errno2ER( int err_no )
{
	ER	er;

	switch( err_no ){
	case EWOULDBLOCK: /* EAGAIN と同じ */
		er = E_WBLK;
		break;
	case ENOMEM:
		er = E_NOMEM;
		break;
	case EBADF:
		er = E_NOEXS;
		break;
	case EPIPE:
		er = E_CLS;
		break;
	default:
		er = E_OBJ;		/* とりあえず E_OBJ とする */
		break;
	}

	return er;
}

#endif /* __errno2ER_h_ */

