
undefined4 FUN_005cbdd0(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int unaff_EBX;
  short sVar3;
  int local_7d4;
  short local_7d0 [1000];
  
  if (DAT_00f3a070 == 0) {
    return 0;
  }
  if ((in_EAX < 2) || (unaff_EBX < 2)) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  iVar1 = 0;
  sVar3 = 0;
  local_7d4 = 0;
  if (0 < unaff_EBX + -1) {
    do {
      if (iVar1 + 2 + in_EAX * 2 < 0x3e9) {
        if (iVar1 != 0) {
          local_7d0[iVar1] = (short)in_EAX + sVar3;
          iVar1 = iVar1 + 1;
        }
      }
      else {
        FUN_005cbbc0(1,5,param_1,in_EAX * unaff_EBX,local_7d0,iVar1,0x39,1);
        iVar1 = 0;
      }
      if (0 < in_EAX) {
        iVar2 = in_EAX;
        do {
          local_7d0[iVar1] = sVar3 + (short)in_EAX;
          local_7d0[iVar1 + 1] = sVar3;
          iVar1 = iVar1 + 2;
          sVar3 = sVar3 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      if (local_7d4 != unaff_EBX + -2) {
        local_7d0[iVar1] = local_7d0[iVar1 + -1];
        iVar1 = iVar1 + 1;
      }
      local_7d4 = local_7d4 + 1;
    } while (local_7d4 < unaff_EBX + -1);
    if (iVar1 != 0) {
      FUN_005cbbc0(1,5,param_1,in_EAX * unaff_EBX,local_7d0,iVar1,0x39,1);
    }
  }
  return 0;
}

