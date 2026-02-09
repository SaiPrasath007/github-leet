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