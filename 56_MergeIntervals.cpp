//56. Merge Intervals
//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//        Given [1,3],[2,6],[8,10],[15,18],
//return [1,6],[8,10],[15,18].

#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareInterval(Interval& a, Interval& b) {
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compareInterval);
        vector<Interval> res;
        for (int i = 0; i < intervals.size(); ++i) {
            if(res.empty() || intervals[i].start > res.back().end) {
                res.push_back(intervals[i]);
            } else {
                res.back().end = max(intervals[i].end, res.back().end);
            }
        }
        return std::move(res);
    }
};
