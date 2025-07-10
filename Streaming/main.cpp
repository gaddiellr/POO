#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
#include "include/Content.h"
#include "include/Content.cpp"
#include "include/Episode.h"
#include "include/Episode.cpp"
#include "include/Movie.h"
#include "include/Movie.cpp"
#include "include/Series.h"
#include "include/Series.cpp"
#include "include/Window.h"
#include "include/Window.cpp"
#include "include/SeriesWindow.h"
#include "include/SeriesWindow.cpp"
#include "include/HomeWindow.h"
#include "include/HomeWindow.cpp"
#include "include/Collection.h"
#include "include/Collection.cpp"
#include "include/Menu.h"
#include "include/Menu.cpp"
#include "include/MenuVideo.h"
#include "include/MenuVideo.cpp"
#include "include/MenuSeries.h"
#include "include/MenuSeries.cpp"
int main(){
    string collectionHome[4];
    string names[8]={"Star Wars I","Star Wars IX","Clone Wars","Ahsoka","one","two","part 1","part 2"};
    int seasons[4]={1,1,1,1};
    string ids[8]={"m1","m2","s1","s2","e1","e2","e3","e4"};
    int lenghts[6]={120,110,30,32,31,31};
    string genres[8]={"B","C","Z","B","A","A","B","B"};
    vector <Content*> contentsHome;
    contentsHome.push_back(new Movie(names[0],ids[0],lenghts[0],genres[0]));
    contentsHome.push_back(new Movie(names[1],ids[1],lenghts[1],genres[1]));
    contentsHome.push_back(new Series(names[2],ids[2],genres[2]));
    contentsHome.push_back(new Series(names[3],ids[3],genres[3]));
    auto contenth1=&contentsHome[0];
    auto contenth2=&contentsHome[1];
    auto contenth3=&contentsHome[2];
    auto contenth4=&contentsHome[3];
    vector <Content*> contentsS1;
    contentsS1.push_back(new Episode(names[4],seasons[0],ids[4],lenghts[2],genres[4],1));
    contentsS1.push_back(new Episode(names[5],seasons[1],ids[5],lenghts[3],genres[5],2));
    auto contents11=&contentsS1[0];
    auto contents12=&contentsS1[1];
    vector <Content*> contentsS2;
    contentsS2.push_back(new Episode(names[6],seasons[2],ids[6],lenghts[4],genres[6],1));
    contentsS2.push_back(new Episode(names[7],seasons[3],ids[7],lenghts[5],genres[7],2));
    auto contents21=&contentsS2[0];
    auto contents22=&contentsS2[1];
    HomeWindow home;
    SeriesWindow s1(names[2]);
    SeriesWindow s2(names[3]);
    Menu menu;
    MenuVideo menuV;
    MenuSeries menuS;
    string op="0";
    string prevop;
    int rating;
    int j;
    while (op!="c"){
        prevop=op;
        j=0;
        rating=0;
        if (op=="0"){
            for(auto i=contentsHome.begin();i!=contentsHome.end();i++){
                collectionHome[j]=(*i)->printData();
                j=j+1;
            }
            sort(collectionHome,collectionHome+4);
            Collection collectionHomeSorted;
            for (int k=0;k<4;k++){
                collectionHomeSorted+=collectionHome[k];
            }
            home.setCollectionData(collectionHomeSorted.getCollectionData());
            cout<<home.printWindow();
            cout<<menu.printMenu();
            cin>>op;
            if (op=="r"){
                op=prevop;
            }
            prevop=op;
        }
        if (op==ids[0]){
            cout<<(*contenth1)->watch();
            cout<<menuV.printMenu();
            cin>>op;
            if (op=="r"){
                while (rating<1||rating>5){
                    cout<<(*contenth1)->rate();
                    cin>>rating;
                }
                (*contenth1)->setRating(rating);
                op=prevop;
            }
        }
        if (op==ids[1]){
            cout<<(*contenth2)->watch();
            cout<<menuV.printMenu();
            cin>>op;
            if (op=="r"){
                while (rating<1||rating>5){
                    cout<<(*contenth2)->rate();
                    cin>>rating;
                }
                (*contenth2)->setRating(rating);
                op=prevop;
            }
        }
        if (op==ids[2]){
            Collection collectionS1;
            for(auto i=contentsS1.begin();i!=contentsS1.end();i++){
                collectionS1+=(*i)->printData();
            }
            s1.setCollectionData(collectionS1.getCollectionData());
            cout<<s1.printWindow();
            cout<<menuS.printMenu();
            cin>>op;
            if (op=="r"){
                while (rating<1||rating>5){
                    cout<<(*contenth3)->rate();
                    cin>>rating;
                }
                (*contenth3)->setRating(rating);
                op=prevop;
            }
        }
        if (op==ids[3]){
            Collection collectionS2;
            for(auto i=contentsS2.begin();i!=contentsS2.end();i++){
                collectionS2+=(*i)->printData();
            }
            s2.setCollectionData(collectionS2.getCollectionData());
            cout<<s2.printWindow();
            cout<<menuS.printMenu();
            cin>>op;
            if (op=="r"){
                while (rating<1||rating>5){
                    cout<<(*contenth4)->rate();
                    cin>>rating;
                }
                (*contenth4)->setRating(rating);
                op=prevop;
            }
        }
        if (op==ids[4]){
            prevop=op;
            cout<<(*contents11)->watch(names[2]);
            cout<<menuV.printMenu();
            cin>>op;
            if (op=="r"){
                while (rating<1||rating>5){
                    cout<<(*contents11)->rate();
                    cin>>rating;
                }
                (*contents11)->setRating(rating);
                op=prevop;
            }
        }
        if (op==ids[5]){
            prevop=op;
            cout<<(*contents12)->watch(names[2]);
            cout<<menuV.printMenu();
            cin>>op;
            if (op=="r"){
                while (rating<1||rating>5){
                    cout<<(*contents12)->rate();
                    cin>>rating;
                }
                (*contents12)->setRating(rating);
                op=prevop;
            }
        }
        if (op==ids[6]){
            prevop=op;
            cout<<(*contents21)->watch(names[3]);
            cout<<menuV.printMenu();
            cin>>op;
            if (op=="r"){
                while (rating<1||rating>5){
                    cout<<(*contents21)->rate();
                    cin>>rating;
                }
                (*contents21)->setRating(rating);
                op=prevop;
            }
        }
        if (op==ids[7]){
            prevop=op;
            cout<<(*contents22)->watch(names[3]);
            cout<<menuV.printMenu();
            cin>>op;
            if (op=="r"){
                while (rating<1||rating>5){
                    cout<<(*contents22)->rate();
                    cin>>rating;
                }
                (*contents22)->setRating(rating);
                op=prevop;
            }
        }
        if (op!="0"&&op!="c"&&op!=ids[0]&&op!=ids[1]&&op!=ids[2]&&op!=ids[3]&&op!=ids[4]&&op!=ids[5]&&op!=ids[6]&&op!=ids[7]){
            op=prevop;
        }
    }
    return 0;
}
