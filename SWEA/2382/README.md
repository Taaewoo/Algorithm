# SWEA 2382 - 미생물 격리 &nbsp; :red_circle:  
![#000000](https://placehold.it/15/000000/000000?text=+) simulation 문제  
![#000000](https://placehold.it/15/000000/000000?text=+) 이전에 삼성 기출 낚시왕 문제를 풀면서 동일한 자리에 왔을 때 삭제하는 방법 적용.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 하지만 i 번째 미생물과 해당 자리에 있는 미생물을 비교하는 즉시 값을 더해버림.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+)  이러면 같은 자리에 계속 값이 누적되기 때문에 뒤에 미생물들을 다 삼켜버림.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+)  답은 겹치는 미생물 중에서 가장 큰 미생물의 방향을 따라야함.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 그래서 미생물을 삼킬 때마다 값을 바로 더하지말고 sum[nx][ny]에 누적시키고  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 최종적으로 남은 미생물 크기에 더해줌.  

