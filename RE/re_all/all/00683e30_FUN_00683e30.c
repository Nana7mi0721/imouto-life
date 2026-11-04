
void FUN_00683e30(int param_1,undefined1 param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 4;
  piVar1 = (int *)(param_1 + 0x58);
  do {
    if (*piVar1 != 0) {
      *(undefined1 *)(*piVar1 + 0x80) = param_2;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar1 = (int *)(param_1 + 0x88);
  iVar2 = 4;
  do {
    if (piVar1[-4] != 0) {
      *(undefined1 *)(piVar1[-4] + 0x111) = param_2;
    }
    if (*piVar1 != 0) {
      *(undefined1 *)(*piVar1 + 0x111) = param_2;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

