// To find the a^b using binary exponentation
int bpow(int a,int b)
{
    int res=1;
    while(b>0)
    {
        if(b%2)
        {
            res*=a;
        }
        b=b/2;
        a=a*a;
    }
    return res;
}
