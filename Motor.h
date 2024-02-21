#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define UP_LEFT 5
#define UP_RIGHT 6
#define DOWN_LEFT 7
#define DOWN_RIGHT 8
#define TURN_LEFT 9
#define TURN_RIGHT 10
#define STOP 0
// Define pins for Motor input
#define A1Pin 14   //4
#define A2Pin 12   //5
#define B1Pin  5   //12
#define B2Pin  4   //14

void processCarMovement(int Action)
{
  //Serial.printf("Got value %d \n", Action);  
  switch(Action)
  {

    case UP:
      digitalWrite(A1Pin, LOW);      
      digitalWrite(A2Pin, HIGH);      
      digitalWrite(B1Pin, HIGH);      
      digitalWrite(B2Pin, LOW);      
      break;
  
    case DOWN:
      digitalWrite(A1Pin, HIGH);      
      digitalWrite(A2Pin, LOW);      
      digitalWrite(B1Pin, LOW);      
      digitalWrite(B2Pin, HIGH);      
      break;
  
    case LEFT:
      digitalWrite(A1Pin, LOW);      
      digitalWrite(A2Pin, LOW);      
      digitalWrite(B1Pin, HIGH);      
      digitalWrite(B2Pin, LOW);      
      break;
  
    case RIGHT:
      digitalWrite(A1Pin, LOW);      
      digitalWrite(A2Pin, HIGH);      
      digitalWrite(B1Pin, LOW);      
      digitalWrite(B2Pin, LOW);      
      break;
  
    case UP_LEFT:
      digitalWrite(A1Pin, LOW);
      analogWrite(A2Pin,100);      
      digitalWrite(B1Pin, HIGH);      
      digitalWrite(B2Pin, LOW);      
      break;
  
    case UP_RIGHT:
      digitalWrite(A1Pin, LOW);      
      digitalWrite(A2Pin, HIGH);      
      analogWrite(B1Pin,100);      
      digitalWrite(B2Pin, LOW);      
      break;
  
    case DOWN_LEFT:
      analogWrite(A1Pin, 256);      
      digitalWrite(A2Pin, LOW);      
      digitalWrite(B1Pin, LOW);      
      digitalWrite(B2Pin, HIGH);      
      break;
  
    case DOWN_RIGHT:
      digitalWrite(A1Pin, HIGH);      
      digitalWrite(A2Pin, LOW);      
      digitalWrite(B1Pin, LOW);      
      analogWrite(B2Pin, 256);      
      break;
  
    case TURN_LEFT:
      digitalWrite(A1Pin, HIGH);      
      digitalWrite(A2Pin, LOW);      
      digitalWrite(B1Pin, HIGH);      
      digitalWrite(B2Pin, LOW);      
      break;
  
    case TURN_RIGHT:
      digitalWrite(A1Pin, LOW);      
      digitalWrite(A2Pin, HIGH);      
      digitalWrite(B1Pin, LOW);      
      digitalWrite(B2Pin, HIGH);      
      break;
  
    case STOP:
      digitalWrite(A1Pin, LOW);      
      digitalWrite(A2Pin, LOW);      
      digitalWrite(B1Pin, LOW);      
      digitalWrite(B2Pin, LOW);      
      break;
  
    default:
      digitalWrite(A1Pin, LOW);      
      digitalWrite(A2Pin, LOW);      
      digitalWrite(B1Pin, LOW);      
      digitalWrite(B2Pin, LOW);      
      break;
  }
}
