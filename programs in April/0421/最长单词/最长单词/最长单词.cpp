#include <iostream>;
using namespace std;
int main() {
	char sentence[500];
	cin.getline(sentence, 500, '.');
	int start = 0;
	int end = 0;
	int currentstart = 0;
	int currentend = 0;
	int current = 0;
	int length = 0;
	int flag = 0;
	for (int i = 0; sentence[i] != '\0'; i++) {
		if (flag == 0 && sentence[i] != ' '&&sentence[i+1]!='\0') {
			currentstart = i;
			current++;
			flag = 1;
		}
		else if (flag == 1 && sentence[i] != ' '&&sentence[i+1] != '\0') {
			current++;
			flag = 1;
		}
		else if (flag == 1 && sentence[i] == ' ') {
			currentend = i - 1;
			flag = 0;
			if (current > length) {
				length = current;
				start = currentstart;
				end = currentend;
			}
			current = 0;
			currentstart = 0;
			currentend = 0;
		}
		else if (flag == 0 && sentence[i] == ' ') {
			current = 0;
			currentstart = 0;
			currentend = 0;
			flag = 0;
		}
		else if (sentence[i + 1] == '\0') {
			currentend = i ;
			current++; 
			if (current > length) {
				length = current;
				start = currentstart;
				end = currentend;
			}
		}
	}
	for (int i = start; i <= end; i++) {
		cout << sentence[i];
	}
	return 0;
}