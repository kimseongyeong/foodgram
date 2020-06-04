#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_foods 52      // 저장할 수 있는 맛집 레코드 최대 갯수

// 맛집 정보 레코드의 데이터 타입을 정의함
typedef struct st_food{
    char city[100];  // 맛집지역
    char type[100];  // 음식 종류
    char name[100];  // 맛집이름
    char menu[100]; //메인메뉴
    int price;  // 1인 기준 가격
    int grade;  // 점수 매기기
} T_Record;

// 라이브러리 함수 원형을 선언함
void r_init();
int r_is_available();       // 현재 추가할 수 있는 데이터 공간이 있는가?
int r_first_available();    // 추가할 수 있는 가장 빠른 포인터 배열의 인덱스 찾기
int r_count();              // 현재 저장된 맛집 레코드의 갯수 가져오기

void r_create(char* c, char* t, char* n, char* m, int pr, int g);   // 신규 맛집 레코드 추가
T_Record* r_search_by_name(char* n);                // 이름이 일치하는 맛집 레코드 포인터 찾기
void r_update(T_Record* p, char* n, char* c, char* t, int pr, int g);  // 특정 맛집 레코드의 정보 업데이트
void r_delete(T_Record* p);     // 특정 맛집 레코드의 맛집정보 제거
void r_get_all(T_Record* a[]);  // 맛집정보가 들어있는 모든 레코드 포인터의 배열을 만들기
void r_get_all2(T_Record* a[]);  // 모든 레코드 포인터의 배열을 만들기 (for debug)

void swap(T_Record* a[], int i, int j);
void r_get_all_sort(T_Record* a[]); //맛집 정보들 grade순서대로 정렬

char* r_to_string(T_Record* p); // 특정 맛집 레코드의 내용을 문자열로 가져오기
char* r_getcity(T_Record* p);   // 특정 맛집 레코드의 위치한 지역 가져오기
char* r_gettype(T_Record* p);   // 특정 맛집 레코드의 음식종류 가져오기
char* r_getname(T_Record* p);   // 특정 맛집 레코드의 가게이름 가져오기
char* r_getmenu(T_Record* p);
int r_getprice(T_Record* p);// 특정 맛집 레코드의 가격 가져오기
int r_getgrade(T_Record* p);// 특정 맛집 레코드의 점수 가져오기

int r_get_all_by_city(T_Record* a[], char* n);  // 맛집이 위치한 지역이 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
int r_get_all_by_type(T_Record* a[], char* n);  // 맛집의 음식 종류가 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
int r_get_all_by_price(T_Record* a[], int n, int m);
char* r_to_string_save(T_Record* p); // 특정 맛집 레코드의 내용을 파일저장용 문자열로 가져오기
