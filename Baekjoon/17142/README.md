# 백준 17142 - 연구소3 &nbsp; :large_blue_circle: :large_blue_circle:
![#000000](https://placehold.it/15/000000/000000?text=+) 조합 찾기 후 bfs 문제  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 처음에 단순히 bfs가 끝나면 답을 업데이트 시켰음  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 이런 경우 빈칸이 다 없어져도 활성화되지 않은 바이러스도 활성화 시키느라 오답이 됨.      
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) bfs while에 들어가기 전에 빈칸의 개수를 세고 0개가 되면 while 탈출하도록 함.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 조합 찾을 때 dfs로 했는데 return 조건에서 실수함.  
![#000000](https://placehold.it/15/000000/000000?text=+) 조합 찾는 방법으로 dfs 말고 next_permutation을 쓰면 간단해짐. 

