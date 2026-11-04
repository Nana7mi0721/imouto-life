
undefined4 FUN_0056fab0(int *param_1,int param_2,char param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_424;
  int local_420;
  int local_41c;
  undefined1 local_418 [4];
  undefined1 local_414 [16];
  undefined1 local_404 [1024];
  undefined2 local_4;
  ushort local_2;
  
  if (param_1[0x221] == 1) {
    iVar1 = FUN_0056ef10(param_1);
    while (iVar1 == 0) {
      FUN_0056da20(0);
      iVar1 = FUN_0056ef10(param_1);
    }
  }
  iVar1 = FUN_00577540(param_1[0xe],param_2,&DAT_0084f3c8);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_00577540(param_1[0xe],param_2,&DAT_0084f3d0);
  if ((iVar1 == 0) || (iVar1 = FUN_00577540(param_1[0xe],param_2,&DAT_0084f3d4), iVar1 == 0)) {
    if (*param_1 == 0) {
      param_1[0x15] = param_1[0x13];
      return 0;
    }
    param_1[0x15] = param_1[0x13];
    return 0;
  }
  iVar1 = FUN_00577540(param_1[0xe],param_2,&DAT_0084f3cc);
  if (iVar1 == 0) {
    if (*param_1 == 0) {
      iVar1 = param_1[0x15];
      if ((*(uint *)(iVar1 + 8) & *(uint *)(iVar1 + 0xc)) != 0xffffffff) {
        param_1[0x15] = param_1[0x13] + *(int *)(iVar1 + 8);
        return 0;
      }
    }
    else if (*(int *)(param_1[0x15] + 4) != -1) {
      param_1[0x15] = param_1[0x13] + *(int *)(param_1[0x15] + 4);
      return 0;
    }
    return 0xffffffff;
  }
  local_41c = param_1[0x15];
  iVar1 = FUN_00577900(param_1[0xe],param_2,0x5c);
  if ((iVar1 == 0) && (iVar1 = FUN_00577900(param_1[0xe],param_2,0x2f), iVar1 == 0)) {
    FUN_0056e290(param_1,local_404,0);
    iVar1 = FUN_0056f910(param_1,local_404);
    if (iVar1 < 0) {
LAB_0056fd1f:
      if (param_4 != 0) {
        FUN_0056d420(param_4,local_404,(uint)local_2 * 4);
        *(undefined2 *)(param_4 + 0x400) = local_4;
        *(ushort *)(param_4 + 0x402) = local_2;
      }
      return 0xffffffff;
    }
  }
  else {
    iVar1 = 0;
    while( true ) {
      FUN_0056e290(param_1,local_404,&local_424);
      iVar1 = iVar1 + local_424;
      iVar2 = FUN_00572fc0(param_2 + iVar1,param_1[0xe],&local_420);
      if ((local_424 == 0) && ((iVar2 == 0x5c || (iVar2 == 0x2f)))) {
        FUN_005764b0(&DAT_0084f3d0,0xffffffff,0x7ffd,local_414,0x10,param_1[0xe]);
        FUN_0056fab0(param_1,local_414,0,0);
      }
      else {
        iVar3 = FUN_0056f910(param_1,local_404);
        if (iVar3 < 0) {
          if (param_3 == '\x01') {
            param_1[0x15] = local_41c;
          }
          goto LAB_0056fd1f;
        }
      }
      if ((iVar2 == 0) ||
         (((iVar3 = FUN_00572fc0(local_420 + iVar1 + param_2,param_1[0xe],local_418), iVar2 == 0x5c
           || (iVar2 == 0x2f)) && (iVar3 == 0)))) break;
      iVar1 = iVar1 + local_420;
    }
  }
  if (param_4 != 0) {
    FUN_0056d420(param_4,local_404,(uint)local_2 * 4);
    *(undefined2 *)(param_4 + 0x400) = local_4;
    *(ushort *)(param_4 + 0x402) = local_2;
  }
  return 0;
}

