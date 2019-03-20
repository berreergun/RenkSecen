void followLine(){
   int p = positionQtr();
   motorhiz(ilkmotorsolhiz - p * kp, ilkmotorsaghiz + p * kp);
}
int positionQtr() {
   qtrread();
  if (sensorvalues[2] == 0 && sensorvalues[3] == 0) {
    return 0;
  } else if (sensorvalues[3] == 0 || sensorvalues[4] == 0) {
    return 1;
  } else if (sensorvalues[4] == 0 || sensorvalues[5] == 0) {
    return 2;
  } else if (sensorvalues[2] == 0 || sensorvalues[1] == 0) {
    return -1;
  } else if (sensorvalues[0] == 0 || sensorvalues[1] == 0) {
    return -2;
  }

  return 0;
}
