/*Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.*/


 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

   int a = 0;
    int b = 0;
    int c = newInterval.start;
    int d = newInterval.end;
    int pos = 0;
    
    // check corner cases
    // Case : If newInterval = [10, 8] instead of [8, 10]
    if (c>d)
        swap(c, d);
        
    vector<int> count;
    vector<Interval> overlap;
    
    // Case : Empty intervals array
    if (intervals.empty())
    {
        overlap.push_back(newInterval);
        return overlap;
    }
        
    for(int i = 0; i<intervals.size(); ++i)
    {
        a = intervals[i].start;
        b = intervals[i].end;
        
        if (max(a,c)>min(b,d))
            continue;
        else
        {
            count.emplace_back(i);
        }
    }
    
    // Case : there is no overlap and,
    if(count.empty())
    {
        int t1 = intervals[0].start; int t2 = intervals[intervals.size()-1].end;
        // Case : newInterval comes at the beginning without overlap
        if (d<t1)
        {
            vector<Interval>::iterator it1;
            it1 = intervals.begin();
            intervals.insert(it1, Interval(c, d));
            return intervals;
        }
        // Case : newInterval comes at the end without overlap 
        else if(c>t2)
        {
            intervals.emplace_back(Interval(c, d));
            return intervals;
        }
        // Case : newInterval comes in between without overlap
        else
        {
            for (int j = 0; j<intervals.size(); ++j)
            {
                if (intervals[j].start > d)
                {
                    pos = j;
                    break;
                }
            }
            vector<Interval>::iterator it2;
            it2 = intervals.begin() + pos;
            intervals.insert(it2, Interval(c, d));
            return intervals;
        }
    }
    
    // Constructing the result vector
    // Case : pushing of intervals before new overlap interval if present
    for (int x = 0; x < count[0]; ++x)
    {
        overlap.emplace_back(intervals[x]);
    }
    // Case : new overlap interval pushing
    int cend = count.size() - 1;
    int temp = cend-count[0];
    int nS = min(intervals[count[0]].start, c);
    int nE = max(intervals[count[cend]].end, d);
    Interval I(nS, nE);
    overlap.emplace_back(I);
    // Case : pushing intervals after new overlap interval if any
    for(int z = (count[cend]+1); z < intervals.size(); ++z)
    {
        overlap.emplace_back(intervals[z]);
    }
    //return the resultant vector
    return overlap;
}
