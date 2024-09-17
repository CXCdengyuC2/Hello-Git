#include <stdio.h>        //用于输入输出操作
#include <stdlib.h>       //包含一些常用函数，如rand和srand
#include <time.h>         //用于获取系统时间来设置随机种子数
int rollDice() {          //定义一个函数rollDice
    return rand() % 6 + 1;//rand() 函数会返回一个随机的整数。% 6 是取模运算，得到的结果是 rand() 返回值除以 6 的余数，这个余数的范围是 0 到 5 。然后+1 使得结果的范围变成 1 到 6 
}                         //生成一到六间随机数

int main() {
    unsigned int seed;    //定义一个无符号整数seed用于接收用户输入的随机数
    printf("请输入一个无符号整数作为随机数种子");
    scanf("%u",&seed);    //读取用户输入并存储到seed中
    srand(seed);          //设置随机数生成器的种子

    int point = 0;        //定义整数变量 point 用于记录玩家的点数（如果第一轮不是 7、11、2、3、12 的和值）
    int sum;              //定义整数变量 sum 用于记录每次掷两个骰子的和值。

    sum = rollDice() + rollDice();//调用 rollDice 函数两次，并将结果相加，得到第一轮掷骰子的和值
    
    if (sum == 7 || sum == 11){
        printf("恭喜，你赢了！\n");
        return 0;
    }else if (sum == 2 || sum ==3 || sum ==12) { 
        printf("很遗憾，你输了！\n");
        return 0;
    }else {
        point = sum;
        printf("你的点数是: d%\n",point);
    }

    while (1) {           //"1"代表永远为真的条件  创造一个无限循环
        sum = rollDice() + rollDice();

        if (sum == point) {
            printf("恭喜，你赢了！\n");
            break;
        } else if (sum == 7) {
            printf("很遗憾，你输了！\n");
            break;
        }
    }

    return 0;
}
