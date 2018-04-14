#ifndef V1_H
#define V1_H

#include "../foldkb.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

//void promicro_bootloader_jmp(bool program);
//matrix is defined in a weird way here; the layout on both sides are asymmetrical, but the "matrix" is symmetrical but with empty gaps
//the last column is defined as a separate row because the firmware currently doesnt support more than 8 columns (this layout has 9 columns per side) K45 and K110 are the Bs on both sides; K53 and K106 are extra keys for ISO
#define KEYMAP( \
	L10,   L11,   L12,   L13,   L14,   L15,   L16,   L17,       R10,   R11,   R12,   R13,   R14,   R15,   R16,   R17, \
	L20,          L22,   L23,   L24,   L25,   L26,   L27,       R20,   R21,   R22,   R23,   R24,   R25,   R26,   R27, \
	L30,          L32,   L33,   L34,   L35,   L36,   L37,       R30,   R31,   R32,   R33,   R34,   R35,   R36, \
	L40,          L42,   L43,   L44,   L45,   L46,   L47,       R40,   R41,   R42,   R43,   R44,   R45,   R46, \
	L50,          L52,   L53,   L54,   L55,   L56,                     R51,          R53,   R54,   R55,          R57 \
	) \
	{ \
		{ L10,   L11,     L12,   L13,   L14,   L15,   L16,   L17}, \
		{ L20,   KC_NO,   L22,   L23,   L24,   L25,   L26,   L27}, \
		{ L30,   KC_NO,   L32,   L33,   L34,   L35,   L36,   L37}, \
		{ L40,   KC_NO,   L42,   L43,   L44,   L45,   L46,   L47}, \
		{ L50,   KC_NO,   L52,   L53,   L54,   L55,   L56,   KC_NO}, \
		{ R10  , R11,   R12,   R13,   R14,   R15,   R16,   R17}, \
		{ R20,   R21,   R22,   R23,   R24,   R25,   R26,   R27}, \
		{ R30,   R31,   R32,   R33,   R34,   R35,   R36,   KC_NO}, \
		{ R40,   R41,   R42,   R43,   R44,   R45,   R46,   KC_NO}, \
		{ KC_NO, R51,   KC_NO, R53,   R54,   R55,   KC_NO, R57} \
	}

#endif
