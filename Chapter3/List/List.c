/*
    由于课本上用了c++的参数传递方法,在c中使用如下方法替换:
        c++: function( SqList &L ){}
        c : typedef struct SqList *PointerToSqList
         function( PointerToSqList p ){} 
         调用: 
            SqList L;
            PointerToSqList p = &L;
            function( p );   
*/

#define LIST_INIT_SIZE 100
#define LISTINCREMENT p->listsize + p->length - p->listsize + 1
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
typedef struct SqList *PointerToSqList;
typedef int ElemType;
typedef int Status;

//初始化
// SqList L;
// PointerToSqList p = &L;
// InitList_Sq( p );
// 等价于: p->elem = new ElemType[LIST_INIT_SIZE];
Status InitList_Sq( PointerToSqList p )
{
    p->elem = ( ElemType * )malloc( LIST_INIT_SIZE *
                                 sizeof( ElemType ) );
    if( !p->elem )
        exit( OVERFLOW );
    p->length = 0;
    p->listsize = LIST_INIT_SIZE;
    return OK;
}

//插入
Status ListInsert_Sq( PointerToSqList p, int i, ElemType e )
{
    ElemType *m, *n;
    if( (i < 1) || ( i > p->length + 1 ) )
        return ERROR;
    If( p->length >= p->listsize ){
        //越界处理
        ElemType *newbase;
        newbase = (ElemType *)realloc( p->elem ,
                (p->listsize + LISTINCREMENT)*sizeof(ElemType) );
        if( !newbase ) exit(OVERFLOW);
        p->elem = newbase;
        p->listsize += LISTINCREMENT;
    }
    m = &( p-> elem[i-1]);//在第i个位置插入
    for( n = &(p->elem[p->length - 1]); n >= m; --n) )
        *( n + 1 ) = *m;
    *m = e;
    ++p->length;
    return OK;
}

//删除
Status ListDelete_Sq( PointerToSqList p, int i, ElemType *pointerToDeletedElem )
{
    ElemType *m, *n;
    if( ( i < 1) || ( i > p->length ) )
        return ERROR;
    m = &(p->elem[i-1]);
    *pointerToDeletedElem = *m;
    n = p->elem + p->length - 1;
    for( ++m; m <= n; ++m)
        *( m - 1 ) = *m;
    --p->length;
    return OK;
}