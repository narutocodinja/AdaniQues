#include<bits/stdc++.h>
using namespace std;
int col_index;

vector<vector<int>> create_matrix(int no_rows, int no_cols){
    srand(time(0)); // to generate different random numbers each time

    vector<vector<int>> arr(no_rows, vector<int>(no_cols,0));
    for(int i = 0; i < no_rows; i++){
        for(int j = 0; j < no_cols; j++){
            arr[i][j] = 0 + rand() % 100; // to generate between 0 to 100
        }
    }
    return arr;
}

bool sort_col(const vector<int>& v1, const vector<int>& v2)
{
    return v1[col_index] < v2[col_index];
}

vector<vector<int>> sort_matrix_cols(vector<vector<int>>& arr, int col_index){
    sort(arr.begin(), arr.end(), sort_col);
    return arr;
}

void print_matrix(vector<vector<int>>& arr){
    cout << "\n";
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "\n";
}

int main(){
    cout << "Program to sort 2d-matrix based on given column index keeping rows intact" << endl;

    int no_rows, no_cols;
    cout << "Enter Number of Rows : " << "\n";
    cin >> no_rows;

    cout << "Enter Number of Cols : " << "\n";
    cin >> no_cols;

    vector<vector<int>> arr(no_rows,vector<int>(no_cols));
    arr = create_matrix(no_rows,no_cols);

    cout << "Enter column index for sort (from 0 to Number of Columns) : " << endl;
    cin >> col_index;
    
    if(col_index < 0 || col_index > no_cols){
        cout << "Invalid Index" << "\n";
        return 0;
    }

    cout << "Matrix Before Sort : " << endl;
    print_matrix(arr);

    sort_matrix_cols(arr, col_index);

    cout << "Matrix After Sort : " << endl;
    print_matrix(arr);

    return 0;
}
