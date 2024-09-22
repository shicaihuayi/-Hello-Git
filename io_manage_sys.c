#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生信息的结构体
typedef struct Student {
    char name[50];
    int age;
    char gender[10];
    int id;
    char hobby[50];
    float score;
    struct Student* next; // 链表中的下一个节点
} Student;

// 创建新学生的函数
Student* create_student(char* name, int age, char* gender, int id, char* hobby, float score) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    strcpy(new_student->name, name);
    new_student->age = age;
    strcpy(new_student->gender, gender);
    new_student->id = id;
    strcpy(new_student->hobby, hobby);
    new_student->score = score;
    new_student->next = NULL;
    return new_student;
}
// 添加学生到链表
void add_student(Student** head, Student* new_student) {
    if (*head == NULL) {
        *head = new_student;
    } else {
        Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_student;
    }
}

// 删除学生
void delete_student(Student** head, int id) {
    Student* temp = *head;
    Student* prev = NULL;
    
    // 如果头结点就是要删除的学生
    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        printf("学生信息已删除。\n");
        return;
    }
    
    // 查找要删除的学生
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    
    // 找不到学生
    if (temp == NULL) {
        printf("未找到学生。\n");
        return;
    }

    // 从链表中删除学生
    prev->next = temp->next;
    free(temp);
    printf("学生信息已删除。\n");
}

// 查看学生信息
void view_students(Student* head) {
    Student* temp = head;
    while (temp != NULL) {
        printf("姓名: %s, 年龄: %d, 性别: %s, 学号: %d, 爱好: %s, 成绩: %.2f\n", 
               temp->name, temp->age, temp->gender, temp->id, temp->hobby, temp->score);
        temp = temp->next;
    }
}
// 按成绩排序学生信息
void sort_students_by_score(Student** head) {
    if (*head == NULL) return;
    
    Student* temp1 = *head;
    Student* temp2 = NULL;
    
    for (temp1 = *head; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->score < temp2->score) {
                // 交换学生信息
                char temp_name[50], temp_gender[10], temp_hobby[50];
                int temp_age, temp_id;
                float temp_score;
                
                strcpy(temp_name, temp1->name);
                temp_age = temp1->age;
                strcpy(temp_gender, temp1->gender);
                temp_id = temp1->id;
                strcpy(temp_hobby, temp1->hobby);
                temp_score = temp1->score;
                
                strcpy(temp1->name, temp2->name);
                temp1->age = temp2->age;
                strcpy(temp1->gender, temp2->gender);
                temp1->id = temp2->id;
                strcpy(temp1->hobby, temp2->hobby);
                temp1->score = temp2->score;
                
                strcpy(temp2->name, temp_name);
                temp2->age = temp_age;
                strcpy(temp2->gender, temp_gender);
                temp2->id = temp_id;
                strcpy(temp2->hobby, temp_hobby);
                temp2->score = temp_score;
            }
        }
    }
}
int main() {
    Student* head = NULL;

    // 示例操作：添加学生
    add_student(&head, create_student("张三", 20, "男", 1001, "篮球", 85.5));
    add_student(&head, create_student("李四", 21, "女", 1002, "羽毛球", 90.0));
    add_student(&head, create_student("王五", 22, "男", 1003, "足球", 88.0));

    // 查看所有学生信息
    printf("当前学生信息：\n");
    view_students(head);

    // 按成绩排序学生
    sort_students_by_score(&head);
    printf("\n按成绩排序后的学生信息：\n");
    view_students(head);

    // 删除学生
    delete_student(&head, 1002);
    printf("\n删除学生后：\n");
    view_students(head);

    return 0;
}
