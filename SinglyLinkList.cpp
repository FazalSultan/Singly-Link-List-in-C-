#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Singly_Link_List{
    private:
        struct Node{
            int value;
            Node* next;
        };
    public:
        Node* head, *Current, *Temp, *Temp_Iterator;
        static int Count_Nodes;
        Singly_Link_List(){
            head =Current = Temp = Temp_Iterator = nullptr;
        }

        // The Add_Node ALways Add New Node to the Start Of the Link-List...
        /*
            void Add_Nodes(int Insert_Value){
            if(head == nullptr){
                head = new Node;
                head->value = Insert_Value;
                head->next = nullptr;
                Count_Nodes +=1;
                return;
            }else {
                Node* Runtime_Node_Creation = new Node;
                Runtime_Node_Creation->value =Insert_Value;
                Runtime_Node_Creation->next =head;
                head = Runtime_Node_Creation;
                Count_Nodes +=1;
                return;
            }
        }
        */
        

        // This Add_Node_To_End Will Add New Nodes After the Already inserted node...
        void Add_Node_to_End(int Node_End_Side){
            if(head == nullptr){
                head = new Node;
                head->value = Node_End_Side;
                head->next = nullptr;
                Temp =head;
                return;
            }else{
                Current =new Node;
                Current->value = Node_End_Side;
                Current->next =  nullptr;
                Temp->next =Current;
                Temp = Temp->next;
                return;
            }
        }

        void Printing_Link_List(){
            // If no Node in List & user Call It Mistakenly...
            if(head == nullptr){
                cout<<"List Is Empty, please Insert Some Nodes to Print on Console.."<<endl;
                return;
            }
            cout<<"The Link-List Is: ";
            Temp = head;
            while( Temp != nullptr){
                cout<< Temp->value << " ";
                if(Temp->next == nullptr){
                    Temp =nullptr;
                    return;
                }else{
                    Temp = Temp->next;
                }
            }
        }
        // The Delete_node Method Will Delete any Node from the List If found else it will Print A message if Not Found...
        void Delete_Node(int Del_Value){
            // If no Node in List & user Call It Mistakenly...
            if(head == nullptr){
                cout<<"List Is Empty, Therefore We Are unabale to Delete the Node..."<<endl;
                return;
            }
            Temp = head;
            // If Node Found At Start...
            if(Temp->value == Del_Value){
                cout<<"Bruh, Node Found At the Start of the List"<<endl;
                head = Temp->next;
                delete Temp;
                Printing_Link_List();
                Count_Nodes -=1;
                return;
            }
            // if found at Any other location...
            while(Temp->next != nullptr){
                if(Temp->next->value == Del_Value){
                    Current = Temp->next;
                    Temp->next = Current->next;
                    delete Current;
                    Printing_Link_List();
                    Count_Nodes -=1;
                    return;
                }else{
                    Temp =Temp->next;
                }
            }
            cout<<"Node not Found to Delete..."<<endl;

        }

        void Search_Node(int Search_Value){
            if(Count_Nodes <= 0){
                cout<<"Can't Search, Beacuse the List is Empty..."<<endl;
                return;
            }
            Temp=head;
            if(Temp->value == Search_Value){
                cout<<"The Search value Is Found AT Start, And the Value Is: "<<Temp->value;
                return;
            }
            while(Temp->next != nullptr ){
                if(Temp->value == Search_Value){
                    cout<<"The Search value Is Found, And the Value Is: "<<Temp->value;
                    return;
                }else{
                    Temp = Temp->next;
                    if(Temp->value== Search_Value && Temp->next == nullptr){
                        cout<<"The Search value Is Found At End, And the Value Is: "<<Temp->value<<endl;
                        return;
                    }
                }
            }
            cout<<"the Search Value Not Found in List..."<<endl;
        }

        int Length_list(){
            return Count_Nodes;
        }
};
int Singly_Link_List ::Count_Nodes =0;
int main(){
    Singly_Link_List Singly_Obj;
    for(int i =1 ; i<=5; i++){
        Singly_Obj.Add_Node_to_End(i);
    }
        Singly_Obj.Printing_Link_List();

        // cout<<"The Length is: "<< Singly_Obj.Length_list()<<endl;
        // Singly_Obj.Delete_Node(9);
        // Singly_Obj.Search_Node(2);
  


    return 0;
}