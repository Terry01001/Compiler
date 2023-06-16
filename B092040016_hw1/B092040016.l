%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Node{
	char *identifier;
	int index;
	struct Node *next;
};
typedef struct Node Node;

int count=0;
Node *front;
Node *tail;
Node *temp;
Node *current;

void create();
int lookup(const char* search);
int insert(const char* id);
void dump();

char* sign="no_sign";
char* c;
long int transfer_num;
int stringlength;
int break_point;
int IsPreOP=0;
int ISPreNUM=0;
unsigned charCount = 1,  lineCount = 1;

void output(unsigned LC, unsigned CC, const char* str, const char* type);
int LinesInComment(const char* string);
int LinesInInt(const char* stringINT);
int LinesInFloat(const char* stringFloat);
int checkOverflow_int(const char* str1);
int checkOverflow_float(const char* str2);
int checkOverflow_newlineint(const char* str3);
int checkOverflow_newlinefloat(const char* str4);
%}

Reserved_word boolean|break|byte|case|char|catch|class|const|continue|default|do|double|else|extends|false|final|finally|float|for|if|implements|int|long|main|new|print|private|protected|public|return|short|static|string|switch|this|true|try|void|while

ID         [[:alpha:]_\$][[:alnum:]_\$]*
String     \"(\\\"|[^\\\"])*\"

DecOct    [+-]?[0-9]+
Hex       [+-]?0x([0-9]|[a-fA-F])+
Integer {DecOct}|{Hex}

N_DecOct  [+-]?[\r\n]*[0-9]+
N_Hex     [+-]?[\r\n]*0x([0-9]|[a-fA-F])+
N_Integer {N_DecOct}|{N_Hex}

float            [+-]?(\.[0-9]+|[0-9]+\.[0-9]*)[fF]?
science          [+-]?(\.[0-9]+|[0-9]+\.[0-9]*)[eE][+-]?[0-9]+[fF]?
nopointfloat     [+-]?[0-9]+[fF]
nopointscience   [+-]?[0-9]+[eE][+-]?[0-9]+[fF]?
Float {float}|{nopointfloat}|{nopointscience}|{science}

N_float            [+-]?[\r\n]*(\.[0-9]+|[0-9]+\.[0-9]*)[fF]?
N_science          [+-]?[\r\n]*(\.[0-9]+|[0-9]+\.[0-9]*)[eE][+-]?[0-9]+[fF]?
N_nopointfloat     [+-]?[\r\n]*[0-9]+[fF]
N_nopointscience   [+-]?[\r\n]*[0-9]+[eE][+-]?[0-9]+[fF]?
N_Float {N_float}|{N_nopointfloat}|{N_nopointscience}|{N_science}

Comments   \/\*[^*]*\*+(?:[^\/*][^*]*\*+)*\/|\/\/.*\n

Space [ \t]
Eol \n

/*  Symbol  */
Comma ,
Colon :
Semicolon ;
Parentheses \(|\)
Square_brackets \[|\]
Brackets \{|\}

Symbol {Comma}|{Colon}|{Semicolon}|{Parentheses}|{Square_brackets}|{Brackets}

/*  Operator  */
Arithmetic [\+\-\*\/]
Addition \+\+
Subtraction \-\-
Module \%
Assignment \=

Small \<
Smallequal \<\=
Big \>
Bigequal \>\=
Equal \=\=
Notequal \!\=
Relational {Small}|{Smallequal}|{Big}|{Bigequal}|{Equal}|{Notequal}

And \&\&
Or \|\|
Not \!
Logical {And}|{Or}|{Not}

Operator {Arithmetic}|{Addition}|{Subtraction}|{Module}|{Assignment}|{Relational}|{Logical}

Invalid_ID1 [0-9][_[:alnum:]\$]*
Invalid_ID2 [_[:alpha:]\$][_[:alnum:]\$]*[\%\\]+[_[:alnum:]\$]+
Invalid_ID {Invalid_ID1}|{Invalid_ID2}

Single_quote \'[^\']*\'
Quote_inside_string \"[^\"\n]*(\"+[[:alnum:]\ ]*\"|[^\"\n]*)+[^\"\n]*\"
Invalid_string {Single_quote}|{Quote_inside_string}

%%
{Reserved_word} {
	output(lineCount, charCount, yytext, "reserved word");
	charCount += yyleng;
	IsPreOP=0;
	ISPreNUM=0;
}

{ID} {
	output(lineCount, charCount, yytext, "ID");
	charCount += yyleng;
	if(lookup(yytext) == -1)
		insert(yytext);
	IsPreOP=0;
	ISPreNUM=0;
}

{String} {
	output(lineCount, charCount, yytext, "string");
	charCount += yyleng;
	IsPreOP=0;
	ISPreNUM=0;
}

{Integer} {
	if(checkOverflow_int(yytext) == 1){
		if(ISPreNUM == 1 && (sign == "+"||sign == "-") ){
			printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\",but \"overflow\".And the sign \"%c\" is more like \"operator\".\n", lineCount, charCount, yytext, "integer", yytext[0]);
			charCount += yyleng;
		}
		else{
			printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\",but \"overflow\".\n", lineCount, charCount, yytext, "integer");
			charCount += yyleng;
		}
	}
	else{
		if(ISPreNUM == 1 && (sign == "+"||sign == "-") ){
			
			printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\".And the sign \"%c\" is more like \"operator\".\n", lineCount, charCount, yytext, "integer", yytext[0]);
			charCount += yyleng;
			
		}
		else{
			output(lineCount, charCount, yytext, "integer");
			charCount += yyleng;
		}
	}
	IsPreOP=0;
	ISPreNUM=1;
}

{Float} {
	if(checkOverflow_float(yytext) == 1){
		if(ISPreNUM == 1 && (sign == "+"||sign == "-") ){
			printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\",but \"overflow\".And the sign \"%c\" is more like \"operator\".\n", lineCount, charCount, yytext, "float", yytext[0]);
			charCount += yyleng;
		}
		else{
			printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\",but \"overflow\".\n", lineCount, charCount, yytext, "float");
			charCount += yyleng;
		}
	}
	else{
		if(ISPreNUM == 1 && (sign == "+"||sign == "-") ){
			printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\".And the sign \"%c\" is more like \"operator\".\n", lineCount, charCount, yytext, "float", yytext[0]);
			charCount += yyleng;
		}
		else{
			output(lineCount, charCount, yytext, "float");
			charCount += yyleng;
		}
	}
	IsPreOP=0;
	ISPreNUM=1;
}

{N_Integer} {
	if(checkOverflow_newlineint(yytext) == 1){
		if(ISPreNUM == 1 && (sign == "+"||sign == "-") ){
			printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\",but \"overflow\".And the sign \"%c\" is more like \"operator\".\n", lineCount, charCount, yytext, "integer", yytext[0]);
			lineCount  += LinesInInt(yytext);
		}
		else{
			printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\",but \"overflow\".\n", lineCount, charCount, yytext, "integer");
			lineCount  += LinesInInt(yytext);
		}
	}
	else{
		if(ISPreNUM == 1 && (sign == "+"||sign == "-") ){
			printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\".And the sign \"%c\" is more like \"operator\".\n", lineCount, charCount, yytext, "integer", yytext[0]);
			lineCount  += LinesInInt(yytext);
		}
		else{
			output(lineCount, charCount, yytext, "integer");
			lineCount  += LinesInInt(yytext);
		}
	}
	IsPreOP=0;
	ISPreNUM=1;
}

{N_Float} {
	if(checkOverflow_newlinefloat(yytext) == 1){
		if(ISPreNUM == 1 && (sign == "+"||sign == "-") ){
			printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\",but \"overflow\".And the sign \"%c\" is more like \"operator\".\n", lineCount, charCount, yytext, "float", yytext[0]);
			lineCount  += LinesInFloat(yytext);
		}
		else{
			printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\",but \"overflow\".\n", lineCount, charCount, yytext, "float");
			lineCount  += LinesInFloat(yytext);
		}
	}
	else{
		if(ISPreNUM == 1 && (sign == "+"||sign == "-") ){
			printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\".And the sign \"%c\" is more like \"operator\".\n", lineCount, charCount, yytext, "float", yytext[0]);
			lineCount  += LinesInFloat(yytext);
		}
		else{
			output(lineCount, charCount, yytext, "float");
			lineCount  += LinesInFloat(yytext);
		}
	}
	IsPreOP=0;
	ISPreNUM=1;
}

{Comments} {
	output(lineCount, charCount, yytext, "comment");
	charCount += yyleng;
	lineCount  += LinesInComment(yytext);
	IsPreOP=0;
	ISPreNUM=0;
}

{Space} {
	charCount += yyleng;
}

{Eol}   {
	lineCount++;
	charCount = 1;
	IsPreOP=0;
	ISPreNUM=0;
}

{Symbol} {
	output(lineCount, charCount, yytext, "symbol");
	charCount += yyleng;
	IsPreOP=0;
	ISPreNUM=0;
}

{Operator} {
	if(IsPreOP==1){
		printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\",but more like \"sign\".\n", lineCount, charCount, yytext, "operator");
		charCount += yyleng;
		IsPreOP=0;
		ISPreNUM=0;
	}
	else{
		output(lineCount, charCount, yytext, "operator");
		charCount += yyleng;
		IsPreOP=1;
		ISPreNUM=0;
	}
	
}

{Invalid_ID} {
	output(lineCount, charCount, yytext, "Invalid_ID");
	charCount += yyleng;
	IsPreOP=0;
	ISPreNUM=0;
}

{Invalid_string} {
	output(lineCount, charCount, yytext, "Invalid_string");
	charCount += yyleng;
	IsPreOP=0;
	ISPreNUM=0;
}

%%
void output(unsigned LC, unsigned CC, const char* str, const char* type){
	printf("Line: %d, 1st char: %d, \"%s\" is a \"%s\".\n", LC, CC, str, type);
}

int LinesInComment(const char* string){
	int linenum = 0;
	stringlength = strlen(string);
	for (int i = 0; i < stringlength; i++){
        if (string[i] == '\n')
			linenum++;
    }
	
	return linenum;
}

int LinesInInt(const char* stringINT){
	int linenum = 0;
	stringlength = strlen(stringINT);
	for (int i = 0; i < stringlength; i++){
        if (stringINT[i] == '\n'){
			linenum++;
			charCount=1;
		}
		else{
			charCount+=1;
		}		
    }
	return linenum;
}

int LinesInFloat(const char* stringFloat){
	int linenum = 0;
	stringlength = strlen(stringFloat);
	for (int i = 0; i < stringlength; i++){
        if (stringFloat[i] == '\n'){
			linenum++;
			charCount=1;
		}
		else{
			charCount+=1;
		}		
    }
	return linenum;
}

int checkOverflow_int(const char* str1){
	if(str1[0] == '+')
		sign="+";
	else if(str1[0] == '-')
		sign="-";
	else
		sign="no_sign";
	stringlength = strlen(str1);

	if(sign =="no_sign"){
		if(str1[0]=='0' && str1[1]=='x'){
			transfer_num=0;
			for(int i=2;i<stringlength;i++){
				transfer_num*=16;
				if(str1[i]=='A'||str1[i]=='a')  transfer_num += 10;
				else if(str1[i]=='B'||str1[i]=='b')  transfer_num += 11;
				else if(str1[i]=='C'||str1[i]=='c')  transfer_num += 12;
				else if(str1[i]=='D'||str1[i]=='d')  transfer_num += 13;
				else if(str1[i]=='E'||str1[i]=='e')  transfer_num += 14;
				else if(str1[i]=='F'||str1[i]=='f')  transfer_num += 15;
				else  transfer_num += (int)(str1[i]-'0');
			}
			if(transfer_num > 2147483647)
				return 1;
			else
				return 0;
		}
		else if(str1[0]=='0'){
			transfer_num=0;
			for(int i=1;i<stringlength;i++){
				transfer_num*=8;
				transfer_num += (int)(str1[i]-'0');
			}
			if(transfer_num > 2147483647)
				return 1;
			else
				return 0;
		}
		else{
			if(atol(str1) > 2147483647)
				return 1;
			else
				return 0;
		}
	}
	else if(sign=="+"){
		if(str1[1]=='0' && str1[2]=='x'){
			transfer_num=0;
			for(int i=3;i<stringlength;i++){
				transfer_num*=16;
				if(str1[i]=='A'||str1[i]=='a')  transfer_num += 10;
				else if(str1[i]=='B'||str1[i]=='b')  transfer_num += 11;
				else if(str1[i]=='C'||str1[i]=='c')  transfer_num += 12;
				else if(str1[i]=='D'||str1[i]=='d')  transfer_num += 13;
				else if(str1[i]=='E'||str1[i]=='e')  transfer_num += 14;
				else if(str1[i]=='F'||str1[i]=='f')  transfer_num += 15;
				else  transfer_num += (int)(str1[i]-'0');
			}
			if(transfer_num > 2147483647)
				return 1;
			else
				return 0;
		}
		else if(str1[1]=='0'){
			transfer_num=0;
			for(int i=2;i<stringlength;i++){
				transfer_num*=8;
				transfer_num += (int)(str1[i]-'0');
			}
			if(transfer_num > 2147483647)
				return 1;
			else
				return 0;
		}
		else{
			if(atol(str1) > 2147483647)
				return 1;
			else
				return 0;
		}
	}
	else if(sign =="-"){
		if(str1[1]=='0' && str1[2]=='x'){
			transfer_num=0;
			for(int i=3;i<stringlength;i++){
				transfer_num*=16;
				if(str1[i]=='A'||str1[i]=='a')  transfer_num += 10;
				else if(str1[i]=='B'||str1[i]=='b')  transfer_num += 11;
				else if(str1[i]=='C'||str1[i]=='c')  transfer_num += 12;
				else if(str1[i]=='D'||str1[i]=='d')  transfer_num += 13;
				else if(str1[i]=='E'||str1[i]=='e')  transfer_num += 14;
				else if(str1[i]=='F'||str1[i]=='f')  transfer_num += 15;
				else  transfer_num += (int)(str1[i]-'0');
			}
			if( (0-transfer_num) < -2147483648)
				return 1;
			else
				return 0;
		}
		else if(str1[1]=='0'){
			transfer_num=0;
			for(int i=2;i<stringlength;i++){
				transfer_num*=8;
				transfer_num += (int)(str1[i]-'0');
			}
			if( (0-transfer_num) < -2147483648)
				return 1;
			else
				return 0;
		}
		else{
			if(atol(str1) < -2147483648)
				return 1;
			else
				return 0;
		}
	}
}

int checkOverflow_float(const char* str2){
	if(str2[0] == '+')
		sign="+";
	else if(str2[0] == '-')
		sign="-";
	else
		sign="no_sign";
	if(atof(str2) > atof("+3.40292347E+38") || atof(str2) < atof("-3.40292347E+38")){
		return 1;
	}
	return 0;
}

int checkOverflow_newlineint(const char* str3){
	int i;
	sign = "no_sign";
	stringlength = strlen(str3);
	for (i = 0; i < stringlength; i++){
        if(str3[i] == '+')
			sign="+";
		else if(str3[i] == '-')
			sign="-";
		else if(str3[i] == '\n'||str3[i]=='\r'){
			continue;
		}
		else{
			break_point = i;
			break;
		}
    }
	stringlength -= break_point;
	char s[stringlength+1];
	for (i = 0; i < stringlength; i++){
        s[i]=str3[i+break_point];
    }
	s[stringlength]='\0';
	c=(char *)malloc(sizeof(char)*(stringlength+1));
	strcpy(c,s);

	if(c[0]=='0'&&c[1]=='x'){
		transfer_num=0;
		for(i=2;i<strlen(c);i++){
			transfer_num*=16;
			if(c[i]=='A'||c[i]=='a')  transfer_num += 10;
			else if(c[i]=='B'||c[i]=='b')  transfer_num += 11;
			else if(c[i]=='C'||c[i]=='c')  transfer_num += 12;
			else if(c[i]=='D'||c[i]=='d')  transfer_num += 13;
			else if(c[i]=='E'||c[i]=='e')  transfer_num += 14;
			else if(c[i]=='F'||c[i]=='f')  transfer_num += 15;
			else  transfer_num += (int)(c[i]-'0');
		}
		if(sign=="no_sign"||sign=="+"){
			if(transfer_num > 2147483647)
				return 1;
			else
				return 0;
		}
		else if(sign=="-"){
			if( (0-transfer_num) < -2147483648)
				return 1;
			else
				return 0;
		}
	}
	else if(c[0]=='0'){
		transfer_num=0;
		for(i=1;i<strlen(c);i++){
			transfer_num*=8;
			transfer_num += (int)(c[i]-'0');
		}
		if(sign=="no_sign"||sign=="+"){
			if(transfer_num > 2147483647)
				return 1;
			else
				return 0;
		}
		else if(sign=="-"){
			if( (0-transfer_num) < -2147483648)
				return 1;
			else
				return 0;
		}
	}
	else{
		if(sign=="no_sign"||sign=="+"){
			if(atol(c) > 2147483647)
				return 1;
			else
				return 0;
		}
		else if(sign=="-"){
			if( (0-atol(c)) < -2147483648)
				return 1;
			else 
				return 0;
		}
	}
}

int checkOverflow_newlinefloat(const char* str4){
	int i;
	sign = "no_sign";
	stringlength = strlen(str4);
	for (i = 0; i < stringlength; i++){
        if(str4[i]== '+')
			sign="+";
		else if(str4[i] == '-')
			sign="-";
		else if(str4[i]== '\n'||str4[i]=='\r'){
			continue;
		}
		else{
			break_point=i;
			break;
		}
    }
	stringlength -= break_point;
	char s[stringlength+1];
	for (i = 0; i < stringlength; i++){
        s[i]=str4[i+break_point];
    }
	s[stringlength]='\0';
	c=(char *)malloc(sizeof(char)*(stringlength+1));
	strcpy(c,s);
	
	if(sign=="no_sign" || sign=="+"){
		if(atof(c) > atof("+3.40292347E+38"))
			return 1;
		else
			return 0;
	}
	else{
		if(0-atof(c) < atof("-3.40292347E+38"))
			return 1;
		else 
			return 0;
	}
}


void create(){
	count=0;
	front =(Node *)malloc(sizeof(Node));
	tail =(Node *)malloc(sizeof(Node));
}

int lookup(const char* search){

	if(count==0){return -1;}
	temp=front;
	for(int i=0;i<count;i++){
		if(strcmp(temp->identifier,search)==0){
			return temp->index;
		}
		temp = temp->next;
	}
	return -1;
}

int insert(const char* id){
	temp =(Node *)malloc(sizeof(Node));
	temp->identifier=(char *)malloc(sizeof(char)*(strlen(id)+1));
	strcpy(temp->identifier,id);
	temp->index=count;
	temp->next=NULL;

	if(count==0){front=temp;tail=temp;}
	else{
		current=(Node *)malloc(sizeof(Node));
		current=front;
		for(int i=0;i<=count;i++){
			if(current->next!=NULL)
				current=current->next;
			else
				current->next=temp;
		}
	}
	count+=1;
	return count-1;
}

void dump(){
	if(count!=0){
		printf("The symbol table contains:\n");
		temp = front;
		for(int i=0;i<count;i++){
			printf("%s\n",temp->identifier);
			if(temp->next!= NULL)
				temp = temp->next;
			else {break;}
		}
	}
}

int main(){
	create();
	yylex();
	dump();
	return 0;
}
