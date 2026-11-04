
int __thiscall FUN_00604ec0(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *unaff_ESI;
  
  uVar1 = param_2;
  if (*(int *)(param_1[0x23] + 200) != 0) {
    iVar2 = (**(code **)(**(int **)(param_1[0x24] + 0x9c) + 0x18))
                      (*(int **)(param_1[0x24] + 0x9c),param_2);
    return iVar2;
  }
  iVar2 = FUN_00604d40(param_2,&param_2);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*param_1 + 0x24))(uVar1,param_2);
    if (-1 < iVar2) {
      if (iVar2 == 0) {
        iVar2 = (**(code **)(**(int **)(param_1[0x24] + 0x9c) + 0x18))
                          (*(int **)(param_1[0x24] + 0x9c),unaff_ESI);
        param_1[0x15] = 0;
      }
      else if (iVar2 == 1) {
        (**(code **)(*unaff_ESI + 8))(unaff_ESI);
        param_1[0x15] = 1;
        if (param_1[0x16] == 0) {
          FUN_006006b0(0xb,0,0);
          param_1[0x16] = 1;
        }
        return 0;
      }
    }
    (**(code **)(*unaff_ESI + 8))(unaff_ESI);
  }
  return iVar2;
}

