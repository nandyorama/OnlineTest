vector< int> strings;
map<int,string> m;
	
int power(int x, unsigned int y)
{
    if( y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
 
}
//Main Utility Function to Parse a string which is delimiter(#) 
//separated numberic digits.
//And give output as character string
string decrypt(string s)
{
	string token,result;
	m[1]="a";
	m[2]="b";
	m[3]="c";
	m[4]="d";
	m[5]="e";
	m[6]="f";
	m[7]="g";
	m[8]="h";
	m[9]="i";
	m[10]="j";
	m[11]="k";
	m[12]="l";
	m[13]="m";
	m[14]="n";
	m[15]="o";
	m[16]="p";
	m[17]="q";
	m[18]="r";
	m[19]="s";
	m[20]="t";
	m[21]="u";
	m[22]="v";
	m[23]="w";
  m[24]="x";
	m[25]="y";
	m[26]="z";
	
	int pos = 0;string del = "#";
	//Parse delimiter separated String and enter numbers in vector
	while ((pos = s.find(del)) != std::string::npos)
	{
		token = s.substr(0, pos);
		strings.push_back(std::atoi(token.c_str()));
		//std::cout << token << std::endl;
		s.erase(0, pos + del.length());
	}
	strings.push_back(std::atoi(s.c_str()));
	//std::cout << s << std::endl;
	
	//Iterate through the container and get corresponding character to form string
	vector<int>::iterator vi= strings.begin();
	for(;vi!=strings.end();vi++)
	{
	  //If Number is less than or equal to 26
		if(*vi<=26)
		{
			//cout<<*vi<<endl;
			result += m[*vi];
		}
		//Else Number is greater than 26
		else
		{
			int sam = *vi;int x =0;  
			while(sam>26)
			{
			  if(sam>=100)
  				x =2;
			  else
	  			x =1;

				cout<<(sam/power(10,x))<<endl;
				result += m[(sam/(power(10,x)))];
				sam = (sam%(power(10,x)));
			}
			//cout<<sam<<endl;
			result += m[sam];
		}
	}
   return result;
}
int main()
{
  //Input to the Decrypt Function
	string s="10#21#12#91";//julia
	string res=decrypt(s);
	//Output from Decrypt Function
	cout<<res<<endl; 
	
	getchar();
	return 0;
}
