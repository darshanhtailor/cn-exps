#include <bits/stdc++.h>
using namespace std;

int convert(char x){
	return x-'0';
}

char convert(int x){
	return x+'0';
}

void _xor(string &data, string &key){
	int cnt0 = 0, enc1 = 0;
	for(int i = 0; i < key.length(); i++){
		char x = convert(convert(data[i])^convert(key[i]));
		if(!enc1){
			if(x == '0') cnt0++;
			else enc1 = 1;
		}
		data[i] = x;
	}
	data.erase(0, cnt0);
}

void sender(){
	string data, key;
	cout << "Enter data to send: ";
	cin >> data;

	cout << "Enter key: ";
	cin >> key;

	data += string(key.length()-1, '0');
	string temp = data;

	while(data.length() >= key.length())
		_xor(data, key);

	temp.erase(temp.length()-data.length(), data.length());
	temp += data;

	cout << "CRC: " << data << "\n";
	cout << "Codeword: " << temp;
}

void receiver(){
	string data, key;
	cout << "Enter data received: ";
	cin >> data;

	cout << "Enter key: ";
	cin >> key;

	while(data.length() >= key.length())
		_xor(data, key);

	cout << "Remainder: " << data << "\n";
	if(data.length() == 0) cout << "No error detected";
	else cout << "Error detected";
}

int main(){
	int op;
    cout << "1. Sender's end\n2. Receiver's end\nInput: ";
    cin >> op;
    switch(op){
        case 1:
            sender();
            break;
        case 2:
            receiver();
            break;
        default:
            break;
    }
	return 0;
}