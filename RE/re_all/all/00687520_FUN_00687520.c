
void FUN_00687520(int param_1)

{
  int *piVar1;
  int iVar2;
  
  FUN_00686af0(param_1,0xd8);
  iVar2 = 0;
  piVar1 = (int *)(param_1 + 0x58);
  do {
    if (*piVar1 != 0) {
      FUN_00686e60(param_1,iVar2);
    }
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 1;
  } while (iVar2 < 4);
  if (*(char *)(param_1 + 0xd1) == '\0') {
    iVar2 = 0;
    piVar1 = (int *)(param_1 + 0x88);
    do {
      if (piVar1[-4] != 0) {
        FUN_00687210(param_1,iVar2,0);
      }
      if (*piVar1 != 0) {
        FUN_00687210(param_1,iVar2,1);
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 4);
  }
  FUN_00686af0(param_1,0xd9);
  return;
}

