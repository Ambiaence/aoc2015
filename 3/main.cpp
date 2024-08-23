

#include <iostream>
#include <algorithm>
#include <tuple>
#include <set>

typedef std::tuple<int,int> Location;
typedef std::set<Location> LocationSet;

int main(int, char**) {
	int character = ' ';

	int x = 0;
	int y = 0;

	LocationSet location_set;
	//Begins delivering at his starting location so we must count the current position.
	location_set.insert(std::make_tuple(x,y));
	while (character != EOF) {
		character = getchar();
		switch(character) {
			case '^':
				y = y+1;
			break;
				
			case '>':
				x = x+1;
			break;

			case 'v':
				y = y-1;
			break;

			case '<':
				x = x-1;
			break;

			default:
			break;
		}
		location_set.insert(std::make_tuple(x,y));
	}

	std::cout << location_set.size() << std::endl;
}
