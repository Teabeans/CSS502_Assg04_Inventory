class InventoryDB:Database {
private:
   film* inventoryTable[];
   int estimateSize();
   int hashTitle();
   bool isValid();
public:
  void display();
  void readIn();
  string toString();
};
