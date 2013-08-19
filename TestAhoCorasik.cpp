// TestAhoCorasik.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

#include "SuffixTrie.h"


int test01()
{	
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

	return 0;

/**
hzyusisheying 0
yusisheyin 2
usisheyin 3
sisheyin 4
isheyin 5
**/


/**
hzyusisheying 0
yusisheyin 15
zyusisheyin 26
isheyin 38
**/

}

int test02()
{	
	CSuffixTrie aTree;
	aTree.AddString("新闻联播");
	aTree.AddString( "联播");
	aTree.AddString( "新闻");

	aTree.BuildTreeIndex();
	CSuffixTrie::DataFoundVector aDataFound;
	aDataFound=aTree.SearchAhoCorasikMultiple("中央电视台新闻30分新闻联播新闻联播");


	for (int iCount=0;
		 iCount<aDataFound.size();
		 ++iCount)
		printf("%s %i\n",aDataFound[iCount].sDataFound.c_str(),aDataFound[iCount].iFoundPosition);

	return 0;


/**
hzyusisheying 0
yusisheyin 15
zyusisheyin 26
isheyin 38
**/

}

int test03()
{
	CSuffixTrie aTree;
	aTree.AddString("stionlist");
	aTree.AddString("ionlist");
	aTree.AddString("tionlist");
	aTree.AddString("usisheyin");
	aTree.AddString("onlist");
	aTree.AddString("uestionlist");
	aTree.AddString("daceshi");

	aTree.BuildTreeIndex();
	CSuffixTrie::DataFoundVector aDataFound;
	aDataFound=aTree.SearchAhoCorasikMultiple("usisheyindaceshiionlist");


	for (int iCount=0;
		 iCount<aDataFound.size();
		 ++iCount)
		printf("%s %i\n",aDataFound[iCount].sDataFound.c_str(),aDataFound[iCount].iFoundPosition);

	return 0;
}


int test04()
{
	CSuffixTrie aTree;
	aTree.AddString("yunnancaifu");
	aTree.AddString("ncaifu");
	aTree.AddString("nnancaifu");
	aTree.AddString("ancaifu");

	aTree.BuildTreeIndex();
	CSuffixTrie::DataFoundVector aDataFound;
	aDataFound=aTree.SearchAhoCorasikMultiple("yunnancaifuncaifunnancaifuancaifu");


	for (int iCount=0;
		 iCount<aDataFound.size();
		 ++iCount)
		printf("%s %i\n",aDataFound[iCount].sDataFound.c_str(),aDataFound[iCount].iFoundPosition);

	return 0;
}



int test05()
{
	CSuffixTrie aTree;
	aTree.AddString("学生");
	aTree.AddString("老师");
	aTree.AddString("(学生");
	aTree.AddString("豆瓣");

	aTree.BuildTreeIndex();
	CSuffixTrie::DataFoundVector aDataFound;
	aDataFound=aTree.SearchAhoCorasikMultiple("今天(学生来上课，老师好开心。学生也开心。");


	for (int iCount=0;
		 iCount<aDataFound.size();
		 ++iCount)
		printf("%s %i\n",aDataFound[iCount].sDataFound.c_str(),aDataFound[iCount].iFoundPosition);

	return 0;
}


int main(int argc, char* argv[])
{


	test01();
	test02();
	test03();
	test04();
	test05();
	

	CSuffixTrie aTree;
	aTree.AddString("barak");
	aTree.AddString("arakoo");
	aTree.AddString("barakoo");
	aTree.AddString("barako565");
	
	aTree.BuildTreeIndex();
	CSuffixTrie::_DataFound aData;
	CSuffixTrie::DataFoundVector aDataFound;
	aDataFound=aTree.SearchAhoCorasikMultiple("1236h6h6barakoo6arakoo123");

	for (int iCount=0;
		 iCount<aDataFound.size();
		 ++iCount)
		printf("%s %i\n",aDataFound[iCount].sDataFound.c_str(),aDataFound[iCount].iFoundPosition);

	// ##########################
	CSuffixTrie::DataFound aDataFnd = aTree.SearchAhoCorasik("1236h6h6barakoo6arakoo123");

	printf("%s %i\n", aDataFnd.sDataFound.c_str(), aDataFnd.iFoundPosition);

	

	return 0;
}
