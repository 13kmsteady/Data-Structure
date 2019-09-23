
/**
 * =========================================================
 *
 * 行走编辑程序
 *
 * =========================================================
 */

typedef char SElemType;

#include "../../ch1/C1.h"
#include "../sequence_stack/C3-1.h"
#include "../sequence_stack/Bo3-1.c"

FILE *fp;

void print(SElemType e) {
    printf("%c", e);
}

/**
 * 将字符 c 发送至 fp 所指的文件中
 * @param c
 */
void copy(SElemType c) {
    fputc(c, fp);
}

/**
 * 利用字符栈 s, 从终端接受一行,并送至调用过程的数据区
 */
void LineEdit() {

    SqStack s;
    char ch;
    InitStack(&s);
    printf("请输入一个文本文件, N 结束输入\n");

    ch = getchar();

    while (ch != 'N') { // 当全文没有结束(EOF 为 ^Z 键,全文结束符)

        while (ch != 'N' && ch != '\n') { // 当全文没有结束,且没到行末(不是换行符)

            switch (ch) {
                case '#':
                    if (!StackEmpty(s)) {
                        Pop(&s, &ch);
                    }
                    break;
                case '@':
                    ClearStack(&s);
                    break;
                default:
                    Push(&s, ch);
                    break;
            }

            ch = getchar(); // 从终端接收下一个字符
        }

        StackTraverse(s, copy); // 将从栈底到栈顶的栈内字符传送至文件
        StackTraverse(s, print);
        fputc('\n', fp); // 向文件输入一个换行符
        ClearStack(&s); // 将 s 置为空栈

        if (ch != EOF) {
            ch = getchar();
        }
    }
    DestroyStack(&s);
}

int main() {

    fp = fopen("ed.txt", "w"); // 在当前目录下建立 ed.txt 文件,用于写数据

    if (fp) {
        LineEdit();
        fclose(fp); // 关闭 fp 所指的文件
    } else {
        printf("建立文件失败\n");
    }
    return 0;
}







