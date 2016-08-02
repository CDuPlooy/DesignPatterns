/*
Plundered from : http://forum.codecall.net/topic/71737-c-proper-memento-implementation/
*/


/*
* Memento, for now, saves the state only for var1 for Originator class.
* You can add more states depending Orginator needs.
*/
class Memento {
      protected:
            int mVar1;

      private:
/*
* We are making all the ways of creating a Memento private
* so that no one can create/modify state of a memento other than the Originator.
*/
Memento(){}
Memento(const Memento& source){ mVar1 = source.mVar1;}
Memento &operator=(const Memento &source){mVar1 = source.mVar1; return *this;}

void setVar1(int var) {mVar1 = var;}
int getVar1() const {return mVar1;}

/*
* Memento is declaring Originator as his friend so that Originator can
* create Memento or access its members.
*/
friend class Orginator;
};


class Orginator {
      private:
int mVar1;
int mVar2;

public:
void setVar1(int var) {mVar1 = var;}
int getVar1() const {return mVar1;}

void setVar2(int var) {mVar2 = var;}
int getVar2() const {return mVar2;}

Memento* saveState(){
      Memento* memento = new Memento;
      memento->setVar1(getVar1());
      return memento;
}

void restoreState(Memento* memento){
      setVar1(memento->getVar1());
}
};

void mementoExample()
{
Orginator* originator = new Orginator;
originator->setVar1(10);
originator->setVar1(11);

// create Memento
Memento* memento = originator->saveState();

// originator state
originator->setVar1(12);

// restore orignator state
originator->restoreState(memento);
}
