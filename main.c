#include "foods.h"
// 애플리케이션용 함수 원형
void create_record();
void read_record();
void update_record();
void delete_record();
void list_record();
void list_sort();
void search_city();
void search_type();
void search_price();
void load_file();
void list_sort();
void save_file();
//void add_record_number();
void debug_records(); // for debug  

int main(){
    int menu;
    while(1){

        printf("\n*********************** Menu ***********************\n1.Create 2.Read 3.Update 4.Delete 5.List 6.List_best\n7.Search(city) 8.Search(type) 9.Search(price)\n10.Load 11.Save 0.Quit\n");
	printf("****************************************************\n");
	printf("Choose a menu > ");
        scanf("%d", &menu);
        printf("\n");
        switch(menu){
            case 1: 
                create_record();
                break;
            case 2: 
                read_record();
                break;
            case 3: 
                update_record();
                break;
            case 4: 
                delete_record();
                break;
            case 5: 
                list_record();
                break;
            case 6: 
                list_sort();
                break;       
            case 7: 
                search_city();
                break;            
            case 8: 
                search_type();
                break;            
            case 9: 
                search_price();
                break;
            case 10: 
                load_file();
                break;
            case 11: 
                save_file();
                break;                
  //          case 12:
//		add_record_number();
//		break;
	    case 13:
                debug_records();
                break;
            case 0:
		return 0; 
            default: 
                break;
        }
    }
    return 0;
}

/*
void add_record_number()
{
	int add;
	printf("How many record spaces would you like to add?> ");
	scanf("%d", &add);
	
	MAX_foods += add;
}
*/

void create_record(){
    if(!r_is_available()) {
        printf("There is no space!\n");
        return;
    }
    char city[100], type[100], name[100], menu[100];
    int price, grade;  
    printf("Enter a new restaurant's info. \n");
    printf("Name > ");
    scanf("%s", name);
    if(r_search_by_name(name)) {
        printf("Duplicated name!\n");
        return;
    }
    printf("City > ");
    scanf("%s", city);
    printf("Type > ");
    scanf("%s", type);
    printf("Menu > ");
    scanf("%s", menu);
    printf("Price > ");
    scanf("%d", &price);
    printf("Grade > ");
    scanf("%d", &grade);
    while( (0>grade) || (grade>10) )
    {
        printf("Error: enter a grade 0~10\n");
        printf("Grade > ");
        scanf("%d", &grade);
    }
    r_create(city, type, name, menu, price, grade);
}

void read_record(){
    char name[100];
    printf("Enter a name > ");
    scanf("%s", name);

    T_Record* p = r_search_by_name(name);
    if(p) {
        printf("Restaurant info.\n");
        printf("Name : %s\n", r_getname(p));
        printf("City : %s\n", r_getcity(p));
        printf("Type : %s\n", r_gettype(p));
	printf("Menu : %s\n", r_getmenu(p));
        printf("Price : %d\n", r_getprice(p));
        printf("Grade : %d\n", r_getgrade(p));
    }
    else {
        printf("No such restaurant!\n");
    }
}

void update_record(){
    char city[100], type[100], name[100];
    int price, grade;
    printf("Enter a name > ");
    scanf("%s", name);

    T_Record* p = r_search_by_name(name);
    if(p) 
    {
        printf("Existing info.\n");
        printf("Name : %s\n", r_getname(p));
        printf("City : %s\n", r_getcity(p));
        printf("Type : %s\n", r_gettype(p));
        printf("Price : %d\n", r_getprice(p));
        printf("Grade : %d\n", r_getgrade(p));
	printf("\n");

        printf("Enter a updated info.\n");
	printf("Name > ");
	scanf("%s", name);
        printf("City > ");
        scanf("%s", city);
        printf("Type > ");
        scanf("%s", type);
        printf("Price > ");
        scanf("%d", &price);
        printf("Grade > ");
        scanf("%d", &grade);
        while( (0>grade) || (grade>10) )
        {
          printf("Error: enter a grade 0~10\n");
          printf("Grade > ");
          scanf("%d", &grade);
        }

        r_update(p, name, city, type, price, grade);
    }
    else {
        printf("No such restaurant!\n");
    }
}

void delete_record(){
    char name[100];
    printf("Enter a name > ");
    scanf("%s", name);

    T_Record* p = r_search_by_name(name);
    if(p) {
        r_delete(p);
        printf("The record is deleted!\n");
    }
    else {
        printf("No such restaurant!\n");
    }
}

void list_record(){
    // 전체 리스트 출력
    printf("All records.\n");
    printf("0. <city> type \"\tname\t\" <grade>\n"); 
    int size = r_count();
    T_Record* records[MAX_foods];
    r_get_all(records);
    for(int i=0; i<size; i++){
        T_Record* p = records[i];
        printf("%2d. %s\n", i+1, r_to_string(p));
    }
}

void list_sort(){
    // 전체 리스트 평점순으로
    printf("All records of high grade order.\n");
    int size = r_count();
    T_Record* records[MAX_foods];

    r_get_all_sort(records);
    //아래는 전체 레코드 출력 
    for(int i=0; i<size; i++){
       
	 T_Record* p = records[i];
        printf("%d. %s\n", i+1, r_to_string(p));
    }
}

void search_city(){
    //지역으로 검색
    char name[100];
    printf("Enter a city > ");
    scanf("%s", name);

    T_Record* records[MAX_foods];
    int size = r_get_all_by_city(records, name);
    printf("%d records found.\n", size);

    for(int i=0; i<size; i++){
        T_Record* p = records[i];
        printf("%d. %s\n", i+1, r_to_string(p));
    }
}

void search_type(){
    //음식종류로 검색
    char name[100];
    printf("Enter a type > ");
    scanf("%s", name);

    T_Record* records[MAX_foods];
    int size = r_get_all_by_type(records, name);
    printf("%d records found.\n", size);

    for(int i=0; i<size; i++){
        T_Record* p = records[i];
        printf("%d. %s\n", i+1, r_to_string(p));
    }
}


void search_price(){

    int n, m;
    printf("Enter price range (X Y : greater than X, not more than Y) : ");
    scanf("%d %d", &n, &m);

    T_Record* records[MAX_foods];
    int size = r_get_all_by_price(records, n, m);
    printf("%d records found.\n", size);

    for(int i=0; i<size; i++){
        T_Record* p = records[i];
        printf("%d. %s\n", i+1, r_to_string(p));
        }
    
}

void load_file(){
    // 데이터파일 읽기
    printf("All data will be reloaded.\n");
    
    printf("1.Yes 0.No > ");
    int yesno;
    scanf("%d", &yesno);
    if (yesno == 0) return;
    
    FILE* f = fopen("foods.txt", "r");
    char city[100], type[100], name[100], menu[100];
    int price, grade;

    while(!feof(f))
    {
        if(!r_is_available()) {
            printf("[Load] There is no space!\n");
            break;
        }

        int n = fscanf(f,"%s %s %s %d %d", city, type, name, &price, &grade);
        if (n<4) break;
        if(r_search_by_name(name)) {
            printf("[Load] Duplicated name(%s)! loading.\n", name);
            continue;
        }
        r_create(city, type, name, menu, price, grade);
	  
    }
	
    printf("%d records are read from file!\n", r_count());    
    fclose(f);
}

void save_file(){
    // 데이터파일 저장
    FILE* f = fopen(	"foods.txt", "w");
    printf("All records.\n");
    int size = r_count();
    T_Record* records[MAX_foods];
    r_get_all(records);
    for(int i=0; i<size; i++){
        T_Record* p = records[i];
        fprintf(f,"%s\n", r_to_string_save(p));
   

    }
    fclose(f);
}
  
void debug_records(){
    // for debug  
    T_Record* records[MAX_foods]={0};
    r_get_all2(records);
    for(int i=0; i<MAX_foods; i++){
        printf("%d - %p\n",i, records[i]);
    }    
}



