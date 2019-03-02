#ifndef __MDNIE_TABLE_H__
#define __MDNIE_TABLE_H__

/* 2016.02.22 */

static struct mdnie_scr_info scr_info = {
	.index = 1,
	.color_blind = 89,	/* ASCR_WIDE_CR[7:0] */
	.white_r = 107,		/* ASCR_WIDE_WR[7:0] */
	.white_g = 109,		/* ASCR_WIDE_WG[7:0] */
	.white_b = 111		/* ASCR_WIDE_WB[7:0] */
};

static inline int color_offset_f1(int x, int y)
{
	return ((y)-((547*(x))/503)+31);
}
static inline int color_offset_f2(int x, int y)
{
	return ((y)-((467*(x))/447)-25);
}
static inline int color_offset_f3(int x, int y)
{
	return ((y)+((201*(x))/39)-18718);
}
static inline int color_offset_f4(int x, int y)
{
	return ((y)+((523*(x))/173)-12111);
}

/* color coordination order is WR, WG, WB */
static unsigned char coordinate_data_1[] = {
	0xff, 0xff, 0xff, /* dummy */
	0xff, 0xf9, 0xf9, /* Tune_1 */
	0xff, 0xfa, 0xfe, /* Tune_2 */
	0xf9, 0xf7, 0xff, /* Tune_3 */
	0xff, 0xfd, 0xfa, /* Tune_4 */
	0xff, 0xff, 0xff, /* Tune_5 */
	0xf9, 0xfb, 0xff, /* Tune_6 */
	0xfb, 0xff, 0xf8, /* Tune_7 */
	0xfb, 0xff, 0xfb, /* Tune_8 */
	0xf9, 0xff, 0xfe, /* Tune_9 */
};

static unsigned char coordinate_data_2[] = {
	0xff, 0xff, 0xff, /* dummy */
	0xff, 0xfa, 0xef, /* Tune_1 */
	0xff, 0xfa, 0xef, /* Tune_2 */
	0xff, 0xfa, 0xef, /* Tune_3 */
	0xff, 0xfa, 0xef, /* Tune_4 */
	0xff, 0xfa, 0xef, /* Tune_5 */
	0xff, 0xfa, 0xef, /* Tune_6 */
	0xff, 0xfa, 0xef, /* Tune_7 */
	0xff, 0xfa, 0xef, /* Tune_8 */
	0xff, 0xfa, 0xef, /* Tune_9 */
};

static unsigned char *coordinate_data[MODE_MAX] = {
	coordinate_data_1,
	coordinate_data_2,
	coordinate_data_2,
	coordinate_data_1,
	coordinate_data_1,
	coordinate_data_1,
};

static unsigned char LEVEL_UNLOCK[] = {
	0xF0,
	0x5A, 0x5A
};

static unsigned char LEVEL_LOCK[] = {
	0xF0,
	0xA5, 0xA5
};

static char BYPASS_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x00, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char BYPASS_1[] ={
	//start
	0xEC,
	0x00, /* de cs cc 000 */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x01, /* CS Gain */
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, /* ascr_skin_on strength 0 00000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xd5, /* ascr_skin_Rr */
	0x2c, /* ascr_skin_Rg */
	0x2a, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf5, /* ascr_skin_Yg */
	0x63, /* ascr_skin_Yb */
	0xfe, /* ascr_skin_Mr */
	0x4a, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf9, /* ascr_skin_Wg */
	0xf8, /* ascr_skin_Wb */
	0x00, /* ascr_Cr */
	0xff, /* ascr_Rr */
	0xff, /* ascr_Cg */
	0x00, /* ascr_Rg */
	0xff, /* ascr_Cb */
	0x00, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x00, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xff, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xff, /* ascr_Yr */
	0x00, /* ascr_Br */
	0xff, /* ascr_Yg */
	0x00, /* ascr_Bg */
	0x00, /* ascr_Yb */
	0xff, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xff, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xff, /* ascr_Wb */
	0x00, /* ascr_Kb */
};

static char NEGATIVE_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char NEGATIVE_1[] ={
	//start
	0xEC,
	0x00, /* de cs cc 000 */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x01, /* CS Gain */
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, /* ascr_skin_on strength 0 00000 */
	0x67, /* ascr_skin_cb */
	0xa9, /* ascr_skin_cr */
	0x0c, /* ascr_dist_up */
	0x0c, /* ascr_dist_down */
	0x0c, /* ascr_dist_right */
	0x0c, /* ascr_dist_left */
	0x00, /* ascr_div_up */
	0xaa,
	0xab,
	0x00, /* ascr_div_down */
	0xaa,
	0xab,
	0x00, /* ascr_div_right */
	0xaa,
	0xab,
	0x00, /* ascr_div_left */
	0xaa,
	0xab,
	0xd5, /* ascr_skin_Rr */
	0x2c, /* ascr_skin_Rg */
	0x2a, /* ascr_skin_Rb */
	0xff, /* ascr_skin_Yr */
	0xf5, /* ascr_skin_Yg */
	0x63, /* ascr_skin_Yb */
	0xfe, /* ascr_skin_Mr */
	0x4a, /* ascr_skin_Mg */
	0xff, /* ascr_skin_Mb */
	0xff, /* ascr_skin_Wr */
	0xf9, /* ascr_skin_Wg */
	0xf8, /* ascr_skin_Wb */
	0xff, /* ascr_Cr */
	0x00, /* ascr_Rr */
	0x00, /* ascr_Cg */
	0xff, /* ascr_Rg */
	0x00, /* ascr_Cb */
	0xff, /* ascr_Rb */
	0x00, /* ascr_Mr */
	0xff, /* ascr_Gr */
	0xff, /* ascr_Mg */
	0x00, /* ascr_Gg */
	0x00, /* ascr_Mb */
	0xff, /* ascr_Gb */
	0x00, /* ascr_Yr */
	0xff, /* ascr_Br */
	0x00, /* ascr_Yg */
	0xff, /* ascr_Bg */
	0xff, /* ascr_Yb */
	0x00, /* ascr_Bb */
	0x00, /* ascr_Wr */
	0xff, /* ascr_Kr */
	0x00, /* ascr_Wg */
	0xff, /* ascr_Kg */
	0x00, /* ascr_Wb */
	0xff, /* ascr_Kb */
};

static char GRAYSCALE_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char GRAYSCALE_1[] ={
	//start
	0xEC,
	0x00, /* de cs cc 000 */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x01, /* CS Gain */
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0xb3, //ascr_Cr
	0x4c, //ascr_Rr
	0xb3, //ascr_Cg
	0x4c, //ascr_Rg
	0xb3, //ascr_Cb
	0x4c, //ascr_Rb
	0x69, //ascr_Mr
	0x96, //ascr_Gr
	0x69, //ascr_Mg
	0x96, //ascr_Gg
	0x69, //ascr_Mb
	0x96, //ascr_Gb
	0xe2, //ascr_Yr
	0x1d, //ascr_Br
	0xe2, //ascr_Yg
	0x1d, //ascr_Bg
	0xe2, //ascr_Yb
	0x1d, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char GRAYSCALE_NEGATIVE_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char GRAYSCALE_NEGATIVE_1[] ={
	//start
	0xEC,
	0x00, /* de cs cc 000 */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x01, /* CS Gain */
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x4c, //ascr_Cr
	0xb3, //ascr_Rr
	0x4c, //ascr_Cg
	0xb3, //ascr_Rg
	0x4c, //ascr_Cb
	0xb3, //ascr_Rb
	0x96, //ascr_Mr
	0x69, //ascr_Gr
	0x96, //ascr_Mg
	0x69, //ascr_Gg
	0x96, //ascr_Mb
	0x69, //ascr_Gb
	0x1d, //ascr_Yr
	0xe2, //ascr_Br
	0x1d, //ascr_Yg
	0xe2, //ascr_Bg
	0x1d, //ascr_Yb
	0xe2, //ascr_Bb
	0x00, //ascr_Wr
	0xff, //ascr_Kr
	0x00, //ascr_Wg
	0xff, //ascr_Kg
	0x00, //ascr_Wb
	0xff, //ascr_Kb
	//end
};

static char COLOR_BLIND_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char COLOR_BLIND_1[] ={
	//start
	0xEC,
	0x00, /* de cs cc 000 */
	0x00, /* de_gain 10 */
	0x00,
	0x07, /* de_maxplus 11 */
	0xff,
	0x07, /* de_maxminus 11 */
	0xff,
	0x01, /* CS Gain */
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char UI_DYNAMIC_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char UI_DYNAMIC_1[] ={
	0xEC,
	0x03, /* de cs cc 000 */
	0x00, /* de_gain 10 */
	0x08,
	0x00, /* de_maxplus 11 */
	0x40,
	0x00, /* de_maxminus 11 */
	0x40,
	0x01, /* CS Gain */
	0x20,
	0x00, //curve 1 b
	0x14, //curve 1 a
	0x00, //curve 2 b
	0x14, //curve 2 a
	0x00, //curve 3 b
	0x14, //curve 3 a
	0x00, //curve 4 b
	0x14, //curve 4 a
	0x03, //curve 5 b
	0x9a, //curve 5 a
	0x03, //curve 6 b
	0x9a, //curve 6 a
	0x03, //curve 7 b
	0x9a, //curve 7 a
	0x03, //curve 8 b
	0x9a, //curve 8 a
	0x07, //curve 9 b
	0x9e, //curve 9 a
	0x07, //curve10 b
	0x9e, //curve10 a
	0x07, //curve11 b
	0x9e, //curve11 a
	0x07, //curve12 b
	0x9e, //curve12 a
	0x0a, //curve13 b
	0xa0, //curve13 a
	0x0a, //curve14 b
	0xa0, //curve14 a
	0x0a, //curve15 b
	0xa0, //curve15 a
	0x0a, //curve16 b
	0xa0, //curve16 a
	0x16, //curve17 b
	0xa6, //curve17 a
	0x16, //curve18 b
	0xa6, //curve18 a
	0x16, //curve19 b
	0xa6, //curve19 a
	0x16, //curve20 b
	0xa6, //curve20 a
	0x05, //curve21 b
	0x21, //curve21 a
	0x0b, //curve22 b
	0x20, //curve22 a
	0x87, //curve23 b
	0x0f, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, //ascr_skin_on strength 0 00000
	0xa9, //ascr_skin_cr
	0x67, //ascr_skin_cb
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xf0, //ascr_skin_Rr
	0x58, //ascr_skin_Rg
	0x68, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x10, //ascr_Rg
	0xff, //ascr_Cb
	0x10, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char UI_STANDARD_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char UI_STANDARD_1[] = {
	0xEC,
	0x00, //de cs gamma 0000
	0x00, //de_gain 10
	0x00,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, /* ascr_Cr */
	0xf4, /* ascr_Rr */
	0xed, /* ascr_Cg */
	0x0a, /* ascr_Rg */
	0xe2, /* ascr_Cb */
	0x12, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x0a, /* ascr_Mg */
	0xdf, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xee, /* ascr_Yr */
	0x28, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x14, /* ascr_Bg */
	0x19, /* ascr_Yb */
	0xf2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char UI_NATURAL_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char UI_NATURAL_1[] ={
	0xEC,
	0x02, //de cs gamma 0000
	0x00, //de_gain 10
	0x00,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x40,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x96, /* ascr_Cr */
	0xd2, /* ascr_Rr */
	0xfa, /* ascr_Cg */
	0x2a, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xdd, /* ascr_Mr */
	0x8c, /* ascr_Gr */
	0x2c, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x48, /* ascr_Gb */
	0xf2, /* ascr_Yr */
	0x34, /* ascr_Br */
	0xf2, /* ascr_Yg */
	0x1e, /* ascr_Bg */
	0x54, /* ascr_Yb */
	0xeb, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char UI_MOVIE_2[] ={
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char UI_MOVIE_1[] ={
	0xEC,
	0x00, // de cs cc 0000
	0x00, //de_gain 10
	0x08,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char UI_AUTO_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char UI_AUTO_1[] = {
	0xEC,
	0x00, //de cs cc 0000
	0x00, //de_gain 10
	0x08,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char VIDEO_DYNAMIC_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char VIDEO_DYNAMIC_1[] = {
	0xEC,
	0x07, /* de cs cc 000 */
	0x00, /* de_gain 10 */
	0x0a,
	0x00, /* de_maxplus 11 */
	0x40,
	0x00, /* de_maxminus 11 */
	0x40,
	0x01, /* CS Gain */
	0x20,
	0x00, //curve 1 b
	0x14, //curve 1 a
	0x00, //curve 2 b
	0x14, //curve 2 a
	0x00, //curve 3 b
	0x14, //curve 3 a
	0x00, //curve 4 b
	0x14, //curve 4 a
	0x03, //curve 5 b
	0x9a, //curve 5 a
	0x03, //curve 6 b
	0x9a, //curve 6 a
	0x03, //curve 7 b
	0x9a, //curve 7 a
	0x03, //curve 8 b
	0x9a, //curve 8 a
	0x07, //curve 9 b
	0x9e, //curve 9 a
	0x07, //curve10 b
	0x9e, //curve10 a
	0x07, //curve11 b
	0x9e, //curve11 a
	0x07, //curve12 b
	0x9e, //curve12 a
	0x0a, //curve13 b
	0xa0, //curve13 a
	0x0a, //curve14 b
	0xa0, //curve14 a
	0x0a, //curve15 b
	0xa0, //curve15 a
	0x0a, //curve16 b
	0xa0, //curve16 a
	0x16, //curve17 b
	0xa6, //curve17 a
	0x16, //curve18 b
	0xa6, //curve18 a
	0x16, //curve19 b
	0xa6, //curve19 a
	0x16, //curve20 b
	0xa6, //curve20 a
	0x05, //curve21 b
	0x21, //curve21 a
	0x0b, //curve22 b
	0x20, //curve22 a
	0x87, //curve23 b
	0x0f, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, //ascr_skin_on strength 0 00000
	0xa9, //ascr_skin_cr
	0x67, //ascr_skin_cb
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xf0, //ascr_skin_Rr
	0x58, //ascr_skin_Rg
	0x68, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x10, //ascr_Rg
	0xff, //ascr_Cb
	0x10, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char VIDEO_STANDARD_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char VIDEO_STANDARD_1[] = {
	0xEC,
	0x04, //de cs gamma 000
	0x00, //de_gain 10
	0x04,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, /* ascr_Cr */
	0xf4, /* ascr_Rr */
	0xed, /* ascr_Cg */
	0x0a, /* ascr_Rg */
	0xe2, /* ascr_Cb */
	0x12, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x0a, /* ascr_Mg */
	0xdf, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xee, /* ascr_Yr */
	0x28, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x14, /* ascr_Bg */
	0x19, /* ascr_Yb */
	0xf2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char VIDEO_NATURAL_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char VIDEO_NATURAL_1[] ={
	0xEC,
	0x06, //de cs gamma 0000
	0x00, //de_gain 10
	0x04,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x01, //cs gain 10
	0x40,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x96, /* ascr_Cr */
	0xd2, /* ascr_Rr */
	0xfa, /* ascr_Cg */
	0x2a, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xdd, /* ascr_Mr */
	0x8c, /* ascr_Gr */
	0x2c, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x48, /* ascr_Gb */
	0xf2, /* ascr_Yr */
	0x34, /* ascr_Br */
	0xf2, /* ascr_Yg */
	0x1e, /* ascr_Bg */
	0x54, /* ascr_Yb */
	0xeb, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char VIDEO_MOVIE_2[] ={
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char VIDEO_MOVIE_1[] ={
	0xEC,
	0x00, // de cs cc 000
	0x00, // de_gain 10
	0x00,
	0x07, // de_maxplus 11
	0xff,
	0x07, // de_maxminus 11
	0xff,
	0x01, // CS Gain 10
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, // ascr_skin_on strength 0 00000
	0x67, // ascr_skin_cb
	0xa9, // ascr_skin_cr
	0x0c, // ascr_dist_up
	0x0c, // ascr_dist_down
	0x0c, // ascr_dist_right
	0x0c, // ascr_dist_left
	0x00, // ascr_div_up 20
	0xaa,
	0xab,
	0x00, // ascr_div_down
	0xaa,
	0xab,
	0x00, // ascr_div_right
	0xaa,
	0xab,
	0x00, // ascr_div_left
	0xaa,
	0xab,
	0xd5, // ascr_skin_Rr
	0x2c, // ascr_skin_Rg
	0x2a, // ascr_skin_Rb
	0xff, // ascr_skin_Yr
	0xf5, // ascr_skin_Yg
	0x63, // ascr_skin_Yb
	0xfe, // ascr_skin_Mr
	0x4a, // ascr_skin_Mg
	0xff, // ascr_skin_Mb
	0xff, // ascr_skin_Wr
	0xf9, // ascr_skin_Wg
	0xf8, // ascr_skin_Wb
	0x00, // ascr_Cr
	0xff, // ascr_Rr
	0xff, // ascr_Cg
	0x00, // ascr_Rg
	0xff, // ascr_Cb
	0x00, // ascr_Rb
	0xff, // ascr_Mr
	0x00, // ascr_Gr
	0x00, // ascr_Mg
	0xff, // ascr_Gg
	0xff, // ascr_Mb
	0x00, // ascr_Gb
	0xff, // ascr_Yr
	0x00, // ascr_Br
	0xff, // ascr_Yg
	0x00, // ascr_Bg
	0x00, // ascr_Yb
	0xff, // ascr_Bb
	0xff, // ascr_Wr
	0x00, // ascr_Kr
	0xff, // ascr_Wg
	0x00, // ascr_Kg
	0xff, // ascr_Wb
	0x00, // ascr_Kb
	//end
};

static char VIDEO_AUTO_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char VIDEO_AUTO_1[] ={
	0xEC,
	0x07, //de cs gamma 000
	0x00, //de_gain 10
	0x08,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x01, //cs gain 10
	0x20,
	0x00, //curve 1 b
	0x14, //curve 1 a
	0x00, //curve 2 b
	0x14, //curve 2 a
	0x00, //curve 3 b
	0x14, //curve 3 a
	0x00, //curve 4 b
	0x14, //curve 4 a
	0x03, //curve 5 b
	0x9a, //curve 5 a
	0x03, //curve 6 b
	0x9a, //curve 6 a
	0x03, //curve 7 b
	0x9a, //curve 7 a
	0x03, //curve 8 b
	0x9a, //curve 8 a
	0x07, //curve 9 b
	0x9e, //curve 9 a
	0x07, //curve10 b
	0x9e, //curve10 a
	0x07, //curve11 b
	0x9e, //curve11 a
	0x07, //curve12 b
	0x9e, //curve12 a
	0x0a, //curve13 b
	0xa0, //curve13 a
	0x0a, //curve14 b
	0xa0, //curve14 a
	0x0a, //curve15 b
	0xa0, //curve15 a
	0x0a, //curve16 b
	0xa0, //curve16 a
	0x16, //curve17 b
	0xa6, //curve17 a
	0x16, //curve18 b
	0xa6, //curve18 a
	0x16, //curve19 b
	0xa6, //curve19 a
	0x16, //curve20 b
	0xa6, //curve20 a
	0x05, //curve21 b
	0x21, //curve21 a
	0x0b, //curve22 b
	0x20, //curve22 a
	0x87, //curve23 b
	0x0f, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, //ascr_skin_on strength 0 00000
	0xa9, //ascr_skin_cr
	0x67, //ascr_skin_cb
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xf0, //ascr_skin_Rr
	0x58, //ascr_skin_Rg
	0x68, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x10, //ascr_Rg
	0xff, //ascr_Cb
	0x10, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char VIDEO_WARM_2[] ={
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char VIDEO_WARM_1[] ={
	0xEC,
	0x00, // de cs cc 000
	0x00, // de_gain 10
	0x00,
	0x07, // de_maxplus 11
	0xff,
	0x07, // de_maxminus 11
	0xff,
	0x01, // CS Gain 10
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, // ascr_skin_on strength 0 00000
	0x67, // ascr_skin_cb
	0xa9, // ascr_skin_cr
	0x0c, // ascr_dist_up
	0x0c, // ascr_dist_down
	0x0c, // ascr_dist_right
	0x0c, // ascr_dist_left
	0x00, // ascr_div_up 20
	0xaa,
	0xab,
	0x00, // ascr_div_down
	0xaa,
	0xab,
	0x00, // ascr_div_right
	0xaa,
	0xab,
	0x00, // ascr_div_left
	0xaa,
	0xab,
	0xd5, // ascr_skin_Rr
	0x2c, // ascr_skin_Rg
	0x2a, // ascr_skin_Rb
	0xff, // ascr_skin_Yr
	0xf5, // ascr_skin_Yg
	0x63, // ascr_skin_Yb
	0xfe, // ascr_skin_Mr
	0x4a, // ascr_skin_Mg
	0xff, // ascr_skin_Mb
	0xff, // ascr_skin_Wr
	0xf9, // ascr_skin_Wg
	0xf8, // ascr_skin_Wb
	0x00, // ascr_Cr
	0xff, // ascr_Rr
	0xff, // ascr_Cg
	0x00, // ascr_Rg
	0xff, // ascr_Cb
	0x00, // ascr_Rb
	0xff, // ascr_Mr
	0x00, // ascr_Gr
	0x00, // ascr_Mg
	0xff, // ascr_Gg
	0xff, // ascr_Mb
	0x00, // ascr_Gb
	0xff, // ascr_Yr
	0x00, // ascr_Br
	0xff, // ascr_Yg
	0x00, // ascr_Bg
	0x00, // ascr_Yb
	0xff, // ascr_Bb
	0xff, // ascr_Wr
	0x00, // ascr_Kr
	0xff, // ascr_Wg
	0x00, // ascr_Kg
	0xff, // ascr_Wb
	0x00, // ascr_Kb
	//end
};

static char VIDEO_COLD_2[] ={
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char VIDEO_COLD_1[] ={
	0xEC,
	0x00, // de cs cc 000
	0x00, // de_gain 10
	0x00,
	0x07, // de_maxplus 11
	0xff,
	0x07, // de_maxminus 11
	0xff,
	0x01, // CS Gain 10
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, // ascr_skin_on strength 0 00000
	0x67, // ascr_skin_cb
	0xa9, // ascr_skin_cr
	0x0c, // ascr_dist_up
	0x0c, // ascr_dist_down
	0x0c, // ascr_dist_right
	0x0c, // ascr_dist_left
	0x00, // ascr_div_up 20
	0xaa,
	0xab,
	0x00, // ascr_div_down
	0xaa,
	0xab,
	0x00, // ascr_div_right
	0xaa,
	0xab,
	0x00, // ascr_div_left
	0xaa,
	0xab,
	0xd5, // ascr_skin_Rr
	0x2c, // ascr_skin_Rg
	0x2a, // ascr_skin_Rb
	0xff, // ascr_skin_Yr
	0xf5, // ascr_skin_Yg
	0x63, // ascr_skin_Yb
	0xfe, // ascr_skin_Mr
	0x4a, // ascr_skin_Mg
	0xff, // ascr_skin_Mb
	0xff, // ascr_skin_Wr
	0xf9, // ascr_skin_Wg
	0xf8, // ascr_skin_Wb
	0x00, // ascr_Cr
	0xff, // ascr_Rr
	0xff, // ascr_Cg
	0x00, // ascr_Rg
	0xff, // ascr_Cb
	0x00, // ascr_Rb
	0xff, // ascr_Mr
	0x00, // ascr_Gr
	0x00, // ascr_Mg
	0xff, // ascr_Gg
	0xff, // ascr_Mb
	0x00, // ascr_Gb
	0xff, // ascr_Yr
	0x00, // ascr_Br
	0xff, // ascr_Yg
	0x00, // ascr_Bg
	0x00, // ascr_Yb
	0xff, // ascr_Bb
	0xff, // ascr_Wr
	0x00, // ascr_Kr
	0xff, // ascr_Wg
	0x00, // ascr_Kg
	0xff, // ascr_Wb
	0x00, // ascr_Kb
	//end
};

static char CAMERA_DYNAMIC_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char CAMERA_DYNAMIC_1[] = {
	0xEC,
	0x03, //de cs gamma 000
	0x00, //de_gain 10
	0x0a,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x20,
	0x00, //curve 1 b
	0x14, //curve 1 a
	0x00, //curve 2 b
	0x14, //curve 2 a
	0x00, //curve 3 b
	0x14, //curve 3 a
	0x00, //curve 4 b
	0x14, //curve 4 a
	0x03, //curve 5 b
	0x9a, //curve 5 a
	0x03, //curve 6 b
	0x9a, //curve 6 a
	0x03, //curve 7 b
	0x9a, //curve 7 a
	0x03, //curve 8 b
	0x9a, //curve 8 a
	0x07, //curve 9 b
	0x9e, //curve 9 a
	0x07, //curve10 b
	0x9e, //curve10 a
	0x07, //curve11 b
	0x9e, //curve11 a
	0x07, //curve12 b
	0x9e, //curve12 a
	0x0a, //curve13 b
	0xa0, //curve13 a
	0x0a, //curve14 b
	0xa0, //curve14 a
	0x0a, //curve15 b
	0xa0, //curve15 a
	0x0a, //curve16 b
	0xa0, //curve16 a
	0x16, //curve17 b
	0xa6, //curve17 a
	0x16, //curve18 b
	0xa6, //curve18 a
	0x16, //curve19 b
	0xa6, //curve19 a
	0x16, //curve20 b
	0xa6, //curve20 a
	0x05, //curve21 b
	0x21, //curve21 a
	0x0b, //curve22 b
	0x20, //curve22 a
	0x87, //curve23 b
	0x0f, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, //ascr_skin_on strength 0 00000
	0xa9, //ascr_skin_cr
	0x67, //ascr_skin_cb
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xf0, //ascr_skin_Rr
	0x58, //ascr_skin_Rg
	0x68, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x10, //ascr_Rg
	0xff, //ascr_Cb
	0x10, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char CAMERA_STANDARD_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char CAMERA_STANDARD_1[] ={
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x04,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, /* ascr_Cr */
	0xf4, /* ascr_Rr */
	0xed, /* ascr_Cg */
	0x0a, /* ascr_Rg */
	0xe2, /* ascr_Cb */
	0x12, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x0a, /* ascr_Mg */
	0xdf, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xee, /* ascr_Yr */
	0x28, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x14, /* ascr_Bg */
	0x19, /* ascr_Yb */
	0xf2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char CAMERA_NATURAL_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char CAMERA_NATURAL_1[] ={
	0xEC,
	0x02, //de cs gamma 0000
	0x00, //de_gain 10
	0x00,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x40,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x96, /* ascr_Cr */
	0xd2, /* ascr_Rr */
	0xfa, /* ascr_Cg */
	0x2a, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xdd, /* ascr_Mr */
	0x8c, /* ascr_Gr */
	0x2c, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x48, /* ascr_Gb */
	0xf2, /* ascr_Yr */
	0x34, /* ascr_Br */
	0xf2, /* ascr_Yg */
	0x1e, /* ascr_Bg */
	0x54, /* ascr_Yb */
	0xeb, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char CAMERA_MOVIE_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char CAMERA_MOVIE_1[] = {
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x08,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x38, //ascr_skin_Rg
	0x48, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf0, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xd8, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xd9, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xe0, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xf6, //ascr_Cb
	0x00, //ascr_Rb
	0xd8, //ascr_Mr
	0x3b, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xd9, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x14, //ascr_Br
	0xf9, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char CAMERA_AUTO_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char CAMERA_AUTO_1[] = {
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x08,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, //ascr_skin_on strength 0 00000
	0x9a, //ascr_skin_cr
	0x6a, //ascr_skin_cb
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x3d, //ascr_skin_Rg
	0x58, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf0, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xd8, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xd9, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xe0, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xf6, //ascr_Cb
	0x00, //ascr_Rb
	0xd8, //ascr_Mr
	0x3b, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xd9, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x14, //ascr_Br
	0xf9, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char GALLERY_DYNAMIC_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char GALLERY_DYNAMIC_1[] = {
	0xEC,
	0x07, //de cs gamma 000
	0x00, //de_gain 10
	0x0a,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x20,
	0x00, //curve 1 b
	0x14, //curve 1 a
	0x00, //curve 2 b
	0x14, //curve 2 a
	0x00, //curve 3 b
	0x14, //curve 3 a
	0x00, //curve 4 b
	0x14, //curve 4 a
	0x03, //curve 5 b
	0x9a, //curve 5 a
	0x03, //curve 6 b
	0x9a, //curve 6 a
	0x03, //curve 7 b
	0x9a, //curve 7 a
	0x03, //curve 8 b
	0x9a, //curve 8 a
	0x07, //curve 9 b
	0x9e, //curve 9 a
	0x07, //curve10 b
	0x9e, //curve10 a
	0x07, //curve11 b
	0x9e, //curve11 a
	0x07, //curve12 b
	0x9e, //curve12 a
	0x0a, //curve13 b
	0xa0, //curve13 a
	0x0a, //curve14 b
	0xa0, //curve14 a
	0x0a, //curve15 b
	0xa0, //curve15 a
	0x0a, //curve16 b
	0xa0, //curve16 a
	0x16, //curve17 b
	0xa6, //curve17 a
	0x16, //curve18 b
	0xa6, //curve18 a
	0x16, //curve19 b
	0xa6, //curve19 a
	0x16, //curve20 b
	0xa6, //curve20 a
	0x05, //curve21 b
	0x21, //curve21 a
	0x0b, //curve22 b
	0x20, //curve22 a
	0x87, //curve23 b
	0x0f, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, //ascr_skin_on strength 0 00000
	0xa9, //ascr_skin_cr
	0x67, //ascr_skin_cb
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xf0, //ascr_skin_Rr
	0x58, //ascr_skin_Rg
	0x68, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x10, //ascr_Rg
	0xff, //ascr_Cb
	0x10, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char GALLERY_STANDARD_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char GALLERY_STANDARD_1[] = {
	0xEC,
	0x04, //de cs gamma 000
	0x00, //de_gain 10
	0x04,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, /* ascr_Cr */
	0xf4, /* ascr_Rr */
	0xed, /* ascr_Cg */
	0x0a, /* ascr_Rg */
	0xe2, /* ascr_Cb */
	0x12, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x0a, /* ascr_Mg */
	0xdf, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xee, /* ascr_Yr */
	0x28, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x14, /* ascr_Bg */
	0x19, /* ascr_Yb */
	0xf2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char GALLERY_NATURAL_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char GALLERY_NATURAL_1[] ={
	0xEC,
	0x06, //de cs gamma 0000
	0x00, //de_gain 10
	0x04,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x01, //cs gain 10
	0x40,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x96, /* ascr_Cr */
	0xd2, /* ascr_Rr */
	0xfa, /* ascr_Cg */
	0x2a, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xdd, /* ascr_Mr */
	0x8c, /* ascr_Gr */
	0x2c, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x48, /* ascr_Gb */
	0xf2, /* ascr_Yr */
	0x34, /* ascr_Br */
	0xf2, /* ascr_Yg */
	0x1e, /* ascr_Bg */
	0x54, /* ascr_Yb */
	0xeb, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char GALLERY_MOVIE_2[] = {
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char GALLERY_MOVIE_1[] = {
	0xEC,
	0x00, // de cs cc 000
	0x00, // de_gain 10
	0x00,
	0x07, // de_maxplus 11
	0xff,
	0x07, // de_maxminus 11
	0xff,
	0x01, // CS Gain 10
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, // ascr_skin_on strength 0 00000
	0x67, // ascr_skin_cb
	0xa9, // ascr_skin_cr
	0x0c, // ascr_dist_up
	0x0c, // ascr_dist_down
	0x0c, // ascr_dist_right
	0x0c, // ascr_dist_left
	0x00, // ascr_div_up 20
	0xaa,
	0xab,
	0x00, // ascr_div_down
	0xaa,
	0xab,
	0x00, // ascr_div_right
	0xaa,
	0xab,
	0x00, // ascr_div_left
	0xaa,
	0xab,
	0xd5, // ascr_skin_Rr
	0x2c, // ascr_skin_Rg
	0x2a, // ascr_skin_Rb
	0xff, // ascr_skin_Yr
	0xf5, // ascr_skin_Yg
	0x63, // ascr_skin_Yb
	0xfe, // ascr_skin_Mr
	0x4a, // ascr_skin_Mg
	0xff, // ascr_skin_Mb
	0xff, // ascr_skin_Wr
	0xf9, // ascr_skin_Wg
	0xf8, // ascr_skin_Wb
	0x00, // ascr_Cr
	0xff, // ascr_Rr
	0xff, // ascr_Cg
	0x00, // ascr_Rg
	0xff, // ascr_Cb
	0x00, // ascr_Rb
	0xff, // ascr_Mr
	0x00, // ascr_Gr
	0x00, // ascr_Mg
	0xff, // ascr_Gg
	0xff, // ascr_Mb
	0x00, // ascr_Gb
	0xff, // ascr_Yr
	0x00, // ascr_Br
	0xff, // ascr_Yg
	0x00, // ascr_Bg
	0x00, // ascr_Yb
	0xff, // ascr_Bb
	0xff, // ascr_Wr
	0x00, // ascr_Kr
	0xff, // ascr_Wg
	0x00, // ascr_Kg
	0xff, // ascr_Wb
	0x00, // ascr_Kb
	//end
};

static char GALLERY_AUTO_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char GALLERY_AUTO_1[] = {
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x08,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, //ascr_skin_on strength 0 00000
	0x9a, //ascr_skin_cr
	0x6a, //ascr_skin_cb
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x3d, //ascr_skin_Rg
	0x58, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf0, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xd8, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xd9, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xe0, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xf6, //ascr_Cb
	0x00, //ascr_Rb
	0xd8, //ascr_Mr
	0x3b, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xd9, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x14, //ascr_Br
	0xf9, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char VT_DYNAMIC_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char VT_DYNAMIC_1[] = {
	0xEC,
	0x03, //de cs gamma 000
	0x00, //de_gain 10
	0x0a,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x20,
	0x00, //curve 1 b
	0x14, //curve 1 a
	0x00, //curve 2 b
	0x14, //curve 2 a
	0x00, //curve 3 b
	0x14, //curve 3 a
	0x00, //curve 4 b
	0x14, //curve 4 a
	0x03, //curve 5 b
	0x9a, //curve 5 a
	0x03, //curve 6 b
	0x9a, //curve 6 a
	0x03, //curve 7 b
	0x9a, //curve 7 a
	0x03, //curve 8 b
	0x9a, //curve 8 a
	0x07, //curve 9 b
	0x9e, //curve 9 a
	0x07, //curve10 b
	0x9e, //curve10 a
	0x07, //curve11 b
	0x9e, //curve11 a
	0x07, //curve12 b
	0x9e, //curve12 a
	0x0a, //curve13 b
	0xa0, //curve13 a
	0x0a, //curve14 b
	0xa0, //curve14 a
	0x0a, //curve15 b
	0xa0, //curve15 a
	0x0a, //curve16 b
	0xa0, //curve16 a
	0x16, //curve17 b
	0xa6, //curve17 a
	0x16, //curve18 b
	0xa6, //curve18 a
	0x16, //curve19 b
	0xa6, //curve19 a
	0x16, //curve20 b
	0xa6, //curve20 a
	0x05, //curve21 b
	0x21, //curve21 a
	0x0b, //curve22 b
	0x20, //curve22 a
	0x87, //curve23 b
	0x0f, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, //ascr_skin_on strength 0 00000
	0xa9, //ascr_skin_cr
	0x67, //ascr_skin_cb
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xf0, //ascr_skin_Rr
	0x58, //ascr_skin_Rg
	0x68, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x10, //ascr_Rg
	0xff, //ascr_Cb
	0x10, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char VT_STANDARD_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char VT_STANDARD_1[] = {
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x04,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, /* ascr_Cr */
	0xf4, /* ascr_Rr */
	0xed, /* ascr_Cg */
	0x0a, /* ascr_Rg */
	0xe2, /* ascr_Cb */
	0x12, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x0a, /* ascr_Mg */
	0xdf, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xee, /* ascr_Yr */
	0x28, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x14, /* ascr_Bg */
	0x19, /* ascr_Yb */
	0xf2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char VT_NATURAL_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char VT_NATURAL_1[] ={
	0xEC,
	0x02, //de cs gamma 0000
	0x00, //de_gain 10
	0x00,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x40,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x96, /* ascr_Cr */
	0xd2, /* ascr_Rr */
	0xfa, /* ascr_Cg */
	0x2a, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xdd, /* ascr_Mr */
	0x8c, /* ascr_Gr */
	0x2c, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x48, /* ascr_Gb */
	0xf2, /* ascr_Yr */
	0x34, /* ascr_Br */
	0xf2, /* ascr_Yg */
	0x1e, /* ascr_Bg */
	0x54, /* ascr_Yb */
	0xeb, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char VT_MOVIE_2[] = {
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char VT_MOVIE_1[] = {
	0xEC,
	0x00, // de cs cc 000
	0x00, // de_gain 10
	0x00,
	0x07, // de_maxplus 11
	0xff,
	0x07, // de_maxminus 11
	0xff,
	0x01, // CS Gain 10
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, // ascr_skin_on strength 0 00000
	0x67, // ascr_skin_cb
	0xa9, // ascr_skin_cr
	0x0c, // ascr_dist_up
	0x0c, // ascr_dist_down
	0x0c, // ascr_dist_right
	0x0c, // ascr_dist_left
	0x00, // ascr_div_up 20
	0xaa,
	0xab,
	0x00, // ascr_div_down
	0xaa,
	0xab,
	0x00, // ascr_div_right
	0xaa,
	0xab,
	0x00, // ascr_div_left
	0xaa,
	0xab,
	0xd5, // ascr_skin_Rr
	0x2c, // ascr_skin_Rg
	0x2a, // ascr_skin_Rb
	0xff, // ascr_skin_Yr
	0xf5, // ascr_skin_Yg
	0x63, // ascr_skin_Yb
	0xfe, // ascr_skin_Mr
	0x4a, // ascr_skin_Mg
	0xff, // ascr_skin_Mb
	0xff, // ascr_skin_Wr
	0xf9, // ascr_skin_Wg
	0xf8, // ascr_skin_Wb
	0x00, // ascr_Cr
	0xff, // ascr_Rr
	0xff, // ascr_Cg
	0x00, // ascr_Rg
	0xff, // ascr_Cb
	0x00, // ascr_Rb
	0xff, // ascr_Mr
	0x00, // ascr_Gr
	0x00, // ascr_Mg
	0xff, // ascr_Gg
	0xff, // ascr_Mb
	0x00, // ascr_Gb
	0xff, // ascr_Yr
	0x00, // ascr_Br
	0xff, // ascr_Yg
	0x00, // ascr_Bg
	0x00, // ascr_Yb
	0xff, // ascr_Bb
	0xff, // ascr_Wr
	0x00, // ascr_Kr
	0xff, // ascr_Wg
	0x00, // ascr_Kg
	0xff, // ascr_Wb
	0x00, // ascr_Kb
	//end
};

static char VT_AUTO_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char VT_AUTO_1[] = {
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x08,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x6a, //ascr_skin_cb
	0x9a, //ascr_skin_cr
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char BROWSER_DYNAMIC_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char BROWSER_DYNAMIC_1[] = {
	0xEC,
	0x03, //de cs gamma 000
	0x00, //de_gain 10
	0x0a,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x20,
	0x00, //curve 1 b
	0x14, //curve 1 a
	0x00, //curve 2 b
	0x14, //curve 2 a
	0x00, //curve 3 b
	0x14, //curve 3 a
	0x00, //curve 4 b
	0x14, //curve 4 a
	0x03, //curve 5 b
	0x9a, //curve 5 a
	0x03, //curve 6 b
	0x9a, //curve 6 a
	0x03, //curve 7 b
	0x9a, //curve 7 a
	0x03, //curve 8 b
	0x9a, //curve 8 a
	0x07, //curve 9 b
	0x9e, //curve 9 a
	0x07, //curve10 b
	0x9e, //curve10 a
	0x07, //curve11 b
	0x9e, //curve11 a
	0x07, //curve12 b
	0x9e, //curve12 a
	0x0a, //curve13 b
	0xa0, //curve13 a
	0x0a, //curve14 b
	0xa0, //curve14 a
	0x0a, //curve15 b
	0xa0, //curve15 a
	0x0a, //curve16 b
	0xa0, //curve16 a
	0x16, //curve17 b
	0xa6, //curve17 a
	0x16, //curve18 b
	0xa6, //curve18 a
	0x16, //curve19 b
	0xa6, //curve19 a
	0x16, //curve20 b
	0xa6, //curve20 a
	0x05, //curve21 b
	0x21, //curve21 a
	0x0b, //curve22 b
	0x20, //curve22 a
	0x87, //curve23 b
	0x0f, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, //ascr_skin_on strength 0 00000
	0xa9, //ascr_skin_cr
	0x67, //ascr_skin_cb
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xf0, //ascr_skin_Rr
	0x58, //ascr_skin_Rg
	0x68, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x10, //ascr_Rg
	0xff, //ascr_Cb
	0x10, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char BROWSER_STANDARD_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char BROWSER_STANDARD_1[] = {
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x04,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, /* ascr_Cr */
	0xf4, /* ascr_Rr */
	0xed, /* ascr_Cg */
	0x0a, /* ascr_Rg */
	0xe2, /* ascr_Cb */
	0x12, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x0a, /* ascr_Mg */
	0xdf, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xee, /* ascr_Yr */
	0x28, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x14, /* ascr_Bg */
	0x19, /* ascr_Yb */
	0xf2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char BROWSER_NATURAL_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char BROWSER_NATURAL_1[] ={
	0xEC,
	0x02, //de cs gamma 0000
	0x00, //de_gain 10
	0x00,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x40,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x96, /* ascr_Cr */
	0xd2, /* ascr_Rr */
	0xfa, /* ascr_Cg */
	0x2a, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xdd, /* ascr_Mr */
	0x8c, /* ascr_Gr */
	0x2c, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x48, /* ascr_Gb */
	0xf2, /* ascr_Yr */
	0x34, /* ascr_Br */
	0xf2, /* ascr_Yg */
	0x1e, /* ascr_Bg */
	0x54, /* ascr_Yb */
	0xeb, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char BROWSER_MOVIE_2[] = {
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char BROWSER_MOVIE_1[] = {
	0xEC,
	0x00, // de cs cc 000
	0x00, // de_gain 10
	0x00,
	0x07, // de_maxplus 11
	0xff,
	0x07, // de_maxminus 11
	0xff,
	0x01, // CS Gain 10
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, // ascr_skin_on strength 0 00000
	0x67, // ascr_skin_cb
	0xa9, // ascr_skin_cr
	0x0c, // ascr_dist_up
	0x0c, // ascr_dist_down
	0x0c, // ascr_dist_right
	0x0c, // ascr_dist_left
	0x00, // ascr_div_up 20
	0xaa,
	0xab,
	0x00, // ascr_div_down
	0xaa,
	0xab,
	0x00, // ascr_div_right
	0xaa,
	0xab,
	0x00, // ascr_div_left
	0xaa,
	0xab,
	0xd5, // ascr_skin_Rr
	0x2c, // ascr_skin_Rg
	0x2a, // ascr_skin_Rb
	0xff, // ascr_skin_Yr
	0xf5, // ascr_skin_Yg
	0x63, // ascr_skin_Yb
	0xfe, // ascr_skin_Mr
	0x4a, // ascr_skin_Mg
	0xff, // ascr_skin_Mb
	0xff, // ascr_skin_Wr
	0xf9, // ascr_skin_Wg
	0xf8, // ascr_skin_Wb
	0x00, // ascr_Cr
	0xff, // ascr_Rr
	0xff, // ascr_Cg
	0x00, // ascr_Rg
	0xff, // ascr_Cb
	0x00, // ascr_Rb
	0xff, // ascr_Mr
	0x00, // ascr_Gr
	0x00, // ascr_Mg
	0xff, // ascr_Gg
	0xff, // ascr_Mb
	0x00, // ascr_Gb
	0xff, // ascr_Yr
	0x00, // ascr_Br
	0xff, // ascr_Yg
	0x00, // ascr_Bg
	0x00, // ascr_Yb
	0xff, // ascr_Bb
	0xff, // ascr_Wr
	0x00, // ascr_Kr
	0xff, // ascr_Wg
	0x00, // ascr_Kg
	0xff, // ascr_Wb
	0x00, // ascr_Kb
	//end
};

static char BROWSER_AUTO_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char BROWSER_AUTO_1[] = {
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x08,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, //ascr_skin_on strength 0 00000
	0x9a, //ascr_skin_cr
	0x6a, //ascr_skin_cb
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xfa, //ascr_skin_Rr
	0x38, //ascr_skin_Rg
	0x58, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char EBOOK_DYNAMIC_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char EBOOK_DYNAMIC_1[] = {
	0xEC,
	0x03, //de cs gamma 000
	0x00, //de_gain 10
	0x0a,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x20,
	0x00, //curve 1 b
	0x14, //curve 1 a
	0x00, //curve 2 b
	0x14, //curve 2 a
	0x00, //curve 3 b
	0x14, //curve 3 a
	0x00, //curve 4 b
	0x14, //curve 4 a
	0x03, //curve 5 b
	0x9a, //curve 5 a
	0x03, //curve 6 b
	0x9a, //curve 6 a
	0x03, //curve 7 b
	0x9a, //curve 7 a
	0x03, //curve 8 b
	0x9a, //curve 8 a
	0x07, //curve 9 b
	0x9e, //curve 9 a
	0x07, //curve10 b
	0x9e, //curve10 a
	0x07, //curve11 b
	0x9e, //curve11 a
	0x07, //curve12 b
	0x9e, //curve12 a
	0x0a, //curve13 b
	0xa0, //curve13 a
	0x0a, //curve14 b
	0xa0, //curve14 a
	0x0a, //curve15 b
	0xa0, //curve15 a
	0x0a, //curve16 b
	0xa0, //curve16 a
	0x16, //curve17 b
	0xa6, //curve17 a
	0x16, //curve18 b
	0xa6, //curve18 a
	0x16, //curve19 b
	0xa6, //curve19 a
	0x16, //curve20 b
	0xa6, //curve20 a
	0x05, //curve21 b
	0x21, //curve21 a
	0x0b, //curve22 b
	0x20, //curve22 a
	0x87, //curve23 b
	0x0f, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, //ascr_skin_on strength 0 00000
	0xa9, //ascr_skin_cr
	0x67, //ascr_skin_cb
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xf0, //ascr_skin_Rr
	0x58, //ascr_skin_Rg
	0x68, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x10, //ascr_Rg
	0xff, //ascr_Cb
	0x10, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char EBOOK_STANDARD_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char EBOOK_STANDARD_1[] = {
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x04,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, /* ascr_Cr */
	0xf4, /* ascr_Rr */
	0xed, /* ascr_Cg */
	0x0a, /* ascr_Rg */
	0xe2, /* ascr_Cb */
	0x12, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x0a, /* ascr_Mg */
	0xdf, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xee, /* ascr_Yr */
	0x28, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x14, /* ascr_Bg */
	0x19, /* ascr_Yb */
	0xf2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char EBOOK_NATURAL_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char EBOOK_NATURAL_1[] ={
	0xEC,
	0x02, //de cs gamma 0000
	0x00, //de_gain 10
	0x00,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x40,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x96, /* ascr_Cr */
	0xd2, /* ascr_Rr */
	0xfa, /* ascr_Cg */
	0x2a, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xdd, /* ascr_Mr */
	0x8c, /* ascr_Gr */
	0x2c, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x48, /* ascr_Gb */
	0xf2, /* ascr_Yr */
	0x34, /* ascr_Br */
	0xf2, /* ascr_Yg */
	0x1e, /* ascr_Bg */
	0x54, /* ascr_Yb */
	0xeb, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char EBOOK_MOVIE_2[] = {
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char EBOOK_MOVIE_1[] = {
	0xEC,
	0x00, // de cs cc 000
	0x00, // de_gain 10
	0x00,
	0x07, // de_maxplus 11
	0xff,
	0x07, // de_maxminus 11
	0xff,
	0x01, // CS Gain 10
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, // ascr_skin_on strength 0 00000
	0x67, // ascr_skin_cb
	0xa9, // ascr_skin_cr
	0x0c, // ascr_dist_up
	0x0c, // ascr_dist_down
	0x0c, // ascr_dist_right
	0x0c, // ascr_dist_left
	0x00, // ascr_div_up 20
	0xaa,
	0xab,
	0x00, // ascr_div_down
	0xaa,
	0xab,
	0x00, // ascr_div_right
	0xaa,
	0xab,
	0x00, // ascr_div_left
	0xaa,
	0xab,
	0xd5, // ascr_skin_Rr
	0x2c, // ascr_skin_Rg
	0x2a, // ascr_skin_Rb
	0xff, // ascr_skin_Yr
	0xf5, // ascr_skin_Yg
	0x63, // ascr_skin_Yb
	0xfe, // ascr_skin_Mr
	0x4a, // ascr_skin_Mg
	0xff, // ascr_skin_Mb
	0xff, // ascr_skin_Wr
	0xf9, // ascr_skin_Wg
	0xf8, // ascr_skin_Wb
	0x00, // ascr_Cr
	0xff, // ascr_Rr
	0xff, // ascr_Cg
	0x00, // ascr_Rg
	0xff, // ascr_Cb
	0x00, // ascr_Rb
	0xff, // ascr_Mr
	0x00, // ascr_Gr
	0x00, // ascr_Mg
	0xff, // ascr_Gg
	0xff, // ascr_Mb
	0x00, // ascr_Gb
	0xff, // ascr_Yr
	0x00, // ascr_Br
	0xff, // ascr_Yg
	0x00, // ascr_Bg
	0x00, // ascr_Yb
	0xff, // ascr_Bb
	0xff, // ascr_Wr
	0x00, // ascr_Kr
	0xff, // ascr_Wg
	0x00, // ascr_Kg
	0xff, // ascr_Wb
	0x00, // ascr_Kb
	//end
};

static char EBOOK_AUTO_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char EBOOK_AUTO_1[] = {
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf6, //ascr_Wg
	0x00, //ascr_Kg
	0xe4, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char EMAIL_AUTO_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char EMAIL_AUTO_1[] = {
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xf4, //ascr_Wg
	0x00, //ascr_Kg
	0xe4, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char HBM_CE_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char HBM_CE_1[] = {
	0xEC,
	0x02, //de cs gamma 000
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x01, //cs gain 10
	0x20,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char HBM_CE_TEXT_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char HBM_CE_TEXT_1[] = {
	0xEC,
	0x02, //de cs gamma 000
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x01, //cs gain 10
	0x20,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xff, //ascr_Cb
	0x00, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char DMB_DYNAMIC_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char DMB_DYNAMIC_1[] = {
	0xEC,
	0x07, //de cs gamma 000
	0x00, //de_gain 10
	0x0a,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x20,
	0x00, //curve 1 b
	0x14, //curve 1 a
	0x00, //curve 2 b
	0x14, //curve 2 a
	0x00, //curve 3 b
	0x14, //curve 3 a
	0x00, //curve 4 b
	0x14, //curve 4 a
	0x03, //curve 5 b
	0x9a, //curve 5 a
	0x03, //curve 6 b
	0x9a, //curve 6 a
	0x03, //curve 7 b
	0x9a, //curve 7 a
	0x03, //curve 8 b
	0x9a, //curve 8 a
	0x07, //curve 9 b
	0x9e, //curve 9 a
	0x07, //curve10 b
	0x9e, //curve10 a
	0x07, //curve11 b
	0x9e, //curve11 a
	0x07, //curve12 b
	0x9e, //curve12 a
	0x0a, //curve13 b
	0xa0, //curve13 a
	0x0a, //curve14 b
	0xa0, //curve14 a
	0x0a, //curve15 b
	0xa0, //curve15 a
	0x0a, //curve16 b
	0xa0, //curve16 a
	0x16, //curve17 b
	0xa6, //curve17 a
	0x16, //curve18 b
	0xa6, //curve18 a
	0x16, //curve19 b
	0xa6, //curve19 a
	0x16, //curve20 b
	0xa6, //curve20 a
	0x05, //curve21 b
	0x21, //curve21 a
	0x0b, //curve22 b
	0x20, //curve22 a
	0x87, //curve23 b
	0x0f, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, //ascr_skin_on strength 0 00000
	0xa9, //ascr_skin_cr
	0x67, //ascr_skin_cb
	0x37, //ascr_dist_up
	0x29, //ascr_dist_down
	0x19, //ascr_dist_right
	0x47, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x25,
	0x3d,
	0x00, //ascr_div_down
	0x31,
	0xf4,
	0x00, //ascr_div_right
	0x51,
	0xec,
	0x00, //ascr_div_left
	0x1c,
	0xd8,
	0xf0, //ascr_skin_Rr
	0x58, //ascr_skin_Rg
	0x68, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xf4, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xff, //ascr_Rr
	0xff, //ascr_Cg
	0x10, //ascr_Rg
	0xff, //ascr_Cb
	0x10, //ascr_Rb
	0xff, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xff, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x00, //ascr_Br
	0xff, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char DMB_STANDARD_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char DMB_STANDARD_1[] = {
	0xEC,
	0x04, //de cs gamma 000
	0x00, //de_gain 10
	0x04,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, /* ascr_Cr */
	0xf4, /* ascr_Rr */
	0xed, /* ascr_Cg */
	0x0a, /* ascr_Rg */
	0xe2, /* ascr_Cb */
	0x12, /* ascr_Rb */
	0xff, /* ascr_Mr */
	0x00, /* ascr_Gr */
	0x0a, /* ascr_Mg */
	0xdf, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x00, /* ascr_Gb */
	0xee, /* ascr_Yr */
	0x28, /* ascr_Br */
	0xef, /* ascr_Yg */
	0x14, /* ascr_Bg */
	0x19, /* ascr_Yb */
	0xf2, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char DMB_NATURAL_2[] ={
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};
static char DMB_NATURAL_1[] ={
	0xEC,
	0x06, //de cs gamma 0000
	0x00, //de_gain 10
	0x04,
	0x00, //de_maxplus 11
	0x40,
	0x00, //de_maxminus 11
	0x40,
	0x01, //cs gain 10
	0x40,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x96, /* ascr_Cr */
	0xd2, /* ascr_Rr */
	0xfa, /* ascr_Cg */
	0x2a, /* ascr_Rg */
	0xef, /* ascr_Cb */
	0x29, /* ascr_Rb */
	0xdd, /* ascr_Mr */
	0x8c, /* ascr_Gr */
	0x2c, /* ascr_Mg */
	0xff, /* ascr_Gg */
	0xe8, /* ascr_Mb */
	0x48, /* ascr_Gb */
	0xf2, /* ascr_Yr */
	0x34, /* ascr_Br */
	0xf2, /* ascr_Yg */
	0x1e, /* ascr_Bg */
	0x54, /* ascr_Yb */
	0xeb, /* ascr_Bb */
	0xff, /* ascr_Wr */
	0x00, /* ascr_Kr */
	0xfa, /* ascr_Wg */
	0x00, /* ascr_Kg */
	0xef, /* ascr_Wb */
	0x00, /* ascr_Kb */
	//end
};

static char DMB_MOVIE_2[] = {
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char DMB_MOVIE_1[] = {
	0xEC,
	0x00, // de cs cc 000
	0x00, // de_gain 10
	0x00,
	0x07, // de_maxplus 11
	0xff,
	0x07, // de_maxminus 11
	0xff,
	0x01, // CS Gain 10
	0x83,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x30, // ascr_skin_on strength 0 00000
	0x67, // ascr_skin_cb
	0xa9, // ascr_skin_cr
	0x0c, // ascr_dist_up
	0x0c, // ascr_dist_down
	0x0c, // ascr_dist_right
	0x0c, // ascr_dist_left
	0x00, // ascr_div_up 20
	0xaa,
	0xab,
	0x00, // ascr_div_down
	0xaa,
	0xab,
	0x00, // ascr_div_right
	0xaa,
	0xab,
	0x00, // ascr_div_left
	0xaa,
	0xab,
	0xd5, // ascr_skin_Rr
	0x2c, // ascr_skin_Rg
	0x2a, // ascr_skin_Rb
	0xff, // ascr_skin_Yr
	0xf5, // ascr_skin_Yg
	0x63, // ascr_skin_Yb
	0xfe, // ascr_skin_Mr
	0x4a, // ascr_skin_Mg
	0xff, // ascr_skin_Mb
	0xff, // ascr_skin_Wr
	0xf9, // ascr_skin_Wg
	0xf8, // ascr_skin_Wb
	0x00, // ascr_Cr
	0xff, // ascr_Rr
	0xff, // ascr_Cg
	0x00, // ascr_Rg
	0xff, // ascr_Cb
	0x00, // ascr_Rb
	0xff, // ascr_Mr
	0x00, // ascr_Gr
	0x00, // ascr_Mg
	0xff, // ascr_Gg
	0xff, // ascr_Mb
	0x00, // ascr_Gb
	0xff, // ascr_Yr
	0x00, // ascr_Br
	0xff, // ascr_Yg
	0x00, // ascr_Bg
	0x00, // ascr_Yb
	0xff, // ascr_Bb
	0xff, // ascr_Wr
	0x00, // ascr_Kr
	0xff, // ascr_Wg
	0x00, // ascr_Kg
	0xff, // ascr_Wb
	0x00, // ascr_Kb
	//end
};

static char DMB_AUTO_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0f, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char DMB_AUTO_1[] = {
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x08,
	0x00, //de_maxplus 11
	0xa0,
	0x00, //de_maxminus 11
	0xa0,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x9a, //ascr_skin_cr
	0x6a, //ascr_skin_cb
	0x25, //ascr_dist_up
	0x1a, //ascr_dist_down
	0x16, //ascr_dist_right
	0x2a, //ascr_dist_left
	0x00, //ascr_div_up 20
	0x37,
	0x5a,
	0x00, //ascr_div_down
	0x4e,
	0xc5,
	0x00, //ascr_div_right
	0x5d,
	0x17,
	0x00, //ascr_div_left
	0x30,
	0xc3,
	0xff, //ascr_skin_Rr
	0x38, //ascr_skin_Rg
	0x58, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xf0, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xd8, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xd9, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0xe0, //ascr_Rr
	0xff, //ascr_Cg
	0x00, //ascr_Rg
	0xf6, //ascr_Cb
	0x00, //ascr_Rb
	0xd8, //ascr_Mr
	0x3b, //ascr_Gr
	0x00, //ascr_Mg
	0xff, //ascr_Gg
	0xd9, //ascr_Mb
	0x00, //ascr_Gb
	0xff, //ascr_Yr
	0x14, //ascr_Br
	0xf9, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0xff, //ascr_Bb
	0xff, //ascr_Wr
	0x00, //ascr_Kr
	0xff, //ascr_Wg
	0x00, //ascr_Kg
	0xff, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

static char CURTAIN_2[] = {
	//start
	0xEB,
	0x01, //mdnie_en
	0x00, //RGB_IF_Type mask 00 000
	0x0c, //scr_roi 1 scr algo_roi 1 algo 00 1 0 00 1 0
};

static char CURTAIN_1[] = {
	0xEC,
	0x00, //de cs gamma 000
	0x00, //de_gain 10
	0x00,
	0x07, //de_maxplus 11
	0xff,
	0x07, //de_maxminus 11
	0xff,
	0x01, //cs gain 10
	0x00,
	0x00, //curve 1 b
	0x20, //curve 1 a
	0x00, //curve 2 b
	0x20, //curve 2 a
	0x00, //curve 3 b
	0x20, //curve 3 a
	0x00, //curve 4 b
	0x20, //curve 4 a
	0x00, //curve 5 b
	0x20, //curve 5 a
	0x00, //curve 6 b
	0x20, //curve 6 a
	0x00, //curve 7 b
	0x20, //curve 7 a
	0x00, //curve 8 b
	0x20, //curve 8 a
	0x00, //curve 9 b
	0x20, //curve 9 a
	0x00, //curve10 b
	0x20, //curve10 a
	0x00, //curve11 b
	0x20, //curve11 a
	0x00, //curve12 b
	0x20, //curve12 a
	0x00, //curve13 b
	0x20, //curve13 a
	0x00, //curve14 b
	0x20, //curve14 a
	0x00, //curve15 b
	0x20, //curve15 a
	0x00, //curve16 b
	0x20, //curve16 a
	0x00, //curve17 b
	0x20, //curve17 a
	0x00, //curve18 b
	0x20, //curve18 a
	0x00, //curve19 b
	0x20, //curve19 a
	0x00, //curve20 b
	0x20, //curve20 a
	0x00, //curve21 b
	0x20, //curve21 a
	0x00, //curve22 b
	0x20, //curve22 a
	0x00, //curve23 b
	0x20, //curve23 a
	0x00, //curve24 b
	0xFF, //curve24 a
	0x00, //ascr_skin_on strength 0 00000
	0x67, //ascr_skin_cb
	0xa9, //ascr_skin_cr
	0x0c, //ascr_dist_up
	0x0c, //ascr_dist_down
	0x0c, //ascr_dist_right
	0x0c, //ascr_dist_left
	0x00, //ascr_div_up 20
	0xaa,
	0xab,
	0x00, //ascr_div_down
	0xaa,
	0xab,
	0x00, //ascr_div_right
	0xaa,
	0xab,
	0x00, //ascr_div_left
	0xaa,
	0xab,
	0xff, //ascr_skin_Rr
	0x00, //ascr_skin_Rg
	0x00, //ascr_skin_Rb
	0xff, //ascr_skin_Yr
	0xff, //ascr_skin_Yg
	0x00, //ascr_skin_Yb
	0xff, //ascr_skin_Mr
	0x00, //ascr_skin_Mg
	0xff, //ascr_skin_Mb
	0xff, //ascr_skin_Wr
	0xff, //ascr_skin_Wg
	0xff, //ascr_skin_Wb
	0x00, //ascr_Cr
	0x00, //ascr_Rr
	0x00, //ascr_Cg
	0x00, //ascr_Rg
	0x00, //ascr_Cb
	0x00, //ascr_Rb
	0x00, //ascr_Mr
	0x00, //ascr_Gr
	0x00, //ascr_Mg
	0x00, //ascr_Gg
	0x00, //ascr_Mb
	0x00, //ascr_Gb
	0x00, //ascr_Yr
	0x00, //ascr_Br
	0x00, //ascr_Yg
	0x00, //ascr_Bg
	0x00, //ascr_Yb
	0x00, //ascr_Bb
	0x00, //ascr_Wr
	0x00, //ascr_Kr
	0x00, //ascr_Wg
	0x00, //ascr_Kg
	0x00, //ascr_Wb
	0x00, //ascr_Kb
	//end
};

#define MDNIE_SET(id)	\
{							\
	.name		= #id,				\
	.update_flag	= {0, 1, 2, 0},			\
	.seq		= {				\
		{	.cmd = LEVEL_UNLOCK,	.len = ARRAY_SIZE(LEVEL_UNLOCK),	.sleep = 0,},	\
		{	.cmd = id##_1,		.len = ARRAY_SIZE(id##_1),		.sleep = 0,},	\
		{	.cmd = id##_2,		.len = ARRAY_SIZE(id##_2),		.sleep = 0,},	\
		{	.cmd = LEVEL_LOCK,	.len = ARRAY_SIZE(LEVEL_LOCK),		.sleep = 0,},	\
	}	\
}

struct mdnie_table bypass_table[BYPASS_MAX] = {
	[BYPASS_ON] = MDNIE_SET(BYPASS)
};

struct mdnie_table accessibility_table[ACCESSIBILITY_MAX] = {
	[NEGATIVE] = MDNIE_SET(NEGATIVE),
	MDNIE_SET(COLOR_BLIND),
	MDNIE_SET(CURTAIN),
	MDNIE_SET(GRAYSCALE),
	MDNIE_SET(GRAYSCALE_NEGATIVE)
};


struct mdnie_table hbm_table[HBM_MAX] = {
	[HBM_ON] = MDNIE_SET(HBM_CE),
	MDNIE_SET(HBM_CE_TEXT),
};

static struct mdnie_table dmb_table[MODE_MAX] = {
	MDNIE_SET(DMB_DYNAMIC),
	MDNIE_SET(DMB_STANDARD),
	MDNIE_SET(DMB_NATURAL),
	MDNIE_SET(DMB_MOVIE),
	MDNIE_SET(DMB_AUTO),
	MDNIE_SET(EBOOK_AUTO)
};

struct mdnie_table main_table[SCENARIO_MAX][MODE_MAX] = {
	/*
		DYNAMIC_MODE
		STANDARD_MODE
		NATURAL_MODE
		MOVIE_MODE
		AUTO_MODE
		READING_MODE
	*/
	// UI_APP
	{
		MDNIE_SET(UI_DYNAMIC),
		MDNIE_SET(UI_STANDARD),
		MDNIE_SET(UI_NATURAL),
		MDNIE_SET(UI_MOVIE),
		MDNIE_SET(UI_AUTO),
		MDNIE_SET(EBOOK_AUTO),
	},
	// VIDEO_APP
	{
		MDNIE_SET(VIDEO_DYNAMIC),
		MDNIE_SET(VIDEO_STANDARD),
		MDNIE_SET(VIDEO_NATURAL),
		MDNIE_SET(VIDEO_MOVIE),
		MDNIE_SET(VIDEO_AUTO),
		MDNIE_SET(EBOOK_AUTO),
	},
	// VIDEO_WARM_APP
	{
		MDNIE_SET(VIDEO_WARM),
		MDNIE_SET(VIDEO_WARM),
		MDNIE_SET(VIDEO_WARM),
		MDNIE_SET(VIDEO_WARM),
		MDNIE_SET(VIDEO_WARM),
		MDNIE_SET(VIDEO_WARM),
	},
	// VIDEO_COLD_APP
	{
		MDNIE_SET(VIDEO_COLD),
		MDNIE_SET(VIDEO_COLD),
		MDNIE_SET(VIDEO_COLD),
		MDNIE_SET(VIDEO_COLD),
		MDNIE_SET(VIDEO_COLD),
		MDNIE_SET(VIDEO_COLD),
	},
	// CAMERA_APP
	{
		MDNIE_SET(CAMERA_DYNAMIC),
		MDNIE_SET(CAMERA_STANDARD),
		MDNIE_SET(CAMERA_NATURAL),
		MDNIE_SET(CAMERA_MOVIE),
		MDNIE_SET(CAMERA_AUTO),
		MDNIE_SET(EBOOK_AUTO),
	},

	// GALLERY_APP
	[GALLERY_MODE] = {
		MDNIE_SET(GALLERY_DYNAMIC),
		MDNIE_SET(GALLERY_STANDARD),
		MDNIE_SET(GALLERY_NATURAL),
		MDNIE_SET(GALLERY_MOVIE),
		MDNIE_SET(GALLERY_AUTO),
		MDNIE_SET(EBOOK_AUTO),
	},
	// VT_APP
	{
		MDNIE_SET(VT_DYNAMIC),
		MDNIE_SET(VT_STANDARD),
		MDNIE_SET(VT_NATURAL),
		MDNIE_SET(VT_MOVIE),
		MDNIE_SET(VT_AUTO),
		MDNIE_SET(EBOOK_AUTO),
	},
	// BROWSER_APP
	{
		MDNIE_SET(BROWSER_DYNAMIC),
		MDNIE_SET(BROWSER_STANDARD),
		MDNIE_SET(BROWSER_NATURAL),
		MDNIE_SET(BROWSER_MOVIE),
		MDNIE_SET(BROWSER_AUTO),
		MDNIE_SET(EBOOK_AUTO),
	},
	// eBOOK_APP
	{
		MDNIE_SET(EBOOK_DYNAMIC),
		MDNIE_SET(EBOOK_STANDARD),
		MDNIE_SET(EBOOK_NATURAL),
		MDNIE_SET(EBOOK_MOVIE),
		MDNIE_SET(EBOOK_AUTO),
		MDNIE_SET(EBOOK_AUTO),
	},
	// EMAIL_APP
	{
		MDNIE_SET(EMAIL_AUTO),
		MDNIE_SET(EMAIL_AUTO),
		MDNIE_SET(EMAIL_AUTO),
		MDNIE_SET(EMAIL_AUTO),
		MDNIE_SET(EMAIL_AUTO),
		MDNIE_SET(EBOOK_AUTO),
	},
};
#undef MDNIE_SET

static struct mdnie_tune tune_info = {
	.bypass_table = bypass_table,
	.accessibility_table = accessibility_table,
	.hbm_table = hbm_table,
	.dmb_table = dmb_table,
	.main_table = main_table,

	.coordinate_table = coordinate_data,
	.scr_info = &scr_info,
	.color_offset = {color_offset_f1, color_offset_f2, color_offset_f3, color_offset_f4}
};

#endif
