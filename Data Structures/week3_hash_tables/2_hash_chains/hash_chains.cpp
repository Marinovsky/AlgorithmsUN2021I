#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using std::string;
using std::list;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    list<string> *elems;
    long long mulmod(long long a, long long b,  long long mod) const{
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
    int hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (mulmod(hash, multiplier, prime) + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    QueryProcessor(int bucket_count2){
        bucket_count=bucket_count2;
        elems=new list<string>[bucket_count];
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            /*
            for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
                if (hash_func(elems[i]) == query.ind)
                    std::cout << elems[i] << " ";
            std::cout << "\n";
            */
            for(auto x: elems[query.ind]){
                cout<<x<<" ";
            }
            cout<<endl;
            //cout<<"check"<<endl;
        } else {
            //vector<string>::iterator it = std::find(elems.begin(), elems.end(), query.s);
            if (query.type == "find"){
                //writeSearchResult(it != elems.end());
                bool finded=false;
                for(auto x: elems[hash_func(query.s)]){
                    if(x==query.s){
                        finded=true;
                    }
                }
                writeSearchResult(finded);
                //writeSearchResult(elems[hash_func(query.s)].search(query.s));
                //cout<<"find"<<endl;
            }else if (query.type == "add") {
                /*
                if (it == elems.end())
                    elems.push_back(query.s);
                */
                int index=hash_func(query.s);
                list<string> :: iterator i;
                for(i=elems[index].begin();i!=elems[index].end();i++){
                    if(*i==query.s){
                        break;
                    }
                }
                if(i == elems[index].end()){
                    elems[hash_func(query.s)].push_front(query.s);
                }
                //cout<<"add"<<endl;
            } else if (query.type == "del") {
                /*
                if (it != elems.end())
                    elems.erase(it);
                */
                int index=hash_func(query.s);
                list<string> :: iterator i;
                for(i=elems[index].begin();i!=elems[index].end();i++){
                    if(*i==query.s){
                        break;
                    }
                }
                if(i != elems[index].end()){
                    elems[index].erase(i);
                }
                //elems[hash_func(query.s)].Delete(query.s);
                //cout<<"del"<<endl;
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
