#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, sz, count = 0;
	cout << "Enter number of frames: ";
	cin >> n;

	cout << "Enter window size: ";
	cin >> sz;

	srand(time(0));
	int i = 1;
	deque<int> q;
	for(;i <= min(n, sz); i++){
		cout << "Sending Frame " << i << "...\n";
		count++;
		q.push_back(i);
	}
	cout << "\n";
	for(;i <= n; i++){
		int r = rand()%2;
		if(r){
			cout << "Acknowledgment received for Frame " << q.front() << "\n";
			q.pop_front();
			cout << "Sending Frame " << i << "...\n\n";
			count++;
			q.push_back(i);
		} else{
			cout << "Acknowledgment failed for Frame " << q.front() << "\n";
			cout << "Retransmitting Window\n";
			for(auto &x:q){
				cout << "Sending Frame " << x << "...\n";
				count++;
			}
			cout << "\n";
			i--;
		}
	}
	vector<int> arr(q.begin(), q.end());
	for(int i = 0; i < arr.size(); i++){
		int r = rand()%2;
		if(r){
			cout << "Acknowledgment received for Frame " << q.front() << "\n\n";
			q.pop_front();
		} else{
			cout << "Acknowledgment failed for Frame " << q.front() << "\n";
			cout << "Retransmitting Window\n";
			for(auto &x:q){
				cout << "Sending Frame " << x << "...\n";
				count++;
			}
			cout << "\n";
			i--;
		}
	}
	cout << "Total frames sent and resent: " << count;
	return 0;
}