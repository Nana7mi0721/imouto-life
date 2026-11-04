
int __fastcall FUN_00604800(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x98);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1);
    if (iVar2 < 0) {
      return iVar2;
    }
    (**(code **)(**(int **)(param_1 + 0x98) + 8))(*(int **)(param_1 + 0x98));
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x9c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  return 0;
}

