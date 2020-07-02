# Contents
* ## **[알고리즘](#알고리즘)**  
  * [Union Find](#union-find)  
  * [Two Pointers](#two-pointers)  
  * [위상 정렬](#위상-정렬)  
  * [최소 스패닝 트리(MST)](#최소-스패닝-트리(MST))  
  
* ## **[문법 및 함수 정리](#문법-및-함수-정리)** 
  * [for문 매크로](#for문-매크로)  
  * [lower_bound, upper_bound](#lower_bound,-upper_bound)
  
#  
#
#

# 알고리즘
### Union Find  
여러 서로소 집합의 정보를 저장하고 있는 자료구조를 의미함.  
트리 구조로써 집합을 표현하고 경로 압축과 레벨 최적화 도입해서 유용함.  
```c++
int find(int a){
    if(uf[a] < 0) return a;
    return uf[a] = find(uf[a]); //merge에서는 바로 위 부모만 저장하기 때문에 메모이제이션처럼 구현.
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return false;
    uf[b] = a;
    return true;
}
```
  
### Two Pointers  

### 위상 정렬  

### 최소 스패닝 트리(MST)  


# 문법 및 함수 정리
### for문 매크로  

### lower_bound, upper_bound  
