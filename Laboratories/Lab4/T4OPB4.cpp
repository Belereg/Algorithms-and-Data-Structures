#include "stdafx.h"

struct Matrice
{
	int* values;
	unsigned rows, cols;
};

struct Node
{
	int data, indexJ;
	Node* next;
};

void swapNodeData(Node *n1, Node *n2)
{
	int dataAux = n1->data, indexAux = n1->indexJ;

	n1->data = n2->data;
	n1->indexJ = n2->indexJ;

	n2->data = dataAux;
	n2->indexJ = indexAux;
}

struct RowNode
{
	int indexI;
	Node *head;
	RowNode *next;
};

void addToTail(Node* &head, const int &info, const int &indexJ)
{
	if (!head)
	{
		head = new Node;
		head->data = info;
		head->indexJ = indexJ;
		head->next = NULL;
	}
	else
	{
		Node* p = head;
		while (p->next)
			p = p->next;

		p->next = new Node;
		p->next->data = info;
		p->next->indexJ = indexJ;
		p->next->next = NULL;
	}
}

void addToTail(RowNode* &head, const int &indexI)
{
	if (!head)
	{
		head = new RowNode;
		head->indexI = indexI;
		head->next = NULL;
		head->head = NULL;
	}
	else
	{
		RowNode* p = head;
		while (p->next)
			p = p->next;
		p->next = new RowNode;
		p->next->indexI = indexI;
		p->next->next = NULL;
		p->next->head = NULL;
	}
}

void deleteList(Node* &node)
{
	if (node->next)
		deleteList(node->next);
	delete node;
}

void deleteList(RowNode* &node)
{
	if (node->next)
		deleteList(node->next);
	delete node;
}

Matrice& readMatrix(Matrice &mat)
{
	if (mat.values)
		delete[] mat.values;

	cin >> mat.rows >> mat.cols;

	if (!(mat.values = new int[mat.rows*mat.cols]))
		throw std::bad_alloc();

	for (unsigned long index = 0ul; index < mat.rows*mat.cols; index++)
		cin >> mat.values[index];
	return mat;
}

int& at(const Matrice &matrix, const unsigned &indexI, const unsigned long &indexJ)
{
	if (matrix.values)
		if (indexI < matrix.rows && indexJ < matrix.cols)
			return matrix.values[indexI*matrix.cols + indexJ];
	throw "Index out of bounds";
}

void buildRow(const Matrice &matrix, RowNode *&rowHead)
{
	RowNode *crt = rowHead;
	while (crt->next)
		crt = crt->next;
	if (crt == rowHead)
		return;
	crt->head = new Node;
	crt->head->data = 0;
	crt->head->indexJ = -1;
	crt->head->next = NULL;
	for (unsigned indexJ = 0; indexJ < matrix.cols; indexJ++)
	{
		if (at(matrix, crt->indexI, indexJ))
			addToTail(crt->head, at(matrix, crt->indexI, indexJ), indexJ);
	}
}

RowNode* buildMatrix(const Matrice &matrix)
{
	RowNode *head = new RowNode;
	head->indexI = -1;
	head->head = NULL;
	head->next = NULL;

	if (matrix.values)
	{
		for (unsigned indexI = 0u; indexI < matrix.rows; indexI++)
		{
			bool isEmpty = true;
			for (unsigned indexJ = 0u; indexJ < matrix.cols; indexJ++)
				if (at(matrix, indexI, indexJ)) {
					isEmpty = false;
					break;
				}
			if (!isEmpty)
			{
				addToTail(head, indexI);
				buildRow(matrix, head);
			}
		}
	}
	return head;
}

void printSparseMatrix(RowNode *head)
{
	RowNode *crt = head;
	while (crt->next)
	{
		crt = crt->next;
		cout << "Linia " << crt->indexI << ": ";
		Node *lineCrt = crt->head->next;
		while (lineCrt->next)
		{
			cout << "(" << lineCrt->indexJ << ", " << lineCrt->data << ") ";
			lineCrt = lineCrt->next;
		}
		cout << "(" << lineCrt->indexJ << ", " << lineCrt->data << ") ";
		cout << endl;
	}
}

int query(RowNode* head, const unsigned &indexI, const unsigned &indexJ) {
	RowNode *crt = head;
	while (crt->next) {
		crt = crt->next;
		if (crt->indexI != indexI)
			continue;
		Node *lineCrt = crt->head;
		while (lineCrt) {
			if (lineCrt->indexJ == indexJ)
				return lineCrt->data;
			lineCrt = lineCrt->next;
		}
	}
	return 0;
}

int rows(RowNode *sparseMatrix) {
	if (sparseMatrix) {
		while (sparseMatrix->next)
			sparseMatrix = sparseMatrix->next;
		return sparseMatrix->indexI + 1;
	}

	return 0;
}

int cols(RowNode *sparseMatrix) {
	if (sparseMatrix) {
		int max = 0;
		while (sparseMatrix->next) {
			sparseMatrix = sparseMatrix->next;
			Node *rowHead = sparseMatrix->head;
			if (!rowHead) continue;
			while (rowHead->next)
				rowHead = rowHead->next;
			if (rowHead->indexJ > max)
				max = rowHead->indexJ;
		}
		return max + 1;
	}
	return 0;
}

inline int max(const int a, const int b) {
	if (a > b)
		return a;
	else
		return b;
}

RowNode* add(RowNode *mat1, RowNode *mat2) {
	if (!mat1 && !mat2)
		return NULL;

	Matrice result;
	result.cols = max(cols(mat1), cols(mat2));
	result.rows = max(rows(mat1), rows(mat2));

	if (!(result.values = new int[result.rows*result.cols]))
		throw "Nu s-a alocat corect";
		
	for (int i = 0; i < max(rows(mat1), rows(mat2)); i++)
		for (int j = 0; j < max(cols(mat1), cols(mat2)); j++)
			at(result, i, j) = query(mat1, i, j) + query(mat2, i, j);

	return buildMatrix(result);
}

int main() {
	Matrice mat1, mat2;
	mat1.values = NULL;
	mat2.values = NULL;

	
	readMatrix(mat1);
	readMatrix(mat2);

	
	RowNode* matrix1 = buildMatrix(mat1);
	RowNode* matrix2 = buildMatrix(mat2);

	
	RowNode *result = add(matrix1, matrix2);

	
	printSparseMatrix(result);

	deleteList(matrix1);
	deleteList(matrix2);
	delete[] mat1.values;
	delete[] mat2.values;

	system("pause");
}
