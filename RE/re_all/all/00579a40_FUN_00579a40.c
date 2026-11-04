
int FUN_00579a40(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,
                undefined4 param_6)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  uVar1 = FUN_00573310(0,param_6,param_5);
  if (uVar1 == 0) {
    return 0;
  }
  if (param_4 < 0) {
    param_4 = 1;
  }
  if (param_3 != 0) {
    param_2 = 0;
  }
  param_4 = param_4 + -1;
  if (param_3 != 0) {
    iVar3 = FUN_00573310(param_1,param_6,param_5);
    if (iVar3 == 0) {
      return 0;
    }
    if (in_EAX < iVar3 + uVar1) {
      return 0;
    }
    if (in_EAX - iVar3 <= uVar1) {
      return iVar3;
    }
    if (param_4 < 1) {
      return iVar3;
    }
    iVar2 = FUN_00577c20(param_4,param_4 >> 0x1f,0x20,iVar3 + param_5,in_EAX - iVar3,param_6);
    return iVar2 + iVar3;
  }
  if (param_2 == 0) {
    if (param_4 < 1) goto LAB_00579b20;
    uVar4 = 0x20;
  }
  else {
    if (param_4 < 1) goto LAB_00579b20;
    uVar4 = 0x30;
  }
  iVar3 = FUN_00577c20(param_4,param_4 >> 0x1f,uVar4,param_5);
LAB_00579b20:
  if (uVar1 < in_EAX - iVar3) {
    iVar2 = FUN_00573310(param_1,param_6,iVar3 + param_5,in_EAX - iVar3);
    iVar3 = iVar3 + iVar2;
  }
  return iVar3;
}

