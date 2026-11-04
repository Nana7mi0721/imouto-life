
undefined4 __fastcall FUN_00606ac0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iStack_c;
  
  iStack_c = 0x606acc;
  (**(code **)(**(int **)(param_1 + 4) + 0x14))();
  iStack_c = *(int *)(param_1 + 0xc);
  iVar2 = (**(code **)(**(int **)(param_1 + 4) + 4))(*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 0x24) = iVar2;
  if (iVar2 == 0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 4) + 8))
                      (*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x14),
                       *(undefined4 *)(param_1 + 0x10),&iStack_c);
    *(int *)(param_1 + 0x24) = iVar2;
    if ((iVar2 == 0x40000) && (piVar1 = *(int **)(param_1 + 0x1c), piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0x40))(piVar1,1);
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    if (-1 < *(int *)(param_1 + 0x24)) {
      if (iStack_c != *(int *)(param_1 + 0x14)) {
        *(int *)(param_1 + 0x14) = iStack_c;
        *(undefined4 *)(param_1 + 0x24) = 1;
        (**(code **)(**(int **)(param_1 + 4) + 0x18))();
        return *(undefined4 *)(param_1 + 0x24);
      }
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  (**(code **)(**(int **)(param_1 + 4) + 0x18))();
  return *(undefined4 *)(param_1 + 0x24);
}

