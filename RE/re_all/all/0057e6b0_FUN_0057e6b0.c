
undefined4 FUN_0057e6b0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (DAT_00aa4fa0 == 0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 200) + 0x30))
                      (*(int **)(param_1 + 200),0,0,param_2 != 0);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x50) = 1;
    (**(code **)(**(int **)(param_1 + 200) + 0x4c))(*(int **)(param_1 + 200),0,0);
    piVar1 = *(int **)(param_1 + 0xcc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))(piVar1,0,0);
    }
    *(undefined4 *)(param_1 + 0x68) = 1;
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  return 0;
}

