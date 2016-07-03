#ifndef _IOFILE_H_
#define _IOFILE_H_

/* Print BUFFER in bases */
void printBase(const void *buffer, long size, int base);

/* Read file & return data in BUFFER
 @return (void*)
 */
void *readFile(const char *fileName, long *bufferSize);

/* Write file from BUFFER to file 
 @return 0 if failed to create file, 1 if successful
 */
int writeFile(const char *fileName, void *buffer, long bufferSize);

#endif
