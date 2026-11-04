
undefined4 FUN_0056a240(int param_1)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  byte abStack_100 [4];
  byte bStack_fc;
  byte bStack_fb;
  byte bStack_fa;
  undefined1 uStack_6b;
  
  uVar5 = 0;
  if ((((DAT_00a828a0 == 1) || (DAT_00a828c0 == 1)) || (DAT_00a828b4 == (int *)0x0)) ||
     ((DAT_00a828a4 == 0 && (0x107 < DAT_00a2e8c8)))) {
    DVar2 = GetCurrentThreadId();
    if ((DVar2 == DAT_00a20c1c) && (iVar1 = (*DAT_00aba168)(), DAT_00a72a68 != iVar1)) {
      DAT_00a72a68 = iVar1;
      if ((param_1 != 0) && (iVar1 = FUN_005501a0(), iVar1 != 0)) {
        return 0;
      }
      GetKeyboardState(abStack_100);
      FUN_0056d380(&DAT_00a72a6c,0,0x100);
      iVar3 = 0;
      uVar4 = 0x41;
      iVar1 = 0;
      do {
        (&DAT_00a72a6c)[*(ushort *)((int)&DAT_007d6e92 + iVar1)] = abStack_100[uVar4];
        iVar3 = iVar3 + 1;
        uVar4 = (uint)*(ushort *)(&UNK_007d6e90 + iVar3 * 6);
        iVar1 = iVar3 * 6;
      } while (*(ushort *)(&UNK_007d6e90 + iVar3 * 6) != 0xffff);
      DAT_00a74b74 = abStack_100[1] >> 7;
      DAT_00a74b75 = abStack_100[2] >> 7;
      DAT_00a74b76 = bStack_fc >> 7;
      if (0x107 < DAT_00a2e8c8) {
        DAT_00a74b77 = bStack_fb >> 7;
        DAT_00a74b78 = bStack_fa >> 7;
      }
      DAT_00a74b70 = 1;
      uVar5 = 1;
    }
  }
  else {
    iVar1 = (*DAT_00aba168)();
    if ((DAT_00a72a68 == iVar1) && (DVar2 = WaitForSingleObject(DAT_00a828b8,0), DVar2 != 0)) {
      return 0;
    }
    if ((param_1 != 0) && (iVar3 = FUN_005501a0(), iVar3 != 0)) {
      return 0;
    }
    if ((DAT_00a828ac != 0) &&
       ((iVar3 = (**(code **)(*DAT_00a828b4 + 0x24))(DAT_00a828b4,0x100,&DAT_00a72a6c), iVar3 == 0
        || ((iVar3 = (**(code **)(*DAT_00a828b4 + 0x1c))(DAT_00a828b4), iVar3 == 0 &&
            (iVar3 = (**(code **)(*DAT_00a828b4 + 0x24))(DAT_00a828b4,0x100,&DAT_00a72a6c),
            iVar3 == 0)))))) {
      DAT_00a72a68 = iVar1;
      DVar2 = WaitForSingleObject(DAT_00a828b8,0);
      if (DVar2 == 0) {
        ResetEvent(DAT_00a828b8);
      }
      GetKeyboardState(abStack_100 + -0xc);
      DAT_00a72aa2 = uStack_6b;
      return 1;
    }
  }
  return uVar5;
}

