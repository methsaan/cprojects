#include <stdio.h>

int is_leap(int year) {
	int leap = 0;
	int state = 1;
	while (state != 6) {
		switch (state) {
			case 1:
				if (year % 4 == 0) {
					state = 2;
				} else {
					state = 5;
				}
				break;
 			case 2:
				if (year % 100 == 0) {
					state = 3;
				} else {
					state = 4;
				}
				break;
 			case 3:
				if (year % 400 == 0) {
					state = 4;
				} else {
					state = 5;
				}
				break;
			case 4:
				leap = 1;
				state = 6;
				break;
			default:
				leap = 0;
				state = 6;
				break;
		}
	}
	return leap;
}

int main(int argc, char *argv[]) {
	/* Practice with State Design Pattern.
	 * Determine whether a given date (MM/dd/YYYY) is valid.
	 * Test Cases:
	 * - Input: 12/05/2025
	 *   Output: Valid date
	 * - Input: 04/40/2023
	 *   Output: Invalid date
	 * - Input: 02/29/1900
	 *   Output: Invalid date
	 * - Input: 13/29/2000
	 *   Output: Invalid date
	 * - Input: 11/31/1994
	 *   Output: Invalid date */
	printf("%d\n", is_leap(1900));
	printf("%d\n", is_leap(2000));
	printf("%d\n", is_leap(2025));
	printf("%d\n", is_leap(2024));
	printf("%d\n", is_leap(1993));
	printf("%d\n", is_leap(1996));
	printf("%d\n", is_leap(1700));
}
