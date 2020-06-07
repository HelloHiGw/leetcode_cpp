class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
        // v.resize(curr + 1);  // the same as following
        v.erase(v.begin() + curr + 1, v.end());
        v.push_back(url);
        ++curr;
    }
    
    string back(int steps) {
        curr = max(curr - steps, 0);
        return v[curr];
    }
    
    string forward(int steps) {
        curr = min(curr + steps, (int)v.size() - 1);
        return v[curr];
    }
    
private:
    vector<string> v;
    int curr;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */


/*
The top of the first stack is the first element in the back history. 
And the top of the other stack - first element of the forward history. 
Move urls from one stack to antother as you go back and forward.
*/
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        // no clear method in stack
        stForward = stack<string>();
        stBack.push(curr);
        curr = url;
    }
    
    string back(int steps) {
        if (steps > stBack.size()) steps = stBack.size();
        for (int i = 0; i < steps; ++i) {
            stForward.push(curr);
            curr = stBack.top();
            stBack.pop();
        }
        return curr;
    }
    
    string forward(int steps) {
        if (steps > stForward.size()) steps = stForward.size();
        for (int i = 0; i < steps; ++i) {
            stBack.push(curr);
            curr = stForward.top();
            stForward.pop();
        }
        return curr;
    }
    
private:
    stack<string> stBack, stForward;
    string curr;
};