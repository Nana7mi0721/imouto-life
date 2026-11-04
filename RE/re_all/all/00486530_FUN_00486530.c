
char * FUN_00486530(void)

{
  uint uVar1;
  char *pcVar2;
  
  if (*DAT_00a1667c == '\b') {
    uVar1 = FUN_004174a0(0,0);
    pcVar2 = (char *)(uVar1 / 8);
    switch(uVar1 % 8) {
    case 0:
      pcVar2 = (char *)FUN_00443aa0(0);
      break;
    case 1:
      pcVar2 = (char *)FUN_00478a70(0);
      break;
    case 2:
      pcVar2 = (char *)FUN_00478b00(0);
      break;
    case 3:
      pcVar2 = (char *)FUN_00478b90(0);
      break;
    case 4:
      pcVar2 = (char *)FUN_00478c20(0);
      break;
    case 5:
      pcVar2 = (char *)FUN_00478ee0(0);
      break;
    case 6:
      pcVar2 = (char *)FUN_004791a0(0);
      break;
    case 7:
      pcVar2 = (char *)FUN_00479460(0);
    }
  }
  else {
    pcVar2 = DAT_00a1667c;
    if (*DAT_00a1667c == '\x04') {
      uVar1 = FUN_004174a0(0,0);
      pcVar2 = (char *)(uVar1 / 4);
      switch(uVar1 % 4) {
      case 0:
        pcVar2 = (char *)FUN_00443aa0(0);
        break;
      case 1:
        pcVar2 = (char *)FUN_00478a70(0);
        break;
      case 2:
        pcVar2 = (char *)FUN_00478b00(0);
        break;
      case 3:
        pcVar2 = (char *)FUN_00478b90(0);
      }
    }
  }
  return pcVar2;
}

