#include <bits/stdc++.h>
#define M 1000001

using namespace std;

class Simplex{
    private:
    vector<vector<double>> a; // simplex tableaux
    int m,n,k; // M constraints, N variables
    vector<string> rows;
    vector<string> col;
    bool flag;
    public:
    Simplex(vector<vector<double>> A, vector<double> b, vector<double> c, vector<int> sign, int art_var){
        m=b.size();
        n=c.size();
        k=art_var;
        flag=true;
        //name=vector<string>(m+n);
        rows=vector<string>(m);
        col=vector<string>(n+m+k);
        a=vector<vector<double>>(m+1, vector<double>(m+n+k+1, 0.0));
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(b[i]<0){
                    a[i][j]=-A[i][j];
                }else{
                    a[i][j]=A[i][j];    
                }
            }
        }
        
        // Put I in the tableau
        for(int j=n;j<m+n;j++){
            if(b[j-n]<0){
                a[j-n][j]=-1.0;
            }else{
                a[j-n][j]=1.0;
            }
        }
        
        int index=0;
        // Put b in the tableau
        for(int j=0;j<m;j++){
            if(b[j]<0){
                a[j][m+n+k]=-b[j];
                a[j][(m+n)+index]=1.0;
                index++;
            }else{
                a[j][m+n+k]=b[j];
            }
        }
        // Put c in the tableau
        for(int j=0; j<n;j++){
            a[m][j]=-c[j];
        }
        
        // Put M in artificial variables of objective function
        for(int j=n+m;j<n+m+k;j++){
            a[m][j]=M;
        }
        // Name the basic variables
        for(int i=n;i<n+m;i++){
            string temp="w"+to_string(i-n);
            rows[i-n]=temp;
            col[i]=temp;
        }

        // Name the non-basic variables
        for(int i=0; i<n;i++){
            string temp="x"+to_string(i);
            col[i]=temp;
        }

        for(int i=n+m; i<n+m+k;i++){
            string temp="a"+to_string(i-(n+m));
            col[i]=temp;
        }
    }
    bool feasible(){
        //cout<<'\n';
        for(int i=m+n;i<m+n+k;i++){
            // Find a row with only one 1 in the i-th column
            int row=0;
            for(int j=0;j<m;j++){
                if(a[j][i]==1){
                    row=j;
                    break;
                }
            }
            // Replace objective function z by -M*row(j)+z
            for(int j=0; j<m+n+k+1;j++){
                a[m][j]+=(-M)*a[row][j];
            }
            rows[row]=col[i];
        }
        //print_tableaux();
        // Find Basic variables
        vector<bool> rows_used(m,0);
        vector<pair<int, int>> basic;
        for(int j=0; j<m+n+k;j++){
            bool find=false;
            int row=0;
            for(int i=0;i<m+1;i++){
                if(a[i][j]!=0){
                    if(find){
                        find=false;
                        break;
                    }else{
                        row=i;
                        find=true;
                    }
                }
            }
            if((find)&&(rows_used[row]==0)){
                basic.push_back(make_pair(row,j));
                rows_used[row]=1;
            }
        }

        // Check if there exist a solution
        bool feasible_sol=true;
        for(auto c:basic){
            if(a[c.first][c.second]*a[c.first][m+n+k]<0){
                feasible_sol=false;
            }
        }
        if(feasible_sol){
            return true;
        }else{
            return false;
        }
    }
    int bland_(){
        int min=0;
        double min_val=0;
        for(int q=0; q<m+n+k;q++){
            if((a[m][q]<min_val)&&(a[m][q]<0)){
                min=q;
                min_val=a[m][q];
            }
        }
        if(min_val==0){
            return -1;
        }else{
            return min;
        }
    }
    int minRatio(int q){
        int p=-1; // Leaving row
        for(int i=0; i<m;i++){
            if(a[i][q]<=0){ // Consider only positive entries
                continue;
            }else if(p==-1){
                p=i;
            }else if((a[i][m+n+k]/a[i][q]) < a[p][m+n+k]/a[p][q]){ // row p has minimum ratio so far
                p=i;
            }
        }
        return p;
    }
    void pivot(int p, int q){
        rows[p]=col[q];
        // Scale all entries but row p and column q
        for(int i=0; i<=m;i++){
            for(int j=0; j<=m+n+k;j++){
                if((i!=p)&&(j!=q)){
                    a[i][j]-= a[p][j]*a[i][q]/a[p][q];
                }
            }
        }
        // Zero out column q
        for(int i=0;i<=m;i++){
            if(i!=p){
                a[i][q]=0.0;
            }
        }
        // Scale row p
        for(int j=0; j<=m+n+k;j++){
            if(j!=q){
                a[p][j]=a[p][j]/a[p][q];
            }
        }
        a[p][q]=1.0;

    }
    bool check(vector<double> x){
        for(int i=0; i<m;i++){
            double sum=0;
            for(int j=0; j<n;j++){
                sum+=A_[i][j]*x[j];
            }
            if(round(sum)>round(b_[i])){
                //cout<<"False: "<<sum<<" "<<b_[i]<<'\n';
                return false;
            }
        }
        return true;
    }
    void solve(){
        while(true){
            int q=bland_();
            if(q==-1){
                break; // We have the optimal solution
            }
            int p=minRatio(q);

            if(p==-1){
                cout<<"Infinity"<<'\n'; // The solution is unbounded
                flag=false;
                break;
            }
            pivot(p,q);
        }
    }
    void print(){
        //print_tableaux();
        if(flag){
            vector<double> result(n,0.0);
            for(int i=0; i<m;i++){
                if(rows[i][0]=='x'){
                    int temp=rows[i][1]-'0';
                    result[temp]=a[i][m+n+k];
                }
            }
            bool solution=check(result);
            if(solution){
                cout<<"Bounded solution"<<'\n';
                for(auto c: result){
                    cout<<setprecision(20);
                    cout<<fixed<<c<<" ";
                }
            }else{
                cout<<"No solution"<<'\n';
            }
            
        }
    }
    double optimal_val(){
        return a[m][n+m];
    }
    void print_tableaux(){
        for(int i=0; i<m+1;i++){
            for(int j=0; j<n+m+k+1;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
};

int main(){
    int m, n, art_var;
    art_var=0;
    cin>>n>>m;
    vector<vector<double>> A(n, vector<double>(m, 0.0));
    vector<double> b(n,0.0);
    vector<int> sign(n,0);
    vector<double> c(m, 0.0);
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0; i<n;i++){
        cin>>b[i];
        if(b[i]<0){
            sign[i]=1;
            art_var++;
        }
    }
    for(int i=0; i<m;i++){
        cin>>c[i];
    }
    Simplex lp(A,b,c,sign, art_var);
    lp.feasible();
    //lp.print_tableaux();
    lp.solve();
    //lp.print_tableaux();
    lp.print();
}