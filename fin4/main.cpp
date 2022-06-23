#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
class freqFile{
	public:
		string filename;
		FILE* fp;
		int cnt[26];
		freqFile(string filename){
			this->filename = filename;
			for(int i = 0 ; i<26;i++){
				cnt[i] = 0;
			}
		}
		void readFile(){
			fp = fopen(filename.c_str(), "r");
			char c;
			while(fscanf(fp,"%c",&c)!=EOF){
				c = tolower(c);
				cnt[c-'a']++;
			}
		}
		void showFreq(){
			for(int i = 0 ; i<26;i++){
				printf("[%c] = %d\n", i+'a', cnt[i]);  
			}
		}
};
int main()
{
    freqFile myFile("main.cpp");
    myFile.readFile();
    myFile.showFreq();
    return 0;
}
