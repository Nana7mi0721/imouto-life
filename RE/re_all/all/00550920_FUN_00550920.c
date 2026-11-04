
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00550920(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  HDC hdc;
  uint uVar4;
  int iVar5;
  int local_2c;
  int local_28;
  int local_24;
  undefined1 local_20 [28];
  int local_4;
  
  if (DAT_00a49730 == 1) {
    return 0;
  }
  FUN_0056bca0(&DAT_007d60f4);
  FUN_0056bfd0();
  DAT_00a49734 = 1;
  DAT_00a21060 = 0;
  FUN_0052ea20();
  FUN_005728b0();
  FUN_0056d840();
  FUN_0057a980();
  FUN_0056c2c0();
  FUN_0060b400();
  FUN_00571540();
  FUN_0052e970(0);
  FUN_0052c670(&DAT_00a23d3c,0xc00);
  FUN_0056b620();
  if (DAT_00a20c40 == 0) {
    do {
      iVar1 = FUN_005167e0();
      local_24 = iVar1;
      FUN_005167a0(&local_2c,&local_28);
      FUN_0056bca0(&DAT_007d60b8,local_2c,local_28,iVar1);
      uVar4 = -(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0;
      iVar2 = FUN_00516830(uVar4);
      iVar5 = 0;
      if (0 < iVar2) {
        do {
          piVar3 = (int *)FUN_00516870(local_20,iVar5,uVar4);
          local_4 = piVar3[3];
          if (((*piVar3 == local_2c) && (piVar3[1] == local_28)) && (piVar3[2] == local_24)) break;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar2);
        iVar1 = local_24;
      }
      if (((iVar5 != iVar2) || (FUN_0056bca0(&DAT_007d609c), local_2c != 0x280)) ||
         ((local_28 != 0x1e0 || (iVar1 != 0x10)))) break;
      FUN_00521e70(0x280,0x1e0,0x20,DAT_00a37e74);
    } while( true );
  }
  if (DAT_00a49738 == 0) {
    hdc = GetDC((HWND)0x0);
    iVar1 = GetDeviceCaps(hdc,0xe);
    iVar2 = GetDeviceCaps(hdc,0xc);
    ReleaseDC((HWND)0x0,hdc);
    if (((iVar1 * iVar2 == 0x18) && (DAT_00a20c40 == 1)) || (iVar1 = FUN_005167e0(), iVar1 == 0x18))
    {
      FUN_0056bb10(&DAT_007d6060);
      FUN_0056bfe0();
      FUN_0056be20(0x1010001,&DAT_007d6040);
      return 0xffffffff;
    }
  }
  QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_00a238d8);
  DAT_00a238d4 = (uint)(DAT_00a238d8 != 0 || _DAT_00a238dc != 0);
  FUN_00510180();
  FUN_00527110(0);
  FUN_0050e2a0();
  iVar1 = FUN_00513580();
  if ((iVar1 != -1) && ((DAT_00a49744 != 0 || (iVar1 = FUN_0054f350(), iVar1 != -1)))) {
    if (DAT_00a49740 == 0) {
      FUN_00596800();
      FUN_00561d80();
    }
    if (DAT_00a4973c == 0) {
      FUN_00541e90();
      FUN_00594c70();
      FUN_0057ba00();
      iVar1 = FUN_0052be20();
      if (iVar1 < 0) goto LAB_00550bd7;
    }
    FUN_005671a0();
    DAT_00a49730 = 1;
    if ((DAT_00a20c40 == 0) && (DAT_00a20c10 == 0)) {
      FUN_00511110(DAT_00a20bec,1);
    }
    FUN_0056c020();
    FUN_0052a4a0(0xfffffffe);
    FUN_0052a4a0(0xfffffffc);
    if ((DAT_00a4973c != 0) || (iVar1 = FUN_00584630(), -1 < iVar1)) {
      DAT_00a49734 = 0;
      if (DAT_00a2d7c0 == 1) {
        DAT_00a2d7bc = 0;
      }
      FUN_0056bfe0();
      FUN_0056bca0(&DAT_007d6020);
      return 0;
    }
  }
LAB_00550bd7:
  FUN_005506d0();
  FUN_0056bfe0();
  FUN_0056bca0(&DAT_007d6040);
  DAT_00a49734 = 0;
  return 0xffffffff;
}

