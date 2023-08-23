#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<typename t>

class Stack_array_based{
private:
    t *a;
    int size;
    int top;
public:
    Stack_array_based(int size):size(size){
        top=-1;
        a=new t [size];
    }
    int Size(){return top+1;}
    void Reverse(){
        if(is_empty())return;
        int cur=pop();
        Reverse();
        insert_at_thebottom(cur);

    }
    void rev_rec(int tq){

        if(tq==-1)return;
        int q=a[tq];
        rev_rec(tq-1);
        cout<<q<<endl;
        insert_at_thebottom(q);

    }
    bool is_full(){

        return size-1==top;
    }
    bool push(t value){
        if(is_full())return false;
        a[++top]=value;

    }
    ~Stack_array_based(){
        delete[] a;
    }
    int pop(){
        if(top==-1)return false;
        return a[top--];
    }
    bool is_empty(){
        return top==-1;
    }
    void diplay(){
        while(top!=-1){
            cout<<a[top--]<<" ";
        }
        cout<<endl;
    }
    int reversed_num(){
        int q=0;
        for(int i=0;i<=top;i++){
            q*=10;
            q+=a[i];

        }
        return q;
    }
    void display_reversed(){
        for(int i=0;i<=top;i++)cout<<a[i]<<" ";
        cout<<endl;
    }
    int Top(){
        if(top!=-1)return a[top];
    }
    void clear(){
        if(top==-1)return;
        int d=top;
        for(int i=0;i<=d;i++)pop();
    }
    void insert_at_thebottom(int value){
        if(is_empty()){
            push(value);
        }
        else {
            int cur=pop();
            insert_at_thebottom(value);
            push(cur);
        }


    }
    void move_rec(int q){
        if(q==top+1)return;
        move_rec(q+1);
        a[q]=a[q-1];
    }
};

class an_arr_st{
private:
    int *a;
    int size;
    int top;
public:
    an_arr_st(int size):size(size){
        top=-1;
        a=new int [size];

    }
    bool push(int v){
        if(size-1==top)return 0;
        int te=a[0];
        for(int i=1;i<=top+1;i++){
            int tt=a[i];
            a[i]=te;
            te=tt;
        }
        a[0]=v;
        top++;
        return true;
    }

    bool pop(){
        if(top==-1)return false;
        for(int i=0;i<top;i++){
            a[i]=a[i+1];
        }
        top--;
        return true;
    }
    void print(){
        for(int i=0;i<=top;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

};
bool is_valid(string s){
    Stack_array_based<char> st(10000);
    for(int i=0;i<s.size();i++){
        if(st.is_empty())st.push(s[i]);
        else {
            if((s[i]==')'&&st.Top()=='(')||(s[i]=='}'&&st.Top()=='{')||(s[i]==']'&&st.Top()=='[')){
                st.pop();
            }
            else st.push(s[i]);
        }
    }
    return st.is_empty();
}

void remove_adjecnt(string s){
    Stack_array_based<char> st(10000);
    for(int i=0;i<s.size();i++){
        if(st.is_empty())st.push(s[i]);
        else {
            if(s[i]==st.Top()){
                st.pop();
            }
            else st.push(s[i]);
        }
    }
    st.display_reversed();
}
int reverse_num(int num){
    Stack_array_based<int>st(100);

    while(num){
        st.push(num%10);
        num/=10;
    }
    return st.reversed_num();
}
class Two_in_one_stack{
private:
    int size;
    int top1,top2;
    int *a;
public:
    Two_in_one_stack(int size):size(size){
        a=new int [size];
        top1=-1;
        top2=size;
    }
    void push(int id,int value){
        int q=size-top2-1;
        if(top2-top1<=1)return;
        if(id==1) {
            a[++top1] = value;
        }
        else if(id==2)a[--top2]=value;
    }
    void pop(int id){
        if(id==1)--top1;
        else if(id==2)++top2;
    }
    void display(){

        while(top1!=-1){
            cout<<a[top1--]<<' ';
        }
        cout<<endl;
        while(top2!=size){
            cout<<a[top2++]<<' ';
        }
        cout<<endl;
    }
    ~Two_in_one_stack(){
        delete[] a;
    }
};
void exploded(int *a,int n){   int c=0;
    Stack_array_based<int >stt(n);
    for(int i=0;i<n;i++){
        int x=a[i];
        bool is= false;


        while(c!=0&&x<0){
            int q=stt.Top();

            if(q<abs(x)){
                stt.pop();
                c--;
                continue;
            }
            else if(q== abs(x)) { stt.pop();
                c--;

            }
            is= true;
            break;

        }
        if(!is){
            stt.push(x);
            if(x>0)c++;
        }
    }
    stt.display_reversed();
}
Stack_array_based<int >sat(10);
int fac(int n){
    if(n==1)return 1;
    sat.push(1);
    return (n*fac(n-1))*sat.pop();

}
void Next_greater(int *a,int n){
    int N[100003]={0};
    Stack_array_based<int>stt(12);

    for(int i=0;i<n;i++){
        int x=a[i];
        while(!stt.is_empty()&&x>stt.Top()){
            N[stt.Top()]=x;
            stt.pop();
        }
        stt.push(x);
    }
    while (!stt.is_empty()){
        N[stt.pop()]=-1;
    }
    for(int i=0;i<n;i++){
        cout<<N[a[i]]<<" ";
    }
    cout<<endl;
}
int scoreOf_parentheses(string s) {
    Stack_array_based<int> st(s.size());
    int res = 0;
    int x;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(0);
        } else {
            x = st.pop();

            if (x == 0)x++;
            else x = x * 2;

            if (st.Size() < 1) {
                res += x;

            } else {
                int d = st.pop();
                d = d + x;

                st.push(d);
            }

        }
    }
    return res;
}
class Stack_linked_based{
private:
    struct Node{
        int data;
        Node *Next {};
        Node(int data):data(data){}
    };
    Node *head{nullptr};
public:
    void push(int value){
        Node *cur =new Node (value);
        cur->Next=head;
        head=cur;
    }
    bool is_empty(){return !head;}
    int pop(){
        assert(!is_empty());
        int element=head->data;
        Node *new_top=head->Next;
        delete head;
        head=new_top;
        return element;
    }
    int peek(){
        assert(!is_empty());
        return head->data;
    }
    void display(){
        for(Node *cur =head;cur!= nullptr;cur=cur->Next){
            cout<<cur->data<<" ";
        }
        cout<<endl;
    }
};
int evaluate_postfix(string str){
    long long res=0;
    Stack_array_based<int >st(12);
    for(int i=0;i<str.size();i++){
        char c=str[i];
        if(c>='0'&&c<='9'){
            int d=c-'0';
            cout<<c<<" "<<d<<endl;
            st.push(d);
        }
        else{
            if(c=='*'){
                int x=st.pop();
                int e=st.pop();
                st.push(e*x);
            }
            else if(c=='+'){
                int x=st.pop();
                int e=st.pop();
                st.push(e+x);
            }
            else if(c=='-'){
                int x=st.pop();
                int e=st.pop();
                st.push(e-x);
            }
            else if(c=='/'){
                int x=st.pop();
                int e=st.pop();
                st.push(e/x);
            }
        }
    }
    return st.pop();
}
bool less_o_e(char a,char b){
    if(a=='^'&&b=='^')return 0;
    if(a=='^')return 0;
    if(b=='^')return 1;
    if(a=='(')return 0;
    if(b=='(')return 0;
    if(a==b)return 1;
    if(a=='*'&&b=='/')return 1;
    if(a=='/'&&b=='*')return 1;
    if(a=='*')return 0;
    if(a=='/')return 0;
    if(a=='+'&&(b=='*'||b=='/'))return 1;
    if(a=='-'&&(b=='*'||b=='/'))return 1;
    return 1;

    ;}
string infix_to_posfix(string str){
    Stack_array_based<char >st(12);
    string op="";
    int x=0;
    int cc=0;
    string postfix="";
    for(int i=0;i<str.size();i++){
        char c=str[i];

        if(c>='0'&&c<='9'||c>='a'&&c<='z') {
            postfix += c;
        }
        else{
            if(c==')'){
                while(st.Top()!='('){
                    postfix+=st.pop();
                }
                st.pop();
            }
            else{
                while (!st.is_empty()&& less_o_e(c,st.Top())){
                    postfix+=st.pop();
                }
                st.push(c);
            }
        }

    }
    while (!st.is_empty()){
        postfix+=st.pop();
    }
    return postfix;
}
int precedence(char a) {
    if (a == '+' || a == '-')return 1;
    if (a == '*' || a == '/')return 2;
    if(a=='^')return 3;
}
int ledss(char a,char b){
    if(b==')')return 0;
    if(a==')')return 0;
    if(a=='^'&&b=='^')return 1;
    return precedence(a)< precedence(b);
}
string infix_to_prefix(string str){
    Stack_array_based<char >st(12);
    string op="";
    int x=str.size();
    int cc=0;
    string prefix="";

    for(int i=x-1;i<str.size();i--){
        char c=str[i];

        if(c>='0'&&c<='9') {
            prefix = c+ prefix;
        }
        else{
            if(c=='('){
                while(st.Top()!=')'){
                    char d=st.pop();
                    string q="";
                    q+=d;
                    prefix=q+prefix;
                }
                st.pop();
            }
            else{

                while (!st.is_empty()&& ledss(c,st.Top())){
                    char d=st.pop();
                    string q="";
                    q+=d;
                    prefix=q+prefix;

                }
                st.push(c);
            }
        }

    }
    while (!st.is_empty()){
        char d=st.pop();
        string q="";
        q+=d;
        prefix=q+prefix;
    }
    return prefix;
}
string remove_expression(string str){
    Stack_array_based<char>st(12);
    for(int i=0;i<str.size();i++){
        char c=str[i];
        if(c=='('&&i){
            if(st.is_empty()&&str[i-1]!='(')st.push(str[i-1]);
            else {


                if(!st.is_empty()){
                    char q=st.Top();
                    if(str[i-1]=='(')st.push(st.Top());
                    else  if(str[i-1]=='+'&&q=='-') { st.push('-') ;
                        str[i-1]='-';
                    }
                    else if(str[i-1]=='-'&&q=='-') { st.push('+') ;
                        str[i-1]='+';
                    }
                }


            }
        }
        else if(c==')')st.pop();
        else if(c=='-'||c=='+'){
            if(!st.is_empty()){
                char q=st.Top();

                if(str[i]=='+'&&q=='-'&&str[i+1]!='(')str[i]='-';
                else if(str[i]=='-'&&q=='-'&&str[i+1]!='(')str[i]='+';
            }

        }

    }
    return str;
}
int main() {
    Stack_array_based <int> st(10);
    st.push(4);
    st.push(33);
    cout<<st.is_empty()<<" "<<st.is_full()<<endl;
    st.push(32);
    st.push(321);
    cout<<st.is_full()<<endl;
    st.pop();
    cout<<st.is_full()<<endl;
    st.diplay();
    an_arr_st an(6);
    an.push(3);
    an.push(32);
    an.print();
    an.pop();
    an.push(323);
    an.print();
    Stack_array_based <char> st1(100);

    string s="zeyad rafat abdelaal";


    for(int i=0;i<s.size();i++){

        st1.push(s[i]);
        if(s[i]==' '){
            st1.diplay();
            st1.clear();
        }

    }
    st1.diplay();
    st1.clear();
    string g="abbaveddea";


    cout<<is_valid(g)<<endl;
    remove_adjecnt(g);
    int num=5245235;
    cout<<reverse_num(num)<<endl;
    Two_in_one_stack stt(12);
    stt.push(1,2);
    stt.push(1,3);
    stt.push(1,2);
    stt.push(1,3);
    stt.pop(1);
    stt.push(1,22);
    stt.push(2,3);
    stt.push(2,4);
    stt.push(2,44);
    stt.display();
    int a []={10,9,4,-6,2,5,-20};
    exploded(a,7);
    st.push(33);
    st.push(13);
    cout<<st.is_empty()<<endl;
    st.insert_at_thebottom(400);
    st.diplay();

    st.insert_at_thebottom(324);
    st.insert_at_thebottom(23);
    st.push(32);
    st.diplay();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.Reverse();
    st.diplay();
    cout<<fac(4)<<endl<<sat.is_empty()<<endl;
    int aa[]={32,90,3,12,80};
    Next_greater(aa,5);
    string gg="()((()))";
    cout<<scoreOf_parentheses(gg)<<endl;
    Stack_linked_based sta;
    sta.push(3);
    sta.push(23);
    sta.push(211);
    cout<<sta.is_empty()<<endl;
    sta.display();
    string ss="1234+*+82/-";
    cout<<evaluate_postfix(ss)<<"s"<<endl;
    string dd="1+3*5-8/2";
    long long q=1+3*5-8/2;
    cout<<q<<endl;
    string ggg=infix_to_posfix(dd);

    cout<<ggg<<endl;cout<<infix_to_prefix(dd)<<endl;
    string exp="1-((4+5)-(6-7)))";
    string pp= remove_expression(exp);
    for(int i=0;i<pp.size();i++)if(pp[i]!='('&&pp[i]!=')')cout<<pp[i];
    cout<<endl;
    return 0;

}
