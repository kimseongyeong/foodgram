#include "foods.h"
//#ifndef DEBUG
//#define DEBUG
//#endif


T_Record* foods[MAX_foods]; // 회원정보데이터 (전역)
int _count = 0;

void r_init(){
    int i;
    for(i=0; i<MAX_foods; i++){
        if(foods[i]!=NULL) {
            free(foods[i]);
        }
        foods[i] = NULL;

	}
    _count = 0;

} 

int r_is_available(){
    int i;
    for(i=0; i<MAX_foods; i++){
        if(foods[i]==NULL)
	{ 
#ifdef DEBUG
	printf("[DEBUG] available.\n");
#endif
	 return 1;
	}
    }
#ifdef DEBUG
	printf("[DEBUG] no available.\n");
#endif 
   return 0;
}

int r_first_available(){
    int i;
    for(i=0; i<MAX_foods; i++){
        if(foods[i]==NULL) return i;
    }
    return -1;
}

int r_count(){
#ifdef DEBUG
	printf("[DEBUG] count: %d\n", _count);
#endif

    return _count;
}

void r_create(char* c, char* t, char* n, char* m, int pr, int g)
{
    int index = r_first_available();
#ifdef DEBUG
	printf("[DEBUG] array index: %d\n", index);
#endif
    foods[index] = (T_Record*)malloc(sizeof(T_Record));
    T_Record* p = foods[index];

    strcpy(p->city, c);
    strcpy(p->type, t);
    strcpy(p->name, n);  
    strcpy(p->menu, m);
    p->price = pr;
    p->grade = g;
    _count++;

#ifdef DEBUG
	printf("[DEBUG] create(load) %s\n", n);
#endif

}

T_Record* r_search_by_name(char* n){
    int i;

#ifdef DEBUG
	printf("[DEBUG] Finding name ...\n");
#endif

    for(i=0; i<_count; i++){
        if(foods[i]!=NULL && strcmp(foods[i]->name, n)==0)
	{
#ifdef DEBUG
	printf("[DEBUG] Find matched name.\n");
#endif   
	 
	 return foods[i];
	}
    }
#ifdef DEBUG
	printf("[DEBUG] It is a new name.\n");
#endif

    return NULL;
}

void r_update(T_Record* p, char* n, char* c, char* t, char* m, int pr, int g){
    strcpy(p->name, n);
    strcpy(p->city, c);
    strcpy(p->type, t);
    strcpy(p->menu, m);
    p->price = pr;
    p->grade = g;
#ifdef DEBUG
	printf("[DEBUG] update complete.\n");
#endif
}

void r_delete(T_Record* p){
    int i, index;
    for(i=0; i<_count; i++)
        if(foods[i]==p) {
            index=i;
            break;
        }
    free(p);
    foods[index] = NULL;
    _count--;
#ifdef DEBUG
	printf("[DEBUG] delete: %s \n", p->name);
#endif
}


void r_get_all(T_Record* a[]){
    int i, c=0;
    for(i=0; i<MAX_foods; i++){
        if(foods[i]!=NULL){
            a[c]=foods[i];
            c++;
        }
    }
#ifdef DEBUG
	printf("[DEBUG] get all.\n");
#endif
}

void r_get_all2(T_Record* a[]){
    int i;
    for(i=0; i<MAX_foods; i++){
        a[i]=foods[i];
    }
}

void swap(T_Record* a[], int i, int j)
{
 
  char temp[100]; 
   int tmp;
    strcpy(temp, foods[i]->city);
    strcpy(foods[i]->city, foods[j]->city);
    strcpy(foods[j]->city, temp); 

    strcpy(temp, foods[i]->type);
    strcpy(foods[i]->type, foods[j]->type);
    strcpy(foods[j]->type, temp);

    strcpy(temp, foods[i]->name);
    strcpy(foods[i]->name, foods[j]->name);
    strcpy(foods[j]->name, temp);

    strcpy(temp, foods[i]->menu);
    strcpy(foods[i]->menu, foods[j]->menu);
    strcpy(foods[j]->menu, temp);

    tmp = foods[i]->price;
    foods[i]->price = foods[j]->price;
    foods[j]->price = tmp;
   
    tmp = foods[i]->grade;
    foods[i]->grade = foods[j]->grade;
    foods[j]->grade = tmp;

}

void r_get_all_sort(T_Record* a[])
{//grade비교해서 더 평점 좋은 애를 위로위로
 int c=0;

  for(int i=0; i<_count; i++)
  {
    #ifdef DEVUG
    printf("[debug_I]i = %d\n", i);
    #endif
      for(int j=i+1; j<_count; j++)
      {
	#ifdef DEBUG
	printf("[debug_J]i = %d, j=%d \n", i, j);
	#endif
        
	if(foods[i]!=NULL && (foods[i]->grade < foods[j]->grade))
        {
	 #ifdef DEBUG
	 printf("[debug] before swap \n");
	 #endif

           swap(foods, i, j);
	   #ifdef DEBUG
	   printf("[debug] after swap\n");
	   #endif
	}
	#ifdef DEBUG           
	printf("[debug]i의 이름 %s. \n", foods[i]->name);
	printf("[debug]j의 이름 %s. \n", foods[j]->name);
	#endif
         
      }
   
       a[c] = foods[i];
	c++;
  }

}
char* r_to_string(T_Record* p){
    static char str[80];
    sprintf(str, "[%s] %s \"%s\t\" <%d>", p->city, p->type, p->name, p->grade);

	 return str;
}

char* r_getcity(T_Record* p){
    return p->city;
}
char* r_gettype(T_Record* p){
    return p->type;
}
char* r_getname(T_Record* p){
    return p->name;
}
char* r_getmenu(T_Record* p){
    return p->menu;
}
int r_getprice(T_Record* p){
    return p->price;
}
int r_getgrade(T_Record* p){
    return p->grade;
}

int r_get_all_by_city(T_Record* a[], char* n){
    // 맛집 위치한 지역이 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
    int i, c=0;
    for(i=0; i<_count; i++){
        if(foods[i]!=NULL && (strcmp(foods[i]->city, n)==0)){
            a[c]=foods[i];
            c++;
        }
    }
    return c;
}

int r_get_all_by_type(T_Record* a[], char* n){
    // 맛집 타입이 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
    int i, c=0;
    for(i=0; i<_count; i++){
        if(foods[i]!=NULL && (strcmp(foods[i]->type, n)==0)){
            a[c]=foods[i];
            c++;
        }
    }
    return c;
}

int r_get_all_by_price(T_Record* a[], int n, int m) {
    //가격대가 문자열과 일치하는 모든 레코드 포인터의 배열 만들기
    int i, c = 0;
    for (i = 0; i < _count; i++) {
        if (foods[i] != NULL && (foods[i]->price > n) && (foods[i]->price <= m))
        {
            a[c] = foods[i];
            c++;
        }
    }
    return c;
}

char* r_to_string_save(T_Record* p){
    static char str[80];
    sprintf(str, "%s %s %s %s %d %d", p->city, p->type, p->name, p->menu, p->price, p->grade);
	#ifdef DEBUG
	printf("[DEBUG] save %s\n", p->name);
	#endif
    return str;
}

