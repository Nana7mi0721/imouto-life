
char * FUN_0044e2e0(void)

{
  uint uVar1;
  char *pcVar2;
  
  if (*DAT_00a1667c == '\b') {
    uVar1 = FUN_004174a0(0,0);
    pcVar2 = (char *)(uVar1 / 8);
    switch(uVar1 % 8) {
    case 0:
      pcVar2 = (char *)FUN_004860a0(0);
      break;
    case 1:
      pcVar2 = (char *)FUN_00486120(0);
      break;
    case 2:
      pcVar2 = (char *)FUN_004861a0(0);
      break;
    case 3:
      pcVar2 = (char *)FUN_00486220(0);
      break;
    case 4:
      pcVar2 = (char *)FUN_004862a0(0);
      break;
    case 5:
      pcVar2 = (char *)FUN_00486320(0);
      break;
    case 6:
      pcVar2 = (char *)FUN_004863a0(0);
      break;
    case 7:
      pcVar2 = (char *)FUN_00486420(0);
    }
  }
  else {
    pcVar2 = DAT_00a1667c;
    if (*DAT_00a1667c == '\x04') {
      uVar1 = FUN_004174a0(0,0);
      pcVar2 = (char *)(uVar1 / 4);
      switch(uVar1 % 4) {
      case 0:
        pcVar2 = (char *)FUN_004860a0(0);
        break;
      case 1:
        pcVar2 = (char *)FUN_00486120(0);
        break;
      case 2:
        pcVar2 = (char *)FUN_004861a0(0);
        break;
      case 3:
        pcVar2 = (char *)FUN_00486220(0);
      }
    }
  }
  return pcVar2;
}

