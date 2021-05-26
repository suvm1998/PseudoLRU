#include<bits/stdc++.h>
using namespace std;
class Node{
	public: int side;//1->right, 0->left;
	Node* right;Node* left;
	Node(){
		right = left = NULL;
		side=2;
	}
};
class tree{
	public: Node* r;int bus;
	void build_memory(Node* root, int size_bits){
		if(size_bits==0){
			return;
		}
		root->left = new Node;
		root->right = new Node;
		build_memory(root->left, size_bits-1);
		build_memory(root->right, size_bits-1);	
		
	}
//Constructor
	tree(int bus_size){
		r = new Node;
		bus = bus_size;
		Node* temp = r;
		//Build Memory pow(2, bus_size) wide
		build_memory(temp, bus_size);
	}

	void config(int address, int bus_size){
		//Address(int)->Address(bool)
		stack<int>s;
		while(s.size()!= bus_size){
			s.push(address%2);
			address = address/2;
		}
		Node* temp = r;
		//If 
		while(!s.empty()){
			int top = s.top();s.pop();
			//1->right, 0->left;
			temp->side = top ? 0:1;
			temp = top? temp->left : temp->right;
		}
	}
	void config_mem(int bus_size, int addr){
		for(int i=0; i< pow(2, bus_size); i++){
			config(i, bus_size);
		}
		config(addr, bus_size);
	}
	void printLRU(){
		Node* temp = r;int cnt = 0;
		while(temp->left!=NULL || temp->right!=NULL){
			if(temp->side==2){
				while(cnt!=bus){
					cout<<"x";
					cnt++;
				}
				break;
			}
			cout<<temp->side;cnt++;
			temp = temp->side?temp->right : temp->left;
		}
	}
};

int main(){
	tree t(3);
	int addr = 6;
	t.config_mem(3, addr);
	t.printLRU();
}
