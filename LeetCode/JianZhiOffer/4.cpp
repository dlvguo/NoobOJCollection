#include<iostream>
#include<vector>
#include<deque>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	int rowNum=matrix.size();
	if(rowNum==0)
		return false;
	int lieNum=matrix[0].size()-1,lie=lieNum;
	int row=0;
	while(row<rowNum&&lie>=0){
		if(matrix[row][lie]==target)
			return true;
		else if(matrix[row][lie]<target){//如果比他小的话 说明row++
			row++;
		}
		else{
			lie--;			
		}
	}
	return false;
}

int main(){
	cout<<"FUCK";
	system("pause");
	int ab;
	vector<int> v;
}