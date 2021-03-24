#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
int get_fibonacci_partial_sum(long long n, long long m) {
    std::vector<int> Fib(61,0);
    std::vector<int> sum(61,0);
    Fib[0]=0; Fib[1]=1;
    sum[0]=0; sum[1]=1;
    for(int i=2;i<61;i++){
        Fib[i]=(Fib[i-1]+Fib[i-2])%10;

        sum[i]=(sum[i-1]+Fib[i])%10;
    }
    /*
    for(int c:sum){
        std::cout<<c<<'\n';
    }
    std::cout<<"Val: "<<sum[60]<<'\n';
    */
    int val1;
    int val2;
    if(n<=60){
        val1= sum[n-1];
    }else{
        long long times=(n-1)/(int)60;
        //std::cout<<times<<'\n';
        int res=(n-1)%60;
        val1=(((times*sum[60])%10)+sum[res])%10;
    }
    if(m<=60){
        val2= sum[m];
    }else{
        long long times=m/(int)60;
        //std::cout<<times<<'\n';
        int res=m%60;
        val2=(((times*sum[60])%10)+sum[res])%10;
    }
    std::cout<<val1<<' '<<val2<<'\n';
    return abs((val2-val1))%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
