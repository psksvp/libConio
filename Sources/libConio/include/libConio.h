#ifndef LIB_CONIO_H
#define LIB_CONIO_H

/*
 * Copyright (c) Abraham vd Merwe <abz@blio.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *	  notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *	  notice, this list of conditions and the following disclaimer in the
 *	  documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the author nor the names of other contributors
 *	  may be used to endorse or promote products derived from this software
 *	  without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <curses.h>
#include <wchar.h>

/*
 * Colors
 */

#define COLOR_BLACK     0                        /* Black */
#define COLOR_RED       1                        /* Red */
#define COLOR_GREEN     2                        /* Green */
#define COLOR_YELLOW    3                        /* Yellow */
#define COLOR_BLUE      4                        /* Blue */
#define COLOR_MAGENTA   5                        /* Magenta */
#define COLOR_CYAN      6                        /* Cyan */
#define COLOR_WHITE     7                        /* White */

/*
 * Attributes
 */

#define ATTR_OFF        0                        /* All attributes off */
#define ATTR_BOLD       1                        /* Bold On */
#define ATTR_DIM        2                        /* Dim (Is this really in the ANSI standard? */
#define ATTR_UNDERLINE  4                        /* Underline (Monochrome Display Only */
#define ATTR_BLINK      5                        /* Blink On */
#define ATTR_REVERSE    7                        /* Reverse Video On */
#define ATTR_INVISIBLE  8                        /* Concealed On */

/*
 * Init & Close
 */

/* Initialize screen */
void conioOpen ();

/* Restore original screen state */
void conioClose ();

/*
 * Output
 */

/* Set color attributes */
void conioSetAttribute (int attr);

/* Set color */
void conioSetColor (int fg,int bg);

/* Move cursor to position (x,y) on the screen. Upper corner of screen is (0,0) */
void conioSetCursor (int x,int y);

/* Put a character on the screen */
void conioPutChar (char ch);

void conioPutString(const char* s);

/* Write a string to the screen */
void conioPrintf (char *format, ...);

/* Refresh screen */
void conioRefresh ();

/* Get the screen width */
int conioScreenWidth ();

/* Get the screen height */
int conioScreenHeight ();

/* Beep */
void conioBeep ();

/*
 * Input
 */

/* Read a character */
int conioGetChar ();

/* Set keyboard timeout in microseconds */
void conioSetKeyboardTimeout (int delay);

/* Empty keyboard buffer */
void conioFlushKeyboardBuffer ();

#endif	/* #ifndef LIB_CONIO_H */
