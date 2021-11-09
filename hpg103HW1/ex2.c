#include <stdio.h>
#include <stdlib.h>

int add(int num1[], int num2[], int res[]) {
  int loop, i, carrybit = 0, val, signR, sign1 = num1[0], sign2 = num2[0]; //sign1 is sign bit of num1, sign 2 is sign bit of num2, and signR is the sign bit of the result
  //first we simulate the 'adding'
  for (i = 3; i >= 0; i--) { //since we are reading in 4 bit binary numbers..
    val = carrybit + num1[i] + num2[i]; //val = total # of bits including carry bit; used to 
    //compute the sum
    if (val > 1) {
      val = val - 2;
      carrybit = 1; //make carry bit '1'
    } else {
      carrybit = 0; //...otherwise no value is carried.
    }
    res[i] = val; //fill the result array with all the bits accumulated bits so far 
    //including the carry bit.
  }
  signR = res[0]; //the sign bit of the result is the 0th index of the resulting array of 
  //binary numbers
  if (sign1 != signR && sign1 == sign2) { //if sign bit of the first number does not equal the
    //sign bit of the result and the sign bits of the two numbers to be added are not equal...
    return 1; //then there is an overflow and we return 1...
  } else {
    return 0; //otherwise we return 0.
  }
}
int main() {
  int num1[4] = {0};
  int num2[4] = {0};
  int res[4];
  int i = 3, j = 3, num, digit, if_overflow;
  printf("num1 = "); //prompt the user to input the values of num1 array
  scanf("%d", & num); //scan for each value of num1 array

  //break the input number to get each individual bit and store in array num1.
  while (num) {
    digit = num % 10;
    num1[i--] = digit;
    num = num / 10;
  }

  printf("num2 = "); //prompt the user to input the values of num2 array
  scanf("%d", & num); //scan for each value of num2 array

  //break the input number to get each individual bit and store in array num2.
  while (num) {
    digit = num % 10;
    num2[j--] = digit;
    num = num / 10;
  }

  if_overflow = add(num1, num2, res); //if_overflow is linked to the add(function).. which has 
  //the logic for the overflow checking implemented within it.
  printf("res = ");
  for (i = 0; i < 4; i++) {
    printf("%d", res[i]); //here we loop through the array to print out the result.
  }
  if (if_overflow == 1) { //if_overflow equals 1 logically if 1 is returned by the add function.
    printf("\n1(overflow)");
  } else {
    printf("\n0 (no overflow)"); //otherwise we print to stdout that there is no overflow 
    //detected.
  }
  return 0;
}
