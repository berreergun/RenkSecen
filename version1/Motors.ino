


void motorhiz(int solhiz, int saghiz) {
  if (solhiz > 0) {
    motorsol.run(FORWARD);
  }
  else {
    motorsol.run(BACKWARD);

  }
  if (saghiz > 0) {
    motorsag.run(FORWARD);

  }
  else {
    motorsag.run(BACKWARD);
  }
  motorsol.setSpeed(abs(solhiz));
  motorsag.setSpeed(abs(saghiz));

}
