#include <stdio.h>
#include <string.h>

const char* manipulate_string(const char *line, size_t len);


int main() {
	//Read in line from user
	char *line = NULL;
	size_t len = 0;
	size_t lineSize = getline(&line, &len, stdin);

	printf("%s", manipulate_string(line, len));
	return 0;
}

const char* manipulate_string(const char *line, size_t len){
	char *and = "&amp";
	char *gt = "&gt";
	char *lt = "&lt";
	static char new_string[256];
	int j =0;

	//Search for all occurenses for <, >, &.
	for(size_t i=0; i<len; ++i){
		if(line[i] == '<'){
			strcpy(&new_string[j], lt);
			j += 3;

		} else if(line[i] == '>'){
			strcpy(&new_string[j], gt);
			j += 3;

		} else if(line[i] == '&'){
			strcpy(&new_string[j], and);
			j +=4;

		} else if(line[i] == '/0'){
			break;
		} else {
			new_string[j] = line[i];
			j += 1;
		}
	}

	return new_string;
}
