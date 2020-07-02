# Contents
* ## **[알고리즘](#알고리즘)**  
  * [Union Find](#union-find)  
  * [Two Pointers](#two-pointers)  
  * [위상 정렬](#위상-정렬)  
  * [최소 스패닝 트리(MST)](#최소-스패닝-트리(MST))  
  
* ## **[문법 및 함수 정리](#문법-및-함수-정리)** 
  * [for문 매크로](#for문-매크로)  
  * [lower_bound, upper_bound](#lower_bound,-upper_bound)

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

### 위상 정렬  
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
### for문 매크로  

### lower_bound, upper_bound  
