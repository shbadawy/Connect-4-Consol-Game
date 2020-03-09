#include<iostream>

using namespace std;
//////////////////////////////
///////Linked List Class//////
//////////////////////////////

class linked_list{

public:
    linked_list(int i) {

            //thisfirst=this;
            linked_list *nitem=new linked_list();
            linked_list *movingLast=NULL;
            this->set_next(nitem);
            nitem->set_pre(this);
            this->last=nitem;
            ptr=this;
            /////////////////////////
            this->numberOfObject=i;

            for (int i=1;i<5;i++){

                    nitem=new linked_list();
                    movingLast=this->last;
                    movingLast->set_next(nitem);
                    nitem->set_pre(movingLast);
                    movingLast=movingLast->get_next();
                    this->last=movingLast;

            }

    }//constructor #1

    linked_list(){}//constructor #2

    //getters
    char get_item(){return item;}
    linked_list *get_next(){return next;}
    linked_list *get_pre(){return pre;}
    linked_list *get_prt(){return ptr;}
    linked_list *get_r(){return r;}
    linked_list *get_l(){return l;}

    //setters
    void set_item(char i){item=i;}
    void set_next(linked_list *i){next=i;}
    void set_pre(linked_list *i) {pre=i;}
    void set_ptr(linked_list *i) {ptr=i;}
    void set_r(linked_list *i) {r=i;}
    void set_l(linked_list *i) {l=i;}
    //functions
    void add (char i);
    bool isEmpty();

private:
    char item=' ';
    linked_list *next=NULL;
    linked_list*pre=NULL;
    linked_list *last=NULL;
    linked_list *ptr=NULL;
    linked_list *r=NULL;
    linked_list *l=NULL;
    int numberOfObject;

    };

void linked_list ::add(char i){
    linked_list *p=this->last;
          p->set_item(i);
          p=p->get_pre();
          this->last=p;
        }
 bool linked_list :: isEmpty(){
     if (last==NULL)return false;
     return true;
     }
     linked_list *fnd (int i);

/////////////////////////////
////functions prototype//////
/////////////////////////////
void display();
void printLine () ;
void printSides();
void connect();
bool check (int col);
bool checkV (linked_list *col);
bool checkH (linked_list *col );

/////////////////////////////
////Global VAr.//////
linked_list c1(1);
linked_list c2(2);
linked_list c3(3);
linked_list c4(4);
linked_list c5(5);
linked_list c6(6);
linked_list c7(7);
//////////////////////////////
///////////////Main///////////
/////////////////////////////
int main()
{
    connect();
	display();//Displays for first time so players can see the board
	int hold,charsPlaced = 0;//Will house user row choice
	bool gamewon = false;//Will be changed to true when game is won and will exit while loop
	char player = 'O';

	while(!gamewon){

        if(charsPlaced == 42) break;//if draw
        if(player == 'O'){//if player 2 lasted dropped a piece so its player 1s turn
				cout<<"player 1 drop where?\n";
			}
			else{
				cout<<"player 2 drop where?\n";
			}
		 A1:cin>>hold;//get user input
         if (cin.fail())	//catch a non number
			{						//
				cin.clear();		//Stops cin trying to put its value in to hold
				goto A1;		//
			}						//Catch a non number

            while (hold <1 || hold >7 ){cout<< "not Valid Number!\nplease enter a value between 1 and 7 :";cin>>hold;}
            switch(hold){

                case 1:
                if (!c1.isEmpty()){cout << "The Column Is Full, Please Enter Another Number :D\n";goto A1;}
                c1.add(player);
                break;
                case 2:
                if (!c2.isEmpty()){cout << "The Column Is Full, Please Enter Another Number :D\n";goto A1;}
                c2.add(player);
                break;
                case 3:
                if (!c3.isEmpty()){cout << "The Column Is Full, Please Enter Another Number :D\n";goto A1;}
                c3.add(player);
                break;
                case 4:
                if (!c4.isEmpty()){cout << "The Column Is Full, Please Enter Another Number :D\n";goto A1;}
                c4.add(player);
                break;
                case 5:
                if (!c5.isEmpty()){cout << "The Column Is Full, Please Enter Another Number :D\n";goto A1;}
                c5.add(player);
                break;
                case 6:
                if (!c6.isEmpty()){cout << "The Column Is Full, Please Enter Another Number :D\n";goto A1;}
                c6.add(player);
                break;
                 case 7:
                if (!c7.isEmpty()){cout << "The Column Is Full, Please Enter Another Number :D\n";goto A1;}
                c7.add(player);
                break;
            }//switch
            display();
            gamewon=check(hold);
            if (!gamewon){
                
            charsPlaced++;
            if(player == 'O')player = '@';
			else player = 'O';
                
            }
        
		}//while


	if(charsPlaced == 42)
		cout<<"No winner, Game was draw\n";
    else if (gamewon){
        
      if (player == 'O')cout << "Player 1 WON !\n"    ;
      else {cout << "Player 2 WON!\n";}
        
    }
}//main
///////////////////////////
////Display Functions//////
void display(){
    for (int i= 1; i <=7 ; i++){
        for (int j = 0 ; j < 4 ;j++)
            cout << " ";
        cout << i;
        for (int j = 0 ; j < 4 ;j++)
            cout << " ";


}
cout <<endl;

    for (int i = 1 ; i <=6;i++){
      printLine();
      printSides();
    }
    c1.set_ptr(&c1);
        c2.set_ptr(&c2);
        c3.set_ptr(&c3);
        c4.set_ptr(&c4);
        c5.set_ptr(&c5);
        c6.set_ptr(&c6);
        c7.set_ptr(&c7);

}//display fun


void printLine () {
        for (int j = 0 ; j < 7;j++){
            cout << " ";
            for (int i = 0 ; i<7; i++){
            cout <<"_";
            }
            cout << " ";
        }
        cout << endl;
}//printLine

void printSides(){
        for (int j = 0 ;j < 7 ; j ++){
            cout <<"|";
            for (int i = 0 ;i<7;i++)cout <<" ";
            cout <<"|";

        }
        cout <<endl;

        linked_list *cRowPtr=NULL;
        for (int j = 1 ;j <= 7 ; j ++){
            cout <<"|";
            for (int i = 0 ;i<3;i++)cout <<" ";
            switch (j){

                    case 1:
                    cRowPtr=c1.get_prt();
                    c1.set_ptr(cRowPtr->get_next());
                    break;
                    case 2:
                    cRowPtr=c2.get_prt();
                    c2.set_ptr(cRowPtr->get_next());
                    break;
                    case 3:
                    cRowPtr=c3.get_prt();
                    c3.set_ptr(cRowPtr->get_next());
                    break;
                    case 4:
                    cRowPtr=c4.get_prt();
                    c4.set_ptr(cRowPtr->get_next());
                    break;
                    case 5:
                    cRowPtr=c5.get_prt();
                    c5.set_ptr(cRowPtr->get_next());
                    break;
                    case 6:
                    cRowPtr=c6.get_prt();
                    c6.set_ptr(cRowPtr->get_next());
                    break;
                    case 7:
                    cRowPtr=c7.get_prt();
                    c7.set_ptr(cRowPtr->get_next());
                    break;
            }
            cout<<cRowPtr->get_item();
            for (int i = 4 ;i<7;i++)cout <<" ";
            cout <<"|";

        }
        cout <<endl;
        for (int j = 0 ;j < 7 ; j ++){
            cout <<"|";
            for (int i = 0 ;i<7;i++)cout <<"_";
            cout <<"|";

        }
        cout <<endl;

}//printSides fun

void connect(){
linked_list *element;//first column
linked_list *element2;//second
 for (int i=1; i<7; i++ )
 {
  element=fnd(i);
  element2=fnd(i+1);
  while (element!= NULL){

            element->set_r(element2);
            element2->set_l(element);
            element=element->get_next();
            element2=element2->get_next();

}

         }
}//end fun


    //////////////////

linked_list *fnd (int i)
{

    switch (i){

    case 1:
    return &c1;
    break;

    case 2:
    return &c2;
    break;

    case 3:
    return &c3;
    break;

    case 4:
    return &c4;
    break;

    case 5:
    return &c5;
    break;

    case 6:
    return &c6;
    break;

    case 7:
    return &c7;
    break;

    default :
    return NULL;
    }

}

bool check (int col){
   linked_list *colPtr= fnd(col);
   if (!checkV(colPtr)) {
       
      if (!checkH(colPtr)){
          
         return false;  
          
      }
        else return true;
       
    }
    else return true;
    
}

bool checkV (linked_list *col){
        unsigned int counter =0;
        char c;
        while (col != NULL && counter != 4){
            
            if (col->get_item() == ' ')col=col->get_next();
            else if (counter == 0 ){c=col->get_item(); col=col->get_next();counter++;}
            else if (col->get_item()==c){counter++; col=col->get_next();}
            else if (col->get_item()!=c){counter=1; c=col->get_item();col=col->get_next();}
        
        }
        
        if (counter == 4){return true;}
        return false;
    
}

bool checkH (linked_list *col ){
        unsigned int counter =0;
        char c;
        while (col->get_item() == ' ' )col=col->get_next();
        while (col->get_l()!= NULL)col=col->get_l();
        while (col != NULL && counter != 4){
                if (col->get_item() == ' '){col=col->get_r();counter=0;}
                else if (counter==0){c=col->get_item(); col=col->get_r();counter++;}
                else if (col->get_item()==c){counter++; col=col->get_r();}
                else if (col->get_item()!=c){counter=1; c=col->get_item();col=col->get_r();}
            
        }
        if (counter == 4)return true;
        return false;
}















