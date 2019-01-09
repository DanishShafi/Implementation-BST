#include<iostream>
#include<conio.h>
#include<stdlib.h>
/* .............Insertion & search in BST .........*/
using namespace std;

struct Node{
	int info;
	Node *right, *left;
};
class BST{
	private:
		Node *temp;
	public:
		Node *root;
		int num;
		BST()
		{
			root=NULL;
			temp=NULL;
		}
		void search(Node *)
		{
			if(root==NULL)
			{
				temp=new Node();
				temp->info=num;
				temp->right=NULL;
				temp->left=NULL;
				root=temp;
				return;
			}
			if(temp->info==num)
			{
				cout<<"The value you enter is already exists"<<endl;
			}
			// For greater numm value
			if(temp->info < num)
			{
				if(temp->right != NULL)
				{
					search(temp->right);
					return ;
				}
				else
				{
					temp->right=new Node();
					temp->right->info=num;
					temp->right->left=NULL;
					temp->right->right=NULL;
					return;
				}
			}
			// For lesser num value
			if(temp->info > num)
			{
				if(temp->left != NULL)
				{
					search(temp->left);
					return ;
				}
				else
				{
					temp->left= new Node();
					temp->left->info=num;
					temp->left->left=NULL;
					temp->left->right=NULL;
					return ;
				}
			}	
		}
		
		void options()
		{
			cout<<"Select the following options"<<endl;
			cout<<"1: Insert the values"<<endl;
			cout<<"2: Print the values"<<endl;
			cout<<"3: Quit the program"<<endl;
		}
		void in_order(Node *)
		{
			if(root==NULL)
			{
				cout<<"The tree is empty"<<endl;
			}
			if(temp->left!=NULL)
			{
				in_order(temp->left);
				cout<<temp->info<<" ";
			}
			if(temp->right!=NULL)
			{
				in_order(temp->right);
				cout<<temp->info<<" ";
			}
			return;
		}
};

int main(){
	
	char ch;
	BST b;
	while(4)
	{
		b.options();
		ch= getch();
		switch(ch)
		{
			case'1':
				//clrscr();
				cout<<"Enter the value for insert"<<endl;
				cin>>b.num;
				b.search(b.root);
				break;
			case '2':
				//clrscr();
				b.in_order(b.root);
				break;
			case '3':
				exit(0);
				break;
				
			default:
				exit(0);
				break;
		}
	}

	
}
