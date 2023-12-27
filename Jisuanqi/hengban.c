

#include<stdio.h>

//初始化存储的最终结果
double Temp = 0;

//初始化承载数字的数组长度
int num = 0;

//初始化输入的有效数组长度
int length = 0;

//判断是否进入计算
char decide;
// 用于存储数字的数组
double arr[100];
// 用于存储运算符的数组
char arrs[100];

int calculator() {
    // 三级运算，将乘法和除法转化为加法
//判定寻找到乘法和除法时，优先计算
// 然后把对应的符号置换成加法，并把计算的两个数字一个置换成0一个置换成结果
    for (int i = 0; i <= length; i++) {
        if (arrs[i] == '*') {
            arr[i] = arr[i - 1] * arr[i];
            arr[i - 1] = 0;
            arrs[i] = arrs[i - 1];
        }
        if (arrs[i] == '/') {
            if (arr[i] == 0) {
                printf("错误，除数不能为0，循环终止\n");
                return 1;
            }
            arr[i] = arr[i - 1] / arr[i];
            arr[i - 1] = 0;
            arrs[i] = arrs[i - 1];
        }
    }
    // 二级运算，将减法转化为其前一位的运算符号
    for (int j = 1; j <= length; j++) {
        if (arrs[j] == '-') {
            arr[j] = arr[j] - arr[j - 1];
            arr[j - 1] = 0;
            //当判断的数不是首位计算时，交换符号
            if (j != 1) {
                arrs[j] = arrs[j - 1];
            }

            arr[j] *= -1;

        }
        //当判断的数不是首位计算时，交换符号
        if (arrs[j] == '+') {

            arr[j] = arr[j] + arr[j - 1];
            arr[j - 1] = 0;
            if (j != 1) {
                arrs[j] = arrs[j - 1];
            }

        }
    }
    //遍历数组中的结果相加
    for (int p = 0; p < length; p++) {
        Temp += arr[p];
    }
    //输出最终结果
    printf("\n结果为%0.3lf\n", Temp);
    return 0;
}


int main() {

    printf("计算器\n输入任意键进入\n");
    while (1) {
        //初始化存储的最终结果
        Temp = 0;

        //初始化承载数字的数组长度
        num = 0;

        //初始化输入的有效数组长度
        length = 0;
        //判断是否继续循环
        char dec;

        // 识别到输入任意键进入程序
        while ((decide = getchar()) != '\n') {

            play:
            while (getchar() != '\n'); // 清除输入缓冲
            /*
            循环变量初始化
            清理所有缓存
            */

            //置空数组
            for (int i = 0; i < num; i++) {
                arr[i] = 0;
                arrs[i] = '\0';
            }
            Temp = 0;
            num = 0;
            length = 0;

            //接收式子
            printf("输入你的式子\n: ");

            while (1) {
                /*
                注：此处不可清理缓存，运用缓存原理进行轮流赋值
                */
                //接收所有数字
                scanf("%lf", &arr[num++]);

                //接收符号
                char p;
                p = getchar();

                arrs[num] = p;
                //判断识别到=号记录长度并退出赋值
                if (arrs[num] == '=') {
                    length = num;

                    break;
                }

                //判定如果式子中有非法符号直接退出重写
                if (arrs[num] != '+' && arrs[num] != '-' && arrs[num] != '*' && arrs[num] != '/' && arrs[num] != '=') {
                    printf("你输入了非法符号，请重新输入\n");
                    goto play;
                }
                // 判断如果式子不完整没有加 = 号，那么重新输入
                for (int j = 0; j < length + 1; j++) {
                    if (arrs[j] == '=') {
                        goto calculator;
                    }
                    if (j == 99) {
                        if (arr[j] != '=') {
                            printf("你输入了不完整的式子，请重新输入\n");
                            goto play;
                        }
                    }

                }
            }
            calculator:
            //调用计算
            calculator();
            while (getchar() != '\n'); // 清除输入缓冲

            //判断是否继续循环
            printf("是否还要继续输入 Y 继续或按任意数字退出\n");
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