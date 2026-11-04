
int __thiscall FUN_004cce30(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_1 != param_2) {
    iVar2 = FUN_004ccff0();
    if (iVar2 == 0) {
      FUN_004cd070();
    }
    else {
      uVar3 = FUN_004ccff0();
      uVar4 = FUN_004ccff0();
      if (uVar4 < uVar3) {
        uVar3 = FUN_004ccff0();
        uVar4 = FUN_004d7840();
        if (uVar4 < uVar3) {
          if (*(int *)(param_1 + 4) != 0) {
            FUN_004d79d0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
            deallocate(*(undefined4 *)(param_1 + 4),
                       (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) / 0xc);
          }
          uVar5 = FUN_004ccff0();
          cVar1 = FUN_004d7950(uVar5);
          if (cVar1 != '\0') {
            uVar5 = DoMessageBox(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                                 *(undefined4 *)(param_1 + 4));
            *(undefined4 *)(param_1 + 8) = uVar5;
          }
        }
        else {
          iVar2 = FUN_004ccff0();
          iVar2 = iVar2 * 0xc + *(int *)(param_2 + 4);
          FUN_004ecc60(*(undefined4 *)(param_2 + 4),iVar2,*(undefined4 *)(param_1 + 4));
          uVar5 = DoMessageBox(iVar2,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_1 + 8));
          *(undefined4 *)(param_1 + 8) = uVar5;
        }
      }
      else {
        uVar5 = FUN_004ecc60(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                             *(undefined4 *)(param_1 + 4));
        FUN_004d79d0(uVar5,*(undefined4 *)(param_1 + 8));
        iVar2 = FUN_004ccff0();
        *(int *)(param_1 + 8) = iVar2 * 0xc + *(int *)(param_1 + 4);
      }
    }
  }
  return param_1;
}

