#include<iostream>
#include<string>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	fstream inp,oup,raw,table;
	time_t start, end;
	//TIME START
	time(&start);
	//CREATE FILE
	inp.open("input.txt",ios::out);
	oup.open("output.txt",ios::out);
	raw.open("raw.txt",ios::in);
	//UPPERCASE WORK
	string input;
	int size;
	cout<<"Enter the KB size of file:";
	cin>>size;
	while(getline(raw,input))
	{
        inp<< input ;
    }
    for(int i=0;i<size-1;i++)
    {
    	inp<<"\n";
    	inp<<input;
	}
	inp<<input;
	string output="";
	for(int i=0;i<input.length();i++)
	{
		int value=input[i];
		if(97<=value&&value<=122)
		{
			char ch=value-32;
			output.push_back(ch);
		}
		else
		{
			char ch=value;
			output.push_back(input[i]);
		}
	}
	for(int i=0;i<size;i++)
    {
    	oup<<output;
    	oup<<"\n";
	}
	//FILE CLOSE
	inp.close();
	oup.close();
	raw.close();
	//TIME END 
	time(&end);
	//DISPLAY TIME
	double timeTaken = double(end - start);
	cout<<"Total time taken : "<<timeTaken<<endl;
	//MAINTAIN TABLE
	table.open("table.txt",ios::in|ios::app);
	table<<size<<"KB\t\t\t"<<timeTaken<<"\n";
	table.close();
}
