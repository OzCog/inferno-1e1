#include <lib9.h>
#include <image.h>

/*
 * Special version of lucidasans/lsr.18, modified so the rectangle
 * is an integral number of words wide.
 */
uchar
defontdata[]=
{
	0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x30,0x20,0x20,0x20,0x20,0x20,
	0x20,0x20,0x20,0x20,0x20,0x20,0x30,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
	0x20,0x20,0x30,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x32,0x30,0x34,0x38,0x20,
	0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x31,0x39,0x20,0x01,0xf0,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xe0,0x03,0x80,0x38,0x01,0xd0,0x19,0x80,0x70,0x00,0x00,0x00,0x00,0x38,
	0x03,0x81,0xc0,0xcc,0xe1,0xc7,0x66,0x00,0x00,0x3a,0x00,0xe0,0x01,0xc0,0x07,0x00,
	0x3a,0x01,0x98,0x00,0x00,0x00,0x01,0xc0,0x03,0x80,0x38,0x03,0x30,0x07,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xfc,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x30,0x06,0x00,0x6c,0x02,0xe0,0x19,0x80,0x98,0x00,0x00,0x00,0x00,0x0c,
	0x06,0x03,0x60,0xcc,0x33,0x0d,0xe6,0x00,0x00,0x5c,0x00,0x30,0x03,0x00,0x0d,0x80,
	0x5c,0x01,0x98,0x00,0x00,0x00,0x00,0x60,0x06,0x00,0x6c,0x03,0x30,0x0c,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x36,
	0x00,0x00,0x10,0x00,0x00,0x00,0x18,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xc8,0x07,0x80,
	0x00,0x00,0x08,0x00,0x30,0x00,0x00,0x03,0x00,0x00,0xe0,0x00,0x60,0x06,0x18,0x60,
	0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0xe6,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0d,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x03,0x36,
	0x06,0x60,0x7c,0x38,0x00,0xf8,0x18,0x42,0x02,0x00,0x00,0x00,0x00,0x00,0x20,0xf8,
	0x03,0x01,0xf8,0x3f,0x00,0x18,0x3f,0xc0,0xf0,0x7f,0xc1,0xf0,0x1f,0x00,0x00,0x00,
	0x00,0x00,0x00,0x7c,0x07,0xe0,0x06,0x03,0xf8,0x0f,0xc3,0xfc,0x0f,0xe3,0xf8,0x1f,
	0x86,0x06,0x18,0x61,0x83,0x18,0x07,0x03,0x86,0x02,0x03,0xc0,0x7f,0x01,0xe0,0x3f,
	0x81,0xf3,0xff,0xcc,0x18,0xc0,0xcc,0x00,0xcc,0x19,0x81,0x9f,0xf3,0x08,0x01,0x80,
	0x00,0x00,0x10,0x00,0x30,0x00,0x00,0x03,0x00,0x01,0x80,0x00,0x60,0x06,0x18,0x60,
	0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0x86,0x18,0x00,0x00,0x04,0x00,0xf0,0x00,0x18,0x19,0x87,
	0xe0,0x66,0x01,0xf0,0x1e,0x00,0x00,0x00,0x00,0x07,0x80,0xf8,0x48,0x00,0x1e,0x1e,
	0x03,0x80,0x00,0x1f,0xc0,0x00,0x00,0x01,0x87,0x80,0x03,0x80,0xc7,0x03,0x07,0x01,
	0x80,0x00,0x60,0x03,0x00,0x18,0x00,0xc0,0x06,0x00,0x30,0x00,0x7f,0x81,0xf8,0x7f,
	0x1f,0xc7,0xf1,0xfc,0x61,0x86,0x18,0x7f,0x81,0x80,0x80,0xf0,0x03,0xc0,0x0f,0x00,
	0x3c,0x00,0xf0,0x00,0x00,0x3d,0x86,0x0c,0x30,0x61,0x83,0x0c,0x18,0xc0,0xc6,0x00,
	0x46,0x0e,0x00,0xe0,0x70,0x1d,0x19,0x81,0xc0,0x00,0x00,0x00,0x38,0x03,0x81,0xc1,
	0x98,0xe0,0xe7,0x66,0x0f,0x03,0xa0,0x70,0x03,0x80,0xe0,0x1d,0x06,0x60,0x00,0x00,
	0x00,0xe0,0x07,0x00,0x70,0x19,0x80,0x70,0xc0,0x0c,0xc0,0x00,0x18,0x1f,0x03,0x24,
	0x06,0x60,0x96,0x6c,0x21,0x8c,0x08,0xc3,0x02,0x00,0x00,0x00,0x00,0x00,0x61,0x8c,
	0x1f,0x03,0x1c,0x63,0x80,0x38,0x3f,0xc3,0x98,0x7f,0xc3,0x18,0x31,0x80,0x00,0x00,
	0x00,0x00,0x00,0xce,0x1c,0x38,0x06,0x03,0x1c,0x38,0xe3,0x07,0x0c,0x03,0x00,0x71,
	0xc6,0x06,0x18,0x61,0x86,0x18,0x07,0x03,0x87,0x02,0x0e,0x70,0x63,0x87,0x38,0x31,
	0xc3,0x38,0x18,0x0c,0x18,0xc0,0xcc,0x30,0xcc,0x19,0x81,0x9f,0xf3,0x0c,0x01,0x80,
	0x80,0x00,0x18,0x00,0x30,0x00,0x00,0x03,0x00,0x03,0x00,0x00,0x60,0x00,0x00,0x60,
	0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0x86,0x18,0x00,0x00,0x04,0x01,0x19,0x00,0x58,0x19,0x8e,
	0x30,0x66,0x06,0x0c,0x33,0x00,0x00,0x00,0x00,0x08,0x40,0xf8,0x48,0x00,0x33,0x33,
	0x06,0x00,0x00,0x3e,0x40,0x00,0x00,0x07,0x8c,0xc0,0x01,0x81,0x83,0x06,0x09,0x83,
	0x00,0x00,0x60,0x03,0x00,0x18,0x00,0xc0,0x06,0x00,0x30,0x00,0xf0,0x07,0x1c,0x60,
	0x18,0x06,0x01,0x80,0x61,0x86,0x18,0x60,0xe1,0xc0,0x83,0x9c,0x0e,0x70,0x39,0xc0,
	0xe7,0x03,0x9c,0x00,0x00,0xe7,0x06,0x0c,0x30,0x61,0x83,0x0c,0x18,0xc0,0xc6,0x00,
	0xc6,0x03,0x01,0x80,0xd8,0x2e,0x19,0x82,0x60,0x00,0x00,0x00,0x0c,0x06,0x03,0x61,
	0x98,0x31,0x8d,0xe6,0x3b,0x05,0xc0,0x18,0x06,0x01,0xb0,0x2e,0x06,0x60,0x00,0x00,
	0x00,0x30,0x0c,0x00,0xd8,0x19,0x80,0xc0,0xc0,0x0c,0xc0,0x00,0x18,0x0f,0x03,0x24,
	0x06,0x61,0x90,0x44,0x61,0x8c,0x10,0x81,0x12,0x40,0x00,0x00,0x00,0x00,0x41,0x04,
	0x03,0x00,0x0c,0x01,0x80,0x78,0x20,0x03,0x00,0x00,0xc6,0x0c,0x60,0xc0,0x00,0x00,
	0x00,0x00,0x00,0x06,0x30,0x08,0x0f,0x03,0x0c,0x60,0x03,0x03,0x0c,0x03,0x00,0xc0,
	0x06,0x06,0x18,0x61,0x8c,0x18,0x05,0x85,0x87,0x82,0x18,0x18,0x61,0x8c,0x0c,0x30,
	0xc6,0x00,0x18,0x0c,0x18,0xc0,0xcc,0x30,0xc6,0x18,0xc3,0x00,0x33,0x04,0x01,0x81,
	0xc0,0x00,0x18,0x00,0x30,0x00,0x00,0x03,0x00,0x03,0x00,0x00,0x60,0x00,0x00,0x60,
	0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x86,0x10,0x00,0x00,0x0f,0x03,0x00,0x80,0x8c,0x31,0x8c,
	0x00,0x00,0x08,0x02,0x03,0x00,0x00,0x00,0x00,0x17,0x20,0x00,0x30,0x00,0x03,0x03,
	0x00,0x00,0x00,0x3e,0x40,0x00,0x00,0x01,0x8c,0xc0,0x01,0x83,0x03,0x0c,0x01,0x86,
	0x00,0x00,0xf0,0x07,0x80,0x3c,0x01,0xe0,0x0f,0x00,0x78,0x00,0xb0,0x0c,0x00,0x60,
	0x18,0x06,0x01,0x80,0x61,0x86,0x18,0x60,0x61,0xe0,0x86,0x06,0x18,0x18,0x60,0x61,
	0x81,0x86,0x06,0x00,0x01,0x83,0x86,0x0c,0x30,0x61,0x83,0x0c,0x18,0x61,0x86,0x00,
	0xc4,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0xb9,0x0f,0x03,0x00,
	0x04,0x41,0x90,0x44,0xc1,0x88,0x01,0x81,0x9d,0xc0,0x40,0x00,0x00,0x00,0xc3,0x06,
	0x03,0x00,0x0c,0x01,0x80,0xd8,0x20,0x06,0x00,0x01,0x86,0x0c,0x60,0xcc,0xc0,0x0c,
	0x00,0x0c,0x00,0x06,0x63,0xec,0x0b,0x03,0x0c,0x60,0x03,0x01,0x8c,0x03,0x00,0xc0,
	0x06,0x06,0x18,0x61,0x98,0x18,0x05,0x85,0x85,0x82,0x18,0x18,0x61,0x8c,0x0c,0x30,
	0xc6,0x00,0x18,0x0c,0x18,0x60,0x8c,0x78,0xc6,0x30,0x62,0x00,0x63,0x06,0x01,0x81,
	0x40,0x00,0x00,0x7c,0x37,0x00,0xf0,0x3b,0x07,0x87,0xe1,0xd8,0x6f,0x06,0x18,0x61,
	0x8c,0x37,0x9e,0x0d,0xe0,0x38,0x1b,0x80,0x76,0x19,0x9f,0x1f,0x18,0x63,0x0c,0xc0,
	0x0c,0x61,0x98,0x67,0xf8,0xc6,0x30,0x00,0x18,0x35,0x83,0x00,0x7f,0x06,0x21,0x8e,
	0x00,0x00,0x08,0x72,0x1f,0x00,0x00,0x00,0x00,0x14,0xa0,0x00,0x00,0x10,0x0e,0x0e,
	0x00,0x03,0x0c,0x3e,0x40,0x00,0x00,0x01,0x8c,0xc0,0x01,0x86,0x03,0x0c,0x07,0x0c,
	0x01,0x80,0xb0,0x05,0x80,0x2c,0x01,0x60,0x0b,0x00,0x58,0x01,0xb0,0x0c,0x00,0x60,
	0x18,0x06,0x01,0x80,0x61,0x86,0x18,0x60,0x31,0x60,0x86,0x06,0x18,0x18,0x60,0x61,
	0x81,0x86,0x06,0x00,0x01,0x85,0x86,0x0c,0x30,0x61,0x83,0x0c,0x18,0x31,0x07,0xf0,
	0xc8,0x0f,0x83,0xe0,0xf8,0x3e,0x0f,0x83,0xe0,0xfb,0xc0,0x78,0x3c,0x0f,0x03,0xc0,
	0xf0,0x61,0x86,0x18,0x1f,0x8d,0xe0,0x38,0x07,0x00,0xe0,0x1c,0x03,0x80,0x10,0x07,
	0x23,0x0c,0x30,0xc3,0x0c,0x30,0xc6,0x18,0xdc,0x18,0x60,0x00,0x3b,0xff,0x03,0x00,
	0x3f,0xf1,0xd0,0x44,0x80,0xd0,0x01,0x81,0x82,0x00,0x40,0x00,0x00,0x00,0x83,0x06,
	0x03,0x00,0x0c,0x03,0x00,0x98,0x20,0x06,0x00,0x03,0x07,0x08,0x60,0xcc,0xc0,0x38,
	0x00,0x07,0x00,0x0c,0x44,0x64,0x19,0x83,0x0c,0xc0,0x03,0x01,0x8c,0x03,0x01,0x80,
	0x06,0x06,0x18,0x61,0xb0,0x18,0x05,0x85,0x84,0xc2,0x30,0x0c,0x61,0x98,0x06,0x30,
	0xc7,0x00,0x18,0x0c,0x18,0x61,0x8c,0x59,0x83,0x20,0x66,0x00,0xc3,0x02,0x01,0x83,
	0x60,0x00,0x00,0xce,0x39,0xc3,0x98,0xe7,0x0c,0xc3,0x07,0x38,0x73,0x86,0x18,0x63,
	0x0c,0x39,0xe7,0x0e,0x70,0xee,0x1c,0xe1,0xce,0x1b,0xb1,0x8c,0x18,0x63,0x0c,0xc3,
	0x0c,0x61,0x98,0x60,0x18,0x46,0x20,0x00,0x18,0x34,0x03,0x00,0x63,0x06,0x61,0x87,
	0x80,0x00,0x10,0x81,0x33,0x0c,0xc0,0x00,0x00,0x17,0x20,0x00,0x00,0x10,0x18,0x03,
	0x00,0x03,0x0c,0x1e,0x40,0x00,0x00,0x01,0x8c,0xcc,0xc1,0x84,0x03,0x18,0x01,0x88,
	0x01,0x81,0x98,0x0c,0xc0,0x66,0x03,0x30,0x19,0x80,0xcc,0x01,0x30,0x18,0x00,0x60,
	0x18,0x06,0x01,0x80,0x61,0x86,0x18,0x60,0x31,0x30,0x8c,0x03,0x30,0x0c,0xc0,0x33,
	0x00,0xcc,0x03,0x0c,0x23,0x04,0xc6,0x0c,0x30,0x61,0x83,0x0c,0x18,0x33,0x06,0x38,
	0xd8,0x19,0xc6,0x71,0x9c,0x67,0x19,0xc6,0x71,0x9e,0x61,0xcc,0x66,0x19,0x86,0x61,
	0x98,0x61,0x86,0x18,0x73,0x8e,0x70,0xee,0x1d,0xc3,0xb8,0x77,0x0e,0xe0,0x10,0x1d,
	0xe3,0x0c,0x30,0xc3,0x0c,0x30,0xc6,0x18,0xe7,0x18,0x60,0x00,0x78,0xff,0x03,0x00,
	0x08,0x80,0xf0,0x6d,0x00,0x60,0x01,0x81,0x8d,0x80,0x40,0x00,0x00,0x00,0x83,0x06,
	0x03,0x00,0x18,0x1e,0x01,0x18,0x3e,0x06,0xf0,0x03,0x03,0xd0,0x60,0xc0,0x00,0xe0,
	0x00,0x01,0xc0,0x30,0xc8,0x64,0x11,0x83,0x18,0xc0,0x03,0x01,0x8c,0x03,0x01,0x80,
	0x06,0x06,0x18,0x61,0xe0,0x18,0x04,0xc9,0x84,0xe2,0x30,0x0c,0x61,0x98,0x06,0x31,
	0x83,0xc0,0x18,0x0c,0x18,0x61,0x86,0x59,0x81,0xc0,0x3c,0x01,0x83,0x03,0x01,0x82,
	0x20,0x00,0x00,0x06,0x30,0xc3,0x00,0xc3,0x18,0x63,0x06,0x18,0x61,0x86,0x18,0x66,
	0x0c,0x30,0xc3,0x0c,0x30,0xc6,0x18,0x61,0x86,0x1c,0x30,0x0c,0x18,0x63,0x0c,0xc3,
	0x0c,0x33,0x18,0x60,0x38,0x46,0x20,0x00,0x00,0x64,0x03,0x00,0xc1,0x83,0x40,0x05,
	0xe0,0x00,0x11,0x81,0x33,0x19,0x80,0x00,0x00,0x14,0xa0,0x00,0x00,0x10,0x30,0x33,
	0x00,0x03,0x0c,0x0e,0x40,0x00,0x00,0x01,0x8c,0xc6,0x61,0x8c,0x03,0x30,0x09,0x98,
	0x00,0x01,0x18,0x08,0xc0,0x46,0x02,0x30,0x11,0x80,0x8c,0x03,0x30,0x18,0x00,0x60,
	0x18,0x06,0x01,0x80,0x61,0x86,0x18,0x60,0x31,0x38,0x8c,0x03,0x30,0x0c,0xc0,0x33,
	0x00,0xcc,0x03,0x06,0x43,0x08,0xc6,0x0c,0x30,0x61,0x83,0x0c,0x18,0x1e,0x06,0x18,
	0xdc,0x00,0xc0,0x30,0x0c,0x03,0x00,0xc0,0x30,0x0c,0x31,0x80,0xc3,0x30,0xcc,0x33,
	0x0c,0x61,0x86,0x18,0x61,0x8c,0x30,0xc6,0x18,0xc3,0x18,0x63,0x0c,0x60,0x00,0x18,
	0xc3,0x0c,0x30,0xc3,0x0c,0x30,0xc6,0x18,0xc3,0x18,0x60,0x00,0x30,0x27,0x03,0x00,
	0x19,0x80,0x78,0x3a,0xe0,0xb1,0x81,0x81,0x88,0x80,0x40,0x00,0x00,0x01,0x83,0x06,
	0x03,0x00,0x30,0x03,0x03,0x18,0x07,0x87,0x18,0x06,0x01,0xf0,0x31,0xc0,0x03,0x80,
	0x7f,0xc0,0x70,0x60,0x98,0xc4,0x31,0x83,0xf0,0xc0,0x03,0x01,0x8f,0xc3,0xf1,0x80,
	0x07,0xfe,0x18,0x61,0xe0,0x18,0x04,0xc9,0x84,0x62,0x30,0x0c,0x63,0x18,0x06,0x3e,
	0x00,0xf0,0x18,0x0c,0x18,0x31,0x06,0xcd,0x81,0xc0,0x18,0x03,0x83,0x01,0x01,0x86,
	0x30,0x00,0x00,0x06,0x30,0x66,0x01,0x83,0x18,0x63,0x0c,0x18,0x61,0x86,0x18,0x6c,
	0x0c,0x30,0xc3,0x0c,0x31,0x83,0x18,0x33,0x06,0x18,0x38,0x0c,0x18,0x61,0x88,0x63,
	0x18,0x1a,0x0c,0x40,0x71,0x86,0x18,0x70,0x80,0x64,0x0f,0xc0,0xc1,0x81,0x80,0x0c,
	0x70,0x00,0x11,0x81,0x1d,0xb3,0x00,0x00,0x00,0x08,0x40,0x00,0x01,0xff,0x3f,0x1e,
	0x00,0x03,0x0c,0x02,0x40,0x70,0x00,0x01,0x87,0x83,0x31,0x99,0xc3,0x33,0x87,0x33,
	0x80,0x03,0x18,0x18,0xc0,0xc6,0x06,0x30,0x31,0x81,0x8c,0x02,0x3f,0x18,0x00,0x7e,
	0x1f,0x87,0xe1,0xf8,0x61,0x86,0x19,0xf8,0x31,0x18,0x8c,0x03,0x30,0x0c,0xc0,0x33,
	0x00,0xcc,0x03,0x03,0x83,0x08,0xc6,0x0c,0x30,0x61,0x83,0x0c,0x18,0x0c,0x06,0x18,
	0xce,0x00,0xc0,0x30,0x0c,0x03,0x00,0xc0,0x30,0x0c,0x33,0x00,0xc3,0x30,0xcc,0x33,
	0x0c,0x61,0x86,0x18,0xc1,0x8c,0x31,0x83,0x30,0x66,0x0c,0xc1,0x98,0x30,0x00,0x31,
	0x63,0x0c,0x30,0xc3,0x0c,0x30,0xc3,0x10,0xc1,0x8c,0x40,0x00,0x10,0x3f,0x03,0x00,
	0x19,0x80,0x3c,0x05,0xb1,0x99,0x81,0x81,0x80,0x07,0xfc,0x07,0xfc,0x01,0x03,0x06,
	0x03,0x00,0x60,0x01,0x86,0x18,0x01,0xc6,0x0c,0x0c,0x03,0x38,0x1e,0xc0,0x0e,0x00,
	0x00,0x00,0x1c,0x60,0x99,0xcc,0x20,0xc3,0x18,0xc0,0x03,0x01,0x8c,0x03,0x01,0x80,
	0xc6,0x06,0x18,0x61,0xb0,0x18,0x04,0xc9,0x84,0x32,0x30,0x0c,0x7c,0x18,0x06,0x33,
	0x00,0x38,0x18,0x0c,0x18,0x33,0x06,0x8d,0x01,0xc0,0x18,0x03,0x03,0x01,0x01,0x86,
	0x30,0x00,0x00,0x7e,0x30,0x66,0x01,0x83,0x1f,0xe3,0x0c,0x18,0x61,0x86,0x18,0x78,
	0x0c,0x30,0xc3,0x0c,0x31,0x83,0x18,0x33,0x06,0x18,0x1c,0x0c,0x18,0x61,0x98,0x65,
	0x98,0x1c,0x0c,0xc0,0xe0,0x46,0x20,0x9c,0x90,0x64,0x03,0x00,0xc1,0x87,0xe0,0x0c,
	0x30,0x00,0x11,0x81,0x00,0x66,0x07,0xfc,0xff,0x07,0x80,0x00,0x00,0x10,0x00,0x00,
	0x00,0x03,0x0c,0x02,0x40,0x70,0x00,0x00,0x00,0x01,0x98,0x32,0xc0,0x64,0xc0,0x65,
	0x81,0x82,0x0c,0x10,0x60,0x83,0x04,0x18,0x20,0xc1,0x06,0x06,0x30,0x18,0x00,0x60,
	0x18,0x06,0x01,0x80,0x61,0x86,0x18,0x60,0x31,0x0c,0x8c,0x03,0x30,0x0c,0xc0,0x33,
	0x00,0xcc,0x03,0x01,0x03,0x10,0xc6,0x0c,0x30,0x61,0x83,0x0c,0x18,0x0c,0x06,0x18,
	0xc6,0x0f,0xc3,0xf0,0xfc,0x3f,0x0f,0xc3,0xf0,0xff,0xf3,0x00,0xff,0x3f,0xcf,0xf3,
	0xfc,0x61,0x86,0x18,0xc1,0x8c,0x31,0x83,0x30,0x66,0x0c,0xc1,0x98,0x31,0xff,0x32,
	0x63,0x0c,0x30,0xc3,0x0c,0x30,0xc3,0x30,0xc1,0x8c,0xc0,0x00,0x10,0xee,0x01,0x00,
	0x7f,0xe0,0x2e,0x09,0x13,0x0d,0x01,0x81,0x80,0x00,0x40,0x00,0x00,0x03,0x03,0x06,
	0x03,0x00,0xc0,0x01,0x8c,0x18,0x00,0xc6,0x0c,0x0c,0x06,0x1c,0x00,0xc0,0x03,0x80,
	0x00,0x00,0x70,0x60,0xda,0xd8,0x7f,0xc3,0x0c,0xc0,0x03,0x01,0x8c,0x03,0x01,0x80,
	0xc6,0x06,0x18,0x61,0x98,0x18,0x04,0x71,0x84,0x3a,0x30,0x0c,0x60,0x18,0x06,0x31,
	0x80,0x18,0x18,0x0c,0x18,0x33,0x06,0x8d,0x02,0x60,0x18,0x06,0x03,0x01,0x81,0x8c,
	0x18,0x00,0x00,0xc6,0x30,0x66,0x01,0x83,0x18,0x03,0x0c,0x18,0x61,0x86,0x18,0x6c,
	0x0c,0x30,0xc3,0x0c,0x31,0x83,0x18,0x33,0x06,0x18,0x07,0x0c,0x18,0x61,0x98,0x65,
	0x90,0x0e,0x0c,0xc1,0xc0,0x46,0x20,0x87,0x18,0x64,0x03,0x00,0x63,0x01,0x80,0x0e,
	0x30,0x00,0x10,0xc1,0x00,0x66,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,
	0x00,0x03,0x0c,0x02,0x40,0x70,0x00,0x00,0x00,0x01,0x98,0x24,0xc0,0xc0,0xc0,0x49,
	0x81,0x87,0xfc,0x3f,0xe1,0xff,0x0f,0xf8,0x7f,0xc3,0xfe,0x07,0xf0,0x18,0x00,0x60,
	0x18,0x06,0x01,0x80,0x61,0x86,0x18,0x60,0x31,0x0e,0x8c,0x03,0x30,0x0c,0xc0,0x33,
	0x00,0xcc,0x03,0x03,0x83,0x20,0xc6,0x0c,0x30,0x61,0x83,0x0c,0x18,0x0c,0x06,0x30,
	0xc7,0x18,0xc6,0x31,0x8c,0x63,0x18,0xc6,0x31,0x8c,0x03,0x00,0xc0,0x30,0x0c,0x03,
	0x00,0x61,0x86,0x18,0xc1,0x8c,0x31,0x83,0x30,0x66,0x0c,0xc1,0x98,0x30,0x00,0x32,
	0x63,0x0c,0x30,0xc3,0x0c,0x30,0xc3,0x30,0xc1,0x8c,0xc0,0x00,0x10,0x6f,0x00,0x00,
	0x11,0x00,0x26,0x19,0x13,0x06,0x01,0x81,0x80,0x00,0x40,0x00,0x00,0x02,0x03,0x06,
	0x03,0x01,0x80,0x01,0x8f,0xfe,0x00,0xc6,0x0c,0x18,0x06,0x0c,0x00,0x80,0x00,0xe0,
	0x7f,0xc1,0xc0,0x00,0x4c,0xf0,0x60,0xc3,0x0c,0x60,0x03,0x03,0x0c,0x03,0x00,0xc0,
	0xc6,0x06,0x18,0x61,0x8c,0x18,0x04,0x71,0x84,0x1a,0x18,0x18,0x60,0x0c,0x0c,0x31,
	0x80,0x18,0x18,0x0c,0x18,0x1a,0x03,0x8f,0x06,0x30,0x18,0x0c,0x03,0x00,0x81,0x8c,
	0x18,0x00,0x01,0x86,0x30,0x66,0x01,0x83,0x18,0x03,0x0c,0x18,0x61,0x86,0x18,0x66,
	0x0c,0x30,0xc3,0x0c,0x31,0x83,0x18,0x33,0x06,0x18,0x03,0x8c,0x18,0x60,0xd0,0x68,
	0xd0,0x16,0x06,0x83,0x80,0xc6,0x30,0x00,0x18,0x64,0x02,0x00,0x7f,0x07,0xe1,0x87,
	0xa0,0x00,0x08,0x72,0x00,0x33,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x03,0x0c,0x02,0x40,0x00,0x00,0x00,0x00,0x03,0x30,0x6c,0xc1,0x81,0x80,0xd9,
	0x81,0x86,0x0c,0x30,0x61,0x83,0x0c,0x18,0x60,0xc3,0x06,0x0c,0x30,0x0c,0x00,0x60,
	0x18,0x06,0x01,0x80,0x61,0x86,0x18,0x60,0x61,0x06,0x86,0x06,0x18,0x18,0x60,0x61,
	0x81,0x86,0x06,0x04,0xc1,0xa1,0x86,0x0c,0x30,0x61,0x83,0x0c,0x18,0x0c,0x07,0xe0,
	0xc3,0x30,0xcc,0x33,0x0c,0xc3,0x30,0xcc,0x33,0x0c,0x03,0x00,0xc0,0x30,0x0c,0x03,
	0x00,0x61,0x86,0x18,0xc1,0x8c,0x31,0x83,0x30,0x66,0x0c,0xc1,0x98,0x30,0x00,0x34,
	0x63,0x0c,0x30,0xc3,0x0c,0x30,0xc1,0xa0,0xc1,0x86,0x80,0x00,0x10,0x7f,0x00,0x00,
	0x33,0x00,0x26,0x31,0x13,0x07,0x01,0x81,0x80,0x00,0x40,0x00,0x00,0x06,0x01,0x04,
	0x03,0x03,0x00,0x01,0x80,0x18,0x00,0xc6,0x0c,0x18,0x06,0x0c,0x01,0x80,0x00,0x38,
	0x00,0x07,0x00,0x00,0x60,0x00,0x40,0x63,0x0c,0x70,0x03,0x03,0x0c,0x03,0x00,0xe0,
	0xc6,0x06,0x18,0x61,0x86,0x18,0x04,0x21,0x84,0x0e,0x18,0x18,0x60,0x0c,0x0c,0x30,
	0xc0,0x18,0x18,0x06,0x30,0x1e,0x03,0x06,0x0c,0x30,0x18,0x18,0x03,0x00,0xc1,0x8c,
	0x18,0x00,0x01,0x86,0x30,0xc3,0x00,0xc3,0x1c,0x03,0x06,0x38,0x61,0x86,0x18,0x63,
	0x0c,0x30,0xc3,0x0c,0x30,0xc6,0x18,0x61,0x86,0x18,0x01,0x8c,0x18,0x60,0xd0,0x38,
	0xf0,0x33,0x07,0x87,0x00,0x86,0x10,0x00,0x18,0x35,0x84,0x00,0x80,0x81,0x81,0x81,
	0xe0,0x00,0x08,0x02,0x00,0x19,0x80,0x04,0x00,0x00,0x00,0x00,0x01,0xff,0x00,0x00,
	0x00,0x03,0x0c,0x02,0x40,0x00,0x00,0x00,0x00,0x06,0x60,0xcf,0xe1,0x82,0x01,0x9f,
	0xc3,0x04,0x06,0x20,0x31,0x01,0x88,0x0c,0x40,0x62,0x03,0x08,0x30,0x0e,0x00,0x60,
	0x18,0x06,0x01,0x80,0x61,0x86,0x18,0x60,0x61,0x03,0x86,0x06,0x18,0x18,0x60,0x61,
	0x81,0x86,0x06,0x08,0x61,0xc1,0x83,0x18,0x18,0xc0,0xc6,0x06,0x30,0x0c,0x06,0x00,
	0xc3,0x30,0xcc,0x33,0x0c,0xc3,0x30,0xcc,0x33,0x0e,0x01,0x80,0xe0,0x38,0x0e,0x03,
	0x80,0x61,0x86,0x18,0x63,0x0c,0x30,0xc6,0x18,0xc3,0x18,0x63,0x0c,0x60,0x10,0x18,
	0xc3,0x0c,0x30,0xc3,0x0c,0x30,0xc1,0xe0,0xc3,0x07,0x80,0x00,0x00,0xfc,0x03,0x00,
	0x33,0x01,0xa4,0x21,0xb1,0x8d,0x80,0x81,0x00,0x00,0x40,0xc0,0x00,0xc4,0x01,0x8c,
	0x03,0x03,0xfc,0x63,0x80,0x18,0x31,0xc3,0x18,0x30,0x03,0x18,0x63,0x0c,0xc0,0x0c,
	0x00,0x0c,0x00,0x60,0x38,0x00,0xc0,0x63,0x1c,0x38,0xe3,0x0e,0x0c,0x03,0x00,0x70,
	0xc6,0x06,0x18,0x61,0x83,0x18,0x04,0x21,0x84,0x0e,0x0e,0x70,0x60,0x07,0x38,0x30,
	0x67,0x30,0x18,0x07,0x70,0x0c,0x03,0x06,0x0c,0x18,0x18,0x1f,0xf3,0x00,0x41,0x80,
	0x00,0x00,0x01,0xce,0x39,0xc3,0x98,0xe7,0x0e,0x63,0x03,0xd8,0x61,0x86,0x18,0x61,
	0x8c,0x30,0xc3,0x0c,0x30,0xee,0x1c,0xe1,0xce,0x18,0x31,0x8c,0x1c,0xe0,0x60,0x30,
	0x60,0x61,0x83,0x06,0x01,0x86,0x18,0x00,0x18,0x1f,0x0f,0xf9,0x00,0x41,0x81,0x80,
	0x70,0x00,0x06,0x0c,0x00,0x0c,0xc0,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x03,0x9c,0x02,0x40,0x00,0x00,0x00,0x00,0x0c,0xc1,0x80,0xc3,0x07,0xc3,0x01,
	0x8c,0x0c,0x06,0x60,0x33,0x01,0x98,0x0c,0xc0,0x66,0x03,0x18,0x30,0x07,0x1c,0x60,
	0x18,0x06,0x01,0x80,0x61,0x86,0x18,0x61,0xc1,0x03,0x83,0x9c,0x0e,0x70,0x39,0xc0,
	0xe7,0x03,0x9c,0x00,0x00,0xe7,0x03,0xb8,0x1d,0xc0,0xee,0x07,0x70,0x0c,0x06,0x00,
	0xc3,0x39,0xce,0x73,0x9c,0xe7,0x39,0xce,0x73,0x9f,0x31,0xcc,0x73,0x1c,0xc7,0x31,
	0xcc,0x61,0x86,0x18,0x77,0x0c,0x30,0xee,0x1d,0xc3,0xb8,0x77,0x0e,0xe0,0x10,0x3d,
	0xc3,0x9c,0x39,0xc3,0x9c,0x39,0xc0,0xc0,0xe7,0x03,0x00,0x00,0x00,0x3c,0x03,0x00,
	0x33,0x00,0xf8,0x00,0xe0,0xf0,0xc0,0xc3,0x00,0x00,0x00,0xc0,0x00,0xcc,0x00,0xf8,
	0x03,0x03,0xfc,0x3f,0x00,0x18,0x1f,0x81,0xf0,0x30,0x01,0xf0,0x3e,0x0c,0xc0,0x00,
	0x00,0x00,0x00,0x60,0x0f,0xc0,0xc0,0x63,0xf8,0x0f,0xc3,0xf8,0x0f,0xe3,0x00,0x1f,
	0xc6,0x06,0x18,0x61,0x81,0x9f,0xc4,0x01,0x84,0x06,0x03,0xc0,0x60,0x01,0xe0,0x30,
	0x63,0xe0,0x18,0x01,0xc0,0x0c,0x03,0x06,0x0c,0x18,0x18,0x1f,0xf3,0x00,0x61,0x80,
	0x00,0x00,0x00,0xf3,0x37,0x00,0xf0,0x3b,0x07,0xc3,0x00,0x18,0x61,0x86,0x18,0x60,
	0xcc,0x30,0xc3,0x0c,0x30,0x38,0x1b,0x80,0x76,0x18,0x1f,0x07,0x0f,0x60,0x60,0x30,
	0x60,0x61,0x83,0x07,0xf9,0x86,0x18,0x00,0x18,0x04,0x0f,0xf8,0x00,0x01,0x81,0x80,
	0x30,0x00,0x01,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x03,0xec,0x02,0x40,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0xc6,0x07,0xc6,0x01,
	0x98,0x0c,0x06,0x60,0x33,0x01,0x98,0x0c,0xc0,0x66,0x03,0x18,0x3f,0x81,0xf8,0x7f,
	0x1f,0xc7,0xf1,0xfc,0x61,0x86,0x18,0x7f,0x01,0x01,0x80,0xf0,0x03,0xc0,0x0f,0x00,
	0x3c,0x00,0xf0,0x00,0x01,0xbc,0x00,0xe0,0x07,0x00,0x38,0x01,0xc0,0x0c,0x06,0x00,
	0xce,0x1e,0x67,0x99,0xe6,0x79,0x9e,0x67,0x99,0xe3,0xe0,0x78,0x3e,0x0f,0x83,0xe0,
	0xf8,0x61,0x86,0x18,0x1c,0x0c,0x30,0x38,0x07,0x00,0xe0,0x1c,0x03,0x80,0x00,0x27,
	0x01,0xec,0x1e,0xc1,0xec,0x1e,0xc0,0xc0,0xdc,0x03,0x00,0x00,0x00,0x38,0x00,0x00,
	0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x42,0x00,0x00,0x00,0x40,0x00,0x08,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x21,0x80,
	0x01,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x18,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x02,0x00,0x01,0x86,0x18,0x00,0x18,0x04,0x00,0x00,0x00,0x00,0x01,0x8c,
	0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x03,0x00,0x02,0x40,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0x02,0x00,0x00,0x01,0xf8,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x24,0x00,0x00,0x00,0x80,0x00,0x08,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x03,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xc0,0x27,0x80,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x30,0x00,0x00,0x30,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x06,0x00,0x00,0xe6,0x70,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x01,0x87,
	0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x03,0x00,0x02,0x40,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x1c,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0xc0,0x06,0x00,0x00,0x00,0xf8,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xe0,0x00,0x00,0x60,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x03,0x00,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x0f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0xc0,0x06,0x00,0x00,0x20,0x20,0x20,0x20,
	0x20,0x20,0x20,0x20,0x32,0x35,0x36,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
	0x20,0x31,0x39,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x31,0x35,0x20,
	0x00,0x00,0x00,0x13,0x00,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,
	0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,
	0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
	0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,
	0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,
	0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
	0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,
	0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,
	0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
	0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,
	0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,
	0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
	0x10,0x00,0x0f,0x10,0x00,0x05,0x15,0x00,0x03,0x10,0x00,0x04,0x19,0x00,0x02,0x06,
	0x00,0x07,0x20,0x00,0x03,0x10,0x00,0x0c,0x2c,0x00,0x02,0x11,0x00,0x0c,0x38,0x00,
	0x03,0x10,0x00,0x0d,0x45,0x00,0x03,0x10,0x00,0x0d,0x52,0x00,0x02,0x06,0x00,0x04,
	0x56,0x00,0x02,0x12,0x00,0x06,0x5c,0x00,0x02,0x12,0x00,0x06,0x62,0x00,0x03,0x0a,
	0x00,0x09,0x6b,0x00,0x06,0x0f,0x00,0x0c,0x77,0x00,0x0e,0x12,0x00,0x04,0x7b,0x00,
	0x0a,0x0b,0x00,0x0c,0x87,0x00,0x0e,0x10,0x00,0x04,0x8b,0x00,0x02,0x12,0x00,0x09,
	0x94,0x00,0x03,0x10,0x00,0x0c,0xa0,0x00,0x03,0x10,0x00,0x0c,0xac,0x00,0x03,0x10,
	0x00,0x0c,0xb8,0x00,0x03,0x10,0x00,0x0b,0xc3,0x00,0x03,0x10,0x00,0x0c,0xcf,0x00,
	0x03,0x10,0x00,0x0c,0xdb,0x00,0x03,0x10,0x00,0x0c,0xe7,0x00,0x03,0x10,0x00,0x0c,
	0xf3,0x00,0x03,0x10,0x00,0x0c,0xff,0x00,0x03,0x10,0x00,0x0c,0x0b,0x01,0x06,0x10,
	0x00,0x04,0x0f,0x01,0x06,0x12,0x00,0x04,0x13,0x01,0x06,0x0f,0x00,0x0c,0x1f,0x01,
	0x09,0x0d,0x00,0x0c,0x2b,0x01,0x06,0x0f,0x00,0x0c,0x37,0x01,0x03,0x10,0x00,0x08,
	0x3f,0x01,0x03,0x10,0x00,0x10,0x4f,0x01,0x03,0x10,0x00,0x0d,0x5c,0x01,0x03,0x10,
	0x00,0x0b,0x67,0x01,0x03,0x10,0x00,0x0d,0x74,0x01,0x03,0x10,0x00,0x0e,0x82,0x01,
	0x03,0x10,0x00,0x0a,0x8c,0x01,0x03,0x10,0x00,0x0a,0x96,0x01,0x03,0x10,0x00,0x0d,
	0xa3,0x01,0x03,0x10,0x00,0x0e,0xb1,0x01,0x03,0x10,0x00,0x06,0xb7,0x01,0x03,0x12,
	0x00,0x06,0xbd,0x01,0x03,0x10,0x00,0x0c,0xc9,0x01,0x03,0x10,0x00,0x0a,0xd3,0x01,
	0x03,0x10,0x00,0x10,0xe3,0x01,0x03,0x10,0x00,0x0e,0xf1,0x01,0x03,0x10,0x00,0x0e,
	0xff,0x01,0x03,0x10,0x00,0x0b,0x0a,0x02,0x03,0x13,0x00,0x0e,0x18,0x02,0x03,0x10,
	0x00,0x0c,0x24,0x02,0x03,0x10,0x00,0x0a,0x2e,0x02,0x03,0x10,0x00,0x0c,0x3a,0x02,
	0x03,0x10,0x00,0x0d,0x47,0x02,0x03,0x10,0x00,0x0c,0x53,0x02,0x03,0x10,0x00,0x10,
	0x63,0x02,0x03,0x10,0x00,0x0b,0x6e,0x02,0x03,0x10,0x00,0x0c,0x7a,0x02,0x03,0x10,
	0x00,0x0b,0x85,0x02,0x02,0x12,0x00,0x06,0x8b,0x02,0x02,0x12,0x00,0x09,0x94,0x02,
	0x02,0x12,0x00,0x06,0x9a,0x02,0x04,0x0e,0x00,0x0c,0xa6,0x02,0x10,0x11,0x00,0x0c,
	0xb2,0x02,0x02,0x06,0x00,0x04,0xb6,0x02,0x06,0x10,0x00,0x0a,0xc0,0x02,0x02,0x10,
	0x00,0x0c,0xcc,0x02,0x06,0x10,0x00,0x0a,0xd6,0x02,0x02,0x10,0x00,0x0c,0xe2,0x02,
	0x06,0x10,0x00,0x0a,0xec,0x02,0x02,0x10,0x00,0x07,0xf3,0x02,0x06,0x13,0x00,0x0c,
	0xff,0x02,0x02,0x10,0x00,0x0c,0x0b,0x03,0x02,0x10,0x00,0x06,0x11,0x03,0x02,0x13,
	0x00,0x06,0x17,0x03,0x02,0x10,0x00,0x0b,0x22,0x03,0x02,0x10,0x00,0x06,0x28,0x03,
	0x06,0x10,0x00,0x12,0x3a,0x03,0x06,0x10,0x00,0x0c,0x46,0x03,0x06,0x10,0x00,0x0b,
	0x51,0x03,0x06,0x13,0x00,0x0c,0x5d,0x03,0x06,0x13,0x00,0x0c,0x69,0x03,0x06,0x10,
	0x00,0x08,0x71,0x03,0x06,0x10,0x00,0x09,0x7a,0x03,0x04,0x10,0x00,0x07,0x81,0x03,
	0x06,0x10,0x00,0x0c,0x8d,0x03,0x06,0x10,0x00,0x0a,0x97,0x03,0x06,0x10,0x00,0x10,
	0xa7,0x03,0x06,0x10,0x00,0x0b,0xb2,0x03,0x06,0x13,0x00,0x0a,0xbc,0x03,0x06,0x10,
	0x00,0x0a,0xc6,0x03,0x02,0x12,0x00,0x06,0xcc,0x03,0x02,0x12,0x00,0x04,0xd0,0x03,
	0x02,0x12,0x00,0x06,0xd6,0x03,0x09,0x0c,0x00,0x0c,0xe2,0x03,0x00,0x00,0x00,0x00,
	0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,
	0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,
	0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,
	0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,
	0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,
	0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,
	0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,
	0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,
	0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,
	0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,
	0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,
	0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x00,0x00,0x00,0x00,
	0xe2,0x03,0x00,0x00,0x00,0x00,0xe2,0x03,0x06,0x13,0x00,0x04,0xe6,0x03,0x03,0x11,
	0x00,0x0c,0xf2,0x03,0x03,0x10,0x00,0x0c,0xfe,0x03,0x04,0x0f,0x00,0x0c,0x0a,0x04,
	0x03,0x10,0x00,0x0c,0x16,0x04,0x02,0x12,0x00,0x04,0x1a,0x04,0x03,0x12,0x00,0x0c,
	0x26,0x04,0x03,0x05,0x00,0x0b,0x31,0x04,0x03,0x10,0x00,0x10,0x41,0x04,0x03,0x0a,
	0x00,0x08,0x49,0x04,0x07,0x0f,0x00,0x0a,0x53,0x04,0x0a,0x0f,0x00,0x0c,0x5f,0x04,
	0x0a,0x0b,0x00,0x0a,0x69,0x04,0x03,0x0b,0x00,0x0c,0x75,0x04,0x03,0x05,0x00,0x0b,
	0x80,0x04,0x02,0x06,0x00,0x05,0x85,0x04,0x06,0x0e,0x00,0x0c,0x91,0x04,0x03,0x0a,
	0x00,0x08,0x99,0x04,0x03,0x0a,0x00,0x08,0xa1,0x04,0x03,0x05,0x00,0x0b,0xac,0x04,
	0x06,0x13,0x00,0x0c,0xb8,0x04,0x03,0x12,0x00,0x0c,0xc4,0x04,0x09,0x0c,0x00,0x0c,
	0xd0,0x04,0x10,0x13,0x00,0x0b,0xdb,0x04,0x03,0x0a,0x00,0x08,0xe3,0x04,0x03,0x0a,
	0x00,0x08,0xeb,0x04,0x07,0x0f,0x00,0x0a,0xf5,0x04,0x03,0x10,0x00,0x0f,0x04,0x05,
	0x03,0x10,0x00,0x0f,0x13,0x05,0x03,0x10,0x00,0x10,0x23,0x05,0x06,0x13,0x00,0x08,
	0x2b,0x05,0x00,0x10,0x00,0x0d,0x38,0x05,0x00,0x10,0x00,0x0d,0x45,0x05,0x00,0x10,
	0x00,0x0d,0x52,0x05,0x00,0x10,0x00,0x0d,0x5f,0x05,0x00,0x10,0x00,0x0d,0x6c,0x05,
	0x00,0x10,0x00,0x0d,0x79,0x05,0x03,0x10,0x00,0x11,0x8a,0x05,0x03,0x13,0x00,0x0d,
	0x97,0x05,0x00,0x10,0x00,0x0a,0xa1,0x05,0x00,0x10,0x00,0x0a,0xab,0x05,0x00,0x10,
	0x00,0x0a,0xb5,0x05,0x00,0x10,0x00,0x0a,0xbf,0x05,0x00,0x10,0x00,0x06,0xc5,0x05,
	0x00,0x10,0x00,0x06,0xcb,0x05,0x00,0x10,0x00,0x06,0xd1,0x05,0x00,0x10,0x00,0x06,
	0xd7,0x05,0x03,0x10,0x00,0x0e,0xe5,0x05,0x00,0x10,0x00,0x0e,0xf3,0x05,0x00,0x10,
	0x00,0x0e,0x01,0x06,0x00,0x10,0x00,0x0e,0x0f,0x06,0x00,0x10,0x00,0x0e,0x1d,0x06,
	0x00,0x10,0x00,0x0e,0x2b,0x06,0x00,0x10,0x00,0x0e,0x39,0x06,0x07,0x0e,0x00,0x0c,
	0x45,0x06,0x02,0x11,0x00,0x0e,0x53,0x06,0x00,0x10,0x00,0x0d,0x60,0x06,0x00,0x10,
	0x00,0x0d,0x6d,0x06,0x00,0x10,0x00,0x0d,0x7a,0x06,0x00,0x10,0x00,0x0d,0x87,0x06,
	0x00,0x10,0x00,0x0c,0x93,0x06,0x03,0x10,0x00,0x0b,0x9e,0x06,0x02,0x10,0x00,0x0b,
	0xa9,0x06,0x03,0x10,0x00,0x0a,0xb3,0x06,0x03,0x10,0x00,0x0a,0xbd,0x06,0x03,0x10,
	0x00,0x0a,0xc7,0x06,0x03,0x10,0x00,0x0a,0xd1,0x06,0x03,0x10,0x00,0x0a,0xdb,0x06,
	0x03,0x10,0x00,0x0a,0xe5,0x06,0x06,0x10,0x00,0x10,0xf5,0x06,0x06,0x13,0x00,0x0a,
	0xff,0x06,0x03,0x10,0x00,0x0a,0x09,0x07,0x03,0x10,0x00,0x0a,0x13,0x07,0x03,0x10,
	0x00,0x0a,0x1d,0x07,0x03,0x10,0x00,0x0a,0x27,0x07,0x03,0x10,0x00,0x06,0x2d,0x07,
	0x03,0x10,0x00,0x06,0x33,0x07,0x03,0x10,0x00,0x06,0x39,0x07,0x03,0x10,0x00,0x06,
	0x3f,0x07,0x01,0x10,0x00,0x0b,0x4a,0x07,0x03,0x10,0x00,0x0c,0x56,0x07,0x03,0x10,
	0x00,0x0b,0x61,0x07,0x03,0x10,0x00,0x0b,0x6c,0x07,0x03,0x10,0x00,0x0b,0x77,0x07,
	0x03,0x10,0x00,0x0b,0x82,0x07,0x03,0x10,0x00,0x0b,0x8d,0x07,0x06,0x0f,0x00,0x0c,
	0x99,0x07,0x06,0x10,0x00,0x0b,0xa4,0x07,0x03,0x10,0x00,0x0c,0xb0,0x07,0x03,0x10,
	0x00,0x0c,0xbc,0x07,0x03,0x10,0x00,0x0c,0xc8,0x07,0x03,0x10,0x00,0x0c,0xd4,0x07,
	0x03,0x13,0x00,0x0a,0xde,0x07,0x03,0x13,0x00,0x0c,0xea,0x07,0x03,0x13,0x00,0x0a,
	0xf4,0x07,0x00,0x00,0x00,0x00,
	/* pad: */ 0x00, 0x00, 0x00
};

Subfont*
getdefont(Display *d)
{
	char *hdr, *p;
	int n;
	Fontchar *fc;
	Subfont *f;
	int ld;
	Rectangle r;
	Image *i;

	/*
	 * make sure data is word-aligned.  this is true with Plan 9 compilers
	 * but not in general.  the byte order is right because the data is
	 * declared as char*, not ulong*.
	 */
	p = (char*)defontdata;
	n = (ulong)p & 3;
	if(n != 0){
		memmove(p+(4-n), p, sizeof defontdata - n);
		p += 4-n;
	}
	ld = atoi(p+0*12);
	r.min.x = atoi(p+1*12);
	r.min.y = atoi(p+2*12);
	r.max.x = atoi(p+3*12);
	r.max.y = atoi(p+4*12);
	/* build image by hand, using existing data. */
	i = allocimage(d, r, ld, 0, 0);
	if(i == 0)
		return 0;

	p += 5*12;
	n = loadimage(i, r, (uchar*)p, (defontdata+sizeof defontdata)-(uchar*)p);
	if(n < 0){
		freeimage(i);
		return 0;
	}

	hdr = p+n;
	n = atoi(hdr);
	p = hdr+3*12;
	fc = malloc(sizeof(Fontchar)*(n+1));
	if(fc == 0){
		freeimage(i);
		return 0;
	}
	_unpackinfo(fc, (uchar*)p, n);
	f = allocsubfont("*default*", n, atoi(hdr+12), atoi(hdr+24), fc, i);
	if(f == 0){
		freeimage(i);
		free(fc);
		return 0;
	}
	return f;
}