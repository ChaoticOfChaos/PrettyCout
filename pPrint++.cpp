#include <iostream>
#include <string>
#include <cctype>
#include <thread>

void pPrint(std::string str) {
	for (char& c : str) {
		c = std::tolower(c);
	}
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz,.;/<>:?!@#$%¨&*()-_=+{[]}|";

	std::string printLabel;

	for (int i = 0; i < str.size(); i++) {
		int count = 0;
		bool found = false;
		while (true) {
			if (str[i] == ' ') {
				printLabel += ' ';
				found = true;
				break;
			}
			else if (str[i] == alphabet[count]) {
				printLabel += alphabet[count];
				found = true;
				break;
			}

			if (found) {
				std::cout << printLabel << std::endl;
			}
			else {
				std::cout << printLabel << alphabet[count] << std::endl;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(100));

			if (count >= 25) {
				count = 0;
			}
			else {
				count++;
			}

			system("cls");
		}
	}
	std::cout << printLabel << std::endl;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		pPrint("Hello World");
		return 1;
	}

	pPrint(argv[1]);
	return 0;
}