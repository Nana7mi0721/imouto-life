
undefined4 FUN_005af060(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  short sVar2;
  int iVar3;
  int local_7d4;
  short local_7d0 [1000];
  
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  if ((in_EAX < 2) || (param_2 < 2)) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  sVar2 = 0;
  iVar3 = 0;
  local_7d4 = 0;
  if (0 < param_2 + -1) {
    do {
      if (iVar3 + 2 + in_EAX * 2 < 0x3e9) {
        if (iVar3 != 0) {
          local_7d0[iVar3] = (short)in_EAX + sVar2;
          iVar3 = iVar3 + 1;
        }
      }
      else {
        FUN_005a7ce0();
        FUN_005d3b70(5,0,in_EAX * param_2,iVar3 + -2,local_7d0,0x65,param_1,0x1c);
        DAT_00a37de4 = DAT_00a37de4 + 1;
        iVar3 = 0;
      }
      if (0 < in_EAX) {
        iVar1 = in_EAX;
        do {
          local_7d0[iVar3] = sVar2 + (short)in_EAX;
          local_7d0[iVar3 + 1] = sVar2;
          iVar3 = iVar3 + 2;
          sVar2 = sVar2 + 1;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      if (local_7d4 != param_2 + -2) {
        local_7d0[iVar3] = local_7d0[iVar3 + -1];
        iVar3 = iVar3 + 1;
      }
      local_7d4 = local_7d4 + 1;
    } while (local_7d4 < param_2 + -1);
    if (iVar3 != 0) {
      FUN_005a7ce0();
      FUN_005d3b70(5,0,in_EAX * param_2,iVar3 + -2,local_7d0,0x65,param_1,0x1c);
      DAT_00a37de4 = DAT_00a37de4 + 1;
    }
  }
  return 0;
}

