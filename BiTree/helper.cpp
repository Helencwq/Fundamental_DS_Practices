#include "tree.h"
#include "helper.h"

int is_valid_bst_str(ElemType str[], int len){
    //0 =: invalid
    //1 =: valid
    if(len < 0)
        return 0;

    //check duplicate
    //TODO: 利用先排序再查重是否可以优化时间复杂度
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(str[i] == str[j])
                return 0;
        }
    }

    return 1;
}
