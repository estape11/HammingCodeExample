//
// Created by Esteban Agüero Pérez  on 9/3/17.
//
#include <iostream>
#include <math.h>

#ifndef TEST_BASECONVERTER_H
#define TEST_BASECONVERTER_H

using namespace std;

/**
 * Inverts the input string
 * @param str
 * @return
 */
string invertirString(string str);

/**
 * Converts the DECIMAL number to Binary
 * @param num
 * @return
 */
string toBinary(int num);

/**
 * Converts the HEX number to Binary
 * @param num
 * @return
 */
string toBinary(string num);

/**
 * Check if the input is power of two
 * @param num
 * @return
 */
bool potenciaDos(int num);

/**
 * Converts the BIN number to decimal
 * @param num
 * @return
 */
int toDecimal(string num);

/**
 * Converts the BIN number to Hexadecimal
 * @param num
 * @return
 */
string toHex(string num);

/**
 * Checks idf a number is binary
 * @param num
 * @return
 */
bool checkBin(string num);

#endif //TEST_BASECONVERTER_H
