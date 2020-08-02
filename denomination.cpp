#include<bits/stdc++.h>

using namespace std;

int main()

{

int tickets_needed,persons,position;

cout<<"Enter the number of persons: ";

cin>>persons;

cout<<"Enter your starting position in line: ";

cin>>position;

position -=1;

int cp = position;

  cout<<"Enter the number of tickets each person wants to buy (12 or less): ";

queue<int> ticket_array;

for(int i=0;i<persons;i++){

int tickets;

cin>>tickets;

ticket_array.push(tickets);

if(i==position){

tickets_needed = tickets;

}

}

int time = 0;

while(tickets_needed!=0){

if(cp==0){

tickets_needed-=1;

time+=1;

if(tickets_needed==0){

break;

}

else{

ticket_array.pop();

ticket_array.push(tickets_needed);

cp = ticket_array.size()-1;

}

}

else{

time+=1;

cp-=1;

int v = ticket_array.front();

if(v-1==0){

ticket_array.pop();

}

else{

ticket_array.pop();

ticket_array.push(v-1);

}

}

}

cout<<time<<" minutes";

  return 0;

}