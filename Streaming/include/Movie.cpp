Movie::Movie(){
}
Movie::Movie(string n,string i,int l,string g):Content(n,i,l,g){
}
Movie::~Movie(){
}
string Movie::printData(){
    string data;
    if (rating>=1&&rating<=5){
        data=name+"\tid: "+id+"\t"+to_string(length)+" min\tgenre: "+genre+"\tMovie\t"+to_string(rating)+"/5";
    }
    else{
        data=name+"\tid: "+id+"\t"+to_string(length)+" min\tgenre: "+genre+"\tMovie\tNo rating yet";
    }
    return data;
}
