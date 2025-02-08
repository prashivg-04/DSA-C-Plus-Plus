//Stock Span Problem
//Span = maximum number of consecutive days(including current) for which price <= today's price

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void stockSpan(vector<int> stocks, vector<int>& span) {
    int n = stocks.size();
    stack<int> s;
    

    span[0] = 1;
    s.push(0);

    for(int i = 1; i < n; i++) {
        while(!s.empty() && stocks[i] >= stocks[s.top()]) {
            s.pop();
        }
        if(s.empty()) {
            span[i] = i+1;
        } else {
            span[i] = i-s.top();
        }
        s.push(i);
    }
}

int main() {
    vector<int> stocks = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span(stocks.size());
    stockSpan(stocks, span);
    return 0;
}

