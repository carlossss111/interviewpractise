#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

void cppwrite(bool append = false){
	std::ofstream fp;
	if (append){
		fp = std::ofstream("file.txt", std::ios_base::app);
	}
	else{
		fp = std::ofstream("file.txt");
	}

	if(!fp.is_open()){
		printf("Error opening file.\n");
		return;
	}

	fp << "This is a line.\n";
	fp << "This is another line.\n";

	fp.close();
}

void cppread(){
	std::ifstream fp("file.txt");
	if(!fp.is_open()){
		printf("Error opening file.\n");
		return;
	}

	std::vector<std::string> strs;
	std::string line;
	while(std::getline(fp, line)){
		strs.push_back(line);
	}	

	for(std::string ln : strs){
		printf("%s\n", ln.c_str());
	}
	
	fp.close();
}

void cwrite(bool append = false){
	FILE* fp;
	if(append){
		if(!(fp = fopen("file.txt", "a"))){
			printf("Error opening file.\n");
		}
	}
	else{
		if(!(fp = fopen("file.txt", "w"))){
			printf("Error opening file.\n");
		}
	}

	fprintf(fp, "This is a line sent from fprintf!\n");
	fprintf(fp, "%s", "this is another one!\n");

	fclose(fp);	
}

void cread(){
	std::vector<std::string*> text;

	FILE* fp;
	if(!(fp = fopen("file.txt", "r"))){
		printf("Error opening file.\n");
	}

	char c;
	std::string* str = new std::string();
	while((c = fgetc(fp)) != EOF){
		if(c == '\n'){
			text.push_back(str);
			str = new std::string();
		}
		else{
			*str += c;
		}
	}
	delete str;

	for(std::string* ln : text){
		printf("%s\n", ln->c_str());
		delete ln;
	}
	
	fclose(fp);
}

int main(int argc, char** argv) {
	//cwrite();
	cread();
	//cppread();
	//cppwrite();
	return 0;
}
