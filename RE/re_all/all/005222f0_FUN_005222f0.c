
undefined4 FUN_005222f0(void)

{
  FUN_005371c0();
  if (DAT_00a37d70 != 0) {
    FUN_0057b290();
    FUN_00583000();
    FUN_00582cc0();
    FUN_00580eb0(1,&LAB_00515790);
    FUN_00580eb0(0x12,0);
    FUN_005689e0();
    FUN_00580eb0(0xf,0);
    FUN_00580eb0(0x10,0);
    if (DAT_00a37d70 != 0) {
      FUN_00580eb0(0x13,0);
      if (DAT_00a37d70 != 0) {
        FUN_00580eb0(0xc,0);
      }
    }
    FUN_00516ed0();
    FUN_00516df0(DAT_00a3d260);
    DAT_00a3d260 = 0xffffffff;
    FUN_00581400(&DAT_00a37df8);
    FUN_00581400(&DAT_00a37e10);
    FUN_00581400(&DAT_00a37e28);
    FUN_00581400(&DAT_00a37e40);
    FUN_00567a00();
    if (DAT_00a37f70 != 0) {
      FUN_0056e1d0(DAT_00a37f70);
      DAT_00a37f70 = 0;
      DAT_00a37f6c = 0;
    }
    FUN_00581030(0x12);
    FUN_00581030(0xf);
    FUN_00581030(0x10);
    FUN_00581030(0xc);
    FUN_00581030(0x13);
    FUN_00581030(1);
    FUN_0051c8a0();
    DAT_00a37d70 = 0;
  }
  return 0;
}

