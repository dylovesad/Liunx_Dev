ARM Cortex-M3 指令格式如下所⽰：
其中，<>内的项是必需的，{ }分内的项是可选的。
opcode: 指令助记符(必需)，如 MOV、LDR 等，对应于指令操作码，⽤来告诉ARM汇编器这条指令的功能。它的前⾯必须有⾄少⼀个空格
符，实际编程中通常使⽤⼀两个Tab键隔开。
cond：condition 的缩写，表⽰指令的执⾏条件(可选，如果没有，表⽰⽆条件执⾏)常⽤的指令执⾏条件如图所⽰。
int main()
{
printf("hello world!!\n");
return 0;
}
// 生成汇编后为：
main:
bl printf // 调用子程序 ， 把pc 的值赋值给lr
mov pc,lr // 从子程序中返回
<opcode>{<cond>}{s} <Rd> , <Rn> {,<operand2>}


EQ Z=1 相等，Equal
NE Z=0 不相等,Not Equal
MI N=1 负数,Minus
PL N=0 正数或零,Plus
VS V=1 溢出
VC V=0 没有溢出
CS C=1 ⽆符号数⼤于或等于
CC C=0 ⽆符号数⼩于
HI C=1，Z=0 ⽆符号数⼤于
LS C=0，Z=1 ⽆符号数⼩于或等于
GE N =V 有符号数⼤于或等于，Greater and Equal
LT N !=V 有符号数⼩于，Less Than
GT N=V，Z=0 有符号数⼤于,Greater Than
LE N!=V，Z=1 有符号数⼩于或等于，Less and Equal
AL 任何 ⽆条件执⾏(默认情况)，ALL

#IF
ADD R0,R1,R2 # R0 = R1 + R2
SUB R0,R1,R2 # R0 = R1 - R2
MOV R0,R1 # R0 = R1
LDR R0,[R1] # R0 = *R1 load register
STR R0,[R1] # *R1 = R0 store register

