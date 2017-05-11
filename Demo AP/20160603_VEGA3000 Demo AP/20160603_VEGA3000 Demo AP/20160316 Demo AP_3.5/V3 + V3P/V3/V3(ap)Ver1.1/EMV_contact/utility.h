
#ifndef UTILITY_H
#define	UTILITY_H

#ifdef	__cplusplus
extern "C" {
#endif


BYTE ShowAPList(BYTE start_y, BYTE max_y, BYTE *sHeaderString, BYTE iHeaderStrLen, BYTE apnum, char aplist[][17], BYTE *selitem);

#ifdef	__cplusplus
}
#endif

#endif	/* UTILITY_H */

