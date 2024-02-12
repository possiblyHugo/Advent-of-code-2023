#include <iostream>
#include <string>
#include <vector>

int main() {	
	std::vector<std::string> calibration_document;
	std::string single_line_buffer = "";
	int lineCount = 0;

	std::cout << "Calibration Document line count:  " << std::endl;
	std::cin >> lineCount;

	for (int i = 0; i < lineCount; i++) {
		
		std::cout << "Please input line " << i + 1 << std::endl; // + 1 is there to not display (line 1) or the line being off by 1.
		std::getline(std::cin, single_line_buffer);

		calibration_document.push_back(single_line_buffer);
		std::cin.clear();
		std::cin.ignore(1);
	}

	for (int i = 0; i < lineCount; i++) {

		for (int j = 0; j < calibration_document[i].length(); j++) {
			std::cout << calibration_document[i][j];
		}
		std::cout << std::endl;
	}


	return 0;
}