#include <stdio.h>
#define LENGTH 16

int value_as_integer(char character) {
	return character - '0';
}

int value_of_next_number(char* line, char** character_pp) {
		int power = 1;
		int value = 0;
		while(**character_pp != 'x' && *character_pp >= line) {
			int digit = value_as_integer(**character_pp);
			value = value + digit*power;
			power = power*10;
			(*character_pp)--;
		}

		(*character_pp)--;
		return value;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int main () {	
	int sum = 0;
	char character_v = ' ';
	char line[LENGTH];
	char* character_p;
	character_p = line;

	while (character_v != EOF) {
		int width = 0;
		int length = 0;
		int height = 0;

		do {
			character_v = getchar();
			*character_p = character_v;
			character_p++;
		} while(character_v != '\n' && character_v != EOF);

		character_p--; //why two?
		character_p--;

		height = value_of_next_number(line, &character_p);
		width = value_of_next_number(line, &character_p);
		length = value_of_next_number(line, &character_p);

		printf("length %d\n", length);
		printf("width %d\n", width);
		printf("height %d\n\n", height);

		int maximum = max(max(height, width), length);

		int tuple[3] = {length, width, height};

		for(int i = 0; i < 3; i++) {
			if (tuple[i] == maximum){ 
				tuple[i] = 0;
				break;
			}
		}

		int ribbon_area = tuple[0]*2 + tuple[1]*2 + tuple[2]*2 ;
		int bow_volume = height * width * length;

		printf("Ribbon %d\n", ribbon_area);
		printf("Bow %d\n", bow_volume);

		sum = sum + ribbon_area + bow_volume;
		character_p = line;
	}
	printf("Sum %d\n", sum);
}
