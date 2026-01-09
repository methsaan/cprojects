#include <stdio.h>

int isLeap(int year) {
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

int isValidDate(int year, int month, int day) {
	int valid = 0;
	int state = 1;
	while (state != 10) {
		switch (state) {
			case 1:
				if (month < 1 || month > 12 || year < 1) {
					printf("Month or year out of bounds.\n");
					state = 9;
				} else if (month == 2) {
					state = 3;
				} else {
					state = 2;
				}
				break;
 			case 2:
				if ((month < 8 && month % 2 == 1) || (month >= 8 && month % 2 == 0)) {
					state = 6;
				} else {
					state = 7;
				}
				break;
 			case 3:
				if (isLeap(year)) {
					state = 4;
				} else {
					state = 5;
				}
				break;
			case 4:
				if (day < 1 || day > 29) {
					printf("Day is out of bounds for a leap year February.\n");
					state = 9;
				} else {
					state = 8;
				}
				break;
			case 5:
				if (day < 1 || day > 28) {
					printf("Day is out of bounds for a non-leap year February.\n");
					state = 9;
				} else {
					state = 8;
				}
				break;
			case 6:
				if (day < 1 || day > 31) {
					printf("Day is out of bounds for a 31-day month.\n");
					state = 9;
				} else {
					state = 8;
				}
				break;
			case 7:
				if (day < 1 || day > 30) {
					printf("Day is out of bounds for a 30-day month.\n");
					state = 9;
				} else {
					state = 8;
				}
				break;
			case 8:
				printf("Valid date.\n");
				valid = 1;
				state = 10;
				break;
			default:
				printf("Invalid date.\n");
				valid = 0;
				state = 10;
				break;
		}
	}
	return valid;
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
	printf("12/05/2025\n");
	printf("%d\n\n", isValidDate(2025, 12, 5));
	printf("04/40/2023\n");
	printf("%d\n\n", isValidDate(2023, 4, 40));
	printf("02/29/1900\n");
	printf("%d\n\n", isValidDate(1900, 2, 29));
	printf("13/29/2000\n");
	printf("%d\n\n", isValidDate(2000, 13, 29));
	printf("11/31/1994\n");
	printf("%d\n\n", isValidDate(1994, 11, 31));
	printf("02/29/2000\n");
	printf("%d\n\n", isValidDate(2000, 2, 29));
	printf("11/00/0000\n");
	printf("%d\n\n", isValidDate(0, 11, 0));
	printf("02/30/2024\n");
	printf("%d\n\n", isValidDate(2024, 2, 30));
}
