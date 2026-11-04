
byte FUN_0056b3f0(void)

{
  int iVar1;
  byte bVar2;
  int *piStack_124;
  int *piStack_120;
  undefined4 uStack_11c;
  byte *pbVar3;
  byte local_114;
  byte bStack_113;
  byte bStack_112;
  byte bStack_111;
  byte bStack_110;
  byte bStack_10f;
  byte bStack_10e;
  byte bStack_10d;
  BYTE local_100;
  byte local_ff;
  byte local_fe;
  byte local_fc;
  byte local_fb;
  byte local_fa;
  
  if (((DAT_00a828a0 != 1) && (DAT_00a828b0 != (int *)0x0)) &&
     ((DAT_00a828a4 != 0 || (DAT_00a2e8c8 < 0x108)))) {
    iVar1 = FUN_0050e880();
    pbVar3 = &local_114;
    if (iVar1 != 0) {
      uStack_11c = 0x14;
      piStack_120 = DAT_00a828b0;
      piStack_124 = (int *)0x56b449;
      iVar1 = (**(code **)(*DAT_00a828b0 + 0x24))();
      if (iVar1 != 0) {
        piStack_124 = DAT_00a828b0;
        iVar1 = (**(code **)(*DAT_00a828b0 + 0x1c))();
        if ((iVar1 != 0) ||
           (iVar1 = (**(code **)(*DAT_00a828b0 + 0x24))(DAT_00a828b0,0x14,&piStack_124), iVar1 != 0)
           ) {
          return 0;
        }
      }
      bVar2 = (local_114 & 0x80) != 0;
      if ((bStack_113 & 0x80) != 0) {
        bVar2 = bVar2 | 2;
      }
      if ((bStack_112 & 0x80) != 0) {
        bVar2 = bVar2 | 4;
      }
      if ((bStack_111 & 0x80) != 0) {
        bVar2 = bVar2 | 8;
      }
      if ((bStack_110 & 0x80) != 0) {
        bVar2 = bVar2 | 0x10;
      }
      if ((bStack_10f & 0x80) != 0) {
        bVar2 = bVar2 | 0x20;
      }
      if ((bStack_10e & 0x80) != 0) {
        bVar2 = bVar2 | 0x40;
      }
      if ((bStack_10d & 0x80) != 0) {
        bVar2 = bVar2 | 0x80;
      }
      DAT_00a74b7c = pbVar3 + (int)DAT_00a74b7c;
      return bVar2;
    }
  }
  uStack_11c = 0x56b4e4;
  FUN_0054f860();
  if (DAT_00a74b70 == 1) {
    bVar2 = DAT_00a74b74 != '\0';
    if (DAT_00a74b75 != '\0') {
      bVar2 = bVar2 | 2;
    }
    if (DAT_00a74b76 != '\0') {
      bVar2 = bVar2 | 4;
    }
    if (DAT_00a2e8c8 < 0x108) {
      return bVar2;
    }
    if (DAT_00a74b77 != '\0') {
      bVar2 = bVar2 | 8;
    }
    local_fa = DAT_00a74b78;
  }
  else {
    uStack_11c = 0x56b543;
    GetKeyboardState(&local_100);
    bVar2 = (local_ff & 0x80) != 0;
    if ((local_fe & 0x80) != 0) {
      bVar2 = bVar2 | 2;
    }
    if ((local_fc & 0x80) != 0) {
      bVar2 = bVar2 | 4;
    }
    if (DAT_00a2e8c8 < 0x108) {
      return bVar2;
    }
    if ((local_fb & 0x80) != 0) {
      bVar2 = bVar2 | 8;
    }
    local_fa = local_fa & 0x80;
  }
  if (local_fa != 0) {
    bVar2 = bVar2 | 0x10;
  }
  return bVar2;
}

