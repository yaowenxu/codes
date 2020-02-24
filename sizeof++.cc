/**
 * Author: Yaowen Xu
 * Github: https://github.com/yaowenxu
 * Organization: 北航系统结构研究所
 * Date: 2020-02-24 11:54:22
 * LastEditTime: 2020-02-24 11:54:37
 * Description: 文件描述信息
 */

#include <stdio.h>

int main(void)
{
   int i = 3;
   int j;

   j = sizeof(++i + ++i);

   printf("i=%d j=%d\n", i, j);

   return 0;
}