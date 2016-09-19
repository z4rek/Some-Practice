#include <iostream>
#include <string>

using namespace std;

//zou_模式匹配算法
int SimpleAlgor(string st1, string st2)
{
    cout<<"Start Algor..."<<endl;
    int flag = 0;
    int equaFlag = 0;
    if(st2.size() > st1.size())
    {
        cout<<"st2 is too long\n";
        return -1;
    }
    int movePos = st1.size() - st2.size() + 1;
    int strLen = st2.size();
    for(flag=0; flag<movePos; flag++)
    {
        int i = flag;
        equaFlag = 0;
        for(int j=0; j<strLen; j++)
        {
            if(st1[i] == st2[j])
            {
                equaFlag++;
                i++;
            }
            else
                break;
        }
        if(equaFlag == strLen)
        {
            cout<<"Find It!\n";
            return flag+1;
        }
        else if(flag==movePos-1 && equaFlag!=strLen)
        {
            cout<<"Find Nothing!\n";
        }
    }

    return 0;
}

//book_algori
int BookAlgor(string str1, string str2)
{
    unsigned int i = 0;
    unsigned int j = 0;

    cout<<"Start Algor..."<<endl;
    if(str2.size() > str1.size())
    {
        cout<<"st2 is too long\n";
        return -1;
    }

    while(i<str1.size() && j<str2.size())
    {
        if(str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i-j+1;
            j = 0;
        }
    }

    if(str2.size() == j)
    {
        return i-j+1;
        cout<<"BookAlgori find it!\n";
    }
    else
        return 0;
}

#if 0

分析思路网址:       https://www.zhihu.com/question/21474082;
//KMP_Algorithm
记 匹配串为P[j]  主串为S[i];

暴力或者朴素匹配法，主串中的i指针总是需要回溯，其实仔细分析，其中有很多多余比较过程，所以算法还可以优化。多余过程分析如下：
为什么可以优化？分析i回溯原因如下：  （例子可参照 abcde与abe  和  abade abae ... ) 【设首字符位置为0】
1.若主串和匹配串第一个位置都不一样了。那还需要回溯吗？直接都往后挪一位，比较i+1和j+1去了。若要回溯，那么肯定是发生在>1的某位置主串和匹配串不匹配了。
2.既然只可能是>1的位置才会发生回溯。那就说明从主串开始和匹配串匹配的初始位置（记为startPos）到主串的i-1位置的字符肯定都是相同的，这点必须想通！
3.那么既然之前主串和匹配串都是相同的，那匹配串的首位干嘛还要依次和主串不停 回溯！ 到的1<startPos<i-1.这些位置去比较呢？
4.此时分两种情况，第一：不匹配位置之前的字符串与首字符到某一位置都不相等。 第二：不匹配位置之前的首字符串到某一位置有相等的 （补充说明一下：
        匹配串的首字符想要和主串的各个字符去比较的话，不就是等价于 匹配串的首字符和匹配串的其他字符去比较吗？？完全可以忽略主串影响 [所以
        这种情况下，匹配串移动的位置也就是和主串根本没有关系的！]    移动多少呢？下面说明
5.当处于第一种情况，都不相等时，明显，都不相等说明，匹配串第1到第j-1位置的都是不相同的，同理主串的第1到第i-1都是不相同的。但是
        主串和匹配串从第1个到j-1个位置的字符串又都相同，那么 确定有结论！：匹配串第1个和主串第1<startPos<i位置之内的任何一个字符都不相同
        那么此时匹配串肯定要移到首字符位置   next[j] = 0;
6.当处于第二种情况，匹配串中有相同时。设为x位置和y位置相同。那么此时显然主串中对应的x和y两个位置也是相同的。那么此时匹配串当然也可以忽略比较
        首字符和主串该位置的比较。直接略过。
        于此，可以得到如下结论：

        匹配i++;当j!=-1（首字符前一位时）且不匹配时i原地不动，完全可以不回溯，只移动j，使j=next[j]即可！;
        a.当不匹配发生在匹配串的首字符位置（0）位置时，那么此时匹配串肯定要移回首字符再与下位比较的  next[j]=0;
        b1.当不匹配发生在匹配串非首字符位置时，那么此时，当无前后缀相等，i不动，j回到首字符0.即主串从刚刚的i与匹配串的j比较变成
            i与0(首字符)比较.   next[j]=0;
        b2.当不匹配发生在匹配串非首字符位置时，那么此时，当有前后缀相等，i不动，j就略过最长的相等前后缀长度即可！
            即为主串从刚刚的i与匹配串额j比较变成i与MAX处比较！  next[j]=MAX;

7.现在的关键是求得串的最大前后缀长度，怎么求？如下思路：
    假如此时已经找到最大前后缀长度为k。那么就有"P[0]~P[k-1]" == "P[j-k]~P[j-1]";既然设定了初始的最大K值，我们就假设这个值已经被求得。那么显然
        这个假设的k值要么就刚好等于实际的最大K值。要么不等于实际K值(不等于那就只有可能大或者只可能比实际K值小)。既然如此，要是刚好假设的k值和实际的
        K值相等，那就直接返回这个假设的k值。即此时有"GetMaxLen(j)==k"成立(表示j长度的串内有k长度的最大前后缀)。若不相等，无非两种情况，到底是假
        设大了还是小了？如下分析：
    a.假如假设的k值小了，那么此时肯定会有另外一个数X>k，(假设X刚好只比k大1.后面是否还有Xn刚好只比X大1，再继续递归分析)即现在假设X=k+1;
        即满足该式"GetMaxLen(j)==k+1"成立;若要满足有这个数X，那么必须有"P[0]~P[x-1]" == "P[j-x]~P[j-1]" 等价于
        "P[0]~P[(k+1)-1]" == "P[j-(k+1)]~P[j-1]";
    b.假如假设的k值大了,那么此时肯定会有另外一个数Y<k,(假设Y刚好只比k小1，后面是否还有Yn刚好只比Y小1,再继续递归分析)即现在假设Y=k-1;
        既满足该式"GerMaxLen(j)==k-1"成立;若要满足有这个Y,那么必须有"P[0]~P[k-2]" == "P[j-k+1]~P[j-1]";

故此有如下程序;


#endif


//KMP获得next数组还是没完全理解，暂时放置。
void GetMaxLen(string str, int* next)
{
    unsigned int j = 1;
    unsigned int k = 0;

    next[1] = 0;

    while(j < str.size())
    {
        if(str[j]==str[k] || k==0)
        {
            j++;
            k++;
            if(str[j] != str[j])
            {
                next[j] = k;
            }
            else
            {
                next[j] = next[k];
            }
        }
        else
        {
            k = next[k];
        }
    }
}


int KmpAlgoritm(string str1, string str2)
{
    unsigned int i = 0;
    unsigned int j = 0;

    int next[255];
    GetMaxLen(str2, next);

    if(str2.size() > str1.size())
    {
        cout<<"Str2 too long!"<<endl;
        return -1;
    }
    else
    {
        while(i<str1.size() && j<str2.size())
        {
            if(str1[i]==str2[j] || 0==(int)j)
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if(str2.size() == j)
        {
            cout<<"Find it"<<endl;
        }
        else
        {
            cout<<"Find Nothing"<<endl;
            return 0;
        }
    }

    return i;
}


int main()
{
    string st1 = "goodgoogleabc";
    string st2 = "abc";
    string st3 = "bcd";
    string st4 = "a";


    //cout<<st1[0]<<endl;

    int returnValue = SimpleAlgor(st1, st4);
    cout<<"returnValue = "<<returnValue<<endl;

    returnValue = BookAlgor(st1, st4);
    cout<<"Book returnValue = "<<returnValue<<endl;

    returnValue = KmpAlgoritm(st1, st4);
    cout<<"KmpAlgoritm returnValue = "<<returnValue<<endl;


    cout << "Hello World!" << endl;
    return 0;
}

