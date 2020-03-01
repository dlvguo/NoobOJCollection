#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
	deque<int> q1;
    MyStack() {
		
    }
    
    /** Push element x onto stack. */
    void push(int x) {
		q1.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		int x=q1.back();
		q1.pop_back();
		return x;
    }
    
    /** Get the top element. */
    int top() {
		return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return q1.size()==0;
    }
};


int main(){
	cout<<"FUCK";
	system("pause");
	int ab;
	vector<int> v;
}