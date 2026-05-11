// ======================================================
// ESP32 REAL TRAFFIC LIGHT SYSTEM WITH PRIORITY BUTTON
// ESP32 DOIT DEVKIT
// ======================================================
//
// REAL TRAFFIC LOGIC:
//
// NORMAL MODE:
// NORTH + SOUTH = GREEN
// EAST + WEST   = RED
//
// THEN:
//
// NORTH + SOUTH = YELLOW
//
// THEN:
//
// ALL RED = 5 SEC
//
// THEN:
//
// EAST + WEST = GREEN
// NORTH + SOUTH = RED
//
// THEN:
//
// EAST + WEST = YELLOW
//
// THEN:
//
// ALL RED = 5 SEC
//
// BUTTON MODE:
// IF EAST BUTTON PRESSED:
// EAST = GREEN
// ALL OTHERS = RED
//
// AFTER 5 SEC:
// SYSTEM RETURNS TO NORMAL AUTOMATIC MODE
//
// ======================================================

// ===========================
// NORTH
// ===========================
const int NR = 23;
const int NY = 22;
const int NG = 21;

// ===========================
// SOUTH
// ===========================
const int SR = 19;
const int SY = 18;
const int SG = 5;

// ===========================
// EAST
// ===========================
const int ER = 17;
const int EY = 16;
const int EG = 4;

// ===========================
// WEST
// ===========================
const int WR = 27;
const int WY = 26;
const int WG = 25;

// ===========================
// BUTTONS
// ===========================
const int BTN_N = 32;
const int BTN_S = 33;
const int BTN_E = 34;
const int BTN_W = 35;

// ===========================
// TIMING
// ===========================
const int GREEN_TIME = 8000;
const int YELLOW_TIME = 3000;
const int RED_TIME = 5000;
const int PRIORITY_TIME = 5000;

bool priorityMode = false;

// ======================================================
// SETUP
// ======================================================

void setup() {

  // NORTH
  pinMode(NR, OUTPUT);
  pinMode(NY, OUTPUT);
  pinMode(NG, OUTPUT);

  // SOUTH
  pinMode(SR, OUTPUT);
  pinMode(SY, OUTPUT);
  pinMode(SG, OUTPUT);

  // EAST
  pinMode(ER, OUTPUT);
  pinMode(EY, OUTPUT);
  pinMode(EG, OUTPUT);

  // WEST
  pinMode(WR, OUTPUT);
  pinMode(WY, OUTPUT);
  pinMode(WG, OUTPUT);

  // BUTTONS
  pinMode(BTN_N, INPUT_PULLUP);
  pinMode(BTN_S, INPUT_PULLUP);

  // INPUT ONLY
  pinMode(BTN_E, INPUT);
  pinMode(BTN_W, INPUT);

  allRed();
}

// ======================================================
// MAIN LOOP
// ======================================================

void loop() {

  // CHECK BUTTONS
  checkButtons();

  // AUTOMATIC MODE
  if (!priorityMode) {

    // =====================================
    // NORTH + SOUTH GREEN
    // =====================================

    northSouthGreen();
    smartDelay(GREEN_TIME);

    // =====================================
    // NORTH + SOUTH YELLOW
    // =====================================

    northSouthYellow();
    smartDelay(YELLOW_TIME);

    // =====================================
    // ALL RED
    // =====================================

    allRed();
    smartDelay(RED_TIME);

    // =====================================
    // EAST + WEST GREEN
    // =====================================

    eastWestGreen();
    smartDelay(GREEN_TIME);

    // =====================================
    // EAST + WEST YELLOW
    // =====================================

    eastWestYellow();
    smartDelay(YELLOW_TIME);

    // =====================================
    // ALL RED
    // =====================================

    allRed();
    smartDelay(RED_TIME);
  }
}

// ======================================================
// BUTTON CHECK
// ======================================================

void checkButtons() {

  // NORTH BUTTON
  if (digitalRead(BTN_N) == LOW) {
    priorityNorth();
  }

  // SOUTH BUTTON
  if (digitalRead(BTN_S) == LOW) {
    prioritySouth();
  }

  // EAST BUTTON
  if (digitalRead(BTN_E) == HIGH) {
    priorityEast();
  }

  // WEST BUTTON
  if (digitalRead(BTN_W) == HIGH) {
    priorityWest();
  }
}

// ======================================================
// PRIORITY SYSTEM
// ======================================================

// --------------------------------------
// NORTH PRIORITY
// --------------------------------------
void priorityNorth() {

  priorityMode = true;

  allRed();

  delay(1000);

  // NORTH GREEN ONLY
  digitalWrite(NR, LOW);
  digitalWrite(NG, HIGH);

  delay(PRIORITY_TIME);

  allRed();

  priorityMode = false;
}

// --------------------------------------
// SOUTH PRIORITY
// --------------------------------------
void prioritySouth() {

  priorityMode = true;

  allRed();

  delay(1000);

  // SOUTH GREEN ONLY
  digitalWrite(SR, LOW);
  digitalWrite(SG, HIGH);

  delay(PRIORITY_TIME);

  allRed();

  priorityMode = false;
}

// --------------------------------------
// EAST PRIORITY
// --------------------------------------
void priorityEast() {

  priorityMode = true;

  allRed();

  delay(1000);

  // EAST GREEN ONLY
  digitalWrite(ER, LOW);
  digitalWrite(EG, HIGH);

  delay(PRIORITY_TIME);

  allRed();

  priorityMode = false;
}

// --------------------------------------
// WEST PRIORITY
// --------------------------------------
void priorityWest() {

  priorityMode = true;

  allRed();

  delay(1000);

  // WEST GREEN ONLY
  digitalWrite(WR, LOW);
  digitalWrite(WG, HIGH);

  delay(PRIORITY_TIME);

  allRed();

  priorityMode = false;
}

// ======================================================
// ALL RED
// ======================================================

void allRed() {

  // NORTH
  digitalWrite(NR, HIGH);
  digitalWrite(NY, LOW);
  digitalWrite(NG, LOW);

  // SOUTH
  digitalWrite(SR, HIGH);
  digitalWrite(SY, LOW);
  digitalWrite(SG, LOW);

  // EAST
  digitalWrite(ER, HIGH);
  digitalWrite(EY, LOW);
  digitalWrite(EG, LOW);

  // WEST
  digitalWrite(WR, HIGH);
  digitalWrite(WY, LOW);
  digitalWrite(WG, LOW);
}

// ======================================================
// NORTH + SOUTH GREEN
// ======================================================

void northSouthGreen() {

  allRed();

  // NORTH
  digitalWrite(NR, LOW);
  digitalWrite(NG, HIGH);

  // SOUTH
  digitalWrite(SR, LOW);
  digitalWrite(SG, HIGH);
}

// ======================================================
// NORTH + SOUTH YELLOW
// ======================================================

void northSouthYellow() {

  // NORTH
  digitalWrite(NG, LOW);
  digitalWrite(NY, HIGH);

  // SOUTH
  digitalWrite(SG, LOW);
  digitalWrite(SY, HIGH);
}

// ======================================================
// EAST + WEST GREEN
// ======================================================

void eastWestGreen() {

  allRed();

  // EAST
  digitalWrite(ER, LOW);
  digitalWrite(EG, HIGH);

  // WEST
  digitalWrite(WR, LOW);
  digitalWrite(WG, HIGH);
}

// ======================================================
// EAST + WEST YELLOW
// ======================================================

void eastWestYellow() {

  // EAST
  digitalWrite(EG, LOW);
  digitalWrite(EY, HIGH);

  // WEST
  digitalWrite(WG, LOW);
  digitalWrite(WY, HIGH);
}

// ======================================================
// SMART DELAY
// ======================================================

void smartDelay(unsigned long timeMs) {

  unsigned long start = millis();

  while (millis() - start < timeMs) {

    checkButtons();

    if (priorityMode) {
      return;
    }

    delay(50);
  }
}