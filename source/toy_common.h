#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TOY_VERSION_MAJOR 0
#define TOY_VERSION_MINOR 6
#define TOY_VERSION_PATCH 5
#define TOY_VERSION_BUILD __DATE__ " " __TIME__

//NOTE: I don't know why the time headers are here, need to try moving them back to the correct spots again
//platform exports/imports
#if defined(__linux__)
#define TOY_API extern
#include <time.h>
#include <sys/time.h>

#elif defined(_WIN32) || defined(WIN32)
#define TOY_API
#include <time.h>
#include <sys/time.h>

#else
#define TOY_API
#include <time.h>
#include <sys/time.h>

#endif

#ifndef TOY_EXPORT
//for processing the command line arguments
typedef struct {
	bool error;
	bool help;
	bool version;
	char* binaryfile;
	char* sourcefile;
	char* compilefile;
	char* outfile; //defaults to out.tb
	char* source;
	bool verbose;
} Command;

extern Command command;

void initCommand(int argc, const char* argv[]);

void usageCommand(int argc, const char* argv[]);
void helpCommand(int argc, const char* argv[]);
void copyrightCommand(int argc, const char* argv[]);
#endif

//NOTE: assigning to a byte from a short loses data
#define AS_USHORT(value) (*(unsigned short*)(&(value)))
