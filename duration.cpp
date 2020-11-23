#include <iostream>
#include "duration.h"

// overload the "<<" operator
ostream &operator << (ostream& output, const duration& dur){
    if (dur.second < 10){
        output << dur.minute << " : 0" << dur.second << endl;
    }
    else
        output << dur.minute << " : " << dur.second << endl;
    return output;
}

// overload the "+" operator
duration operator + (const duration& dur1, const duration& dur2){
  int sumOfMinutes = dur1.minute + dur2.minute;
  int sumOfSeconds = dur1.second + dur2.second;

  // loop until seconds are less than 59
  while (sumOfSeconds > 59){
    sumOfSeconds = sumOfSeconds - 60;
    sumOfMinutes++; // add one minute every 60 seconds
  }

  return duration(sumOfMinutes,sumOfSeconds);
}

duration::duration() { // define the default constructor
  minute = 0;
  second = 0;
}

duration::duration(int m, int s) {
  setMinute(m);
  setSecond(s);
}

// define the setters

void duration::setMinute(int m) {
  minute = m;
}

void duration::setSecond(int s) {
  second = s;
}