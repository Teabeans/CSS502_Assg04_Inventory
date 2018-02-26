class CustomerDB : Databace {
private:
   Customer* customerTable[10000];
   bool isValid();
public:
   void readIn();
   string toString();
   void display();
   Customer getCustomerAt();
};
