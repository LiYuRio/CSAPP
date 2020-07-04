/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int not_and_result = ~(x & y);
  int or_result = ~(~x & ~y);
  return or_result & not_and_result;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  int val = ~0;
  val = val << 31;
  return val;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int val =  x + 1;
  int xor = x ^ val;
  int result = ~xor;
  return !result & !!(~x);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int val1 = x;
  int val2 = x >> 8;
  int val3 = x >> 16;
  int val4 = x >> 24;
  int result = (val1 & val2 & val3 & val4 & 0xFF) | 0x55;
  return !(~result & 0xFF);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int val1 = !((x ^ 0x8) & 0xF);
  int val2 = !((x ^ 0x9) & 0xF);
  int val3 = !((x >> 3) & 0x1);
  int val4 = !((x >> 4) ^ 0x3);
  int result = (val1 | val2 | val3) & val4;
  return result;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int flag = !x;
  flag = ~flag + 1;
  return (flag & z) | (~flag & y);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int x_sign = x >> 31;
  int y_sign = y >> 31;
  int sign_equal = !(x_sign ^ y_sign);
  int tmin = 1 << 31; 
  int x_is_tmin = !(tmin ^ x);
  int neg_x = ~x + 1;
  int sum = neg_x + y;
  int sign = sum >> 31;
  int result = (!(sign & 0x1)) & sign_equal & (!x_is_tmin);
  return  x_is_tmin | result | ((!sign_equal) & !(y_sign & 0x1));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int is_tmin = (x >> 31) & 0x1; 
  int neg_x = ~x + 1;
  int result = ((neg_x ^ x) >> 31) & 0x1;
  return (~result) & 0x1 & (~is_tmin);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int val1 = x & 0xFF;
  int val2 = (x >> 8) & 0xFF;
  int val3 = (x >> 16) & 0xFF;
  int val4 = (x >> 24) & 0xFF;
  int is_equal4 = (!val4) | (!(val4 ^ 0xFF));
  int is_equal3 = (!(val4 ^ val3)) & is_equal4;
  int is_equal2 = (!(val3 ^ val2)) & is_equal3; 
  int is_equal1 = (!(val2 ^ val1)) & is_equal2;  
  int flag1 = ~(!is_equal1) + 1;
  int flag2 = ~(!is_equal2) + 1; 
  int flag3 = ~(!is_equal3) + 1;
  int flag4 = ~(!is_equal4) + 1; 
  int count = ((flag1 & 0) | (~flag1 & 8));
  int highest = ~((x >> 31) & 0x1) + 1;
  count = count + ((flag2 & 0) | (~flag2 & 8));
  count = count + ((flag3 & 0) | (~flag3 & 8));
  count = count + ((flag4 & 0) | (~flag4 & 8));
  count = ~count + 25;
  val3 = ~(count >> 31);
  count = val3 & count;
  val1 = (x >> count) & 0xFF;
  flag1 = (val1 ^ highest) & 0xFF;
  val2 = !flag1;
  val2 = val2 + !(flag1 >> 1);
  val2 = val2 + !(flag1 >> 2);
  val2 = val2 + !(flag1 >> 3);
  val2 = val2 + !(flag1 >> 4);
  val2 = val2 + !(flag1 >> 5);
  val2 = val2 + !(flag1 >> 6);
  val2 = val2 + !(flag1 >> 7);
  val2 = 10 + ~val2;
  count = count + val2;
  return count;
  // flag1 = (!x) | !(~x); 
  // flag1 = ~flag1 + 1;
  // return (flag1 & 0x1) | (~flag1 & count);
  // printf("%d %d\n", val2, count);
  // flag2 = (flag1 >> 7) & 0x1;
  // tmp_count = tmp_count + flag2;
  // flag2 = (flag1 >> 6) & 0x1 & flag2;
  // tmp_count = tmp_count + flag2;
  // flag2 = (flag1 >> 5) & 0x1 & flag2;
  // tmp_count = tmp_count + flag2;
  // flag2 = (flag1 >> 4) & 0x1 & flag2;
  // tmp_count = tmp_count + flag2;
  // flag2 = (flag1 >> 3) & 0x1 & flag2;
  // tmp_count = tmp_count + flag2;
  // flag2 = (flag1 >> 2) & 0x1 & flag2;
  // tmp_count = tmp_count + flag2;
  // flag2 = (flag1 >> 1) & 0x1 & flag2;
  // tmp_count = tmp_count + flag2;
  // flag2 = flag1 & 0x1 & flag2;
  // tmp_count = tmp_count + flag2;
  // flag1 = !(((val1 >> 7) & 0x1) ^ highest);
  // tmp_count = tmp_count + flag1;
  // flag1 = (!(((val1 >> 6) & 0x1) ^ highest)) & flag1;
  // tmp_count = tmp_count + flag1;
  // flag1 = (!(((val1 >> 5) & 0x1) ^ highest)) & flag1;
  // tmp_count = tmp_count + flag1;
  // flag1 = (!(((val1 >> 4) & 0x1) ^ highest)) & flag1;
  // tmp_count = tmp_count + flag1;
  // flag1 = (!(((val1 >> 3) & 0x1) ^ highest)) & flag1;
  // tmp_count = tmp_count + flag1;
  // flag1 = (!(((val1 >> 2) & 0x1) ^ highest)) & flag1;
  // tmp_count = tmp_count + flag1;
  // flag1 = (!(((val1 >> 1) & 0x1) ^ highest)) & flag1;
  // tmp_count = tmp_count + flag1;
  // flag1 = (!(val1 & 0x1) ^ highest) & flag1;
  // tmp_count = tmp_count + flag1; 
  // tmp_count = 8 - tmp_count + 1;
  // // printf("%d %d %d, %x\n", count, neg_count, tmp_count, x);
  // count = neg_count + tmp_count;
  // flag = (!x) | !(~x); 
  // flag = ~flag + 1;
  // return (flag & 0x1) | (~flag & count);
  // return 32;

  // int is_zero = !x;
  // int is_ones = !(~x);
  // int flag = !(is_ones | is_zero);
  // int count = flag;
  // int val = (x >> 1);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 2); 
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 3);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 4);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 5);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 6);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 7);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 8);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 9);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 10);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 11);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 12);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 13);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 14);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 15);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 16);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 17);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 18);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 19);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 20);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 21);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 22);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 23);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 24);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 25);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 26);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 27);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 28);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 29);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 30);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // val = (x >> 31);
  // is_zero = !val;
  // is_ones = !(~val);
  // flag = !(is_ones | is_zero);
  // count = count + flag;
  // return count + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  return 2;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  return 2;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
