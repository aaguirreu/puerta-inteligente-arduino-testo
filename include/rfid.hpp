// Constructor
void startRFID() {
    SPI.begin();     // Init SPI bus
    rfid.PCD_Init(); // Init MFRC522
}
// Comparison of RFID UIDs.
bool compareRFIDuids() {
    if (rfid.uid.uidByte[0] == nuidPICC[0] &&
        rfid.uid.uidByte[1] == nuidPICC[1] &&
        rfid.uid.uidByte[2] == nuidPICC[2] &&
        rfid.uid.uidByte[3] == nuidPICC[3])
    {
        return true;
    }
    else {return false;}
}
// Main function for RFID.
void checkRFID(bool& _passwordProcess) {
    // Detecting and reading card
    if (!rfid.PICC_IsNewCardPresent())
        return;
    if (!rfid.PICC_ReadCardSerial())
        return;

    if (compareRFIDuids()) {
        String id = "";
        //rfid_uid to string
        for (byte i = 0; i < 4; i++) {
            nuidPICC[i] = rfid.uid.uidByte[i];
            id += nuidPICC[i];
        }
        //findSD(id);
        // If the uid are equals, start the password process.
        writeDisplay("Club ExDev", "Bienvenide");
        _passwordProcess = true;
        cleanPassword();
        delay(2000);
        writeDisplay("Ingrese clave:", "");
    }
    // These are to prevent two PICC actives at the same time.
    rfid.PICC_HaltA();      // Halt PICC
    rfid.PCD_StopCrypto1(); // Stop encryption on PCD
}