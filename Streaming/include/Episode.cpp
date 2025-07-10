Episode::Episode(){
}
Episode::Episode(string n,int s,string i,int l,string g,int nE):Content(n,s,i,l,g,nE){
}
Episode::~Episode(){
}
string Episode::printData(){
    string data;
    if (rating>=1&&rating<=5){
        data=name+"\tseason: "+to_string(season)+"\tid: "+id+"\t"+to_string(length)+" min\tgenre: "+genre+"\tEpisode\t"+to_string(rating)+"/5";
    }
    else{
        data=name+"\tseason: "+to_string(season)+"\tid: "+id+"\t"+to_string(length)+" min\tgenre: "+genre+"\tEpisode\tNo rating yet";
    }
    return data;
}
