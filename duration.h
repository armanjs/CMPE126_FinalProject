#include <iostream>
using namespace std;

class duration {
  friend ostream& operator << (ostream& output, const duration& clk);
  friend duration operator + (const duration& dur1, const duration& dur2);

public:
  duration(); // default constructor
  duration(int m, int s);
  // setters
  void setHour(int h);
  void setMinute(int m);
  void setSecond(int s);

//private:
  int minute;
  int second;
};