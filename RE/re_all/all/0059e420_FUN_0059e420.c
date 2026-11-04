
undefined4 FUN_0059e420(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 8) != '\0') {
    iVar1 = 0;
    piVar2 = (int *)(param_1 + 0x3c);
    if (0 < *(int *)(param_1 + 0x38)) {
      do {
        iVar3 = 0;
        do {
          if (*(int *)(*piVar2 + 4 + iVar3) != 0) {
            FUN_005d3370(*(undefined4 *)(*piVar2 + 4 + iVar3));
            *(undefined4 *)(*piVar2 + 4 + iVar3) = 0;
          }
          iVar3 = iVar3 + 4;
        } while (iVar3 < 0x18);
        if (*(int *)(*piVar2 + 0x1c) != 0) {
          FUN_005d3370(*(int *)(*piVar2 + 0x1c));
          *(undefined4 *)(*piVar2 + 0x1c) = 0;
        }
        if (*(int *)(*piVar2 + 0x20) != 0) {
          FUN_005d3370(*(int *)(*piVar2 + 0x20));
          *(undefined4 *)(*piVar2 + 0x20) = 0;
        }
        if (*(int *)*piVar2 != 0) {
          FUN_005d3370(*(int *)*piVar2);
          *(undefined4 *)*piVar2 = 0;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 7;
      } while (iVar1 < *(int *)(param_1 + 0x38));
    }
  }
  return 0;
}

