class Database {
private:
   <object>* dataTable;
   virtual bool isValid();
   void errorOutput();
public:
   virtual void readIn();
};
