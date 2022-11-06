#define datapin 12
#define latchpin 11
#define clkpin 10
#define dg1 9
#define dg2 8
#define dg3 7
#define dg4 6
int num=0;
int n1;
int n2;
int n3;
int n4;
String n;
unsigned long prevmillis=0;
String s="11000000111110011010010010110000100110011001001010000010111110001000000010010000";
void inpPos(){
  digitalWrite(datapin,1);
  digitalWrite(clkpin,1);
  digitalWrite(clkpin,0);
  digitalWrite(datapin,0);
}
void inpNeg(){
  digitalWrite(datapin,0);
  digitalWrite(clkpin,1);
  digitalWrite(clkpin,0);
  digitalWrite(datapin,1);
}
void print_i(int i,int dg){
  digitalWrite(latchpin,0);
  if(dg==dg2){
    inpNeg();
  }
  else{
  inpPos();
  }
  for(int j=1;j<8;j++){
    if(s[i*8+j]-'0'){
     inpPos();
    }
    else{
    inpNeg();
    }
  }
  digitalWrite(latchpin,1);
  digitalWrite(dg,HIGH);
  delay(5);
  digitalWrite(dg,LOW);
}
void print_4digit(int n){
   n1=n/1000;
  n=n%1000;
   n2=n/100;
  n=n%100;
   n3=n/10;
  n=n%10;
   n4=n;
  
    print_i(n1,dg1);
    print_i(n2,dg2);
    print_i(n3,dg3);
    print_i(n4,dg4);
    
  
}
void setup(){
  Serial.begin(9600);
  pinMode(datapin,OUTPUT);
  pinMode(latchpin,OUTPUT);
  pinMode(clkpin,OUTPUT);
  pinMode(dg1,OUTPUT);
  pinMode(dg2,OUTPUT);
  pinMode(dg3,OUTPUT);
  pinMode(dg4,OUTPUT);
  digitalWrite(dg1,LOW);
  digitalWrite(dg2,LOW);
  digitalWrite(dg3,LOW);
  digitalWrite(dg4,LOW);
  Serial.setTimeout(1000);
  Serial.println("always give input in 4 digits");
  Serial.println("first two digits for hrs");
  Serial.println("last two digits for min");
}
void reset(){
Serial.println("always give input in 4 digits");
  Serial.println("first two digits for hrs");
  Serial.println("last two digits for min");
}
int minB=30;
int hrsB=12;

void loop(){
    if(Serial.available()>0){
      n1=Serial.read()-48;
      n2=Serial.read()-48;
      n3=Serial.read()-48;
      n4=Serial.read()-48;
      hrsB=n1*10+n2;
      minB=n3*10+n4;
      Serial.println(hrsB*100+minB);
      reset();
     }
   
  int min=millis()/(60000);
   int hrs=min/60;
  num=((hrs+hrsB)%24)*100+((min+minB)%60);
     print_4digit(num);
 }
