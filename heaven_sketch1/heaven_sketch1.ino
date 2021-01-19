void setup() {
  //Serial.begin(9600);
  cardstack* stackLL = new cardstack(-1);
  cardstack* stackLR = new cardstack(-1);
  cardstack* stackRL = new cardstack(-1);
  cardstack* stackRL = new cardstack(-1);
  heaven game = new heaven(stackLL,stackLR,stackRL,stackRR,-1);
  game.check_row();
  game.check_deck();
}

void loop() {
  if (game.row_to_row()) {
    game.check_row();
  }
  if (game.deck_to_row()) {
    game.check_row();
    game.check_deck();
  }
}
// ###### Cards Stack Class ###### //
public class cardstack { // card stack class
  private:
    short topcard;
    short SIZE;
    short* STACK;
  public:
    cardstack(short top);
    short getsize() { return this.SIZE; }
    short peektop() { return this.topcard; }
    short pop();
    void push(short top);
    ~cardstack() { delete[] STACK; STACK = nullptr; }
}
cardstack::cardstack(short top) : SIZE(0), topcard(top) {
  this.STACK = new short(13){-1}; //13 cards max can go in each stack
}
short cardstack::pop() {
  if (this.SIZE > 0) {
    short temp = this.STACK[this.SIZE-1];
    this.STACK[this.SIZE-1] = -1;
    this.SIZE--;
    if (this.SIZE > 0) {
      this.topcard = this.STACK[this.SIZE-1];
    } else {
      this.topcard = -1;
    }
    return temp;
  }
}
void cardstack::push(short top) {
  if (this.SIZE < 13) {
    this.STACK[this.SIZE-1] = top;
    this.SIZE++;
    this.topcard = top;
  }
}
// ################################# //
// ###### Game Class ###### //
public class heaven {
  private:
    cardstack rowstacks[4];
    short topdeck;
    short topheap;
  public:
    heaven(cardstack a, cardstack b, cardstack c, cardstack d, short top) : topdeck(top), topheap(-1) {
      rowstacks = {a,b,c,d};
    }
    void ckeck_row(); // sets the stacks of personal cards
    void check_deck(); // sets the top card of the deck
    bool row_to_row(); // if can play card from stack to stack returns true and does it
    bool deck_to_row(); // if can play card from deck to stack returns true and does it
}
void heaven::check_row() {
  // template match card to the various deck positions
  short row[5];
  //row = getrow(); // get the cards from photorec on the server
  for(int i = 0; i < 4; i++) {
    if (this.rowstacks[i].peektop() != row[i]) {
      this.rowstacks[i].push(row[i]);
    }
  }
}
void heaven::check_deck() {
  //short top = getdeck();
  if (this.topdeck != top) {
    this.topdeck = top;
  }
}
bool heaven::row_to_row() {
  short count = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; i < 4; j++) {
      if (i != j && (this.rowstacks[i].peektop() > 26 && this.rowstacks[j].peektop() <= 26) && (this.rowstacks[i].peektop() - this.rowstacks[j] == 27 || this.rowstacks[i].peektop() - this.rowstacks[j] == 14)) {
        // movecard();
        this.rowstacks[i].push(this.rowstacks[j].peektop());
        this.rowstacks[j].pop();
        count++;
      } else if (i != j && (this.rowstacks[i].peektop() <= 26 && this.rowstacks[j].peektop() > 26) && (this.rowstacks[j].peektop() - this.rowstacks[i] == 27 || this.rowstacks[j].peektop() - this.rowstacks[i] == 14)) {
        // movecard();
        this.rowstacks[j].push(this.rowstacks[i].peektop());
        this.rowstacks[i].pop();
        count++;
      }
    }
  }
  if (count > 0) {
    return true;
  }
  return false;
}
// ################################## //
