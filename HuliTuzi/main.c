


#include <stdio.h>
#include "time.h"
#include "stdlib.h"

int main() {
    //����׷����
    //����һ������Ϊ��ͼ
    char arr[29] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                    '0', '0', '0', '0', '0', '0', '0', '0', '0'};
    //���������߻���������
    char dec;
    //�������
    char H = 'h';
    //����ѡ�����Ϸģʽ
    int choose = 0;
    //�洢����������
    char go;
    //��������
    char T = 't';
    //��������������
    char run;
    //��ʼ�����ӵ�λ��
    arr[4] = T;
    //�������ӵ��±�
    int table_t = 4;
    int tt = 0;
    //��ʼ�������λ��
    arr[0] = H;
    //���������±�
    int table_h = 0;
    int hh = 0;
    int rj = 0;
    char move = '\0';
    printf("����׷����С��Ϸ\n");
    printf("���������������Ϸ\n");

    //ʶ������س��������
    while ((dec = getchar()) != '\n') {
        while (getchar() != '\n');  //�������
        menu:

        printf("����׷����\n");
        printf("1.������Ϸ\n");
        printf("2.˫����Ϸ\n");
        printf("3.��Ϸ����\n");
        printf("4.�˳���Ϸ\n");
        printf("������������ģʽ\n");
        scanf("%d", &choose);
        while (getchar() != '\n');  //�������
        if (choose != 1 && choose != 2 && choose != 3 && choose != 4) {
            printf("��������ȷ��ģʽ���\n");
            goto menu;
        }

        switch (choose) {
            case 1:
                printf("������Ϸ�Ҹ棺\n");

                printf(" ���Ʋ�����Ϸ���ܾ�������Ϸ��\n");

                printf(" ע�����ұ�����������ƭ�ϵ���\n");

                printf("   �ʶ���Ϸ���ԣ�������Ϸ����\n");

                printf(" ������ʱ�䣬���ܽ������\n");
                goto play;
                break;
            case 2:
                printf("������Ϸ�Ҹ棺\n");

                printf(" ���Ʋ�����Ϸ���ܾ�������Ϸ��\n");

                printf(" ע�����ұ�����������ƭ�ϵ���\n");

                printf("   �ʶ���Ϸ���ԣ�������Ϸ����\n");

                printf(" ������ʱ�䣬���ܽ������\n");
                goto play;
                break;
            case 3:
                printf("��Ϸ����\n����ÿ�ο�������������ƶ�1������ÿ�ο����������������2�������3����������ߣ�Ȼ�����ǽ����ƶ�");
                printf("�������ߣ�Ȼ�����ǽ����ƶ�������������������ڵĸ�����ᱻ�Ե�����������߽��������ڵĸ��ӿ��԰����ӳԵ�\n");
                printf("tips: �㿴������\n���㿴û�������������\n");
                goto menu;
                break;
            case 4:
                printf("�°࣡\n");
                return 1;
        }
        play:
        while (1) {

            printf("\n��ǰ��ͼ�������\n");

            for (int i = 0; i < 29; i++) {
                printf(" %c", arr[i]);
            }
            if (table_t == table_h) {
                printf("\n����ʤ����\n");
                return 1;
            }
            again_h:

            printf("\n�����ж��������������������ƶ�һ������L����������R������\n");

            scanf(" %c", &go);
            //�ж��Ƿ��ǵ���ģʽ
            if (choose == 1) {
                rj++;
            }
            while (getchar() != '\n');  //�������
            //�ж����������ǽ�ߵ��������
            if (table_h == 0) {
                if (go == 'l' || go == 'L') {
                    printf("ײǽ���߲���\n");
                    goto again_h;

                }
            }
            if (table_h == 28) {
                if (go == 'r' || go == 'R') {
                    printf("ײǽ���߲���\n");
                    goto again_h;
                }
            }


            //Ѱ�Һ������ڵ�λ��
            for (int j = 0; j < 28; j++) {
                if (arr[j] == H) {
                    table_h = j;
                    break;
                }

            }

            switch (go) {

                case 'l':

                case 'L':

                    //��ԭ�����Ϳ�
                    hh = table_h;
                    arr[hh] = '0';
                    //ʵ���ƶ�
                    table_h--;
                    arr[table_h] = H;
                    //�ж��Ƿ�ʤ��
                    if (table_t == table_h) {
                        printf("\n����ʤ����\n");
                        return 1;
                    }
                    if (rj != 0) {
                        goto again_T;
                    }
                    break;
                case 'r':
                case 'R':

                    //��ԭ�����Ϳ�
                    hh = table_h;
                    arr[hh] = '0';
                    //ʵ���ƶ�
                    table_h++;
                    arr[table_h] = H;
                    //�ж��Ƿ�ʤ��
                    if (table_t == table_h) {
                        printf("\n����ʤ����\n");
                        return 1;
                    }
                    if (rj != 0) {
                        goto again_T;
                    }
                    break;
                default:
                    printf("û�±�����\n");
                    if (choose == 1) {
                        goto again_h;
                    }
                    goto again_h;
                    break;

            }


            again_t:

            printf("�����ж��������������������ƶ���������L����������R������\n");
            scanf(" %c", &run);
            while (getchar() != '\n');  //�������

            //�ж����������ǽ�ߵ��������
            if (table_t == 0) {
                if (run == 'l' || run == 'L') {
                    printf("ײǽ���߲���\n");
                    goto again_t;

                }
            }
            if (table_t == 28) {
                if (run == 'r' || run == 'R') {
                    printf("ײǽ���߲���\n");
                    goto again_t;
                }
            }

            //Ѱ���������ڵ�λ��
            for (int j = 0; j < 29; j++) {
                if (arr[j] == T) {
                    table_t = j;
                }

            }
            switch (run) {
                case 'l':

                case 'L':
                    //��ԭ�����Ϳ�
                    tt = table_t;
                    arr[tt] = '0';
                    //���⴦���������ȶ������Ӻ󶯣������ƶ�������֮ǰ��λ�û�Ѻ����Ϳ�
                    if (tt == hh) {
                        arr[table_h] = H;
                    }
                    //ʵ���ƶ�
                    table_t--;
                    table_t--;
                    arr[table_t] = T;


                    break;
                case 'r':
                case 'R':
                    //��ԭ�����Ϳ�
                    tt = table_t;
                    arr[tt] = '0';
                    //���⴦���������ȶ������Ӻ󶯣������ƶ�������֮ǰ��λ�û�Ѻ����Ϳ�
                    if (tt == hh) {
                        arr[table_h] = H;
                    }
                    //ʵ���ƶ�
                    table_t++;
                    table_t++;
                    arr[table_t] = T;

                    break;
                default:
                    printf("û�±�����\n");
                    goto again_t;
                    break;
            }
            again_T:
            if (choose == 1) {


                if (rj == 0) {
                    printf("�쳣");
                    return 1;
                }
                //Ѱ���������ڵ�λ��
                for (int j = 0; j < 30; j++) {
                    if (arr[j] == T) {
                        table_t = j;
                    }
                }
                //������΢�����ܻ�
                //����ÿ���ж������������Ƿ��к��꣬��������򷴷�����
                //��ֹ����������ͼ�� table_t - 2 >= 0
                if (arr[table_t - 1] == '0' && arr[table_t - 2] == '0' && arr[table_t - 3] != 'h' && table_t - 2 >= 0) {

                    //��ԭ�����Ϳ�
                    tt = table_t;
                    arr[tt] = '0';
                    //���⴦���������ȶ������Ӻ󶯣������ƶ�������֮ǰ��λ�û�Ѻ����Ϳ�
                    if (tt == hh) {
                        arr[table_h] = H;
                    }
                    //ʵ���ƶ�
                    table_t--;
                    table_t--;
                    arr[table_t] = T;

                    goto play;
                } else if (arr[table_t + 1] == '0' && arr[table_t + 2] == '0' && arr[table_t + 3] != 'h' &&
                           table_t + 2 <= 28) {
                    //��ԭ�����Ϳ�
                    tt = table_t;
                    arr[tt] = '0';
                    //���⴦���������ȶ������Ӻ󶯣������ƶ�������֮ǰ��λ�û�Ѻ����Ϳ�
                    if (tt == hh) {
                        arr[table_h] = H;
                    }
                    //ʵ���ƶ�
                    table_t++;
                    table_t++;
                    arr[table_t] = T;
                    goto play;
                } else {

                    if (table_t - 2 >= 0) {
                        //��ԭ�����Ϳ�
                        tt = table_t;
                        arr[tt] = '0';
                        //���⴦���������ȶ������Ӻ󶯣������ƶ�������֮ǰ��λ�û�Ѻ����Ϳ�
                        if (tt == hh) {
                            arr[table_h] = H;
                        }
                        //ʵ���ƶ�
                        table_t--;
                        table_t--;
                        arr[table_t] = T;

                        goto play;
                    } else {
                        //��ԭ�����Ϳ�
                        tt = table_t;
                        arr[tt] = '0';
                        //���⴦���������ȶ������Ӻ󶯣������ƶ�������֮ǰ��λ�û�Ѻ����Ϳ�
                        if (tt == hh) {
                            arr[table_h] = H;
                        }
                        //ʵ���ƶ�
                        table_t++;
                        table_t++;
                        arr[table_t] = T;
                        goto play;
                    }
                }
            }
        }
    }
}


