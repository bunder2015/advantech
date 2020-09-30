#include <windows.h>
#include "dll6155.h"

static unsigned char return0 = 0;
static unsigned short return1 = 0;
static unsigned short return2 = 0;

unsigned char FAR PASCAL _export CtrlInit() {
	__asm {
		cli
		
		mov ax,0x3598
		int 0x21
		
		mov return1,bx
		mov return2,es
		
		sti
	}
	
	if ((return1 == 0) && (return2 == 0)) {
		return 255; // TSR not loaded
	}	

	__asm {
		mov ax,'HE'
		mov bx,'LO'
		int 0x98

		mov return1,ax
                mov return2,bx

        }

	if (CmdCheck(return1, return2)) {
		if ((return1 == 'IM') && (return2 == 'OK')) {
                 	return 1; // TSR loaded and functional
		}else{
                 	return 254; // Not our TSR
                }

	}else{
		return 253; // TSR did not accept command
	}
};

unsigned char FAR PASCAL _export RunWD (unsigned char htime) {
	__asm {
		mov ax,'RW'
		mov bl,htime
		int 0x98

		mov return1,ax
                mov return2,bx
	}

	if (CmdCheck(return1, return2)) {
         	return 1;
	}else{
		return 253; // TSR did not accept command
        }
};

unsigned char FAR PASCAL _export GetWT() {
	__asm {
		mov ax,'WT'
		int 0x98

		mov return0,bl
		mov return1,ax
                mov return2,bx
        }

	if (CmdCheck(return1, return2)) {
         	return return0;
	}else{
		return 253; // TSR did not accept command
	}
};

unsigned char FAR PASCAL _export StopWD() {
	__asm {
		mov ax,'SW'
		int 0x98

		mov return1,ax
                mov return2,bx
	}

	if (CmdCheck(return1, return2)) {
         	return 1;
	}else{
		return 253; // TSR did not accept command
	}
};

unsigned char FAR PASCAL _export RebootWD() {
	__asm {
		mov ax,'RB'
		int 0x98

		mov return1,ax
                mov return2,bx
	}

	if (CmdCheck(return1, return2)) {
         	return 1;
	}else{
		return 253; // TSR did not accept command
        }
};

unsigned char CmdCheck (unsigned short r1, unsigned short r2) {
	if ((r1 == 'WH') && (r2 == 'AT')) {
		return 0; 	// TSR did not accept command
	}else{
		return 1;
        }
};

#pragma argsused
int FAR PASCAL LibMain (HANDLE hInstance, WORD wDataSeg, WORD cbHeapSize, LPSTR lpCmdLine) {
	return 1;
};