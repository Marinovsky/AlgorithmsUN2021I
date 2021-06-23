#include <bits/stdc++.h>

using namespace std;

void diagonal_matrix(vector<vector<double>> &matrix){
    int col=matrix.size()-1;
    int row=-1;
    for(int i=0; i<matrix.size();i++){
        for(int j=i;j<matrix.size();j++){
            if(matrix[j][i]!=0.0){
                swap(matrix[j],matrix[i]);
                break;
            }
        }
    }
}

int main(){
    int size;
    cin>>size;
    vector<vector<double>> matrix (size, vector<double>(size+1,0.0));
    for(int i=0; i<size;i++){
        for(int j=0; j<size+1;j++){
            cin>>matrix[i][j];
        }
    }
    diagonal_matrix(matrix);
    /*
    for(int i=0; i<size;i++){
        for(int j=0; j<size+1;j++){
            std::cout.precision(20);
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"-------------------------------"<<'\n';
    */
    for(int i=0; i<size;i++){
        if(matrix[i][i]==0.0){
            continue;
        }
        for(int j=0; j<size;j++){
            if(i!=j){
                double scalar=matrix[j][i]/matrix[i][i];
                for(int k=0; k<size+1;k++){
                    matrix[j][k]=matrix[j][k]-(scalar*matrix[i][k]);
                }   
            }
        }
    }
    vector<double> result(size, 0.0);
    for(int i=0; i<size;i++){
        if(matrix[i][i]!=0.0){
            result[i]=matrix[i][size]/matrix[i][i];
        }   
    }
   for(int i=0; i<size;i++){
       std::cout.precision(20);
       cout<<fixed<<result[i]<<" ";
   }

}