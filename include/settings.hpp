// Pins
#define BUTTON1PIN 2      // Set for Button 1. Uses pin 2.
#define BUTTON2PIN 3      // Set for Button 2. Uses pin 3.
#define BUTTON3PIN 4      // Set for Button 3. Uses pin 4.
#define BUTTON4PIN 5      // Set for Button 4. Uses pin 5.
#define INNERBUTTONPIN 6  // Set for inner Button. Uses pin 6.
#define SDPIN 44           // Set for SD module. Uses pin 7.
//#define SDSCK 
#define I2C_BUS_ADDRESS 10 //
#define RFIDRESETPIN 8    // Set for RFID. Uses pin 8.
#define RFIDSSPIN 9     // Set for RFID. Uses pin 9.
#define RFIDMOSIPIN 51    // Set for RFID. Uses pin 11.
#define RFIDMISOPIN 50    // Set for RFID. Uses pin 12.
#define RFIDSCKPIN 52     // Set for RFID. Uses pin 13.


// inits
LiquidCrystal_I2C lcd(0x3F, 16, 2);    // Set for Display. Uses pin A4, A5
MFRC522 rfid(RFIDSSPIN, RFIDRESETPIN); // Set for RFID.
bool passwordProcess;          // Password process status
const int passSize = 4;                      // Tamaño de la contraseña
int password[passSize];                       // Array for password.
byte nuidPICC[4];                      // Array to store UUID of the NFC
File exDevFile;                        // File to manipulate the SD file.
int ms;


// Dummys
const int dummyPassword[4] = {1, 2, 3, 4}; // Array with an example password.