%{
#include "y.tab.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

unsigned long long cpos = 1, tokc = 0, lc = 1;
char full_line[1024];
extern int error_flag;
extern int error_charnum;
extern int error_linenum;
%}
/*Reserved_word break|byte|case|catch|const|continue|default|do|double|extends|false|finally|implements|long|private|protected|public|short|switch|this|true|try*/
PrimitiveType boolean|char|int|float|string

ID         [[:alpha:]_\$][[:alnum:]_\$]*

DecOct    [+-]?[0-9]+
Hex       [+-]?0x([0-9]|[a-fA-F])+
Integer {DecOct}|{Hex}

float            [+-]?(\.[0-9]+|[0-9]+\.[0-9]*)[fF]?
science          [+-]?(\.[0-9]+|[0-9]+\.[0-9]*)[eE][+-]?[0-9]+[fF]?
nopointfloat     [+-]?[0-9]+[fF]
nopointscience   [+-]?[0-9]+[eE][+-]?[0-9]+[fF]?
Float {float}|{nopointfloat}|{nopointscience}|{science}

String     \"(\\\"|[^\\\"])*\"
SglineComments \/\/.*\n
Comments   \/\*[^*]*\*+(?:[^\/*][^*]*\*+)*\/\n


Space [ \t]
Newline \n

Single_char [\[\]\(\)\,\:\;\+\-\*\/\%\=\<\>\!]
%%
{Space} {
    //if(error_flag==1){error_charnum=cpos;error_linenum=lc;error_flag=0;}
	cpos += 1; //1???
	//strcat(full_line," ");
}

{Newline}   {
	cpos=1;
    printf("line %2d: %s\n",lc,full_line);
	memset(full_line,0,1024);
	lc++;
	//return NEWLINE;
}

{PrimitiveType} {
	cpos += yyleng;
    strcat(full_line,yytext);
    strcat(full_line," ");
	sscanf(yytext,"%s",&yylval.strVal);
	return PTYPE;
}

"++" {
    cpos += yyleng;
    strcat(full_line," ++ ");
    return PP;
}
"--" {
    cpos += yyleng;
    strcat(full_line," -- ");
    return MM;
}
"<=" {
    cpos += yyleng;
    strcat(full_line," <= ");
    return LE;
}
">=" {
    cpos += yyleng;
    strcat(full_line," >= ");
    return GE;
}
"==" {
    cpos += yyleng;
    strcat(full_line," == ");
    return EQ;
}
"!=" {
    cpos += yyleng;
    strcat(full_line," != ");
    return NE;
}
"&&" {
    cpos += yyleng;
    strcat(full_line," && ");
    return AND;
}
"||" {
    cpos += yyleng;
    strcat(full_line," || ");
    return OR;
}
"{" {
    cpos += yyleng;
    strcat(full_line,"{");
    return LB;
}
"}" {
    cpos += yyleng;
    strcat(full_line,"}");
    return RB;
}

"class" {
    cpos += yyleng;
    strcat(full_line,"class ");
    return CLASS;
}
"else" {
    error_charnum=cpos;
    cpos += yyleng;
    strcat(full_line,"else ");
    return ELSE;
}
"final" {
    cpos += yyleng;
    strcat(full_line,"final ");
    return FINAL;
}
"for" {
    cpos += yyleng;
    strcat(full_line,"for ");
    return FOR;
}
"if" {
    cpos += yyleng; 
    strcat(full_line,"if ");
    return IF;
}
"main" {
    cpos += yyleng; 
    strcat(full_line,"main ");
    return MAIN;
}
"new" {
    cpos += yyleng; 
    strcat(full_line,"new ");
    return NEW;
}
"print" {
    cpos += yyleng;
    strcat(full_line,"print ");
    return PRINT;
}
"return" {
    cpos += yyleng;
    strcat(full_line,"return ");
    return RETURN;
}
"static" {
    cpos += yyleng; 
    strcat(full_line,"static ");
    return STATIC;
}
"void" {
    cpos += yyleng; 
    strcat(full_line,"void ");
    return VOID;
}
"while" {
    cpos += yyleng;
    strcat(full_line,"while ");
    return WHILE;
}

{ID} {
    //if(error_flag==1){error_charnum=cpos;error_linenum=lc;error_flag=0;}
	cpos += yyleng;
    //error_charnum=cpos;
    strcat(full_line,yytext);
    strcat(full_line," ");
	sscanf(yytext,"%s",&yylval.strVal);
	/* not sure */
	return ID;
}

{Integer} {
	cpos += yyleng;
    strcat(full_line,yytext);
    strcat(full_line," ");
	sscanf(yytext,"%s",&yylval.strVal);
	return INT_N;
}

{Float} {
	cpos += yyleng;
    strcat(full_line,yytext);
    strcat(full_line," ");
	sscanf(yytext,"%s",&yylval.strVal);
	return FLOAT_N;
}

{String} {
	cpos += yyleng;
    strcat(full_line,yytext);
    strcat(full_line," ");
	sscanf(yytext,"%s",&yylval.strVal);
	return STR;
}

{Comments} {
	cpos += yyleng;

	//print comment
	printf("line %2d: ",lc);

	for(int i=0;i < yyleng;i++){
		putchar(yytext[i]);
		if(yytext[i]=='\n' && i != yyleng-1){
			printf("line %2d: ",++lc);
		}
	}
    lc++;
    cpos=1;
    //printf("lc:%d",lc);
}
{SglineComments} {
    cpos+=yyleng;

    //print comment
    printf("line %2d: ",lc);

    for(int i=0;i < yyleng;i++){
		putchar(yytext[i]);
	}
    lc++;
    cpos=1;
    //printf("lc:%d",lc);
}

{Single_char} {
    //if(error_flag==1){error_charnum=cpos;error_linenum=lc;error_flag=0;}
    cpos += yyleng;
    //strcat(full_line," ");
    strcat(full_line,yytext);
    strcat(full_line," ");
    return yytext[0];
}
%%
