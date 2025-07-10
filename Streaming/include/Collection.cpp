Collection::Collection(){
    collectionData="";
}
void Collection::operator+=(string data){
    collectionData=collectionData+data+"\n";
}
string Collection::getCollectionData(){
    return collectionData;
}
