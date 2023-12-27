//
// Created by Administrator on 2023/12/13.
//
#include <stdio.h>
#include <stdlib.h>


typedef struct People {
    char name[15];
    char phone[30];
    int sex;
    struct People *next;
} people;
people *head = NULL;
int num = 0;//表示通讯录里有几个人
void add() {
    num++;
    people *tail = (people *) malloc(sizeof(people));
    printf("输入你的姓名：\n");
    fgets(tail->name, sizeof(tail->name), stdin);
    again:
    printf("输入联系人性别：\n");
    printf("1. 男\n");
    printf("2. 女\n");
    printf("3. 不愿意透露\n");
    scanf("%d", &tail->sex);
    if (tail->sex != 1 && tail->sex != 2 && tail->sex != 3) {
        goto again;
    }
    printf("输入联系人电话：\n");
    scanf("%s", tail->phone);

    tail->next = head;
    head = tail;
}
void write() {
    people *tail;
    tail= (people *) malloc(sizeof(people));
    FILE *file = fopen(".\\files\\通讯录.txt", "w+");
    if (file == NULL) {
        perror("打开失败");
        return;
    }
    while (tail->next ==NULL) {
        // 写入文件
        int fpret = fputs(tail->name, file);
        if (fpret == EOF) {
            perror("写入失败");
            tail->next = head;
            head = tail;
        }

        // 添加换行符
        fputc('\n', file);
    }
    fclose(file);
}

void print() {
    if (num == 0) {
        printf("你的通讯录空空如也\n");
        return;
    }
    people *current = head;
    while (current != NULL) {
        printf("姓名：%s 性别：", current->name);
        if (current->sex == 1) {
            printf("男");
        } else if (current->sex == 2) {
            printf("女");
        } else {
            printf("不愿意透露");
        }
        printf("电话：%s\n", current->phone);
        current = current->next;
    }
}

int main(){
    int dec;
 scanf("%d",&dec);
 switch (dec){
     case 1:
         add();

         print();
         write();
         break;
     default:
         break;
 }
}