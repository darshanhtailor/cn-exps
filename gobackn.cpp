#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, sz;
	cout << "Enter number of frames: ";
	cin >> n;

	cout << "Enter window size: ";
	cin >> sz;

	int winidx = 1, count = 0;
	srand(time(0));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < sz; j++){
			if(i+j <= n){
				cout << "Sending Frame " << i+j << "....\n";
				count++;
			}
		}

		bool flag = true;
		for(int j = 0; j < sz; j++){
			if(i+j > n) break;

			int r = rand()%2;
			if(r == 1){
				cout << "Acknowledgment for Frame " << i+j << "\n";
				winidx++;
			} else{
				cout << "Acknowledgment not received for Frame " << i+j << "\nTimeout! Retransmitting Window....\n\n";
				i = winidx-1;
				flag = false;
				break;
			}
		}

		if(flag){
			i += sz-1;
			cout << "\n";
		}
	}

	cout << "Total number of frames sent and resent: " << count;
}