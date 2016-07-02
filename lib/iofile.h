#ifndef _IOFILE_H_
#define _IOFILE_H_

/* Self-defined types */

/* Declarations */
void printBase(void*, long, int);
void *readFile(const char*, long*);
int writeFile(const char*, void*, long);

#endif
