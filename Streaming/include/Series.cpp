Series::Series(){
}
Series::Series(string n,string i,string g):Content(n,i,g){
}
Series::~Series(){
}
string Series::printData(){
    string data;
    if (rating>=1&&rating<=5){
        data=name+"\tid: "+id+"\t-\tgenre: "+genre+"\tSeries\t"+to_string(rating)+"/5";
    }
    else{
        data=name+"\tid: "+id+"\t-\tgenre: "+genre+"\tSeries\tNo rating yet";
    }
    return data;
}
