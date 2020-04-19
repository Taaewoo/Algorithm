# 백준 16236 - 아기 상어 &nbsp; :Large_blue_circle:
![#000000](https://placehold.it/15/000000/000000?text=+) bfs의 반복문제  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 먹이를 찾았다고 bfs를 끝내면 안되고 해당 깊이까지는 다 돌아야함.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 해당 깊이에서 후보군에 넣을 때 조건이 필요함(0이 아니고 자신보다 작은 크기일 때)  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) bfs 순회 중 현재 깊이가 먹이를 먹은 깊이보다 많을 때 업데이트하고 return 시킴.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 이러면 먹이를 먹고 다음 깊이가 없다면 조건에 걸리지 않아 업데이트가 안됨.      
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 업데이트를 while문 밖에 두면 됨.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 그러면 조건에 걸려서 break되거나 더이상 순회할 좌표가 없을 때도 업데이트가 됨.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 단, 먹이를 먹을 때 값이 변하는 dd 값이 -1이라면 먹이를 못 먹은 경우이므로 return false.  
