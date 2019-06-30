// O(log n)
class KthLargest {
private:
    int _k;
    priority_queue<int, vector<int>, greater<int>> _queue;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (int i = 0; i < nums.size(); i++) add(nums[i]);
    }

    int add(int val) {
        if (_queue.size() < _k || val > _queue.top()) _queue.push(val);
        if (_queue.size() > _k) _queue.pop();
        return _queue.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
