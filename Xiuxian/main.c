/*
* �ȴ��Ż���
* ��·����Ȼ��Ѫ
* ��ֻ������Ʒ
* ����
 * ������
* */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define row 15
#define low 15
// ��ʼ����ʼҳ��ѡ��
int dec = 0;
//���屳����Ʒ��ŵ��ڼ�λ
int obj = 0;
//���幦�����﹦����ŵ��ڼ�λ
int SpellBook = 0;
//����Ӧ��������ֵ�ͼ
int MAP = 0;
//���������Ĺ���ȼ�BOSS����С��
int event = 0;
// ����һ������ȷ���������ֵ
int n = 0;
//�ж��Ƿ�ӵ�����
int task = 0;
//���������л�ɱ��
int kill = 0;
//��¼��ʼѡ���츳����
int decide = 0;
// ����
double healthy = 100; // ��ʼ����ֵ
int attack = 10; // ��ʼ������
// ����
int defense = 5; // ��ʼ������
// ����
int mana = 30; // ��ʼ����
// ����
double lingli = 0; // ��ʼ����
// ����
int backpack[15];  // ��ʼ����
// ����
int spell[10];
// ��ҽṹ��
typedef struct {
    int x; // ��Һ�����
    int y; // ���������
} Player;
//��������
char name_my[10];


//�������뻺�滺��
void clearPoint() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ����
int menu(int arr_dec[10], int *ddd, char sex[]) {
    while (1) {
        printf("\t��������\n");
        printf("\t1.��ʼ��Ϸ\n");
        printf("\t2.�˳���Ϸ\n");
        printf("�������ֽ����Ӧģʽ\n");
        scanf("%d", &dec);
        if (dec == 1) {
            play:
            clearPoint();
            printf("�����������\n");
            fgets(name_my, sizeof(name_my), stdin);

            printf("ѡ������Ա�\n");
            printf("1.��\n");  // Ѫ��
            printf("2.Ů\n");  // ����
            printf("3.��Ը��͸¶�Ա��������\n");  // ������
            int condition = 0; // �����ж������Ƿ�Ϸ�
            //�ж������Ƿ��������
            while (!condition) {
                scanf("%d", &decide);

                // ������
                clearPoint();

                if (decide == 1 || decide == 2 || decide == 3) {
                    condition = 1; // ����Ϸ�������ѭ��
                } else {
                    printf("������Ч\n ");
                }
            }
            // ��������¼ѡ����ʲô
            arr_dec[*ddd] = decide;
            ++(*ddd);
            if (decide == 1) {
                strcpy(sex, "��");
            } else if (decide == 2) {
                strcpy(sex, "Ů");
            } else if (decide == 3) {
                strcpy(sex, "��Ը͸¶");
            }
            printf("ѡ���������\n");
            printf("��ĸ�����...\n");
            printf("1.���ɵ�ƽ��\n");  // Ѫ��
            printf("2.�����е�һ������\n");  // ����
            printf("3.���Ǹ��¶�\n");  // ����
            condition = 0; // �����ж������Ƿ�Ϸ�
            //�ж������Ƿ��������
            while (!condition) {
                scanf("%d", &decide);

                // ������
                clearPoint();

                if (decide == 1 || decide == 2 || decide == 3) {
                    condition = 1; // ����Ϸ�������ѭ��
                } else {
                    printf("������Ч\n ");
                }
            }
            // ��������¼ѡ����ʲô
            arr_dec[*ddd] = decide;
            ++(*ddd);
            printf("ѡ���������\n");
            printf("������ʱ...\n");
            printf("1.������ƽ\n");  // Ѫ��
            printf("2.��ʵ���ֵ�����\n");  // ����
            printf("3.���������۸�\n");  // ����
            condition = 0; // �����ж������Ƿ�Ϸ�
            //�ж������Ƿ��������
            while (!condition) {
                scanf("%d", &decide);

                // ������
                clearPoint();

                if (decide == 1 || decide == 2 || decide == 3) {
                    condition = 1; // ����Ϸ�������ѭ��
                } else {
                    printf("������Ч\n ");
                }
            }
            // ��������¼ѡ����ʲô
            arr_dec[*ddd] = decide;

            // ����ѡ�����������Ӧ������
            //��������������ֻ��ѡ�������żӣ�����������дһ��ÿ��һ����һ��Ѫ

            for (int i = 0; i < 10; ++i) {
                if (arr_dec[i] == 1) {
                    healthy += 10;
                } else if (arr_dec[i] == 2) {
                    mana += 10;
                } else if (arr_dec[i] == 3) {
                    defense += 10;
                }
            }
            return 0;
        } else if (dec == 2) {
            // �˳���Ϸ
            return 1;
        } else {
            printf("�����˷Ƿ�����\n");
            clearPoint();
        }
    }
}

//����
void Spell() {
    //1001����1099����һ�ױ�����������
    //1101-1199���ڶ���������������...
    //2001-2099����һ�ױ�����������
    //2101-2199���ڶ���������������...
    //3001-3099����һ��ҩƷ
    //3101-3199���ڶ���ҩƷ...
    //4001-4199���ڸ��ֹ�����Ʒ
    //5001-5199���ڸ��ַ�����Ʒ
    //���ҹ����������ֶ�Ӧ�ı�ž��������
    for (int p = 0; p < 10; ++p) {
        if (spell[p] == 1001) {
            printf("|[һ��]�����캮| ");
        }
        if (spell[p] == 1002) {
            printf("|[һ��]׷������| ");
        }
        if (spell[p] == 1003) {
            printf("|[һ��]������÷| ");
        }
        if (spell[p] == 2001) {
            printf("|[һ��]������| ");
        }
        if (spell[p] == 2002) {
            printf("|[һ��]���ɹ�| ");
        }
        if (spell[p] == 3001) {
            printf("|[һ��]��Ѫ��| ");
        }
    }
    printf("\n");
}

//������Ʒ
void Goods() {
    for (int p = 0; p < 10; ++p) {
        if (backpack[p] == 4001) {
            printf("|[һ��]ľ��| ");
        }
        if (backpack[p] == 5001) {
            printf("|[һ��]ľ��| ");
        }
    }
    printf("\n");
}

// ����������������
void showMy(char boundary[], char sects[], char sex[]) {
    for (int j = 0; j < 10; ++j) {
        //�ж����д������ķ�����������
        //��Ӧ��Ų鿴126��
        if (spell[j] > 1000 && spell[j] < 2000) {//��Ӧ��������
            attack *= 2;
        }
        if (spell[j] > 2000 && spell[j] < 3000) {//��Ӧ��������
            defense *= 2;
        }
        if (backpack[j] == 4001) {//��Ӧľ��
            attack += 30;
        }
        if (backpack[j] == 5001) {//��Ӧľ��
            defense += 30;
        }
    }
    fputs(name_my, stdout);//�������
    //չʾ�Լ�������
    printf("\n������%lf\n ������%d\n ������%d\n ������%lf\n ������%d\n", healthy, attack, defense,
           lingli, mana);
    printf("�Ա�%s\n���ɣ�%s\n���磺%s\n������\n", sex, sects, boundary);
    //�������
    Spell();
    //��̬�任���������Ʒ
    printf("���������Ʒ��\n ");
    Goods();

}

// ���ƾ���
int Boundary(char boundary[]) {

    srand(time(NULL));  // �������
//α���һ��ͻ�Ƶĸ��ʡ�
    if (lingli >= 100 + 100 * n) {
        ++n;
        //����һ����������ж��Ƿ�ͻ�Ƴɹ�
        int num1 = rand() % 100;
        printf("����Ϊ%d", num1);
        char try;
        printf("�Ƿ����ͻ�ƣ�\nY/N\n");
        scanf(" %c", &try);
        if (try == 'N' || try == 'n') {
            n--;
            return n;
        }
        switch (n) {
            case 1:

                if (num1 > 40) {
                    strcpy(boundary, "|����|\n");
                    printf("ͻ�Ƴɹ�\n");
                    healthy *= 10;
                    defense *= 10;
                    attack *= 10;
                    mana *= 10;
                    lingli = 0;
                    break;
                } else {
                    printf("\n*******ͻ��ʧ��*******\n");
                    printf("\n****��������������ɢ****\n");
                    n--;
                    lingli = 0;
                }
                break;
            case 2:
                if (num1 > 50) {
                    strcpy(boundary, "|����|\n");
                    healthy *= 10;
                    defense *= 10;
                    attack *= 10;
                    mana *= 10;
                    lingli = 0;
                    break;
                } else {
                    printf("\n*******ͻ��ʧ��*******\n");
                    printf("\n****��������������ɢ****\n");
                    lingli = 0;
                    n--;
                }
                break;
            case 3:
                if (num1 > 70) {
                    strcpy(boundary, "|�ᵤ|\n");
                    healthy *= 10;
                    defense *= 10;
                    attack *= 10;
                    mana *= 10;
                    lingli = 0;
                    break;
                } else {
                    printf("\n*******ͻ��ʧ��*******\n");
                    printf("\n****��������������ɢ****\n");
                    lingli = 0;
                    n--;
                }
                break;
            case 4:
                if (num1 > 80) {
                    strcpy(boundary, "|ԪӤ|\n");
                    healthy *= 10;
                    defense *= 10;
                    attack *= 10;
                    mana *= 10;
                    lingli = 0;
                    break;
                } else {
                    printf("\n*******ͻ��ʧ��*******\n");
                    printf("\n****��������������ɢ****\n");
                    lingli = 0;
                    n--;
                }
                break;
            case 5:
                if (num1 > 90) {
                    strcpy(boundary, "|����|\n");
                    healthy *= 10;
                    defense *= 10;
                    attack *= 10;
                    mana *= 10;
                    lingli = 0;
                    break;
                } else {
                    printf("\n*******ͻ��ʧ��*******\n");
                    printf("\n****��������������ɢ****\n");
                    lingli = 0;
                    n--;
                }
                break;
        }
    }
    return n;  // ���ظ��º�ľ���ֵ
}

// ��ʼ����ͼ
void Map(char arr[row][row], Player player) {

    // ��ʼ����ͼ
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (i == 0 || i == row - 1 || j == 0 || j == row - 1) {
                arr[i][j] = '#';  // ����ǽ
            } else {
                arr[i][j] = '_';  // ��������Ϊ�յ�
            }
        }
    }

    // ������
    arr[player.x][player.y] = 'I';
}

//��ӡ��ͼ
void printMap(char arr[row][row], char name[], int num, int num1, Player player) {
    // ��ʾ��ͼ
    char person[10][10] = {"��", "��", "��", "��", "Ѩ", "��", "��"};

    //û�м����������Ժ���˵����ֹ������ɵ���ͼ��
/*
    arr[num - 2][num + 2] = 'L';    // ����
    arr[num - 1][num - 1] = 'S';    // ����
    arr[num1][num1] = '!';    // ǿ��
    arr[num1 + 1][num1 + 1] = '!';
    arr[num1 + 1][num1 - 1] = '!';
    arr[num1 + 1][num1] = '@';//��Ѩ
    // ����������
    arr[num][num] = 'Q';
    // ������
    arr[player.x][player.y] = 'I';
*/

    printf("\n==============\n %c\n", name);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (i == (num + 1) && j == (num + 3)) {
                printf(" !");
                fputs(person[0], stdout);    // �峤
                printf("  ");
                continue;
            }
            if (i == (num - 2) && j == (num + 2)) {
                printf(" !");
                fputs(person[1], stdout);    // ����
                printf("  ");
                continue;
            }
            if (i == (num - 1) && j == (num - 1)) {
                printf(" !");
                fputs(person[2], stdout);    // ����
                printf("  ");
                continue;
            }
            if (i == (num1) && j == (num1) || i == (num1 + 1) && j == (num1 + 1) ||
                i == (num1 + 1) && j == (num1 - 1)) {
                printf(" !");
                fputs(person[3], stdout);    // ǿ��
                printf("  ");
                continue;
            }
            if (i == (num1 + 1) && j == (num1)) {
                printf(" !");
                fputs(person[4], stdout);    // ��Ѩ
                printf("  ");
                continue;
            }
            if (i == (num) && j == (num)) {
                printf(" !");
                fputs(person[5], stdout);    // ����
                printf("  ");
                continue;
            }
            if (i == (player.x) && j == (player.y)) {
                printf(" .");
                fputs(person[6], stdout);    // ���
                printf("  ");
                continue;
            }
            printf("  %c ", arr[i][j]);
            printf("  ");
        }
        printf("\n");
    }
}


//���ﳲѨ��ͼ��ʼ��
void Map_lair(char lair[low][low], Player player, int num3) {

    for (int i = 0; i < low; ++i) {
        for (int j = 0; j < low; ++j) {
            if (i == 0 || i == low - 1 || j == 0 || j == low - 1) {
                lair[i][j] = '#';  // ����ǽ
            } else {
                lair[i][j] = '-';  // ��������Ϊ�յ�
            }
        }
    }

    lair[num3 + 1][num3] = '&';//��һ��BOSS
    lair[num3][num3 - 1] = '&';//�ڶ���BOSS
    lair[num3][num3 + 1] = '&';//������BOSS
    lair[num3][num3] = '@';//����Ѩ�ĳ���
    //���峲Ѩ���ǽ
    lair[num3 - 2][num3] = '#';
    lair[num3 - 1][num3 - 1] = '#';
    lair[num3 - 1][num3 + 1] = '#';
    // ������
    lair[player.x][player.y] = 'I';


}

//��ӡ���ﳲѨ�ĵ�ͼ
void printlair(char lair[low][low], Player player, int num3) {
    char monster[10][10] = {"��", "��", "��","��"};
    //���峲Ѩ��ͼ
    for (int i = 0; i < low; i++) {
        for (int j = 0; j < low; j++) {
            if (i == (num3 + 1) && j == (num3)) {
                printf(" !");
                fputs(monster[0], stdout);
                printf("  ");
                continue;
            }
            if (i == (num3) && j == (num3 - 1)) {
                printf(" !");
                fputs(monster[1], stdout);
                printf("  ");
                continue;
            }
            if (i == (num3) && j == (num3 + 1)) {
                printf(" !");
                fputs(monster[2], stdout);
                printf("  ");
                continue;
            }
            if (i == (player.x) && j == (player.y)) {
                printf(" .");
                fputs(monster[3], stdout);
                printf("  ");
                continue;
            }
            printf("  %c ", lair[i][j]);
            printf("  ");
        }
        printf("\n");
    }
}

//�������λ�û���
void reset(Player *player) {
    player->x = 1;
    player->y = 1;
}

// ��������ƶ�
int Move(char arr[row][row], char move, Player *player, char lair[low][low]) {

    // ����ԭʼλ��
    int X = player->x;
    int Y = player->y;

    // �ƶ��߼�
    switch (move) {
        case 'w':
            player->x--;
            break;
        case 's':
            player->x++;
            break;
        case 'a':
            player->y--;
            break;
        case 'd':
            player->y++;
            break;
    }

    if (MAP == 0) {
        // �߽��飬��ֹԽ��
        if (player->x < 0 || player->x >= row || player->y < 0 || player->y >= row ||
            arr[player->x][player->y] == '#') {
            // �ָ�ԭʼλ��
            player->x = X;
            player->y = Y;
            return 0; // δ�ɹ��ƶ�
        }
        return 1; // �ɹ��ƶ�
    }

    if (MAP == 21) {
        // �߽��飬��ֹԽ��
        if (player->x < 0 || player->x >= low || player->y < 0 || player->y >= low ||
            lair[player->x][player->y] == '#') {
            // �ָ�ԭʼλ��
            player->x = X;
            player->y = Y;
            return 0; // δ�ɹ��ƶ�
        }
        return 1; // �ɹ��ƶ�
    }

    return 0; // Ĭ�������δ�ɹ��ƶ�
}

// �����¼�
/*
 *����Ӧ�ĵ�ͼ���ӹ���ͼ��
 */
int Event(Player *player, int num, int num1, char boundary[], int num3) {
    //1-10��NPC�¼�
    //11-20��ս���¼�
    //21-30�ǽ����µ�ͼ
    //�ж�������ͼ�������ĸ�

    if (MAP == 0) {

        if (player->x == num + 1 && player->y == num + 3) {
            printf("\n�������˴峤\n");
            printf("�峤:����ǰ�����������˳�û���԰���������һ����\n��Ϊ�ر���������5����Ѫ��\n");
            //��������
            task = 1;
            for (int h = 0; h < 5; ++h) {//5����Ѫ��
                backpack[obj] = 3001;
                //�����еĵڼ�λ
                ++obj;
            }
        }
        if (player->x == num - 2 && player->y == num + 2) {
            printf("\n������������\n");
            printf("���ˣ����˵��Ի�:�����Ұѹ����㣬ϣ������԰��Ҵ�������ˡ�\n");
            backpack[obj] = 4001;//һ��ľ��
            ++obj;
        }
        if (player->x == num - 1 && player->y == num - 1) {
            printf("\n������������\n");
            printf("���������꣡�����п��洫���ƣ��ɻ�����ȫ \n");
            backpack[obj] = 5001;
            ++obj;
        }
        if (player->x == num1 && player->y == num1 || player->x == num1 + 1 && player->y == num1 + 1 ||
            player->x == num1 + 1 && player->y == num1 - 1) {
            printf("\n������������\nս����ʼ��\n");
            printf("�����죺���ҿ�����ô����\n");
            event = 2;
            return event;
        }
        if (player->x == num1 + 1 && player->y == num1) {
            printf("\n****�����������˳�Ѩ****\n");
            MAP = 21;
            return MAP;
        }
        if (player->x == num && player->y == num) {
            printf("\n�����մ�������������ֵ��������\n");
            printf("�����죺�治��\n");
            lingli += 100;
            printf("����ֵ��%lf\n", lingli);

            // �������粢���¾���
            n = Boundary(boundary);
            // �����ǰ����ȼ�
            printf("��ǰ����ȼ���%d\n", n);
            return n;
        }
    }
    if (MAP == 21) {
        if (player->x == num3 && player->y == num3) {
            printf("\n****����������ִ�****\n");
            MAP = 0;
            return MAP;
        }
        if (player->x == num3 && player->y == num3 - 1) {
            printf("\n��������|[����]��������|\nս����ʼ��\n");
            printf("�����죺���ҿ�����ô����\n");
            event = 3;
            kill++;
            return event;

        }
        if (player->x == num3 && player->y == num3 + 1) {
            printf("\n��������|[����]����ɽ����|\nս����ʼ��\n");
            printf("�����죺���ҿ�����ô����\n");
            event = 4;
            kill++;
            return event;
        }
        if (player->x == num3 + 1 && player->y == num3) {
            printf("\n��������|[����]Ұ����|\nս����ʼ��\n");
            printf("�����죺���ҿ�����ô����\n");
            event = 5;
            kill++;
            return event;
        }

    }
    return 0;
}

//ս��ϵͳ
/*
 *Ȼ����������ӹ��������ֵ
 */
void Wars(int war) {
    int num1 = rand() % 20 + 30;//С�ֵ���ֵ30-50
    int num2 = rand() % 100 + 50;//boss��ֵ500-120
    int healthy_t;
    int defense_t;
    int attack_t;

    switch (event) {
        case 2:
            attack_t = num1 * 2;
            defense_t = num1 * 2;
            healthy_t = num1 * 2;
            break;
        case 3:
        case 4:
        case 5:
            attack_t = num2 * 4;
            defense_t = num2 * 4;
            healthy_t = num2 * 4;
            break;
    }

    int round = 1;

    while (healthy > 0 && healthy_t > 0) {
        printf("�غ� %d\n", round);
        printf("���Ѫ����%lf\n", healthy);
        printf("����Ѫ����%d\n", healthy_t);

        // ��һغ�
        printf("��Ļغ�\n");
        printf("1.����\n");
        printf("2.����\n");
        printf("3.����\n");
        printf("4.ҩƷ\n");
        printf("�������\n");
        scanf("%d", &war);

        switch (war) {
            case 1:
                printf("����Ѹ�ײ����ڶ�����֮ʽ��������һ��\n");
                healthy_t -= (attack - defense_t * 2);
                break;
            case 2:
                printf("���ͷ�����������������ֹ����ͷ\n");
                healthy -= (attack_t - defense * 2);
                break;
            case 3:
                for (int g = 0; g < 10; ++g) {
                    if (spell[g] != 1001 && spell[g] != 1002 && spell[g] != 1003) {
                        printf("\n�������ӷ���\n");
                        return;
                    }
                }
                printf("��˫�ֿ��ٽ�ӡ������Ĭ���\n");
                for (int i = 0; i < 15; ++i) {
                    if (spell[i] == 1001) {
                        printf("|[һ��]�����캮| ");
                    }
                    if (spell[i] == 1002) {
                        printf("|[һ��]׷������| ");
                    }
                    if (spell[i] == 1003) {
                        printf("|[һ��]������÷| ");
                    }
                    healthy_t -= (attack * 2);
                }
                break;

            case 4:
                for (int h = 0; h < 10; ++h) {
                    if (backpack[h] == 3001) {
                        printf("�����һ��ҩ��HP++\n");
                        healthy += 15;
                        backpack[h] = 0;
                        break;
                    }
                }
                break;
            default:
                printf("��Ч��ѡ��\n");
        }

        // ���ս���Ƿ����
        if (healthy <= 0) {
            printf("��������֧�ҵ��ˣ�ȫ���ա�\n");
            break;
        }
        if (healthy_t <= 0) {
            printf("��������Ĺ�����һ���غ�\n");
            printf("���ƺ��ڸղŵ�ս��������|����|\n");
            break;
        }

        // ���˻غ�
        printf("���ֻغ�\n");
        healthy -= (attack_t - defense * 0.3);

        // ���ս���Ƿ����
        if (healthy <= 0) {
            printf("��������֧�ҵ��ˣ�ȫ���ա�\n");
            break;
        }
        if (healthy_t <= 0) {
            printf("��������Ĺ�����һ���غ�\n");
            printf("���ƺ��ڸղŵ�ս��������|����|\n");
            break;
        }

        round++;
    }
    event = 0;
}

//����ϵͳ
void Task() {
    if (task == 1) {
        printf("\nĿǰ����ɱ����Ѩ����ֻ������%d/3��\n", kill);
        if (kill == 3) {
            printf("\n������ɣ�\n������\n");
            srand(time(NULL));
            int reward = rand() % 3 + 1001;
            //��������������������������н���
            switch (reward) {
                case 1001:
                    printf("|[һ��]�����캮| ");
                    spell[SpellBook] = 1001;
                    ++SpellBook;
                    break;
                case 1002:
                    printf("|[һ��]׷������| ");
                    spell[SpellBook] = 1002;
                    ++SpellBook;
                    break;
                case 1003:
                    printf("|[һ��]������÷| ");
                    spell[SpellBook] = 1003;
                    ++SpellBook;
                    break;
            }
            task = 0;
        }
    }
}

int main() {

    // ��ʼ��ս��ʱ��ѡ��
    int war = 0;
    // ����洢ѡ�������
    int arr_dec[10];
    // �����Ա�
    char sex[10];
    // �����ͼ
    char arr[row][row];
    //������ﳲѨ
    char lair[low][low];
    // �����ͼ��һ���������λ��
    int ddd = 0;
    // ����
    char name[] = "������";
    // ����
    char boundary[] = "|����|";
    // ����
    char sects[] = "��";
    // ������������ƶ�
    char move;
    // �������
    Player player = {1, 1}; // ��ʼ�����λ��
    srand(time(NULL));  // �������
    // ����0��8֮����������
    int num = rand() % 5 + 3;  // ����3-7֮��������
    srand(time(NULL));  // �������
    // ����0��10֮�������
    int num1 = rand() % 3 + 8;  // ����8-10֮��������
    srand(time(NULL));  // �������
    //����0-9�������
    int num3 = rand() % 10;
    if (menu(arr_dec, &ddd, sex) == 1) {
        return 1;
    }

    //��ʼ����ͼ
    Map(arr, player);
    Map_lair(lair, player, num3);

    Play:
    reset(&player);
    while (1) {
        //�����ִ��ƶ�
        while (1) {
            if (MAP == 0) {
                //��ʾ��ǰ����
                Task();
                // ��ʾ��ͼ
                printMap(arr, name, num, num1, player);
                printf("��I�鿴��������\n����WSAD�������ƶ�\n");
                scanf(" %c", &move);
                //�ж��ƶ�ʱѡ����ʲô
                if (move == 'i' || move == 'I') {
                    // ��ʾ���˵�����
                    showMy(boundary, sects, sex);
                }
                // ��������¼�
                if (Event(&player, num, num1, boundary, num3)) {
                    // �������粢���¾���
                    n = Boundary(boundary);
                    //ս������
                    Wars(war);
                    if(healthy <= 0){
                        printf("��Ϸ����");
                        return 0;
                    }
                }

                if (Move(arr, move, &player, lair)) {
                    // �ɹ��ƶ�����µ�ͼ
                    Map(arr, player);
                }

                if (MAP != 0) {
                    break;
                }
            }
        }
        //ÿ�ν����µ�ͼ����λ�û���
        reset(&player);
        //�ڳ�Ѩ��ͼ���ƶ�
        while (1) {
            if (MAP == 21) {
                //��ʾ��ǰ����
                Task();
                //��ʾ��Ѩ��ͼ
                printlair(lair,player,num3);
                printf("��I�鿴��������\n����WSAD�������ƶ�\n");
                scanf(" %c", &move);
                //�ж��ƶ�ʱѡ����ʲô
                if (move == 'i' || move == 'I') {
                    // ��ʾ���˵�����
                    showMy(boundary, sects, sex);
                }
                // ��������¼�
                if (Event(&player, num, num1, boundary, num3)) {
                    //ս������
                    Wars(war);
                    if(healthy <= 0){
                        printf("��Ϸ����");
                        return 0;
                    }
                }

                if (Move(arr, move, &player, lair)) {
                    // �ɹ��ƶ�����µ�ͼ
                    Map_lair(lair, player, num3);

                }

                if (MAP != 21) {
                    break;
                }
            }
        }
        //ÿ�ν����µ�ͼ����λ�û���
        reset(&player);
    }

}




