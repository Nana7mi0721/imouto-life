
undefined4 __thiscall FUN_006006b0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x44);
  if (piVar1 == (int *)0x0) {
    return 0x80004001;
  }
  if (param_2 != 1) {
    uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,param_2,param_3,param_4);
    return uVar2;
  }
  if (param_1 == 0) {
    uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,1,param_3,0);
    return uVar2;
  }
  uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,1,param_3,param_1 + 0xc);
  return uVar2;
}

