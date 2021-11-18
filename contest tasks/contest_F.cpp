#include <deque>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main(){
    deque <string> q;
    string str;
    int n=0;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> str;
        if ((str == "*")){
            cin >> str;
            q.insert(q.begin() + q.size()/2 + q.size() % 2, str);
        } else
        if ((str == "+")){
            cin >> str;
            q.push_back(str);
        } else
        if ((str == "-")){
            cout << q.front() << endl;
            q.pop_front();
        }
    }
}