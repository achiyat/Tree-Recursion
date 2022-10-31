#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)


typedef struct Leaf
{
	// Management or MetaData
	int level;
	struct Leaf* Left;
	struct Leaf* Right;
	struct Leaf* Parent;

	// Data (Real Data)
	int Val;
} TLeaf;


TLeaf* Root = NULL;
TLeaf* pointer;

void AddLeaf(TLeaf* curr, int val);
void printTree();

int selector = 1;
int count = 0;
int pointerNUM;



TLeaf* R(TLeaf* item)
{
	if (pointer->Left != NULL && pointer->Right != NULL)
	{
		pointer = pointer->Left;
		LR(pointer);
	}
	else if (pointer->Left != NULL)
	{
		pointer = pointer->Left;
		L(pointer);
	}
	else if (pointer->Right != NULL)
	{
		pointer = pointer->Right;
		R(pointer);
	}
}

TLeaf* L(TLeaf* item)
{
	if (pointer->Left != NULL && pointer->Right != NULL)
	{
		pointer = pointer->Left;
		LR(pointer);
	}
	else if (pointer->Left != NULL)
	{
		pointer = pointer->Left;
		L(pointer);
	}
	else if (pointer->Right != NULL)
	{
		pointer = pointer->Right;
		R(pointer);
	}
}

TLeaf* LR(TLeaf* item)
{
	L(pointer);

	R(pointer);
}

TLeaf* get_pointer(TLeaf* item)
{
	if (pointer->Left != NULL && pointer->Right != NULL)
	{
		pointer = pointer->Left;
		get_pointer(pointer);
		printf("%d", pointer->Parent);
		L(pointer);
		R(pointer);
		//LR(pointer);
	}
	else
	{
		printf("%d", pointer->Val);
	}

	pointer = pointer->Parent;
	return pointer;


}

void printTree()
{
	/*
	TLeaf* pointer = Root;

	//
	int pointerNUM;

	while (pointer->Right != NULL)
	{
		pointer = pointer->Right;
	}

	int maxNUM = pointer->Val;

	pointer = Root;

	while (pointer->Left != NULL)
	{
		pointer = pointer->Left;
	}
	*/

	//pointer->Val = pointerNUM;

	//pointer->Parent->Val;
	//get_pointer();
	/******************************
	TLeaf* curr;

	if (count == 0)
	{
		TLeaf* pointer = Root;

		while (pointer->Left != NULL)
		{
			pointer = pointer->Left;
		}
		curr = pointer;
	}
	else
	{
		while (pointer->Left != NULL && selector == pointer->Val)
		{
			pointer = pointer->Left;
		}
	}
	count++;
	***********************************************/
	
	TLeaf* pointer = Root;

	while (pointer != NULL && selector != pointer->Val)
	{
		pointer = pointer->Left;
	}


	if (pointer->Val < Root->Right->Val && pointer->Right == NULL)
	{
		printf("%d", pointer->Val);
		//selector = pointer->Val;

		if (Root->Val != pointer->Val)
		{
			
			pointer = pointer->Parent;
			selector = pointer->Val;
		}
		else
		{
			pointer->Val = Root->Right->Val;
			selector = pointer->Val;
		}
	}
	else if (pointer->Val < Root->Right->Val && pointer->Right != NULL)
	{
		printf("%d", pointer->Val);
		//selector = pointer->Val;

		if (Root->Val != pointer->Val)
		{
			pointer = pointer->Right;
			selector = pointer->Val;
		}
		else
		{
			pointer->Val = Root->Right->Val;
			selector = pointer->Val;
		}
	}

	printTree();

	/*
	//3
	while (pointer->Val < Root->Right->Val && pointer->Right == NULL)
	{
		printf("%d", pointer->Val);
		//selector = pointer->Val;

		if (Root->Val != pointer->Val)
		{
			pointer = pointer->Parent;
			selector = pointer;
		}
		else
		{
			pointer->Val = Root->Right->Val;
			selector = pointer->Val;
		}

		//printTree();
	}*/

}



void AddLeaf(TLeaf* curr, int val)
{
	TLeaf* newLeaf = (TLeaf*)malloc(sizeof(TLeaf));
	newLeaf->Val = val;
	newLeaf->Right = NULL;
	newLeaf->Left = NULL;

	if (Root == NULL)
	{
		Root = newLeaf;
		newLeaf->Parent = NULL;
	}
	else {
		if (curr == NULL)
		{
			curr = Root;
		}

		if (curr->Val < val)
		{
			if (curr->Right == NULL)
			{
				// add into
				curr->Right = newLeaf;
				newLeaf->Parent = curr;
			}
			else
			{
				AddLeaf(curr->Right, val);
			}

		}
		else
		{
			if (curr->Left == NULL)
			{
				// add into
				curr->Left = newLeaf;
				newLeaf->Parent = curr;
			}
			else
			{
				AddLeaf(curr->Left, val);
			}
		}
	}
}


int main()
{
	Root = NULL;
	AddLeaf(NULL, 6);
	AddLeaf(NULL, 9);
	AddLeaf(NULL, 2);
	AddLeaf(NULL, 4);
	AddLeaf(NULL, 223);
	AddLeaf(NULL, 23);
	AddLeaf(NULL, 3);
	AddLeaf(NULL, 123);
	AddLeaf(NULL, 7);
	AddLeaf(NULL, 322);
	AddLeaf(NULL, 10);
	AddLeaf(NULL, 100);
	AddLeaf(NULL, 1);
	AddLeaf(NULL, 8);
	AddLeaf(NULL, 5);

	TLeaf* pointer = Root;
	TLeaf* get_pointer(pointer);
	printTree();
	

}


/*

	while (pointer->Val < Root->Right->Val && pointer->Right == NULL)
	{
		printf("%d", pointer->Val);
		//selector = pointer->Val;

		if (Root->Val != pointer->Val)
		{
			pointer = pointer->Parent;
			selector = pointer;
		}
		else
		{
			pointer->Val = Root->Right->Val;
			selector = pointer;
		}

		//printTree();
	}

	while (pointer->Val < Root->Right->Val && pointer->Right != NULL)
	{
		printf("%d", pointer->Val);
		//selector = pointer->Val;

		if (Root->Val != pointer->Val)
		{
			pointer = pointer->Right;
			selector = pointer;
		}
		else
		{
			pointer->Val = Root->Right->Val;
			selector = pointer;
		}
	}


*/