
/*
计算器
缺点，数组长度有限，最大计算次数为99次，如果超过了这个次数，那么数组将会 报错
待优化：没有真正实现动态扩容数组
未知错误，最后判定是否退出时输入除1以外的数字会报错；
*/

#include <stdio.h>

int main() {

    //判断是否进入计算
    char decide;
    // 用于存储数字的数组
    double arr[100];
    // 用于存储运算符的数组
    char arrs[100];
    printf("计算器\n输入回车进入\n");
    while (1) {
        //初始化存储的最终结果
        double Temp = 0;
        //初始化统计数字个数值
        int js = 1;
        //初始化承载数字的数组长度
        int num = 0;
        //初始化承载符号的数组长度
        int NUM = 0;
        //初始化输入的有效数组长度
        int length = 0;
        //判断是否继续循环
        char dec;


        //识别到输入回车进入程序
        while (1) {
            decide = getchar();
            if (decide != '\n') {
                break;
            }
            //接收第n个数字，并判定是否读取成功
            printf("输入你的第%d个数字\n: ", js);
            if (scanf("%lf", &arr[num]) != 1) {
                printf("请输入合法的数字\n");
                while (getchar() != '\n'); // 清除输入缓冲
                continue;
            }
            //记录第几个数字
            ++js;
            //数组扩容
            ++num;
            //伪动态数组长度
            length = num;
            //数组随着输入数字次数增加而自增
            //arrs的数组首位滞空，为了与arr数组对应
            ++NUM;
            printf("\n请输入运算符 (+, -, *, /, =):\n");
            scanf(" %c", &arrs[NUM]);
            while (arrs[NUM] != '+' && arrs[NUM] != '-' && arrs[NUM] != '*' && arrs[NUM] != '/' && arrs[NUM] != '=') {
                printf("\n"); //使进入循环
                printf("\n请输入正确的符号:\n");
                while (getchar() != '\n');
                arrs[NUM] = getchar(); //重新获取符号
            }

            //识别=时退出
            if (arrs[NUM] == '=') {
                break;
            }

        }
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
        printf("\n结果为%lf\n", Temp);
        //判断是否继续循环
        printf("是否还要继续输入 1继续或按任意字母退出\n");
        scanf("%d", &dec);
        if (dec != 1) {
            return 1;
        }
    }

}

