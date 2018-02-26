class Film:Media {
   struct actorNode {
      string actor;
      actorNode* next;
   }
private:
   string director;
   actorNode* actorList;
   string category;
   string inventoryID;
public:
   bool featuresActor();
   string getActor();
   string getDirector();
   void setActor();
   void setDirector();
};
