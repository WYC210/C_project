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
int num = 0;//��ʾͨѶ¼���м�����
void add() {
    num++;
    people *tail = (people *) malloc(sizeof(people));
    printf("�������������\n");
    fgets(tail->name, sizeof(tail->name), stdin);
    again:
    printf("������ϵ���Ա�\n");
    printf("1. ��\n");
    printf("2. Ů\n");
    printf("3. ��Ը��͸¶\n");
    scanf("%d", &tail->sex);
    if (tail->sex != 1 && tail->sex != 2 && tail->sex != 3) {
        goto again;
    }
    printf("������ϵ�˵绰��\n");
    scanf("%s", tail->phone);

    tail->next = head;
    head = tail;
}
void write() {
    people *tail;
    tail= (people *) malloc(sizeof(people));
    FILE *file = fopen(".\\files\\ͨѶ¼.txt", "w+");
    if (file == NULL) {
        perror("��ʧ��");
        return;
    }
    while (tail->next ==NULL) {
        // д���ļ�
        int fpret = fputs(tail->name, file);
        if (fpret == EOF) {
            perror("д��ʧ��");
            tail->next = head;
            head = tail;
        }

        // ��ӻ��з�
        fputc('\n', file);
    }
    fclose(file);
}

void print() {
    if (num == 0) {
        printf("���ͨѶ¼�տ���Ҳ\n");
        return;
    }
    people *current = head;
    while (current != NULL) {
        printf("������%s �Ա�", current->name);
        if (current->sex == 1) {
            printf("��");
        } else if (current->sex == 2) {
            printf("Ů");
        } else {
            printf("��Ը��͸¶");
        }
        printf("�绰��%s\n", current->phone);
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