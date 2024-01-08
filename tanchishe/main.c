#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define Long 111 // ��Ϸ������
#define Height 29 // ��Ϸ����߶�
// �����ͼԪ��

#define SNAKE_BODY 1 //����
#define SNAKE_HEAD 2 //��ͷ
#define FOOD 3 //ʳ��
#define WALL 4 //ǽ
#define UP 72 //���������
#define DOWN 80 //���������
#define LEFT 75 //���������
#define RIGHT 77 //���������
#define SPACE 32 //��ͣ
#define ESC 27 //�˳�
// ����̰���߽ṹ��
typedef struct {
    int x;
    int y;
    int lastMove;  // ��һ���ƶ��ķ���
    int score;  // �÷�
    int gameover;  // ��Ϸ������־
} snake_head;
typedef struct {
    int x[Height * Long];
    int y[Height * Long];
} snake_body;
typedef struct {
    snake_head *head;
    snake_body *body;
} snakes;
snakes *snake[3];
int map[Height][Long];  // ��ͼ�������߽�
int play, number = 0;//ѡ��ģʽ�͵�ͼ��С
int foodX, foodY;  // ʳ������
int wallX[30], wallY[30],level =0,temp = 0 , fangxiang;//ǽ�ĺ�������͵ڼ���,�洢�ڼ��ص���ʱ�������ж�����

//�����߼��Ĳ����ͳ�ʼ���߼�
void intSnake(int player) {//player�������
    //��̬�����ߵ��ڴ�
    int a = rand() % (Height / 2) + 2;
    int b = rand() % (Long / 2) + 2;
    for (int i = 0; i <= player; ++i) {
        snake[i] = (snakes *) malloc(sizeof(snakes));
        snake[i]->head = (snake_head *) malloc(sizeof(snake_head));
        snake[i]->body = (snake_body *) malloc(sizeof(snake_body));
    }
    if (player == 0 && number == 0) {
        snake[player]->head->score = 2;
        snake[player]->head->x = a;
        snake[player]->head->y = b;
        snake[player]->head->lastMove = 6;
        snake[player]->head->gameover = 0;
        snake[player]->body->x[0] = a;
        snake[player]->body->y[0] = b - 1;
        snake[player]->body->x[1] = a;
        snake[player]->body->y[1] = b - 2;
        map[snake[player]->head->x][snake[player]->head->y] = SNAKE_HEAD;
        map[snake[player]->body->x[0]][snake[player]->body->y[0]] = SNAKE_BODY;
        map[snake[player]->body->x[1]][snake[player]->body->y[1]] = SNAKE_BODY;
    } else if (player == 1 && number == 0) {
        snake[0]->head->x = 8;
        snake[0]->head->y = 8;
        snake[0]->body->x[0] = 8;
        snake[0]->body->y[0] = 8 - 1;
        snake[0]->body->x[1] = 8;
        snake[0]->body->y[1] = 8 - 2;
        snake[player]->head->x = a;
        snake[player]->head->y = b;
        snake[player]->body->x[0] = a;
        snake[player]->body->y[0] = b - 1;
        snake[player]->body->x[1] = a;
        snake[player]->body->y[1] = b - 2;
        for (int i = 0; i <= player; ++i) {
            snake[i]->head->score = 2;
            snake[i]->head->lastMove = 6;
            snake[i]->head->gameover = 0;
            map[snake[i]->head->x][snake[i]->head->y] = SNAKE_HEAD;
            map[snake[i]->body->x[0]][snake[i]->body->y[0]] = SNAKE_BODY;
            map[snake[i]->body->x[1]][snake[i]->body->y[1]] = SNAKE_BODY;
        }
    }
    if (player == 2 && number == 1) {
        int q, p;
        snake[0]->head->score = 3;
        snake[0]->head->x = a;
        snake[0]->head->y = b;
        snake[0]->head->lastMove = 6;
        snake[0]->head->gameover = 0;
        snake[0]->body->x[0] = a;
        snake[0]->body->y[0] = b - 1;
        snake[0]->body->x[1] = a;
        snake[0]->body->y[1] = b - 2;
        snake[0]->body->x[2] = a;
        snake[0]->body->y[2] = b - 2;
        map[snake[0]->head->x][snake[0]->head->y] = SNAKE_HEAD;
        map[snake[0]->body->x[0]][snake[0]->body->y[0]] = SNAKE_BODY;
        map[snake[0]->body->x[1]][snake[0]->body->y[1]] = SNAKE_BODY;
        map[snake[0]->body->x[2]][snake[0]->body->y[2]] = SNAKE_BODY;
    }
}

//��ɫ����
void color(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //��ɫ����
    //ע��SetConsoleTextAttribute��һ��API��Ӧ�ó����̽ӿڣ�
}

//���ع��
void HideCursor() {
    CONSOLE_CURSOR_INFO curInfo; //��������Ϣ�Ľṹ�����
    curInfo.dwSize = 1; //���û��ֵ�Ļ������������Ч
    curInfo.bVisible = FALSE; //���������Ϊ���ɼ�
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
    SetConsoleCursorInfo(handle, &curInfo); //���ù����Ϣ
}

//�����ת
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//�����
void out() {
    // ����ߺ�ʳ��
    for (int i = 0; i < Height; ++i) {
        for (int j = 0; j < Long; ++j) {
            if (map[i][j] == SNAKE_HEAD) {
                color(2);
                gotoxy(j, i);
                printf("O");  // ��ͷ
            } else if (map[i][j] == SNAKE_BODY) {
                color(1 + rand() % 14);
                gotoxy(j, i);
                printf("o");  // ����
            } else if (map[i][j] == FOOD) {
                gotoxy(j, i);
                printf("��");  // ʳ��
            }else if(map[i][j] == WALL){
                gotoxy(j,i);
                printf("��");//ǽ
            }else {
                printf(" ");  // �ո��ʾ�հ�����
            }
        }
        printf("\n");
    }

}

//����ʳ�������������������ʳ��ĸ���
void Food(int player) {
    for (int i = 0; i <= player; ++i) {
        // ����ʳ����������
        foodY = 1 + rand() % (Long - 2);
        foodX = 1 + rand() % (Height - 2);
        // ���ʳ������������ϣ���������
        while (map[foodY][foodX] == SNAKE_BODY) {
            foodY = 1 + rand() % (Long - 2);
            foodX = 1 + rand() % (Height - 2);
        }
    }
}

//��������Ǽ��͸����߼�����Ϣ
void updateMap(int player) {
    // ���µ�ͼ
    for (int i = 0; i < Height; ++i) {
        for (int j = 0; j < Long; ++j) {
            if (i == 0 || i == Height - 1 || j == 0 || j == Long - 1) {
                map[i][j] = 1;  // �߽�
            } else {
                map[i][j] = 0;  // ��յ�ͼ
            }
        }
    }
    // ���������ͷ�����µ���ͼ��
    for (int i = 0; i <= player; ++i) {
        for (int j = 0; j < snake[i]->head->score; ++j) {
            map[snake[i]->body->x[j]][snake[i]->body->y[j]] = SNAKE_BODY;
        }
        map[snake[i]->body->x[0]][snake[i]->body->y[0]] = SNAKE_HEAD;
        if (player == 2) {
            break;
        }
    }
    // ��ʳ����µ���ͼ��
    map[foodX][foodY] = FOOD;
    if(play == 2) {
        // �ڵ�ͼ������ǽ
        for (int i = 0; i < level; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (fangxiang == 0) {
                    map[wallX[i] + j][wallY[i]] = WALL;
                } else {
                    map[wallX[i]][wallY[i] + j] = WALL;
                }
            }
        }
    }
}

//����������
void updateBody(int player) {
    if (player == 2) {
        int prevX = snake[0]->body->x[0];
        int prevY = snake[0]->body->y[0];
        int prev2X, prev2Y;

        // ������β��λ��
        snake[0]->body->x[0] = snake[0]->head->x;
        snake[0]->body->y[0] = snake[0]->head->y;

        // �����������λ��
        for (int i = 1; i < snake[0]->head->score; ++i) {
            prev2X = snake[0]->body->x[i];
            prev2Y = snake[0]->body->y[i];
            snake[0]->body->x[i] = prevX;
            snake[0]->body->y[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        return;
    }
    int prevX = snake[player]->body->x[0];
    int prevY = snake[player]->body->y[0];
    int prev2X, prev2Y;

    // ������β��λ��
    snake[player]->body->x[0] = snake[player]->head->x;
    snake[player]->body->y[0] = snake[player]->head->y;

    // �����������λ��
    for (int i = 1; i < snake[player]->head->score; ++i) {
        prev2X = snake[player]->body->x[i];
        prev2Y = snake[player]->body->y[i];
        snake[player]->body->x[i] = prevX;
        snake[player]->body->y[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
}

//���ռ������벢�ƶ�
void algorithm(int player) {

    if (player == 0) {
        updateBody(player);//������β
        switch (snake[player]->head->lastMove) {
            case 8:
                snake[player]->head->x--;
                break;
            case 2:
                snake[player]->head->x++;
                break;
            case 4:
                snake[player]->head->y--;
                break;
            case 6:
                snake[player]->head->y++;
                break;
        }
    } else if (player == 1) {
        //������β
        for (int i = 0; i <= player; ++i) {
            updateBody(i);
        }
        for (int i = 0; i <= player; ++i) {
            switch (snake[i]->head->lastMove) {
                case 8:
                    snake[i]->head->x--;
                    break;
                case 2:
                    snake[i]->head->x++;
                    break;
                case 4:
                    snake[i]->head->y--;
                    break;
                case 6:
                    snake[i]->head->y++;
                    break;
            }
        }
    }
    if (player == 2) {
        updateBody(player);//������β
        switch (snake[0]->head->lastMove) {
            case 8:
                snake[0]->head->x--;
                break;
            case 2:
                snake[0]->head->x++;
                break;
            case 4:
                snake[0]->head->y--;
                break;
            case 6:
                snake[0]->head->y++;
                break;
        }
    }
}

//�ƶ�
void move(int player) {
    char input;
    int num;
    if (player == 0) {
        // �����û�����
        if (_kbhit()) {
            input = _getch();
            if (input == SPACE) {
                while (1) {
                    int put = _getch();
                    if (put == SPACE) {
                        break;
                    }
                    Sleep(1);
                }
            }
            if (input == ESC) {
                exit(0);
            }
            if (input == UP && snake[player]->head->lastMove != 2 ||
                input == 'w' && snake[player]->head->lastMove != 2 ||
                input == 'W' && snake[player]->head->lastMove != 2) {
                snake[player]->head->lastMove = 8;
            } else if (input == DOWN && snake[player]->head->lastMove != 8 ||
                       input == 's' && snake[player]->head->lastMove != 8 ||
                       input == 'S' && snake[player]->head->lastMove != 8) {
                snake[player]->head->lastMove = 2;
            } else if (input == LEFT && snake[player]->head->lastMove != 6 ||
                       input == 'a' && snake[player]->head->lastMove != 6 ||
                       input == 'A' && snake[player]->head->lastMove != 6) {
                snake[player]->head->lastMove = 4;
            } else if (input == RIGHT && snake[player]->head->lastMove != 4 ||
                       input == 'd' && snake[player]->head->lastMove != 4 ||
                       input == 'D' && snake[player]->head->lastMove != 4) {
                snake[player]->head->lastMove = 6;
            }
        }
    }
    if (player == 1) {
        // �����û�����
        if (_kbhit()) {
            input = _getch();
            if (input == ESC) {
                exit(0);
            }
            if (input == SPACE) {
                while (1) {
                    int put = _getch();
                    if (put == SPACE) {
                        break;
                    }
                    Sleep(1);
                }
            }
            if (input == UP || input == DOWN || input == LEFT || input == RIGHT) {
                num = 0;
            }
            if (input == 'S' || input == 's' || input == 'w' || input == 'W' || input == 'a' ||
                input == 'A' ||
                input == 'd' || input == 'D') {
                num = 1;
            }
            if (input == UP && snake[num]->head->lastMove != 2) {
                snake[num]->head->lastMove = 8;
            } else if (input == DOWN && snake[num]->head->lastMove != 8) {
                snake[num]->head->lastMove = 2;

            } else if (input == LEFT && snake[num]->head->lastMove != 6) {
                snake[num]->head->lastMove = 4;
            } else if (input == RIGHT && snake[num]->head->lastMove != 4) {
                snake[num]->head->lastMove = 6;
            }
            if (input == 'w' && snake[num]->head->lastMove != 2 ||
                input == 'W' && snake[num]->head->lastMove != 2) {
                snake[num]->head->lastMove = 8;
            } else if (input == 's' && snake[num]->head->lastMove != 8 ||
                       input == 'S' && snake[num]->head->lastMove != 8) {
                snake[num]->head->lastMove = 2;
            } else if (input == 'a' && snake[num]->head->lastMove != 6 ||
                       input == 'A' && snake[num]->head->lastMove != 6) {
                snake[num]->head->lastMove = 4;
            } else if (input == 'd' && snake[num]->head->lastMove != 4 ||
                       input == 'D' && snake[num]->head->lastMove != 4) {
                snake[num]->head->lastMove = 6;
            }
        }
    }
    if (player == 2) {
        // �����û�����
        if (_kbhit()) {
            input = _getch();
            if (input == ESC) {
                exit(0);
            }
            if (input == SPACE) {
                while (1) {
                    int put = _getch();
                    if (put == SPACE) {
                        break;
                    }
                    Sleep(1);
                }
            }
            if (input == UP && snake[0]->head->lastMove != 2 ||
                input == 'w' && snake[0]->head->lastMove != 2 ||
                input == 'W' && snake[0]->head->lastMove != 2) {
                snake[0]->head->lastMove = 8;
            } else if (input == DOWN && snake[0]->head->lastMove != 8 ||
                       input == 's' && snake[0]->head->lastMove != 8 ||
                       input == 'S' && snake[0]->head->lastMove != 8) {
                snake[0]->head->lastMove = 2;
            } else if (input == LEFT && snake[0]->head->lastMove != 6 ||
                       input == 'a' && snake[0]->head->lastMove != 6 ||
                       input == 'A' && snake[0]->head->lastMove != 6) {
                snake[0]->head->lastMove = 4;
            } else if (input == RIGHT && snake[0]->head->lastMove != 4 ||
                       input == 'd' && snake[0]->head->lastMove != 4 ||
                       input == 'D' && snake[0]->head->lastMove != 4) {
                snake[0]->head->lastMove = 6;
            }
        }
    }
}

//����Ƿ�ײ�����������ǽ��������Ĳ����Ǽ��ͼ���߼�����Ϣ
int check(int player) {
    for (int j = 0; j <= player; ++j) {
        // ����Ƿ�ײ��ǽ�ڻ�������
        if (snake[j]->head->x <= 0 || snake[j]->head->x >= Height - 1 || snake[j]->head->y <= 0 ||
            snake[j]->head->y >= Long - 1) {
            snake[j]->head->gameover = 1;
            return snake[j]->head->gameover;
        }
        for (int i = 0; i < snake[j]->head->score; ++i) {
            if (snake[j]->head->x == snake[j]->body->x[i] &&
                snake[j]->head->y == snake[j]->body->y[i]) {
                snake[j]->head->gameover = 1;
                return snake[i]->head->gameover;
            }
            if(map[snake[j]->head->x][snake[j]->head->y] == WALL){
                snake[j]->head->gameover = 1;
                return snake[i]->head->gameover;
            }
        }

        // ����Ƿ�Ե�ʳ��
        if (snake[j]->head->x == foodX && snake[j]->head->y == foodY) {
            snake[j]->head->score = snake[j]->head->score + 1;
            updateBody(j);
            Food(j);  // �����µ�ʳ��
            if(play ==2) {
                temp = level;
                ++level;
                for (int i = temp; i < level; ++i) {
                    wallX[i] = rand() % (Height - 1);
                    wallY[i] = rand() % (Long - 1);
                    fangxiang = rand() % 2;
                }
            }
        }
        //�����ͷ�Ƿ�ײ�������ɵ�ǽ
        if (play == 0 && number == 1) {
            if (map[snake[0]->head->x][snake[0]->head->y] == SNAKE_BODY) {
                snake[j]->head->gameover = 1;
                return snake[0]->head->gameover;
            }
        }

        if (player == 2) {
            return 0;
        }
    }
    return 0;
}

void menu() {
    int dec, difficulty;
    printf("\n\n\n\n\t\t\t̰���ߴ���ս");
    printf("\n\t\t\t0.����ģʽ");
    printf("\n\t\t\t1.����ģʽ");
    printf("\n\t\t\t2.˫��ģʽ");
    printf("\n\t\t\t4.�˳���Ϸ");
    scanf("%d", &dec);
    system("cls");

    switch (dec) {
        case 1:
            play = 0; // ����ģʽ


            break;
        case 2:
            play = 1; // ˫��ģʽ
            break;
        case 0:
            play = 2; // �Զ���ģʽ
            number = 1;//�ڼ���
            break;
        case 4:
            exit(0);
        default:
            printf("������������Ϲ涨��ѡ��");
            menu();
            break;
    }
}
void tips(){
    gotoxy(130,0);
    printf("WASD/��������ƶ� | space/�ո���ͣ | Esc������");
}
int main() {
    //���عر�
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    char dec;
    menu();//�˵�ѡ��
    HideCursor();//���ع��

    srand(time(NULL));  // �����������
    for (int k = 0; k <= play; ++k) {//����ѡ���ģʽ��ʼ����Ӧ������
        if (play == 1 && k == 0 || play == 2 && k == 0 || play == 2 && k == 1) {//��������ģʽ
            continue;
        }
        intSnake(k);//��ʼ����
        Food(k);//����ʳ��
        updateMap(k);//���µ�ͼ
        while (check(k) == 0) {//�����������������ѭ������

            for (int i = 0; i < 10; ++i) {//�ظ�����ʮ���ƶ�ָ���ֹһ�ΰ�̫���µ��»�������
                move(k);//�����ƶ�
            }
            algorithm(k);//���ݽ��մ����ƶ��߼�
            updateMap(k);//�ƶ�����µ�ͼ
            out();//�����ͼ��
            tips();//������ʾ
            Sleep(80);//��ͣ80��ֹ�ƶ�̫��
        }
    }
    // ��Ϸ��������
    system("cls");
    printf("\n\n\n\n\t\t\t��Ϸ����");
    for (int i = 0; i <= play; ++i) {
        printf("\n\n\n\t\t\t���%d����Ϊ��%d", i + 1, snake[i]->head->score);
        if (play == 2) {
            break;
        }
    }
    for (int i = 0; i <= play; ++i) {
        free(snake[i]->head);
        free(snake[i]->body);
        free(snake[i]);

    }
    printf("\n\t\t\t�Ƿ�Ҫ������Ϸ��\n\t\t\tY/N\n\t\t\t");
    scanf(" %c", &dec);
    if (dec == 'y' || dec == 'Y') {
        system("cls");
        main();
    } else {
        exit(0);
    }
    return 0;
}

