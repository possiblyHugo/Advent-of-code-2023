#include <iostream>
#include <string>
#include <vector>
#include <ctype.h> // isdigit

int main() {	
	std::vector<std::string> calibration_document;
	int lineCount = 0;
	int calibration_total = 0;

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
				}
				else { // Any other number which isn't the first value becomes the last KNOWN value
					last_value = string_character - '0';
				}

			}
		}
		
		if (last_value == 0) { // Condition check that if only one number is found in the line. (Instructions prompt that the single number should be doubled)
			last_value = first_value;
		}

		calibration_total += ((first_value * 10) + last_value); // First_value is multiplied by then to shift the number once to the left. 1 and 2 becomes 12 that way
		
		first_value = 0;
		last_value = 0;
	}

	std::cout << "The total for this calibration document is: " << calibration_total << std::endl;

	return 0;
}