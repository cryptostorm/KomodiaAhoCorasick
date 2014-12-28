KomodiaAhoCorasick
集合匹配与AC自动机
==================

A string set matching algorithm



1.    示例
我们有一个集合的模式串，比如说一组A：
pig，rabbit，mouse
此时来了一个匹配串B：
I saw a rabbit and a pigeon in this forest.
我们需要B中字符是否包含A中任意一个单词？包含哪一些？每一种包含几个？
针对上面例子的答案是：包含；包含如下两个单词；每一种包含1个：
rabbit, pig.
2.    问题描述
这就一个集合匹配问题（Set Matching），即对于一组模式串集合A，查询一个较长匹配串B中是否包含A中元素；其中
l  A的规模：10万个，每个长度50字符；
l  B的长度：10亿个字符。
相关描述：
http://www.cs.uku.fi/~kilpelai/BSA05/lectures/slides04.pdf
ftp://163.13.200.222/assistant/bearhero/prog/%A8%E4%A5%A6/ac_bm.pdf
http://en.wikipedia.org/wiki/Aho-Corasick_algorithm
3.    解决方案
3.1    设计空间
若只是一个模式串，匹配另外一个长串，通常采用的方法是使用KMP算法，对一个模式串进行预处理，设置匹配过程中失败后的下标步进距离，跳到已经匹配的下一个子串，重新利用匹配过程中已经匹配的字符，提高效率。
而对于集合匹配，也可以采用类似的思路，需要设计的有两个部分
l  对A集合的串进行预处理；
l  匹配过程中失败后下标的移动。
3.2    解决思路
前缀树，即字典树：即以单个字符为节点，第n层代表第n个位置的字符，把模式串集合建立一棵树。
AC自动机：在字典树的基础上，加入失败跳转指针，使得查询阶段过程中匹配失败后，利用已经匹配字符，直接跳转到匹配了一部分的另外一个节点处继续进行匹配。
附，Huffman树，最优二叉树，带权路径长度和达到最小，以01串编码解码，需要知道模式串在目标串中出现的概率。目标在于减少编码长度，而不是快速匹配。
4.    代码实现
4.1    简介
为了避免重复发明轮子，我在网络上搜索了AC自动机的实现，筛选后得到了如下网址：
http://www.komodia.com/aho-corasick
项目	说明
实现语言	C++
实现形式	类，树，可复用性强
开源协议	要求在不删除注释的条件下分发使用
注意事项	手册中强调本代码还有若干bug，不建议在生产环境中使用。
因为找不到其他更好的AC自动机实现，所以我就在该版本的基础修改bug，经过若干天的尝试，修复了2个bug，暂时没有发现其他bug。
项目	说明
Bug01	多次匹配时重新定位指针错误
Bug02	特殊编码匹配，例如UTF8
4.2    使用方法
修正以上两个bug的代码挂在：https://github.com/elfinhe/KomodiaAhoCorasick。
使用的协议是：不要删除代码中的注释，不建议在商业环境中使用。
列出常用的函数如下，具体可以参考文档“AhoCorasick.pdf”：
函数	说明
AddString	在树上添加一个串，仅为算法的字典树部分
DeleteString	在树上删除一个串
BuildTreeIndex	建立AC自动机的失败跳转指针
SearchAhoCorasik	使用AC自动机查找某个串是否包含集合中任意一个串
4.3    代码示例
列出C++简单示例代码如下：
            CSuffixTrie aTree;
            aTree.AddString("hzyusisheying");
            aTree.AddString( "zyusisheyin");
            aTree.AddString(  "yusisheyin");
            aTree.AddString(   "usisheyin");
            aTree.AddString(    "sisheyin");
            aTree.AddString(     "isheyin");
 
            aTree.BuildTreeIndex();
            CSuffixTrie::DataFoundVector aDataFound;
            aDataFound=aTree.SearchAhoCorasikMultiple("hzyusisheyinghzyusisheyingzyusisheyingisheying");
 
 
            for (int iCount=0;
                         iCount<aDataFound.size();
                         ++iCount)
                        printf("%s %i\n",aDataFound[iCount].sDataFound.c_str(),aDataFound[iCount].iFoundPosition);
 
5.    结语
通过示例引入“集合匹配”的问题。这个问题虽然简单常见，例如，黑名单、敏感词、关键字统计，但是在真实环境超大数据量的情况下，完全正确地优化却没那么容易，所以这里给出了一个较容易复用的现成实现，或许是各位最大的收获。如果遇到任何问题，联系：elfinhe■gmail【dot】com。
