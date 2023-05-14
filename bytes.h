#ifndef BYTES_H
#define BYTES_H

typedef struct _2_s 	{ char	_[2];  } _2_s_t;
typedef struct _4_s 	{ char	_[4];  } _4_s_t;
typedef struct _8_s 	{ char	_[8];  } _8_s_t;
typedef struct _16_s	{ char	_[16]; } _16_s_t;
typedef struct _32_s	{ char	_[32]; } _32_s_t;
typedef struct _64_s	{ char	_[64]; } _64_s_t;

typedef union bytes2_u{
	_2_s_t _;
	short s;
	char c;
} bytes2;

typedef union bytes4_u{
	_4_s_t _;
	int i;
	char c;
	float f;
	long l;
} bytes4;

typedef union bytes8_u{
	_8_s_t _;
	int i;
	char c;
	float f;
	double d;
	long l;
	long long ll;
	void* p;
} bytes8;

typedef union bytes16_u{
	_16_s_t _;
	int i;
	char c;
	float f;
	double d;
	long l;
	long long ll;
	void* p;
} bytes16;

typedef union bytes32_u{
	_32_s_t _;
	int i;
	char c;
	float f;
	double d;
	long l;
	long long ll;
	void* p;
} bytes32;

typedef union bytes64_u{
	_64_s_t _;
	int i;
	char c;
	float f;
	double d;
	long l;
	long long ll;
	void* p;
} bytes64;

typedef bytes8 bytes;

#endif