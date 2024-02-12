#include <iostream>
#include <string>
#include <vector>
#include <ctype.h> // isdigit

int main() {	
	std::vector<std::string> calibration_document;
	int lineCount = 0;

	std::cout << "Calibration Document line count:  " << std::endl;
	std::cin >> lineCount;

	for (int i = 0; i < lineCount; i++) {
		std::string single_line_buffer;
		
		std::cout << "Please input line " << i + 1 << std::endl; // + 1 is there to not display (line 1) or the line being off by 1.
		std::cin.clear();
		std::cin.ignore(1);
		std::getline(std::cin, single_line_buffer);

		calibration_document.push_back(single_line_buffer);
	}

	for (int i = 0; i < lineCount; i++) {
		int first_value = 0;
		int last_value = 0;

		for (int j = 0; j < calibration_document[i].length(); j++) {
			char string_character = calibration_document[i][j];

			if (isdigit(calibration_document[i][j])) {

				if (first_value == 0) {
					first_value = string_character - '0';
					std::cout << first_value;
				}

			}
		}
		std::cout << std::endl;
		first_value = 0;
		last_value = 0;
	}

	return 0;
}