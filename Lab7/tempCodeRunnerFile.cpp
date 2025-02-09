   vector<int> mat(n + s);
   vector<int>::iterator it;

   it = set_intersection(arr.begin(), arr.end(), v.begin(), v.end(), mat.begin());
    
   for (int i = 0; i < mat.size(); i++){
        if(mat[i] != 0){
            cout << mat[i] << " ";  
        }
        else{
            break;
        }
   }