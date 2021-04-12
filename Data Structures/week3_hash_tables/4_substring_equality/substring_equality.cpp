#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

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
long long power(unsigned long long x, unsigned long long y, long long p)
{
    int res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

class Solver {
private:
	string s;
	vector<long long> h1;
	vector<long long> h2;
	int x=263;
	long long m1=1000000009;
    long long m2=1000000007;
public:
	Solver(string s1){
		s=s1;
		h1.resize(s.length()+1);
		h2.resize(s.length()+1);
		h1[0]=0;
		h2[0]=0;
		for(int i=1; i<=s.length();i++){
            //h1[i]=((x*h1[i-1]+s[i])%m1+m1)%m1;
            //h2[i]=((x*h2[i-1]+s[i])%m2+m2)%m2;
            h1[i]=((mulmod(x,h1[i-1],m1)+s[i-1])%m1+m1)%m1;
            h2[i]=((mulmod(x,h2[i-1],m2)+s[i-1])%m2+m2)%m2;
            //cout<<((mulmod(x,h1[i-1],m1)+s[i])%m1+m1)%m1<<" "<<((mulmod(x,h2[i-1],m2)+s[i])%m2+m2)%m2<<endl;
            //cout<<h1[i]<<" "<<h2[i]<<endl;
		}
	}

	bool ask(int a, int b, int l) {
		long long temp=power(x,l,m1);
		long long temp2=power(x,l,m2);
		long long a_1=((h1[a+l]-mulmod(temp,h1[a], m1))%m1+m1)%m1;
		long long a_2=((h1[b+l]-mulmod(temp,h1[b], m1))%m1+m1)%m1;
		long long b_1=((h2[a+l]-mulmod(temp2,h2[a], m2))%m2+m2)%m2;
		long long b_2=((h2[b+l]-mulmod(temp2,h2[b], m2))%m2+m2)%m2;
        /*
		long long a_1_=((h1[a+l]-temp*h1[a])%m1+m1)%m1;
		long long a_2_=((h1[b+l]-temp*h1[b])%m1+m1)%m1;
		long long b_1_=((h2[a+l]-temp*h2[a])%m2+m2)%m2;
		long long b_2_=((h2[b+l]-temp*h2[b])%m2+m2)%m2;
		cout<<a_1<<" "<<a_2<<" - "<<b_1<<" "<<b_2<<endl;
		cout<<a_1_<<" "<<a_2_<<" - "<<b_1_<<" "<<b_2_<<endl;
		*/
		if((a_1==a_2)&&(b_1==b_2)){
            return true;
		}else{
            return false;
		}
	}
};

int main() {
    ///*
	std::ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
	//*/
	//cout<<int('l')<<endl;
	return 0;
}
