int rxPin = 0;                    // RX PIN 
 int txPin = 1;                    // TX TX
  //GPS  
 int byteGPS=-1;
 char linea[300] = "";
 char comandoGPR[7] = "$GPRMC";
 int cont=0;
 int bien=0;
 int conta=0;
 int indices[13];
 char flag,flag1;



 
 void setup() 
{
pinMode(14,INPUT);pinMode(8,OUTPUT);
Serial.begin(9600);
}

void loop() 
{

int hbr=digitalRead(14);


if(hbr==1)
{
int hbr= digitalRead(14);flag=0;
Serial.println(hbr);

 pinMode(rxPin, INPUT);
   pinMode(txPin, OUTPUT);
    for (int i=0;i<300;i++)
   {       
     linea[i]=' ';
   }
   digitalWrite(8,1);
  gps();  sendmsg();
 
  flag=1;
  digitalWrite(8,0);
}


}
 



void sendmsg()
{
  

Serial.println("AT+CMGF=1");    
delay(1000);  
Serial.println("AT+CMGS=\"+918668070191\"\r"); 
delay(1000);
delay(1000);
Serial.println("");
//Serial.println("Latitude and Longitude");
delay(1000);
Serial.println("https://www.latlong.net/c/?lat=");
Serial.print(linea[21]);
Serial.print(linea[22]);
Serial.print(linea[23]);
Serial.print(linea[24]);
Serial.print(linea[25]);
Serial.print(linea[26]);
Serial.print(linea[27]);
Serial.print(linea[28]);
Serial.print(linea[29]);
Serial.print(linea[30]);
Serial.print(linea[31]);

Serial.print("&long=");
Serial.print(linea[32]);
Serial.print(linea[33]);
Serial.print(linea[34]);
Serial.print(linea[35]);
Serial.print(linea[36]);
Serial.print(linea[37]);
Serial.print(linea[38]);
Serial.print(linea[39]);
Serial.print(linea[40]);
Serial.print(linea[41]);
Serial.print(linea[42]);
Serial.print(linea[43]);
Serial.print(linea[44]);
delay(1000);
Serial.println((char)26);
delay(4000);
}


 void gps() 
 {

     byteGPS=Serial.read();      
    if (byteGPS == -1) 
    {           
     delay(100); 
   } else {
   
     linea[conta]=byteGPS;        
     conta++;                      
     if (byteGPS==13)
     {            
       cont=0;
       bien=0;
       for (int i=1;i<7;i++)
       {     
         if (linea[i]==comandoGPR[i-1])
         {
           bien++;
         }
       }
       if(bien==6)
       {               
         for (int i=0;i<300;i++){
           if (linea[i]==',')
           {    
             indices[cont]=i;
             cont++;
           }
           if (linea[i]=='*')
           {    
             indices[12]=i;
             cont++;
           }
         }
         Serial.println("");     
         Serial.println("");
         for (int i=2;i<5;i++)
         {
           if(i==2)
           {
          for (int j=indices[i];j<(indices[i+1]-1);j++)
           {
            ((linea[j+1]));  
            }}
             if(i==4)
           {
             Serial.print(",");
           for (int j=indices[i];j<(indices[i+1]-1);j++)
           {
              ((linea[j+1]));  
              
       }}
       
           sendmsg();flag=0;
         }
         
       }
              

       conta=0;                    
       for (int i=0;i<300;i++){     
         linea[i]=' ';             
       }  
       
      
     }
   
   }
 }
 

