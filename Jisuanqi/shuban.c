
/*
������
ȱ�㣬���鳤�����ޣ����������Ϊ99�Σ���������������������ô���齫�� ����
���Ż���û������ʵ�ֶ�̬��������
δ֪��������ж��Ƿ��˳�ʱ�����1��������ֻᱨ��
*/

#include <stdio.h>

int main() {

    //�ж��Ƿ�������
    char decide;
    // ���ڴ洢���ֵ�����
    double arr[100];
    // ���ڴ洢�����������
    char arrs[100];
    printf("������\n����س�����\n");
    while (1) {
        //��ʼ���洢�����ս��
        double Temp = 0;
        //��ʼ��ͳ�����ָ���ֵ
        int js = 1;
        //��ʼ���������ֵ����鳤��
        int num = 0;
        //��ʼ�����ط��ŵ����鳤��
        int NUM = 0;
        //��ʼ���������Ч���鳤��
        int length = 0;
        //�ж��Ƿ����ѭ��
        char dec;


        //ʶ������س��������
        while (1) {
            decide = getchar();
            if (decide != '\n') {
                break;
            }
            //���յ�n�����֣����ж��Ƿ��ȡ�ɹ�
            printf("������ĵ�%d������\n: ", js);
            if (scanf("%lf", &arr[num]) != 1) {
                printf("������Ϸ�������\n");
                while (getchar() != '\n'); // ������뻺��
                continue;
            }
            //��¼�ڼ�������
            ++js;
            //��������
            ++num;
            //α��̬���鳤��
            length = num;
            //���������������ִ������Ӷ�����
            //arrs��������λ�Ϳգ�Ϊ����arr�����Ӧ
            ++NUM;
            printf("\n����������� (+, -, *, /, =):\n");
            scanf(" %c", &arrs[NUM]);
            while (arrs[NUM] != '+' && arrs[NUM] != '-' && arrs[NUM] != '*' && arrs[NUM] != '/' && arrs[NUM] != '=') {
                printf("\n"); //ʹ����ѭ��
                printf("\n��������ȷ�ķ���:\n");
                while (getchar() != '\n');
                arrs[NUM] = getchar(); //���»�ȡ����
            }

            //ʶ��=ʱ�˳�
            if (arrs[NUM] == '=') {
                break;
            }

        }
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
        printf("\n���Ϊ%lf\n", Temp);
        //�ж��Ƿ����ѭ��
        printf("�Ƿ�Ҫ�������� 1������������ĸ�˳�\n");
        scanf("%d", &dec);
        if (dec != 1) {
            return 1;
        }
    }

}

