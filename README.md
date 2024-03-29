# Contents
* ## **[문법 및 함수 정리](#문법-및-함수-정리-1)**
* ### [Python](#python-1)
  * [Queue 사용](#queue-사용)
  * [Priority Queue 사용](#priority-queue-사용)
  * [변수 값 일괄 수정](#변수-값-일괄-수정)
  * [시간 Stinrg을 int형 분 또는 초로 계산하기](#시간-Stinrg을-int형-분-또는-초로-계산하기)
  * [Binary Search 함수 사용](#Binary-Search-함수-사용)
  * [삼항 연산자](#삼항-연산자)
  * [Dictionary key 값 여부에 상관 없이 List에 값 append 하기](#Dictionary-key-값-여부에-상관-없이-List에-값-append-하기)
  * [Deep Copy](#deep-copy)
  * [Reversed for문](#reversed-for문)
  * [공백문자열을 공백으로 split](#공백문자열을-공백으로-split)
  * [2차원 배열 초기화](#2차원-배열-초기화)
  * [2차원 배열 정렬](#2차원-배열-정렬)
  

* ## **[알고리즘](#알고리즘-1)**  
  * [Union Find](#union-find)  
  * [Two Pointers](#two-pointers)  
  * [Counting Sort](#Counting-Sort)  
  * [위상 정렬](#위상-정렬)  
  * [최소 스패닝 트리(MST)](#최소-스패닝-트리mst)  
  * [다익스트라 알고리즘(Dijkstra's Algorithm)](#다익스트라-알고리즘dijkstras-algorithm)
 
  
* ## **다시 풀어볼 문제**  
  * [[LeetCode] 11. Container With Most Water](https://github.com/Taaewoo/Algorithm/tree/master/LeetCode/011~020/11)
  * [[LeetCode] 15. 3Sum](https://github.com/Taaewoo/Algorithm/tree/master/LeetCode/011~020/15)
  * [[LeetCode] 25. Reverse Nodes in k-Group](https://github.com/Taaewoo/Algorithm/tree/master/LeetCode/25-reverse-nodes-in-k-group)
  * [[LeetCode] 26. Remove Duplicates from Sorted Array](https://github.com/Taaewoo/Algorithm/tree/master/LeetCode/26-remove-duplicates-from-sorted-array)
  * [[KaKao] 22 신입 1차 5. 양과 늑대]()
  * [[KaKao] 2022 KAKAO TECH INTERNSHIP 3. 등산코스 정하기](https://github.com/Taaewoo/Algorithm/tree/master/Kakao/2022%20KAKAO%20TECH%20INTERNSHIP/118669.%E2%80%85%EB%93%B1%EC%82%B0%EC%BD%94%EC%8A%A4%E2%80%85%EC%A0%95%ED%95%98%EA%B8%B0)
  * [[KaKao] 2022 KAKAO TECH INTERNSHIP 4. 코딩 테스트 공부](https://github.com/Taaewoo/Algorithm/tree/master/Kakao/2022%20KAKAO%20TECH%20INTERNSHIP/118668.%E2%80%85%EC%BD%94%EB%94%A9%E2%80%85%ED%85%8C%EC%8A%A4%ED%8A%B8%E2%80%85%EA%B3%B5%EB%B6%80)
  
  
* ## **알고리즘 메모**  
  * 연속된 index의 배열 합 -> 구간 합.
  * BFS에서 노드의 visit 체크를 하면 안되는 경우 -> 노드마다 max 또는 min 값을 저장하고 최적 값 발견 시 Queue에 추가 및 값 업데이트
  
<br>
<br>
  
# 문법 및 함수 정리
## Python
### Queue 사용
 - Python에서는 Queue 자료구조가 따로 존재하지 않음.
 - Deque로 Queue 기능 사용

~~~python
from collections import deque

q = deque([1,2,3])
q.append(7)
q.append(8)
print(q)
# deque([4, 5, 6, 7, 8])

print(queue.popleft())
# 5

~~~

### Priority Queue 사용
 - heapq package를 사용하는 것이 일반 PriorityQueue보다 더 빠름
 - "queue_name" list에 val 값 넣기
~~~python
 heapq.heappush(queue_name, val)
~~~
 - "queue_name" list에서 priority value 꺼내기 ( 삭제 포함 )
~~~python
 heapq.heappop(queue_name)
~~~
 - "queue_name" list에서 priority value 모두 꺼내기
~~~python
while queue:
    heapq.heappop(queue)
~~~

### 변수 값 일괄 수정
 - 다수의 변수 값을 서로 바꿔야할 때 사용
 - 각각의 변수 값이 변하지 않은 채로 업데이트 되기 떄문에 유용
 ~~~python
a = 1
b = 2
c = 3

a,b,c = b,a,b

# 2,1,2
print(a,b,c)
~~~

### 시간 Stinrg을 int형 분 또는 초로 계산하기
 - 시:분 일 때 분으로 환산  
~~~python
times = "01:30"
time_table = [60,1]
sum([a*b for a,b in zip(time_table,map(int,times[i+1].split(":")))])
~~~

 - 시:분:초 일 때 초로 환산  
~~~python
times = "01:30:25"
time_table = [3600,60,1]
sum([a*b for a,b in zip(time_table,map(int,times[i+1].split(":")))])
~~~

### Binary Search 함수 사용
 - List에서 특정 숫자가 들어갈 index를 얻을 수 있음.
 - 이 때 동일한 숫자가 List 안에 있을 때 기준이 필요함.
   - 동일한 숫자 앞에 위치시킬 것인가? -> bisect_left(list, num)
   - 동일한 숫자 뒤에 위치시킬 것인가? -> bisect_right(list, num)

~~~python
from bisect import bisect_left, bisect_right

l = [1,3,4,5,5,5,6]
bisect_left(l, 5) # 결과 값 : 3
bisect_right(l, 5) # 결과 값 : 6
~~~

### 삼항 연산자
 - (True일 때 value) if (조건) else (False일 때 value)

~~~python
val = 3 if True else 2

print(val) # 3
~~~


### Dictionary key 값 여부에 상관 없이 List에 값 append 하기
 - Dictionary의 value가 List라면 Dictionary의 key 값을 항상 체크해야했음.
   - 1줄짜리 코드가 if, else 까지 4줄이 되어버림.
 - Dictionary의 setdefault 함수를 사용하면 key 여부에 상관 없이 append 가능.

~~~python
dic = {}

dic.setdefault("aa",[]).append(11)

print(dic["aa"]) # 11
~~~

### Deep Copy
 - Deep Copy를 하게 되면 주소 값 복사가 아니기 때문에 서로 다른 객체가 됨.

~~~python
import copy

l = [[1,2,3],[4,5,6],[7,8,9]]

tmp_l = copy.deepcopy(l)

tmp_l[0][0] = 6

print(l)

# [[1,2,3],[4,5,6],[7,8,9]]
~~~

### Reversed for문
 - List 객체를 역방향으로 for문을 돌리고 싶을 때 효율적인 방법.
 - reversed() 메소드를 사용.
 - 직관적인 생각으로는 range()를 사용하여 마지막 index부터 접근할 수 있지만, 가독성에 문제가 있음.
 - Slicing으로 list[::-1] 하는 방법이 있지만, 메모리 효율이 좋지 못함.
 - reversed() 메소드는 Iterator를 사용하기 때문에 효율적이고 편함.

~~~python
list = [1,2,3]

for l in reversed(list):
    print(l)

# 3
# 2
# 1
~~~

### 공백문자열을 공백으로 split
 - 공백으로 이루어진 문자열을 공백으로 split을 하면 어떻게 될까?
 - 공백으로 기준으로 "" 길이 0인 문자열이 원소로 추가됨.

~~~python
print("   ".split(" "))

# ['', '', '', '']
~~~

### 2차원 배열 초기화
 - 파이썬의 경우 1차원 배열에 * 연산으로 2차원을 만들면 같은 주소 값이 되기 때문에 안됨.

~~~python
array = [ [0]*n for _ in range(n) ]
~~~

### 2차원 배열 정렬
 - lambda를 사용하여 2차원 배열 각 index에 맞게 정렬하는 방법.

~~~python
twoDimensionArray = [[3,3],[3,2],[1,1],[4,3]]

twoDimensionArray.sort(key = lambda x : (x[0], x[1]))

print(twoDimensionArray)
~~~

## C++
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

# **알고리즘**
### **Union Find**  
- 여러 서로소 집합의 정보를 저장하고 있는 자료구조를 의미함.  
- 트리 구조로써 집합을 표현하고 경로 압축과 레벨 최적화 도입해서 유용함.  
#### C++
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

#### C++
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

#### C++
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
  

