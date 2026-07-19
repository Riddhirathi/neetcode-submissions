class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minh;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num: nums){
            minh.push(num);
            if(minh.size()>k) minh.pop();
        }
    }
    
    int add(int val) {
        minh.push(val);
        if(minh.size()>k) minh.pop();
        return minh.top();
    }
};
