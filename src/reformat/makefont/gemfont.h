#ifndef GEMFONT_H
#define GEMFONT_H

/* This file supports GEM style fonts.  They live on disk in three parts.
   1st there's the header structure below, then a list of 'x' offsets into
   the data - one 16-bit word for each offset, and 1 offset for each letter
   in the font plus an extra offset at the end.

   This is followed by the data which is a single bitmap.
   */

struct	font_hdr {
WORD	id;			/* some random number, doesnt matter */
WORD	size;		/* Size in points.  Somehow related to pixel height. */
char	facename[32];	/* Give it a name, don't really matter. */
WORD	ADE_lo;		/* Lowest ascii character in font */
WORD	ADE_hi;		/* Highest ascii character in font */
WORD	top_dist;
WORD	asc_dist;	/* Ascender to baseline?? */
WORD	hlf_dist;
WORD	des_dist;	/* des for descender. */
WORD	bot_dist;
WORD	wchr_wdt;	/* Widest character width. */
WORD	wcel_wdt;	/* Widest 'cell' width (includes distance to next character) */
WORD	lft_ofst;
WORD	rgt_ofst;
WORD	thckning;
WORD	undrline;
WORD	lghtng_m;	/* Lightening mask.  Just use 0x55aa. */
WORD	skewng_m;	/* Skewing mask for italics. If 1 bit rotate this line. 0xaaaa*/
WORD	flags;		/* Just set to zero.  Half-assed intel swap if otherwise. */
char *hz_ofst;  /* On disk byte offset from beginning of file to hor. offsets */
WORD	*ch_ofst;	/* On disk byte offset to beginning of ?? kerning ?? data. */
UBYTE	*fnt_dta;	/* On disk byte offset to beginning of bitmap. */
WORD	frm_wdt;	/* Byte width of bitmap. */
WORD	frm_hgt;	/* Pixel height of bitmap. */
struct font_hdr	*nxt_fnt; /* Set to 0 */
}; 

#define STPROP 0
#define MFIXED 1
#define MPROP 2

#endif GEMFONT_H
