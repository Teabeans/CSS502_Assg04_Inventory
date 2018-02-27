class Customer {
private:
   string firstName;
   string lastName;
   int IDnumber;
   Transaction* history[];
public:
   int getID();
   string getName();
   string queryHistory();
};
