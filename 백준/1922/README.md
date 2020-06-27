# 백준 1922 - 네트워크 연결 &nbsp; :large_blue_circle:  
![#000000](https://placehold.it/15/000000/000000?text=+) BFS, 조합  
![#000000](https://placehold.it/15/000000/000000?text=+) BFS로 섬을 구분한 뒤, 만들 수 있는 다리들을 저장.  
![#000000](https://placehold.it/15/000000/000000?text=+) 다리들 중에서 섬 갯수 - 1개 만큼을 next permutation으로 조합을 구함.  
![#000000](https://placehold.it/15/000000/000000?text=+) 선택된 다리들을 이용해 섬을 모두 방문할 수 있으면 답을 업데이트.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 처음에 다리 선택까지 했지만 섬을 다 방문할 수 있는지에 대한 풀이로 BFS를 생각 못함.   
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 1번 섬을 시작으로 BFS를 이용해 모든 섬을 방문할 수 있는지 검사한다.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) MST로 한번 더 풀어야함.
<span style="color:red">붉은 색</span>
-> 최소 스패닝 트리
-> 크루스칼 알고리즘을 이용하여 해결
-> Union Find 구현에서 "return uf[a] = find(uf[a])"의 이유를 몰랐음.
-> merge 함수에서 uf[a]는 바로 위 부모를 저장하기 때문에 find_uf 함수에서 불필요한 반복 탐색을 하므로 메모이제이션처럼 구현함.
