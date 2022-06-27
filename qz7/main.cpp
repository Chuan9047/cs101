#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class myString {};

class ReadClass {
	public:
		ifstream in;
		string str;
		int num_of_class;

	void showClass() {
		in.open("main.cpp");
		num_of_class = 0;
		while(getline(in, str)) {
			int str_start = str.find("class", 0);
			int class_name = str.find("{", str_start);
			if(str_start == 0 && class_name != -1) {
				num_of_class++;
				for(int i = str_start; i < class_name - 1; i++) {
					cout << str[i];
				}
				cout << endl;
			}
		}
		in.close();
		cout << num_of_class << " class in main.cpp" << endl;
	}
};

int main(void) {
	ReadClass rfile;
	rfile.showClass();
	return 0;
}
