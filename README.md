# Contents
* ## **[알고리즘](#알고리즘-1)**  
  * [Union Find](#union-find)  
  * [Two Pointers](#two-pointers)  
  * [위상 정렬](#위상-정렬)  
  * [최소 스패닝 트리(MST)](#최소-스패닝-트리mst)  
  
* ## **[문법 및 함수 정리](#문법-및-함수-정리-1)**  
  * [lower_bound, upper_bound](#lower_bound-upper_bound)
  * [C++ 구조체 생성자 오버로딩](#c-구조체-생성자-오버로딩)
  * [map 순회](#map-순회)
  * [2차원 배열 특정 value 초기화](#2차원-배열-특정-value-초기화)
  * [2차원 배열 90도 회전](#2차원-배열-90도-회전)
  * [2차원 행,열 바꾸기](#2차원-행열-바꾸기)
  * [배열 내 최소, 최대값 구하기](#배열-내-최소-최대값-구하기)
  * [배열 복사](#배열-복사)
  * [2차원 vector 크기 및 값 초기화](#2차원-vector-크기-및-값-초기화)
  * [C++ split 함수 구현](#c-split-함수-구현)
  * [C++ split 함수 구현 2](#c-split-함수-구현-2)
  * [C++ replace all 구현](#c-replace-all-구현)
  * [Priority Queue cmp 함수 선언](#Priority-Queue-cmp-함수-선언)
  * [struct의 비교 함수 선언](#struct의-비교-함수-선언)  
  
* ## **[틀린 문제](#틀린-문제-1)**  
  * [백준 16235 - 나무 재테크](#백준-16235---나무-재테크-code)  
  * [백준 17143 - 낚시왕](#백준-17143---낚시왕-code)  
  * [SWEA 2382 - 미생물 격리](#SWEA-2382---미생물-격리-code)  
  * [백준 17136 - 색종이 붙이기](#백준-17136---색종이-붙이기-code)  
  * [SWEA 2112 - 보호 필름](#SWEA-2112---보호-필름-code)  
  * [SWEA 1949 - 등산로 조성](#SWEA-1949---등산로-조성-code)  
  * [백준 1655 - 가운데를 말해요](#백준-1655---가운데를-말해요-code)  
  * [백준 2003 - 수들의 합2](#백준-2003---수들의-합2-code)  
  * [백준 19236 - 청소년 상어](#백준-19236---청소년-상어-code)  
  
* ## **[맞은 문제](#맞은-문제-1)**  
  * [백준 14890 - 경사로](#백준-14890---경사로-code)   
  * [백준 15684 - 사다리 조작](#백준-15684---사다리-조작-code)   
  * [백준 14891 - 톱니바퀴](#백준-14891---톱니바퀴-code)   
  
<br>
<br>
  
# **알고리즘**
### **Union Find**  
- 여러 서로소 집합의 정보를 저장하고 있는 자료구조를 의미함.  
- 트리 구조로써 집합을 표현하고 경로 압축과 레벨 최적화 도입해서 유용함.  
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
  
### **Two Pointers**  
- 상당히 긴 배열이 주어지고 연속된 구간의 합을 구할 때 사용됨.
- **시작점 S, 끝점 E**를 가리키는 변수를 각각 만들어서 투 포인터라고 한다.
- S=0, E=0으로 시작해서 S==E 인 경우는 선택된 게 없는 부분 집합이다.
- 원하는 값 M보다 작으면 E가 가리키는 배열 값을 더한 뒤 E를 한 칸 옮긴다.
- M보다 크다면 S가 가리키는 배열 값을 빼준 뒤 S를 한 칸 옮긴다.
- 이 때 M 값과 같다면 답을 1 더해주고 S를 한 칸 옮긴다.
- 그리고 **E가 N에 도달**하면 계산을 끝낸다.

~~~c++
int s=0, e=0, sum=0, ans=0;
while(1){
    if(sum >= m) sum -= arr[s++];
    else if(e == n) break;
    else sum += arr[e++];
        
    if(sum == m) ans++;
}
~~~

### **위상 정렬**  
- 유향 그래프의 정점을 정렬.
- 그래프의 방향이 모두 한 방향으로 통일되도록 정렬함.
- 만약 역행하는 그래프가 있다면 그것은 싸이클의 존재를 의미함.
- 풀이 과정 
 1. 자신에게 연결되어 있지 않은 노드들을( indegree가 0 ) Queue에 push.
 2. N번만큼 for문을 수행, Queue의 front를 result[i]에 넣음.
 3. 자신이 가리키는 노드의 indegree를 감소시키고 0이라면 Queue에 push. ( 이 때 result[i]는 정렬된 노드의 순서 )  
**_만약 for문이 돌기 전에 Queue가 empty면 싸이클 존재를 의미함._**  
**_for문 도중 Queue의 크기가 2이상인 것은 답이 여러개를 의미함._**  

~~~c++
for(int i=0; i<N; i++){
    if(Q.empty()){
        return 0;
    }
 
    int cur = Q.front();
    Q.pop();
    result[i] = curr+1;
    for(int next: adj[curr])
        if(--indegree[next] == 0) Q.push(next);
}
~~~

### 최소 스패닝 트리(MST)  
- 트리의 간선마다 cost가 있을 때, 간선의 가중치 합이 최소인 스패닝 트리.
- MST를 위한 알고리즘은 프림, 솔린, 크루스칼 알고리즘이 있음.
- **크루스칼 알고리즘**
1. 간선들을 오름차순으로 모두 정렬시킴.
2. 정렬 순서대로 검사하면서 간선과 연결된 두 노드가 같은 그룹이면 다음으로 넘어가고 같은 그룹이 아니면 해당 간선을 선택하고 두 노드를 같은 그룹에 포함시킨다. ( Union Find 사용 )
3. 총 V-1개를 선택했으면 종료시키고 가중치 합을 구한다.  
**_같은 그룹인지 확인, 같은 그룹에 포함시킬 때는 Union Find를 이용한다._**

~~~c++
int sum=0, cnt=0;
for(int i=0; i<n; i++){
    if(merge(v[i].f,v[i].t)){
        sum += v[i].c;
        if(++cnt == m-1) break;
    }
}
~~~
  

# 문법 및 함수 정리
### lower_bound, upper_bound  
 - first부터 last까지 중 val 보다 크거나 같은 값의 첫 위치  
~~~c++
 lower_bound(first, last, val);  
~~~
 - first부터 last까지 중 val 보다 큰 값의 첫 위치  
~~~c++
 upper_bound(first, last, val);  
~~~  
  
### C++ 구조체 생성자 오버로딩  
~~~c++
typedef struct S{
      int x,y,z;
      S(){z=1;}
      S(int X, int Y, int Z) : x(X),y(Y),z(Z){}
  };
~~~  
  
### map 순회  
~~~c++
for(auto it=m.begin(); it!=m.end(); it++){
    cout << it->first << " " << it->second; // key, value 출력
}
~~~

### 2차원 배열 특정 value 초기화  
 - fill( 시작 주소, 종료 주소(마지막 원소 +1), value )
~~~
int dp[1000][1000];
fill(dp[0],dp[1000], 5); // dp[999][999]에서 +1이기 때문에 dp[1000]
~~~

### 2차원 배열 90도 회전
~~~c++
int temp_arr[100][100];
FOR(i,0,n) FOR(j,0,n) temp_arr[i][j] = arr[n-j-1][i];
memmove(arr,temp_arr,sizeof(arr)); // 새로 만든 배열을 기존 배열에 다시 복사
~~~

### 2차원 행,열 바꾸기
~~~c++
int temp_arr[100][100];
FOR(i,0,n) FOR(j,0,n) temp_arr[i][j] = arr[j][i];
memmove(arr,temp_arr,sizeof(arr));
~~~  
  
### 배열 내 최소, 최대값 구하기
 - 배열 내 최소,최대를 구하는 함수로써 비교 함수도 인자로 넣어줄 수 있다.  
 - 주의할 점은 배열의 return 값이 배열의 주소 값이기 때문에 *을 붙여줘야한다.  
~~~c++
*min_element(zSum, zSum+5);
*max_element(zSum, zSum+5);
~~~  
  
### 배열 복사
 - 다차원 배열의 경우도 복사가 가능하다.
~~~c++
memmove(temp, arr, sizeof(arr));
~~~
  
 - 2차원 배열의 행 단위로도 복사가 가능하다.
~~~c++
memmove(temp, arr[x], sizeof(temp));
~~~

### 2차원 vector 크기 및 값 초기화
 - 이런 경우 6x5의 vector를 0으로 초기화.
~~~c++
vector<vector<int> > arr(6, vector<int>(5, 0));
~~~
  
### C++ split 함수 구현
~~~c++
vector<string> split(string s, string d){
    vector<string> result;
    
    auto start = 0U;
    auto end = s.find(d);
    while (end != string::npos){
        result.push_back(s.substr(start, end - start));
        start = end + d.length();
        end = s.find(d, start);
    }
    result.push_back(s.substr(start, end));
    
    return result;
}
~~~
  
### C++ split 함수 구현 2
- split delimeter를 여러 개 지정하고 싶을 때 사용.
- 단 strtok의 인자로 string이 아닌 char배열이 들어가야함.
~~~c++
vector<string> split(string s){
    vector<string> sv;
    
    char cs[100];
    strcpy(cs,s.c_str());
    
    char* tok3 = strtok(cs,",+");
    while(tok3!=NULL){
        sv.push_back(tok3);
        tok3 = strtok(NULL,",+");
    }
    
    return sv;
}
~~~
  
### C++ replace all 구현
- x를 y로 replace.
~~~c++
replace( s.begin(), s.end(), 'x', 'y');
~~~
  
- string을 string으로 바꾸고 싶을 때
~~~c++
void ReplaceAll(string &s, const string &from, const string &to){
    size_t pos=0;
    while((pos=s.find(from,pos)) != string::npos){
        s.replace(pos,from.length(),to);
        pos += to.length();
    }
}
~~~
  
### cmp 함수 선언  
- 이 경우 string 길이에 따른 cmp 함수 선언.
~~~c++
bool cmp(string s, string s2){
    if(s.size() < s2.size()) return true;
    return false;
}
~~~

### Priority Queue cmp 함수 선언
- true가 return 되는 경우 a,b가 스왑됨.
~~~c++
struct cmp{
    bool operator()(int &a, int &b){
        return a > b;
    }
};
~~~
  
### struct의 비교 함수 선언
- struct 타입의 비교 연산자를 위한 경우
- 아래는 MST를 위한 struct 선언과 비교 함수 선언 코드.
~~~c++
typedef struct E{
    int f,t,c;
    E(int F, int T, int C) : f(F), t(T), c(C) {}
    bool operator <(const E& e)const{ return c < e.c; }
};
~~~
  
<br>
<br>
  
# 틀린 문제
### 백준 16235 - 나무 재테크 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/16235/16235.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 단순 simulation 문제      
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 각각의 나무를 vector의 2차원 배열로 표현했음.    
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 봄 계절에 양분을 얻지 못하는 나무는 죽은 나무로   표현하고 삭제하지 않음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 이유는 vector의 erase를 쓰고 싶지 않았기 때문에.    
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 하지만 데이터를 남기고 있던 것이 오히려 시간을 더 오래 걸리게 했음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) vector의 pop_back() 함수를 이용하면 해결가능함.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 원래는 pop_back을 안써서 vector의 뒤에서부터 탐색하며 erase를 했는데 대안이 생김.  
<br>
  
### 백준 17143 - 낚시왕 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/17143/17143.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) simulation 문제  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 상어 잡기, 상어 움직이기 모두 구현했는데, 상어가 겹칠 때 효율적으로 삭제시키는 방법을 알아야함.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 구현은 할 수 있겠지만 너무 비효율적인 방법인 것 같음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 삭제할 때 해당 좌표에 상어들을 다 넣어놓고 나중에 비교하고 삭제하려고 했음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 이렇게 하면 가장 큰 상어를 구할지라도 삭제하는 과정에서 vector의 erase를 사용하고 코드가 길어짐.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 구조체 S 타입으로 2차원 배열 선언하고 상어의 이동이 끝날 때마다 해당 위치 상어와 비교.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 크기가 크다면 덮어 씌우고 크기가 작다면 다음으로 넘어감.  
<br>
  
### SWEA 2382 - 미생물 격리 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/SWEA/2382/2382.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) simulation 문제  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 이전에 삼성 기출 낚시왕 문제를 풀면서 동일한 자리에 왔을 때 삭제하는 방법 적용.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 하지만 i 번째 미생물과 해당 자리에 있는 미생물을 비교하는 즉시 값을 더해버림.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 이러면 같은 자리에 계속 값이 누적되기 때문에 뒤에 미생물들을 다 삼켜버림.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 답은 겹치는 미생물 중에서 가장 큰 미생물의 방향을 따라야함.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 그래서 미생물을 삼킬 때마다 값을 바로 더하지말고 sum[nx][ny]에 누적시키고  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 최종적으로 남은 미생물 크기에 더해줌.  
<br>
  
### 백준 17136 - 색종이 붙이기 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/17136/17136.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) (0,0)에서 시작해 한 칸씩 움직이면서 5개 색종이를 붙이고 dfs 재귀 사용.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 색종이를 붙일 수 있는지에 대한 조건식에서 실수해버림.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) visit 변수에 대해서는 체크하지 않아서 시간 초과 및 오답이 나와버려서 해맸음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 조건 잘 보고 따지고, 굳이 visit 변수를 만들지 않고 배열 값을 0으로 만들면 됨.  
<br>
  
### SWEA 2112 - 보호 필름 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/SWEA/2112/2112.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) dfs 문제  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 각 줄마다 0 또는 1로 바꾸기 또는 바꾸지 않고 다음 depth로 넘어가기  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 문제의 구현자체는 크게 어렵지 않았지만 코드가 조금 더러운 느낌이 있음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 숏코딩 참고해보자  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 모든 행에 dfs를 진행하고 끝 행에 왔을 때 return 시키는 방법을 사용해서 시간초과 뜸.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 문제의 답은 무조건 k보다 클 수 없다는 점을 이용해서 n이 k보다 크면 return 시켜야함.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) dfs는 깊이 끝까지 간다는 점을 잘 생각하고 문제를 풀어야할 듯.  
<br>
  
### SWEA 1949 - 등산로 조성 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/SWEA/1949/1949.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) dfs 문제  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 문제 자체는 간단한 문제였지만 문제를 제대로 읽지 않음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 문제에서는 한 칸을 최대 k만큼 깎을 수 있다고 했기때문에 꼭 k만큼 깎지 않아도 됨.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+)  그리고 마지막으로 48개에서 통과 못하고 못 풀었던 부분은  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 봉우리를 깎을 때 현재 위치의 값보다 -1만큼만 깎으면 됨.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+)  오히려 더 깎으면 다음 진행에 있어서 악영향이 있기 때문.  
<br>
  
### 백준 1655 - 가운데를 말해요 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/1655/1655.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) priority queue 문제  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 수가 입력될 때마다 중간 번째 숫자를 출력하는 문제.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) priority queue를 1개만 사용하겠다는 고정관념에 사로잡혀 풀지 못했던 문제.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) priority queue 2개를 만들어 max heap, min heap으로 만든다.    
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) min heap의 top이 max heap의 top보다 큰 수가 들어오고  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) heap의 크기는 같거나 max heap이 1 더 크다.  
<br>
  
### 백준 2003 - 수들의 합2 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/2003/2003.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) S, E를 가리키는 변수를 만들어 각각 움직이며 확인.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 풀이 및 코드 숙달할 것.  
<br>

### 백준 19236 - 청소년 상어 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/19236/19236.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) dfs + 시뮬레이션  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 물고기들과 상어의 움직임으로 구현하고 dfs로 다음 단계를 들어가는 문제.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 답이 계속 틀렸지만 원인을 찾지 못했음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 그래서 결국 정답 코드를 디버깅해서 dfs 과정을 비교해서 문제를 알아냄.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 문제는 물고기들을 순서대로 움직이기 위한 변수를 dfs과정에 따라 백트래킹 하지 않음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 다른 것들은 모두 백트래킹을 구현했기 때문에 위의 변수만 추가로 백트래킹하니 맞았음.  
  
<br>
<br>
  
# 맞은 문제
### 백준 14890 - 경사로 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/14890/14890.cpp)  
&nbsp;&nbsp;![#111111](https://placehold.it/15/000000/000000?text=+) 단순 simulation 문제  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 경사로를 넣는 조건이 다양해서 조금 까다로웠음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 행, 열에 대해 답을 구해야 하는데 이런 경우 2차원 배열을 90도 돌리는 방법을 이용하면 쉬워짐.
<br>
  
### 백준 15694 - 사다리 조작 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/15684/15684.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 단순 simulation 문제 + dfs     
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 문제는 어렵지 않은데 구현이 귀찮았음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 히든케이스( 사다리를 놓지 않아도 통과되는 경우 )를 생각 못함.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 코드 너무 더럽게 짰음. 숏코딩 참고하자.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 꼭 다시 풀어보기!!
<br>
  
### 백준 14891 - 톱니바퀴 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/14891/14891.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 단순 simulation 문제     
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 돌리는 바퀴 기준으로 방향 변수에 대해 실수함.  
<br>
  
