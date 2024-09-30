#include <fstream>
#include <iostream>
#include <algorithm>
#include <stack>

#include "ArgumentManager.h"

using namespace std;

struct content{
  string command;
  string lineData;
};

void insert(stack<string> st, string command){
  st.push(command);
}

void deleteCommand(stack<string> st, string command){
  string top = st.top();
  if(top == command){
    st.pop();
  }
}

int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);

  string input = am.get("input");
  string output = am.get("output");

  ifstream inputfile(input);
  ofstream outputfile(output);

  stack<string> s;
  stack<string> sCommands;
  
  string line;
  string text;
  //int index = 0;

  while (getline(inputfile, line)){
    line.erase(remove(line.begin(), line.end(), '\n'), line.end());
    line.erase(remove(line.begin(), line.end(), '\t'), line.end());
    line.erase(remove(line.begin(), line.end(), '\r'), line.end());
   

    string typeCommand = line.substr(0, line.find(" "));
    //cout << line << endl;
    //cout << typeCommand << endl;
    if(typeCommand == "Insert"){//insert //insert = push
      sCommands.push(line);
      
      line = line.substr(7); //remove command & space
      //cout << line << endl;
      
      string command = line.substr(1, line.length()-2);
      //cout << command << endl;
        
        if(text.empty()){
          text = command;
        } else{
          text = text + " " + command;
        }
       
      s.push(command);
      
    } else if(typeCommand == "Delete"){//delete //delete = top or pop
        sCommands.push(line);
        line = line.substr(7); //remove command & space
        //cout << line << endl;
        
        string command = line.substr(1, line.length()-2);
        //cout << command << endl;
    
      size_t pos = text.find(command);
      if(pos != string::npos){
        text.erase(pos, text.length()+1);
      } 
      
       string top = s.top();
       if(top == command){
          deleteCommand(s, command);
       } else{
         sCommands.pop();
       }

      
    } else{//undo // undo = pop
      if(!sCommands.empty()){
        string lastTop = sCommands.top();
        sCommands.pop();

        if(lastTop.substr(0, 6) == "Delete"){
          //sCommands.push(line);

            lastTop = lastTop.substr(7); //remove command & space
          //cout << line << endl;

          string command = lastTop.substr(1, lastTop.length()-2);
          //cout << command << endl;

            if(text.empty()){
              text = command;
            } else{
              text = text + command;
            }

          s.push(command);
        } else if(lastTop.substr(0, 6) == "Insert"){
          //sCommands.push(line);
              lastTop = lastTop.substr(7); //remove command & space
            //cout << line << endl;

            string command = lastTop.substr(1, lastTop.length()-2);
            //cout << command << endl;

          size_t pos = text.find(command);
          if(pos != string::npos){
            text.erase(pos, text.length()+1);
          } 

           string top = s.top();
           if(top == command){
              deleteCommand(s, command);
           } else{
             //sCommands.pop();
           }
        }
      }
    }

  }
  outputfile << text << endl;
  cout << text << endl;
}