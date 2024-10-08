#include <arduinoFFT.h>  // Correct library include

#define SAMPLES 128            // Must be a power of 2
#define SAMPLING_FREQUENCY 4000 // Hz, must be less than 10000 due to ADC limitations

#define RED_PIN  11
#define GREEN_PIN  10
#define BLUE_PIN  6

ArduinoFFT<double> FFT = ArduinoFFT<double>();  // Use template with <double> type


unsigned int sampling_period_us;
unsigned long microseconds;

double vReal[SAMPLES];
double vImag[SAMPLES];

void setup() {
  Serial.begin(9600);
  sampling_period_us = round(1000000 * (1.0 / SAMPLING_FREQUENCY));
}

void loop() {
  /* Sampling */
  for (int i = 0; i < SAMPLES; i++) {
    microseconds = micros();    // Overflows after around 70 minutes!
    vReal[i] = analogRead(A0);  // Connect mic to A0
    vImag[i] = 0;

    while (micros() < (microseconds + sampling_period_us)) {
      // wait for the next sample
    }
  }

  /* FFT */
  FFT.windowing(vReal, SAMPLES, FFT_WIN_TYP_RECTANGLE, FFT_FORWARD); // Windowing
  //FFT_WIN_TYP_HANN or FFT_WIN_TYP_BLACKMAN or FFT_WIN_TYP_RECTANGLE

  FFT.compute(vReal, vImag, SAMPLES, FFT_FORWARD);                 // Compute FFT
  FFT.complexToMagnitude(vReal, vImag, SAMPLES);                   // Compute magnitudes

  /* Find peak frequency */
  double peakFrequency = FFT.majorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
  Serial.println(peakFrequency);

  // Use the peak frequency to control the RGB LED
  controlRGB(peakFrequency);
}

void controlRGB(double frequency) {
  // Map frequency ranges to RGB values
  if (frequency < 200) {
    analogWrite(RED_PIN, 255);  // Low frequency -> Red
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
  } else if (frequency < 600) {
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 255);  // Mid frequency -> Green
    analogWrite(BLUE_PIN, 0);
  } else {
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 255);  // High frequency -> Blue
  }
}
