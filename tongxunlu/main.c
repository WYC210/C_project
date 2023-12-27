#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct People {
    char name[15];
    char phone[30];
    int sex;
    struct People *next;
} people;
people *head = NULL;
int num = 0;//表示通讯录里有几个人

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

void find() {
    people *current = head;
    int find_sex, dec = 0;
    char find_name[10];
    while (dec != 1 && dec != 2 && dec != 3) {
        printf("输入你想通过什么来查找\n");
        printf("1.姓名\n");
        printf("2.性别\n");
        printf("3.电话号码\n");
        scanf("%d", &dec);
    }
    while (getchar() != '\n');

    switch (dec) {
        case 1:
            printf("输入你要查找的姓名\n");
            fgets(find_name, sizeof(find_name), stdin);

            for (int i = 0; i < num; ++i) {
                if (strcmp(find_name, current->name) == 0) {
                    printf("姓名：%s 性别：", current->name);
                    if (current->sex == 1) {
                        printf("男");
                    } else if (current->sex == 2) {
                        printf("女");
                    } else {
                        printf("不愿意透露");
                    }
                    printf("电话：%s\n", current->phone);
                    return;
                }
                current = current->next;
            }
            printf("查无此人\n");
            break;

        case 2:
            printf("输入你要查找的性别\n");
            printf("1.男\n");
            printf("2.女\n");
            printf("3.不愿意透露\n");
            scanf("%d", &find_sex);

            for (int i = 0; i <= num; ++i) {
                if (current->sex == find_sex) {
                    printf("姓名：%s 性别：", current->name);
                    if (current->sex == 1) {
                        printf("男");
                    } else if (current->sex == 2) {
                        printf("女");
                    } else {
                        printf("不愿意透露");
                    }
                    printf("电话：%s\n", current->phone);
                    return;
                }
                current = current->next;
            }
            printf("查无此人\n");
            break;
        case 3:
            printf("输入你要查找的姓名\n");
            fgets(find_name, sizeof(find_name), stdin);
            for (int i = 0; i <= num; ++i) {
                if (strcmp(current->name, find_name) == 0) {
                    printf("姓名：%s 性别：", current->name);
                    if (current->sex == 1) {
                        printf("男");
                    } else if (current->sex == 2) {
                        printf("女");
                    } else {
                        printf("不愿意透露");
                    }
                    printf("电话：%s\n", current->phone);
                    return;
                }
                current = current->next;
            }
            printf("查无此人\n");
            break;
        default:
            printf("无效的选择，请重新输入。\n");
            find();
            break;
    }
}

void delete() {
    people *Delete = NULL;
    people *current = head;
    int dec = 0;
    char deletes[20];

    while (dec != 1 && dec != 2 && dec != 3) {
        printf("输入你想要查找删除联系人的方式\n");
        printf("1.通过姓名查找删除联系人\n");
        printf("2.通过电话号码查找删除联系人\n");
        printf("3.清空通讯录\n");
        scanf("%d", &dec);
    }
    while (getchar() != '\n');

    switch (dec) {
        case 1:
            printf("输入你想要查找删除联系人的姓名\n");
            fgets(deletes, sizeof(deletes), stdin);

            for (int i = 0; i < num; ++i) {
                if (strcmp(deletes, current->name) == 0) {
                    if (Delete == NULL) {
                        Delete = head;
                        head = head->next;
                        free(Delete->name);
                        free(Delete->phone);
                        free(Delete);
                        --num;
                        printf("删除成功！");
                        return;
                    }

                    Delete->next = current->next;
                    free(current->name);
                    free(current->phone);
                    free(current);
                    --num;
                    printf("删除成功！");
                    return;
                }

                Delete = current;
                current = current->next;
            }
            printf("查无此人\n");
            break;

        case 2:
            printf("输入你想要查找删除联系人的电话号码\n");
            fgets(deletes, sizeof(deletes), stdin);

            for (int i = 0; i < num; ++i) {
                if (strcmp(deletes, current->phone) == 0) {
                    if (Delete == NULL) {
                        Delete = head;
                        head = head->next;
                        free(Delete->name);
                        free(Delete->phone);
                        free(Delete);
                        --num;
                        printf("删除成功！");
                        return;
                    }

                    Delete->next = current->next;
                    free(current->name);
                    free(current->phone);
                    free(current);
                    --num;
                    printf("删除成功！");
                    return;
                }

                Delete = current;
                current = current->next;
            }
            printf("查无此人\n");
            break;

        case 3:
            current = head;
            while (current->next != NULL) {
                people *next = current->next;
                free(current);
                current = next;
            }
            head = NULL;  // 清空通讯录后将头指针设为NULL
            num = 0;
            printf("通讯录已清空！");
            break;
    }
}

void chance() {
    people *chances = NULL;
    people *current = head;
    int dec = 0, choose, sex;
    char chanced[20];
    while (dec != 1 && dec != 2 && dec != 3) {
        printf("输入你想要查找修改联系人的方式\n");
        printf("1.通过姓名查找修改联系人\n");
        printf("2.通过电话号码查找修改联系人\n");
        scanf("%d", &dec);
    }
    while (getchar() != '\n');
    switch (dec) {
        case 1:
            printf("输入你想要修改联系人的姓名\n");
            fgets(chanced, sizeof(chanced), stdin);
            for (int i = 0; i < num; ++i) {
                if (strcmp(chanced, current->name) == 0) {
                    chances = current;
                    printf("选择你想修改的内容\n");
                    printf("1.姓名\n");
                    printf("2.性别\n");
                    printf("3.电话号码\n");
                    scanf("%d", &choose);
                    while (getchar() != '\n');
                    switch (choose) {
                        case 1:
                            printf("输入新的名字\n");
                            fgets(chances->name, sizeof(chances->name), stdin);
                            break;
                        case 2:
                            printf("输入新的性别\n");
                            printf("1.男\n");
                            printf("2.女\n");
                            printf("3.不愿意透露\n");
                            scanf("%d", &sex);
                            while (getchar() != '\n');
                            switch (sex) {
                                case 1:
                                    chances->sex = 1;
                                    break;
                                case 2:
                                    chances->sex = 2;
                                    break;
                                case 3:
                                    chances->sex = 3;
                                    break;
                            }
                            break;
                        case 3:
                            printf("输入新的电话号码\n");
                            fgets(chances->phone, sizeof(chances->phone), stdin);
                            break;
                    }
                    return;
                }
                current = current->next;
            }
            printf("查无此人\n");
            break;

        case 2:
            printf("输入你想要修改联系人的电话号码\n");
            fgets(chanced, sizeof(chanced), stdin);
            for (int i = 0; i < num; ++i) {
                if (strcmp(chanced, current->phone) == 0) {
                    chances = current;
                    printf("选择你想修改的内容\n");
                    printf("1.姓名\n");
                    printf("2.性别\n");
                    printf("3.电话号码\n");
                    scanf("%d", &choose);
                    while (getchar() != '\n');
                    switch (choose) {
                        case 1:
                            printf("输入新的名字\n");
                            fgets(chances->name, sizeof(chances->name), stdin);
                            break;
                        case 2:
                            printf("输入新的性别\n");
                            printf("1.男\n");
                            printf("2.女\n");
                            printf("3.不愿意透露\n");
                            scanf("%d", &sex);
                            while (getchar() != '\n');
                            switch (sex) {
                                case 1:
                                    chances->sex = 1;
                                    break;
                                case 2:
                                    chances->sex = 2;
                                    break;
                                case 3:
                                    chances->sex = 3;
                                    break;
                            }
                            break;
                        case 3:
                            printf("输入新的电话号码\n");
                            fgets(chances->phone, sizeof(chances->phone), stdin);
                            break;
                    }
                    return;
                }
                current = current->next;
            }
            printf("查无此人\n");
            break;
    }

}


void menu() {
    int dec;
    while (1) {
        printf("\n通讯录\n");
        printf("1.查看通讯录\n");
        printf("2.增添联系人\n");
        printf("3.删减联系人\n");
        printf("4.查找联系人\n");
        printf("5.修改联系人\n");
        printf("6.保存并退出通讯录\n");
        printf("0.直接退出通讯录\n");
        scanf("%d", &dec);
        while (getchar() != '\n');
        system("cls");
        switch (dec) {
            case 1:
                print();
                break;
            case 2:
                add();
                break;
            case 3:
                delete();
                break;
            case 4:
                find();
                break;
            case 5:
                chance();
                break;
            case 6:
                exit(0);
            case 0:
                exit(0);
            default:
                printf("无效的选择，请重新输入。\n");
                menu();
        }
    }
}


int main() {

        menu();
    return 0;
}