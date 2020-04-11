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

void r_create(char* c, char* t, char* n, int pr, int g)
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

void r_update(T_Record* p, char* c, char* t, int pr, int g){
    strcpy(p->city, c);
    strcpy(p->type, t);
    p->price = pr;
    p->grade = g;
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
    int i, c=0;
    for(i=0; i<MAX_foods; i++){
        a[i]=foods[i];
    }
}

void swap_2(T_Record* a[], int i, int j)
{//city, type, name, price, grade
 // char temp[20];
 
  char *temp; //= (char*)malloc(20*sizeof(char));
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
    
    tmp = foods[i]->price;
    foods[i]->price = foods[j]->price;
    foods[j]->price = tmp;

    tmp = foods[i]->grade;
    foods[i]->grade = foods[j]->grade;
    foods[j]->grade = tmp;

}



void swap(/*T_Record *a[]*/)
{
  T_Record *temp;
  int c=0;
  for(int i=0; i<MAX_foods; i++)
  {
       printf("i = %d, j = %d\n", i, i+1);
       if(foods[i]->grade < foods[i+1]->grade)
       {
        temp=foods[i];
        foods[i] = foods[i+1];
        foods[i+1] = temp;

        printf("[DEBUG] temp 후 j의 grade.%d name %s \n",foods[i+1]->grade, foods[i+1]->name);
        printf("[DEBUG] temp 후 i의 grade.%d \n",foods[i]->grade);

        }

       // a[i] = foods[i];
       // printf("[debug] a의 이름 %s.\n", a[i]->name);


   }

  
}


/*
  T_Record *temp;
  int c=0;
  for(int i=0; i<_count; i++)
  {
   for(int j=i+1; j<_count+1; j++)
   {
	printf("i = %d, j = %d\n", i, j);
       if(foods[i]->grade < foods[j]->grade)
       {
        temp=foods[i];
        foods[i] = foods[j];
        foods[j] = temp;

	printf("[DEBUG] temp 후 j의 grade.%d name %s \n",foods[j]->grade, foods[j]->name);
        printf("[DEBUG] temp 후 i의 grade.%d \n",foods[i]->grade);

	}

       // a[i] = foods[i];
       // printf("[debug] a의 이름 %s.\n", a[i]->name);
        
      
   }

  }
}
*/
/*
void swap_3(T_Record*first[], T_Record*second[])
{
    T_Record *temp;

    temp =first;
    first=second;
    second = temp;

}
*/

void r_get_all_sort(T_Record* a[])
{//grade비교해서 더 평점 좋은 애를 위로위로
 int i, c=0;

  for(int i=0; i<MAX_foods; i++)
  {
      for(int j=i; j<MAX_foods; j++)
      {
	#ifdef DEBUG
	printf("[debug]i = %d, j=%d \n", i, j);
	#endif
        
	if(foods[i]!=NULL && (foods[i]->grade < foods[j]->grade))
        {
	 #ifdef DEBUG
	 printf("[debug] before swap \n");
	 #endif

           swap_2(foods, i, j);
#ifdef DEBUG
printf("[debug] swap이 됐어??\n");
#endif
       a[c] = foods[i];

       c++;
	}
	#ifdef DEBUG           
	printf("[debug]i의 이름 %s. \n", foods[i]->name);
	printf("[debug]j의 이름 %s. \n", foods[j]->name);
	#endif
         
      }
   
  }

}
char* r_to_string(T_Record* p){
    static char str[80];
    sprintf(str, "[%s] %s \"%s\" %d <%d>", p->city, p->type, p->name, p->price, p->grade);

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
int r_getprice(T_Record* p){
    return p->price;
}
int r_getgrade(T_Record* p){
    return p->grade;
}

int r_get_all_by_name(T_Record* a[], char* n){
    // 맛집름에 문자열이 포함된 모든 레코드 포인터의 배열 만들기    
    int i, c=0;
    for(i=0; i<_count; i++){
        if(foods[i]!=NULL && strstr(foods[i]->name, n)){
            a[c]=foods[i];
            c++;
        }
    }
    return c;
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

int r_get_all_by_price(T_Record* a[], int n, int m){
    // 회원생년이 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
    int i, c=0;
    for(i=0; i<_count; i++){
        if(foods[i]!=NULL && (foods[i]->price > n) && (foods[i]->price <= m))
        {
            a[c]=foods[i];
            c++;
        }
    }
    return c;
}

char* r_to_string_save(T_Record* p){
    static char str[80];
    sprintf(str, "%s %s %s %d %d", p->city, p->type, p->name, p->price, p->grade);
#ifdef DEBUG
	printf("[DEBUG] save %s\n", p->name);
#endif
    return str;
}
