#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


typedef struct {
	int type;//1 is unary 2 is binary
	double number;
	char operator[11];
} ElemenType;


typedef struct SNode{
	ElemenType date;
	struct SNode * next;
} SNode ,*Stack;



Stack NUM, OPER;//��ջ�������ջ

//��ջ������ʼ������

void Push(ElemenType in,Stack S)
{
	SNode *TmpCell;
	TmpCell = (SNode *)malloc(sizeof(SNode));
	strcpy(TmpCell->date.operator,in.operator);
	TmpCell->date.number = in.number;
	TmpCell->date.type = in.type;
	TmpCell->next = S->next;
	S->next = TmpCell;
}

void Pop(Stack S, ElemenType *out)
{
	SNode *FirstCell;
	FirstCell = S->next;
	if(!FirstCell){//???
		printf("ERROR:101 \n");//�������101
		exit(0);//��ֹ���򣬴���ԭ������Ǳ��ʽΥ��
	}
	S->next = FirstCell->next;
	strcpy(out->operator,FirstCell->date.operator);
	out->number = FirstCell->date.number;
	out->type = FirstCell->date.type;
	free(FirstCell);
}

Stack CreateStack(Stack *S)
{
	*S = (Stack)malloc(sizeof(struct SNode));
	(*S)->next = NULL;
}	


void DestroyStack(Stack *S)
{
	SNode *p;
	while(p = *S){
		*S = p->next;
		free(p);
	}
}

//ElemenType GeTOP(Stack S)
//{
//	ElemenType TopElem;
//	SNode *FirstCell;
//	FirstCell = S->next;
//	TopElem = FirstCell->date;
//	return TopElem;
//}



//��ջ��������

struct{
	char str[100];
	int kind;//0 is number, 1 is operator
} OneChar;//�ж�ÿһ��������λ�����ֻ������

char *expression;
int i = 0;//�ַ�������ű�

//���ʽ������ʼ�� ����

void getexpression()
{
	 char *p;
	 int limit;
	 int size = 100;
	 expression = (char*)malloc(size * sizeof(char));
	 p = expression;
	 while((*p = getchar()) != '\n'){
	 	if(*p != ' '){
	 		if((*p >= 'A')&&(*p <= 'Z')){
	 			*p += 'a'-'A';//����дת��ΪСд
	 		}
	 	p++;
	 	limit++;
	 	}
	 }
	 *p++ = '#';//��#��Ǳ��ʽ��ͷ�ͽ�β
	 *p = '\0';
}

int judge(char ch){
	if((ch >= '0')&&(ch <= '9')||(ch == '.'))
		return 1;
	else if((ch == '+')&&(ch == '-')){
		if((i == 0)||(expression[i-1] == '('))
			return 1;
	}
	return 0;
}

void getOneChar()
{
	char *p = OneChar.str;
	*p = expression[i];
	if(judge(*p)){
		while(judge(*++p = expression[++i]));//
		*p = '\0';
		OneChar.kind = 0;	
		return;
	}
	else if((*p >= 'a')&&(*p <= 'z')){
		while((expression[i+1] >= 'a')&&(expression[i+1] <= 'z'))
			*++p = expression[++i];
	}
	
	i++;
	*++p = '\0';
//	if(!strcmp(OneChar.str,"pi")){
//		strcpy(OneChar.str,"3.1415926535897932");
////		sprintf(OneChar.str,"%.16g",acos(-1.0));
//		OneChar.kind = 0;
//		return;
//	}
//	else if(!strcmp(OneChar.str,"e")){
//		sprintf(OneChar.str,"%.16g",exp(1));
//		OneChar.kind = 0;
//		return;
//	}
	OneChar.kind = 1;
	return;
}

char Prioritize(ElemenType *operator1, ElemenType *operator2)
{
	char *oper1,*oper2;
	oper1 = operator1->operator;
	oper2 = operator2->operator;
	if(!strcmp(oper1,"ln")||!strcmp(oper1,"log")||
		!strcmp(oper1,"sin")||!strcmp(oper1,"cos")||!strcmp(oper1,"tan")){
		operator1->type = 1;
		return (!strcmp(oper2,"!")||!strcmp(oper2,"(")||!strcmp(oper2,"^"))? '<' : '>' ;
	}
	else if(!strcmp(oper1,"!")){
		operator1->type = 1;
		return '>';//
	}
	else if(!strcmp(oper1,"+")||!strcmp(oper1,"-")||!strcmp(oper1,"*")||!strcmp(oper1,"/")||
			!strcmp(oper1,"(")||!strcmp(oper1,")")||!strcmp(oper1,"^")||!strcmp(oper1,"#")){
		operator1->type = 2;
		switch(oper1[0]){
			case '+': case '-': return (!strcmp(oper2,"+")||!strcmp(oper2,"-")||
										!strcmp(oper2,")")||!strcmp(oper2,"#")) ? '>' : '<';
			case '*': case '/': return (strcmp(oper2,"(")||strcmp(oper2,"^")) ? '>' : '<';
			case '(': return !strcmp(oper2,")") ? '=' : '<';
			case ')': return '>';
			case '^': return (strcmp(oper2,"(")||strcmp(oper2,"!")||strcmp(oper2,"^")) ? '>' : '<';
			case '#': return !strcmp(oper2,"#") ? '=' : '<';
		}
	}else {printf("ERROR:102");exit(0);}//���ֲ���ʶ��������
}
//���ȼ����ؽ���

int factorial(n)
{
	if(n <= 1) return 1;
	else return n * factorial(n-1);
}//�׳����� δ����

ElemenType Calculate(ElemenType num1, ElemenType oper, ElemenType num2)
{
	ElemenType result;
	if(oper.type == 1){
		if(!strcmp(oper.operator,"!")) result.number = factorial(num1.number);
		else if(!strcmp(oper.operator,"lg")) result.number = log10(num1.number);
		else if(!strcmp(oper.operator,"ln")) result.number = log(num1.number);
		else if(!strcmp(oper.operator,"sin")) result.number = sin(num1.number);
		else if(!strcmp(oper.operator,"cos")) result.number = cos(num1.number);
		else if(!strcmp(oper.operator,"tan")) result.number = tan(num1.number);
	}else{
		switch(*oper.operator) {
			case '+': result.number = num1.number + num2.number; break;
			case '-': result.number = num1.number - num2.number; break;
			case '*': result.number = num1.number * num2.number; break;
			case '/': result.number = num1.number / num2.number; break;
			case '^': result.number = pow(num1.number,num2.number);break;
		}
	}
	return result;
}

int main()
{
	ElemenType num1, num2, oper;
//	char c;
	printf("���׼�����v0.1.0 \n\n");
	printf("֧�ֵ������:\n| + | - | * | / | \n|sin|cos|tan|   | \n| lg| ln| ^ | ! |\n\n");
	printf("�������:\n101: ���ʽ���Ϸ���������ʽ�����Ƿ���ȷ \n102: ��Υ�������\n\n");
	printf("������ʽ���س���ֵ \n");
	printf("����quit��������\n\n\n");
	
	while(1){
		i = 0;
		getexpression();
		if(!strcmp(expression,"quit#")) return 0;

		CreateStack(&NUM);
		CreateStack(&OPER);
		strcpy(oper.operator, "#");
		Push(oper, OPER);
		getOneChar();
		while(strcmp(OneChar.str,"#")||strcmp(OPER->next->date.operator,"#")){
			if(OneChar.kind){
				strcpy(oper.operator,OneChar.str);
				switch(Prioritize(&(OPER->next->date), &oper)){
					case '<':
						strcpy(oper.operator,OneChar.str);
						Push(oper,OPER);
						getOneChar();
						break;
					case '=':
						Pop(OPER,&oper);
						getOneChar();
						break;
					case '>':
						Pop(OPER,&oper);
						Pop(NUM,&num2);
						if(oper.type == 2){
							Pop(NUM,&num1);
						}
						Push(Calculate(num1,oper,num2), NUM);
				}
			}
			else{
				num1.number = atof(OneChar.str);
				Push(num1,NUM);
				getOneChar();
			}
		}
		printf("%.16g\n\n",NUM->next->date.number);
		free(expression);
		DestroyStack(&NUM);
		DestroyStack(&OPER);
	}
	free(expression);
	return 0;
}

