#include<stdio.h>
#include<stdlib.h>
#define student_data_file "student_data.txt"
enum NO_TYPE {
    list_student=1,
    add_a_student,
    modify_a_student,
    delete_a_student,
    quit
};
typedef struct Student{
    char name[20];
    int age;
    int class;
    double height;
}Student;
#define MAX_N 10000
Student stu_arr[MAX_N +5];
int stu_cnt;
int read_from_file(const char * filename,Student *arr)
{
    int n=0;
    FILE *fp = fopen(filename,"r");
    if(fp==NULL)
    {exit(1);
    return 0;}
    while(fscanf(fp,"%s",arr[n].name) != EOF)
    {
            fscanf(fp,"%d%d%lf",&arr[n].age,&arr[n].class,&arr[n].height);
            n+=1;
    }
    fclose(fp);
    return n;
}
// 将学生列表展示出来
void print_students()
{
    stu_cnt = read_from_file(student_data_file,stu_arr);
    // for(int i = 0;i < (sizeof(stu_arr) / sizeof(stu_arr[0]));i++)
   for(int i = 0;i < stu_cnt;i++)
    printf("|%4d|%10s|%4d|%6d|%8.2lf|\n",i+1,stu_arr[i].name,stu_arr[i].age,stu_arr[i].class,stu_arr[i].height);
    return;
}

void list_student_list()
{
    int eqution_num = printf("|%4s|%10s|%4s|%6s|%8s|\n","ID","name","age","class","height");
    while(--eqution_num)
    {
        printf("=");
    }
    printf("\n");
    print_students(stu_arr);
    return;
}
int usage(){
    int num;
    do{
    printf("%d:list student\n",list_student);
    printf("%d:add a student\n",add_a_student);
    printf("%d:modify a student\n",modify_a_student);
    printf("%d:delete a student\n",delete_a_student);
    printf("%d:quit\n",quit);
    printf("mysql>");
    scanf("%d",&num);
    }while(num<1||num>5);
    return num;
}
int main()
{   
    stu_cnt = read_from_file(student_data_file,stu_arr);
    while(1)
    {
        int num = usage();
        switch(num){
        case list_student: list_student_list();break;
        case add_a_student: printf("2:add a student\n");break;
        case modify_a_student: printf("3:modify a student\n");break;
        case delete_a_student: printf("4:delete a student\n");break;
        case quit: exit(0);
        default:
            printf("please put number in 1-5, other number is illegal!");
            break;
    }
    }
    return 0;
}