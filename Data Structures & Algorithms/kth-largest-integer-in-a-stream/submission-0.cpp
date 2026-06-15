using namespace std;
class KthLargest {
 public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        for (int num : nums) {
            q_.push(num);
            if (q_.size() > k_) {
                q_.pop();
            }
        }
    }
    
    int add(int val) {
        q_.push(val);
        if (q_.size() > k_) {
            q_.pop();
        }
        return q_.top();
    }
 private:
    priority_queue<int, vector<int>, greater<int>> q_;
    int k_;
};
