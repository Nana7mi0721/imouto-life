
undefined4 FUN_0050f0b0(HMENU param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 local_20;
  int local_1c;
  undefined4 local_c;
  
  iVar2 = GetMenuItemCount(param_1);
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = FUN_0050f020();
      iVar1 = DAT_00a2d284;
      if (iVar3 == -1) {
        return 0xffffffff;
      }
      if (iVar3 != 1) {
        iVar3 = DAT_00a2d284 * 0x108;
        (&DAT_00a24e84)[DAT_00a2d284 * 0x42] = param_1;
        (&DAT_00a24e88)[iVar1 * 0x84] = (short)iVar4;
        (&DAT_00a24e8a)[iVar1 * 0x84] = local_20;
        FUN_0056cf70(iVar3 + 0xa24e8c,0x100,local_c);
        DAT_00a2d284 = DAT_00a2d284 + 1;
        if (local_1c != 0) {
          FUN_0050f0b0(local_1c);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  return 0;
}

