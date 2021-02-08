// RAM
// © 2020-2021 Patrick Lafarguette

#ifndef RAM_H_
#define RAM_H_

#include "Bus.h"

// http://pcbjunkie.net/index.php/resources/ram-info-and-cross-reference-page/

// https://www.c64-wiki.com/wiki/RAM

// http://www.minuszerodegrees.net/memory/4164.htm
// http://www.minuszerodegrees.net/memory/41256.htm

enum {
	SIGNAL_CS,
	SIGNAL_RAS,
	SIGNAL_CAS,
	SIGNAL_WE, // /W
	SIGNAL_OE, // /G
	SIGNAL_GND, // VSS
	SIGNAL_VCC, // +5V
	SIGNAL_VBB, // -5V
	SIGNAL_VDD, // +12V
	SIGNAL_COUNT
};

enum {
	BUS_ADDRESS,
	BUS_RAS = 0,
	BUS_CAS,
	BUS_D,
	BUS_Q,
	BUS_LOW,
	BUS_HIGH,
	BUS_COUNT,
};

typedef struct RAM {
	uint8_t count;
	int8_t signals[SIGNAL_COUNT];
	Bus bus[BUS_COUNT];
	void (*idle)();
	void (*fill)(const bool alternate);
	void (*write_address)(Bus& bus);
} RAM;

RAM ram;

const char* RAM_BUS[BUS_COUNT] = { "row", "column", "d", "q", "low", "high" };

#endif /* RAM_H_ */
