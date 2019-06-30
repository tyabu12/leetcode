// O(n)
class KthLargest {
private:
    int _k;
    multiset<int> _st;
    int _lastKVal;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        _st.insert(nums.begin(), nums.end());
        _lastKVal = INT_MIN;
    }

    int add(int val) {
        _st.insert(val);
        if (val <= _lastKVal) return _lastKVal;
        else {
            auto it = _st.rbegin();
            for (int i = 0; i < _k - 1; i++) it++;
            _lastKVal = *it;
            return *it;
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
