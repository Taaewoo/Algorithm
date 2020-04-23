# 백준 17143 - 낚시왕 &nbsp; :red_circle: :red_circle: :large_blue_circle:
![#000000](https://placehold.it/15/000000/000000?text=+) simulation 문제  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 상어 잡기, 상어 움직이기 모두 구현했는데, 상어가 겹칠 때 효율적으로 삭제시키는 방법을 알아야함.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 구현은 할 수 있겠지만 너무 비효율적인 방법인 것 같음.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 삭제할 때 해당 좌표에 상어들을 다 넣어놓고 나중에 비교하고 삭제하려고 했음.  
![#f03c15](https://placehold.it/15/f03c15/000000?text=+) 이렇게 하면 가장 큰 상어를 구할지라도 삭제하는 과정에서 vector의 erase를 사용하고 코드가 길어짐.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 구조체 S 타입으로 2차원 배열 선언하고 상어의 이동이 끝날 때마다 해당 위치 상어와 비교.  
![#1589F0](https://placehold.it/15/1589F0/000000?text=+) 크기가 크다면 덮어 씌우고 크기가 작다면 다음으로 넘어감.   

