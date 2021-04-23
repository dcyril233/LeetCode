#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool result = m.find(val) == m.end();
        m[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, m[val].size()-1));
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool result = m.find(val) != m.end();
        if(result) {
            auto last = nums.back();
            int index = m[val].back();
            m[last.first][last.second] = index;
            nums[index] = last;
            m[val].pop_back();
            if(m[val].empty())
                m.erase(val);
            nums.pop_back();
        }
        return result;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        RandomizedCollection* obj = new RandomizedCollection();
        cout << obj->insert(1) << endl;
        cout << obj->insert(1) << endl;
        cout << obj->insert(2) << endl;
        cout << obj->insert(1) << endl;
        cout << obj->getRandom() << endl;
    }
    return 0;
}
#endif