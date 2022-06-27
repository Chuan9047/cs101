#include <iostream>
#include <string>
using namespace std;
class Clock {
    protected:
        int Hour;
        int minute;
        int second;
        string meridian;
    public:
        Clock(int hr, int m, int s, string apm) {
            if(hr<=12&&hr>=1)
                Hour = hr;
            if(m<=59&&m>=0)
                minute = m;
            if(s<=59&&s>=0)
                second = s;
            if(!apm.compare("AM")||!apm.compare("PM"));
                meridian = apm;
        }
        void display(){
            cout << Hour << ":" << minute << ":" << second << " " << meridian << endl;
        }
};
class StandardClock : Clock {
    public:
        StandardClock(int a, int b, int c, string d):Clock(a, b, c, d){};
        void display() {
            if(!meridian.compare("AM"))
                cout << "上午 ";
            else
                cout << "下午 ";
            cout << Hour << ":" << minute << ":" << second << endl;
        }
};
class MilitaryClock : Clock{
    public:
        MilitaryClock(int a, int b, int c, string d):Clock(a, b, c, d){};
        void display() {
             if(!meridian.compare("AM"))
                cout << Hour;
            else if(!meridian.compare("PM"))
                cout << Hour+12;
            cout << ":" << minute << ":" << second << endl;
        }
};
int main()
{
    Clock cc(10,25,43,"AM");
    StandardClock sc(10, 25, 43, "AM");
    MilitaryClock mc(10,25,43,"PM");
    cc.display();
    sc.display();
    mc.display();
    return 0;
}
