#ifndef __LinkedList_H__
#define __LinkedList_H__
#include "Tools.h" //Iostream & Typedef

template<class TYPE>
struct NodeList //Struct: everything is public (by default)
{	
	NodeList<TYPE>* Prev = NULL; 
	NodeList<TYPE>* Next = NULL; 

	TYPE Data; //Public

	NodeList(const TYPE& Data): Data(Data){} //Constructor
	//Destr is created by default
};


template<class TYPE>
class List
{
public:
	NodeList<TYPE>* Start = NULL;
	NodeList<TYPE>* End = NULL;

	//Erase END and do it another time (start private and getstart (torna punter constant)

	List(){} //Constructor
	~List(){ Clear2(); } //Constructor

	void PushBack(const TYPE& Data) //PushBack
	{
		ListNode<TYPE>* NewNode = new NodeList<TYPE>(Data);

		if (Start!= NULL)
		{
			End->Next = NewNode;
			NewNode->Prev = End;
			End = NewNode;
		}
		else
			Start = End = NewNode;
	}

	bool Empty() const //CheckEmpty
	{
		return Start == NULL;
	}

	void Clear() //Clear
	{
		NodeList<TYPE>* Tmp = End;

		for (uint i = Size(); i > 0; i--)
		{
			Tmp = Tmp->Prev;
			delete Tmp->Next;
		}
		Start = End = NULL;
	}

	void Clear2() //Option 2
	{	
		if (Start != NULL)
		{
			NodeList<TYPE>* Tmp1 = Start;
			NodeList<TYPE>* Tmp2;

			while (Tmp1 != NULL)
			{
				Tmp2 = Tmp1->Next;
				delete Tmp1;
				Tmp1 = Tmp2;
			}
		}
		Start = End = NULL;
	}

	uint Size() const //Size
	{
		NodeList<TYPE>* Tmp = Start;
		uint Ret = 0;

		while (Tmp)
		{
			++Ret;
			Tmp = Tmp->Next;
		}
		return Ret;
	}
};
#endif //__LinkedList_H__

//NEXT DAY: 
/*

-front() un get del start (tornen nodes constants)
-back() un get de l'ultim
-popback(tornen el qe sa eliminat)
-popfront (que torni el valor que s'ha eliminat)
-remove agafa un node i el treu (no retornem la data que eliminem)

*/