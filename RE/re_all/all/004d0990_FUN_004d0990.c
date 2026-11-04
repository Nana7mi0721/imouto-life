
int __thiscall FUN_004d0990(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_1 != param_2) {
    iVar2 = FUN_004d0b50();
    if (iVar2 == 0) {
      FUN_004db6a0();
    }
    else {
      uVar3 = FUN_004d0b50();
      uVar4 = FUN_004d0b50();
      if (uVar4 < uVar3) {
        uVar3 = FUN_004d0b50();
        uVar4 = FUN_004db510();
        if (uVar4 < uVar3) {
          if (*(int *)(param_1 + 4) != 0) {
            FUN_004db750(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
            deallocate(*(undefined4 *)(param_1 + 4),
                       (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) / 0x1fc);
          }
          uVar5 = FUN_004d0b50();
          cVar1 = FUN_004db6c0(uVar5);
          if (cVar1 != '\0') {
            uVar5 = DoMessageBox(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                                 *(undefined4 *)(param_1 + 4));
            *(undefined4 *)(param_1 + 8) = uVar5;
          }
        }
        else {
          iVar2 = FUN_004d0b50();
          iVar2 = iVar2 * 0x1fc + *(int *)(param_2 + 4);
          FUN_004ed520(*(undefined4 *)(param_2 + 4),iVar2,*(undefined4 *)(param_1 + 4));
          uVar5 = DoMessageBox(iVar2,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_1 + 8));
          *(undefined4 *)(param_1 + 8) = uVar5;
        }
      }
      else {
        uVar5 = FUN_004ed520(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                             *(undefined4 *)(param_1 + 4));
        FUN_004db750(uVar5,*(undefined4 *)(param_1 + 8));
        iVar2 = FUN_004d0b50();
        *(int *)(param_1 + 8) = iVar2 * 0x1fc + *(int *)(param_1 + 4);
      }
    }
  }
  return param_1;
}

