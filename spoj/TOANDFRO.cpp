//TOANDFRO - To and Fro
#include<bits/stdc++.h>
using namespace std;
 
int main () {
	int col;
	cin >> col;
	while(col) {
		string s;
		cin >> s;
		int stLen = s.length();
		int row = stLen / col;
		char arr[stLen];
		int sign = 1;
		arr[0] = s[0];
		int j = 0, k = 1;
		for(int i = 1; i <= 2 * row - 1; i++) {
			if(i % 2 == 0) {
				j++;
				arr[j] = s[k++];
			}
			else if(i % 2 != 0) {
				int temp = col;
				while(--temp) {
					j = j + sign * row;
					arr[j] = s[k++];
				}
				if(sign == 1)
					sign = -1;
				else 
					sign = 1;
			}
		}
		arr[stLen] = '\0';
		int i = 0;
		while(arr[i] != '\0') {
			cout << arr[i];
			i++;
		}
		cin >> col;
		if(col != 0)
		cout << endl;
	}
}
