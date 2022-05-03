#include<bits/stdc++.h>

using namespace std;

#define N 10000						// Total Number of points in textfile.txt, dont change it!

float* get_my_file()				// Function to read textfile.txt
{
	float* a; 
	a = new float [N];
	fstream newfile;
	newfile.open("testfile.txt",ios::in);

   	if (newfile.is_open())
   	{   
		string tp;
		int i=0;
		while(getline(newfile, tp))
		{
			a[i]=stof(tp);
			i++;
		}
		newfile.close();
  	}
  	else
  	{
  		cout<<"File not read!!\n";
  	}

  return a;

}

int main()
{
	float* input = get_my_file();
	// Uncomment the code below to check if the file is successfully printed to the console
	auto temp = input;
	for(int i = 0; i < N; i++)
	{
		cout<<*temp<<endl;
		temp++;
	}
}