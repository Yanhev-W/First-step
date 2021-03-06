#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 40

int main(int argc, char* argv[])
{
    FILE *in, *out;
    int ch;
    char name[LEN];     //存储文件名
    int count = 0;      //用来读取计数
    char *find;
    //检查命令行
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    //设置输入
    if((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "I could't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    //设置输出
    strncpy(name, argv[1], LEN-5);
    name[LEN-5] = '\0';
    find = strchr(name, '.');
    if(*find)
        *find = 0;
    strcat(name, ".red");
    if((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't crate output file.\n");
        exit(3);
    }
    //拷贝数据
    while((ch = getc(in)) != EOF)
    {
        if(count++ %3 == 0)
            putc(ch, out);
     }
        //收尾工作
    if(fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;

}
