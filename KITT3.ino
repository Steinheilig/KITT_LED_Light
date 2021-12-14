const int LEDpins[6] = {11,10,9,6,5,3};

float t = 0;            // time 
float dt = 0.01;        // time increment

int max_bright = 255;   // max brightness
float mu = 0;           // mean position of traveling light wave
float f = .1;           // oscillation frequency of the mean wave position 
float sigma  = .5 *0.9; // std of the light wave 

void setup() {
 Serial.begin(9600);
 for (int led = 0; led <= 5; led++) { 
   analogWrite(LEDpins[led], 0 );    //Off   
 }
}

void loop() {
 t = t + dt;
 mu = 1/2.*5*(1+sin(2*PI*f*t)) - 0*1/2. ; // mean position at time t
 for (int led = 0; led <= 5; led++) {  // calculate the brightness for each LED at position <led> at time <t> 
   analogWrite(LEDpins[led], max_bright*exp( (-1* pow( (led-mu) ,2) )/( 2* pow(sigma,2)) ));    //On 
 }
}
