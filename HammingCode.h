//
// Created by Esteban Agüero Pérez  on 9/3/17.
//
#include "BaseConverter.h"
#include <vector>
#ifndef TEST_HAMMINGCODE_H
#define TEST_HAMMINGCODE_H

/**
 * Makes the Hamming's table
 * @param data
 */
void tabla1(string data);

/**
 * Makes the Hamming's verification table
 * @param data
 * @param veri
 */
void tabla2(string data,string veri);

/**
 * Si es paridad par = 0
 * Si es paridad impar =1
 * @param code
 * @param paridad
 * @return
 */
string toHamming(string code, bool paridad);

/**
 * Verify a string with parity bits and returns the number of the bit with the error
 * @param data
 * @param paridad
 * @return
 */
string verifyHamming(string data,bool paridad);

/**
 * Returns the original HEX number from binary Hamming encode
 * @param data
 * @param paridad
 * @return
 */
string fromHamming(string data, bool paridad);

#endif //TEST_HAMMINGCODE_H
