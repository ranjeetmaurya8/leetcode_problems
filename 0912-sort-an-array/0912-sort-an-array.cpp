class Solution {
public:

    void merge(vector<int>& arr,int  st, int mid, int end){
        vector<int> temp;

       int i = st, j = mid+1;

       while(i<= mid && j<= end){
        if(arr[i]>=arr[j]){
            temp.push_back(arr[j]);
            j++;

        }
        else{
            temp.push_back(arr[i]);
            i++;
        }
       }

    while(i<=mid){
         temp.push_back(arr[i]);
            i++;

    }
    while(j<=end){
         temp.push_back(arr[j]);
            j++;

        }

    for(int idx = 0 ; idx < temp.size(); idx++ ){
        arr[idx+st] = temp[idx];
    }
}

    void mergesort(vector<int>& arr,int  st, int end ){
        if(st<end){

        int mid  = st+(end -st)/2;

        mergesort(arr, st, mid);  // for left half
        mergesort(arr, mid+1, end); // for second half

        merge(arr, st , mid, end);
        }
    }
    vector<int> sortArray(vector<int>& arr) {

        mergesort(arr, 0, arr.size()-1);

        return arr;
    }
        
};