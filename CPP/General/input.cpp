#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>

void cppregular(){
	std::string userInput;
	std::getline(std::cin, userInput);
	printf("You wrote: %s\n", userInput.c_str());
}

void cppdelimited(){
	std::vector<std::string> strs;

	// Get line delimited by '\n'
	std::string lineIn;
	std::getline(std::cin, lineIn);

	// Loop through line delimited by ',\'
	std::istringstream line;
	line.str(lineIn);
	for (std::string split; std::getline(line, split, ',');){
		strs.push_back(split);
	}

	// Loop through resulting vector
	printf("Results:\n");
	for (std::string split: strs) {
		printf("%s\n", split.c_str());
	}
}

void cregular(){
	char line[256];
	if (!fgets(line, sizeof(line), stdin)){
		printf("Failed to read into buffer\n");
	}

	printf("%s\n", line);
}

void cdelimited(){
	std::vector<std::string*> strs;

	// Get line
	char line[256];
	if (!fgets(line, sizeof(line), stdin)){
		printf("Failed to read into buffer\n");
	}

	// Loop through line delimited by ',\'
	int i = 0;
	char current = line[i];
	std::string* str = new std::string();
	while(current != '\0'){	
		if(current == ',' || current == '\n'){
			*str += '\0';
			strs.push_back(str);
			str = new std::string();
		}
		else{
			*str += current;
		}
		current = line[++i];
	}
	delete str;

	// Loop through resulting vector
	printf("Results:\n");
	for (std::string* split: strs) {
		printf("%s\n", split->c_str());
	}

	// Free memory
	for (std::string* split: strs) {
		delete split;
	}
	
}

int main(int argc, char** argv){
	printf("Enter text:\n");
	cdelimited();
	//cregular();
	//cppdelimited();
	//cppregular();
	return 0;
}
