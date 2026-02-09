#include <stdio.h>
#include <stdlib.h>
long long* mergeAdjacent(int* nums, int numsize, int* returnsize)
{
    long long* ans = (long long*)malloc(numsize*sizeof(long long));
    int i,j=0;
    for(i=0;i<numsize;i++)
    {
        long long cv=(long long)nums[i];
        while(j>0 && ans[j-1]==cv)
        {
            cv= ans[j-1]+cv;
            j--;
        }
        ans[j]=cv;
        j++;
    }
    *returnsize=j;
    return ans;
}
int main() {
    int nums[] = {1, 2, 2, 4, 4};
    int n = 5;
    int returnSize;

    long long* result = mergeAdjacent(nums, n, &returnSize);

    printf("Final Result: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%lld%s", result[i], (i == returnSize - 1 ? "" : ", "));
    }
    printf("]\n");

    free(result);
    return 0;
}