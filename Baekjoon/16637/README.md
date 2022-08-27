# 백준 16637 - 괄호 추가하기 &nbsp; :red_circle: :large_blue_circle: :large_blue_circle:
![#000000](https://placehold.it/15/000000/000000?text=+) dfs 문제       
![#000000](https://placehold.it/15/000000/000000?text=+) 문제에서 모든 연산자 우선순위는 같다고 했기 때문에 앞에서부터 차례대로 연산함.  
![#000000](https://placehold.it/15/000000/000000?text=+) 핵심은 괄호를 어디에 넣을지인데 괄호안에는 연산자가 한개만 존재하기 때문에 쉬움.    
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) dfs를 이용하여 현재 지점에서 다음 숫자를 바로 연산할지 아니면  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 다음, 다다음 숫자를 괄호로 묶어서 연산할지 재귀로 들어가면 됨.  
