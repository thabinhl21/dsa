#include <arithmeticExpression.h>
#include <stack>
#include <fstream>
#include <sstream>

arithmeticExpression::arithmeticExpression(const string &expr)
{
    infixExpression = expr;
}

void arithmeticExpression::buildTree()
{
    stack<TreeNode> tree;
    infixExpression = infix_to_postfix(); //converts infix to postfix
    char key = 'a';
    for (unsigned i = 0; i < infixExpression.size(); ++i) //loop through postfix
    {
        if (infixExpression.at(i) != ' ') //ignore spaces
        {
            tree.push(TreeNode(infixExpression.at(i), key)); //create node with value and key and add it to tree stack
            if (key == 'a') //if key is a, node is root
            {
                root = &tree.top();
            }
            ++key; //increment key
        }
    }
}

void arithmeticExpression::infix()
{
    infix(root);
}

void arithmeticExpression::prefix()
{
    prefix(root);
}

void arithmeticExpression::postfix()
{
    postfix(root);
}

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void arithmeticExpression::infix(TreeNode *Node)
{
    if (root != nullptr)
    {

    }
}

void arithmeticExpression::prefix(TreeNode *Node)
{

}

void arithmeticExpression::postfix(TreeNode *Node)
{

}

void arithmeticExpression::visualizeTree(ofstream &file, TreeNode *root)
{

}