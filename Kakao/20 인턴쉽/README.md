# 카카오 20 인턴 1번 - 키패드 누르기 &nbsp; :large_blue_circle:  
![#000000](https://placehold.it/15/000000/000000?text=+) 시뮬레이션  
![#000000](https://placehold.it/15/000000/000000?text=+) 쉬웠던 문제.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 숫자에 따라 왼손가락 위치, 오른손가락 위치를 업데이트한다.  

# 카카오 20 인턴 2번 - 수식 최대화 &nbsp; :large_blue_circle:  
![#000000](https://placehold.it/15/000000/000000?text=+) string, 구현 문제    
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) string을 이용한 구현 문제라서 조금 까다로웠음.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) split으로 숫자와 문자들을 쪼개 하나의 벡터에 저장한다.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) next_permutation으로 연산자 조합을 만든 뒤 위에서 만든 벡터를 순회한다.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 숫자이거나 해당 연산자가 아니라면 새로운 벡터에 쌓는다.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 해당 연산자라면 새 벡터의 마지막 숫자와 연산자 다음 숫자를 계산.( 마치 stack 처럼 )  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 만들어질 수 있는 수가 long long일수 있기 때문에 string에서 int로 바꿔 틀렸음.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+)  string to long long의 함수는 atoll이다.  
  
# 카카오 20 인턴 3번 - 보석 쇼핑 &nbsp; :large_blue_circle:  
![#000000](https://placehold.it/15/000000/000000?text=+) two pointers 문제  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 매번 모든 물건을 가지고 있는지 검사하는 것에서 시간 초과가 남  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) check가 true일 때는 continue를 해서 시간을 줄였지만 그래도 시간 초과가 남.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 물건 목록을 담고있는 map을 순회하면서 확인할 필요가 없었음.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 물건 목록 map과 현재 물건들 목록 map의 크기가 같으면 조건 만족.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 코딩 테스트 당시 two pointer를 몰라서 아예 풀지 않았는데 공부하니 풀었음.  
  
# 카카오 20 인턴 4번 - 경주로 건설 &nbsp; :large_blue_circle:  
![#000000](https://placehold.it/15/000000/000000?text=+) bfs 문제    
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 코딩테스트 당시 dfs를 메모이제이션을 이용했지만 답이 계속 틀려 실패.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 평소 bfs문제는 이동 가중치가 모두 같기 때문에 목적지에 먼저 도착하는 경로가 최소 경로임.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) **하지만 가중치가 있을 때는 최소 경로가 최소 가중치가 아님!!**  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 그래서 이 문제를 풀 때는 방문한 좌표를 다시 방문할 수 있다.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 하지만 조건으로는 가중치가 해당 좌표에 저장된 가중치보다 같거나 작아야함.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) dfs 메모이제이션으로 다시 풀어보자.  
