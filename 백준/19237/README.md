# 백준 19237 - 어른 상어 &nbsp; :red_circle:  
![#000000](https://placehold.it/15/000000/000000?text=+) 시뮬레이션  
![#000000](https://placehold.it/15/000000/000000?text=+) 입력부터 어떤 자료구조를 써야할지 고민하게 했던 문제.  
![#000000](https://placehold.it/15/000000/000000?text=+) 조건들이 상당히 까다롭고 디버깅이 참 힘들었음.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) for문이 돌던 중 vector erase를 수행해서 끝까지 돌지 못하고 끝남.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 삭제할 index를 저장해서 for문 끝나고 sort 시킨 후 뒤에서부터 erase.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 맵에 상어 번호를 적어야 하는 부분에서 vector index를 저장해서 틀렸음.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 디버깅이 힘들어 질문 검색에 있는 반례를 통해 에러를 찾음.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 꼼꼼하고 실수 없는 코딩만이 답이다....  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 이전과 같이 무언가를 잡아먹을 때 새로운 temp 맵을 만들어 상어들의 새로운 위치를 저장.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 잡아먹히는 객체는 맵에 저장하지 않는다.  
