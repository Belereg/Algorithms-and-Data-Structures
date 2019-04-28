#include "stdafx.h"

#if 0
struct nod
{
	int data;
	nod *next;
};

void push(int a, nod *&stiva)
{
	nod *p = new nod;
	p->data = a;
	if (stiva == NULL)
	{
		stiva = p;
		p->next = NULL;
	}
	else
	{
		p->next = stiva;
		stiva = p;
	}

}

int pop(nod *&stiva)
{

	if (stiva == NULL)
	{
		//cout << "Stiva vida, return : ";
		return -1;
	}
	else
	{
		nod *p = stiva;
		stiva = stiva->next;
		p->next = NULL;
		return p->data;
	}

}

int main()
{
	char s[100];
	cin.get(s, 100);

	int i=0, k = 0;
	nod *stiva = NULL;

	while (s[i])
	{
	//	cout << "a intrat cu " << s[i] << endl;
		if (s[i] == 'a' && k == 0)
		{
			//cout << "stiva ++";
			push(1, stiva);
		}
		else if (s[i] == 'a' && k < 0)
			k++;
		else if (s[i] == 'b' && k == 0 && stiva)
		{
			//cout << "stiva --";
			pop(stiva);
		}
		else if (s[i] == 'b' && k <= 0&& !stiva)
			k--;
		i++;
	}

	if (stiva == NULL && k == 0)
		cout << "a=b";
	else
		cout << "a>b sau a<b";

//	cout << s << endl;
	system("pause");
}
#endif