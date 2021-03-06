# Contents
* ## **[알고리즘](#알고리즘-1)**  
  * [Union Find](#union-find)  
  * [Two Pointers](#two-pointers)  
  * [위상 정렬](#위상-정렬)  
  * [최소 스패닝 트리(MST)](#최소-스패닝-트리mst)  
  * [다익스트라 알고리즘(Dijkstra's Algorithm)](#다익스트라-알고리즘dijkstras-algorithm)
  
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
  * [백준 19237 - 어른 상어](#백준-19237---어른-상어-code)  
  
* ## **[맞은 문제](#맞은-문제-1)**  
  * [백준 14890 - 경사로](#백준-14890---경사로-code)   
  * [백준 15684 - 사다리 조작](#백준-15684---사다리-조작-code)   
  * [백준 14891 - 톱니바퀴](#백준-14891---톱니바퀴-code)  
  * [백준 15685 - 드래곤커브](#백준-15685---드래곤커브-code)  
  * [백준 16236 - 아기 상어](#백준-16236---아기-상어-code)  
  * [백준 17142 - 연구소 3](#백준-17142---연구소-3-code)  
  * [백준 17140 - 이차원 배열과 연산](#백준-17140---이차원-배열과-연산-code)  
  * [백준 17779 - 게리맨더링2](#백준-17779---게리맨더링2-code)  
  * [백준 17837 - 새로운 게임2](#백준-17837---새로운-게임2-code)  
  * [백준 17822 - 원판 돌리기](#백준-17822---원판-돌리기-code) 
  * [백준 16637 - 괄호 추가하기](#백준-16637---괄호-추가하기-code)
  * [백준 17281 - ⚾](#백준-17281----code)
  * [백준 17406 - 배열 돌리기4](#백준-17406---배열-돌리기4-code)
  * [백준 17471 - 게리맨더링](#백준-17471---게리맨더링-code)
  * [카카오 겨울 인턴 1번 - 크레인 인형뽑기 게임](#카카오-겨울-인턴-1번---크레인-인형뽑기-게임-code)  
  * [SWEA 2105 - 디저트 카페](#SWEA-2105---디저트-카페-code)  
  * [백준 9466 - 텀 프로젝트](#백준-9466---텀-프로젝트-code)  
  * [백준 11051 - 이항 계수2](#백준-11051---이항-계수2-code)  
  * [백준 11286 - 절댓값 힙](#백준-11286---절댓값-힙-code)  
  * [백준 1644 - 소수의 연속합](#백준-1644---소수의-연속합-code)  
  * [백준 1806 - 부분합](#백준-1806---부분합-code)  
  * [백준 2096 - 내려가기](#백준-2096---내려가기-code)  
  * [백준 2623 - 음악프로그램](#백준-2623---음악프로그램-code)  
  * [백준 1516 - 게임 개발](#백준-1516---게임-개발-code)  
  * [백준 17472 - 다리 만들기2](#백준-17472---다리-만들기2-code)  
  * [백준 1922 - 네트워크 연결](#백준-1922---네트워크-연결-code)
  * [백준 6497 - 전력난](#백준-6497---전력난-code)  
  * [카카오 20 인턴 1번 - 키패드 누르기](#카카오-20-인턴-1번---키패드-누르기-code)  
  * [카카오 20 인턴 2번 - 수식 최대화](#카카오-20-인턴-2번---수식-최대화-code)  
  * [카카오 20 인턴 3번 - 보석 쇼핑](#카카오-20-인턴-3번---보석-쇼핑-code)  
  * [카카오 20 인턴 4번 - 경주로 건설](#카카오-20-인턴-4번---경주로-건설-code)
  * [백준 19238 - 스타트 택시](#백준-19238---스타트-택시-code)
  
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
<br>

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
<br>
  
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
<br>

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
<br>

### 다익스트라 알고리즘(Dijkstra's Algorithm)  
- 정점과 간선이 주어질 때 시작점에서부터 목표 지점까지의 최소 거리를 구하는 알고리즘.
- 조건으로는 간선의 길이가 항상 0 이상이 되어야한다.
- 방문하지 않은 정점들 중 최소 거리를 우선으로 방문한다. -> priority queue 이용.
- 방문하지 않은 정점의 최소 거리를 업데이트 시킬 순 있지만 방문한 정점은 재방문 x
- 그 이유는 이미 방문할 예정인 정점 중에서 최소 거리인 정점부터 방문하기 때문에
- 이미 방문한 정점은 다른 정점으로부터 최소 거리가 업데이트 될 수 없음.
- 풀이방법
1. 시작점에서 간선으로 이어지는 정점들의 거리를 업데이트 하고 priority queue에 정점 push.
2. pq의 top(방문 할 예정인 정점 중 최소)을 방문.
3. 이미 방문한 정점이라면 그냥 넘어간다.
4. pq가 empty일 때까지 while문을 실행하고 빠져나오면 결과를 출력.
  
~~~c++
dist[k-1] = 0; // 시작점을 0으로 초기화
pq.push(V(k-1,0));
while(!pq.empty()){
    V cur = pq.top(); pq.pop();
        
    if(visit[cur.n]) continue; // BFS와 다르게 방문할 시점에서 visit을 체크하고
    visit[cur.n] = true; // 방문하지 않았다면 방문함과 동시에 true로 바꿔준다.
        
    for(auto ee : adj[cur.n]){
        int next = ee.v;
        if(dist[next] <= cur.d + ee.w) continue;
            
        dist[next] = cur.d + ee.w;
        pq.push(V(next,dist[next]));
    }
}
~~~
  
<br>
<br>
  
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

### 백준 19237 - 어른 상어 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/19237/19237.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 시뮬레이션  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 입력부터 어떤 자료구조를 써야할지 고민하게 했던 문제.  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 조건들이 상당히 까다롭고 디버깅이 참 힘들었음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) for문이 돌던 중 vector erase를 수행해서 끝까지 돌지 못하고 끝남.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 삭제할 index를 저장해서 for문 끝나고 sort 시킨 후 뒤에서부터 erase.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 맵에 상어 번호를 적어야 하는 부분에서 vector index를 저장해서 틀렸음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 디버깅이 힘들어 질문 검색에 있는 반례를 통해 에러를 찾음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 꼼꼼하고 실수 없는 코딩만이 답이다....  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 이전과 같이 무언가를 잡아먹을 때 새로운 temp 맵을 만들어 상어들의 새로운 위치를 저장.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 잡아먹히는 객체는 맵에 저장하지 않는다.  
  
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
  
### 백준 15685 - 드래곤커브 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/15685/15685.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 단순 simulation 문제  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 지금까지 만들어진 방향을 vector에 저장.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 1세대를 그릴 때마다 vector의 역순으로 탐색.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 탐색을 하면서 각 방향에 +1을 해주고 그려줌.  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) Stack을 사용할까 생각했지만 vector로도 충분히 가능할 것 같아서 vector로 구현함.  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 생각해보니 Stack은 탐색이 힘들어서 적합하지 않을 듯.  
<br>
  
### 백준 16236 - 아기 상어 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/16236/16236.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) bfs의 반복문제  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 먹이를 찾았다고 bfs를 끝내면 안되고 해당 깊이까지는 다 돌아야함.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 해당 깊이에서 후보군에 넣을 때 조건이 필요함(0이 아니고 자신보다 작은 크기일 때)  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) bfs 순회 중 현재 깊이가 먹이를 먹은 깊이보다 많을 때 업데이트하고 return 시킴.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 이러면 먹이를 먹고 다음 깊이가 없다면 조건에 걸리지 않아 업데이트가 안됨.      
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 업데이트를 while문 밖에 두면 됨.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 그러면 조건에 걸려서 break되거나 더이상 순회할 좌표가 없을 때도 업데이트가 됨.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 단, 먹이를 먹을 때 값이 변하는 dd 값이 -1이라면 먹이를 못 먹은 경우이므로 return false.  
<br>
  
### 백준 17142 - 연구소 3 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/17142/17142.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 조합 찾기 후 bfs 문제  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 처음에 단순히 bfs가 끝나면 답을 업데이트 시켰음  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 이런 경우 빈칸이 다 없어져도 활성화되지 않은 바이러스도 활성화 시키느라 오답이 됨.      
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) bfs while에 들어가기 전에 빈칸의 개수를 세고 0개가 되면 while 탈출하도록 함.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 조합 찾을 때 dfs로 했는데 return 조건에서 실수함.  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 조합 찾는 방법으로 dfs 말고 next_permutation을 쓰면 간단해짐.  
<br>
  
### 백준 17140 - 이차원 배열과 연산 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/17140/17140.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) simulation 문제  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 배열을 검사해서 새로운 배열을 만드는 것은 구현했음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 하지만 시험장에서 풀었다면 시간이 부족했을 것 같음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 행마다 검사, 열마다 검사를 각각 따로 만들려고 했기때문.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 배열을 90도 돌리는 방법도 생각했지만 배열 모양이 정사각형이 아니기 때문에 불가능.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 생각해보니 회전이 아니라 행,열을 바꾸면 되는 문제였음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 계산하는 함수는 1개만 만들고 행,열을 바꿔주며 계속 진행함.  
<br>
  
### 백준 17779 - 게리맨더링2 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/17779/17779.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) simulation 문제  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 처음에 구역을 어떻게 나눌지에 대해 고민함.    
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 구역을 모두 5로 채운 다음 각 지역에 맞게 채우면 됨.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 1,3 구역은 열 0부터 시작해서 경계선에 만나면 다음 행으로 넘어감.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 2,4 구역은 열 n-1부터 시작해서 경계선에 만나면 다음 행으로 넘어감.  
<br>
  
### 백준 17837 - 새로운 게임2 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/17837/17837.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) simulation 문제  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 기본적인 구현은 다 했지만 부분부분 실수로 인해 시간이 지체됨.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 배열 값 업데이트 할 때 index 값도 업데이트 해야한다면 순서 주의하기.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 말이 이동할 때 if, else if로 파랑 or 빨강으로 했는데 이 부분에서 틀렸음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 말이 다음 칸이 파랑색이고 반대 방향도 빨강색일 때 if,else if에 의해 걸리지 않음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 파랑 빨강일 때를 각각 if문으로 구현한다.  
<br>
  
### 백준 17822 - 원판 돌리기 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/17822/17822.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) simulation, bfs 문제  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 기본적인 구현은 다 했지만 역시나 실수로 해맸음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) Queue 조건에서 값이 같을 때만 추가하는 것을 빼먹음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 삭제할 index 추가할 때 Queue 시작하는 지점을 넣지 않음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 역시나 코드 한줄 복붙하는 과정에서 값을 고치지 않아 계속 답이 안나옴.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 절대로 코드 복붙하지말고 실수 줄이려면 직접 쓰자.  
<br>
  
### 백준 16637 - 괄호 추가하기 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/16637/16637.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) dfs 문제       
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 문제에서 모든 연산자 우선순위는 같다고 했기 때문에 앞에서부터 차례대로 연산함.  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 핵심은 괄호를 어디에 넣을지인데 괄호안에는 연산자가 한개만 존재하기 때문에 쉬움.    
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) dfs를 이용하여 현재 지점에서 다음 숫자를 바로 연산할지 아니면  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 다음, 다다음 숫자를 괄호로 묶어서 연산할지 재귀로 들어가면 됨.  
<br>
  
### 백준 17281 - ⚾ [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/17281/17281.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 시뮬레이션  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) next_permutation을 쓰면 쉽게 풀리는 문제.  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 매 선수마다 각각의 경우를 구현해준다.   
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 루 배열을 만들어놓고 안타의 경우 루 배열에 따라 점수가 나도록 함.  
<br>
  
### 백준 17406 - 배열 돌리기4 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/17406/17406.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 시뮬레이션  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) next_permutation을 쓰면 쉽게 풀리는 문제.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 배열 index 값 실수함.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 회전시킬 때 4방향의 코드가 모두 비슷하므로 배열 index 값 실수 주의.  
<br>
  
### 백준 17471 - 게리맨더링 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/17471/17471.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) bfs 탐색, 조합  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) next_permutation을 쓰면 쉽게 풀리는 문제.    
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 고정 갯수의 조합이 아니기 때문에 for문 안에 do while( next_permutation ) 사용.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 서로 다 연결되어있는지 확인하기 위해서 bfs를 사용했음.  
<br>
  
### 카카오 겨울 인턴 1번 - 크레인 인형뽑기 게임 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EC%B9%B4%EC%B9%B4%EC%98%A4/%EA%B2%A8%EC%9A%B8%20%EC%9D%B8%ED%84%B4/1%EB%B2%88.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 명령에 맞게 인형을 옮기는 시뮬레이션  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) vector의 back(), pop_back()을 사용하면 쉬움.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+)  처음에 입력을 제대로 확인하지 않아서 틀림.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 입력은 위에부터 받기 때문에 아래부터 저장하는 새로운 2차원 vector를 만들어야함.    
<br>
  
### SWEA 2105 - 디저트 카페 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/SWEA/2105/2105.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 시뮬레이션.  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 백준 게리맨더링2와 같이 4중 for문을 이용.    
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 쉬운 문제였음.  
<br>
  
### 백준 9466 - 텀 프로젝트 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/9466/9466.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) dfs 문제  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 그룹 내에서 원소 찾을 때 vector의 find를 하니 시간초과가 났음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) n이 최대 10만이기 때문에 최악의 경우 계속 10만번 가까운 순회가 발생하게 됨.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) vector 대신에 map 사용해서 시간초과를 해결함.  
<br>
  
### 백준 11051 - 이항 계수2 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/11051/11051.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) dp 문제  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 모든 경우의 조합을 구하는 경우 시간초과가 남.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) nCk = (n-1)C(k-1) + (n-1)Ck 라는 특성을 이용해 dp로 문제를 품.  
<br>
  
### 백준 11286 - 절댓값 힙 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/11286/11286.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) priority queue 문제  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) pair 비교와 다르게 priority queue는 비교 함수 선언이 조금 달랐음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) compare 함수 선언에 대해서 다시 공부하게 됨.  
<br>
  
### 백준 1644 - 소수의 연속합 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/1644/1664.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) two pointers 문제  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) S, E를 가리키는 변수를 만들어 각각 움직이며 확인.   
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) S, E의 다음 값을 소수 중에서 골라야 함.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 하지만 매번 다음 소수를 정할 때마다 중복되는 과정이 있기 때문에 시간 초과가 남.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 소수를 구했을 때마다 check 변수에 소수인지 아닌지 저장해놓음.  
<br>
  
### 백준 1806 - 부분합 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/1806/1806.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) two pointers 문제  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) S, E를 가리키는 변수를 만들어 각각 움직이며 확인.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 길이의 최소 값을 구해야 하므로 조건을 만족할 때마다 답 갱신.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) E가 끝 지점에 왔을 때 else if( E == N ) 에 조건에 걸린다는 것은 이미 S 포인터를 움직여도 답을 찾을 수 없기 때문에 while문 종료시켜야함.  
<br>
  
### 백준 2096 - 내려가기 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/백준/2096/2096.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) DP 문제  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 제일 밑에부터 dp값을 갱신하면서 올라온다.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 계속 메모리 초과 문제가 발생했는데 이 문제에서는 10만 크기의 dp 배열을 만들 필요가 없었음.   
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 각 층에서 dp값을 계속 갱신하면서 올라오면 크기가 3~5면 충분함.  
<br>
  
### 백준 2623 - 음악프로그램 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/백준/2623/2623.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 위상 정렬  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 위상 정렬 풀이에 맞게 indegree, con 변수 값 전처리   
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 위상 정렬 풀이 법 익히기.  
<br>
  
### 백준 1516 - 게임 개발 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/백준/1516/1516.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 위상 정렬  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 위상 정렬을 만든 뒤 현재 노드가 가리키는 노드의 시간 업데이트  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 어떤 노드 ND가 있을 때, ND를 가리키는 노드 중 for, queue의 순서 상 가장 늦은 노드 시간 + ND의 시간으로 업데이트를 해서 틀림.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) ND를 가리키는 노드들 중 가장 긴 시간에서 ND의 시간을 더해줘야 함.  
<img src="https://user-images.githubusercontent.com/28804154/90214301-fd711880-de32-11ea-8dd1-4824e6a60215.png"  width="45%" height="45%">  
<br>
  
### 백준 17472 - 다리 만들기2 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/17472/17472.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) BFS, 조합  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) BFS로 섬을 구분한 뒤, 만들 수 있는 다리들을 저장.  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 다리들 중에서 섬 갯수 - 1개 만큼을 next permutation으로 조합을 구함.  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 선택된 다리들을 이용해 섬을 모두 방문할 수 있으면 답을 업데이트.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 처음에 다리 선택까지 했지만 섬을 다 방문할 수 있는지에 대한 풀이로 BFS를 생각 못함.   
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 1번 섬을 시작으로 BFS를 이용해 모든 섬을 방문할 수 있는지 검사한다.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) MST로 한번 더 풀어야함.  
<br>
  
### 백준 1922 - 네트워크 연결 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/1922/1922.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 최소 스패닝 트리  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 크루스칼 알고리즘을 이용하여 해결  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) Union Find 구현에서 "return uf[a] = find(uf[a])"의 이유를 몰랐음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) merge 함수에서 uf[a]는 바로 위 부모를 저장하기 때문에 find_uf 함수에서 불필요한 반복 탐색을 하므로 메모이제이션처럼 구현함.  
<br>
  
### 백준 6497 - 전력난 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/6497/6497.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 최소 스패닝 트리  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 크루스칼 알고리즘을 이용하여 해결  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 기본 MST와 같이 풀고 전체 cost에서 최소 cost를 뺀 값이 정답.  
<br>
  
### 카카오 20 인턴 1번 - 키패드 누르기 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/카카오/20%20인턴쉽/1번.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 시뮬레이션  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 쉬웠던 문제.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 숫자에 따라 왼손가락 위치, 오른손가락 위치를 업데이트한다.  
<br>
  
### 카카오 20 인턴 2번 - 수식 최대화 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/카카오/20%20인턴쉽/2번.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) string, 구현 문제    
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) string을 이용한 구현 문제라서 조금 까다로웠음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) split으로 숫자와 문자들을 쪼개 하나의 벡터에 저장한다.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) next_permutation으로 연산자 조합을 만든 뒤 위에서 만든 벡터를 순회한다.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 숫자이거나 해당 연산자가 아니라면 새로운 벡터에 쌓는다.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 해당 연산자라면 새 벡터의 마지막 숫자와 연산자 다음 숫자를 계산.( 마치 stack 처럼 )  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 만들어질 수 있는 수가 long long일수 있기 때문에 string에서 int로 바꿔 틀렸음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+)  string to long long의 함수는 atoll이다.  
<br>
  
### 카카오 20 인턴 3번 - 보석 쇼핑 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/카카오/20%20인턴쉽/3번.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) two pointers 문제  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 매번 모든 물건을 가지고 있는지 검사하는 것에서 시간 초과가 남  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) check가 true일 때는 continue를 해서 시간을 줄였지만 그래도 시간 초과가 남.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 물건 목록을 담고있는 map을 순회하면서 확인할 필요가 없었음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 물건 목록 map과 현재 물건들 목록 map의 크기가 같으면 조건 만족.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 코딩 테스트 당시 two pointer를 몰라서 아예 풀지 않았는데 공부하니 풀었음.  
<br>
  
### 카카오 20 인턴 4번 - 경주로 건설 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/카카오/20%20인턴쉽/4번.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) bfs 문제    
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 코딩테스트 당시 dfs를 메모이제이션을 이용했지만 답이 계속 틀려 실패.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 평소 bfs문제는 이동 가중치가 모두 같기 때문에 목적지에 먼저 도착하는 경로가 최소 경로임.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) **하지만 가중치가 있을 때는 최소 경로가 최소 가중치가 아님!!**  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 그래서 이 문제를 풀 때는 방문한 좌표를 다시 방문할 수 있다.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 하지만 조건으로는 가중치가 해당 좌표에 저장된 가중치보다 같거나 작아야함.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) dfs 메모이제이션으로 다시 풀어보자.  
<br>
  
### 백준 19238 - 스타트 택시 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/백준/19238/19238.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) bfs 문제  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 겉보기에 쉬운 문제였지만 귀찮은 조건들이 몇개 있었음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 비슷한 bfs를 각각 만들었는데 더 좋은 방법이 있을 듯 함.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 조건 구현을 조금 깔끔하지 못하게 했는데 코드 최적화가 필요 할 듯.      
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 좌표가 1부터 시작해서 런타임 에러가 발생함.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 좌표 실수는 절대 하지 말자!!  
<br>
