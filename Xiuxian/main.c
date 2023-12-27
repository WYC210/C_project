/*
* 等待优化：
* 走路会自然回血
* 打怪会掉落物品
* 功法
 * 任务奖励
* */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define row 15
#define low 15
// 初始化开始页面选择
int dec = 0;
//定义背包物品存放到第几位
int obj = 0;
//定义功法袋里功法存放到第几位
int SpellBook = 0;
//定义应该输出哪种地图
int MAP = 0;
//定义遇到的怪物等级BOSS还是小怪
int event = 0;
// 定义一个用于确定境界的数值
int n = 0;
//判断是否接到任务
int task = 0;
//定义任务中击杀数
int kill = 0;
//记录开始选择天赋奖励
int decide = 0;
// 生命
double healthy = 100; // 初始生命值
int attack = 10; // 初始攻击力
// 防御
int defense = 5; // 初始防御力
// 法力
int mana = 30; // 初始法力
// 灵力
double lingli = 0; // 初始灵力
// 背包
int backpack[15];  // 初始背包
// 功法
int spell[10];
// 玩家结构体
typedef struct {
    int x; // 玩家横坐标
    int y; // 玩家纵坐标
} Player;
//定义姓名
char name_my[10];


//清理输入缓存缓存
void clearPoint() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 界面
int menu(int arr_dec[10], int *ddd, char sex[]) {
    while (1) {
        printf("\t文字修仙\n");
        printf("\t1.开始游戏\n");
        printf("\t2.退出游戏\n");
        printf("输入数字进入对应模式\n");
        scanf("%d", &dec);
        if (dec == 1) {
            play:
            clearPoint();
            printf("输入你的姓名\n");
            fgets(name_my, sizeof(name_my), stdin);

            printf("选择你的性别\n");
            printf("1.男\n");  // 血厚
            printf("2.女\n");  // 法多
            printf("3.不愿意透露性别的神秘人\n");  // 防御高
            int condition = 0; // 用于判断输入是否合法
            //判断输入是否符合条件
            while (!condition) {
                scanf("%d", &decide);

                // 清理缓存
                clearPoint();

                if (decide == 1 || decide == 2 || decide == 3) {
                    condition = 1; // 输入合法，跳出循环
                } else {
                    printf("输入无效\n ");
                }
            }
            // 数组来记录选择了什么
            arr_dec[*ddd] = decide;
            ++(*ddd);
            if (decide == 1) {
                strcpy(sex, "男");
            } else if (decide == 2) {
                strcpy(sex, "女");
            } else if (decide == 3) {
                strcpy(sex, "不愿透露");
            }
            printf("选择你的身世\n");
            printf("你的父亲是...\n");
            printf("1.自由的平民\n");  // 血厚
            printf("2.门派中的一名长老\n");  // 法多
            printf("3.你是个孤儿\n");  // 防高
            condition = 0; // 用于判断输入是否合法
            //判断输入是否符合条件
            while (!condition) {
                scanf("%d", &decide);

                // 清理缓存
                clearPoint();

                if (decide == 1 || decide == 2 || decide == 3) {
                    condition = 1; // 输入合法，跳出循环
                } else {
                    printf("输入无效\n ");
                }
            }
            // 数组来记录选择了什么
            arr_dec[*ddd] = decide;
            ++(*ddd);
            printf("选择你的身世\n");
            printf("你年少时...\n");
            printf("1.摆烂躺平\n");  // 血厚
            printf("2.老实本分的修行\n");  // 法多
            printf("3.经常被人欺负\n");  // 防高
            condition = 0; // 用于判断输入是否合法
            //判断输入是否符合条件
            while (!condition) {
                scanf("%d", &decide);

                // 清理缓存
                clearPoint();

                if (decide == 1 || decide == 2 || decide == 3) {
                    condition = 1; // 输入合法，跳出循环
                } else {
                    printf("输入无效\n ");
                }
            }
            // 数组来记录选择了什么
            arr_dec[*ddd] = decide;

            // 根据选择的身世加相应的属性
            //增加限制条件，只有选完身世才加，并根据特性写一个每走一个回一滴血

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
            // 退出游戏
            return 1;
        } else {
            printf("输入了非法数字\n");
            clearPoint();
        }
    }
}

//功法
void Spell() {
    //1001——1099属于一阶被动攻击功法
    //1101-1199属于二阶主动攻击功法...
    //2001-2099属于一阶被动防御功法
    //2101-2199属于二阶主动防御功法...
    //3001-3099属于一阶药品
    //3101-3199属于二阶药品...
    //4001-4199属于各种攻击物品
    //5001-5199属于各种防御物品
    //查找功法，有那种对应的编号就输出哪种
    for (int p = 0; p < 10; ++p) {
        if (spell[p] == 1001) {
            printf("|[一阶]冬至天寒| ");
        }
        if (spell[p] == 1002) {
            printf("|[一阶]追寒锁骨| ");
        }
        if (spell[p] == 1003) {
            printf("|[一阶]寒骨折梅| ");
        }
        if (spell[p] == 2001) {
            printf("|[一阶]盾灵术| ");
        }
        if (spell[p] == 2002) {
            printf("|[一阶]吐纳功| ");
        }
        if (spell[p] == 3001) {
            printf("|[一阶]凝血丸| ");
        }
    }
    printf("\n");
}

//背包物品
void Goods() {
    for (int p = 0; p < 10; ++p) {
        if (backpack[p] == 4001) {
            printf("|[一阶]木弓| ");
        }
        if (backpack[p] == 5001) {
            printf("|[一阶]木盾| ");
        }
    }
    printf("\n");
}

// 根据身世增加属性
void showMy(char boundary[], char sects[], char sex[]) {
    for (int j = 0; j < 10; ++j) {
        //判断所有带攻击的法术增加属性
        //对应编号查看126行
        if (spell[j] > 1000 && spell[j] < 2000) {//对应攻击功法
            attack *= 2;
        }
        if (spell[j] > 2000 && spell[j] < 3000) {//对应防御功法
            defense *= 2;
        }
        if (backpack[j] == 4001) {//对应木弓
            attack += 30;
        }
        if (backpack[j] == 5001) {//对应木盾
            defense += 30;
        }
    }
    fputs(name_my, stdout);//输出姓名
    //展示自己的属性
    printf("\n生命：%lf\n 攻击：%d\n 防御：%d\n 灵力：%lf\n 法力：%d\n", healthy, attack, defense,
           lingli, mana);
    printf("性别：%s\n门派：%s\n境界：%s\n功法：\n", sex, sects, boundary);
    //输出功法
    Spell();
    //动态变换背包里的物品
    printf("背包里的物品：\n ");
    Goods();

}

// 控制境界
int Boundary(char boundary[]) {

    srand(time(NULL));  // 设置随机
//伪随机一个突破的概率。
    if (lingli >= 100 + 100 * n) {
        ++n;
        //生成一个随机数来判断是否突破成功
        int num1 = rand() % 100;
        printf("概率为%d", num1);
        char try;
        printf("是否进行突破？\nY/N\n");
        scanf(" %c", &try);
        if (try == 'N' || try == 'n') {
            n--;
            return n;
        }
        switch (n) {
            case 1:

                if (num1 > 40) {
                    strcpy(boundary, "|炼气|\n");
                    printf("突破成功\n");
                    healthy *= 10;
                    defense *= 10;
                    attack *= 10;
                    mana *= 10;
                    lingli = 0;
                    break;
                } else {
                    printf("\n*******突破失败*******\n");
                    printf("\n****丹田受损，灵力消散****\n");
                    n--;
                    lingli = 0;
                }
                break;
            case 2:
                if (num1 > 50) {
                    strcpy(boundary, "|筑基|\n");
                    healthy *= 10;
                    defense *= 10;
                    attack *= 10;
                    mana *= 10;
                    lingli = 0;
                    break;
                } else {
                    printf("\n*******突破失败*******\n");
                    printf("\n****丹田受损，灵力消散****\n");
                    lingli = 0;
                    n--;
                }
                break;
            case 3:
                if (num1 > 70) {
                    strcpy(boundary, "|结丹|\n");
                    healthy *= 10;
                    defense *= 10;
                    attack *= 10;
                    mana *= 10;
                    lingli = 0;
                    break;
                } else {
                    printf("\n*******突破失败*******\n");
                    printf("\n****丹田受损，灵力消散****\n");
                    lingli = 0;
                    n--;
                }
                break;
            case 4:
                if (num1 > 80) {
                    strcpy(boundary, "|元婴|\n");
                    healthy *= 10;
                    defense *= 10;
                    attack *= 10;
                    mana *= 10;
                    lingli = 0;
                    break;
                } else {
                    printf("\n*******突破失败*******\n");
                    printf("\n****丹田受损，灵力消散****\n");
                    lingli = 0;
                    n--;
                }
                break;
            case 5:
                if (num1 > 90) {
                    strcpy(boundary, "|化神|\n");
                    healthy *= 10;
                    defense *= 10;
                    attack *= 10;
                    mana *= 10;
                    lingli = 0;
                    break;
                } else {
                    printf("\n*******突破失败*******\n");
                    printf("\n****丹田受损，灵力消散****\n");
                    lingli = 0;
                    n--;
                }
                break;
        }
    }
    return n;  // 返回更新后的境界值
}

// 初始化地图
void Map(char arr[row][row], Player player) {

    // 初始化地图
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (i == 0 || i == row - 1 || j == 0 || j == row - 1) {
                arr[i][j] = '#';  // 生成墙
            } else {
                arr[i][j] = '_';  // 其他区域为空地
            }
        }
    }

    // 添加玩家
    arr[player.x][player.y] = 'I';
}

//打印地图
void printMap(char arr[row][row], char name[], int num, int num1, Player player) {
    // 显示地图
    char person[10][10] = {"村", "猎", "守", "盗", "穴", "灵", "我"};

    //没有加限制条件以后再说，防止随机生成到地图外
/*
    arr[num - 2][num + 2] = 'L';    // 猎人
    arr[num - 1][num - 1] = 'S';    // 守卫
    arr[num1][num1] = '!';    // 强盗
    arr[num1 + 1][num1 + 1] = '!';
    arr[num1 + 1][num1 - 1] = '!';
    arr[num1 + 1][num1] = '@';//巢穴
    // 随机添加灵气
    arr[num][num] = 'Q';
    // 添加玩家
    arr[player.x][player.y] = 'I';
*/

    printf("\n==============\n %c\n", name);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (i == (num + 1) && j == (num + 3)) {
                printf(" !");
                fputs(person[0], stdout);    // 村长
                printf("  ");
                continue;
            }
            if (i == (num - 2) && j == (num + 2)) {
                printf(" !");
                fputs(person[1], stdout);    // 猎人
                printf("  ");
                continue;
            }
            if (i == (num - 1) && j == (num - 1)) {
                printf(" !");
                fputs(person[2], stdout);    // 守卫
                printf("  ");
                continue;
            }
            if (i == (num1) && j == (num1) || i == (num1 + 1) && j == (num1 + 1) ||
                i == (num1 + 1) && j == (num1 - 1)) {
                printf(" !");
                fputs(person[3], stdout);    // 强盗
                printf("  ");
                continue;
            }
            if (i == (num1 + 1) && j == (num1)) {
                printf(" !");
                fputs(person[4], stdout);    // 巢穴
                printf("  ");
                continue;
            }
            if (i == (num) && j == (num)) {
                printf(" !");
                fputs(person[5], stdout);    // 灵气
                printf("  ");
                continue;
            }
            if (i == (player.x) && j == (player.y)) {
                printf(" .");
                fputs(person[6], stdout);    // 玩家
                printf("  ");
                continue;
            }
            printf("  %c ", arr[i][j]);
            printf("  ");
        }
        printf("\n");
    }
}


//怪物巢穴地图初始化
void Map_lair(char lair[low][low], Player player, int num3) {

    for (int i = 0; i < low; ++i) {
        for (int j = 0; j < low; ++j) {
            if (i == 0 || i == low - 1 || j == 0 || j == low - 1) {
                lair[i][j] = '#';  // 生成墙
            } else {
                lair[i][j] = '-';  // 其他区域为空地
            }
        }
    }

    lair[num3 + 1][num3] = '&';//第一个BOSS
    lair[num3][num3 - 1] = '&';//第二个BOSS
    lair[num3][num3 + 1] = '&';//第三个BOSS
    lair[num3][num3] = '@';//出巢穴的出口
    //定义巢穴后的墙
    lair[num3 - 2][num3] = '#';
    lair[num3 - 1][num3 - 1] = '#';
    lair[num3 - 1][num3 + 1] = '#';
    // 添加玩家
    lair[player.x][player.y] = 'I';


}

//打印怪物巢穴的地图
void printlair(char lair[low][low], Player player, int num3) {
    char monster[10][10] = {"猪", "妖", "人","我"};
    //定义巢穴地图
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

//重置玩家位置缓存
void reset(Player *player) {
    player->x = 1;
    player->y = 1;
}

// 控制玩家移动
int Move(char arr[row][row], char move, Player *player, char lair[low][low]) {

    // 保存原始位置
    int X = player->x;
    int Y = player->y;

    // 移动逻辑
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
        // 边界检查，防止越界
        if (player->x < 0 || player->x >= row || player->y < 0 || player->y >= row ||
            arr[player->x][player->y] == '#') {
            // 恢复原始位置
            player->x = X;
            player->y = Y;
            return 0; // 未成功移动
        }
        return 1; // 成功移动
    }

    if (MAP == 21) {
        // 边界检查，防止越界
        if (player->x < 0 || player->x >= low || player->y < 0 || player->y >= low ||
            lair[player->x][player->y] == '#') {
            // 恢复原始位置
            player->x = X;
            player->y = Y;
            return 0; // 未成功移动
        }
        return 1; // 成功移动
    }

    return 0; // 默认情况，未成功移动
}

// 触发事件
/*
 *在相应的地图增加怪物图标
 */
int Event(Player *player, int num, int num1, char boundary[], int num3) {
    //1-10是NPC事件
    //11-20是战斗事件
    //21-30是进入新地图
    //判断两个地图到底是哪个

    if (MAP == 0) {

        if (player->x == num + 1 && player->y == num + 3) {
            printf("\n你遇到了村长\n");
            printf("村长:少侠前方林中有土匪出没可以帮我们清理一下吗。\n作为回报我送于你5颗凝血丸\n");
            //激活任务
            task = 1;
            for (int h = 0; h < 5; ++h) {//5颗凝血丸
                backpack[obj] = 3001;
                //背包中的第几位
                ++obj;
            }
        }
        if (player->x == num - 2 && player->y == num + 2) {
            printf("\n你遇到了猎人\n");
            printf("猎人：受伤的猎户:少侠我把弓借你，希望你可以帮我处理掉土匪。\n");
            backpack[obj] = 4001;//一把木弓
            ++obj;
        }
        if (player->x == num - 1 && player->y == num - 1) {
            printf("\n你遇到了守卫\n");
            printf("守卫：少年！我这有块祖传盾牌，可护你周全 \n");
            backpack[obj] = 5001;
            ++obj;
        }
        if (player->x == num1 && player->y == num1 || player->x == num1 + 1 && player->y == num1 + 1 ||
            player->x == num1 + 1 && player->y == num1 - 1) {
            printf("\n你遇到了土匪\n战斗开始！\n");
            printf("丁傲天：让我看看这么个事\n");
            event = 2;
            return event;
        }
        if (player->x == num1 + 1 && player->y == num1) {
            printf("\n****你遇到了土匪巢穴****\n");
            MAP = 21;
            return MAP;
        }
        if (player->x == num && player->y == num) {
            printf("\n你吸收大量灵气，灵气值有所上升\n");
            printf("丁傲天：真不错\n");
            lingli += 100;
            printf("灵气值：%lf\n", lingli);

            // 升级境界并更新境界
            n = Boundary(boundary);
            // 输出当前境界等级
            printf("当前境界等级：%d\n", n);
            return n;
        }
    }
    if (MAP == 21) {
        if (player->x == num3 && player->y == num3) {
            printf("\n****你进入了新手村****\n");
            MAP = 0;
            return MAP;
        }
        if (player->x == num3 && player->y == num3 - 1) {
            printf("\n你遇到了|[练气]上申妖人|\n战斗开始！\n");
            printf("丁傲天：让我看看这么个事\n");
            event = 3;
            kill++;
            return event;

        }
        if (player->x == num3 && player->y == num3 + 1) {
            printf("\n你遇到了|[练气]鼓岭山贼王|\n战斗开始！\n");
            printf("丁傲天：让我看看这么个事\n");
            event = 4;
            kill++;
            return event;
        }
        if (player->x == num3 + 1 && player->y == num3) {
            printf("\n你遇到了|[练气]野猪王|\n战斗开始！\n");
            printf("丁傲天：让我看看这么个事\n");
            event = 5;
            kill++;
            return event;
        }

    }
    return 0;
}

//战斗系统
/*
 *然后在这里添加怪物具体数值
 */
void Wars(int war) {
    int num1 = rand() % 20 + 30;//小怪的数值30-50
    int num2 = rand() % 100 + 50;//boss数值500-120
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
        printf("回合 %d\n", round);
        printf("你的血量：%lf\n", healthy);
        printf("土匪血量：%d\n", healthy_t);

        // 玩家回合
        printf("你的回合\n");
        printf("1.攻击\n");
        printf("2.防御\n");
        printf("3.法术\n");
        printf("4.药品\n");
        printf("输入序号\n");
        scanf("%d", &war);

        switch (war) {
            case 1:
                printf("你以迅雷不及掩耳盗铃之式给他来了一下\n");
                healthy_t -= (attack - defense_t * 2);
                break;
            case 2:
                printf("你把头塞到裤裆里防御，防止他爆头\n");
                healthy -= (attack_t - defense * 2);
                break;
            case 3:
                for (int g = 0; g < 10; ++g) {
                    if (spell[g] != 1001 && spell[g] != 1002 && spell[g] != 1003) {
                        printf("\n你会个锤子法术\n");
                        return;
                    }
                }
                printf("你双手快速结印，嘴里默念法术\n");
                for (int i = 0; i < 15; ++i) {
                    if (spell[i] == 1001) {
                        printf("|[一阶]冬至天寒| ");
                    }
                    if (spell[i] == 1002) {
                        printf("|[一阶]追寒锁骨| ");
                    }
                    if (spell[i] == 1003) {
                        printf("|[一阶]寒骨折梅| ");
                    }
                    healthy_t -= (attack * 2);
                }
                break;

            case 4:
                for (int h = 0; h < 10; ++h) {
                    if (backpack[h] == 3001) {
                        printf("你吃了一口药，HP++\n");
                        healthy += 15;
                        backpack[h] = 0;
                        break;
                    }
                }
                break;
            default:
                printf("无效的选择\n");
        }

        // 检查战斗是否结束
        if (healthy <= 0) {
            printf("你体力不支挂掉了，全剧终。\n");
            break;
        }
        if (healthy_t <= 0) {
            printf("土匪在你的攻击下一命呜呼\n");
            printf("你似乎在刚才的战斗中有所|感悟|\n");
            break;
        }

        // 土匪回合
        printf("对手回合\n");
        healthy -= (attack_t - defense * 0.3);

        // 检查战斗是否结束
        if (healthy <= 0) {
            printf("你体力不支挂掉了，全剧终。\n");
            break;
        }
        if (healthy_t <= 0) {
            printf("土匪在你的攻击下一命呜呼\n");
            printf("你似乎在刚才的战斗中有所|感悟|\n");
            break;
        }

        round++;
    }
    event = 0;
}

//任务系统
void Task() {
    if (task == 1) {
        printf("\n目前任务：杀死巢穴中三只大妖（%d/3）\n", kill);
        if (kill == 3) {
            printf("\n任务完成！\n奖励：\n");
            srand(time(NULL));
            int reward = rand() % 3 + 1001;
            //当完成任务随机获得三本功法进行奖励
            switch (reward) {
                case 1001:
                    printf("|[一阶]冬至天寒| ");
                    spell[SpellBook] = 1001;
                    ++SpellBook;
                    break;
                case 1002:
                    printf("|[一阶]追寒锁骨| ");
                    spell[SpellBook] = 1002;
                    ++SpellBook;
                    break;
                case 1003:
                    printf("|[一阶]寒骨折梅| ");
                    spell[SpellBook] = 1003;
                    ++SpellBook;
                    break;
            }
            task = 0;
        }
    }
}

int main() {

    // 初始化战斗时的选择
    int war = 0;
    // 定义存储选择的数字
    int arr_dec[10];
    // 定义性别
    char sex[10];
    // 定义地图
    char arr[row][row];
    //定义怪物巢穴
    char lair[low][low];
    // 定义地图第一次重置玩家位置
    int ddd = 0;
    // 名字
    char name[] = "丁傲天";
    // 境界
    char boundary[] = "|凡人|";
    // 门派
    char sects[] = "无";
    // 定义接收上下移动
    char move;
    // 定义玩家
    Player player = {1, 1}; // 初始化玩家位置
    srand(time(NULL));  // 设置随机
    // 生成0到8之间的随机整数
    int num = rand() % 5 + 3;  // 生成3-7之间的随机数
    srand(time(NULL));  // 设置随机
    // 生成0到10之间的整数
    int num1 = rand() % 3 + 8;  // 生成8-10之间的随机数
    srand(time(NULL));  // 设置随机
    //生成0-9的随机数
    int num3 = rand() % 10;
    if (menu(arr_dec, &ddd, sex) == 1) {
        return 1;
    }

    //初始化地图
    Map(arr, player);
    Map_lair(lair, player, num3);

    Play:
    reset(&player);
    while (1) {
        //在新手村移动
        while (1) {
            if (MAP == 0) {
                //显示当前任务
                Task();
                // 显示地图
                printMap(arr, name, num, num1, player);
                printf("按I查看个人属性\n输入WSAD来上下移动\n");
                scanf(" %c", &move);
                //判断移动时选择了什么
                if (move == 'i' || move == 'I') {
                    // 显示个人的属性
                    showMy(boundary, sects, sex);
                }
                // 触发随机事件
                if (Event(&player, num, num1, boundary, num3)) {
                    // 升级境界并更新境界
                    n = Boundary(boundary);
                    //战斗机制
                    Wars(war);
                    if(healthy <= 0){
                        printf("游戏结束");
                        return 0;
                    }
                }

                if (Move(arr, move, &player, lair)) {
                    // 成功移动后更新地图
                    Map(arr, player);
                }

                if (MAP != 0) {
                    break;
                }
            }
        }
        //每次进入新地图重置位置缓存
        reset(&player);
        //在巢穴地图中移动
        while (1) {
            if (MAP == 21) {
                //显示当前任务
                Task();
                //显示巢穴地图
                printlair(lair,player,num3);
                printf("按I查看个人属性\n输入WSAD来上下移动\n");
                scanf(" %c", &move);
                //判断移动时选择了什么
                if (move == 'i' || move == 'I') {
                    // 显示个人的属性
                    showMy(boundary, sects, sex);
                }
                // 触发随机事件
                if (Event(&player, num, num1, boundary, num3)) {
                    //战斗机制
                    Wars(war);
                    if(healthy <= 0){
                        printf("游戏结束");
                        return 0;
                    }
                }

                if (Move(arr, move, &player, lair)) {
                    // 成功移动后更新地图
                    Map_lair(lair, player, num3);

                }

                if (MAP != 21) {
                    break;
                }
            }
        }
        //每次进入新地图重置位置缓存
        reset(&player);
    }

}




