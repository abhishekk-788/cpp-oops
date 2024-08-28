
// C++ Compiler decides which function to call before seeing its accessbility. 

#include<bits/stdc++.h>
using namespace std;

/* Diamond Shape Problem */

/*
		File
		/  \
InputFile  OutputFile
        \  /
       IOFile
*/

class File
{
	public:
	string name;
	
	void open();
};

class InputFile: public File {
};

class OutputFile: public File {
};

class IOFile : public InputFile, public OutputFile {
};

int main()
{
	IOFile f;
	f.open(); 	/* Ambiguous */
}
