int ledler[] = {2,3,4,5,6,7,8,9,10,11}; 
// bu noktada daha kısa bir kod kullanarak işlemi yerine getirmek için ledlerimizin bağlı olduğu bacakları dizi biçiminde tanımlıyoruz.
// At this point, we define the legs to which our leds are connected in the form of an array to perform the operation using a shorter code.


void setup() {
  for (int i =0;i<10;i++)// for döngüsü ve diziler kullanılarak kısa satırlarla çıkış bacaklarımızı tanımladık.
                        //We defined our output legs with short lines using the for loop and arrays.
  {
  pinMode(ledler[i], OUTPUT);
  pinMode(A0, OUTPUT);  
  Serial.begin(9600);//Seri monitörün aktifleşmesini sağlıyoruz.
                    //We enable the serial monitor to be activated.
  }
}
void loop()
{
  int isik = analogRead(A0); //Burada A0 analog pinimize taktığımız fotoresptörümüzü tanımlıyoruz.
                            //Here we define our photoresistor that we attach to our analog pin A0.
  Serial.println("isik value : ");//Seri ekrana yazdırmak istediğimiz bazı ifadeleri tanımlıyoruz.
                                 //We define some expressions that we want to print to the serial screen.
  Serial.println(isik);//Seri ekrana 'isik' değerimizi bastırıyoruz.
                      //We print our 'light' value to the serial screen
  delay(50);
  
if (isik >50) 
{ Serial.println("isik value higher than 50...");//seri ekranımıza hangi poz,syonda olduğumuzu bilgi amaçlı yazzdırıyoruz.
                                                // we print the position we are in on our serial screen for informational purposes.
  delay(50);
  for (int i =0;i<10;i++)//Ledlerimizin 1. sıradan başlayarak son ledimize kadar 200ms aralıklarla yakılmasını sağlıyoruz.
                        //We make our leds turn on with a delay of 200ms starting from the 1st row until our last led.
  {
  digitalWrite(ledler[i],HIGH);
  delay(200);
    
  }


   
 for (int i =10;i>-1;i--)//Ledlerimizin son sıradan başlayarak 200 ms gecikme ile sırayla söndürülmesini sağlıyoruz.
                        //We ensure that our leds are turned off sequentially, starting from the last row, with a delay of 200 ms.
  {
  digitalWrite(ledler[i],LOW);
  delay(200);
    
  }

  
}
 else
 {
   Serial.println("isik value lower than 50....");

  for (int i =10;i>-1;i--)//Ledlerimizin son sıradan başlayarak ilk ledimize doğru (soldan sağa) 200ms gecikme ile yanmasını sağlıyoruz.
                        //We make our leds turn on from the last row to our first led (from left to right) with a delay of 200ms.
  {
  digitalWrite(ledler[i],HIGH);
  delay(200);
    
  }
  for (int i =0;i<10;i++)//Ledlerimizin ilk sıradan başlayarak son ledimize doğru (sağdan sola) 200ms gecikme ile sönmesini sağlıyoruz.
                        //We make our leds turn off with a delay of 200ms starting from the first row and towards our last led (from right to left).
  {
  digitalWrite(ledler[i],LOW);
  delay(200);

  }

 }   
  }