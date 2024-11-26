/******************
Name: Darmostuk Aleksandr
ID: 345758676
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
  while (1) {
    printf("Choose an option:\n\t1. Happy Face\n\t2. Balanced Number\n\t3. "
           "Generous Number\n\t4. Circle Of Joy\n\t5. Happy Numbers\n\t6. "
           "Festival Of Laughter\n\t7. Exit\n");
    int option;
    int num = scanf("%d", &option);
    while (num != 1 || option < 1 || option > 7) {

      printf("This option is not available, please try again.\n");
      printf("Choose an option:\n\t1. Happy Face\n\t2. Balanced Number\n\t3. "
             "Generous Number\n\t4. Circle Of Joy\n\t5. Happy Numbers\n\t6. "
             "Festival Of Laughter\n\t7. Exit\n");
      int num = scanf("%d", &option);
      // Consume the remainder of the line
    }

    // Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
    /* Example:
     * n = 3:
     * 0   0
     *   o
     * \___/
     */
    // 1. Happy Face
    if (option == 1) {
      // Read face symbols
      char eye, nose, mouth;
      printf("Enter symbols for the eyes, node, and mouth:\n");
      scanf(" %c %c %c", &eye, &nose, &mouth);

      // Read face size
      int size;
      printf("Enter face size:\n");
      num = scanf("%d", &size);
      while (num != 1 || size < 1 || size % 2 != 1) {
        printf("The face's size must be an odd and positive number, please try "
               "again:\n");
        num = scanf("%d", &size);
      }
      int lineLength = size + 2;

      // Print the eyes
      printf("%c", eye);
      for (int i = 0; i < size; ++i) {
        printf(" ");
      }
      printf("%c\n", eye);

      // Print the nose
      for (int i = 0; i < lineLength / 2; ++i) {
        printf(" ");
      }
      printf("%c", nose);
      for (int i = 0; i < lineLength / 2; ++i) {
        printf(" ");
      }
      printf("\n");

      // Print the mouth
      printf("\\");
      for (int i = 0; i < size; ++i) {
        printf("%c", mouth);
      }
      printf("/\n");

      // Next command
      continue;
    }

    // Case 2: determine whether the sum of all digits to the left of the middle
    // digit(s) and the sum of all digits to the right of the middle digit(s)
    // are equal
    /* Examples:
    Balanced: 1533, 450810, 99
    Not blanced: 1552, 34
    Please notice: the number has to be bigger than 0.
    */
    // 2. Balanced Number
    if (option == 2) {
      // Get the number
      int number;
      printf("Enter a number:\n");
      int num = scanf("%d", &number);
      while (num != 1 || number < 1) {
        printf("Only positive number is allowed, please try again:\n");
        num = scanf("%d", &number);
      }

      // Determine the digit count
      int digitCount = 0;
      for (int number_copy = number; number_copy; number_copy /= 10) {
        ++digitCount;
      }

      // Compute the sum of lower half of digits and store the middle digit, if
      // digit_count is odd
      int middleDigit = 0;
      int lowerSum = 0;
      for (int i = 0; i < digitCount / 2 + digitCount % 2; ++i) {
        lowerSum += number % 10;
        if (digitCount % 2 == 1 && i == digitCount / 2) {
          middleDigit = number % 10;
        }
        number /= 10;
      }

      // Compute the sum of higher half of digits
      int higherSum = middleDigit;
      for (; number; number /= 10) {
        higherSum += number % 10;
      }

      // Print the result
      if (higherSum == lowerSum) {
        printf("This number is balanced and brings harmony!\n");
      } else {
        printf("This number isn't balanced and destroys harmony.\n");
      }

      // Next command
      continue;
    }

    // Case 3: determine whether the sum of the proper divisors (of an integer)
    // is greater than the number itself
    /* Examples:
    Abudant: 12, 20, 24
    Not Abudant: 3, 7, 10
    Please notice: the number has to be bigger than 0.
    */
    // 3. Generous Number
    if (option == 3) {
      // Read the number
      printf("Enter a number:\n");
      int number;
      int num = scanf("%d", &number);
      while (num != 1 || number < 1) {
        printf("Only positive number is allowed, please try again:\n");
        num = scanf("%d", &number);
      }

      // Calculate sum of proper divisors
      // All numbers are divisible by 1, so don't bother checking it
      int divisorSum = 1;
      for (int divisor = 2; divisor <= number / 2; ++divisor) {
        if (number % divisor == 0) {
          divisorSum += divisor;
        }
      }

      // Print the result
      if (divisorSum > number) {
        printf("This number is generous!\n");
      } else {
        printf("This number does not share.\n");
      }

      // Next command
      continue;
    }

    // Case 4: determine wether a number is a prime.
    /* Examples:
    This one brings joy: 3, 5, 11
    This one does not bring joy: 15, 8, 99
    Please notice: the number has to be bigger than 0.
    */
    // 4. Circle of Joy
    if (option == 4) {
      // Read the number
      int number;
      printf("Enter a number:\n");
      int num = scanf("%d", &number);
      while (num != 1 || number < 1) {
        printf("Only positive number is allowed, please try again:\n");
        num = scanf("%d", &number);
      }

      // Immediately check for 1
      if (number == 1) {
        printf("The circle remains incomplete.\n");

        // Next command
        continue;
      }

      // Check if the number is prime
      int isPrime = 1;
      for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
          isPrime = 0;
          break;
        }
      }

      // The number is not prime, print the result and skip checking the
      // reversed number
      if (!isPrime) {
        printf("The circle remains incomplete.\n");
        continue;
      }

      // Reverse the number
      int reversed = 0;
      for (; number; number /= 10) {
        reversed *= 10;
        reversed += number % 10;
      }

      // Check if reversed number is prime
      isPrime = 1;
      for (int i = 2; i < reversed / 2; ++i) {
        if (reversed % i == 0) {
          isPrime = 0;
          break;
        }
      }

      // Print the result
      if (!isPrime) {
        printf("The circle remains incomplete.\n");
      } else {
        printf("This number completes the circle of joy!\n");
      }

      // Next command
      continue;
    }

    // Happy numbers: Print all the happy numbers between 1 to the given number.
    // Happy number is a number which eventually reaches 1 when replaced by the
    // sum of the square of each digit
    /* Examples:
    Happy :) : 7, 10
    Not Happy :( : 5, 9
    Please notice: the number has to be bigger than 0.
    */
    // 5. Happy Numbers
    if (option == 5) {
      // Read the number
      int number;
      printf("Enter a number:\n");
      int num = scanf("%d", &number);
      while (num != 1 || number < 1) {
        printf("Only positive number is allowed, please try again:\n");
        num = scanf("%d", &number);
      }

      // As number >= 1, 1 is always in the interval [1, number]
      // Since 1 is a happy number, print it immediately
      printf("Between 1 and %d only these numbers bring happiness: 1", number);
      // Print all happy numbers in the interval [1, number]
      // Since all numbers in the interval [2, 6] are known to be not happy,
      // don't bother checking them and start the loop with i == 7
      for (int i = 7; i <= number; ++i) {
        // Repeatedly calculate the sum of squares of digits until 1 is reached
        // or a cycle is detected
        int sum = i;
        do {
          int nextSum = 0;
          for (int sumCopy = sum; sumCopy; sumCopy /= 10) {
            int digit = sumCopy % 10;
            nextSum += digit * digit;
          }
          sum = nextSum;

          // If the sum reaches 1, the number is happy
          // If the number is unhappy, the sum reaches eventually reaches 4, as
          // described here:
          // https://en.wikipedia.org/wiki/Happy_number#10-happy_numbers
        } while (sum != 1 && sum != 4);

        // Print the result
        if (sum == 1) {
          printf(" %d", i);
        }
      }
      printf("\n");

      // Next command
      continue;
    }

    // Festival of Laughter: Prints all the numbers between 1 the given number:
    // and replace with "Smile!" every number that divided by the given smile
    // number and replace with "Cheer!" every number that divided by the given
    // cheer number and replace with "Festival!" every number that divided by
    // both of them
    /* Example:
    6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
    */
    // 6. Festival Of Laughter
    if (option == 6) {
      // Get divisors
      int smile, cheer;
      printf("Enter a smile and cheer number:\n");
      int num = scanf(" smile: %d, cheer: %d", &smile, &cheer);
      while (num != 2 || smile < 1 || cheer < 1 || smile == cheer) {
        // Clear the remainder of the line
        scanf("%*[^\n]%*c");
        printf("Only 2 different positive numbers in the given format are "
               "allowed for the festival, please try again:\n");
        num = scanf(" smile: %d, cheer: %d", &smile, &cheer);
      }
      // Get maximum
      int maximum;
      printf("Enter maximum number for the festival:\n");
      num = scanf("%d", &maximum);
      while (num != 1 || maximum < 1) {
        printf("Only positive maximum number is allowed, please try again:\n");
        num = scanf("%d", &maximum);
      }

      // Print the result
      for (int i = 1; i <= maximum; ++i) {
        if (i % smile == 0 && i % cheer == 0) {
          printf("Festival!\n");
        } else if (i % smile == 0) {
          printf("Smile!\n");
        } else if (i % cheer == 0) {
          printf("Cheer!\n");
        } else {
          printf("%d\n", i);
        }
      }

      // Next command
      continue;
    }

    // 7. Exit
    if (option == 7) {
      printf("Thank you for your journey through Numeria!\n");
      break;
    }
  }

  return 0;
}
