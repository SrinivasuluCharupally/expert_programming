/// @brief this tell about difference b/w CLOCK_MONOTIC_RAW and CLOCK_MONOTINIC

/// @brief CLOCK_MONOTONIC_RAW would be relevant mainly to cases where more accurate time is wanted over very short intervals, and CLOCK_MONOTONIC would be preferable for longer-term timers measured in minutes, hours or days.

// https://www.softwariness.com/articles/monotonic-clocks-windows-and-posix/

// soruce https://gist.github.com/Zaxuhe/4757305


#include<iostream>
#include<time.h>

using namespace std;

int main() {
	timespec ts_raw, ts;

	clock_gettime(CLOCK_MONOTONIC_RAW, &ts_raw);
	clock_gettime(CLOCK_MONOTONIC, &ts);
	
	cout << "RAW time = " << ts_raw.tv_sec << "." << ts_raw.tv_nsec << endl;
	cout << "NON RAW time = " << ts_raw.tv_sec << "." << ts.tv_nsec << endl;

}
