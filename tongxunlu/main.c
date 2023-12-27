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
int num = 0;//��ʾͨѶ¼���м�����

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

void find() {
    people *current = head;
    int find_sex, dec = 0;
    char find_name[10];
    while (dec != 1 && dec != 2 && dec != 3) {
        printf("��������ͨ��ʲô������\n");
        printf("1.����\n");
        printf("2.�Ա�\n");
        printf("3.�绰����\n");
        scanf("%d", &dec);
    }
    while (getchar() != '\n');

    switch (dec) {
        case 1:
            printf("������Ҫ���ҵ�����\n");
            fgets(find_name, sizeof(find_name), stdin);

            for (int i = 0; i < num; ++i) {
                if (strcmp(find_name, current->name) == 0) {
                    printf("������%s �Ա�", current->name);
                    if (current->sex == 1) {
                        printf("��");
                    } else if (current->sex == 2) {
                        printf("Ů");
                    } else {
                        printf("��Ը��͸¶");
                    }
                    printf("�绰��%s\n", current->phone);
                    return;
                }
                current = current->next;
            }
            printf("���޴���\n");
            break;

        case 2:
            printf("������Ҫ���ҵ��Ա�\n");
            printf("1.��\n");
            printf("2.Ů\n");
            printf("3.��Ը��͸¶\n");
            scanf("%d", &find_sex);

            for (int i = 0; i <= num; ++i) {
                if (current->sex == find_sex) {
                    printf("������%s �Ա�", current->name);
                    if (current->sex == 1) {
                        printf("��");
                    } else if (current->sex == 2) {
                        printf("Ů");
                    } else {
                        printf("��Ը��͸¶");
                    }
                    printf("�绰��%s\n", current->phone);
                    return;
                }
                current = current->next;
            }
            printf("���޴���\n");
            break;
        case 3:
            printf("������Ҫ���ҵ�����\n");
            fgets(find_name, sizeof(find_name), stdin);
            for (int i = 0; i <= num; ++i) {
                if (strcmp(current->name, find_name) == 0) {
                    printf("������%s �Ա�", current->name);
                    if (current->sex == 1) {
                        printf("��");
                    } else if (current->sex == 2) {
                        printf("Ů");
                    } else {
                        printf("��Ը��͸¶");
                    }
                    printf("�绰��%s\n", current->phone);
                    return;
                }
                current = current->next;
            }
            printf("���޴���\n");
            break;
        default:
            printf("��Ч��ѡ�����������롣\n");
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
        printf("��������Ҫ����ɾ����ϵ�˵ķ�ʽ\n");
        printf("1.ͨ����������ɾ����ϵ��\n");
        printf("2.ͨ���绰�������ɾ����ϵ��\n");
        printf("3.���ͨѶ¼\n");
        scanf("%d", &dec);
    }
    while (getchar() != '\n');

    switch (dec) {
        case 1:
            printf("��������Ҫ����ɾ����ϵ�˵�����\n");
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
                        printf("ɾ���ɹ���");
                        return;
                    }

                    Delete->next = current->next;
                    free(current->name);
                    free(current->phone);
                    free(current);
                    --num;
                    printf("ɾ���ɹ���");
                    return;
                }

                Delete = current;
                current = current->next;
            }
            printf("���޴���\n");
            break;

        case 2:
            printf("��������Ҫ����ɾ����ϵ�˵ĵ绰����\n");
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
                        printf("ɾ���ɹ���");
                        return;
                    }

                    Delete->next = current->next;
                    free(current->name);
                    free(current->phone);
                    free(current);
                    --num;
                    printf("ɾ���ɹ���");
                    return;
                }

                Delete = current;
                current = current->next;
            }
            printf("���޴���\n");
            break;

        case 3:
            current = head;
            while (current->next != NULL) {
                people *next = current->next;
                free(current);
                current = next;
            }
            head = NULL;  // ���ͨѶ¼��ͷָ����ΪNULL
            num = 0;
            printf("ͨѶ¼����գ�");
            break;
    }
}

void chance() {
    people *chances = NULL;
    people *current = head;
    int dec = 0, choose, sex;
    char chanced[20];
    while (dec != 1 && dec != 2 && dec != 3) {
        printf("��������Ҫ�����޸���ϵ�˵ķ�ʽ\n");
        printf("1.ͨ�����������޸���ϵ��\n");
        printf("2.ͨ���绰��������޸���ϵ��\n");
        scanf("%d", &dec);
    }
    while (getchar() != '\n');
    switch (dec) {
        case 1:
            printf("��������Ҫ�޸���ϵ�˵�����\n");
            fgets(chanced, sizeof(chanced), stdin);
            for (int i = 0; i < num; ++i) {
                if (strcmp(chanced, current->name) == 0) {
                    chances = current;
                    printf("ѡ�������޸ĵ�����\n");
                    printf("1.����\n");
                    printf("2.�Ա�\n");
                    printf("3.�绰����\n");
                    scanf("%d", &choose);
                    while (getchar() != '\n');
                    switch (choose) {
                        case 1:
                            printf("�����µ�����\n");
                            fgets(chances->name, sizeof(chances->name), stdin);
                            break;
                        case 2:
                            printf("�����µ��Ա�\n");
                            printf("1.��\n");
                            printf("2.Ů\n");
                            printf("3.��Ը��͸¶\n");
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
                            printf("�����µĵ绰����\n");
                            fgets(chances->phone, sizeof(chances->phone), stdin);
                            break;
                    }
                    return;
                }
                current = current->next;
            }
            printf("���޴���\n");
            break;

        case 2:
            printf("��������Ҫ�޸���ϵ�˵ĵ绰����\n");
            fgets(chanced, sizeof(chanced), stdin);
            for (int i = 0; i < num; ++i) {
                if (strcmp(chanced, current->phone) == 0) {
                    chances = current;
                    printf("ѡ�������޸ĵ�����\n");
                    printf("1.����\n");
                    printf("2.�Ա�\n");
                    printf("3.�绰����\n");
                    scanf("%d", &choose);
                    while (getchar() != '\n');
                    switch (choose) {
                        case 1:
                            printf("�����µ�����\n");
                            fgets(chances->name, sizeof(chances->name), stdin);
                            break;
                        case 2:
                            printf("�����µ��Ա�\n");
                            printf("1.��\n");
                            printf("2.Ů\n");
                            printf("3.��Ը��͸¶\n");
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
                            printf("�����µĵ绰����\n");
                            fgets(chances->phone, sizeof(chances->phone), stdin);
                            break;
                    }
                    return;
                }
                current = current->next;
            }
            printf("���޴���\n");
            break;
    }

}


void menu() {
    int dec;
    while (1) {
        printf("\nͨѶ¼\n");
        printf("1.�鿴ͨѶ¼\n");
        printf("2.������ϵ��\n");
        printf("3.ɾ����ϵ��\n");
        printf("4.������ϵ��\n");
        printf("5.�޸���ϵ��\n");
        printf("6.���沢�˳�ͨѶ¼\n");
        printf("0.ֱ���˳�ͨѶ¼\n");
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
                printf("��Ч��ѡ�����������롣\n");
                menu();
        }
    }
}


int main() {

        menu();
    return 0;
}