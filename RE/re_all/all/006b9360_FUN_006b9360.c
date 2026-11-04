
int FUN_006b9360(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = FUN_006b8dd0(0xdf30,0x10);
    if (iVar1 != 0) {
      iVar2 = FUN_006b93c0(iVar1,param_1,param_2);
      if (-1 < iVar2) {
        *(undefined4 *)(iVar1 + 0x358) = 0;
        *(undefined4 *)(iVar1 + 0x35c) = 0;
        return iVar1;
      }
    }
    FUN_006b8e20(iVar1);
  }
  return 0;
}

