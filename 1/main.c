#include <stdio.h>

int main() {
	int character = ' ';
	int floor = 0;

	while(character != EOF) {
		character = getchar();
		if (character == '(') {
			floor++;
		}

		if (character == ')') {
			floor--;
		}
	}

	printf("floor = %d", floor);
}


