class Content{
public:
    Content();
    Content(string,string,int,string);
    Content(string,string,string);
    Content(string,int,string,int,string,int);
    virtual void setRating(int const&);
    virtual string printData()=0;
    virtual string watch();
    virtual string watch(string);
    virtual string rate();
protected:
    string name;
    int season;
    string id;
    int length;
    string genre;
    int num;
    int rating;
};
