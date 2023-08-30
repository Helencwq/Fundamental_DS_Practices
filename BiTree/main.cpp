#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "tree_traverse.h"
#include "queue.h"
#include "helper.h"

int main() {
    int *str = NULL;
    int len = 0;

    printf("Please Input Array Length:\n");
    scanf("%d", &len);

    if(len < 0){
        printf("ERROR: Invalid array length!\n");
        return 0;
    }else if(len == 0){
        printf("WARNING: Empty array! Input will not be taken.\n");
    }else{
        str = (int*) calloc(len, sizeof (int));

        printf("Please Input int Array:\n");
        for(int i = 0; i < len; i++){
            scanf("%d", &str[i]);
        }
    }


//    int string_res = is_valid_bst_str(str,len);
//    printf("%d\n",string_res);

//    len = 5;
//    int testStr[5] = {1,2,3,4,5};

    BiTree root = CreateBiTreeLevelOrder(str,len);
    printf("\nPre\n");
    RecursivePreOrderTraverse(root);
    printf("\nLevel\n");
    LevelOrderTraverse(root);
    printf("\nInorder\n");
    RecursiveInOrderTraverse(root);
    printf("\nPostOrder\n");
    RecursivePostOrderTraverse(root);
    printf("\n");

    if(InsertBiTreeLevelOrder(root, 9)){
        printf("\nPre\n");
        RecursivePreOrderTraverse(root);
        printf("\nLevel\n");
        LevelOrderTraverse(root);
        printf("\nInorder\n");
        RecursiveInOrderTraverse(root);
        printf("\nPostOrder\n");
        RecursivePostOrderTraverse(root);
    }
    return 0;
}
