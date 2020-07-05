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
  
* ## **[틀린 문제](#틀린문제-1)**  
  * [백준 16235 - 나무 재테크](#백준-16235---나무-재테크-code)    
  
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
  
# 틀린 문제
### 백준 16235 - 나무 재테크 [(Code)](https://github.com/Taaewoo/Algorithm/blob/master/%EB%B0%B1%EC%A4%80/16235/16235.cpp)  
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 단순 simulation 문제      
&nbsp;&nbsp;![#000000](https://placehold.it/15/000000/000000?text=+) 각각의 나무를 vector의 2차원 배열로 표현했음.    
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 봄 계절에 양분을 얻지 못하는 나무는 죽은 나무로   표현하고 삭제하지 않음.  
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 이유는 vector의 erase를 쓰고 싶지 않았기 때문에.    
&nbsp;&nbsp;![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 하지만 데이터를 남기고 있던 것이 오히려 시간을 더 오래 걸리게 했음.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) vector의 pop_back() 함수를 이용하면 해결가능함.  
&nbsp;&nbsp;![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 원래는 pop_back을 안써서 vector의 뒤에서부터 탐색하며 erase를 했는데 대안이 생김.  
