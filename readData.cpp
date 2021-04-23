#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    vector<int> nums;
    string s;
    cin >> s;
    string tmp;
    stringstream st1, st2;
    st1.str(s);
    while(getline(st1, tmp, ',')) {
        st2.clear();
        st2.str(tmp);
        while(getline(st2, tmp, '-'))
            nums.push_back(stoi(tmp));
    }
    
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ',';
    }
    return 0;
}