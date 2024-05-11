#include <iostream>

int main() {
	int character = ' ';
	int floor = 0;
	int character_position = 1;
	int index_of_first_basement_visit = -1;
	bool has_been_in_basement = false;

	while(character != EOF) {
		character = getchar();

		if (character == '(') {
			floor++;
		}

		if (character == ')') {
			floor--;
		}
		
		if (has_been_in_basement) { 
			continue;
		};

		if (floor < 0) {
			has_been_in_basement = true;
			index_of_first_basement_visit = character_position;
		}
		character_position++;


	}
	printf("floor = %d", floor);
	printf("index = %d", index_of_first_basement_visit);
}


