/**
 * 带头结点的线性链表类型
 *
 */
typedef struct LNode { // 结点类型
    ElemType data;
    struct LNode *next;
} *Link, *Position;

typedef struct { // 链表类型
    Link head, tail; // 分别指向线性链表中的头结点和 最后一个结点
    int len; // 线性链表中数据元素的个数
} LinkList;