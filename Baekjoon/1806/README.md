# 백준 1664 - 소수의 연속합 &nbsp; :large_blue_circle:  
![#000000](https://placehold.it/15/000000/000000?text=+) two pointers 문제  
![#000000](https://placehold.it/15/000000/000000?text=+) S, E를 가리키는 변수를 만들어 각각 움직이며 확인.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 길이의 최소 값을 구해야 하므로 조건을 만족할 때마다 답 갱신.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) E가 끝 지점에 왔을 때 else if( E == N ) 에 조건에 걸린다는 것은 이미 S 포인터를 움직여도 답을 찾을 수 없기 때문에 while문 종료시켜야함.  
