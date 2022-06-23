#include <iostream>
using namespace std;

class Clock {
	protected:
		int hr;
		int min;
		int sec;
	public:
		string meridian;
		Clock(int h, int m, int s, string mer) {
			hr = h;
			min = m;
			sec = s;
			meridian = mer;
		}
		void display() {
			cout << hr << ":" << min << ":" << sec << " " << meridian << endl;
		}
};

class StandardClock : Clock {
	private:
		string Chinese_meridian;
	public:
		StandardClock(int h, int m, int s, string mer) : Clock(h, m, s, mer) {
			if(mer == "AM") {
				Chinese_meridian = "上午";
			} else {
				Chinese_meridian = "下午";
			}
		}
		void display() {
			cout << Chinese_meridian << " " << hr << ":" << min << ":" << sec << endl;
		}
		
};

class MilitaryClock : Clock {
	private:
		int mc_h;
	public:
		MilitaryClock(int h, int m, int s, string mer) : Clock(h, m, s, mer) {
			if(mer == "PM") {
				mc_h = h + 12;
			}
		}
		void display() {
			cout << mc_h << ":" << min << ":" << sec << endl;
		}
		
};

int main(void) {
	Clock cc(10, 25, 43, "AM");
	StandardClock sc(10, 25, 43, "AM");
	MilitaryClock mc(10, 25, 43, "PM");
	cc.display();
	sc.display();
	mc.display();

	return 0;
}
