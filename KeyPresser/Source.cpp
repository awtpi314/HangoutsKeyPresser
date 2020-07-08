#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
	INPUT input;

	std::cout << "How many times would you like to print? ";
	int times = 100;
	std::cin >> times;

	std::cout << "Enter a word (~ ends input): ";
	char currentChar = 'B';
	std::string s = "";
	while (std::cin.peek() != '~') {
		std::cin >> currentChar;
		s += (char)toupper(currentChar);
	}
	std::cin.clear();
	const char* keyArray = s.c_str();

	Sleep(5000);

	input.type = INPUT_KEYBOARD;
	input.ki.wScan = 0;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;

	for (int j = 0; j < times; j++) {
		// Press "/" key
		input.ki.wVk = VK_OEM_2;
		input.ki.dwFlags = 0;
		SendInput(1, &input, sizeof(input));

		// Relesase "/" key
		input.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &input, sizeof(input));

		for (int i = 0; i < s.length(); i++) {
			input.ki.wVk = keyArray[i];
			input.ki.dwFlags = 0;
			SendInput(1, &input, sizeof(input));

			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(input));
		}

		input.ki.wVk = VK_RETURN;
		input.ki.dwFlags = 0;
		SendInput(1, &input, sizeof(input));

		input.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &input, sizeof(input));

		//Sleep(30);
	}

	return 0;
}