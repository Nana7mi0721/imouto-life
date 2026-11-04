
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005fdc60(int param_1,LPCWSTR param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  iVar1 = lstrcmpW(param_2,(LPCWSTR)&DAT_00a06030);
  if (iVar1 != 0) {
    *param_3 = 0;
    return 0x80040216;
  }
  iVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0x1c))(0);
  if (iVar1 == 0) {
    *param_3 = 0;
    (**(code **)(_DAT_00000000 + 4))(0);
    return 0;
  }
  piVar2 = (int *)(iVar1 + 0xc);
  *param_3 = piVar2;
  (**(code **)(*piVar2 + 4))(piVar2);
  return 0;
}

