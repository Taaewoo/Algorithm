#include <iostream>
using namespace std;

pair<int,int> p[100000];

int main(){
   int T;
   
   scanf("%d", &T);

   for(int t=0; t<T; t++){
      int n,total=0;

      scanf("%d", &n);

      for(int i=0; i<n; i++){
         scanf("%d", &p[i].first);
         scanf("%d", &p[i].second);
      }

	  sort(p,p+n);

	  int min = p[0].second;
      for(int i=0; i<n; i++){
		  if(min >= p[i].second){
            total++;
			min = p[i].second;
         }
      }

      printf("%d\n", total);
   }
}
