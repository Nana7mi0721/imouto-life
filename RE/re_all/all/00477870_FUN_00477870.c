
undefined4 __thiscall
FUN_00477870(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = FUN_004d00e0(param_1);
  if (param_2 < iVar1) {
    iVar1 = FUN_004717c0(param_2);
    if (param_3 < iVar1) {
      iVar1 = FUN_004d00e0(param_1);
      if ((param_2 < iVar1) && (-1 < param_2)) {
        iVar1 = FUN_004717c0(param_2);
        if ((param_3 < iVar1) && (-1 < param_3)) {
          iVar1 = FUN_00477980(param_2);
          if ((param_4 < iVar1) && (-1 < param_4)) {
            FUN_004d0120(param_2);
            piVar3 = (int *)FUN_004ce990(param_4);
            if (param_5 == 0) {
              uVar2 = 0;
            }
            else if (*piVar3 / 1000 == 1) {
              iVar1 = *piVar3 % 1000;
              FUN_004d0120(param_2);
              FUN_004cfcd0(param_3);
              uVar2 = FUN_004ce990(iVar1);
            }
            else {
              uVar2 = 0;
            }
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

