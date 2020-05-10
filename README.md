FOODGRAM
========
맛집 검색 프로그램
------------------

### What is it?
여러 맛집들의 정보를 등록해두고, 나중에 찾아볼 수 있는 프로그램   
지역별, 가격별, 음식 종류별로 검색할 수 있다.   
외출을 하면 항상 생각하는 것이 어디서 무엇을 먹을지인데,   
그럴 때 사용하면 좋은 프로그램이다.

내가 다닌 맛집들 기록용으로 시작했다:)

### How use it?
메뉴가 있다.   
새로운 맛집을 등록할 수 있고, 그 외 검색 기능들도 있다.

#### Menu
0. 종료
1. create : 새로운 맛집 등록 (이름, 지역, 타입, 가격, 평점)   
  - name
  - city 
  - type
2. read : 입력된 맛집 정보 읽어오기
3. update : 맛집 정보 수정하기
4. delete : 맛집 정보 삭제하기
5. list : 저장된 전체 맛집 리스트
6. list_best : 평점이 큰 순서대로 리스트(평점 0~10점)
7. search(city) : 지역이름으로 검색
8. search(type) : 음식 종류로 검색
9. search(price) : 음식 가격대별 검색(1인 기준으로 설정되어있음)
10. load : 내장된 파일 업로드함
11. save : 프로그램 내역 파일에 저장
