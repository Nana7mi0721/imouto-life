
undefined4 FUN_0057ee90(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (DAT_00aa4fa0 == 0) {
    return 0xffffffff;
  }
  if ((*(int *)(param_1 + 0xcc) == 0) || (*(int *)(param_1 + 0x68) == 0)) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x50) != 1) {
    if (*(int *)(param_1 + 0x68) == 1) {
      *(undefined4 *)(param_1 + 0x68) = 2;
      uVar2 = FUN_00550060(0);
      *(undefined4 *)(param_1 + 0x6c) = uVar2;
    }
    else {
      iVar3 = FUN_00550060(0);
      if (iVar3 < *(int *)(param_1 + 0x6c)) {
        iVar3 = (iVar3 - *(int *)(param_1 + 0x6c)) + 0x7ffffff;
      }
      else {
        iVar3 = iVar3 - *(int *)(param_1 + 0x6c);
      }
      if (2999 < iVar3) {
        *(undefined4 *)(param_1 + 0x68) = 0;
        piVar1 = *(int **)(param_1 + 0xcc);
        if (DAT_00aa4254 == 0) {
          if (piVar1 == (int *)0x0) {
            return 0xffffffff;
          }
          (**(code **)(*piVar1 + 0x10))(piVar1,0,0);
          return 0xffffffff;
        }
        if (piVar1 == (int *)0x0) {
          return 0xffffffff;
        }
        (**(code **)(*piVar1 + 0x10))(piVar1,0,0);
        return 0xffffffff;
      }
    }
  }
  return 0;
}

