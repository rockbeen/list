#include <iostream>
using namespace std;

template <class T>
struct item
{
	T data;
	item* next;
	};
template <class T>
class list
{
	private:
		item<T>* first;
		int size()//the size
		{
			item<T>* current=first;
			int i=0;
			while(current!=NULL)
			{
				i++;
				current=current->next;
		
				}
			return i;
			}
	public:
		
		list()
		{first=NULL;}
		~list();
		list(const list & );//Default Constructor
		void add_item(T );
		void display();
		void delete_item_end();
		void add_item_end(T);
		void show_size();
		void delete_item_first();
		void display_first();
		void display_last();
		void deleting_equals(T d);
		list<T>& operator=(const list<T>& );
	};
template <class T>
void list<T>::add_item(T d)//add to top of list
{
	
	item<T>* newitem= new item<T>;
	newitem->data=d;
	newitem->next=first;
	first=newitem;
	
	}
template <class T>
void list<T>::add_item_end(T d)//add to end of list
{
	int i=size();
	item<T>* current=first;
	while(i>1)
		{
			i--;
			current=current->next;
		
		}
	
	item<T>* newitem= new item<T>;
	newitem->data=d;
	current->next=newitem;
	newitem->next=NULL;


	
	}
template <class T>
void list<T>::delete_item_end()//deleting to end of list
{
	item<T>* current=first->next;
	delete first;
	first=current;
	
	}
template <class T>
void list<T>::delete_item_first()//deleting the first element
{
	int i=size();
	item<T>* current=first;
	if (i==1)
	{	
		delete this;
	
		}
	else 
	{while(i>2)
		{	i--;
			current=current->next;
		}
		item<T>* current2=current->next;
		current->next=NULL;
		delete current2;
		}
	}	
/*template <class T>
void list<T>::display()
{
	
	item<T>* current=first;
	while(current!=NULL)
	{
		cout<<current->data<<endl;
		current=current->next;
		}
	}*/
template <class T> 
void list<T>::display_last()//Reading the last element
{

	cout<<first->data<<endl;

	}
template <class T> 
void list<T>::display_first()//Reading the first element
{
	
	item<T>* current=first;
	int i=size();
	while(i!=1)
		{
			i--;
			current=current->next;
		
		}
		cout<<current->data<<endl;
	}
template <class T> 
list<T>::~list()//Destructor
{
    item<T>* current=first;
	while(current!=NULL)
	{
		item<T>* current2=current->next;
		delete current;
		current=current2;
		
		}
   
}
template <class T> 
void list<T>::deleting_equals(T d)//Deleting all list items equal to the one passed
{
    item<T>* current=first;
	while(current!=NULL)
	{
		
		item<T>* current2=current->next;
		if (current2->data==d)
			{
				
			current->next=current2->next;
			delete current2;
			current=current->next;
			current=current->next;
			
			}
		else current=current2;
		
		}
   
}
template <class T> 
void list<T>::show_size()//Reading the size
{
	cout<<size()<<endl;	
	}
template <class T> 
list<T>::list(const list & other)//Copy Constructor
{

		item<T>* newitem= other.first;
		first=newitem;
	
	}

template <class T>
list<T>& list<T>::operator=(const list<T>& other)//Copy assignment operator
{
    item<T>* newitem= other.first;
	first=newitem;
    return *this;
}

 int main()
{
	
 return 0;
}

