


#include <stdio.h>
#include "time.h"
#include "stdlib.h"

int main() {
    //狐狸追兔子
    //定义一个数组为地图
    char arr[29] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                    '0', '0', '0', '0', '0', '0', '0', '0', '0'};
    //决定向左走还是向右走
    char dec;
    //定义狐狸
    char H = 'h';
    //定义选择的游戏模式
    int choose = 0;
    //存储狐狸向哪走
    char go;
    //定义兔子
    char T = 't';
    //定义兔子向哪走
    char run;
    //初始化兔子的位置
    arr[4] = T;
    //定义兔子的下标
    int table_t = 4;
    int tt = 0;
    //初始化狐狸的位置
    arr[0] = H;
    //定义狐狸的下标
    int table_h = 0;
    int hh = 0;
    int rj = 0;
    char move = '\0';
    printf("狐狸追兔子小游戏\n");
    printf("输入任意键进入游戏\n");

    //识别到输入回车进入程序
    while ((dec = getchar()) != '\n') {
        while (getchar() != '\n');  //清楚缓存
        menu:

        printf("狐狸追兔子\n");
        printf("1.单人游戏\n");
        printf("2.双人游戏\n");
        printf("3.游戏规则\n");
        printf("4.退出游戏\n");
        printf("输入你想进入的模式\n");
        scanf("%d", &choose);
        while (getchar() != '\n');  //清楚缓存
        if (choose != 1 && choose != 2 && choose != 3 && choose != 4) {
            printf("请输入正确的模式编号\n");
            goto menu;
        }

        switch (choose) {
            case 1:
                printf("健康游戏忠告：\n");

                printf(" 抵制不良游戏，拒绝盗版游戏。\n");

                printf(" 注意自我保护，谨防受骗上当。\n");

                printf("   适度游戏益脑，沉迷游戏伤身。\n");

                printf(" 合理安排时间，享受健康生活。\n");
                goto play;
                break;
            case 2:
                printf("健康游戏忠告：\n");

                printf(" 抵制不良游戏，拒绝盗版游戏。\n");

                printf(" 注意自我保护，谨防受骗上当。\n");

                printf("   适度游戏益脑，沉迷游戏伤身。\n");

                printf(" 合理安排时间，享受健康生活。\n");
                goto play;
                break;
            case 3:
                printf("游戏规则\n狐狸每次可以向左或向右移动1格，兔子每次可以向左或向右跳过2格进到第3格里。狐狸先走，然后它们交替移动");
                printf("狐狸先走，然后它们交替移动如果兔子跳进狐狸所在的格子则会被吃掉。如果狐狸走进兔子所在的格子可以把兔子吃掉\n");
                printf("tips: 你看懂了吗？\n管你看没看懂，玩就完了\n");
                goto menu;
                break;
            case 4:
                printf("下班！\n");
                return 1;
        }
        play:
        while (1) {

            printf("\n当前地图情况如下\n");

            for (int i = 0; i < 29; i++) {
                printf(" %c", arr[i]);
            }
            if (table_t == table_h) {
                printf("\n狐狸胜利！\n");
                return 1;
            }
            again_h:

            printf("\n狐狸行动，你可以向左或者向右移动一格，输入L向左走输入R向右走\n");

            scanf(" %c", &go);
            //判定是否是单人模式
            if (choose == 1) {
                rj++;
            }
            while (getchar() != '\n');  //清楚缓存
            //判定如果到左面墙边的特殊情况
            if (table_h == 0) {
                if (go == 'l' || go == 'L') {
                    printf("撞墙了走不了\n");
                    goto again_h;

                }
            }
            if (table_h == 28) {
                if (go == 'r' || go == 'R') {
                    printf("撞墙了走不了\n");
                    goto again_h;
                }
            }


            //寻找狐狸所在的位置
            for (int j = 0; j < 28; j++) {
                if (arr[j] == H) {
                    table_h = j;
                    break;
                }

            }

            switch (go) {

                case 'l':

                case 'L':

                    //让原来的滞空
                    hh = table_h;
                    arr[hh] = '0';
                    //实现移动
                    table_h--;
                    arr[table_h] = H;
                    //判断是否胜利
                    if (table_t == table_h) {
                        printf("\n狐狸胜利！\n");
                        return 1;
                    }
                    if (rj != 0) {
                        goto again_T;
                    }
                    break;
                case 'r':
                case 'R':

                    //让原来的滞空
                    hh = table_h;
                    arr[hh] = '0';
                    //实现移动
                    table_h++;
                    arr[table_h] = H;
                    //判断是否胜利
                    if (table_t == table_h) {
                        printf("\n狐狸胜利！\n");
                        return 1;
                    }
                    if (rj != 0) {
                        goto again_T;
                    }
                    break;
                default:
                    printf("没事别乱输\n");
                    if (choose == 1) {
                        goto again_h;
                    }
                    goto again_h;
                    break;

            }


            again_t:

            printf("兔子行动，你可以向左或者向右移动两格，输入L向左走输入R向右走\n");
            scanf(" %c", &run);
            while (getchar() != '\n');  //清楚缓存

            //判定如果到左面墙边的特殊情况
            if (table_t == 0) {
                if (run == 'l' || run == 'L') {
                    printf("撞墙了走不了\n");
                    goto again_t;

                }
            }
            if (table_t == 28) {
                if (run == 'r' || run == 'R') {
                    printf("撞墙了走不了\n");
                    goto again_t;
                }
            }

            //寻找兔子所在的位置
            for (int j = 0; j < 29; j++) {
                if (arr[j] == T) {
                    table_t = j;
                }

            }
            switch (run) {
                case 'l':

                case 'L':
                    //让原来的滞空
                    tt = table_t;
                    arr[tt] = '0';
                    //特殊处理，当狐狸先动，兔子后动，狐狸移动到兔子之前的位置会把狐狸滞空
                    if (tt == hh) {
                        arr[table_h] = H;
                    }
                    //实现移动
                    table_t--;
                    table_t--;
                    arr[table_t] = T;


                    break;
                case 'r':
                case 'R':
                    //让原来的滞空
                    tt = table_t;
                    arr[tt] = '0';
                    //特殊处理，当狐狸先动，兔子后动，狐狸移动到兔子之前的位置会把狐狸滞空
                    if (tt == hh) {
                        arr[table_h] = H;
                    }
                    //实现移动
                    table_t++;
                    table_t++;
                    arr[table_t] = T;

                    break;
                default:
                    printf("没事别乱输\n");
                    goto again_t;
                    break;
            }
            again_T:
            if (choose == 1) {


                if (rj == 0) {
                    printf("异常");
                    return 1;
                }
                //寻找兔子所在的位置
                for (int j = 0; j < 30; j++) {
                    if (arr[j] == T) {
                        table_t = j;
                    }
                }
                //让他稍微的智能化
                //兔子每次判定做跳三个内是否有狐狸，如果有则向反方向跳
                //防止兔子跳出地图外 table_t - 2 >= 0
                if (arr[table_t - 1] == '0' && arr[table_t - 2] == '0' && arr[table_t - 3] != 'h' && table_t - 2 >= 0) {

                    //让原来的滞空
                    tt = table_t;
                    arr[tt] = '0';
                    //特殊处理，当狐狸先动，兔子后动，狐狸移动到兔子之前的位置会把狐狸滞空
                    if (tt == hh) {
                        arr[table_h] = H;
                    }
                    //实现移动
                    table_t--;
                    table_t--;
                    arr[table_t] = T;

                    goto play;
                } else if (arr[table_t + 1] == '0' && arr[table_t + 2] == '0' && arr[table_t + 3] != 'h' &&
                           table_t + 2 <= 28) {
                    //让原来的滞空
                    tt = table_t;
                    arr[tt] = '0';
                    //特殊处理，当狐狸先动，兔子后动，狐狸移动到兔子之前的位置会把狐狸滞空
                    if (tt == hh) {
                        arr[table_h] = H;
                    }
                    //实现移动
                    table_t++;
                    table_t++;
                    arr[table_t] = T;
                    goto play;
                } else {

                    if (table_t - 2 >= 0) {
                        //让原来的滞空
                        tt = table_t;
                        arr[tt] = '0';
                        //特殊处理，当狐狸先动，兔子后动，狐狸移动到兔子之前的位置会把狐狸滞空
                        if (tt == hh) {
                            arr[table_h] = H;
                        }
                        //实现移动
                        table_t--;
                        table_t--;
                        arr[table_t] = T;

                        goto play;
                    } else {
                        //让原来的滞空
                        tt = table_t;
                        arr[tt] = '0';
                        //特殊处理，当狐狸先动，兔子后动，狐狸移动到兔子之前的位置会把狐狸滞空
                        if (tt == hh) {
                            arr[table_h] = H;
                        }
                        //实现移动
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


