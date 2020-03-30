
#include <stdexcept>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <iostream>       // std::cout
#include <exception>
#include <bits/stdc++.h>
#include "PhoneticFinder.hpp"

using namespace std;


char letters[12][2]={{'v','w'},{'b','f'},{'b','p'},{'f','p'},
{'g','j'},{'c','k'},{'k','q'},{'c','q'},{'s','z'},{'d','t'},
{'o','u'},{'i','y'}};

int ind,wordSize,textSize;
bool over=false;
char text[100],word[100],answer[100];



struct oops : std::exception {
   string what()  noexcept 
  {return "Did not find the word '"+phonetic::convertToString(word,wordSize)+"'\n";}
};

using namespace phonetic;


namespace phonetic{

string convertToString(char* a, int size){
 
    int i; 
    string s = ""; 
    for (i = 0; i < size; i++) { 
        s = s + a[i]; 
    } 
    return s; 
} 


bool compareLen(){
    int j=ind;
    int size=0;
    while(j<textSize && text[j]!=' '){
        size++;
        j++;
    }
    //printf("size is %d\n",size);
    if(wordSize==size){
        //printf("wordsize==size\n");
        return true;
    }
    else
        return false;
}


bool compareLetters(int c, int ind){
    //printf("start of compare letters\n");
    char w=tolower(word[c]);
    char t=tolower(text[ind]);
    //printf("w is %c\n",w);
                printf("t is %c\n",t);
    if(w==t)
    return true;
    else{
        for(int i=0;i<12;i++){
                if((w==letters[i][0] && t==letters[i][1])||
                (w==letters[i][1] && t==letters[i][0])){
                return true;
                }
    }
    return false;
}
}


bool compare(){
    if(phonetic::compareLen()){
        int i=0;
        while(i<wordSize && ind<textSize && phonetic::compareLetters(i,ind)){
            ind++;
            i++;         
        }
        if(i<wordSize){
                while(ind<textSize && text[ind]!=' '){
                    ind++;
                            }
                return false;
            }
        return true;
    }
    return false;
}


string find(string sentence,string inputWord){
    //printf("start of find\n");

    strcpy(word,inputWord.c_str());
    wordSize=inputWord.length();
    //printf("word is %s\n",word);

    strcpy(text,sentence.c_str());
    textSize=sentence.length();
    //printf("text is %s\n",text);

    int start=0;
    ind=0;
    while(ind<textSize){
        if(phonetic::compare()){
            string str=phonetic::convertToString(text,textSize);
            string s = str.substr(start,ind-start);
            //printf("answer is %s\n",s.c_str());
            return s;
        }
        ind++;
        start=ind;
    }
    throw oops();
}

}

