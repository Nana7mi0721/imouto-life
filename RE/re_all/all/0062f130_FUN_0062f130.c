
void __thiscall FUN_0062f130(int *param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_retaddr;
  
  if ((code *)param_1[0x17] != (code *)0x0) {
    (*(code *)param_1[0x17])(param_1,param_2);
  }
  (**(code **)(*param_1 + 0x74))(param_2);
  param_1[8] = 0;
  param_1[7] = unaff_retaddr;
  iVar1 = (**(code **)(*param_1 + 0xc))();
  param_1[0xc] = iVar1;
  (**(code **)(*param_1 + 0x18))();
  (**(code **)(*param_1 + 0x7c))();
  param_1[0x1c] = unaff_retaddr;
  (**(code **)(*param_1 + 0x80))(param_1 + 0x19);
  (**(code **)(*param_1 + 0x78))(param_2);
  iVar1 = 0;
  if (0 < param_1[0x3d]) {
    do {
      (**(code **)(**(int **)(param_1[0x3f] + iVar1 * 4) + 4))(param_1,param_2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[0x3d]);
  }
  FUN_0062f5d0(param_2);
  if ((code *)param_1[0x16] != (code *)0x0) {
    (*(code *)param_1[0x16])(param_1,param_2);
  }
  return;
}

