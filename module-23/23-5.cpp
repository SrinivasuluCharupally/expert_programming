/*
At a bus-station, you have time-table for buses arrival and departure. You need to find the minimum number of platforms so that all the buses can be placed as per their schedule.

For example consider the above example.

arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

All events sorted by time.

Total platforms at any time can be obtained by subtracting total departures from total arrivals by that time.

Time     Event Type     Platforms
9:00       A                1
9:10       D                0
9:40       A                1
9:50       A                2
11:00      A                3
11:20      D                2
11:30      D                1
12:00      D                0
15:00      A                1
18:00      A                2
19:00      D                1
20:00      D                0
Minimum Platforms needed on railway station = Maximum platforms needed at any time = 3
*/

SOurce: http://www.crazyforcode.com/min-number-platforms-required-railway-station/

int findPlatform(int arr[], int dep[], int n)
{
   int plat_needed = 1, result = 1;
   int i = 1, j = 0;
  
   // Similar to merge in merge sort to process all events
   while (i < n && j < n)
   {
      if (arr[i] < dep[j])
      {
          plat_needed++;
          i++;
          if (plat_needed > result)  // Update result if needed
              result = plat_needed;
      }
      else // Else decrements count of platforms needed
      {
          plat_needed--;
          j++;
      }
   }
  
   return result;
}


