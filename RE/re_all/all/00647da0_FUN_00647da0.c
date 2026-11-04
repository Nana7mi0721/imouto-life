
undefined4 FUN_00647da0(int param_1)

{
  short sVar1;
  
  switch(*(undefined2 *)(param_1 + 0x1c)) {
  case 1:
  case 5:
    sVar1 = *(short *)(param_1 + 0x1e);
    if ((sVar1 == 2) || (sVar1 == 6)) {
      return 2;
    }
    if (sVar1 == 3) {
      return 3;
    }
    if (sVar1 == 7) {
      return 3;
    }
    if (sVar1 == 4) {
      return 1;
    }
    if (sVar1 == 8) {
      return 1;
    }
    break;
  case 2:
  case 6:
    sVar1 = *(short *)(param_1 + 0x1e);
    if (sVar1 == 1) {
      return 2;
    }
    if (sVar1 == 5) {
      return 2;
    }
    if (sVar1 == 3) {
      return 1;
    }
    if (sVar1 == 7) {
      return 1;
    }
    if (sVar1 == 4) {
      return 3;
    }
    if (sVar1 == 8) {
      return 3;
    }
    break;
  case 3:
  case 7:
    sVar1 = *(short *)(param_1 + 0x1e);
    if ((sVar1 == 1) || (sVar1 == 5)) {
      return 3;
    }
    if (sVar1 == 2) {
      return 1;
    }
    if (sVar1 == 6) {
      return 1;
    }
    if (sVar1 == 4) {
      return 2;
    }
    if (sVar1 == 8) {
      return 2;
    }
    break;
  case 4:
  case 8:
    sVar1 = *(short *)(param_1 + 0x1e);
    if ((sVar1 == 1) || (sVar1 == 5)) {
      return 1;
    }
    if (sVar1 == 2) {
      return 3;
    }
    if (sVar1 == 6) {
      return 3;
    }
    if ((sVar1 == 3) || (sVar1 == 7)) {
      return 2;
    }
  }
  return 0;
}

