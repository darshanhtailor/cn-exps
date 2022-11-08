#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int convert(char x){
    return x-'0';
}

char convert(int x){
    return x+'0';
}

int bin2dec(string str){
    int ret = 0, len = str.length();
    for(int i = 0; i < len; i++)
        ret += convert(str[i])*(1<<(len-i-1));
    return ret;
}

void sender(){
    string data;
    cout << "Enter data to send: ";
    cin >> data;

    int n = data.length(), r = 0;
    while((1<<r) < n+r+1) r++;
    int len = n+r;

    string toSend(len, '0');
    int pwr = 0, idx = n-1;
    for(int i = len-1; i >= 0; i--){
        if((1<<pwr) == len-i) pwr++;
        else{
            toSend[i] = data[idx];
            idx--;
        }
    }

    vector<int> nums(len+1);
    for(int i = 0; i < len+1; i++) nums[i] = i;

    pwr = 0;
    for(int i = len-1; i >= 0; i--){
        if((1<<pwr) == len-i){
            bool f = false, x = 0;
            for(int j = 1; j <= len; j++){
                if(nums[j]&1 and !f) f = true;
                else if(nums[j]&1) x ^= convert(toSend[len-j]);
                nums[j] >>= 1;
            }
            toSend[i] = convert(x);
            pwr++;
        }
    }

    int x = 0;
    for(auto &y:toSend) x ^= convert(y);
    toSend = convert(x) + toSend;

    cout << "Message sent: " << toSend;
}

void receiver(){
    string data;
    cout << "Enter data received: ";
    cin >> data;

    int p = 0;
    for(auto &x:data) p ^= convert(x);
    char bit1 = data[0];
    data.erase(0, 1);

    int n = data.length();
    vector<int> nums(n+1);
    for(int i = 0; i < n+1; i++) nums[i] = i;

    string cstr = "";
    while(!all_of(nums.begin(), nums.end(), [](int i){ return !i; })){
        int x = 0;
        for(int i = 1; i <= n; i++){
            if(nums[i]&1)
                x ^= convert(data[n-i]);
            nums[i] >>= 1;
        }
        cstr += convert(x);
    }
    reverse(cstr.begin(), cstr.end());
    int c = bin2dec(cstr);

    cout << "c(binary): " << cstr << ", c: " << c << ", p: " << p << "\n";

    if(c == 0 and p == 0) cout << "No error detected";
    else if(c == 0 and p == 1){
        cout << "Error in parity bit\n";
        data = bit1 + data;
        data[0] = convert(!convert(data[0]));
        cout << "Correct message: " << data;
    } else if(c != 0 and p == 0){
        cout << "Double bit error detected. Cannot be corrected.";
    } else if(c != 0 and p == 1){
        cout << "Single bit error detected in bit " << c << "\n";
        data[n-c] = convert(!convert(data[n-c]));
        cout << "Correct message: " << bit1+data;
    }
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