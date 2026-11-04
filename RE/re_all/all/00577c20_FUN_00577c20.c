
int FUN_00577c20(uint param_1,int param_2,undefined4 param_3,int param_4,uint param_5,
                undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint local_4;
  
  iVar4 = 0;
  uVar1 = FUN_00573310(0,param_6,param_4,param_5);
  if (uVar1 == 0) {
    return 0;
  }
  local_4 = 0;
  uVar3 = param_5;
  if ((param_2 != 0) || (param_1 != 0)) {
    while ((iVar2 = FUN_00573310(param_3,param_6,iVar4 + param_4,uVar3), iVar2 != 0 &&
           (iVar2 + uVar1 <= uVar3))) {
      iVar4 = iVar4 + iVar2;
      uVar3 = param_5 - iVar4;
      if (uVar3 <= uVar1) {
        return iVar4;
      }
      local_4 = local_4 + 1;
      if ((param_2 == 0) && (param_1 <= local_4)) {
        return iVar4;
      }
    }
  }
  return iVar4;
}

