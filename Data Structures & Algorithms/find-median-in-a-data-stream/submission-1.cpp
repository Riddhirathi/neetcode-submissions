class MedianFinder {
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxh.push(num);
        if(!minh.empty() && maxh.top() > minh.top()){
            minh.push(maxh.top());
            maxh.pop();
        }
        if(maxh.size() > minh.size()+1){
            minh.push(maxh.top());
            maxh.pop();
        }
        if(minh.size() > maxh.size()+1){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size() == minh.size()){
            return (maxh.top()+minh.top())/2.0;
        }
        else if(maxh.size()>minh.size()){
            return maxh.top();
        }
        else return minh.top();
    }
};
