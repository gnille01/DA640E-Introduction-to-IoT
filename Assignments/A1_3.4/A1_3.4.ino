/*

  Melody

  Plays a melody

  circuit:

  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010

  modified 30 Aug 2011

  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/Tone

*/
// Revised version of public "Tone" program 


#include "pitches.h"

// notes in the melody:
int melody[] = {

  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_D4, 
  NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, 0, 
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_D4, 
  NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, 0

};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1.5, 8, 2, 2, 
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1.5, 8, 2, 2
};

void setup() {
  Serial.begin(9600);  // Start serial communication for debugging

  // Iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 32; thisNote++) {

    // Calculate the note duration (e.g., quarter note = 1000 / 4):
    int noteDuration = 1000 / noteDurations[thisNote];

    // Print debug info:
    Serial.print("Playing note: ");
    Serial.print(melody[thisNote]);
    Serial.print(" Duration: ");
    Serial.println(noteDuration);

    // Play the note if it's not a rest (0):
    if (melody[thisNote] != 0) {
      tone(A2, melody[thisNote], noteDuration);  // Play the note
    } 
    else {
      Serial.println("Rest note");
    }

    // Wait for the note to finish playing:
    delay(noteDuration);

    // Stop the tone explicitly after each note:
    noTone(A2);

    // Pause between notes to distinguish them:
    delay(noteDuration * 0.30);  // Short pause between notes
  }

  // Turn off buzz after for loop
  /*
  noTone(A0);
  delay(500);
  */
  digitalWrite(A2, INPUT); // or use  (A0, LOW);

}

void loop() {
  // No need to repeat the melody.
}
