#include "../sharedef.h"
#include "utility.h"

#define d_FONTSIZE 16

BYTE ShowAPList(BYTE start_y, BYTE max_y, BYTE *sHeaderString, BYTE iHeaderStrLen, BYTE apnum, char aplist[][17], BYTE *selitem)
{
	BYTE str[20], i, curr_top, curr_off, c;
	BYTE hx = 1, hy = 1;
	BYTE baHeader[17];

	CTOS_LCDTClearDisplay();

	//Show [AP List]
	if (iHeaderStrLen <= d_FONTSIZE) {
		//by Center
		hx = ((d_FONTSIZE - iHeaderStrLen) / 2) + 1;
		memset(baHeader, 0x20, sizeof (baHeader));
		memcpy(&baHeader[hx - 1], sHeaderString, iHeaderStrLen);
		CTOS_LCDTPrintXY(1, 1, baHeader);
	}


	curr_top = 0;
	curr_off = 0; //Offset from curr_top

	while (1) {
		for (i = start_y; i <= max_y; i++)
			CTOS_LCDTPrintXY(1, i, (BYTE*)"                ");

		for (i = 0; i < max_y - start_y + 1; i++) {
			if (curr_top + i >= apnum)
				break;

			if (i == curr_off)
				CTOS_LCDTSetReverse(TRUE);

			CTOS_LCDTPrintXY(1, start_y + i, (BYTE*)aplist[curr_top + i]);

			if (i == curr_off)
				CTOS_LCDTSetReverse(FALSE);
		}

		ForceMainDevice_KBDGet(&c);

		//UP for V7, F1 for V9
		if (c == d_KBD_UP || c == d_KBD_F1) {
			if (curr_off > 0) {
				curr_off--;
			}
			else if (curr_top > 0 && curr_off == 0) {
				curr_top--;
			}
		} else if (c == d_KBD_DOWN || c == d_KBD_F4) {
			if (curr_top + curr_off + 1 < apnum) {
				if (curr_off < max_y - start_y) {
					curr_off++;
				} else if (curr_top + curr_off < apnum) {
					curr_top++;
				}
			}
		} else if (c == d_KBD_ENTER) {
			*selitem = curr_top + curr_off;
			return 0;
		} else if (c == d_KBD_CANCEL) {
			return 1;
		} else if (c >= '1' && c <= '9') {
			*selitem = c - '0' - 1;
			return 0;
		}
	}
}
