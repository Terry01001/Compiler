%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int yylex();
void yyerror(const char *s);

int error_flag = 0;
int error_charnum;
int error_linenum;
int operator_length=0;
int lack_commaid=0;
extern unsigned long long cpos,lc;
extern char full_line[1024];

int scopenum=0;
struct Node{
	char *identifier;
	int scope;
	int used;
	struct Node *next;
};
typedef struct Node Node;

int count=0;
Node *front;
Node *tail;
Node *temp;
Node *current;

void create();
int lookup(const char* search,int sco);
int insert(const char* id,int sco);
void beused(const char* used_id,int sco);
void usedornot();
void resetforclass();
void resettable();
void dump();
%}

%union{
    char strVal[80];
}

%type <strVal>  ID INT_N FLOAT_N STR PTYPE
%type <strVal>  classes declare nosemi semiornot func_orid eachid compound main_orid para_list comma_para initialid const_exprandexpr comma_id
%type <strVal>  fin_id fincomma_id const_expr statements simple calculate expression term more_factor factor postop_orinvoke preop 
%type <strVal>  para_invoke comma_invoke loop forloop forinitopt  arr forupdateopt postop bool_expr errordetect operator more_operator infixop simorcom conditional elseornot

%token PTYPE PP MM LE GE EQ NE AND OR LB RB CLASS ELSE FINAL FOR IF MAIN NEW PRINT RETURN STATIC VOID WHILE ID INT_N FLOAT_N STR 

%%
/*classes: CLASS ID '{' fields methods '}'*/
classes: 
		|classes CLASS ID LB {scopenum++;} statements RB {scopenum--;scopenum+=10;}
		;

declare: 
		| STATIC PTYPE eachid comma_id semiornot 
		| PTYPE  func_orid  //methods or var_declare   /*problem*/
		| FINAL  PTYPE fin_id fincomma_id semiornot 
		| ID ID {if(lookup($2,scopenum)==-1)
					insert($2,scopenum); 
				else 
					printf("******\'%s\' is a duplicated identifier in the current scope.******\n",$2);
		} '=' NEW {beused($2,scopenum);} ID  '('  ')' {error_charnum=cpos;error_linenum=lc;} nosemi //objects  /*problem*/
		| VOID  main_orid '('  ')'  compound //methods
		| MAIN  '('  ')'  compound //methods
		| classes //class in the class
		;

nosemi: {lack_commaid+=1;resetforclass();printf("Line %2d, char: %2d, statement without semicolon\n",error_linenum,error_charnum);}
		| ';'
		;

semiornot: {printf("Line %2d, char: %2d, statement without semicolon\n",error_linenum,error_charnum);} 
		| ';'
		;
func_orid: eachid comma_id semiornot {resettable();}
		| ID '(' para_list ')'  compound  //methods
		| '[' ']' ID '=' NEW PTYPE arr ';'
		;
eachid: ID {if(lookup($1,scopenum)==-1)
				insert($1,scopenum); 
			else
				printf("******\'%s\' is a duplicated identifier in the current scope.******\n",$1);
			error_charnum=cpos;error_linenum=lc;
		} initialid ;

compound: LB {scopenum++;} statements RB {scopenum--;} ;

main_orid: MAIN 
		|ID 
		;
para_list: 
		| PTYPE ID comma_para 
		;
comma_para:
		| ',' PTYPE ID comma_para
		;
initialid: 
		| '='  const_exprandexpr
		;
const_exprandexpr: const_expr | expression
		;
comma_id:
		| ','  eachid comma_id
		| eachid {
			lack_commaid+=1;
			printf("Line %2d, char: %2d, a syntax error at \"%s\"\n",error_linenum,error_charnum,$1);
		} comma_id  //error:lack of comma
		;
fin_id: ID {if(lookup($1,scopenum)==-1)
				insert($1,scopenum); 
			else
				printf("******\'%s\' is a duplicated identifier in the current scope.******\n",$1);
			error_charnum=cpos;error_linenum=lc;
		} '='  const_expr
		;
fincomma_id:
		| ','  fin_id fincomma_id
		;
const_expr: INT_N   
		|const_expr '+'  INT_N  
		|const_expr '-'  INT_N  
		|const_expr '*'  INT_N  
		|const_expr '/'  INT_N  
		;
/*statement*/
/*
分別去處理statements裡的文法，像是compound、simple、whileloop、forloop、conditional(if) 、return等， 
並透過遞迴的方式去長(這樣可以長出很多句子)，還能長到declare，使其能夠匹配大部分文法，
其中特別的是compound還會長出statements，此用意為讓括號裡還能長出宣告及敘述。
*/
statements:
		| statements compound        //compound type: { statements }
		| statements simple          
		| statements loop
		| statements forloop
		| statements conditional
		| statements RETURN expression ';'   /*return*/
		| statements declare
		| statements ELSE {printf("******Else Without If at line %d, char %d******\n",lc,error_charnum-1);} simorcom //error:else without if
		| statements ';'
		;
/*simple*/
simple: PRINT '(' expression ')' ';'   //print function
		|ID {beused($1,scopenum);} calculate ';'   //expression related to id
		| expression ';'   //expression
		;

calculate: PP   //++
		| MM    //--
		| '=' expression     //'=' expression
		;

expression: term
		| expression '+' term
		| expression '-' term
		;

term: factor more_factor;

more_factor: 
		|'*' factor more_factor
		|'/' factor more_factor
		;
factor: ID {beused($1,scopenum);} arr postop_orinvoke
		|const_expr postop_orinvoke
		|'(' expression ')'
		|preop ID
		|STR
		;
postop_orinvoke:
		|PP
		|MM
		|'(' para_invoke ')' //method invoke
		;
preop: PP|MM|'+'|'-';

para_invoke:
		|ID comma_invoke
		;
comma_invoke:
		|',' ID comma_invoke
		;

/*whileloop*/
loop: WHILE '(' bool_expr ')' simorcom   //while loop
		;
/*forloop*/
forloop: FOR '(' forinitopt ';' bool_expr ';' forupdateopt ')' simorcom  //forloop
		;
forinitopt: ID arr '=' expression 
		| PTYPE ID arr '=' expression ;

arr: | '[' INT_N ']' ;

forupdateopt: ID arr postop;
postop: PP | MM ;


bool_expr: expression infixop expression       //boolean expression
		| errordetect   
		;
errordetect: operator {printf("******Invalid Boolean Expression at line %d,char %2d******\n",lc,cpos-operator_length-1);} factor;
operator: more_operator operator
		| '+' {operator_length+=1;}
		| '-' {operator_length+=1;}
		| '*' {operator_length+=1;}
		| '/' {operator_length+=1;}
		;
more_operator: | operator;


infixop: EQ|NE|'<'|'>'|LE|GE;

simorcom: simple
		| compound
		;
/*conditional(if)*/
conditional: IF '(' bool_expr ')' simorcom elseornot;   //if conditional

elseornot:
		| ELSE simorcom 
		;

%%
void create(){
	count=0;
	front =(Node *)malloc(sizeof(Node));
	tail =(Node *)malloc(sizeof(Node));
}

int lookup(const char* search,int sco){

	if(count==0){return -1;}
	temp=front;
	for(int i=0;i<count;i++){
		if(strcmp(temp->identifier,search)==0 && temp->scope == sco){
			return temp->scope; //return scopenum of the id
		}
		temp = temp->next;
	}
	return -1;
}

int insert(const char* id,int sco){
	temp =(Node *)malloc(sizeof(Node));
	temp->identifier=(char *)malloc(sizeof(char)*(strlen(id)+1));
	strcpy(temp->identifier,id);
	temp->scope=scopenum;
	temp->used=0;
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

void beused(const char* used_id,int sco){//sco is the cuurent scope
	if(count==0){return;}
	temp=front;
	for(int i=0;i<count;i++){
		if(strcmp(temp->identifier,used_id)==0 && sco-temp->scope <= 5){
			 temp->used += 1;
			 break;
		}
		temp = temp->next;
	}
	
	return;
}

void usedornot(){
	if(count!=0){
		int flagnotuse=0;
		temp = front;
		for(int i=0;i<count;i++){
			if(temp->next!= NULL){
				if(temp->used==0){
					flagnotuse+=1;
				}
				temp = temp->next;
			}
			else {break;}
		}

		if(flagnotuse!=0){
			temp = front;
			printf("There are not used variable:\n");
			for(int i=0;i<count;i++){
				if(temp->used==0){
					printf("%s\n",temp->identifier);
				}
				if(temp->next!= NULL)
					temp = temp->next;
				else {break;}
			}	
		}
	}
}

void resetforclass(){
	if(count!=0 && lack_commaid!=0){
		temp = front;
		for(int i=0;i<count-lack_commaid;i++){
			if(i==count-lack_commaid-1){
				temp->next=NULL;
				tail=temp;
			}
			else{
				temp=temp->next;
			}
		}
		count=count-lack_commaid;
		lack_commaid=0;
	}
}

void resettable(){
	if(count!=0 && lack_commaid!=0){
		temp = front;
		for(int i=0;i<count-lack_commaid-1;i++){
			if(i==count-lack_commaid-2){
				temp->next=NULL;
				tail=temp;
			}
			else{
				temp=temp->next;
			}
		}
		count=count-lack_commaid-1;
		lack_commaid=0;
	}
}

void dump(){
	if(count!=0){
		printf("The symbol table contains:\n");
		temp = front;
		for(int i=0;i<count;i++){
			printf("%s %d\n",temp->identifier,temp->used);
			if(temp->next!= NULL)
				temp = temp->next;
			else {break;}
		}
	}
}

int main() {
    create();
    yyparse();
	usedornot();
	//dump();
    return 0;
}
