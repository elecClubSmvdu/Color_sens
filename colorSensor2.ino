int redPin=11;
int greenPin=10;
int bluePin=6;
unsigned int pulsewidth;
int rcolorStrength;
int bcolorStrength;
int gcolorStrength;
int S2=7;
int S3=8;
int OutPin=4;


void setup()
{
  Serial.begin(9600);
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);
  pinMode(OutPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  
}

void loop()
{
  int myarr[3]={bcolorStrength,gcolorStrength,rcolorStrength};
  // for red color s2 and s3 are low
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
pulsewidth=pulseIn(OutPin,LOW);
rcolorStrength=(pulsewidth/400.0)-1;
rcolorStrength=255-rcolorStrength; // we flipped it bcuz a big input meant a small color, now a big no means a strong red

 // for green color s2 and s3 are high
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
pulsewidth=pulseIn(OutPin,LOW);
gcolorStrength=(pulsewidth/400.0)-1;
gcolorStrength=255-gcolorStrength; // we flipped it bcuz a big input meant a small color, now a big no means a strong green

// for blue color, s2 is low and s3 are high
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
pulsewidth=pulseIn(OutPin,LOW);
bcolorStrength=(pulsewidth/400.0)-1;
bcolorStrength=255-bcolorStrength; // we flipped it bcuz a big input meant a small color, now a big no means a strong blue
  Serial.print(rcolorStrength);
  Serial.print(",");
  Serial.print(gcolorStrength);
  Serial.print(",");
  Serial.println(bcolorStrength);
 
 
  delay(100);
  // IF WE WANT A INTERMEDIATE COLOR, JUST SCALE THE each corresponding higher...(exaggerate)
 
/*whichever is the biggest , analogWrite it to 255;
whichever is the least , analogWrite it to 0;
whichever is the intermediate , analogWrite it to half of it;

may use if statements
but we do it the teja way*/
int temp;

int maxi=bcolorStrength;
for(int i=0;i<2;i++)
{
if(myarr[i]>maxi)
{
temp=maxi;
maxi=myarr[i];
myarr[i]=temp;
}
}
myarr[0]=255;
myarr[1]=(myarr[1])/2;
myarr[3]=0;

analogWrite(redPin,rcolorStrength);
analogWrite(greenPin,gcolorStrength);
analogWrite(bluePin,bcolorStrength);

  
  
}

