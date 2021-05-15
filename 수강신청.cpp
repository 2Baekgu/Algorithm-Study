#include <iostream>
using namespace std;

int main(){
     std::ios::sync_with_stdio(false);
   int student_id, a, b;// 입력받는 학번, 수강가능 인원, 입력받는 수
   cin >> a >> b;
   int arr[b];
   int arr_2[b];
   int answer[a];
   int k = 0;
   for (int i = 0; i < b; i++)
   {
       cin >> student_id;
       arr[i] = student_id;
       arr_2[i] = student_id;
   }
   
   for(int i = 0; i<b; i++){
       for (int j = b-1; j > i; j--){
           if (arr[i] == arr_2[j]){
               arr[i] = -1;
           }
       }
   }
   for (int i = 0; i < b; i++)
   {
       if(arr[i] != -1 && k<3){
           answer[k] = arr[i];
           k++;
       }
   }
   for (int i = 0; i < a; i++)
   {
       cout << answer[i] << '\n';
   }
   return 0;
}