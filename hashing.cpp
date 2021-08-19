#include <iostream>
using namespace std;

//hash class
class hash {
	// Private section
	const static int tableSize=10;
	//data item
	struct data{
		string name;
		int no;
		data* next;
	};
	
	//Data Table
	data *item[tableSize];

	
	
	public:
		// Public Declarations
		
		//Class's Constructor
	hash(){
		for(int i=0;i<tableSize;i++){
			item[i]=new data;
			item[i]->name="empty";
			item[i]->no=0;
			item[i]->next=NULL;
		}
	}
	//hash function
	int hashF(int key){
		return tableSize%key;
	}
	
	//add in the List
	void add(int no,string name){
		int index=hashF(no);
		
		if(item[index]->name== "empty"){
			item[index]->no=no;
			item[index]->name=name;
			
		}
		else{
			data *ptr= item[index];
			data *n= new data;
			n->no= no;
			n->name= name;
			n->next= NULL;
			
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=n;
		}
	}
	
	//print the list
	void printTable(){
		int count=0;
		
		for(int i=0;i<tableSize;i++){
		data *ptr= item[i];
		
			if(ptr->next!=NULL){
				while(ptr->next!=NULL){
				
					cout<<endl<<"	"<<ptr->no<<endl;
					cout<<"	"<<ptr->name<<endl;
					ptr=ptr->next;
				}
				//last struct
				cout<<endl<<"	"<<ptr->no<<endl;
				cout<<"	"<<ptr->name<<endl;
			}
			
			else{
				cout<<endl<<item[i]->no<<endl;
				cout<<item[i]->name<<endl;
			}
		}
	}
	
	//search the key
	void search(int key){
		
		int index= hashF(key);
		bool check= false;
		if(item[index]->name== "empty"){
			
			cout<<endl<<"Record Not Found!";
		}
		else{
			if(item[index]->next!= NULL){
				data *ptr= item[index];
		
				while(ptr->next!=NULL){
					if(ptr->no== key){
						check= true;
						break;
					}
					ptr=ptr->next;
				}
				if(check== true){
					cout<<"Record= "<<ptr->name;
					cout<<endl<<"Record Found!";
				}
				else if(ptr->no== key){
					cout<<"Record= "<<ptr->name;
					cout<<endl<<"Record Found!";
				}
				else if(ptr->no!= key){
					cout<<endl<<"Record Not Found!";
				}
			}
			else{
				cout<<"Record= "<<item[index]->name;
				cout<<endl<<"Record Found!";
			}
		}
	}
};



int main(){
	//creating object
	hash table1;
	
	//intializing the table
	
	table1.add(3,"H");
	table1.add(6,"J");
	table1.add(9,"K");
	table1.add(7,"H2");
	
	//print the table
	table1.search(7);
	
	return 0;
}

