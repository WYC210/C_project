

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
//����ڼ�������¼
int record = 0;
void now(char Time[][50], double money) {
    time_t t;
    struct tm *info;
    time(&t);
    info = localtime(&t);

    sprintf(Time[record], "����%d��%d��%d�� %02d:%02d:%02d ��ȡ��%lf",
            1900 + info->tm_year, 1 + info->tm_mon, info->tm_mday,
            info->tm_hour, info->tm_min, info->tm_sec, money);
    printf("%s\n", Time[record]);
    ++record;
}
//����ϵͳ
int main() {
    //�ж��Ƿ����
    char decide;
    //������ģʽ�еı��
    char num1;
    //��ʼ�����
    double money = 0;
    //��ʼ��ȡ����
    double outmoney = 0;
    //��ʾ���
    double balance = 0;
    //����һ������洢ÿ������Ľ��
    double arr[100];
    //ʵ������α����
    int temp = 0;
    //��������
    double rate = 0.0225;
    //��ʼ�����
    int year = 0;
    //��ʼ����Ϣ
    double interest = 0;
    //�洢δ�������
    double abc = 0;
    //����һ������жϳ�ʼ���
    int NUM = -1;
    char username[1000] = " "; // ���ڴ洢��¼ʱ���û���
    char password[1000] = " "; // ���ڴ洢��¼ʱ������
    char login_username[1000] = " "; // ���ڴ洢ע��ʱ���û���
    char login_password[1000] = " "; // ���ڴ洢ע��ʱ������
    //�������鳤��
    int length = 0;
//���ڴ洢��ǰʱ��
char Time[100][50];
    printf("516����\n");
    printf("���������������ϵͳ\n");
    //ʶ������س��������

    while ((decide = getchar()) != ' \n') {
        while (1) {

            printf("--------------------\n");
            printf("ע�᣺\nע������û���\n");

            scanf("%s", login_username);
            pass:
            printf("ע���������(���볤��Ϊ6λ)\n");
            scanf("%s", login_password);
            //��¼�������鳤��
            length = strlen(login_password);
            if (length != 6) {
                //��ʼ���洢��ʱ���������
                for (unsigned int i = 0; i < strlen(password); i++)
                    password[i] = '\0';
                //���鳤�Ȳ�Ϊ6������������
                goto pass;
            }

            // ʹ��scanf���������û�������ַ���

            again:    //����һ����ǣ������˳���¼
            while (1) {

                //��¼
                printf("--------------------\n");
                printf("���¼��\n");
                printf("��������˺�\n");
                scanf("%s", username);
                printf("�����������\n");
                scanf("%s", password);
                //�ж��Ƿ���ע��ʱ��������
                if (strcmp(username, login_username) == 0 && strcmp(password, login_password) == 0) {
                    printf("��¼�ɹ���\n");
                    //��ʼ��ע��ʱ����Ϣ
                    for (unsigned int i = 0; i < strlen(username); i++)
                        username[i] = '\0';
                    for (unsigned int i = 0; i < strlen(password); i++)
                        password[i] = '\0';
                    break;
                }
                printf("\n�˺Ż������������������������\n");
            }
            //�������ҵ��ı��
            int num = 0;

            while (1) {


                {
                    //���еĲ˵�
                    printf("--------------------\n");
                    printf("1.�鿴���˴�ȡ���¼\n");
                    printf("2.���\n");
                    printf("3.ȡ��\n");
                    printf("4.�鿴��ǰ����\n");
                    printf("5.�鿴����������Ϣ\n");
                    printf("6.�޸��˺�\n");
                    printf("7.�޸�����\n");
                    printf("8.�˳���¼\n");
                    printf("9.��������\n");
                    printf("--------------------\n");
                    printf("���뿪����ģʽ\n");
                    printf("�����������ҵ��ı��\n");
                    //��������ı��

                    while (scanf(" %d", &num) != 1 || num != 516 && num >= 10)  //�ж��Ƿ�Ϊ�Ϸ�����
                    {
                        printf("������Ϸ�������:\n");
                        //�������
                        while (getchar() != '\n');
                    }


                    //�жϰ����Ƿ���ȷ
                    if (num == 516) {
                        while (num == 516) {
                            //�洢��Ϣ�䶯
                            double add = 0;
                            //�����߲˵�
                            printf("--------------------\n");
                            printf("\n�ɹ����뿪����ģʽ\n");
                            printf("a.������������\n");
                            printf("b.������������\n");
                            printf("c.�鿴��ǰ����\n");
                            printf("�鿴�����û���Ϣ\n");
                            printf("d.�˳�������ģʽ\n");
                            printf("--------------------\n");
                            printf("�����������ҵ��ı��\n");
                            //���ձ�ţ������ǵ����洢��������ָ���

                            scanf(" %c", &num1);
                            //�����û�����ı�Ų�����ѭ��
                            switch (num1) {
                                //��������
                                case 'a':
                                    printf("------------------------\n");
                                    printf("��ǰ����Ϊ%lf\n", rate);
                                    printf("�����������Ӷ���\n");
                                    scanf("%lf", &add);
                                    rate = rate + add;
                                    printf("�޸ĳɹ�\n��ǰ��ϢΪ%lf\n", rate);

                                    break;
                                    //��������
                                case 'b':
                                    printf("----------------------\n");
                                    printf("��ǰ����Ϊ%lf\n", rate);
                                    printf("����������ٶ���\n");
                                    scanf("%lf", &add);
                                    rate = rate - add;
                                    printf("�޸ĳɹ�\n��ǰ��ϢΪ%lf\n", rate);

                                    break;
                                    //�鿴����
                                case 'c':
                                    printf("----------------------\n");
                                    printf("��ǰ��ϢΪ%lf\n", rate);

                                    break;
                                    //�˳�
                                case 'd':
                                    printf("----------------------\n");
                                    printf("�Ѱ�ȫ�˳�\n");

                                    num = 0;
                                    break;
                                default:
                                    printf("----------------------\n");
                                    printf("\n���е�û������ʲô��\n");

                                    break;
                            }
                        }
                    }
                    //�û��˵�
                    switch (num) {
                        //��ʾ���˲˵�
                        case 1:
                            if (NUM == -1) {
                                printf("----------------------\n");
                                printf("\n��ĸ�����Ϣ���£�\n");
                                printf("�û���%s��\n", login_username);
                                printf("����%s\n", login_password);
                                printf("���Ϊ��0\n");
                                break;
                            }
                            printf("----------------------\n");
                            printf("\n��ĸ�����Ϣ���£�\n");
                            printf("����%s\n", login_username);
                            printf("����%s\n", login_password);
                            printf("���Ϊ��%lf\n", money);
                            //�����ȡ���¼
                            printf("��Ĵ�ȡ���¼Ϊ\n");
                            for (int i = 0; i < record; i++) {
                                printf("%s\n", Time[i]);
                            }


                            break;
                            //������
                        case 2:
                            printf("----------------------\n");
                            printf("��������Ҫ���Ľ��\n");
                            scanf("%lf", &money);
                            //��ÿ�δ��Ľ���¼�������������
                            arr[temp] = money;
                            //����α����
                            balance += arr[temp];
                            temp++;
                            //�ж���ʾ������Ϣ������ʹ�䲻Ϊ0
                            NUM++;

                            now(Time,money);
                            printf("������Ϊ��%lf\n", balance);
                            break;
                        case 3:
                            //ȡ�����Ȿ���Ƿ�Ϊ0
                            while (1) {
                                //ȡ��ʱ��������֤
                                while (1) {
                                    printf("������֤������������\n");
                                    scanf("%s", password);
                                    if (strcmp(password, login_password) == 0) {
                                        printf("��֤�ɹ���\n");
                                        break;
                                    }
                                    printf("��֤ʧ�ܣ�����ɱ�����֤�������޷����к���ҵ��\n");
                                    //��ʼ���洢��ʱ���������
                                    for (unsigned int i = 0; i < strlen(password); i++)
                                        password[i] = '\0';

                                }
                                printf("----------------------\n");
                                printf("�������ȡ����\n");
                                scanf("%lf", &outmoney);
                                if (outmoney <= balance) {
                                    balance -= outmoney;
                                    arr[temp] = outmoney * -1;
                                    now(Time,arr[temp]);
                                  printf("�����ʣ%lf\n", balance);
                                    arr[temp] = outmoney * -1;
                                    //����α����
                                    temp++;
                                    break;
                                } else {
                                    printf("----------------------\n");
                                    printf("ȡ��ʧ�ܣ�����˻���û����ô��Ǯ,�������˷�����\n�������˵�\n");

                                    break;
                                }
                            }
                            break;
                            //�鿴��ǰ����
                        case 4:
                            printf("----------------------\n");
                            printf("��ǰ����Ϊ��%lf\n", rate);

                            break;
                            //�鿴����
                        case 5:
                            printf("----------------------\n");
                            printf("��������鿴�������Ժ����Ϣ\n");
                            scanf("%d", &year);
                            if (money == 0) {
                                printf("��û�б����޷�����δ������Ϣ\n");

                                break;
                            }

                            interest = (double) year * rate;
                            abc = (double) year * rate + money;
                            printf("\n%d���Ժ������ϢΪ%lf�����Ϊ%lf\n", year, interest, abc);

                            break;
                        case 6:
                            //�޸��û���
                            while (1) {
                                printf("������֤������������\n");
                                scanf("%s", password);

                                if (strcmp(password, login_password) == 0) {
                                    printf("��֤�ɹ���\n");
                                    break;
                                }
                                printf("��֤ʧ�ܣ�����ɱ�����֤�������޷����к���ҵ��\n");
                                //��ʼ���洢��ʱ���������
                                for (unsigned int i = 0; i < strlen(password); i++)
                                    password[i] = '\0';

                            }

                            printf("������������û���\n");
                            scanf("%s", username);
                            printf("�޸ĳɹ�������û���Ϊ��\n %s", username);
                            strcpy(login_username, username);
                            //��ʼ���洢��ʱ�˻�������
                            for (unsigned int i = 0; i < strlen(username); i++) {
                                password[i] = '\0';

                            }
                            break;
                        case 7:
                            //�޸�����
                            while (1) {
                                printf("������֤������������\n");
                                scanf("%s", password);
                                if (strcmp(password, login_password) == 0) {
                                    printf("��֤�ɹ���\n");
                                    break;
                                }
                                printf("��֤ʧ�ܣ�����ɱ�����֤�������޷����к���ҵ��\n");
                            }
                            printf("���������������\n");
                            scanf("%s", password);
                            printf("�޸ĳɹ����������Ϊ��\n %s", password);
                            strcpy(login_password, password);
                            //��ʼ���洢��ʱ���������
                            for (unsigned int i = 0; i < strlen(password); i++) {
                                password[i] = '\0';

                            }
                            break;
                            //�˳���¼
                        case 8:
                            //��ת����¼ҳ��
                            goto again;
                            break;
                        case 9 :
                            //��������
                            return 1;
                        default:
                            printf("----------------------\n");
                            printf("������1-9������\n");

                            break;
                    }
                }
            }
        }
    }
}