#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReplaceMyString{
    public:
        size_t pos_a, pos_b;
        string str;
        ReplaceMyString replaceString(string a, string b){
            ofstream out;
            ifstream in;
            in.open("main.cpp");
            out.open("Rmain.cpp");
            
            while(getline(in, str)){
                pos_a = str.find(a);
                pos_b = str.find(b);
                if(pos_a != string::npos){
                    str = str.replace(pos_a, a.length(), b);
                    if(b.find(a) != string::npos){
                        pos_b += (b.length()-a.length());
                        str = str.replace(pos_b, a.length(), b);
                    }
                }
                out << str << endl;
            }
            out.close();
            in.close();
        }
};

int main(){
    ReplaceMyString my;
    my.replaceString("IU","IU is best");
    return 0;
}
