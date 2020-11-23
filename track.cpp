#include "track.h"
#include "duration.h"

track :: track(){
    name = "";
    artist = "";
    album = "";
    year = 0;
    duration();
}

track :: track(string n, string a, string alb, int y, int min, int sec){
    name = n;
    artist = a;
    album = alb;
    year = y;
    time.setSecond(sec);
    time.setMinute(min);
}

ostream& operator<<(ostream& ofs, const track& obj) {
    ofs << "'" << obj.name << "' by '" << obj.artist 
    << "' in " << obj.album << " (" << obj.year << ") " << endl;
    return ofs;
}