
undefined4 FUN_0057e730(int param_1)

{
  int *piVar1;
  int unaff_ESI;
  
  if (DAT_00aa4fa0 == 0) {
    (**(code **)(**(int **)(param_1 + 200) + 0x48))(*(int **)(param_1 + 200));
    return 0;
  }
  (**(code **)(**(int **)(param_1 + 200) + 0x50))(*(int **)(param_1 + 200),0,0);
  piVar1 = *(int **)(param_1 + 0xcc);
  if ((piVar1 != (int *)0x0) && (unaff_ESI != 0)) {
    (**(code **)(*piVar1 + 0x10))(piVar1,0,0);
  }
  *(undefined4 *)(param_1 + 0x50) = 0;
  return 0;
}

