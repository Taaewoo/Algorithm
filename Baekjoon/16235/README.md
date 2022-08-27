# 백준 16235 - 나무 재테크 &nbsp; :red_circle: :red_circle:
![#000000](https://placehold.it/15/000000/000000?text=+) 단순 simulation 문제      
![#000000](https://placehold.it/15/000000/000000?text=+) 각각의 나무를 vector의 2차원 배열로 표현했음.    
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 봄 계절에 양분을 얻지 못하는 나무는 죽은 나무로   표현하고 삭제하지 않음.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 이유는 vector의 erase를 쓰고 싶지 않았기 때문에.    
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 하지만 데이터를 남기고 있던 것이 오히려 시간을 더 오래 걸리게 했음.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) vector의 pop_back() 함수를 이용하면 해결가능함.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 원래는 pop_back을 안써서 vector의 뒤에서부터 탐색하며 erase를 했는데 대안이 생김.  
