/*
	AES
*/

#ifndef VECTOR_H
#define VECTOR_H

#include "stddef.h"




typedef struct ByteVector ByteVector;


ByteVector*	 	ByteVector_New(unsigned int length);
void			ByteVector_Del(ByteVector* vec);

unsigned int            ByteVector_GetLength(ByteVector* vec); 

void			ByteVector_SetIndex(ByteVector* vec, unsigned int pos, unsigned char value);
unsigned char           ByteVector_GetIndex(ByteVector* vec, unsigned int pos);

void			ByteVector_SetValues(ByteVector* vec, const unsigned char* values, size_t valuesLength);      // copy bytes from bytearray to vector
void                    ByteVector_GetValues(ByteVector* vec, unsigned char* toWrite, size_t amount);

void                    ByteVector_Copy(ByteVector* vec, ByteVector* copyto);   // copy values from first parameter into second

void                    ByteVector_Add(ByteVector* vec, ByteVector* other,
                        unsigned char (*AddFunction)(unsigned char val1, unsigned char val2));       // add both input vectors and store result in first input vector
unsigned char           ByteVector_Dot(ByteVector* vec, ByteVector* other, 
                        unsigned char (*AddFunction)(unsigned char val1, unsigned char val2), 
                        unsigned char (*MultiplyFunction)(unsigned char val1, unsigned char val2));  // perform dot product with both input vectors and return result

void                    ByteVector_Shift(ByteVector* vec, unsigned int amount);     // cyclically shifts the vectors values in the +index direction




#endif
