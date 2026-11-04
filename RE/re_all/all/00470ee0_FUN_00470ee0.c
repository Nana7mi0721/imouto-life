
int __thiscall FUN_00470ee0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_004d00e0(param_1);
  if (param_2 < iVar1) {
    FUN_004d0120(param_2);
    iVar1 = FUN_004ce080();
    if (param_3 < iVar1) {
      FUN_004d0120(param_2);
      piVar2 = (int *)FUN_004ce990(param_3);
      return *piVar2 / 1000;
    }
  }
  return -1;
}

