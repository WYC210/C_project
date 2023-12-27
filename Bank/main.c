

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
//定义第几条存款记录
int record = 0;
void now(char Time[][50], double money) {
    time_t t;
    struct tm *info;
    time(&t);
    info = localtime(&t);

    sprintf(Time[record], "你在%d年%d月%d日 %02d:%02d:%02d 存取了%lf",
            1900 + info->tm_year, 1 + info->tm_mon, info->tm_mday,
            info->tm_hour, info->tm_min, info->tm_sec, money);
    printf("%s\n", Time[record]);
    ++record;
}
//银行系统
int main() {
    //判定是否进入
    char decide;
    //开发者模式中的编号
    char num1;
    //初始化金额
    double money = 0;
    //初始化取款金额
    double outmoney = 0;
    //显示金额
    double balance = 0;
    //定义一个数组存储每次输入的金额
    double arr[100];
    //实现数组伪自增
    int temp = 0;
    //银行利率
    double rate = 0.0225;
    //初始化年份
    int year = 0;
    //初始化利息
    double interest = 0;
    //存储未来的余额
    double abc = 0;
    //定义一个标记判断初始金额
    int NUM = -1;
    char username[1000] = " "; // 用于存储登录时的用户名
    char password[1000] = " "; // 用于存储登录时的密码
    char login_username[1000] = " "; // 用于存储注册时的用户名
    char login_password[1000] = " "; // 用于存储注册时的密码
    //定义数组长度
    int length = 0;
//用于存储当前时间
char Time[100][50];
    printf("516银行\n");
    printf("按任意键进入银行系统\n");
    //识别到输入回车进入程序

    while ((decide = getchar()) != ' \n') {
        while (1) {

            printf("--------------------\n");
            printf("注册：\n注册你的用户名\n");

            scanf("%s", login_username);
            pass:
            printf("注册你的密码(密码长度为6位)\n");
            scanf("%s", login_password);
            //记录输入数组长度
            length = strlen(login_password);
            if (length != 6) {
                //初始化存储临时密码的数组
                for (unsigned int i = 0; i < strlen(password); i++)
                    password[i] = '\0';
                //数组长度不为6重新输入密码
                goto pass;
            }

            // 使用scanf函数接收用户输入的字符串

            again:    //定义一个标记，用于退出登录
            while (1) {

                //登录
                printf("--------------------\n");
                printf("请登录：\n");
                printf("输入你的账号\n");
                scanf("%s", username);
                printf("输入你的密码\n");
                scanf("%s", password);
                //判断是否与注册时输入的相等
                if (strcmp(username, login_username) == 0 && strcmp(password, login_password) == 0) {
                    printf("登录成功！\n");
                    //初始化注册时的信息
                    for (unsigned int i = 0; i < strlen(username); i++)
                        username[i] = '\0';
                    for (unsigned int i = 0; i < strlen(password); i++)
                        password[i] = '\0';
                    break;
                }
                printf("\n账号或者密码输入错误，请重新输入\n");
            }
            //储存办理业务的编号
            int num = 0;

            while (1) {


                {
                    //银行的菜单
                    printf("--------------------\n");
                    printf("1.查看个人存取款记录\n");
                    printf("2.存款\n");
                    printf("3.取款\n");
                    printf("4.查看当前利率\n");
                    printf("5.查看若干年后的利息\n");
                    printf("6.修改账号\n");
                    printf("7.修改密码\n");
                    printf("8.退出登录\n");
                    printf("9.结束程序\n");
                    printf("--------------------\n");
                    printf("进入开发者模式\n");
                    printf("输入你想办理业务的编号\n");
                    //接收输入的编号

                    while (scanf(" %d", &num) != 1 || num != 516 && num >= 10)  //判断是否为合法数字
                    {
                        printf("请输入合法的数字:\n");
                        //清除缓存
                        while (getchar() != '\n');
                    }


                    //判断暗号是否正确
                    if (num == 516) {
                        while (num == 516) {
                            //存储利息变动
                            double add = 0;
                            //开发者菜单
                            printf("--------------------\n");
                            printf("\n成功进入开发者模式\n");
                            printf("a.增加银行利率\n");
                            printf("b.减少银行利率\n");
                            printf("c.查看当前利率\n");
                            printf("查看所有用户信息\n");
                            printf("d.退出开发者模式\n");
                            printf("--------------------\n");
                            printf("输入你想办理业务的编号\n");
                            //接收编号，这里是单独存储，与外面分隔开

                            scanf(" %c", &num1);
                            //传入用户输入的编号并进入循环
                            switch (num1) {
                                //增加利率
                                case 'a':
                                    printf("------------------------\n");
                                    printf("当前利率为%lf\n", rate);
                                    printf("输入你想增加多少\n");
                                    scanf("%lf", &add);
                                    rate = rate + add;
                                    printf("修改成功\n当前利息为%lf\n", rate);

                                    break;
                                    //减少利率
                                case 'b':
                                    printf("----------------------\n");
                                    printf("当前利率为%lf\n", rate);
                                    printf("输入你想减少多少\n");
                                    scanf("%lf", &add);
                                    rate = rate - add;
                                    printf("修改成功\n当前利息为%lf\n", rate);

                                    break;
                                    //查看利率
                                case 'c':
                                    printf("----------------------\n");
                                    printf("当前利息为%lf\n", rate);

                                    break;
                                    //退出
                                case 'd':
                                    printf("----------------------\n");
                                    printf("已安全退出\n");

                                    num = 0;
                                    break;
                                default:
                                    printf("----------------------\n");
                                    printf("\n你闲的没事乱输什么？\n");

                                    break;
                            }
                        }
                    }
                    //用户菜单
                    switch (num) {
                        //显示个人菜单
                        case 1:
                            if (NUM == -1) {
                                printf("----------------------\n");
                                printf("\n你的个人信息如下：\n");
                                printf("用户名%s：\n", login_username);
                                printf("密码%s\n", login_password);
                                printf("金额为：0\n");
                                break;
                            }
                            printf("----------------------\n");
                            printf("\n你的个人信息如下：\n");
                            printf("姓名%s\n", login_username);
                            printf("密码%s\n", login_password);
                            printf("金额为：%lf\n", money);
                            //输出存取款记录
                            printf("你的存取款记录为\n");
                            for (int i = 0; i < record; i++) {
                                printf("%s\n", Time[i]);
                            }


                            break;
                            //存入金额
                        case 2:
                            printf("----------------------\n");
                            printf("输入你想要存款的金额\n");
                            scanf("%lf", &money);
                            //把每次存款的金额记录下来，方便输出
                            arr[temp] = money;
                            //数组伪自增
                            balance += arr[temp];
                            temp++;
                            //判定显示个人信息自增，使其不为0
                            NUM++;

                            now(Time,money);
                            printf("你的余额为：%lf\n", balance);
                            break;
                        case 3:
                            //取款，并检测本金是否为0
                            while (1) {
                                //取款时，进行验证
                                while (1) {
                                    printf("本人验证，请输入密码\n");
                                    scanf("%s", password);
                                    if (strcmp(password, login_password) == 0) {
                                        printf("验证成功！\n");
                                        break;
                                    }
                                    printf("验证失败，请完成本人验证，否则无法进行后面业务\n");
                                    //初始化存储临时密码的数组
                                    for (unsigned int i = 0; i < strlen(password); i++)
                                        password[i] = '\0';

                                }
                                printf("----------------------\n");
                                printf("输入你的取款金额\n");
                                scanf("%lf", &outmoney);
                                if (outmoney <= balance) {
                                    balance -= outmoney;
                                    arr[temp] = outmoney * -1;
                                    now(Time,arr[temp]);
                                  printf("你的余额还剩%lf\n", balance);
                                    arr[temp] = outmoney * -1;
                                    //数组伪自增
                                    temp++;
                                    break;
                                } else {
                                    printf("----------------------\n");
                                    printf("取款失败，你的账户里没有这么多钱,或输入了非数字\n返回主菜单\n");

                                    break;
                                }
                            }
                            break;
                            //查看当前利率
                        case 4:
                            printf("----------------------\n");
                            printf("当前利率为：%lf\n", rate);

                            break;
                            //查看利率
                        case 5:
                            printf("----------------------\n");
                            printf("输入你想查看多少年以后的利息\n");
                            scanf("%d", &year);
                            if (money == 0) {
                                printf("你没有本金，无法计算未来的利息\n");

                                break;
                            }

                            interest = (double) year * rate;
                            abc = (double) year * rate + money;
                            printf("\n%d年以后你的利息为%lf，余额为%lf\n", year, interest, abc);

                            break;
                        case 6:
                            //修改用户名
                            while (1) {
                                printf("本人验证，请输入密码\n");
                                scanf("%s", password);

                                if (strcmp(password, login_password) == 0) {
                                    printf("验证成功！\n");
                                    break;
                                }
                                printf("验证失败，请完成本人验证，否则无法进行后面业务\n");
                                //初始化存储临时密码的数组
                                for (unsigned int i = 0; i < strlen(password); i++)
                                    password[i] = '\0';

                            }

                            printf("请输入你的新用户名\n");
                            scanf("%s", username);
                            printf("修改成功，你的用户名为：\n %s", username);
                            strcpy(login_username, username);
                            //初始化存储临时账户的数组
                            for (unsigned int i = 0; i < strlen(username); i++) {
                                password[i] = '\0';

                            }
                            break;
                        case 7:
                            //修改密码
                            while (1) {
                                printf("本人验证，请输入密码\n");
                                scanf("%s", password);
                                if (strcmp(password, login_password) == 0) {
                                    printf("验证成功！\n");
                                    break;
                                }
                                printf("验证失败，请完成本人验证，否则无法进行后面业务\n");
                            }
                            printf("请输入你的新密码\n");
                            scanf("%s", password);
                            printf("修改成功，你的密码为：\n %s", password);
                            strcpy(login_password, password);
                            //初始化存储临时密码的数组
                            for (unsigned int i = 0; i < strlen(password); i++) {
                                password[i] = '\0';

                            }
                            break;
                            //退出登录
                        case 8:
                            //跳转到登录页面
                            goto again;
                            break;
                        case 9 :
                            //结束进程
                            return 1;
                        default:
                            printf("----------------------\n");
                            printf("请输入1-9的数字\n");

                            break;
                    }
                }
            }
        }
    }
}