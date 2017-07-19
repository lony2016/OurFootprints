#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

void ArrayNumCount(int a[], int n)
{
    int i;
    if(n<=0 || a == NULL)
    {
        return;
    }
    for(i=0; i<n; i++)
    {
        a[i] = a[i]*n;
    }
    for(i=0; i<n; i++)
    {
        a[a[i]/n]++;
    }
    for(i=0; i<n; i++)
    {
        a[i] %= n;
    }
    //a[0]表示数组元素的个数
    for(i=0;i<n;i++)
    {
        if(i == 0)
        {
            cout << "the number of array is " << n << endl;
        }else{
            cout << "element: " << i << " , count: " << a[i] <<endl;
        }

    }
}
class Solution
{
public:
    int findLUSlength(string a, string b) {
           return a == b?-1:(a.length() > b.length()?a.length():b.length());
    }
    struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    void convert(TreeNode* root, int& sum){
        if(root == NULL) return;
        convert(root->right, sum);
        root->val += sum;
        sum = root->val;
        convert(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return NULL;
        int sum = 0;
        convert(root, sum);
        return root;
    }
    //104. Maximum Depth of Binary Tree
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int res = 0;
        queue<TreeNode*> qu;
        qu.push(root);//将x 接到队列的末端
        while(!qu.empty())//q.empty()，当队列空时，返回true
        {
            ++res;
            int size = qu.size();
            for(int i = 0; i < size; ++i)//使用for循环是保证每层遍历完才能进入下一层，用来计算树的高度，跟
            {
                TreeNode* t = qu.front();//即最早被压入队列的元素
                qu.pop();//弹出队列的第一个元素，注意，并不会返回被弹出元素的值
                if(t->left != NULL) qu.push(t->left);
                if(t->right != NULL) qu.push(t->right);
            }
        }
        return res;
    }


    //404. Sum of Left Leaves
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root || ((root->left == NULL) && (root->right == NULL))) return 0;
        int sum = 0;
        bool left = false;
        helper_sumLeftleaves(root, left, sum);
        return sum;
    }
    void helper_sumLeftleaves(TreeNode* root, bool left, int& sum)
    {
        if(!root) return;
        if((root->left == NULL) && (root->right == NULL) && left)
        {
            sum += root->val;
            return;
        }
        helper_sumLeftleaves(root->left, true, sum);
        helper_sumLeftleaves(root->right, false, sum);
    }
    int sumOfLeftLeaves2(TreeNode* root) {
        if(!root || ((root->left == NULL) && (root->right == NULL))) return 0;
        int sum = 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int tree_height = 0;
        while(!qu.empty())
        {
           int size = qu.size();
           ++tree_height;//加for循环可以计算树的高度
           TreeNode* node;
           for(int i = 0; i < size; ++i)//加不加for对这题结果没影响，
               //for只是保证每层遍历完才再次进入下一层循环（while循环），正好计算树的高度
           {
               node = qu.front();
               qu.pop();
               if((node->left != NULL) && (node->left->left == NULL) && (node->left->right == NULL))
               {
                   sum += node->left->val;
               }
               if(node->left != NULL) qu.push(node->left);
               if(node->right != NULL) qu.push(node->right);
           }
         }
         return sum;
    }

    //168. Excel Sheet Column Title
    string convertToTitle(int n) {
        string s = "";
        string str[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M",
                          "N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        while(n > 0)
        {
            int i = n%26;//每次取n的每个位上的数：个位、十位、百位等等
            if(i == 0)
                s = "Z" + s;//warn:是把s追加到新加入的字母后面，顺序不要搞错
            else
                s = str[i-1] + s;//warn:是把s追加到新加入的字母后面，顺序不要搞错
            //res = s + res;//或者res = s.append(res);
            n = (n-1)/26;//结合10进制来想：0-9，而此处的26进制是从1开始的
        }
        return s;
    }
    string convertToTitle2(int n) {
        string s = "";
        while(n > 0)
        {
            char ch = 'A' + (n-1)%26;//结合10进制来想：0-9，而此处的26进制是从1开始的
            s = ch + s;
            n = (n - 1)/26;//结合10进制来想：0-9，而此处的26进制是从1开始的
        }
        return s;
    }

    //387.First Unique Character in a String
    int firstUniqChar(string s) {//不推荐此方法
        int index = -1;
        int length = s.length();
        if(length == 0) return -1;
        if(length == 1) return 0;
        for(int i = 0; i < (int)s.length(); ++i)
        {
            bool flag = true;
            for(int j = 0 ; j < (int)s.length() ; ++j)
            {
                if(j != i)
                {
                    if(s[i] == s[j])
                    {
                        flag = false;
                        break;
                    }
                }

            }
            if(flag)
            {
                index = i;
                break;
            }
        }
        return index;
    }
    int firstUniqChar2(string s)
    {
        vector<int> count(26);
        int index = -1;
        for(int i = 0; i < (int)s.size(); ++i)//对s中每个字母计数
        {
            ++count[s[i] - 'a'];
        }
        for(int i = 0; i < (int)s.size(); ++i)
        {
            if(count[s[i] - 'a'] == 1)//第一次出现计数为1的返回
            {
                index = i;
                break;
            }
        }
        return index;
    }

    //
};

int main()
{
    Solution su;
//    int n = 26;
//    string str1 = "leetcode";
    string str2 = "";

    int index = su.firstUniqChar2(str2);
//    string s = su.convertToTitle2(n);
    cout << index << endl;
//    cout << str2.length() << endl;
//    return 0;

    return 0;
}









