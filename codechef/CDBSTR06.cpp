#include<bits/stdc++.h>
using namespace std;

int main () {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int>ar(n);
        for(int i = 0; i < n; i++) 
            cin >> ar[i];
        
        int curSum = 0, maxSum = 0, curStart = 0, curEnd = 0, start = 0, end = 0;
        for(int i = 0; i < n; i++) {
            if(ar[i] < 0) {
                curEnd = max(0, i - 1);
                if(maxSum < curSum) {
                    maxSum = curSum;
                    start = curStart;
                    end = curEnd;
                }
                else if(maxSum == curSum) {
                    if(start - end < curStart - curEnd) {
                        start = curStart;
                        end = curEnd;
                    }
                }
                curStart = min(n, i+1);
                curSum = 0;
                continue;
            }
            curSum += ar[i];
        }
        if(curEnd <= curStart)  
            curEnd = n - 1;
        if(curSum > maxSum) {
            maxSum = curSum;
            start = curStart;
            end = curEnd;
        }
        else if(curSum == maxSum) {
            if(curEnd - curStart > n - start) {
                start = curStart;
                end = curEnd;
            }
        }
        // cout << maxSum << endl;
        // cout << curSum << endl;
        for(int i = start; i <= end; i++) {
            cout << ar[i] << " ";
        }
    }
}
