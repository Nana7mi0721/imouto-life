
undefined4 FUN_0056a030(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined1 local_10 [16];
  
  if ((DAT_00a828ac == (int *)0x0) || (DAT_00a828ac == (int *)0xffffffff)) {
    return 0xffffffff;
  }
  FUN_0054f400();
  FUN_0056bb10(&DAT_007d7844);
  DAT_00a74b80 = 0;
  if (DAT_00a82890 != 0) {
    uVar3 = 0;
    puVar4 = &DAT_00a74bc8;
    do {
      iVar1 = (*DAT_00a82894)(uVar3,local_10);
      if (iVar1 == 0) {
        FUN_0056bca0(&DAT_007d77f8,DAT_00a74b80);
        puVar4[0x1c] = uVar3;
        *puVar4 = 0x5999;
        puVar2 = puVar4 + -0x10;
        iVar1 = 2;
        do {
          puVar2[7] = 0;
          *puVar2 = 0;
          puVar2[1] = 0;
          puVar2[5] = 0;
          puVar2[6] = 0;
          puVar2 = puVar2 + 8;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
        FUN_0056d380(puVar4 + 1,0,0x50);
        FUN_0056d380(puVar4 + 0x15,0,0x1a);
        FUN_0056cf70(puVar4 + 0x20,0x208,L"Controller (XBOX 360 For Windows)");
        FUN_0056cf70(puVar4 + 0xa2,0x208,L"Controller (XBOX 360 For Windows)");
        puVar4 = puVar4 + 0x135;
        DAT_00a74b80 = DAT_00a74b80 + 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 4);
  }
  (**(code **)(*DAT_00a828ac + 0x10))(DAT_00a828ac,4,&LAB_00569130,0,1);
  return 0;
}

