

#include<stdio.h>

//��ʼ���洢�����ս��
double Temp = 0;

//��ʼ���������ֵ����鳤��
int num = 0;

//��ʼ���������Ч���鳤��
int length = 0;

//�ж��Ƿ�������
char decide;
// ���ڴ洢���ֵ�����
double arr[100];
// ���ڴ洢�����������
char arrs[100];

int calculator() {
    // �������㣬���˷��ͳ���ת��Ϊ�ӷ�
//�ж�Ѱ�ҵ��˷��ͳ���ʱ�����ȼ���
// Ȼ��Ѷ�Ӧ�ķ����û��ɼӷ������Ѽ������������һ���û���0һ���û��ɽ��
    for (int i = 0; i <= length; i++) {
        if (arrs[i] == '*') {
            arr[i] = arr[i - 1] * arr[i];
            arr[i - 1] = 0;
            arrs[i] = arrs[i - 1];
        }
        if (arrs[i] == '/') {
            if (arr[i] == 0) {
                printf("���󣬳�������Ϊ0��ѭ����ֹ\n");
                return 1;
            }
            arr[i] = arr[i - 1] / arr[i];
            arr[i - 1] = 0;
            arrs[i] = arrs[i - 1];
        }
    }
    // �������㣬������ת��Ϊ��ǰһλ���������
    for (int j = 1; j <= length; j++) {
        if (arrs[j] == '-') {
            arr[j] = arr[j] - arr[j - 1];
            arr[j - 1] = 0;
            //���жϵ���������λ����ʱ����������
            if (j != 1) {
                arrs[j] = arrs[j - 1];
            }

            arr[j] *= -1;

        }
        //���жϵ���������λ����ʱ����������
        if (arrs[j] == '+') {

            arr[j] = arr[j] + arr[j - 1];
            arr[j - 1] = 0;
            if (j != 1) {
                arrs[j] = arrs[j - 1];
            }

        }
    }
    //���������еĽ�����
    for (int p = 0; p < length; p++) {
        Temp += arr[p];
    }
    //������ս��
    printf("\n���Ϊ%0.3lf\n", Temp);
    return 0;
}


int main() {

    printf("������\n�������������\n");
    while (1) {
        //��ʼ���洢�����ս��
        Temp = 0;

        //��ʼ���������ֵ����鳤��
        num = 0;

        //��ʼ���������Ч���鳤��
        length = 0;
        //�ж��Ƿ����ѭ��
        char dec;

        // ʶ������������������
        while ((decide = getchar()) != '\n') {

            play:
            while (getchar() != '\n'); // ������뻺��
            /*
            ѭ��������ʼ��
            �������л���
            */

            //�ÿ�����
            for (int i = 0; i < num; i++) {
                arr[i] = 0;
                arrs[i] = '\0';
            }
            Temp = 0;
            num = 0;
            length = 0;

            //����ʽ��
            printf("�������ʽ��\n: ");

            while (1) {
                /*
                ע���˴����������棬���û���ԭ�����������ֵ
                */
                //������������
                scanf("%lf", &arr[num++]);

                //���շ���
                char p;
                p = getchar();

                arrs[num] = p;
                //�ж�ʶ��=�ż�¼���Ȳ��˳���ֵ
                if (arrs[num] == '=') {
                    length = num;

                    break;
                }

                //�ж����ʽ�����зǷ�����ֱ���˳���д
                if (arrs[num] != '+' && arrs[num] != '-' && arrs[num] != '*' && arrs[num] != '/' && arrs[num] != '=') {
                    printf("�������˷Ƿ����ţ�����������\n");
                    goto play;
                }
                // �ж����ʽ�Ӳ�����û�м� = �ţ���ô��������
                for (int j = 0; j < length + 1; j++) {
                    if (arrs[j] == '=') {
                        goto calculator;
                    }
                    if (j == 99) {
                        if (arr[j] != '=') {
                            printf("�������˲�������ʽ�ӣ�����������\n");
                            goto play;
                        }
                    }

                }
            }
            calculator:
            //���ü���
            calculator();
            while (getchar() != '\n'); // ������뻺��

            //�ж��Ƿ����ѭ��
            printf("�Ƿ�Ҫ�������� Y ���������������˳�\n");
            scanf(" %c", &dec);
            switch (dec) {
                case 'Y':
                case 'y':
                    goto play;
                default:
                    return 1;
            }

        }

    }
}