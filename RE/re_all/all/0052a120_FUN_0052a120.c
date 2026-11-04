
int FUN_0052a120(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_005809a0(1,0,0xffffffff);
  if (iVar1 != -1) {
    iVar2 = FUN_00527c20(iVar1,0,param_1,(float)param_1,param_2,(float)param_2,param_3,
                         (float)param_3,param_4,(float)param_4,param_5,0);
    if (-1 < iVar2) {
      return iVar1;
    }
    FUN_00580b80(iVar1);
  }
  return -1;
}

