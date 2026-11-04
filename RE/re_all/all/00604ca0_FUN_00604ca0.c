
undefined4 FUN_00604ca0(int param_1,LPCWSTR param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  iVar1 = lstrcmpW(param_2,(LPCWSTR)&DAT_00a06030);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0x1c))(0);
    if (iVar1 != 0) {
      piVar2 = (int *)(iVar1 + 0xc);
      goto LAB_00604d0a;
    }
  }
  else {
    iVar1 = lstrcmpW(param_2,(LPCWSTR)&DAT_00a060b8);
    if (iVar1 != 0) {
      *param_3 = 0;
      return 0x80040216;
    }
    iVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0x1c))(1);
    if (iVar1 != 0) {
      piVar2 = (int *)(iVar1 + 0xc);
      goto LAB_00604d0a;
    }
  }
  piVar2 = (int *)0x0;
LAB_00604d0a:
  *param_3 = piVar2;
  if (piVar2 == (int *)0x0) {
    return 0x8007000e;
  }
  (**(code **)(*piVar2 + 4))(piVar2);
  return 0;
}

