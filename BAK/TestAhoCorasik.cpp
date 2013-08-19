// TestAhoCorasik.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

#include "SuffixTrie.h"


int test01()
{	
	CSuffixTrie aTree;
	aTree.AddString(L"hzyusisheying");
	aTree.AddString( L"zyusisheyin");
	aTree.AddString(  L"yusisheyin");
	aTree.AddString(   L"usisheyin");
	aTree.AddString(    L"sisheyin");
	aTree.AddString(     L"isheyin");

	aTree.BuildTreeIndex();
	CSuffixTrie::DataFoundVector aDataFound;
	aDataFound=aTree.SearchAhoCorasikMultiple(L"hzyusisheyinghzyusisheyingzyusisheyingisheying");


	for (int iCount=0;
		 iCount<aDataFound.size();
		 ++iCount)
		printf("%S %i\n",aDataFound[iCount].sDataFound.c_str(),aDataFound[iCount].iFoundPosition);

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
	aTree.AddString(L"新闻联播");
	aTree.AddString( L"联播");

	aTree.BuildTreeIndex();
	CSuffixTrie::DataFoundVector aDataFound;
	aDataFound=aTree.SearchAhoCorasikMultiple(L"中央电视台新闻30分新闻联播");


	for (int iCount=0;
		 iCount<aDataFound.size();
		 ++iCount)
		printf("%S %i\n",aDataFound[iCount].sDataFound.c_str(),aDataFound[iCount].iFoundPosition);

	return 0;


/**
hzyusisheying 0
yusisheyin 15
zyusisheyin 26
isheyin 38
**/

}


int main(int argc, char* argv[])
{


	test02();
	/**
	CSuffixTrie aTree;
	aTree.AddString(L"barak");
	aTree.AddString(L"arakoo");
	aTree.AddString(L"barakoo");
	aTree.AddString(L"barako565");
	
	aTree.BuildTreeIndex();
	CSuffixTrie::_DataFound aData;
	CSuffixTrie::DataFoundVector aDataFound;
	aDataFound=aTree.SearchAhoCorasikMultiple(L"1236h6h6barakoo6arakoo123");

	for (int iCount=0;
		 iCount<aDataFound.size();
		 ++iCount)
		printf("%S %i\n",aDataFound[iCount].sDataFound.c_str(),aDataFound[iCount].iFoundPosition);

	// ##########################
	CSuffixTrie::DataFound aDataFnd = aTree.SearchAhoCorasik(L"1236h6h6barakoo6arakoo123");

	printf("%S %i\n", aDataFnd.sDataFound.c_str(), aDataFnd.iFoundPosition);

	**/

	return 0;
}
