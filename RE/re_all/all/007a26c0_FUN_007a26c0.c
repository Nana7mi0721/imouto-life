
undefined4 FUN_007a26c0(int param_1)

{
  if (param_1 < 0x3e81) {
    if (param_1 == 16000) {
      return 3;
    }
    if (param_1 == 8000) {
      return 6;
    }
    if (param_1 == 12000) {
      return 4;
    }
  }
  else {
    if (param_1 == 24000) {
      return 2;
    }
    if (param_1 == 48000) {
      return 1;
    }
  }
  return 0;
}

