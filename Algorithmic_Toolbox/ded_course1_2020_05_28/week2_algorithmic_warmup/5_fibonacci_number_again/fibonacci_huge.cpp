#include <iostream>
#include <string>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long Size(int m) {
    std::vector<int> Fib((m*m),0);

    Fib[0]=0;
    Fib[1]=1;
    long long pos=0;

    for(long long i=2; i<=m*m;i++){
        Fib[i]=(Fib[i-1]+Fib[i-2])%m;
        //std::cout<<Fib[i]<<'\n';
        if(Fib[i]==0){
            pos=i;
            if((Fib[i]+Fib[i-1])%m==1){
                break;
            }
        }
    }
    if(pos!=0){
        return pos;
    }else{
        return 0;
    }
}
long long get_fibonacci_huge(long long n, int m){
    long long pattern=Size(m);
    while(n%pattern>=pattern){
        n=n%pattern;
    }
    long long Fib[n%pattern+1];
    Fib[0]=0;
    Fib[1]=1;
    for(int i=2; i<(n%pattern)+1;++i){
        Fib[i]=(Fib[i-1]+Fib[i-2])%m;
    }
    return Fib[n%pattern];
}

int main() {

    //long long n, m;
    //std::cin >> n >> m;
    /*
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    */
    //std::string a="01";
    std::cout<<Size(10)<<'\n';
    //std::cout<<get_fibonacci_huge(n,m)<<'\n';
    return 0;
}
