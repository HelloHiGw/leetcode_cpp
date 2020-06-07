class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, sum = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            /*
            point 1, here seems greedy ? choose the next one as start ?  (emmm i don't know)
            Note: If there exists a solution, it is guaranteed to be unique.
            start is unique. so it is not greedy ? (emmm i don't know)
            */
            if (tank < 0) {  
                start = i + 1;
                tank = 0;
            }
        }
        return sum >= 0 ? start : -1;  // point 2
    }
};

/*
1. If car starts at A and can not reach B. Any station between A and B
can not reach B.(B is the first station that A can not reach.)

2. If the total number of gas is bigger than the total number of cost. There must be a solution.

Proof for the second point:

If there is only one gas station, it’s true.

If there are two gas stations a and b, and gas(a) cannot afford cost(a), i.e., gas(a) < 
cost(a), then gas(b) must be greater than cost(b), i.e., gas(b) > cost(b), since gas(a) 
+ gas(b) > cost(a) + cost(b); so there must be a way too.

If there are three gas stations a, b, and c, where gas(a) < cost(a), i.e., we cannot travel from a to b directly, then:

either if gas(b) < cost(b), i.e., we cannot travel from b to c directly, then gas(c) > 
cost(c), so we can start at c and travel to a; since gas(b) < cost(b), gas(c) + gas(a) 
must be greater than cost(c) + cost(a), so we can continue traveling from a to b. Key 
Point: this can be considered as there is one station at c’ with gas(c’) = gas(c) + 
gas(a) and the cost from c’ to b is cost(c’) = cost(c) + cost(a), and the problem 
reduces to a problem with two stations. This in turn becomes the problem with two 
stations above.

or if gas(b) >= cost(b), we can travel from b to c directly. Similar to the case above, 
this problem can reduce to a problem with two stations b’ and a, where gas(b’) = gas(b) 
+ gas(c) and cost(b’) = cost(b) + cost(c). Since gas(a) < cost(a), gas(b’) must be 
greater than cost(b’), so it’s solved too.

For problems with more stations, we can reduce them in a similar way. In fact, as seen 
above for the example of three stations, the problem of two stations can also reduce to 
the initial problem with one station.
*/