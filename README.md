FOODGRAM
========
맛집 검색 프로그램
------------------
## restaurant search program

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
##### 1. create : add new record
    - name
    - city 
    - type
    - price
    - grade
##### 2. read : read a record
    * 이름을 입력하면 그 이름에 해당하는 맛집 정보를 불러온다
##### 3. update : modify a record
    + 수정하고자 하는 맛집의 이름을 입력하면, 해당하는 맛집의 정보를 전부 수정할 수 있다. 
##### 4. delete : delete a record
    * 삭제하고자 하는 맛집의 이름을 입력하면, 그 맛집 레코드는 삭제된다.
##### 5. list : list
    - 저장되어있는 맛집 전체 리스트를 불러온다.
##### 6. list_best : list in grade order
    - 평점이 큰 순서대로 전체 리스트를 불러온다. (평점 0~10점으로 구성)
##### 7. search(city) : search by city
    - 지역이름을 입력하면(포항, 서울, 대전 ..etc) 해당 지역에 포함되어있는 맛집 리스트가 나열된다.
##### 8. search(type) : search by type
    - 음식의 종류를 입력하면(한식, 양식, 일식, 중식, 분식) 해당 타입에 속하는 맛집 리스트가 나열된다.
##### 9. search(price) : search by price
    - 원하는 가격대를 입력하면 그 범위 안에 속하는 맛집 리스트가 나열된다. (1인 기준 평균 가격)
##### 10. load : file load
    - 내장되어 있는 foods.txt 파일을 업로드한다. (파일에 이미 몇 개의 맛집 리스트가 저장되어있음!)
##### 11. save : save in file
    - 프로그램을 실행하며 수정된 내용을 다시 파일에 저장한다.(추가하거나 삭제, 수정한 내용을 다시 파일에 저장)
##### 0. 종료
