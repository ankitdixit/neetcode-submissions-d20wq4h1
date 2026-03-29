/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start < b.start;
        });

        vector<bool> scheduled(n, false);
        int rooms = 0;
        int remaining = n;
        
        while(remaining > 0) {
            int last_end = -1;
            for (int i = 0; i < n; i++) {
                if (scheduled[i]) continue;
                if (last_end <= intervals[i].start) {
                    scheduled[i] = true;
                    last_end = intervals[i].end;
                    remaining--;
                }
            }
            rooms++;
        }
        return rooms;
    }
};
