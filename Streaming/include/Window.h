class Window{
public:
    virtual void setCollectionData(string const&);
    virtual string printWindow()=0;
protected:
    string collectionData;
};
