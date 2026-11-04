
char * FUN_00485f80(void)

{
  uint uVar1;
  char *pcVar2;
  
  if (*DAT_00a1667c == '\b') {
    uVar1 = FUN_004174a0(0,0);
    switch(uVar1 % 8) {
    case 0:
      FUN_00478700();
      break;
    case 1:
      FUN_00478650();
      break;
    case 2:
      FUN_004785a0();
      break;
    case 3:
      FUN_004784f0();
      break;
    case 4:
      FUN_00478520();
      break;
    case 5:
      FUN_00478730();
      break;
    case 6:
      FUN_004785d0();
      break;
    case 7:
      FUN_00478680();
    }
  }
  pcVar2 = DAT_00a1667c;
  if (*DAT_00a1667c == '\x04') {
    uVar1 = FUN_004174a0(0,0);
    pcVar2 = (char *)(uVar1 / 4);
    switch(uVar1 % 4) {
    case 0:
      pcVar2 = (char *)FUN_00478700();
      break;
    case 1:
      pcVar2 = (char *)FUN_00478650();
      break;
    case 2:
      pcVar2 = (char *)FUN_004785a0();
      break;
    case 3:
      pcVar2 = (char *)FUN_004784f0();
    }
  }
  return pcVar2;
}

