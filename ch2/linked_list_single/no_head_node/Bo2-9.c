/**
 * =========================================================
 *
 * 不带头结点的单链表(存储结构由 C2-2.h 定义),求前驱和后驱算法
 *
 * =========================================================
 */
/**
* 初始条件: 线性表 L 已存在
* 操作结果: 若 cur_e 是 L 的数据元素,且不是第一个,则用 pre_e 返回它的前驱,返回 OK.
*          否则操作失败,pre_e 无定义,返回 INFEASIBLE
*
* @param L
* @param cure_e
* @param pre_e
* @return
*/
Status PriorElem(LinkList L, ElemType cure_e, ElemType *pre_e) {

    LinkList q,p = L;
    while(p->next){
        q = p->next;
        if(q->data == cure_e){
            *pre_e = p->data;
            return OK;
        }
        p = q;
    }

    return INFEASIBLE;
}

/**
 * 初始条件: 线性表 L 已存在
 * 操作结果: 若 cur_e 是 L 的数据元素,且不是最后一个,则用 next_e 返回它的后驱,返回 OK.
 *          否则操作失败,next_e 无定义,返回 INFEASIBLE
 *
 * @param L
 * @param cure_e
 * @param pre_e
 * @return
 */
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e) {
    LinkList p = L;
    while (p->next){
        if(p->data == cur_e){
            *next_e = p->next->data;
            return OK;
        }
        p=p->next;
    }
    return INFEASIBLE;
}

