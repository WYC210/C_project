#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define Long 111 // 游戏区域宽度
#define Height 29 // 游戏区域高度
// 定义地图元素

#define SNAKE_BODY 1 //蛇身
#define SNAKE_HEAD 2 //蛇头
#define FOOD 3 //食物
#define WALL 4 //墙
#define UP 72 //方向键：上
#define DOWN 80 //方向键：下
#define LEFT 75 //方向键：左
#define RIGHT 77 //方向键：右
#define SPACE 32 //暂停
#define ESC 27 //退出
// 定义贪吃蛇结构体
typedef struct {
    int x;
    int y;
    int lastMove;  // 上一次移动的方向
    int score;  // 得分
    int gameover;  // 游戏结束标志
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
int map[Height][Long];  // 地图，包含边界
int play, number = 0;//选则模式和地图大小
int foodX, foodY;  // 食物坐标
int wallX[30], wallY[30],level =0,temp = 0 , fangxiang;//墙的横纵坐标和第几关,存储第几关的临时变量，判定方向

//传入蛇几的参数就初始化蛇几
void intSnake(int player) {//player玩家人数
    //动态分配蛇的内存
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

//颜色设置
void color(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //颜色设置
    //注：SetConsoleTextAttribute是一个API（应用程序编程接口）
}

//隐藏光标
void HideCursor() {
    CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量
    curInfo.dwSize = 1; //如果没赋值的话，光标隐藏无效
    curInfo.bVisible = FALSE; //将光标设置为不可见
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
    SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}

//光标跳转
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//输出蛇
void out() {
    // 输出蛇和食物
    for (int i = 0; i < Height; ++i) {
        for (int j = 0; j < Long; ++j) {
            if (map[i][j] == SNAKE_HEAD) {
                color(2);
                gotoxy(j, i);
                printf("O");  // 蛇头
            } else if (map[i][j] == SNAKE_BODY) {
                color(1 + rand() % 14);
                gotoxy(j, i);
                printf("o");  // 蛇身
            } else if (map[i][j] == FOOD) {
                gotoxy(j, i);
                printf("★");  // 食物
            }else if(map[i][j] == WALL){
                gotoxy(j,i);
                printf("█");//墙
            }else {
                printf(" ");  // 空格表示空白区域
            }
        }
        printf("\n");
    }

}

//生成食物——传入的坐标决定生成食物的个数
void Food(int player) {
    for (int i = 0; i <= player; ++i) {
        // 生成食物的随机坐标
        foodY = 1 + rand() % (Long - 2);
        foodX = 1 + rand() % (Height - 2);
        // 如果食物出现在蛇身上，重新生成
        while (map[foodY][foodX] == SNAKE_BODY) {
            foodY = 1 + rand() % (Long - 2);
            foodX = 1 + rand() % (Height - 2);
        }
    }
}

//传入参数是几就更新蛇几的信息
void updateMap(int player) {
    // 更新地图
    for (int i = 0; i < Height; ++i) {
        for (int j = 0; j < Long; ++j) {
            if (i == 0 || i == Height - 1 || j == 0 || j == Long - 1) {
                map[i][j] = 1;  // 边界
            } else {
                map[i][j] = 0;  // 清空地图
            }
        }
    }
    // 将蛇身体和头部更新到地图上
    for (int i = 0; i <= player; ++i) {
        for (int j = 0; j < snake[i]->head->score; ++j) {
            map[snake[i]->body->x[j]][snake[i]->body->y[j]] = SNAKE_BODY;
        }
        map[snake[i]->body->x[0]][snake[i]->body->y[0]] = SNAKE_HEAD;
        if (player == 2) {
            break;
        }
    }
    // 将食物更新到地图上
    map[foodX][foodY] = FOOD;
    if(play == 2) {
        // 在地图上生成墙
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

//更新蛇身体
void updateBody(int player) {
    if (player == 2) {
        int prevX = snake[0]->body->x[0];
        int prevY = snake[0]->body->y[0];
        int prev2X, prev2Y;

        // 更新蛇尾的位置
        snake[0]->body->x[0] = snake[0]->head->x;
        snake[0]->body->y[0] = snake[0]->head->y;

        // 更新蛇身体的位置
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

    // 更新蛇尾的位置
    snake[player]->body->x[0] = snake[player]->head->x;
    snake[player]->body->y[0] = snake[player]->head->y;

    // 更新蛇身体的位置
    for (int i = 1; i < snake[player]->head->score; ++i) {
        prev2X = snake[player]->body->x[i];
        prev2Y = snake[player]->body->y[i];
        snake[player]->body->x[i] = prevX;
        snake[player]->body->y[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
}

//接收键盘输入并移动
void algorithm(int player) {

    if (player == 0) {
        updateBody(player);//更新蛇尾
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
        //更新蛇尾
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
        updateBody(player);//更新蛇尾
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

//移动
void move(int player) {
    char input;
    int num;
    if (player == 0) {
        // 处理用户输入
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
        // 处理用户输入
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
        // 处理用户输入
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

//检查是否撞到了身体或者墙——传入的参数是几就检查蛇几的信息
int check(int player) {
    for (int j = 0; j <= player; ++j) {
        // 检测是否撞到墙壁或者自身
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

        // 检测是否吃到食物
        if (snake[j]->head->x == foodX && snake[j]->head->y == foodY) {
            snake[j]->head->score = snake[j]->head->score + 1;
            updateBody(j);
            Food(j);  // 生成新的食物
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
        //检测蛇头是否撞到了生成的墙
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
    printf("\n\n\n\n\t\t\t贪吃蛇大作战");
    printf("\n\t\t\t0.闯关模式");
    printf("\n\t\t\t1.单人模式");
    printf("\n\t\t\t2.双人模式");
    printf("\n\t\t\t4.退出游戏");
    scanf("%d", &dec);
    system("cls");

    switch (dec) {
        case 1:
            play = 0; // 单人模式


            break;
        case 2:
            play = 1; // 双人模式
            break;
        case 0:
            play = 2; // 自定义模式
            number = 1;//第几关
            break;
        case 4:
            exit(0);
        default:
            printf("错误：请输入符合规定的选项");
            menu();
            break;
    }
}
void tips(){
    gotoxy(130,0);
    printf("WASD/方向键：移动 | space/空格：暂停 | Esc：结束");
}
int main() {
    //隐藏关标
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    char dec;
    menu();//菜单选择
    HideCursor();//隐藏光标

    srand(time(NULL));  // 设置随机种子
    for (int k = 0; k <= play; ++k) {//根据选择的模式初始化对应的数据
        if (play == 1 && k == 0 || play == 2 && k == 0 || play == 2 && k == 1) {//跳过单人模式
            continue;
        }
        intSnake(k);//初始化蛇
        Food(k);//生成食物
        updateMap(k);//更新地图
        while (check(k) == 0) {//当检查满足死亡条件循环结束

            for (int i = 0; i < 10; ++i) {//重复接收十次移动指令防止一次按太多下导致缓存问题
                move(k);//接收移动
            }
            algorithm(k);//根据接收处理移动逻辑
            updateMap(k);//移动后更新地图
            out();//输出蛇图像
            tips();//侧栏提示
            Sleep(80);//暂停80防止移动太快
        }
    }
    // 游戏结束处理
    system("cls");
    printf("\n\n\n\n\t\t\t游戏结束");
    for (int i = 0; i <= play; ++i) {
        printf("\n\n\n\t\t\t玩家%d分数为：%d", i + 1, snake[i]->head->score);
        if (play == 2) {
            break;
        }
    }
    for (int i = 0; i <= play; ++i) {
        free(snake[i]->head);
        free(snake[i]->body);
        free(snake[i]);

    }
    printf("\n\t\t\t是否要继续游戏？\n\t\t\tY/N\n\t\t\t");
    scanf(" %c", &dec);
    if (dec == 'y' || dec == 'Y') {
        system("cls");
        main();
    } else {
        exit(0);
    }
    return 0;
}

