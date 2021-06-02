//addition of 2 numbers stored in linked list
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node*next;
};
struct Node* build_list(int n)
{
 struct Node* final_head;
      struct Node* final_temp;
      final_head=NULL;
      final_temp=NULL;
      for(int i=0;i<n;i++)
      { int x;
          struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
          cin>>x;
          newnode->data=x;
          newnode->next=NULL;
          if(final_head==NULL)
          {
              final_head=newnode;
              final_temp=newnode;
          }
          else{
              final_temp->next=newnode;
              final_temp=final_temp->next;
          }
      }
      return final_head;
}
 struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        vector<int>a,b;
      struct Node* temp1,*temp2;
      temp1=first;
      temp2=second;
      while(temp1!=NULL)
      {
          a.push_back(temp1->data);
          temp1=temp1->next;
      }
        while(temp2!=NULL)
      {
          b.push_back(temp2->data);
          temp2=temp2->next;
      }
      int i=a.size()-1;
      int j=b.size()-1;
      vector<int>final;
      int rem=0;
      int sum=0;
      while(i>=0 && j>=0)
      {
          sum=a.at(i)+b.at(j)+rem;
          rem=sum/10;
          final.push_back(sum%10);
          i--;
          j--;
      }
      if(i>=0)
      {
          while(i>=0)
          {
          sum=a.at(i)+rem;
          rem=sum/10;
          final.push_back(sum%10);
          i--;
          }
          if(rem>0)
         final.push_back(rem);
      }
     else if(j>=0)
      {
           while(j>=0)
          {
          sum=b.at(j)+rem;
          rem=sum/10;
         final.push_back(sum%10);
          j--;
          }
          if(rem>0)
          final.push_back(rem);
      }
      reverse(final.begin(),final.end());
      struct Node* final_head;
      struct Node* final_temp;
      final_head=NULL;
      final_temp=NULL;
      for(int i=0;i<final.size();i++)
      {
          struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
          newnode->data=final.at(i);
          newnode->next=NULL;
          if(final_head==NULL)
          {
              final_head=newnode;
              final_temp=newnode;
          }
          else{
              final_temp->next=newnode;
              final_temp=newnode;
          }
      }
      return final_head;

    }
void print_list(struct Node* head)
{
    	struct Node* tail;
    	tail=head;
    	while(tail!=NULL)
    	{
    		cout<<tail->data<<" ";
    		tail=tail->next;
		}
		return;
}
int main()
{
	int n,m;
	cout<<"Enter the size of the first and second linked list: ";
cin>>n>>m;
struct Node* head1=build_list(n);
struct Node* head2=build_list(m);
struct Node* final_head=addTwoLists(head1,head2);
print_list(final_head);
return 0;
}
