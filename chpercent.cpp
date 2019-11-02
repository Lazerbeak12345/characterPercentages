#include <iostream>
#include <fstream>
void printRow(std::string name,double number,double total) {
	//std::cout<<name<<"\t"<<number<<"\t"<<number/total*100<<"%\n";
	std::cout<<number<<"\t"<<name<<"\t"<<number/total*100<<"%\n";
}
int main(int l,char** a) {
	double total=0,
		uppercase=0,lowercase=0,digits=0,
		spaces=0,tabs=0,
		lines=0,
		openParens=0,closeParens=0,
		openCurlys=0,closeCurlys=0,
		openSquares=0,closeSquares=0,
		openAngles=0,closeAngles=0,
		periods=0,colons=0,semicolons=0,commas=0,
		singleQuotes=0,doubleQuotes=0,
		questionMarks=0,exclamationPoints=0,
		poles=0,tildes=0,backticks=0,atSigns=0,
		pounds=0,usdSigns=0,percents=0,
		carrots=0,andpersands=0,underscores=0,
		astriks=0,minus=0,plus=0,equals=0,
		forwardSlash=0,backslash=0;
	std::string buffer;
	double i;
	//std::cout <<std::string(a[l-1]);
	std::ifstream iFile(a[l-1]);
	while(getline(iFile,buffer)) {
		for (i=0;i<buffer.size();i++) {
			switch(buffer[i]) {
				case'A':case'B':case'C':case'D':case'E':case'F':case'G':case'H':case'I':case'J':case'K':case'L':case'M':case'N':case'O':case'P':case'Q':case'R':case'S':case'T':case'U':case'V':case'W':case'X':case'Y':case'Z':
					uppercase++;break;
				case'a':case'b':case'c':case'd':case'e':case'f':case'g':case'h':case'i':case'j':case'k':case'l':case'm':case'n':case'o':case'p':case'q':case'r':case's':case't':case'u':case'v':case'w':case'x':case'y':case'z':
					lowercase++;break;
				case'0':case'1':case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':
					digits++;break;

				case' ':spaces++;break;	case'\t':tabs++;break;

				case'(':openParens++;break;	case')':closeParens++;break;
				case'{':openCurlys++;break;	case'}':closeCurlys++;break;
				case'[':openSquares++;break;	case']':closeSquares++;break;
				case'<':openAngles++;break;	case'>':closeAngles++;break;

				case'.':periods++;break;	case':':colons++;break;	case';':semicolons++;break;	case',':commas++;break;
				case'\'':singleQuotes++;break;	case'"':doubleQuotes++;break;
				case'?':questionMarks++;break;	case'!':exclamationPoints++;break;
				case'|':poles++;break;	case'~':tildes++;break;	case'`':backticks++;break; case'@':atSigns++;break;
				case'#':pounds++;break;	case'$':usdSigns++;break;	case'%':percents++;break;
				case'^':carrots++;break;	case'&':andpersands++;break;	case'_':underscores++;break;

				case'*':astriks++;break;	case'-':minus++;break;	case'+':plus++;break;	case'=':equals++;break;
				case'/':forwardSlash++;break;	case'\\':backslash++;break;
				
				default:std::cerr <<"Unknown character \""<<buffer[i]<<"\"\n";
			}
		}
		total+=buffer.size();
		lines++;
	}
	printRow("Uppercase",uppercase,total);	printRow("Lowercase",lowercase,total);
	printRow("Spaces   ",spaces,total);	printRow("Tabs     ",tabs,total); printRow("Digits   ",digits,total);
	std::cout<<"\n";
	printRow("(",openParens,total);	printRow(")",closeParens,total);
	printRow("{",openCurlys,total);	printRow("}",closeCurlys,total);
	printRow("[",openSquares,total);	printRow("]",closeSquares,total);
	printRow("<",openAngles,total);	printRow(">",closeAngles,total);
	std::cout<<"\n";
	printRow(".",periods,total);		printRow(":",colons,total);
	printRow(";",semicolons,total);	printRow(",",commas,total);
	printRow("'",singleQuotes,total);	printRow("\"",doubleQuotes,total);
	printRow("?",questionMarks,total);	printRow("!",exclamationPoints,total);
	printRow("|",poles,total);	printRow("~",tildes,total);	printRow("`",backticks,total);	printRow("@",atSigns,total);
	printRow("#",pounds,total);	printRow("$",usdSigns,total);	printRow("%",percents,total);
	printRow("^",carrots,total);	printRow("&",andpersands,total);	printRow("_",underscores,total);
	std::cout<<"\n";
	printRow("*",astriks,total);	printRow("-",minus,total);
	printRow("+",plus,total);	printRow("=",equals,total);
	printRow("/",forwardSlash,total);	printRow("\\",backslash,total);
	std::cout<<"\nChars\t"<<total<<"\nLines\t"<<lines<<"\n";
}

