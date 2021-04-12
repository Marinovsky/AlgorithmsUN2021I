#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}
long long mulmod(long long a, long long b,  long long mod){
        long long res=0;
        a=a%mod;
        while(b>0){
            if(b%2==1){
                res=(res+a)%mod;
            }
            a=(a*2)%mod;
            b=b/2;
        }
        return res%mod;
}
int hash_func(const string& s){
    static const size_t multiplier = 263; //x
    static const size_t prime = 1000000007;//prime number
    unsigned long long hash = 0;
    for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
        hash = (mulmod(hash, multiplier, prime) + s[i]) % prime;
    return hash;
}
vector<long long> precomputeHashes(string t, int p_len){
    vector<long long> H(t.length()-p_len +1, 0);
    long long p=1000000007;
    long long x=263;
    string s = t.substr(t.length()-p_len, p_len);
    //cout<<s<<endl;
    H[t.length()-p_len]=hash_func(s);
    //cout<<H[t.length()-p_len]<<endl;
    long long y=1;
    for(int i=1;i<=p_len;i++){
        y=mulmod(y, x, p);
    }
    //cout<<y<<endl;
    for(int i=t.length()-p_len-1;i>=0;i--){
        H[i]=((mulmod(x, int(H[i+1]), p)+t[i]-mulmod(y, t[i+p_len], p))%p+p)%p;
        //cout<<"- "<<H[i]<<" - "<<mulmod(x, int(H[i+1]),p)<<" "<<int(t[i])<<" "<<mulmod(y, t[i+p_len], p)<<endl;
    }
    return H;
}
vector<int> Rabin_Karp(string t, string p){
    vector<int> result;
    long long phash=hash_func(p);
    vector<long long> H=precomputeHashes(t, p.length());
    for(int i=0;i<=(t.length()-p.length());i++){
        if(phash==H[i]){
            if(t.substr(i, p.length())==p){
                result.push_back(i);
            }
        }
    }
    return result;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    Data temp=read_input();
    print_occurrences(Rabin_Karp(temp.text, temp.pattern));
    return 0;
}
